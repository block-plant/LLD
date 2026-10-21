// Design a Tic-Tac-Toe game. 
// Two players play on a 3x3 board. 
// Players take turns placing their piece (X or O). 
// The game checks for a win or a draw after every move.

// enum moves {X , O , Empty} 
// enum turn {player1 , player2} 

// [Game]
// -Data : vector<Player*> players , unique_ptr<Board> board
// -API : bool checkWin() , turn playerTurn()

// [Board]
// -Data : moves Grid[3][3]
// -API : printBoard() , place(int row , int col , moves Grid) , isFull()

// [Player]
// -Data : std::string name , moves move
// -API : moves playerMove()  , getName() 


// Going into step 1 of machine coding 

// code the enum 
#include <iostream>
#include <string>
#include <vector>
#include <memory>
enum class Moves {
    X,
    O,
    EMPTY,
}; 
// write the player class 
class Player {
    private:
        std::string name ; 
        Moves piece ;
    public:
        Player(const std::string&n , Moves p) : name(n) , piece(p) {}
        ~Player() {}
        std::string getName() const {
            return name ;
        }
        Moves getMove() const {
            return piece ;
        }
};
// writting the Board class 
class Board {
    private:
        Moves grid[3][3];
    public:
        Board() {
            for(int i = 0 ; i < 3 ; i++) {
                for(int j = 0 ; j < 3 ; j++) {
                    grid[i][j] = Moves::EMPTY ; 
                }
            }
        }
        ~Board() {}
        void printBoard() const {
            for(int i = 0 ; i < 3 ; i++) {
                for(int j = 0 ; j < 3 ; j++) {
                    if(grid[i][j] == Moves::EMPTY) {
                        std::cout << '.' << ' ';
                    }
                    else if(grid[i][j] == Moves::X) {
                        std::cout << 'X' << ' ';
                    }
                    else if(grid[i][j] == Moves::O) {
                        std::cout << 'O' << ' ';
                    }
                    if(j != 2) std::cout << " | " << std::endl;
                }
                std::cout << std::endl;
            }
        }
        bool place(const int row , const int col , const Moves move) {
            if(grid[row][col] != Moves::EMPTY) return false ;
            grid[row][col] = move ;
            return true; 
        }
        bool isFull() const {
            for(int i = 0 ; i < 3 ; i++) {
                for(int j = 0 ; j < 3 ; j++) {
                    if(grid[i][j] == Moves::EMPTY) return false;
                }
            }
            return true;
        }
        bool checkWin(Moves piece) const {
            for(int i = 0; i < 3; i++) {
                if(grid[i][0] == piece && grid[i][1] == piece && grid[i][2] == piece) {
                    return true;
                }
            }
            for(int i = 0; i < 3; i++) {
                if(grid[0][i] == piece && grid[1][i] == piece && grid[2][i] == piece) {
                    return true;
                }
            }
            if(grid[0][0] == piece && grid[1][1] == piece && grid[2][2] == piece) {
                return true;
            }
            if(grid[0][2] == piece && grid[1][1] == piece && grid[2][0] == piece) {
                return true;
            }
            return false;
        }
};
class Game {
    private:
        std::unique_ptr<Board> board ;
        std::vector<Player*> players ; 
    public: 
        Game() {
            board = std::make_unique<Board>() ;
        }
        void addPlayers(Player* player) {
            players.push_back(player);
        } 
        bool playerTurn(Player* player , int row , int col) {
            Moves move = player->getMove(); 
            bool full = this->board->isFull();
            if(full) {
                std::cout << "Board got full. " << std::endl;
                return false; 
            }
            bool done = this->board->place(row , col , move);
            if(done) {
                bool won = this->board->checkWin(move);
                if(won) std::cout << player->getName() << " WON !!" << std::endl;
                else std::cout << "Play more , not won yet." << std::endl;
                return true;
            }
            return false;
        }
        void showBoard() const {
            board->printBoard();
        }
};
int main() {
    Player p1("alice" , Moves::X);
    Player p2("bob" , Moves::O);
    Game g1 ; 
    g1.addPlayers(&p1);
    g1.addPlayers(&p2);
    
    std::cout << "--- Game Start ---" << std::endl;
    
    g1.playerTurn(&p1, 0, 0); // Alice plays top-left
    g1.showBoard();
    g1.playerTurn(&p2, 1, 0); // Bob plays middle-left
    g1.showBoard();
    g1.playerTurn(&p1, 0, 1); // Alice plays top-middle
    g1.showBoard();
    g1.playerTurn(&p2, 1, 1); // Bob plays middle-middle
    g1.showBoard();
    g1.playerTurn(&p1, 0, 2);
    g1.showBoard();
}