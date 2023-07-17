#include <bits/stdc++.h>
using namespace std;
int main()
{
    // vector<int> v = {2, 3, 52, 4};
    // v.emplace_back(55);
    // vector<int>::iterator it = v.begin();
    // // cout << *(it) << " ";
    // // it++;
    // // cout << *(it) << endl;
    // // cout << v.back();
    // for (auto i = v.begin(); i != v.end(); i++) // when using auto the datatype is automatically assigned to the variable according to the value stored.
    // {
    //     cout << *(i) << " ";
    // }
    int num = 7;
    int cnt = __builtin_popcount(num);
    cout << cnt;
    return 0;
}