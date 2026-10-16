// this lecture is dedicated to singleton pattern

// A country can only have one President at a time.
// If the military needs orders, they ask the President. 
// If the treasury needs a budget signature, 
// they ask the President. 
// They don't create a new President every time 
// they need a decision; they all talk to the exact 
// same person.

// Some resources in a software system are incredibly 
// expensive to create or must absolutely not be duplicated 
// to avoid corrupting data.

// Examples:
// A Database Connection Pool.

// A File Logger (if two objects try to write to the exact 
//     same log file at the exact same millisecond, the file 
//     gets corrupted).

// Global App Configuration (settings).

// If we let developers write Database db; 
// wherever they want, our application will open 
// hundreds of database connections and crash the server. 
// We need to guarantee that only one instance of this 
// class can ever exist, and everyone must share it.


#include <iostream>
#include <string>

// class Logger {
//     private:
//         int logCount;
//         Logger() {
//             logCount = 0 ; 
//             std::cout << "initialize..." << std::endl;
//         } 
//     public:
//         // if you find Logger b = a // throw error
//         Logger(const Logger&) = delete;
//         // if you find b = a // throw error
//         Logger& operator=(const Logger&) = delete;
//         static Logger& getInstance() {
//             static Logger instance ;
//             return instance;
//         }
//         void count(const std::string&str) {
//             logCount++ ; 
//             std::cout << logCount << ' ' << str << std::endl;
//         }
// };
// int main() {
//     Logger& log1 = Logger::getInstance() ;
//     log1.count("first") ; 
//     Logger& log2 = Logger::getInstance() ;
//     log2.count("second");
//     return 0 ;
// }

class ConfigurationFile {
    private:
        std::string serverIP ; 
        int port ; 
        ConfigurationFile() {
            serverIP = "192.168.1.1";
            port = 8080;
        }
    public: 
        // deleting ConfigurationFile log = a ;
        ConfigurationFile(const ConfigurationFile&) = delete;
        // deleting b = a ; 
        ConfigurationFile& operator = (const ConfigurationFile&) = delete;
        static ConfigurationFile& getInstance() {
            static ConfigurationFile instance ;
            return instance;
        }
        std::string getServerID() {
            return serverIP ;
        }
        int getPort() {
            return port;
        }
};
int main() {
    ConfigurationFile& f1 = ConfigurationFile::getInstance();
    std::cout << f1.getServerID() << ' ' << f1.getPort() << std::endl;
    ConfigurationFile& f2 = ConfigurationFile::getInstance();
    std::cout << f2.getServerID() << ' ' << f2.getPort() << std::endl;
} 