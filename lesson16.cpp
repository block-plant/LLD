// WHITEBOARD ARCHITECTURE 

// this is one of the important class 

// THE ENGINEERING PROBLEM 
// In a 45-minute LLD interview, 
// if you immediately open the IDE and start typing 
// class x { ... }, you will likely realize 25 minutes in that 
// your relationships are wrong. You will have to delete half 
// your code, and you will fail the interview.

// You must spend the first 10 to 15 minutes of the 
// interview drawing boxes and arrows (or typing a 
// plain-text outline) to get the interviewer to agree 
// with your design before you write a single line of C++.


// so basically we make the blueprint either through 
// block diagram or comments that clearly define the 
// architecture.

// The Solution Architecture (UML-Lite)
// We use a lightweight text-based version of UML 
// (Unified Modeling Language).
// For every entity we parsed from our Nouns and Verbs, 
// we write a quick outline showing:

// Relationships 
// (-> for Aggregation , <> for Composition/Ownership)

// Data (Variables)
// APIs (Methods)

// lets take LIBRARY SYSTEM as an example : 

// =======================================
// WHITEBOARD ARCHITECTURE: LIBRARY SYSTEM
// =======================================

// Design a Parking Lot. 
// The Lot has multiple ParkingSpots. 
// Spots can be Small, Medium, or Large. 
// A Vehicle (like a Car or Truck) can park 
// in a spot if the size matches. 
// The Lot needs to be able to park a vehicle 
// and unpark a vehicle.


// first finding any restricted quantity !
// Spots : "Small" , "Medium" or "Large"
// Vehicle : "Car" , "Truck"
// these will be written with enum and there class name 

// finding the entities 
// 1. Lot 
// 2. ParkingSpots
// 3. Vehicle 

// finding attributes 
// 1. Lot has collection of parkingspots
// 2. ParkingSpot has a string for size , and an ID.
// 3. Vehicle has a string for size.

// finding relations 
// If Lot is destroyed then ParkingSpots will also be destroyed.
// If Lot is destroyed then Vehicles will not be destroyed.

// finding functions 
// for Lot : it needs to park and unpark the vehicle 
// for ParkingSpot : bool check if size of vehicle and spot is same.

// ================================
// WHITEBOARD DIAGRAM : PARKING LOT 
// ================================

// 1. ENUMERATIONS 
// ---------------
// enum ParkingSpots {Small , Medium , Large} 
// enum Vehicle {Car , Truck}

// 2. CLASSES 
// ----------
// [Lot] 
// - Data : vector<unique_ptr> slots , vector<Vehicle*> vehicles
// - API : park(Vehicle*) , unpark(Vehicle*) 

// [ParkingSpots] 
// - Data : string ID , string size 
// - API : bool check(Vehicle*) , getID()

// [Vehicle]
// - Data : string size 
// - API : getSize() , getStatus()





// HOMEWORK 


// Design a Movie Ticket Booking System. 
// A Theater contains multiple Screens. 
// Each Screen plays a specific Movie and 
// has multiple Seats. Seats can be Silver, Gold, or VIP. 
// A Customer can book a Ticket for a specific Seat. 
// The Ticket acts as a confirmed receipt of the booking.

// // there is an enum of Seats 

// enum SeatType {Silver , Gold , VIP} 
// enum TicketStatus { CONFIRMED, CANCELLED }

// // choosing classes
// [Customer]
// - Data : string name, string email
// - API : getName()

// [Theater] 
// - Data : vector<unique_ptr<Screen>> Screens , string location 
// - API : getNumberOfActiveScreens() 

// [Screen]
// - Data : string screenID , string movieName , string movieDuration , bool filled , vector<unique_ptr<Seat>> seats
// - API : getMovieDuration() , getNumberOfSeats() 

// [Seat]
// - Data : string seatId, SeatType type, double price, bool isBooked
// - API : book() , isAvailable()

// [Ticket]
// - Data : string ticketId , Customer* customer , Seat* seat , double finalPrice, TicketStatus status
// - API : generateReceipt()


