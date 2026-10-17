// this lec will be on REQUIREMENT PASSING (NOUN AND VERB)
// In a Low-Level Design interview, you will not be given a list of classes. 
// The interviewer will paste a paragraph of plain English text into a Google Doc, 
// like: "Design a movie ticket booking system where users can search for movies 
// and book seats."

// If you just start writing C++ code immediately, you will get lost, 
// create God Classes, and fail the interview. You need a systematic 
// way to translate a plain English paragraph into C++ Architecture.



// When you read a prompt, you act like an English teacher analyzing a sentence.

// Identify the Nouns: These become your Classes (Entities).
// Identify the Adjectives/Possessions: These become your Member Variables (Attributes).
// Identify the Verbs: These become your Methods (Behaviors/APIs).

// CLASS EXAMPLE 

// Design a Library system. A Member can borrow a Book. 
// A Book has a title and an ISBN. 
// The Librarian can add new Books to the system

// breaking 
// nouns : member , book , librarian
// adjectives : 
    // 1. member : nothing
    // 2. book : title and ISBN
    // 3. Librarian : nothing 
// verbs
    // 1. member : borrow 
    // 2. book : nothing 
    // 3. Librarian : add books

#include <iostream>
#include <string>

// class Book {
//     private:
//         std::string title ;
//         int number ;
//     public: 
//         Book(const std::string&t , int n) : title(t) , number(n) { }
//         ~Book() {}
//         std::string getTitle() const {
//             return title;
//         }
//         int getISBN() const {
//             return number;
//         }
// };
// class Member {
//     public:
//         void borrow(const Book& borrowed_book) const {
//             std::cout << "Member is borrowing the book : " << borrowed_book.getTitle() << std::endl;
//         }
// };
// class Librarian {
//     public:
//         void addBooks(const Book&addedBook) const {
//             std::cout << "Librarian added a new book : " << addedBook.getTitle() << std::endl;
//         }
// };
// int main() {
//     Librarian lb ; 
//     std::string book1 = "Harry Potter";
//     Book b1(book1 , 1234);
//     lb.addBooks(b1);
//     Member m1 ; 
//     m1.borrow(b1);
//     return 0 ; 
// }


// HOMEWORK 

// Design a simple Food Delivery App. 
// A Customer has a delivery address and can place an Order. 
// An Order contains a list of FoodItems and a total price. 
// A Restaurant can accept an Order or reject an Order.

#include <vector>

class Order {
    private:
        std::vector<std::string> Items ; 
        int price ;
    public:
        Order(const std::vector<std::string>&It , int p) : Items(It) , price(p) {}
        ~Order() {}
};

class Restaurant {
    private: 
        std::string name ;
    public:
        Restaurant(const std::string&n) : name(n) {} 
        ~Restaurant() {}
        bool accepts() {
            return true ;
        } 
};
class Customer {
    private:
        std::string deliveryAddress ; 
    public:
        Customer(const std::string& address) : deliveryAddress(address) {}
        ~Customer() {} 
        void placeOrder() {
            std::cout << "Order placed waiting for restraunt's approval" << std::endl;
        }  
};
class App {
    private:
        std::string name ;
        std::vector<Order*> orders ; 
        std::vector<Restaurant*> rest ; 
        std::vector<Customer*> cust ; 
    public:
        App(const std::string&n) : name(n) {}
        ~App() {} 
        void addRestraunt(Restaurant* newRest) {
            rest.push_back(newRest);
        }
        void makeOrder(Restaurant* newRest , Order* ord) {
            // ensuring that the newRest is available with the app 
            if(newRest->accepts()) {
                std::cout << "Order accepted" << std::endl;
                orders.push_back(ord) ; 
            }  
            else {
                std::cout << "Order rejected" << std::endl;
            }
        }
};
int main() {
    App startup("Zomato");
    Restaurant rest1("Dominos"); 
    Restaurant rest2("Pizza Hut");  
    startup.addRestraunt(&rest1);
    startup.addRestraunt(&rest2);
    Customer c1("street 21 , Lucknow"); 
    std::vector<std::string> order ;
    int n ;
    std::cin >> n ;
    int totalPrice = 0 ;  
    for(int i = 0 ; i < n ; i++) {
        std::string s ; 
        std::cin >> s ;
        order.push_back(s);
        int p ; 
        std::cin >> p ; 
        totalPrice += p ; 
    }    
    Order o1(order , totalPrice);
    c1.placeOrder();
    startup.makeOrder(&rest1 , &o1);
    startup.makeOrder(&rest2 , &o1);
    return 0 ; 
}