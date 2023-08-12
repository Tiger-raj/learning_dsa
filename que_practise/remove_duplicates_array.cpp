#include <bits/stdc++.h>
using namespace std;
void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int removeDuplicates(vector<int> &arr, int n)
{
    int newlen = n;
    int key = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == key)
        {
            newlen--;
            vector<int>::iterator it = arr.begin() + i;
            arr.erase(it);
            i--;
        }
        else
        {
            key = arr[i];
        }
    }
    display(arr);
    return newlen;
}
int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    int size;
    cin >> size;
    vector<int> arr;
    int t;
    for (int i = 0; i < size; i++)
    {
        cin >> t;
        arr.push_back(t);
    }
    cout << removeDuplicates(arr, size) << endl;
    // }
    return 0;
}