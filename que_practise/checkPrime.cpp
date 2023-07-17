#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    // T.C. O(sqrt(n))
    vector<int> v;
    int i;
    for (i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if ((n / i) != i)
            {
                v.push_back(n / i);
            }
        }
    }
    if (v.size() == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    if (isPrime(45))
        cout << "Prime";
    else
        cout << "Not Prime";

    return 0;
}