// KAHN'S ALGORITHM

#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
void inDegree(vector<int> adj[], vector<int> &indeg, int v)
{
    for (int i = 0; i < v; i++)
    {
        for (auto u : adj[i])
        {
            indeg[u]++;
        }
    }
}
bool topologicalSort(vector<int> adj[], int v)
{
    vector<int> indeg(v);
    inDegree(adj, indeg, v);
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    int cnt = 0;
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        cnt++;
        for (auto w : adj[u])
        {
            if (--indeg[w] == 0)
            {
                q.push(w);
            }
        }
    }
    return (cnt != v);
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
    if (topologicalSort(adj, V))
    {
        cout << "\nGraph have cycle\n";
    };
    return 0;
}