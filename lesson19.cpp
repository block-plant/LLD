// again we are practising a ques 

// Design a Parking Lot. Two spot types (Compact, Large). 
// Two vehicle types (Car, Truck). 
// Vehicles enter, get assigned an available spot, 
// and receive a Ticket. When they leave, they hand in the Ticket, 
// the spot frees up, and a fee is calculated (₹50/hour for Compact, 
// ₹100/hour for Large).


// white board architecture 
// enum SpotSize { COMPACT, LARGE }
// enum VehicleType { CAR, TRUCK }

// [Vehicle]
// - Data: VehicleType type, string licensePlate
// - API: getType(), getPlate()

// [Slot] 
// - Data: int slotId, SpotSize size, bool isOccupied 
// - API: park(), freeSlot(), isAvailable(), getSize()

// [Ticket] 
// - Data: int ticketId, Slot* parkedSlot, time_t entryTime 
// - API: getSlot(), getEntryTime()

// [Lot]
// - Data: vector<unique_ptr<Slot>> slots, vector<unique_ptr<Ticket>> tickets
// - API: Ticket* parkVehicle(Vehicle* v), int unparkVehicle(Ticket* t)

#include <ctime>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

enum class VehicleType {
    CAR,
    TRUCK,
};
enum class SpotSize {
    COMPACT,
    LARGE,
};
class Vehicle {
    private:
        VehicleType t ;
        std::string licensePlate;
    public:
        Vehicle(const VehicleType ct, const std::string&lp) : t(ct) , licensePlate(lp) {}
        ~Vehicle() {}
        std::string getPlate() {
            return licensePlate;
        }
        VehicleType getType() {
            return t ; 
        }
};

// [Slot] 
// - Data: int slotId, SpotSize size, bool isOccupied 
// - API: park(), isAvailable(), getSize()
class Slot {
    private:
        int id;
        SpotSize size;
        bool isOccupied;
    public:
        Slot(const int p, const SpotSize sz) : id(p), size(sz), isOccupied(false) {}
        ~Slot() {}
        SpotSize getSize() {
            return size;
        }
        bool isAvailable() {
            return !isOccupied; 
        }
        bool park() {
            if(isAvailable()) {
                std::cout << "Vehicle is parket at Slot id : " << id << std::endl;
                isOccupied = true; 
                return true;
            }
            return false;
        }
        void freeSlot() {
            isOccupied = false;
        }
};

// [Ticket] 
// - Data: int ticketId, Slot* parkedSlot, time_t entryTime 
// - API: getSlot(), getEntryTime()
class Ticket {
    private:
        int ticketId ; 
        Slot* parkedSlot;
        time_t entryTime;
    public:
        Ticket(const int ID , Slot* s) : ticketId(ID) , parkedSlot(s) {
            entryTime = time(0);
        }
        ~Ticket() {}
        Slot* getSlot() {
            return parkedSlot;
        } 
        time_t getEntryTime() {
            return entryTime;
        }
        int getTicketID() {
            return ticketId;
        }
};

// [Lot]
// - Data: vector<unique_ptr<Slot>> slots, vector<unique_ptr<Ticket>> tickets
// - API: Ticket* parkVehicle(Vehicle* v), int unparkVehicle(Ticket* t)]
class Lot {
    private:
        std::vector<std::unique_ptr<Slot>> slots;
        std::vector<std::unique_ptr<Ticket>> tkt;
        int tktID = 1 ;
    public:
        Lot(int numCompact , int numLarge) {
            for(int i = 0 ; i < numCompact ; i++) {
                slots.push_back(std::make_unique<Slot>(tktID++ , SpotSize::COMPACT));
            }
            for(int i = 0 ; i < numLarge ; i++) {
                slots.push_back(std::make_unique<Slot>(tktID++ , SpotSize::LARGE));
            }
        }
        ~Lot() {}
        Ticket* park(Vehicle* vc) {
            VehicleType type = vc->getType() ;
            Ticket* tick;
            for(size_t i = 0; i < slots.size(); i++) {
                if(slots[i]->isAvailable()) {
                    SpotSize spotSz = slots[i]->getSize();
                    if(type == VehicleType::TRUCK && spotSz == SpotSize::LARGE) {
                        slots[i]->park();
                        auto newTicket = std::make_unique<Ticket>(tktID++ , slots[i].get());
                        Ticket* ptr = newTicket.get();
                        tkt.push_back(std::move(newTicket));
                        return ptr;
                    }
                    else if (type == VehicleType::CAR) {
                        slots[i]->park();
                        auto newTicket = std::make_unique<Ticket>(tktID++, slots[i].get());
                        Ticket* ptr = newTicket.get();
                        tkt.push_back(std::move(newTicket));
                        return ptr;
                    }
                }
            }
            std::cout << "Parking Lot is Full!" << std::endl;
            return nullptr;
        }
        int unpark(Ticket* t) {
            if(!t) return 0;
            
            Slot* s = t->getSlot();
            time_t exitTime = time(0);
            double secondsParked = difftime(exitTime, t->getEntryTime());
            int hours = (int)secondsParked;
            if(hours == 0) hours = 1; // Base fee of 1 hour minimum
            int rate = (s->getSize() == SpotSize::COMPACT) ? 50 : 100;
            int totalFee = hours * rate;

            s->freeSlot();
            std::cout << "Vehicle unparked from Slot " << (s->getSize() == SpotSize::COMPACT ? "COMPACT" : "LARGE") << ". Total Fee: ₹" << totalFee << std::endl;
            return totalFee;
        }
};
int main() {
    Lot lot(2, 2); 
    
    Vehicle v1(VehicleType::CAR, "UP32-AB-1234");
    Vehicle v2(VehicleType::TRUCK, "MH12-CD-5678");

    Ticket* t1 = lot.park(&v1);
    Ticket* t2 = lot.park(&v2);
    lot.unpark(t1);
    lot.unpark(t2);

    return 0;
}