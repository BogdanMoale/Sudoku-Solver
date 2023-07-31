# Sudoku-Solver
Simple C++ console application that use backtracking to solve sudoku board

* The code begins by including necessary header files iostream and fstream for input/output operations and file handling.

* const int N = 9; defines a constant N representing the size of the Sudoku grid. In this case, the Sudoku grid is 9x9.

* The isSafe function is used to check if it's safe to place a number num in a given cell (row, col) of the Sudoku grid. It checks the row, column, and the 3x3 subgrid to ensure that the number doesn't violate any Sudoku rules.

* The findEmptyCell function is used to find an empty cell in the Sudoku grid. It returns the position of the first empty cell it encounters by updating the row and col variables by reference.

* The solveSudoku function is the main backtracking algorithm to solve the Sudoku puzzle. It recursively attempts to place numbers from 1 to 9 in empty cells. If it finds a safe placement, it continues to solve the remaining Sudoku. If it can't find a valid placement, it backtracks and tries different numbers until a solution is found or concludes that no solution exists.

* The printGrid function is used to print the solved Sudoku grid or the original unsolved grid.

* In the main function, an integer array board[N][N] is created to hold the Sudoku grid.

* The code reads the Sudoku grid from a file named sudoku_board.txt using the ifstream object inputFile. If the file cannot be opened, it displays an error message and exits the program.

* It then prints the original Sudoku grid from the file.

* The solveSudoku function is called to attempt to solve the puzzle. If a solution is found, it prints the solved Sudoku grid. Otherwise, it displays a message indicating that no solution exists.

Overall, the code uses backtracking to solve the Sudoku puzzle by recursively trying different numbers in empty cells until it finds a valid solution or exhausts all possibilities. The program reads the Sudoku grid from a file, solves it, and prints the solved grid on the console.