// Snakes and Ladder 

// enum pos {SNAKE , LADDER , NONE} 

// [Game]
// -Data : std::unique_ptr<Dice> dice , std::unique_ptr<Board> board , vector<Player*> player 
// -API : bool playMove() , bool checkWin()

// [Board] 
// -Data : int size , unordered_map<int , int> ladders , unordered_map<int , int> snakes 
// -API : bool playYourMove(int curVal , int diceValue)

// [Player]
// -Data : std::string name , int current_pos 
// -API : getName() 

// [Dice] 
// -Data : int faceCount 
// -API : int roll()

#include <iostream>
#include <string>
#include <memory>
#include <cstddef>
#include <unordered_map>
#include <vector>
#include <ctime>
enum class pos {
    L,
    S,
    N,
};
class Dice { 
    private:
        size_t faceCount ; 
    public:
        Dice(const size_t x) : faceCount(x) {}
        ~Dice() {}
        size_t roll() const {
            return (size_t)(rand() % 6 + 1);
        }
};
class Player {
    private:
        std::string name ;
        size_t curPos ;
    public:
        Player(const std::string&n , const size_t pos) : name(n) , curPos(pos) {}
        ~Player() {}
        std::string getName() const {
            return name ; 
        }
        size_t getPos() {
            return curPos ;
        }
        void setPos(const size_t cur) {
            curPos = cur ; 
        }
};
class Board {
    private:
        size_t size ; 
        std::unordered_map<size_t , size_t> snakes ;
        std::unordered_map<size_t , size_t> ladders ;
        std::vector<pos> cell ; 
    public: 
        Board(const size_t sz) : size(sz) {
            cell.resize(sz + 1, pos::N);
            ladders = {
                {4, 14}, {9, 31}, {21, 42}, {28, 84}, 
                {51, 67}, {72, 91}, {80, 98}
            };
            for(auto [l , r] : ladders) {
                cell[l] = pos::L ;
            }
            snakes = {
                {17, 7}, {54, 34}, {62, 19}, {64, 60}, 
                {87, 36}, {93, 73}, {95, 75}, {99, 4}
            };
            for(auto [l , r] : snakes) {
                cell[l] = pos::S ; 
            }
            for(int i = 0 ; i <= sz ; i++) {
                if(cell[i] != pos::L && cell[i] != pos::S) {
                    cell[i] = pos::N ;
                }
            }
        }
        ~Board() {}
        size_t place(const size_t cur , const size_t diceVal) {
            size_t move = cur + diceVal ; 
            if(move > size) return cur ; 
            if(cell[move] == pos::L) {
                return (size_t)ladders[move];
            }
            else if(cell[move] == pos::S) {
                return (size_t)snakes[move];
            }
            return move ;
        }
        bool checkWin(const size_t cur) const {
            if(cur == size) return true;
            return false; 
        }
        size_t getSize() const {
            return size;
        } 
}; 
class Game {
    private:
        std::unique_ptr<Board> board;
        std::unique_ptr<Dice> dice;
        std::vector<Player*> player;
    public:
        Game() {
            board = std::make_unique<Board>(100) ;
            dice = std::make_unique<Dice>(6); 
        }
        ~Game() {}
        void addPlayer(Player* pl) {
            player.push_back(pl);
        }
        bool playerTurn(Player* p1) {
            size_t dv = this->dice->roll();
            size_t cur = p1->getPos(); 
            size_t play = this->board->place(cur , dv) ;
            p1->setPos(play);
            if(this->board->checkWin(play)) {
                std::cout << p1->getName() << " rolled " << dv << " and WON !!!" << std::endl;
                return true; // Game Over!
            }
            std::cout << p1->getName() << " rolled " << dv << " and is currently on " << p1->getPos() << std::endl;
            return false; // Keep playing
        }
};
int main() {
    srand(time(0));
    Game g1 ; 
    Player p1("Alice" , 1);
    Player p2("Bob" , 1);
    g1.addPlayer(&p1);
    g1.addPlayer(&p2);
    Dice d(6); 
    while(1) {
        if(g1.playerTurn(&p1)) break;
        if(g1.playerTurn(&p2)) break;
    }
    return 0 ; 
}