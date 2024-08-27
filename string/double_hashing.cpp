#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll m = 1e9 + 9;

// calculate power in log(b) time
ll power(ll base, ll power, ll m)
{
    base %= m;
    ll res = 1;
    while (power > 0)
    {
        if (power & 1)
        {
            res = res * base % m;
        }
        base = (base * base) % m;
        power >>= 1;
    }
    return res;
}

ll modulo_inverse(ll base, ll mod)
{
    return power(base, mod - 2, mod);
}
/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    int n = s.size();
    // Your code here
    int p1 = 31, p2 = 37;
    ll mod1 = 1e9 + 7, mod2 = 1e9 + 9;
    vector<int> hash1(n, 0), hash2(n, 0);
    hash2[0] = hash1[0] = s[0] - 'a' + 1;
    for (int i = 1; i < n; i++)
    {
        hash1[i] = (hash1[i - 1] + (s[i] - 'a' + 1) * power(p1, i, mod1)) % mod1;
        hash2[i] = (hash2[i - 1] + (s[i] - 'a' + 1) * power(p2, i, mod2)) % mod2;
    }

    set<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // s[i...j]
            int h1 = (int)((hash1[j] - (i > 0 ? hash1[i - 1] : 0) + mod1) * modulo_inverse(power(p1, i, mod1), mod1)) % mod1;
            int h2 = (int)((hash2[j] - (i > 0 ? hash2[i - 1] : 0) + mod2) * modulo_inverse(power(p2, i, mod2), mod2)) % mod2;
            st.insert(make_pair(h1, h2));
        }
    }
    return st.size() + 1;
}

int main()
{
}