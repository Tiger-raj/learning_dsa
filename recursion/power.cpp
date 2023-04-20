// n^n = n*n*n*....(m times)
// pow(m,n) = 1, n==0 and pow(m,n-1)*m , n>0

// # calls = m+1
// TC and SC : O(m)
#include <bits/stdc++.h>
using namespace std;
/*
int pow(int n, int m)
{
    if (m == 0)
    {
        return 1;
    }
    else
    {
        return pow(n, m - 1) * n;
    }
}
*/

// We can reduce the no. of calls by making function such that if power is even then it passes n*n and takes it's power n/2 and if power is odd then it passes n*n and takes it's powes (n-1)/2 and multiplies the result by n at end. This will reduce the no. of calls by half and give the same result.

// FASTER VERSION

int pow(int n, int m)
{
    if (m == 0)
    {
        return 1;
    }
    if (m % 2 == 0)
    {
        return pow(n * n, m / 2);
    }
    else
    {
        return pow(n * n, (m - 1) / 2) * n;
    }
}

int main()
{
    cout << pow(5, 3);
    return 0;
}