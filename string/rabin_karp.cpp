#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m = 1e9 + 9;

// calculate power in log(b) time
ll power(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll val = power(a, b / 2);
    if (!b % 2)
    {
        return (val % m * val % m) % m;
    }
    else
    {
        return (val % m * val % m * a % m) % m;
    }
}

// check if s string is substring of t or not, can be modified according to the use.
bool rabin_karp(string s, string t)
{
    ll p = 31;
    int S = s.size(), T = t.size();
    vector<ll> power(max(S, T), 1);
    for (int i = 1; i < power.size(); i++)
    {
        power[i] = (power[i - 1] * p) % m;
    }
    vector<ll> H(T + 1, 0);
    for (int i = 0; i < T; i++)
    {
        H[i + 1] = (H[i] + (t[i] - 'a' + 1) * power[i]) % m;
    }
    ll HS = 0;
    for (int i = 0; i < S; i++)
    {
        HS = (HS + (s[i] - 'a' + 1) * power[i]) % m;
    }
    ll currHS = 0;
    for (int i = 0; i + S <= T; i++)
    {
        currHS = (H[i + S] - H[i] + m) % m;
        if (currHS == HS * power[i] % m)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}