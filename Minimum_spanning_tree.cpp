// Spanning Tree: A tree with n nodes and n-1 edges, such that all nodes are reachable from one other
//  Example:
//    2- 0 -1
//      / \
//     3   4

// Minimum sum of all the weights of edges is MST- Minimum Spanning Tree

// ------------------------------------------------------------------Prims Algo for MST--------------------------------------------------------------------------
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

// ------------------------------------------------Kruskal's Algo--------------------------------------------------------
// sort all the edges to weight
// Do DSU, if parent same means already added, no need to consider
// otherwise add it

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {

        int ult_par = findParent(u);
        int vlt_par = findParent(v);

        if (ult_par == vlt_par)
            return;
        if (rank[ult_par] < rank[vlt_par])
        {
            parent[ult_par] = vlt_par;
        }
        else if (rank[vlt_par] < rank[ult_par])
            parent[vlt_par] = ult_par;
        else
        {
            parent[vlt_par] = ult_par;
            rank[vlt_par]++;
        }
    }

    void unionBySize(int u, int v)
    {

        int ult_par = findParent(u);
        int vlt_par = findParent(v);

        if (ult_par == vlt_par)
            return;
        if (size[ult_par] < size[vlt_par])
        {
            parent[ult_par] = vlt_par;
            size[vlt_par] += size[ult_par];
        }
        else
        {
            parent[vlt_par] = ult_par;
            size[ult_par] += size[vlt_par];
        }
    }
    void display_Size()
    {
        for (int i = 0; i < size.size(); i++)
            cout << size[i];
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {

        vector<pair<int, pair<int, int>>> vt;
        for (int i = 0; i < V; i++)
        {
            for (auto &a : adj[i])
            {
                vt.push_back({a[1], {i, a[0]}});
            }
        }
        sort(vt.begin(), vt.end());
        DisjointSet DS(vt.size());
        int ans = 0;
        for (int i = 0; i < vt.size(); i++)
        {
            if (DS.findParent(vt[i].second.first) == DS.findParent(vt[i].second.second))
            {
                continue;
            }
            DS.unionByRank(vt[i].second.first, vt[i].second.second);
            ans += vt[i].first;

            // cout<<" "<<vt[i].second.first<<" "<<vt[i].second.second<<" "<<vt[i].first<<endl;
        }

        return ans;
    }
};
