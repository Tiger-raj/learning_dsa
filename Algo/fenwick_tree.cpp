#include <bits/stdc++.h>
using namespace std;
int n;
// BIT is 1 based
vector<int> bit;
void update(int id, int val)
{
    while (id <= n)
    {
        bit[id] += val;
        id += (id & -id);
    }
}
// to get range sum : [1, id]
int query(int id)
{
    int ans = 0;
    while (id > 0)
    {
        ans += bit[id];
        id -= (id & -id);
    }
    return ans;
}
int main()
{
    cin >> n;
    bit = vector<int>(n + 1, 0); // as bit array is 1 index, 0 index is not used
    vector<int> a(n + 1);        // this array is also taken 1 based here, but you can take it as 0 based but just make sure to populate the bit array correctly cuz it's always 1 indexed, just pass i+1, a[i] in that case inside the update call

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i]);
    }

    int q; // no. of queries
    cin >> q;
    while (q--)
    {
        int typeOfQuery;
        cin >> typeOfQuery;

        // find the sum in the range L to R
        if (typeOfQuery == 1)
        {
            int L, R;
            cin >> L >> R;
            int ans = query(R) - query(L - 1); // L and R need to be 1 indexed, if passed as 0 indexed just add 1 to them
            cout << ans << endl;
        }
        else
        { // Replace the value at that index ( we can also add the value at that index)
            int id, val;
            cin >> id >> val;
            update(id, -a[id]); // first make it's contribution to 0
            a[id] = val;        // update the original input array 'a'
            update(id, a[id]);  // update the bit array
        }
    }

    return 0;
}