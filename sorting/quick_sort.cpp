#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l, j = h;
    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[l], &arr[j]);
    return j;
}

void quickSort(int arr[], int l, int h) // Best case [when partitioning is always at middle] and average case T.C. : O(nlogn) and wrost case [when list is already sorted then partitioning is at first element then at 2nd then at 3rd and so on] T.C. : O(n^2), inplace sorting, not stable.
{
    if (l < h)
    {
        int j = partition(arr, l, h);
        quickSort(arr, l, j);
        quickSort(arr, j + 1, h);
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
    int A[11] = {43, 25, 5, 2, 23, 57, 9, 521, 0, 69, -1};
    quickSort(A, 0, 10);
    display(A, 10);
    return 0;
}