#include <bits/stdc++.h>
using namespace std;
void Insert(int arr[], int n)
{
    int temp = arr[n];
    int i = n;
    while (i > 0 && temp > arr[(i - 1) / 2])
    {
        arr[i] = arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    arr[i] = temp;
}

void Delete(int arr[], int n)
{
    int x, i, j;
    x = arr[0];
    arr[0] = arr[n];
    i = 0;
    j = 2 * i + 1;
    while (j < n - 1)
    {
        if (arr[j + 1] > arr[j])
        {
            j++;
        }
        if (arr[i] < arr[j])
        {
            swap(arr[i], arr[j]);
            i = j;
            j = j * 2 + 1;
        }
        else
        {
            break;
        }
    }
    arr[n] = x;
}
int main()
{
    int arr[7] = {5, 53, 9, 0, 1, 23, 85};
    for (int i = 1; i < 7; i++)
    {
        Insert(arr, i);
    }
    for (int i = 6; i >= 0; i--)
    {
        Delete(arr, i);
    }
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';

    return 0;
}