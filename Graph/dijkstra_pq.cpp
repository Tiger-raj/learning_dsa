// Problem link : https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/0

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.

    // using priority queue DS
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V);
        for (int i = 0; i < V; i++)
            dist[i] = 1e9;
        dist[S] = 0;     // current shortest dist of node S
        pq.push({0, S}); // dist of node from source, node

        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int edgeWeight = it[1];
                int adjNode = it[0];
                if (dis + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }

    /* using set DS

     vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>> st;
        vector<int> dist(V, 1e9);

        st.insert({0,S});// dist of node from source, node
        dist[S] = 0; // current shortest dist of node S

        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            for(auto it : adj[node]){
                int edgeWeight= it[1];
                int adjNode = it[0];

                if(dis + edgeWeight < dist[adjNode]){
                    // erase if it existed already
                    if(dist[adjNode] != 1e9){
                        st.erase({dist[adjNode], adjNode});
                    }

                    dist[adjNode] = dis + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }

    */
};

// T.C. : O(ElogV),  S.C. : O(V)
int main()
{

    return 0;
}