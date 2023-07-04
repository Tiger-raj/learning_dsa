#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v)
// void printVec(vector <int> v)
// here also our vector of main function is copied here in this formal argument which is an expensive task as time complexity of this task is O(n), so we should avoid doing this instead use '&' to pass vector by refrence.
{
    int size = v.size();
    cout << "size : " << size << "\n";
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}
int main()
{
    /*
    vector<int> v;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x); // Time Complexicity of push_back() function is O(1) i.e. same as that of adding element to array.
        // push_back() function adds element to the end of the vector.
    }
    */
    // we can also declare size of vector during vector declaration and also initialise that size with some value.
    vector<int> v(10);    // this will initialise all 10 values with 0
    v.push_back(7);       // since size of vector is dynamic so if we push more element than declared limit then it's size will increase.
    vector<int> v2(5, 4); // this will initialise all 5 values with 4.
    // printVec(v);
    // printVec(v2);
    // v2.pop_back(); // this function removes last element from the vector v2. T.C. of pop_back() function is also : O(1)
    printVec(v2);
    // Vectors can also be copied.

    vector<int> v3 = v2;
    // T.C. of copying operation : O(n)

    v3.push_back(54); // it'll not change v2 as v3 is just copy of v2.
    printVec(v3);
    printVec(v2);
    return 0;
}