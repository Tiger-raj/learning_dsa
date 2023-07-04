#include <iostream>
using namespace std;
int main()
{
    pair<int, string> p;
    // p = make_pair(2, "abc");
    p = {2, "abc"}; // alter method to initialise pair

    // pair<int, string> p1 = p; // copying p in p1 by value.
    // p1.first = 21;

    pair<int, string> &p1 = p; // copying p in p1 by refrence.
    p1.first = 21;             // now changing any value of p1 will change value of p also.

    cout << p1.first << endl;
    cout << p.first << " " << p.second << endl;
    return 0;
}