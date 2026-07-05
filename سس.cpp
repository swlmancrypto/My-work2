#include <iostream>
#include <vector>

using namespace std;

void drawBoard(char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// ÏÇáÉ ááÊÍÞÞ ãä ÇáÝæÒ
bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

int main() {
    char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
    char currentPlayer = 'X';
    int choice, row, col;
    int turn = 0;

    cout << "--- áÚÈÉ Tic-Tac-Toe ---\n";

    while (turn < 9) {
        drawBoard(board);
        cout << "áÇÚÈ " << currentPlayer << "¡ ÇÎÊÑ ÎÇäÉ (1-9): ";
        cin >> choice;

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = currentPlayer;
            
            if (checkWin(board, currentPlayer)) {
                drawBoard(board);
                cout << "ãÈÑæß! ÇááÇÚÈ " << currentPlayer << " ÝÇÒ!\n";
                return 0;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            turn++;
        } else {
            cout << "åÐå ÇáÎÇäÉ ãÍÌæÒÉ¡ ÌÑÈ ãÑÉ ÃÎÑì.\n";
        }
    }

    drawBoard(board);
    cout << "in";
	return 0 ; }
