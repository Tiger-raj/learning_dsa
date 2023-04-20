#include <bits/stdc++.h>
using namespace std;
int ncr(int n, int r)
{
    if (r == 0 || r == n)
    {
        return 1;
    }
    else
    {
        return ncr(n - 1, r - 1) + ncr(n - 1, r);
    }
}
int main()
{
    cout << ncr(5, 1);
    return 0;
}