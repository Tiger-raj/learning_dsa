#include <bits/stdc++.h>
using namespace std;

vector<int> compute_pi(string pat)
{
    int n = pat.length();
    vector<int> pi(n);
    pi[0] = 0;
    for (int i = 1; i < n; i++)
    {
        pi[i] = 0;
        int j = pi[i - 1]; /* trying length j + 1 */
        while (j > 0 && pat[j] != pat[i])
        {
            j = pi[j - 1];
        }
        if (pat[j] == pat[i])
        {
            pi[i] = j + 1;
        }
    }
    return pi;
}

vector<int> find_matches(string text, string pat)
{
    int n = pat.length(), m = text.length();
    string s = pat + "$" + text;
    vector<int> pi = compute_pi(s), ans;
    for (int i = n + 1; i <= n + m; i++)
    { /* n + 1 is where the text starts */
        if (pi[i] == n)
        {
            ans.push_back(i - 2 * n); /* i - (n - 1) - (n + 1) */
        }
    }
    return ans;
}

int main()
{

    return 0;
}
