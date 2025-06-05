#include <iostream>
using namespace std;

// Function declarations
void drawBoard(char board[3][3]);
bool checkWin(char board[3][3], char player);
bool checkDraw(char board[3][3]);

int main() {
    char board[3][3] = { {'1','2','3'},
                         {'4','5','6'},
                         {'7','8','9'} };
    int move;
    char player = 'X';
    bool gameOver = false;

    while (!gameOver) {
        drawBoard(board);
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> move;

        // Validate move
        if (move < 1 || move > 9) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Cell already taken! Try again.\n";
            continue;
        }

        board[row][col] = player;

        // Check for win
        if (checkWin(board, player)) {
            drawBoard(board);
            cout << "Player " << player << " wins!\n";
            gameOver = true;
        }
        // Check for draw
        else if (checkDraw(board)) {
            drawBoard(board);
            cout << "It's a draw!\n";
            gameOver = true;
        }
        // Switch player
        else {
            player = (player == 'X') ? 'O' : 'X';
        }
    }
    return 0;
}

// Function to draw the board
void drawBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Function to check for a win
bool checkWin(char board[3][3], char player) {
    // Rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }
    // Diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

// Function to check for a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}