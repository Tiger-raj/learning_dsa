#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        int sum, maxi;
        maxi = max(a, max(b, c));
        sum = a + b + c + n;
        if (sum % 3 == 0 && sum / 3 >= maxi)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}