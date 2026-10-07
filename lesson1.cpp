// SRP (single reponsibility principle) : this just means that one class should 
// have one and only one reason to change

// task is to break this code written by the CP programmer into SRP
// #include <iostream>
// #include <string>

// class Student {
// public:
//     std::string name;
//     int mathScore;
//     int englishScore;

//     Student(std::string n, int m, int e) {
//         name = n;
//         mathScore = m;
//         englishScore = e;
//     }

//     // Does math logic
//     bool hasPassed() {
//         return (mathScore + englishScore) >= 100;
//     }

//     // Does terminal I/O
//     void printReportCard() {
//         std::cout << "Student: " << name << "\n";
//         if (hasPassed()) {
//             std::cout << "Status: PASS\n";
//         } else {
//             std::cout << "Status: FAIL\n";
//         }
//     }
// };

// my code starts here 
#include <iostream>
#include <string>

class Student {
    private:
        std::string name ;
        int mathScore ;
        int englishScore ; 
    public: 
        Student(std::string n , int m , int e) {
            name = n; 
            mathScore = m ;
            englishScore = e ;
        }
        std::string getName() const {
            return name ;
        }
        int getMathmarks() const {
            return mathScore ; 
        }
        int getEngmarks() const {
            return englishScore ; 
        }
};

class scenario {
    public: 
        bool haspassed(const Student& s) {
            return (s.getMathmarks() + s.getEngmarks()) >= 100;
        }
};

class printer {
    public: 
        void printReportCard(const Student& s) {
            std::cout << "Student: " << s.getName() << std::endl;
            scenario sc ;
            if(sc.haspassed(s)) {
                std::cout << "Status: PASS\n";
            } else {
                std::cout << "Status: FAIL\n";
            }
        }
};


int main() {
    Student s1("Ayush" , 0 , 91);
    printer pr ; 
    pr.printReportCard(s1);
    return 0 ;
}

// lesson 1 ends here 
