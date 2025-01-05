// Kosaraju's algorithms

// SCC-> only directed graphs, from a start element you can reach back to that element.
// Kosaraju's algo

// sort all the edges according to finishing point ->dfs and store values in stack (like topo sort)

// reverse the graph

// do a dfs

class Solution
{
public:
    stack<int> st;

    void dfs(vector<vector<int>> &adj, vector<int> &vis, int i)
    {
        vis[i] = 1;
        for (auto a : adj[i])
        {
            if (!vis[a])
                dfs(adj, vis, a);
        }
        st.push(i);
    }
    int kosaraju(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                dfs(adj, vis, i);
        }

        vector<vector<int>> adjT(n);
        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }
        vis.assign(n, 0);
        int cnt = 0;
        while (!st.empty())
        {
            if (!vis[st.top()])
            {
                cnt++;
                dfs(adjT, vis, st.top());
            }
            st.pop();
        }

        return cnt;
    }
};