#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <ctype.h>

using namespace std;
const bool CLEAR_SCREEN = true;
void clearScreen() {
    cout << endl;

    if (CLEAR_SCREEN) {
        cout << "\033c";
    }

    cout << endl;

    return;
}

void drawBoard(const vector < char >&gameBoard) {
    clearScreen();
    for (int i = 0; i < 9; i += 3) {
        cout << "  " << gameBoard.at(i) << "  |  " << gameBoard.at(i + 1) << "  |  "
            << gameBoard.at(i + 2) << "  " << endl;
        if (i < 6) {
            cout << "-----|-----|-----" << endl;
        }
    }
    cout << endl;

    return;
}


void initVector(vector <char> &v) {
    
    for (unsigned int i = 0; i < v.size(); ++i) {
        v.at(i) = 'a' + i;
    }
    
    return;
}



int convertPosition(char boardPosition) {
    int positionIndex;
    for (unsigned int i = 0; i < 26; ++i) {
        if(boardPosition == ('a' + i)) {
            positionIndex = i;
        }
    }
    return positionIndex;
}


bool validPlacement(const vector<char>  &gameBoard, int positionIndex) {
    if (positionIndex < gameBoard.size() && gameBoard.at(positionIndex) != 'X' && gameBoard.at(positionIndex) != 'O' ) {
        return true;
    }
    else {
        return false;
    }
}

int getPlay(const vector<char> &gameBoard) {
    char boardPosition = ' ';

    
    while(!validPlacement(gameBoard, convertPosition(boardPosition))) {
            cout << "Please choose a position: ";
            cin >> boardPosition;
            cout << endl;
        
    }
    return convertPosition(boardPosition);
}

bool gameWon(vector<char> &gameBoard) {
    if (gameBoard.at(0) == gameBoard.at(1) && gameBoard.at(1) == gameBoard.at(2)) {
        return true;
    }
    else if (gameBoard.at(0) == gameBoard.at(3) && gameBoard.at(0) == gameBoard.at(6)) {
        return true;
    }
    else if (gameBoard.at(0) == gameBoard.at(4) && gameBoard.at(0) == gameBoard.at(8)) {
        return true;
    }
    else if (gameBoard.at(3) == gameBoard.at(4) && gameBoard.at(3) == gameBoard.at(5)) {
        return true;
    }
    else if (gameBoard.at(6) == gameBoard.at(7) && gameBoard.at(6) == gameBoard.at(8)) {
        return true;
    }
    else if (gameBoard.at(1) == gameBoard.at(4) && gameBoard.at(1) == gameBoard.at(7)) {
        return true;
    }
    else if (gameBoard.at(2) == gameBoard.at(5) && gameBoard.at(2) == gameBoard.at(8)) {
        return true;
    }
    else if (gameBoard.at(2) == gameBoard.at(4) && gameBoard.at(2) == gameBoard.at(6)) {
        return true;
    }
    else {
        return false;
    }

}


bool boardFull(const vector<char> &gameBoard) {
    int count = 0;
    for (unsigned int i = 0; i < gameBoard.size(); ++i) {
        if ((gameBoard.at(i) != 'X') && (gameBoard.at(i) != 'O')) {
            ++count;
        }
    }
    if (count == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    vector<char> gameBoard(9);
    const int PLAYER1 = 0;
    const int PLAYER2 = 1;
    int whosTurn = PLAYER1;
    
    initVector(gameBoard);    // populates gameboard with letters
    
    drawBoard(gameBoard); // draws board
    
    while ((boardFull(gameBoard)) == false && gameWon(gameBoard) == false) { 
        int positionIndex;
        positionIndex = getPlay(gameBoard);
        
        //replace with X or O
        if(whosTurn  == PLAYER1) {
            gameBoard.at(positionIndex) = 'X';
        }
        else {
            gameBoard.at(positionIndex) = 'O';
        }
        
        
        //change turns
        if (whosTurn  == PLAYER1) {
            whosTurn = PLAYER2;
        }
        else {
            whosTurn = PLAYER1;
        }
        // display updated board
        drawBoard(gameBoard);
        
    }
    
    if (gameWon(gameBoard)) {
        if (whosTurn == PLAYER1) {
            cout << "PLAYER 2 WINS!" << endl;
        }
        else if (whosTurn == PLAYER2) {
            cout << "PLAYER 1 WINS!" << endl;
        }
    }
    else if (boardFull(gameBoard)) {
        cout << "No one wins" << endl;
        
    }
    
  
    return 0;
}