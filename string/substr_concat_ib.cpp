// string concatenation : interviewBit - 150
#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
long long get_hash(string s)
{
    int n = size(s);
    long long h = 0;
    long long p = 1;
    for (int i = 0; i < n; i++)
    {
        h = (h + (s[i] - 'a' + 1) * p) % mod;
        p = (long long)(p * 31) % mod;
    }
    return h;
}

long long pwr(long long base, long long power, long long m)
{
    base %= m;
    long long res = 1;
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

long long modulo_inverse(long long base, long long mod)
{
    return pwr(base, mod - 2, mod);
}

vector<int> findSubstring(string A, const vector<string> &B)
{
    int n = B.size();
    int m = B[0].size();

    // long long sumhash = 0;
    unordered_map<long long, int> org;
    for (int i = 0; i < n; i++)
    {
        long long hash = get_hash(B[i]);
        org[hash]++;
    }

    int sz = size(A);
    vector<long long> strhash(sz, 0);
    long long h = 0;
    long long p = 1;
    for (int i = 0; i < sz; i++)
    {
        h = (h + (A[i] - 'a' + 1) * p) % mod;
        p = (long long)(p * 31) % mod;
        strhash[i] = h;
    }

    int len = n * m;
    vector<int> ans;
    for (int i = 0, j = len - 1; j < sz; i++, j++)
    {
        int k = i;
        // long long currsum = 0;
        unordered_map<long long, int> temp = org;
        bool flag = true;
        while (k + m - 1 <= j)
        {
            long long h = (((strhash[k + m - 1] - (k ? strhash[k - 1] : 0) + mod) % mod) * modulo_inverse(pwr(31, k, mod), mod)) % mod;
            if (temp.find(h) != temp.end())
            {
                temp[h]--;
                if (temp[h] == 0)
                    temp.erase(h);
            }
            else
            {
                flag = false;
                break;
            }
            k = k + m;
        }
        if (flag && temp.size() == 0)
            ans.push_back(i);
    }
    return ans;
}

int main()
{

    return 0;
}