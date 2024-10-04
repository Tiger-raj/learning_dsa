#include <bits/stdc++.h>
using namespace std;

// tc : O(nlog(logn))
vector<int> seive(int n)
{
    vector<bool> prime(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            primes.push_back(i);
        }
    }
    return primes;
}
int main()
{
    vector<int> ans = seive(15);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}