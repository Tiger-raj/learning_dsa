#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n == 2)
        return true;
    else
    {
        int i;
        for (i = 2; i < n; i++)
        {
            if (n % i == 0)
                return false;
        }
    }
    return true;
}
void printPrimeFactorization(int n)
{
    int temp = n, i = 2, flag = 0;
    while (temp != 1 && i <= n)
    {
        flag = 0;
        if (isPrime(i) && (temp % i == 0))
        {
            cout << i << " ";
            temp /= i;
            flag = 1;
        }
        if (flag == 0)
            i++;
    }
}
int main()
{
    printPrimeFactorization(100);
    return 0;
}