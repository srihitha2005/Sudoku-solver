#include <iostream>

using namespace std;

#define N 9

//printing the array
void print(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

//checking if the state of board is valid or not
bool isSafe(int grid[N][N], int row, int col, int num)
{
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;

    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;

    int startRow = row - row % 3, startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

//final solving
bool solveSudoku(int grid[N][N], int row, int col)
{
    //if already completely filled return true
    if (row == N - 1 && col == N)
        return true;

    if (col == N) {
        row++;
        col = 0;
    }

    if (grid[row][col] > 0)
        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= N; num++)
    {

        if (isSafe(grid, row, col, num))
        {

            grid[row][col] = num;

            if (solveSudoku(grid, row, col + 1))
                return true;
        }

        grid[row][col] = 0;
    }
    return false;
}

int main()
{
    int grid[N][N];

    cout << "Enter the Sudoku grid (0 for empty cells):" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout<<"Solved sudoku : \n";
    if (solveSudoku(grid, 0, 0))
        print(grid);
    else
        cout << "no solution exists " << endl;

    return 0;
}
