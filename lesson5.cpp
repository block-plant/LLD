// this is the 5th principle of the SOLID

// (DIP) : Dependency inversion principle 

// rule : the high level modules should not depend upon the low level modules 
// they both should depend upon abstraction (interface).

// suppose we have 2 types of databases to use 

// now we hardcode one of them inside UserServices , so it later on becomes 
// hard to scrape off the whole UserServices and make changes

// so what we do is make a Database module seperately as a interface (socket where database attaches)
// then we get multiple databases (postgres , MongoDB) implementing that Database module
// and we can create instance of seperate databases in int main and pass along with the data.


// WHAT NOT TO DO !
// class MySQLDatabase {
// public:
//     void save() const { std::cout << "Saving to MySQL\n"; }
// };

// class UserService {
// public:
//     void registerUser() {
//         MySQLDatabase db; // TERRIBLE! Hardcoded dependency.
//         db.save();
//     }
// };

// WHAT TO DO !
// #include <iostream>
// #include <string>

// // 1. The Abstraction (The Wall Socket)
// class IDatabase {
// public:
//     virtual void save(std::string data) const = 0;
//     virtual ~IDatabase() {}
// };

// // 2. Low-Level Module A (Coal Plant)
// class MySQLDatabase : public IDatabase {
// public:
//     void save(std::string data) const override {
//         std::cout << "Writing '" << data << "' to MySQL database.\n";
//     }
// };

// // 3. Low-Level Module B (Solar Panel)
// class MongoDatabase : public IDatabase {
// public:
//     void save(std::string data) const override {
//         std::cout << "Writing '" << data << "' to MongoDB NoSQL document.\n";
//     }
// };

// // 4. High-Level Module (The Lamp)
// class UserService {
// public:
//     // Notice: We ask for the INTERFACE. We don't care which DB it actually is!
//     void registerUser(std::string username, const IDatabase& db) {
//         std::cout << "Validating user " << username << "...\n";
        
//         // We use the database without knowing if it's MySQL or Mongo
//         db.save(username); 
//     }
// };

// int main() {
//     UserService service;
    
//     // We create the specific databases in main()
//     MySQLDatabase mySql;
//     MongoDatabase mongo;

//     // We "plug in" whichever database we want!
//     std::cout << "--- Launching App with MySQL ---\n";
//     service.registerUser("Ayush_CP", mySql);

//     std::cout << "\n--- Migrating to MongoDB ---\n";
//     service.registerUser("Ayush_CP", mongo);

//     return 0;
// }



// PROBLEM
// #include <iostream>

// class StripeAPI {
// public:
//     void charge(int amount) const {
//         std::cout << "Charging $" << amount << " using Stripe.\n";
//     }
// };

// class Store {
// public:
//     void checkout(int amount) {
//         StripeAPI stripe; // Hardcoded!
//         stripe.charge(amount);
//     }
// };
// rewrite this is as whatever learnt 

#include <iostream>
#include <string>
class Ipaymentprocessor {
    public:
        virtual void pay(int amount) const = 0 ; 
        virtual ~Ipaymentprocessor() {}
};
class StripeAPI: public Ipaymentprocessor {
    public:
        void pay(int amount) const override {
            std::cout << "payment of " << amount << " made through Stripe." << std::endl;
        }
};
class PaypalAPI: public Ipaymentprocessor {
    public:
        void pay(int amount) const override {
            std::cout << "payment of " << amount << " made through Paypal." << std::endl;
        }
};
class Store {
    public: 
        void checkout(int amount , Ipaymentprocessor&method) {
            std::cout << "Processing" << std::endl;
            method.pay(amount);
        } 
};
int main() {
    Store myStore ;
    PaypalAPI paypal ; 
    StripeAPI stripe ;
    myStore.checkout(202 , paypal);
    myStore.checkout(10000 , stripe);
    return 0 ;
}