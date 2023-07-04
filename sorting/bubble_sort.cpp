#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void bubbleSort(int arr[], int n) // stable sort, inplace sort, T.C. : O(n^2) for average and wrost case , and it's O(n) for best case [i.e. when the array is already sorted]
{
    int i, j, swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped)
        {
            break;
        }
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
    bubbleSort(A, 10);
    display(A, 10);
    return 0;
}