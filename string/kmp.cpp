#include <bits/stdc++.h>
using namespace std;

void lps_fill(string str, vector<int> &lps)
{
    int n = size(str);
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
    return;
}
vector<int> kmp(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();
    vector<int> lps(M, 0);
    lps_fill(pat, lps);
    int i = 0, j = 0;
    vector<int> ans;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            i++;
            j++;
        }
        if (j == M)
        {
            ans.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return ans;
}
int main()
{
    string txt = "abcabcdefdabgabcfhi";
    string pat = "abc";
    vector<int> ans = kmp(pat, txt);
    for (auto it : ans)
        cout << it << " ";

    return 0;
}