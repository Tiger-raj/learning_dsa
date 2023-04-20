// 1+2+3+....+ N-1 + N
// sum(N) = sum(N-1) + N, N>0 and 0 , N == 0 ;

#include <bits/stdc++.h>
using namespace std;

// TC : O(n)
// SC : O(n)
// No. of recursive calls : n+1
int sumN(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return sumN(n - 1) + n;
    }
}

// using formula to get ans, best way, TC : O(1), SC : O(1)
/*
int sumN(int n)
{
    return n * (n + 1) / 2;
}
*/

// using loop to get answer, better way than using recursion as it's more space efficient. TC : O(n), SC : O(1)
/*
int sumN(int n)
{
    int i, s = 0;
    for (i = 1; i <= n; i++)
    {
        s += i;
    }
    return s;
}
*/

int main()
{
    cout << sumN(5);
    return 0;
}

// We can directly use the formula for calculating the sum of n natural numbers i.e. n(n+1)/2;

// We can use loop to calculate the sum of n natural number and it will be more spcae efficient cuz recursion internally uses stack for it's implementation.
