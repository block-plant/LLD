// LSP (LISKOV SUBSTITUTION PRINCIPLE)
// this means that the child should follow whatever things its parent asks for

// suppose we have a square , square inherits from a rectangle 
// mathematically square is a rectangle , but in parent of a rectangle it will expect height and width
// but in square it just wants to get one side.

// This is the hardest SOLID principle.

#include <iostream>
#include <string>

class File {
    public:
        virtual void read() const = 0 ; 
};

class readableFile: public File {
    public:
        void read() const override {
            std::cout << "reading file....." << std::endl;
        }
};

class writeableFile: public File {
    public:
        void read() const override {
            std::cout << "reading file....." << std::endl;
        }
        void write() {
            std::cout << "writting file....." << std::endl;
        }
};

int main() {
    readableFile r ; 
    r.read();
    writeableFile w ; 
    w.read();
    w.write();
    return 0;
}