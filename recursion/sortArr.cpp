#include <bits/stdc++.h>
using namespace std;
void insertEl(vector<int> &arr, int ele)
{
    if (arr.size() == 0 || arr[arr.size() - 1] <= ele)
    {
        arr.push_back(ele);
        return;
    }
    int temp = arr[arr.size() - 1];
    arr.pop_back();
    insertEl(arr, ele);
    arr.push_back(temp);
}
void sortArr(vector<int> &arr)
{
    if (arr.size() == 1)
    {
        return;
    }
    int ele = arr[arr.size() - 1];
    arr.pop_back();
    sortArr(arr);
    insertEl(arr, ele);
}

int main()
{
    vector<int> arr = {2, 1, 4, 0, 33, 87};
    sortArr(arr);
    for (auto i : arr)
        cout << i << " ";
    return 0;
}