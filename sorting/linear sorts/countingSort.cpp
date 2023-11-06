#include <bits/stdc++.h>
using namespace std;

//  NAIVE APPROACH

/*
void countSort(int arr[], int n, int k)
{
    int count[k] = {0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    int index = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            arr[index] = i;
            index++;
        }
    }
    return;
}
*/

// BETTER APPROACH
void countSortB(int arr[], int n, int k)
{
    int count[k] = {0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    for (int i = 1; i < k; i++)
    {
        count[i] += count[i - 1];
    }
    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 6, k = 5;
    int arr[n] = {1, 4, 4, 1, 0, 1};
    // countSort(arr, n, k);
    countSortB(arr, n, k);
    display(arr, n);
    return 0;
}