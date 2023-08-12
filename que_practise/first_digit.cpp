// finding first digit of a number 

#include <bits/stdc++.h>
using namespace std;

int firstDigit(int n)
{
    while (n >= 10)
    {
        n /= 10;
    }
    return n;
}
int main()
{
    cout << firstDigit(29388) << " ";
    cout << firstDigit(57388) << " ";
    cout << firstDigit(109388) << " ";
    return 0;
}