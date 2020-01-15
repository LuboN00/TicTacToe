#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
char optionBoard[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

char turn = 'X';
char winner;
int drawCnt = 0;
bool endGame = false;
bool draw = false;
int row, colum;
int choise;

void printBoard();
void printOptionBoard();
void printAllBoards();
void playerTurn();
void winnerChecker();

void printBoard() {
    cout << setw(50) << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << setw(60) << "- - - - -" << endl;
    cout << setw(50) << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << setw(60) << "- - - - -" << endl;
    cout << setw(50) << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;

    return;
}

void printOptionBoard() {
    cout << setw(50) << optionBoard[0][0] << " | " << optionBoard[0][1] << " | " << optionBoard[0][2] << endl;
    cout << setw(60) << "- - - - -" << endl;
    cout << setw(50) << optionBoard[1][0] << " | " << optionBoard[1][1] << " | " << optionBoard[1][2] << endl;
    cout << setw(60) << "- - - - -" << endl;
    cout << setw(50) << optionBoard[2][0] << " | " << optionBoard[2][1] << " | " << optionBoard[2][2] << endl;

    return;
}

void printAllBoards() {
    system("cls");

    cout << setw(50) << "Tic Tac Toe" << endl << setw(50) << "For 2 Players" << endl << endl << setw(50) << "Player 1 - 'X'  Player 2 - 'O'" << endl << endl;
 
    printBoard();

    cout << endl << endl;
    
    printOptionBoard();

    return;
}

void playerTurn() {
    if (turn == 'X') {
        cout << endl << "It's player 'X' turn: ";
    }

    else if (turn == 'O') {
        cout << endl << "It's player 'O' turn: ";
    }

    cin >> choise;

    switch(choise) {
        case 1 : row = 0; colum = 0; break;
        case 2 : row = 0; colum = 1; break;
        case 3 : row = 0; colum = 2; break;
        case 4 : row = 1; colum = 0; break;
        case 5 : row = 1; colum = 1; break;
        case 6 : row = 1; colum = 2; break;
        case 7 : row = 2; colum = 0; break;
        case 8 : row = 2; colum = 1; break;
        case 9 : row = 2; colum = 2; break;
        default: cout << "ERROR! Invalid input!" << endl;
    }

    if (turn == 'X' && board[row][colum] != 'X' && board[row][colum] != 'O') {
        board[row][colum] = 'X';
        turn = 'O';
        drawCnt++;
    }

    else if (turn == 'O' && board[row][colum] != 'X' && board[row][colum] != 'O') {
        board[row][colum] = 'O';
        turn = 'X';
        drawCnt++;
    }

    else {
        cout << "ERROR! This field is taken!" << endl;
        playerTurn();
    }
}

void winnerChecker() {

    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') || (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')) {
            winner = 'X';
            endGame = true;
            return;
        }
    }

    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') || (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')) {
            winner = 'O';
            endGame = true;
            return;
        }
    }

    if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')) {
        winner = 'X';
        endGame = true;
        return;
    }

    if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')) {
        winner = 'O';
        endGame = true;
        return;
    }

    if (drawCnt > 8) {
        draw = true;
        endGame = true;
        return;
    }
}

int main() {

    while(endGame != true){
        printAllBoards();
        playerTurn();
        winnerChecker();
    }

    if (winner == 'X' && draw == false) {
        printAllBoards();
        cout << endl << "Player 1 is the WINNER!!!" << endl;
        return 0;
    }
    
    else if (winner == 'O' && draw == false) {  
        printAllBoards();
        cout << endl <<"Player 2 is the WINNER!!!" << endl;
        return 0;
    }

    else { 
        cout << "The game was DRAW!!!" << endl;
    }

    return 0;
}