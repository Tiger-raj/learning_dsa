#include <bits/stdc++.h>
#define int long long
#define lld long double
#define fl(i, n) for (int i = 0; i < n; i++)
#define ff first
#define ss second
#define pb push_back
#define iarr(arr, n) fl(i, n) cin >> arr[i];
#define parr(arr)      \
    for (auto x : arr) \
        cout << x << ' ';
using namespace std;
vector<int> kmp(string str)
{
    int n = size(str);
    vector<int> lps(n, 0);
    for (int i = 1; i < n; i++)
    {
        int k = lps[i - 1];

        while (k > 0 && str[k] != str[i])
        {
            k = lps[k - 1];
        }
        if (str[k] == str[i])
        {
            k++;
        }
        lps[i] = k;
    }
    return lps;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        vector<int> a = kmp(s);
        parr(a);
    }
    return 0;
}