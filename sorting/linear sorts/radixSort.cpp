#include <bits/stdc++.h>
using namespace std;
void countSortB(int arr[], int n, int exp)
{
    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n)
{
    int max = *max_element(arr, arr + n);
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSortB(arr, n, exp);
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
    int n = 6;
    int arr[n] = {319, 212, 6, 8, 100, 50};
    radixSort(arr, n);
    display(arr, n);
    return 0;
}