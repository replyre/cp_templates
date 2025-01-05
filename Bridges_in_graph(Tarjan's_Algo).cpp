// what is a bridge? -> a point which when removed separates one component into 2
// tarjan's algo:
// 2 array:
// tn[]-> time of insertion
// lowt[]->lowest time of insertion among all adjacent nodes(⭐ apart from parent).

class Solution
{
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &graph, int tn[], int low[], vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        tn[node] = low[node] = timer;
        timer++;
        for (auto a : graph[node])
        {
            if (a == parent)
                continue;
            if (!vis[a])
            {
                dfs(a, node, vis, graph, tn, low, bridges);
                low[node] = min(low[node], low[a]);
                if (low[a] > tn[node])
                    bridges.push_back({a, node});
            }
            else
                low[node] = min(low[node], low[a]);
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {

        vector<vector<int>> graph(n);
        for (auto it : connections)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        int tn[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, graph, tn, low, bridges);
        return bridges;
    }
};

// Articulation point -> node whose removal breaks graph into multiple components
// tn[]-> time of insertion
// lowt[]->lowest time of insertion among all adjacent nodes(⭐ apart from parent & visited nodes and take its tn as low).

class Solution
{
    int timer = 1;

    void dfs(int node, int par, vector<int> &vis, int tn[], int lowt[], vector<int> &mark, vector<int> adj[])
    {
        vis[node] = 1;
        int children = 0;
        tn[node] = lowt[node] = timer++;
        for (auto a : adj[node])
        {

            if (a == par)
                continue;
            if (!vis[a])
            {
                children++;
                dfs(a, node, vis, tn, lowt, mark, adj);
                lowt[node] = min(lowt[node], lowt[a]);
                if (lowt[a] >= tn[node] && par != -1)
                    mark[node] = 1;
            }
            else
            {
                lowt[node] = min(lowt[node], tn[a]);
            }
        }

        if (par == -1 && children > 1)
        {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        int tn[V], lowt[V];
        vector<int> vis(V, 0);
        vector<int> mark(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(i, -1, vis, tn, lowt, mark, adj);
        }

        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            if (mark[i] == 1)
                ans.push_back(i);
        }

        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};