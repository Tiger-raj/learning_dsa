#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long get_hash(string s)
{
    int n = size(s);
    long long h = 0;
    for (int i = 0; i < n; i++)
        h = (h * 31 + (s[i] - 'a' + 1)) % mod;
    return h;
}
vector<int> rabin_karp(string s, string t)
{
    int n = size(s), m = size(t);
    long long p = 1;
    for (int i = 1; i <= m - 1; i++)
        p = (p * 31) % mod;
    vector<int> pos;
    long long ht = get_hash(t);
    long long hs = get_hash(s.substr(0, m));
    if (hs == ht)
        pos.push_back(0);
    for (int l = 1, r = m; r < n; l++, r++)
    {
        int del = ((s[l - 1] - 'a' + 1) * p) % mod;
        int add = s[r] - 'a' + 1;
        hs = ((hs - del + mod) * 31 + add) % mod;
        if (hs == ht)
            pos.push_back(l);
    }
    return pos;
}
int main()
{
    string s, t;
    cin >> s >> t;
    cout << size(rabin_karp(s, t));
}