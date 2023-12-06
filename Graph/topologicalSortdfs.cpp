#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
int flag = 0;
void dfs(vector<int> adj[], int u, stack<int> &st, vector<bool> &visited, vector<bool> &recSt)
{
    visited[u] = true;
    recSt[u] = true;
    for (auto w : adj[u])
    {
        if (visited[w] == false)
        {
            dfs(adj, w, st, visited, recSt);
        }
        else if (recSt[u] == true)
        {
            cout << "Graph conatins cycle";
            flag = 1;
        }
    }
    st.push(u);
}
void topoSort(vector<int> adj[], int v)
{
    stack<int> st;
    vector<bool> visited(v, false);
    vector<bool> recSt(v, false);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            dfs(adj, i, st, visited, recSt);
            if (flag)
            {
                return;
            }
        }
    }
    while (st.empty() != true)
    {
        int u = st.top();
        st.pop();
        cout << u << " ";
        visited[u] = true;
    }
}

int main()
{
    int V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    // addEdge(adj, 2, 0);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    topoSort(adj, V);
    return 0;
}
