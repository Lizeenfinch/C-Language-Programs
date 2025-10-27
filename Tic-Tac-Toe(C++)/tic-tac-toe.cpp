#include <iostream>
#include <vector>
#include <string>

// Function to print the Tic-Tac-Toe board
void printBoard(const std::vector<std::vector<char>>& board) {
    system("cls"); // Clear the console for a clean display (use "clear" for Linux/macOS)
    std::cout << "\n\tTic-Tac-Toe\n\n";
    std::cout << "Player 1 (X)  -  Player 2 (O)\n\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    std::cout << "     |     |     \n\n";
}

// Function to check for a win condition
bool checkWin(const std::vector<std::vector<char>>& board, char mark) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
            (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
        return true;
    }
    return false;
}

// Function to check for a draw
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell != 'X' && cell != 'O') {
                return false; // Found an empty cell, not a draw
            }
        }
    }
    return true; // All cells are filled
}

int main() {
    std::vector<std::vector<char>> board = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int currentPlayer = 1;
    bool gameEnd = false;
    int choice;
    char mark;

    do {
        printBoard(board);
        currentPlayer = (currentPlayer % 2) ? 1 : 2;
        mark = (currentPlayer == 1) ? 'X' : 'O';

        std::cout << "Player " << currentPlayer << " (" << mark << "), enter your move (1-9): ";
        std::cin >> choice;

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = mark;
        } else {
            std::cout << "Invalid move. Please try again.\n";
            currentPlayer--;
        }

        if (checkWin(board, mark)) {
            printBoard(board);
            std::cout << "==> Player " << currentPlayer << " (" << mark << ") wins!\n";
            gameEnd = true;
        } else if (checkDraw(board)) {
            printBoard(board);
            std::cout << "==> Game is a draw!\n";
            gameEnd = true;
        }

    } while (!gameEnd);

    return 0;
}
