#include <bits/stdc++.h>
using namespace std;

void replace(string s)
{
    if (s.size() > 10)
    {
        cout << s[0] << s.size() - 2 << s[s.size()] << endl;
    }
    else
    {
        cout << s;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        replace(s);
    }
    return 0;
}