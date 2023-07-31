#include <iostream>
#include <fstream>
using namespace std;

const int N = 9; // Size of the Sudoku grid

// Function to check if it's safe to place a number in a given cell
bool isSafe(int board[N][N], int row, int col, int num) {
    // Check the row and column
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Check the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to find an empty cell in the Sudoku grid
bool findEmptyCell(int board[N][N], int& row, int& col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                return true; // Found an empty cell
            }
        }
    }
    return false; // No empty cell found
}

// Main function for Sudoku solver
bool solveSudoku(int board[N][N]) {
    int row, col;

    // Check if there is an empty cell
    if (!findEmptyCell(board, row, col)) {
        return true; // No empty cell left, Sudoku solved
    }

    // Try placing numbers from 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            // If placing the number is safe, place it
            board[row][col] = num;

            // Recursively solve the remaining Sudoku
            if (solveSudoku(board)) {
                return true;
            }

            // If placing the number doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    return false; // No solution found
}

// Function to print the Sudoku grid
void printGrid(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int board[N][N];

    // Read the Sudoku grid from a file
    ifstream inputFile("sudoku_board.txt");
    if (!inputFile) {
        cout << "Error opening file 'sudoku_board.txt'. Make sure the file exists in the current directory.\n";
        return 1;
    }

    cout << "Sudoku grid from file:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!(inputFile >> board[i][j])) {
                cout << "Error reading the Sudoku grid from the file.\n";
                return 1;
            }
        }
    }

    inputFile.close();

    if (solveSudoku(board)) {
        cout << "Sudoku Solved:\n";
        printGrid(board);
        // Add this line to wait for a user input before closing the console
        cout << "Press any key to exit...";
        cin.get();
    }
    else {
        cout << "No solution exists for the given Sudoku.\n";
        // Add this line to wait for a user input before closing the console
        cout << "Press any key to exit...";
        cin.get();
    }

    return 0;
}
