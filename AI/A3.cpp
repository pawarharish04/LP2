#include <iostream>
#include <vector>

using namespace std;

class NQueens
{
private:
    int N;
    vector<vector<int>> board;

    // Arrays for Branch and Bound
    vector<int> leftRow;
    vector<int> upperDiagonal;
    vector<int> lowerDiagonal;

public:

    // Constructor
    NQueens(int n)
    {
        N = n;

        board.resize(N, vector<int>(N, 0));

        leftRow.resize(N, 0);

        upperDiagonal.resize(2 * N - 1, 0);

        lowerDiagonal.resize(2 * N - 1, 0);
    }

    // Function to print board
    void printBoard()
    {
        cout << "\nSolution Board:\n\n";

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
    }

    // Backtracking Function
    bool solve(int col)
    {
        // Base condition
        if (col >= N)
        {
            return true;
        }

        // Try placing queen in every row
        for (int row = 0; row < N; row++)
        {

            // Check if safe
            if (leftRow[row] == 0 &&
                lowerDiagonal[row + col] == 0 &&
                upperDiagonal[N - 1 + col - row] == 0)
            {

                // Place Queen
                board[row][col] = 1;

                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[N - 1 + col - row] = 1;

                // Recursive call
                if (solve(col + 1))
                {
                    return true;
                }

                // Backtracking
                board[row][col] = 0;

                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[N - 1 + col - row] = 0;
            }
        }

        return false;
    }

    // Driver function
    void start()
    {
        if (solve(0))
        {
            printBoard();
        }
        else
        {
            cout << "No Solution Exists";
        }
    }
};

int main()
{
    int n;

    cout << "Enter value of N: ";
    cin >> n;

    NQueens obj(n);

    obj.start();
     // Time Complexity O(N!)
     //Space Complexity O(N^2)
    return 0;
}