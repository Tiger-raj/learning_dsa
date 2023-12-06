// detect cycle in an undirected graph using dfs

#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> arr[], int a, int b)
{
    arr[a].push_back(b);
    arr[b].push_back(a);
}

bool dfsRec(vector<int> adj[], int s, bool visited[], int parent)
{
    visited[s] = true;
    for (auto u : adj[s])
    {
        if (visited[u] == false)
        {
            if (dfsRec(adj, u, visited, s) == true)
            {
                return true;
            }
        }
        else if (u != parent)
        {
            return true;
        }
    }
    return false;
}
bool dfs(vector<int> adj[], int v)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            if (dfsRec(adj, i, visited, -1) == true)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int v = 2;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    // addEdge(adj, 0, 2);
    // addEdge(adj, 0, 5);
    // addEdge(adj, 2, 4);
    // addEdge(adj, 1, 3);
    // addEdge(adj, 3, 5);
    if (dfs(adj, v))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}