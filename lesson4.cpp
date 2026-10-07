// this is the 4th principle 

// Interface Segregation Principle 
// dont club too many functions in one interface 
// make seperate interfaces according to the work they are supposed to do 

// converting "Fat Interface" to Seperate Interface.

#include <iostream>
#include <string>

class ImakeCall {
    public:
        virtual void makeCall() const = 0;
        virtual ~ImakeCall() {}
};
class IsendEmail {
    public:
        virtual void sendEmail() const = 0;
        virtual ~IsendEmail() {}
};
class IbrowseWeb {
    public:
        virtual void browseWeb() const = 0;
        virtual ~IbrowseWeb() {}
};
class OldSchoolFlipPhone : public ImakeCall {
    public:
        void makeCall() const override { 
            std::cout << "Calling..." << std::endl ; 
        }
};
class Iphone : public IbrowseWeb , ImakeCall , IsendEmail {
    public: 
        void makeCall() const override {
            std::cout << "Calling..." << std::endl ;
        } 
        void browseWeb() const override {
            std::cout << "Calling through web" << std::endl; 
        }
        void sendEmail() const override {
            std::cout << "Sending Email..." << std::endl;
        }
};
int main() {
    OldSchoolFlipPhone phone1 ; 
    Iphone phone2; 
    phone1.makeCall() ;
    phone2.sendEmail() ; 
    phone2.browseWeb() ; 
    return 0 ; 
}