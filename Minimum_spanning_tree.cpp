// Spanning Tree: A tree with n nodes and n-1 edges, such that all nodes are reachable from one other
//  Example:
//    2- 0 -1
//      / \
//     3   4

// Minimum sum of all the weights of edges is MST- Minimum Spanning Tree

// Prims Algo for MST
// base:
// Priority queue
// Visisted Array [wt, node, parent]
// MST list to store ans, start from any point and store the smallest dis(PQ will handle it)  and mark it as visited

// you can start with any node.

// code
#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    // Priority queue to pick the smallest edge weight
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    vector<int> vis(V, 0); // Visited array to track visited nodes
    int sum = 0;
    vector<pair<int, int>> mstEdges; // Vector to store MST edges

    // Push the initial node (weight 0, node 0, parent -1)
    pq.push({0, {0, -1}});

    while (!pq.empty())
    {
        auto [wt, edge] = pq.top(); // Smallest edge
        pq.pop();

        int node = edge.first;
        int parent = edge.second;

        // If already visited, skip
        if (vis[node])
            continue;

        // Mark as visited and add weight to the sum
        vis[node] = 1;
        sum += wt;

        // Add the edge to MST edges (skip for the initial node)
        if (parent != -1)
        {
            mstEdges.push_back({parent, node});
        }

        // Add all adjacent nodes to the priority queue
        for (auto &neighbor : adj[node])
        {
            int adjNode = neighbor[0];
            int edgeWeight = neighbor[1];
            if (!vis[adjNode])
            {
                pq.push({edgeWeight, {adjNode, node}});
            }
        }
    }

    // Debug: Print the MST edges (optional)
    cout << "MST Edges:\n";
    for (auto &edge : mstEdges)
    {
        cout << edge.first << " - " << edge.second << endl;
    }

    return sum; // Return the total weight of the MST
}
