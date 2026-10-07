// this covers the OCP  
// OCP stands for OPEN/CLOSED Principle  

// take example of a gaming console , whenever the company releases a new game , the gamer is
// able to use to the same hardware for even new games.

// this means our software should be in such a way that : the software is closed for MODIFICATION 
// but open for EXTENSION
// extension is used like making new classes for each usecase.

// #include <iostream>
// #include <string>

// // 1. THE INTERFACE (The Disc Drive)
// class PaymentMethod {
// public:
//     // virtual ... = 0 means "Child classes MUST implement this"
//     virtual void pay(int amount) const = 0; 
    
//     // Virtual destructor is a C++ rule when using virtual functions. 
//     // Just include it, we don't need to overthink it right now.
//     virtual ~PaymentMethod() {} 
// };

// // 2. EXTENSION 1: Credit Card (A specific game disc)
// class CreditCard : public PaymentMethod {
// public:
//     // "override" tells the compiler we are fulfilling the Interface's rule.
//     void pay(int amount) const override {
//         std::cout << "Processing $" << amount << " via Credit Card.\n";
//     }
// };

// // 3. EXTENSION 2: PayPal (Another specific game disc)
// class PayPal : public PaymentMethod {
// public:
//     void pay(int amount) const override {
//         std::cout << "Routing $" << amount << " through PayPal API.\n";
//     }
// };

// // 4. THE SYSTEM (The Console) - It is CLOSED for modification!
// class CheckoutSystem {
// public:
//     // Notice it takes the INTERFACE (PaymentMethod), not a specific card!
//     void processPayment(const PaymentMethod& method, int amount) {
//         std::cout << "Starting checkout...\n";
//         method.pay(amount); // Polymorphism in action!
//     }
// };

// int main() {
//     CheckoutSystem checkout;
    
//     CreditCard myCard;
//     PayPal myPayPal;

//     // The checkout system handles both perfectly without knowing what they are.
//     checkout.processPayment(myCard, 50);
//     checkout.processPayment(myPayPal, 20);

//     return 0;
// }

// above is the example that can be used as an example.

#include <iostream>
#include <string>

class Shape {
    public: 
        virtual double calculateArea() const = 0 ;
        virtual std::string getName() const = 0 ; 
        virtual ~Shape() {}
};

class Square : public Shape {
    int side ;
    public:
        Square(int s) {
            side = s ;
        }
        double calculateArea() const override {
            return side * side ;
        }
        std::string getName() const override {
            return "Square" ; 
        }
};  

class Circle : public Shape {
    int radius ; 
    public: 
        Circle(int r) {
            radius = r ;
        }
        double calculateArea() const override {
            return 3.14 * radius * radius ;
        }
        std::string getName() const override {
            return "Circle"; 
        }
};

class Printer {
    public: 
        void print(const Shape&s) {
            std::cout << "The area for the shape " << s.getName() << " is " << s.calculateArea() << "." << std::endl;  
        }
};

int main() {
    Printer p ; 
    Square sq(10) ; 
    Circle cir(5) ;
    p.print(sq);
    p.print(cir) ;
    return 0; 
}