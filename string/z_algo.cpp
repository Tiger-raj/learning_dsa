#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s)
{
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > r)
        {
            l = r = i;
            while (r < n && s[r - l] == s[r])
                r++;
            z[i] = r - l;
            r--;
        }
        else
        {
            int k = i - l;
            if (z[k] < r - i + 1)
            {
                z[i] = z[k];
            }
            else
            {
                l = i;
                while (r < n && s[r - l] == s[r])
                    r++;
                z[i] = r - l;
                r--;
            }
        }
    }
    return z;
}
int main()
{
    string s = "ababab";
    vector<int> z = z_function(s);
    return 0;
}