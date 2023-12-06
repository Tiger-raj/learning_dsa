#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> arr[], int a, int b)
{
    arr[a].push_back(b);
    arr[b].push_back(a);
}
// T.C : O(V+E)
void bfs(vector<int> adj[], int v, int s, bool visited[])
{

    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u])
        {
            if (visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
void bfsDis(vector<int> adj[], int v)
{
    bool visited[v + 1];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            bfs(adj, v, i, visited);
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
    addEdge(adj, 4, 5);
    bfsDis(adj, v);
    return 0;
}
