// 0! = 1, 1! = 1
// n! = 1*2*3*....*n-1*n
// n! = (n-1)!*n , n > 0 and 1 , n == 0

#include <bits/stdc++.h>
using namespace std;
int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return fact(n - 1) * n;
    }
}
int main()
{
    cout << fact(5);
    return 0;
}

// same analysis as that of sum of n natural number using recursion.
