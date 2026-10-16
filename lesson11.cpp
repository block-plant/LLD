// Imagine ordering a custom sandwich at Subway.
// You don’t just say, 
// "Give me sandwich combination #402."
// You also don't walk behind the counter 
// and bake the bread yourself.
// Instead, you guide the "Sandwich Artist" 
// step-by-step: "I want Italian bread. Add chicken. 
// Add lettuce. Skip the tomatoes. Toast it." 
// At the end, they hand you the finished sandwich.

// If you do this in a production system 
// (like creating a User profile), 
// it creates the Telescoping Constructor Anti-Pattern:

// C++
// What if the user only wants to provide their name and email?
// User myUser("Ayush", "ayush@email.com", "", "", 0, false, false, "");

#include <iostream>
#include <string>

// class Builder {
//     private:
//         std::string cpu;
//         std::string ram;
//         std::string storage;
//         bool hasDedicatedGPU ;
//         Builder() : hasDedicatedGPU(false) {}
//         friend class Building;
//     public:
//         void print() const {
//             std::cout << "cpu : " << cpu << 
//                          " ram : " << ram << 
//                          " storage : " << storage << 
//                          " has dedicated GPU : " << (hasDedicatedGPU ? "Yes" : "No") << std::endl;
//         }
// };
// class Building {
//     private:
//         Builder techComputer ; 
//     public:
//         Building& setCpu(const std::string&valCpu) {
//             techComputer.cpu = valCpu ; 
//             return *this ; 
//         }     
//         Building& ramCpu(const std::string&valRam) {
//             techComputer.ram = valRam ;
//             return *this ;
//         }
//         Building& storageCpu(const std::string&valStorage) {
//             techComputer.storage = valStorage ;
//             return *this ;
//         }
//         Building& GPU(const bool hasGPU) {
//             techComputer.hasDedicatedGPU = hasGPU ;
//             return *this ; 
//         }
//         Builder build() {
//             return techComputer ;
//         }
// };
// int main() {
//     Builder a = Building()
//                 .setCpu("ARM")
//                 .ramCpu("64")
//                 .storageCpu("512")
//                 .GPU(true)
//                 .build() ;
//     a.print() ;
//     a = Building()
//         .setCpu("Snapdragon")
//         .ramCpu("8")
//         .storageCpu("128")
//         .GPU(false)
//         .build() ;
//     a.print() ;
//     return 0 ;
// }

// this is the builder pattern , the above was classwork

class Pizza {
    private:
        std::string size ; 
        bool cheese ;
        bool pepperoni ; 
        bool mushrooms ; 
        Pizza() : cheese(false) , pepperoni(false) , mushrooms(false) {}
        friend class Pizzabuilder;
    public:
        void print() const {
            std::cout << "the size of the pizza : " << size << std::endl;
            std::cout << "cheese : " << (cheese ? "YES" : "NO") << std::endl;
            std::cout << "pepperoni : " << (pepperoni ? "YES" : "NO") << std::endl;
            std::cout << "mushrooms : " << (mushrooms ? "YES" : "NO") << std::endl;
        }
} ;
class Pizzabuilder {
    private:
        Pizza pizza ; 
    public:
        Pizzabuilder& setSize(const std::string& sz) {
            pizza.size = sz ; 
            return *this ;
        }
        Pizzabuilder& che(const bool ches) {
            pizza.cheese = ches ; 
            return *this;
        }
        Pizzabuilder& pep(const bool pepp) {
            pizza.pepperoni = pepp;
            return *this;
        }
        Pizzabuilder& mush(const bool rooms) {
            pizza.mushrooms = rooms ;
            return *this ;
        }
        Pizza build() {
            return pizza ;
        }
};
int main() {
    Pizza pz = Pizzabuilder()
                .setSize("Regular")
                .build();
    pz.print();
    pz = Pizzabuilder()
            .setSize("Large")
            .che(true)
            .pep(false)
            .mush(true)
            .build();
    pz.print();
    pz = Pizzabuilder()
            .setSize("Large")
            .che(true)
            .pep(true)
            .mush(false)
            .build();
    pz.print();
    return 0 ; 
}
// three important things to keep here ,
// 1. the friend keyword 
// 2. the syntax of writting & in the second function that is the friend 
// of the first function.
// 3. return *this ;