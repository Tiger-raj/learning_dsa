#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
bool dfsRec(vector<int> adj[], int s, vector<bool> &visited, vector<bool> &recSt)
{
    visited[s] = true;
    recSt[s] = true;
    for (auto u : adj[s])
    {
        if (visited[u] == false && dfsRec(adj, u, visited, recSt))
        {
            return true;
        }
        else if (recSt[u] == true)
        {
            return true;
        }
    }
    recSt[s] = false;
    return false;
}
bool dfs(vector<int> adj[], int v)
{
    vector<bool> visited(v, false);
    vector<bool> recSt(v, false);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            if (dfsRec(adj, i, visited, recSt) == true)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);

    cout << dfs(adj, V);
    return 0;
}