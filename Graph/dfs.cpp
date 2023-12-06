#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> arr[], int a, int b)
{
    arr[a].push_back(b);
    arr[b].push_back(a);
}

void dfsRec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (int u : adj[s])
    {
        if (visited[u] == false)
        {
            dfsRec(adj, u, visited);
        }
    }
}
void dfs(vector<int> adj[], int v, int s)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    // dfsRec(adj, s, visited);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            dfsRec(adj, i, visited);
        }
    }
}

int main()
{
    int v = 6;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 5);
    addEdge(adj, 2, 4);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 5);
    // addEdge(adj, 4, 5);
    dfs(adj, v, 0);
    return 0;
}