#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n) // T.C. : O(n^2) for wrost and average case , for best case [i.e. when array is already sorted] T.C. : O(n) , stable sorting , inplace sorting
{
    int key, i, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertionSort(A, 10);
    display(A, 10);
    return 0;
}