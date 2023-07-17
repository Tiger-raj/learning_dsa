/*
you are given an integer n.
function sumOfAllDivisors(n) is defined as the summation of (sum of
all divisors of i) where i ranges from 1 to n.
*/

#include <bits/stdc++.h>
using namespace std;

int sumOfAllDivisors(int n)
{
    // T.C. : O(n^2)
    // int i, j, sod, soi = 0;
    // for (i = 1; i <= n; i++)
    // {
    //     sod = 0;
    //     for (j = 1; j * j <= i; j++)
    //     {

    //         if (i % j == 0)
    //         {
    //             sod += j;
    //             if ((i / j) != j)
    //             {
    //                 sod += i / j;
    //             }
    //         }
    //     }
    //     soi += sod;
    // }
    // return soi;

    // T.C. : O(n)
    // int i,soi = 0;
    // for(i=1; i<= n; i++){
    // 	soi += i*(n/i);
    // }
    // return soi;

    // T.C. : O(sqrt(n))
    int ans = 0;
    int l = 1, r, k, sum;
    while (l <= n)
    {
        k = n / l;
        r = n / k;
        sum = ((l + r) * (r - l + 1)) / 2;
        ans += sum * k;
        l = r + 1;
    }
    return ans;
}

int main()
{
    cout << sumOfAllDivisors(5);
    return 0;
}