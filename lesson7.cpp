// factory pattern 

// last time we studied strategy pattern , but problem with that is 
// suppose we wanted a class named car , so we were making it 
// ourselves with make_unique<>() , instead we could have used an if-else 
// so here in this we make a factory type of structure with if-else 
// so the user does not have to do make_unique<>() with hardcoded values.

// this voilated the single responsibility principle.

// #include <iostream>
// #include <memory>
// #include <stdexcept>
// #include <string> 
// #include <memory.h>
// class Ivehicle {
//     public:
//         virtual void drive() const = 0 ;
//         virtual ~Ivehicle() {}
// };
// class Car: public Ivehicle {
//     public:
//         void drive() const override {
//             std::cout << "I am Driving a car." << std::endl;
//         }
// };
// class Bike: public Ivehicle {
//     public: 
//         void drive() const override {
//             std::cout << "I am Driving a bike." << std::endl;
//         }
// };
// class Factory {
//     public:
//         static std::unique_ptr<Ivehicle> select(const std::string& other) {
//             if(other == "bike") {
//                 return std::make_unique<Bike>();
//             }
//             else if(other == "car") {
//                 return std::make_unique<Car>();
//             }
//             else {
//                 throw std::invalid_argument("this is an invalid object");
//             }
//         }
// };
// int main() {
//     std::string one = "bike";
//     std::string two = "car";
//     std::string three = "truck";
//     std::unique_ptr<Ivehicle> myBike = Factory::select(one);
//     myBike->drive();
//     std::unique_ptr<Ivehicle> myCar = Factory::select(two);
//     myCar->drive();
//     // std::unique_ptr<Ivehicle> myTruck = Factory::select(three);
//     // myTruck->drive();
//     return 0 ;
// }


// see how we used if else inside of the Factory class with the use of 
// make_unique and unique_ptr 
// this is exactly the factory pattern.

#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>

class IDocument {
    public:
        virtual void parse() const = 0 ; 
        virtual ~IDocument() {}
};
class JsonParser: public IDocument {
    public: 
        void parse() const override {
            std::cout << "parsing through JSON parser." << std::endl; 
        }
};
class XmlParser: public IDocument {
    public: 
        void parse() const override {
            std::cout << "parsing through XML parser." << std::endl;
        }
};
class Factory {
    public:
        static std::unique_ptr<IDocument> select(const std::string & type) {
            if(type == "json") {
                return std::make_unique<JsonParser>();
            }
            else if(type == "xml") {
                return std::make_unique<XmlParser>();
            }
            else {
                throw std::invalid_argument("This is an invalid argument");
            }
        }
};
int main() {
    std::string input1 ; 
    std::cin >> input1 ; 
    std::unique_ptr<IDocument> a = Factory::select(input1);
    a->parse();
    return 0 ;
}