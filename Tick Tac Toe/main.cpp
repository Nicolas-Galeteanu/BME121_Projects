//
// Created by nicol on 2026-09-14.
//
#include <iostream>
using namespace std;

/**
 * Write code here
 * Test Things
 */
char board3x3 [3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

int botTurn = 0;

void drawBoard(char board[3][3]) {
    cout << "---------\n";
    for (int i = 0; i < 3; i++) {
        cout << " |";
        for (int a = 0; a < 3; a++) {
            cout << board[i][a] << "|";
        }
        cout << "\n---------\n";
    }
}
bool win(char board[3][3], char player, char selection) {
    int row = selection % 3 - 1;
    int col = (selection-1) / 3;
    if (board[col][0]==player && board[col][1]==player && board[col][2]==player ) {
        return true;
    }else if (board[0][row]==player && board[1][row]==player && board[2][row]==player ) {
        return true;
    }else if (board[0][0]==player && board[1][1]==player && board[2][2]==player ) {
        return true;
    }else if (board[0][2]==player && board[1][1]==player && board[2][0]==player ) {
        return true;
    }else {
        return false;
    }

}
int playerSelction(char board[3][3], char player) {
    int selection;
    int row, col;
    bool valid=false;

    while (!valid) {
        cin >> selection;
        row = selection % 3 - 1;
        col = selection / 3;
        if (board[col][row] != selection+'0') {
            cout <<"Invalid Try Again\n";
        }
        else{valid = true;}

    }

    board[col][row] = player;
    return selection;
}
int botSelction(char board[3][3]) {

}
void game1p(char board[3][3]) {

}
void game2p(char board[3][3]) {
    char player1, player2;
    cout<<"Player 1 pick your letter: ";
    cin >> player1;
    cout<<"Player 2 pick your letter: ";
    cin >> player2;
    player1 = toupper(player1);
    player2 = toupper(player2);
    char turn = player1;
    for (int i = 0; i < 9; i++) {
        int selection;
        drawBoard(board);
        cout<<"its "<<turn<<"'s turn, please select a move ";
        if (turn == player1) {
            selection=playerSelction(board, turn);
            if (win(board, turn, selection)) {
                i = 10;
                cout<<"Player 1 wins!\n";
            }
            win(board, turn, selection);
            turn = player2;
        }else {
            selection = playerSelction(board, turn);
            if (win(board, turn, selection)) {
                i = 10;
                cout<<"Player 2 wins!\n";
            }
            turn = player1;
        }



    }
    cout<<"game over!!!!";
}

int main()
{
    game2p(board3x3);
    return 0;
}
