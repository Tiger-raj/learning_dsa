#include <bits/stdc++.h>
using namespace std;

//  T.C. : O(V+E) most optimized way to get shortest path from a single source to all nodes using topological sort and relaxing all adjacent of each nodes in topological sorted array of nodes.
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
vector<int> topologicalSort(vector<int> adj[], int v)
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
    // int cnt = 0;
    vector<int> topoOrder;
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        // cout << u << " ";
        topoOrder.push_back(u);
        // cnt++;
        for (auto w : adj[u])
        {
            if (--indeg[w] == 0)
            {
                q.push(w);
            }
        }
    }
    // return (cnt != v);
    return topoOrder;
}

vector<int> shortestPath(vector<int> adj[], int s, int v, vector<vector<int>> weight)
{
    vector<int> dist(v, INT_MAX);
    dist[s] = 0;
    vector<int> topoOrder = topologicalSort(adj, v);
    for (auto u : topoOrder)
    {
        for (auto w : adj[u])
        {
            if (dist[w] > dist[u] + weight[u][w])
            {
                dist[w] = dist[u] + weight[u][w];
            }
        }
    }
    return dist;
}
int main()
{
    int V = 6;
    vector<int> adj[V];
    vector<vector<int>> weight(V, vector<int>(V, 0));
    addEdge(adj, 0, 1);
    weight[0][1] = 2;
    addEdge(adj, 0, 4);
    weight[0][4] = 1;
    addEdge(adj, 1, 2);
    weight[1][2] = 3;
    addEdge(adj, 4, 2);
    weight[4][2] = 2;
    addEdge(adj, 2, 3);
    weight[2][3] = 6;
    addEdge(adj, 4, 5);
    weight[4][5] = 4;
    addEdge(adj, 5, 3);
    weight[5][3] = 1;
    vector<int> dist = shortestPath(adj, 0, V, weight);
    for (auto i : dist)
    {
        cout << i << " ";
    }
    // if (topologicalSort(adj, V))
    // {
    //     cout << "\nGraph have cycle\n";
    // };
    return 0;
}