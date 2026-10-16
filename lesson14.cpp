// composition vs aggregation 

// we use two types of concepts 
// delete both the objects that is created and
// the first object (has-a)
// keep the inside object even when the outer object gets
// destroyed

#include <iostream>
#include <memory>
#include <vector>

// // showing engine depending on its car
// class Engine {
//     public:
//         Engine() {
//             std::cout << "Started" << std::endl;
//         }
//         ~Engine() {
//             std::cout << "Stopped" << std::endl;
//         }
//         void start() const {
//             std::cout << "VROOM !" << std::endl;
//         }
// };
// class Car {
//     private:
//         // these things will be the one getting 
//         // destroyed if car is destroyed
//         std::unique_ptr<Engine> engine;
//     public:
//         Car() {
//             engine = std::make_unique<Engine>();
//         }
//         void drive() const {
//             engine->start() ;
//         }
// };  

// // now showing that passengers and taxi are not related
// class Passenger {
//     private:
//         std::string name;
//     public:
//         Passenger(std::string n) : name(n) {
//             std::cout << name << " enters the world" << std::endl;
//         }
//         ~Passenger() {
//             std::cout << name << " died" << std::endl;
//         }
//         std::string getName() const {
//             return name ;
//         }
// };
// class Taxi {
//     private:
//         std::vector<Passenger*> pass ;
//     public:
//         void pickup(Passenger* p) {
//             pass.push_back(p);
//             std::cout << "name of the passenger is : " << p->getName() << std::endl;
//         }
// };
// int main() {
//     {
//         Car mycar ;
//         mycar.drive();
//     }
//     Passenger John("john");
//     {
//         Taxi t ;
//         t.pickup(&John);
//     }
//     std::cout << John.getName() << std::endl;
//     return 0;
// }

// implementing the same for hospital , room and doctor

// room will be destroyed if hospital is destroyed
class Room {
    public:
        Room() {
            std::cout << "this is a room" << std::endl;
        }
        ~Room() {
            std::cout << "room destroyed" << std::endl;
        }
};
class Doctor {
    private:
        std::string name;
    public:
        Doctor(const std::string&n) : name(n) {
            std::cout << "New doctor came : " << n << std::endl;
        } 
        ~Doctor() {
            std::cout << "Doctor left : " << name << std::endl;
        }
        std::string getName() const {
            return name;
        }
};
class Hospital {
    private:
        // hold rooms as an entity that gets destroyed on removal of the room.
        std::unique_ptr<Room> rooms;
        std::vector<Doctor*> docs;
    public:
        Hospital() {
            rooms = std::make_unique<Room>(); 
        }
        ~Hospital() {
            std::cout << "Hospital Destroyed" << std::endl;
        }
        void callPatient() {
            std::cout << "Patients come in" << std::endl;
        };
        void doctors(Doctor* d) {
            docs.push_back(d);
        }
};  
int main() {
    std::string name = "ramesh";
    Doctor d(name);
    {
        Hospital ht ; 
        ht.doctors(&d);
        ht.callPatient();
    }
    std::cout << d.getName() << std::endl;
    return 0 ; 
}
