#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int h)
{
    int n = h - l + 1;
    int arr3[n];
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= h)
    {
        if (arr[i] <= arr[j])
        {
            arr3[k++] = arr[i++];
        }
        else
        {
            arr3[k++] = arr[j++];
        }
    }

    while (i <= m)
    {
        arr3[k++] = arr[i++];
    }

    while (j <= h)
    {
        arr3[k++] = arr[j++];
    }

    for (i = 0; i < n; i++)
    {
        arr[l + i] = arr3[i];
    }
}

void mergeSort(int arr[], int l, int h) // The best case T.C. : O(n) and worst and average case T.C. : O(nlogn), outplace sorting, stable sorting algorithm
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
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
    int A[10] = {43, 25, 5, 2, 23, 57, 9, 521, 0, 69};
    mergeSort(A, 0, 9);
    display(A, 10);
    return 0;
}