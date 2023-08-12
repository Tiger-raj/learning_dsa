#include <bits/stdc++.h>
using namespace std;
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int removeDuplicates(int arr[], int n)
{
    // WHAT I DID

    /*
  int newlen = n;
  int count = 0;
  int key = arr[0];
  int ikey = 0;
  for (int i = 1; i < n; i++)
  {
      if (arr[i] == key)
      {
          count++;
          newlen--;
      }
      else
      {
          if (count)
          {
              swap(arr[ikey + 1], arr[i]);
              key = arr[ikey + 1];
              ikey++;
              count = 0;
          }
          else
          {
              if (i - ikey > 1)
              {
                  swap(arr[ikey + 1], arr[i]);
                  key = arr[ikey + 1];
                  ikey++;
              }
              else
              {

                  key = arr[i];
                  ikey = i;
              }
          }
      }
  }
  display(arr, newlen);
  return newlen;
  */

    // WHAT I SHOULD HAVE DONE :/
    // TWO POINTER APPROACH

    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    display(arr, i + 1);
    return i + 1;
}
int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << removeDuplicates(arr, size) << endl;
    return 0;
}