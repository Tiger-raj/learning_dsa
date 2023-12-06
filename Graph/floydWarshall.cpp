// All Pair Shortest Path Problem

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        // T.C : O(n^3), S.C : O(n^2) as we'r using n^2 space (given matrix) while solving the problem
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 1e9;
                }
                if (i == j)
                    matrix[i][j] = 0;
            }
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        /*To check for negative weight cycle
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][i] < 0)
            {
                cout << "Negative weight cycle exist";
                break;
            }
        }
        */
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1e9)
                {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};

int main()
{

    return 0;
}