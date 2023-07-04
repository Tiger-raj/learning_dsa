#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void shellSort(int arr[], int n) // T.C. : O(n^2) for wrost case [i.e. when array is reverse sorted] and it's O(nlogn) for best and average case, not stable, inplace sorting method.
{
    int gap, i, j;
    for (gap = n / 2; gap >= 1; gap = gap / 2)
    {
        for (j = gap; j < n; j++)
        {
            for (i = j - gap; i >= 0; i = i - gap)
            {
                if (arr[i + gap] > arr[i])
                {
                    break;
                }
                else
                {
                    swap(&arr[i + gap], &arr[i]);
                }
            }
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
    shellSort(A, 10);
    display(A, 10);
    return 0;
}