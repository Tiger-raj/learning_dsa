#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Custom hash function for pair<int, int>
struct pair_hash
{
    size_t operator()(const pair<ll, ll> &pair) const
    {
        auto hash1 = hash<ll>{}(pair.first);
        auto hash2 = hash<ll>{}(pair.second);
        return hash1 ^ (hash2 << 1); // XOR and bit-shift combination
    }
};

int main()
{
    unordered_set<pair<ll, ll>, pair_hash> st;
    return 0;
}