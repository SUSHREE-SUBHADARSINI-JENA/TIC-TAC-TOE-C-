
#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic Tac Toe board
void displayBoard(const vector<vector<char>>& board) {
    for (const vector<char>& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Check rows
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Check columns
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Check main diagonal
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Check anti-diagonal
    }
    return false;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize an empty 3x3 board
    char currentPlayer = 'X'; // Player X starts

    cout << "Tic Tac Toe" << endl;

    // Main game loop
    for (int move = 0; move < 9; ++move) {
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2) for your move: ";
        cin >> row >> col;

        // Check if the chosen cell is valid
        if (row < 0 )row > 2 ;col < 0 ;col > 2 ;board[row][col] != ' ';{
            cout << "Invalid move. Try again." << endl;
            --move; // Repeat the current move
            continue;
        }

        // Update the board
        board[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // If no one wins
    if (!checkWin(board, 'X') && !checkWin(board, 'O')) {
        displayBoard(board);
        cout << "It's a draw!" << endl;
    }

    return 0;
}