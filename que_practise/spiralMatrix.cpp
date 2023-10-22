#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int c1 = 0, c2 = matrix[0].size() - 1;
    int r1 = 0, r2 = matrix.size() - 1;
    vector<int> ans;

    while (c1 <= c2 && r1 <= r2)
    {
        for (int i = c1; i <= c2; i++)
        {
            ans.push_back(matrix[r1][i]);
        }
        r1++;

        for (int i = r1; i <= r2; i++)
        {
            ans.push_back(matrix[i][c2]);
        }
        c2--;

        if (r1 <= r2)
        {
            for (int i = c2; i >= c1; i--)
            {
                ans.push_back(matrix[r2][i]);
            }
            r2--;
        }

        if (c1 <= c2)
        {
            for (int i = r2; i >= r1; i--)
            {
                ans.push_back(matrix[i][c1]);
            }
            c1++;
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = spiralOrder(matrix);

    for (auto a : ans)
    {
        cout << a << " ";
    }

    return 0;
}
