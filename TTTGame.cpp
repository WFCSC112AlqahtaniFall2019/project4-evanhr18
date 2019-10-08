/* Class: TicTacToe
 * Author: [FINISH ME]
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
#include "time.h"
using namespace std;

int main() {

    int numberOfPlayers;
    int row;
    int column;
    TicTacToe tictac;

    srand(time(NULL));

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (true) {                                          // input players
        cout << "One or two players? (1 or 2)" << endl;
        cin >> numberOfPlayers;
        if (numberOfPlayers != 1 && numberOfPlayers != 2) {
            cout << "Not a valid number of players.";
        }
        else {
            break;
        }
    }

    tictac.initializeBoard();       // make board

    tictac.printBoard();

    if (numberOfPlayers == 1) {                         //start of game with one player

        int i = rand()%2;

        if (i == 1) {                               //picking which player goes first
            tictac.changePlayer();
        }

        while (!tictac.checkForWin() && !tictac.isBoardFull()) {

            if (tictac.getCurrentPlayerNumber() == 1) {
                cout << "It is player " << tictac.getCurrentPlayerNumber() << "'s turn." << endl;
                cout << "Pick a row and column (1, 2, 3): " << endl;
                cin >> row >> column;

                if (row > 3 || column > 3 || row < 1 || column < 1) {                   //checking to see if location is valid
                    cout << "That is not a valid location." << endl;
                }
                else if (!tictac.placeMark(row - 1, column - 1)) {              //checking to see if spot has already been taken
                    cout << "This spot has already been taken. Pick again." << endl;
                }
                else {                                                      //putting mark on board and changes player
                    tictac.placeMark(row - 1, column - 1);
                    tictac.printBoard();
                    tictac.changePlayer();
                }
            }

            else {
                cout << "It is player " << tictac.getCurrentPlayerNumber() << "'s turn." << endl;
                cout << "Pick a row and column (1, 2, 3): " << endl;

                row = rand()%3 + 1;                                 //picking random row and column
                column = rand()%3 + 1;
                cout << row << " " << column << endl;

                if (!tictac.placeMark(row - 1, column - 1)) {           //checking if spot has already been taken
                    row = rand()%3 + 1;
                    column = rand()%3 + 1;
                }
                else {                                      //putting mark on board and changes player

                    tictac.placeMark(row - 1, column - 1);
                    tictac.printBoard();
                    tictac.changePlayer();

                }
            }

        }

    }


    if (numberOfPlayers == 2) {                         //game for two players

        while (!tictac.checkForWin() && !tictac.isBoardFull()) {
            cout << "It is player " << tictac.getCurrentPlayerNumber() << "'s turn." << endl;           //picking row and column
            cout << "Pick a row and column (1, 2, 3): " << endl;
            cin >> row >> column;

            if (row > 3 || column > 3 || row < 1 || column < 1) {                   //checking if location is valid
                cout << "That is not a valid location." << endl;
            }
            else if (!tictac.placeMark(row - 1, column - 1)) {              //checking to see if location has already been taken
                cout << "This spot has already been taken. Pick again." << endl;
            }
            else {                                                      //places mark and changes player
                tictac.placeMark(row - 1, column - 1);
                tictac.printBoard();
                tictac.changePlayer();
            }

        }

    }

    if (tictac.checkForWin()) {                     //checks to see if the game has been won

        tictac.changePlayer();

        cout << "Player " << tictac.getCurrentPlayerNumber() << " has won! Congrats!" << endl;
    }

    if (tictac.isBoardFull()) {                                     //checks to see if the board is full

        cout << "The Board is full. It's a tie. Good luck next time!" << endl;

    }


    return 0;
}