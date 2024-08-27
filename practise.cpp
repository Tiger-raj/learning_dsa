#include <bits/stdc++.h>
using namespace std;
#define long long int;

struct pair_hash
{
    size_t operator()(const pair<int, int> &pair) const
    {
        auto hash1 = hash<int>{}(pair.first);
        auto hash2 = hash<int>{}(pair.second);
        return hash1 ^ (hash2 << 1); // XOR and bit-shift combination
    }
};
int main()
{
    string s, isbad;
    cin >> s;
    cin >> isbad;
    int k;
    cin >> k;
    int mod[2] = {1000000007, 1000000009};
    int base[2] = {31, 37};
    int n = s.length();
    unordered_set<pair<int, int>, pair_hash> st;
    for (int i = 0; i < n; i++)
    {
        int hash[2] = {0, 0};
        int pow[2] = {1, 1};
        int bad = 0;
        for (int j = i; j < n; j++)
        {
            if (isbad[s[j] - 'a'] == '0')
            {
                bad++;
            }
            if (bad > k)
                break;
            for (int l = 0; l < 2; l++)
            {
                hash[l] = (hash[l] + (s[j] - 'a' + 1) * pow[l]) % mod[l];
                pow[l] = (pow[l] * base[l]) % mod[l];
            }
            st.insert({hash[0], hash[1]});
        }
    }
    cout << st.size() << endl;
    return 0;
}