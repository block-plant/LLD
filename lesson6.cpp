// In Lesson 5 (DIP), we passed the payment method into the checkout() function every single time.
// now suppose that the user has a payment preference , but you ask him again and again , thats an overhead.

// you want to somehow remember the thing

// now the problem with it is that suppose in shopping cart the user has some preference , but we cannot define that payment interface inside the shopping cart class.

// class Shopping_cart {
//     paymentGatewayStripe stripe ; // we cannot do this // COMPILER ERROR !!!! 
// };

// Because an interface has no variables and no code (= 0), C++ doesn't know how much 
// memory to allocate for it! To store an interface inside a class, we must use a pointer or a reference.

// Since raw pointers (IPaymentProcessor*) cause memory leaks if you forget to delete them, 
// production C++ uses a Smart Pointer: std::unique_ptr.

// Think of std::unique_ptr<Shape> as a protective box holding a pointer to a Shape.
// Creation: Instead of new Square(5), you write std::make_unique<Square>(5).
// Automatic Cleanup: When the box goes out of scope (like when main() ends), it automatically deletes 
// the object inside. Zero memory leaks.
// Why is it called "Unique"? Only one variable is allowed to own this box at a time. You cannot copy it! 
// If you want to give the box to a class, you have to explicitly hand it over using std::move(box). 
// (Now you see why std::move exists—it's just handing the unique box to a new owner!).
// Using it: Instead of a dot ., you use an arrow -> to call functions on it (e.g., processor->pay(100);).


// THE STRATEGY PATTERN 
// The Strategy Pattern allows a class to hold onto an algorithm/behavior 
// (via a smart pointer to an interface) and swap it out at runtime! 

// #include <iostream>
// #include <memory>

// // a class that has multiple options ! 
// class Ipayment {
//     public: 
//         virtual void pay(const int amount) const = 0 ; 
//         virtual ~Ipayment() {}
// };
// class UPI: public Ipayment {
//     public: 
//         void pay(const int amount) const override {
//             std::cout << "Amount paid through UPI : " << amount << std::endl;
//         }
// };
// class NetBanking: public Ipayment {
//     public: 
//         void pay(const int amount) const override {
//             std::cout << "Amount paid through Netbanking : " << amount << std::endl;
//         }
// };
// // this is the service where on runtime the things needs to be changed 
// class Payment_Method {
//     private: 
//         std::unique_ptr<Ipayment> current ;
//     public:
//         void update_method(std::unique_ptr<Ipayment> other) {
//             current = std::move(other) ; // for moving the unique_ptr we use move() 
//         }
//         void task(const int amount) const {
//             current->pay(amount);
//         }
// };
// int main() {
//     Payment_Method payment ;
//     // making the first runtime choice 
//     std::unique_ptr<Ipayment> upi = std::make_unique<UPI>();
//     payment.update_method(std::move(upi)) ;
//     payment.task(10000);
    
//     // making the second runtime choice 
//     std::unique_ptr<Ipayment> netbank = std::make_unique<NetBanking>(); 
//     payment.update_method(std::move(netbank)) ;
//     payment.task(12000);
// }


// the above example showed that how do we use unique_ptr<> 

#include <iostream>
#include <memory>

class Iroute {
    public: 
        virtual void make_path(const std::string&a , const std::string&b) const = 0 ; 
        virtual ~Iroute() {}
};
class Walk:public Iroute {
    public: 
        void make_path(const std::string&a , const std::string&b) const override {
            std::cout << "Constructing a walking path from " << a << " to " << b << std::endl;
        }
};
class Car: public Iroute {
    public: 
        void make_path(const std::string&a , const std::string&b) const override {
            std::cout << "Constructing a car path from " << a << " to " << b << std::endl;
        } 
};
// this is the class that uses the runtime behaviour change.
class Navigator {
    private: 
        std::unique_ptr<Iroute> current ; 
    public: 
        void set_strategy(std::unique_ptr<Iroute> other) {
            current = std::move(other) ;
        }
        void travel(const std::string&a , const std::string&b) const {
            current->make_path(a , b);
        }
};
int main() {
    Navigator maps ; 
    std::unique_ptr<Iroute> car = std::make_unique<Car>();
    maps.set_strategy(std::move(car));
    maps.travel("Home" , "Office");

    std::unique_ptr<Iroute> walk = std::make_unique<Walk>();
    maps.set_strategy(std::move(walk));
    maps.travel("Office" , "Park");

    return 0 ; 
}