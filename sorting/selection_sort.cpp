#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void selectionSort(int arr[], int n) //  T.C. : O(n^2) always , inplace sorting , stable sorting
{
    int min, i, j;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
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
    int n = sizeof(A) / sizeof(A[0]);
    selectionSort(A, n);
    display(A, n);
    return 0;
}