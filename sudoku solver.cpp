#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 9;

void printGrid(const vector<vector<int>>& grid) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(const vector<vector<int>>& grid, int row, int col, int num) {
    // Check the row
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    // Check the column
    for (int x = 0; x < SIZE; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    // Check the 3x3 box
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[boxRow + i][boxCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(vector<vector<int>>& grid, int row, int col) {
    if (row == SIZE - 1 && col == SIZE) {
        return true;
    }

    if (col == SIZE) {
        row++;
        col = 0;
    }

    if (grid[row][col] > 0) {
        return solveSudoku(grid, row, col + 1);
    }

    for (int num = 1; num <= SIZE; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) {
                return true;
            }
        }
        grid[row][col] = 0;
    }

    return false;
}

int main() {
    vector<vector<int>> grid(SIZE, vector<int>(SIZE));

    cout << "Enter the Sudoku grid (0 for empty cells):\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "Solved Sudoku:\n";
    if (solveSudoku(grid, 0, 0)) {
        printGrid(grid);
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
