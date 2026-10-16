// Imagine you are buying a coffee. 
// You start with a base: Simple Coffee.
// Then, you want to customize it. 
// You ask for Milk. Then you ask for Caramel.
// The barista doesn't brew a completely new, 
// special "Milk-Caramel-Coffee" bean. 
// They just take the cup of Simple Coffee, 
// and wrap it in a layer of milk, 
// then wrap it again in a layer of caramel.

// Each layer adds to the price and the description, 
// but the core object inside is still just coffee.

// If we use standard inheritance (Parent/Child) 
// to customize objects, we suffer from Class Explosion.

// Imagine an ICoffee interface. We want to offer Milk, Caramel, and Vanilla.
// If we use inheritance, we have to create:

// CoffeeWithMilk

// CoffeeWithCaramel

// CoffeeWithVanilla

// CoffeeWithMilkAndCaramel

// CoffeeWithMilkAndVanilla...
// For just 3 toppings, 
// we need 8 different classes! 
// If we have 10 toppings, we need hundreds of classes. 
// This is impossible to maintain.


// trying to implement the coffee shop 
// multiple decorations items 

// THIS IS CALLED THE DECORATOR PATTERN

#include <iostream>
#include <memory.h>
#include <string>
#include <memory>

// implement Icoffee 
// class Icoffee {
//     public:
//         // what all does all object should have ?
//         virtual double getCost() const = 0 ;
//         virtual std::string getDescription() const = 0 ;
//         // destructor
//         virtual ~Icoffee() {}
// };
// // implement a basic coffee 
// class SimpleCoffee: public Icoffee {
//     public:
//         double getCost() const override {
//             return 5.0 ; 
//         }
//         std::string getDescription() const override {
//             return "Simple Coffee" ;
//         }
// };
// // add decorator 1 
// class Milk: public Icoffee {
//     private:
//         std::unique_ptr<Icoffee> previous ; 
//     public:
//         Milk(std::unique_ptr<Icoffee> prev) : previous(std::move(prev)) {}
//         double getCost() const override {
//             return previous->getCost() + 1.5;
//         }
//         std::string getDescription() const override {
//             return previous->getDescription() + " Milk added";
//         }
// };
// // add decorator 2 
// class Caramel: public Icoffee {
//     private:
//         std::unique_ptr<Icoffee> previous ;
//     public:
//         Caramel(std::unique_ptr<Icoffee> prev) : previous(std::move(prev)) {}
//         double getCost() const override {
//             return previous->getCost() + 2.5 ; 
//         }
//         std::string getDescription() const override {
//             return previous->getDescription() + " with Caramel";
//         }
// };
// int main() {
//     std::unique_ptr<Icoffee> cf = std::make_unique<SimpleCoffee>();
//     double cost = cf->getCost();
//     std::cout << cost << std::endl; 
//     std::string des = cf->getDescription();
//     std::cout << des << std::endl;
//     cf = std::make_unique<Milk>(std::move(cf));
//     cost = cf->getCost();
//     std::cout << cost << std::endl; 
//     des = cf->getDescription();
//     std::cout << des << std::endl;
//     cf = std::make_unique<Caramel>(std::move(cf));
//     cost = cf->getCost();
//     std::cout << cost << std::endl; 
//     des = cf->getDescription();
//     std::cout << des << std::endl;
//     return 0 ; 
// }

// until here it was classwork 

// hw 

class Itext {
    public:
        virtual std::string render() const = 0 ;
        virtual ~Itext() {}
};
// here we just initialize the base object 
class PlainText: public Itext {
    public: 
        std::string render() const override { 
            return "Hello";
        }
};
// the bold decorator
class Bold: public Itext {
    private:
        std::unique_ptr<Itext> previous ;
    public: 
        Bold(std::unique_ptr<Itext> prev) : previous(std::move(prev)) {}
        std::string render() const override {
            return "<b>" + previous->render() + "</b>" ; 
        }
};
// italic decorator
class Italic: public Itext {
    private:
        std::unique_ptr<Itext> previous;
    public:
        Italic(std::unique_ptr<Itext> prev) : previous(std::move(prev)) {}
        std::string render() const override {
            return "<i>" + previous->render() + "</i>";
        };
};
int main() {
    std::unique_ptr<Itext> ptr = std::make_unique<PlainText>(); 
    std::cout << ptr->render() << std::endl;
    ptr = std::make_unique<Bold>(std::move(ptr));
    std::cout << ptr->render() << std::endl;
    ptr = std::make_unique<Italic>(std::move(ptr));
    std::cout << ptr->render() << std::endl;
    return 0 ;  
}