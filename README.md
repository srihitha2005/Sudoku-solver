# Sudoku Solver

This C++ program implements a backtracking algorithm to solve Sudoku puzzles.

## Usage

1. **Compile:** Compile the code using a C++ compiler.
2. **Run:** Execute the compiled program.
3. **Input:** Enter the Sudoku puzzle in row-major order, with 0 representing empty cells.
4. **Output:** The program will output the solved Sudoku puzzle if a solution exists. Otherwise, it will print "No solution exists."

## How it Works

The program uses a recursive backtracking algorithm:

1. **Start at the first empty cell.**
2. **Try each possible number (1-9) for the current cell.**
3. **If the number is valid (doesn't violate Sudoku rules), move to the next empty cell.**
4. **Recursively call the solve function to fill the rest of the grid.**
5. **If the current number leads to a dead end (no valid numbers for subsequent cells), backtrack and try the next number.**
6. **If the algorithm successfully fills the entire grid, the solution is found.**

## Explanation of Code

- **`printGrid`:** Prints the Sudoku grid.
- **`isValid`:** Checks if placing `num` in the cell at `row`, `col` is valid according to Sudoku rules.
- **`solveSudoku`:** The recursive backtracking function to solve the Sudoku puzzle.
- **`main`:** Gets input from the user, solves the Sudoku, and prints the result.

## Example

**Input:**

0 0 0 0 7 4 8 0 0
0 0 0 0 0 8 7 2 6
8 0 0 0 0 0 3 0 5
1 0 2 0 8 0 4 0 9
0 0 8 4 3 0 1 6 2
7 0 0 0 1 2 5 0 0
4 0 0 8 6 5 0 0 3
9 0 5 0 0 3 0 0 0
0 8 3 0 9 0 2 5 0

**Output:**

2 5 6 3 7 4 8 9 1
3 4 9 1 5 8 7 2 6
8 7 1 6 2 9 3 4 5
1 3 2 5 8 6 4 7 9
5 9 8 4 3 7 1 6 2
7 6 4 9 1 2 5 3 8
4 2 7 8 6 5 9 1 3
9 1 5 2 4 3 6 8 7
6 8 3 7 9 1 2 5 4


## Notes

- The program uses a simple backtracking algorithm. More advanced techniques could improve performance.
- The program assumes the input is a valid Sudoku puzzle.
- The `SIZE` constant defines the grid size (9 for standard Sudoku).

  

