#include <bits/stdc++.h>
using namespace std;

// undirected graph
void addEdge(vector<int> arr[], int a, int b)
{
    arr[a].push_back(b);
    arr[b].push_back(a);
}

void printAdj(vector<int> arr[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << "Adjacent of " << i << ": ";
        for (auto ele : arr[i])
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}
int main()
{
    int v = 4;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    printAdj(adj, v);
    return 0;
}