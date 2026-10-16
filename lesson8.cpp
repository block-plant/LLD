// in this class we start with 
// Observer Pattern

// It has two main parts:

// The Publisher (Subject): 
// The thing that has news. 
// It keeps a list of subscribers. 
// When its state changes, it loops through its list and calls update() on everyone.

// The Subscriber (Observer): 
// The things listening for news. 
// They all implement an IObserver interface.

// pehle samjho ki subscriber ko kis kis type ke updates chaiye
// jis jis type ke updates chaiye unn sab ko input update me kar denge

#include <iostream>
#include <string.h>
#include <memory>
#include <vector>

// class Isubscriber {
//     public:
//         virtual void update(const std::string&type) const = 0 ; 
//         virtual ~Isubscriber() {}
// };
// // now this subcriber can have 2 types of updates 
// // through message and gmail.
// class GmailNotifiation: public Isubscriber {
//     public:
//         void update(const std::string&type) const override {
//             std::cout << "GMAIL NOTIFICATION SENT." << std::endl;
//         };
// };
// class Mobile: public Isubscriber {
//     public:
//         void update(const std::string&type) const override {
//             std::cout << "Mobile notification done." << std::endl;
//         };
// };
// class YoutubeChannel {
//     private:
//         std::string youtubeChannelName ; 
//         // create an array of requirements (as pointers)
//         std::vector<Isubscriber*> name;
//     public:
//         YoutubeChannel(std::string n) : youtubeChannelName(n) {}
//         void add(Isubscriber* something) {
//             name.push_back(something);
//         }
//         void upload(const std::string&n) {
//             std::cout << youtubeChannelName << "just uploaded : " << n << std::endl;
//             for(Isubscriber* sub : name) {
//                 sub->update(n);
//             }
//         }
// };
// int main() {
//     // creating my channel 
//     YoutubeChannel yt("Ayush Tech House");
//     GmailNotifiation gmailService ; 
//     Mobile mobileService ; 
//     // we used & to pass the memory of this pointer to the raw pointer.
//     yt.add(&gmailService);
//     yt.add(&mobileService);
//     yt.upload("Iphone 16 review.");
//     yt.upload("My first PS5 review.");
//     return 0 ; 
// }

// doing the assignment 
class Iweatherforcast {
    public:
        virtual void tellTemperature(const int&temp) const = 0 ; 
        virtual ~Iweatherforcast() {}
};
class PhoneDisplay: public Iweatherforcast {
    public:
        void tellTemperature(const int&temp) const override {
            std::cout << "This temperature on the screen is : " << temp << std::endl;
        }
};
class WindowDisplay: public Iweatherforcast {
    public:
        void tellTemperature(const int&temp) const override {
            std::cout << "The temperature on the screen is : " << temp << std::endl;
        }
};
class RadioWeatherForecast {
    private:
        std::vector<Iweatherforcast*> optionsToForecast;
        std::string nameOfBranch;
    public:
        RadioWeatherForecast(std::string n) : nameOfBranch(n) {}

        void insertOptions(Iweatherforcast* channel) {
            optionsToForecast.push_back(channel);
        }
        void update(const int&temp) {
            std::cout << "Updating " << temp << std::endl;
            for(Iweatherforcast* sub : optionsToForecast) {
                sub->tellTemperature(temp);
            } 
        }
};
int main() {
    RadioWeatherForecast rwf("MAIN BRANCH");
    PhoneDisplay pd ;
    WindowDisplay wd ; 
    rwf.insertOptions(&pd);
    rwf.insertOptions(&wd);
    rwf.update(12);
    rwf.update(2000);
    return 0 ;
}
