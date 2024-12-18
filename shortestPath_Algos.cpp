
#include <bits/stdc++.h>
using namespace std;

//-------------------------------------------- Shortest Path Algos  --------------------------------------------------------

//-------------------------------------------------- Toposort -------------------------------------------------------------
//  requirement->DAG
// TC & SC: O(V+E);

class Solution

{
public:
    stack<int> store;
    // toposort dfs
    void dfs(vector<vector<pair<int, int>>> &graph, vector<int> &vis, int i)
    {
        vis[i] = 1;
        store.push(i);
        for (auto &a : graph[i])
        {
            if (!vis[a.first])
                dfs(graph, vis, a.first);
        }
    }
    // eg:V = 4, E = 2, edge = [[0,1,2],[0,2,1]] shortest path from 0 to all nodes

    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> graph(V);
        // adding values to graph
        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        vector<int> vis(V);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(graph, vis, i);
        }
        // making all the routes [∞, ∞, ∞, ∞]
        vector<int> ans(V, INT_MAX);

        ans[0] = 0;
        while (!store.empty()) // to start for end of toposort covering max elements since it is u at top
        {
            int temp = store.top();
            store.pop();
            for (auto &a : graph[temp])
            {
                if (ans[temp] == INT_MAX)
                    continue;
                int sum = a.second + ans[temp];
                // check for minimum and updating also avoiding infinite loop
                if (sum < ans[a.first])
                {
                    ans[a.first] = min(ans[a.first], sum);
                    store.push(a.first);
                }
            }
        }
        // printing answer
        for (int i = 0; i < V; i++)
        {
            if (ans[i] == INT_MAX)
                ans[i] = -1;
        }

        return ans;
    }
};

//-------------------------------------------------- undirected BFS -----------------------------------------------------------

// TC and SC: (V+E)
class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<vector<int>> graph(N);
        queue<int> q;
        for (auto &a : edges)
        {
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }
        vector<int> dis(N, INT_MAX);
        dis[src] = 0;
        q.push(src);
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            for (auto &a : graph[temp])
            {
                if (dis[temp] + 1 < dis[a])
                {
                    dis[a] = dis[temp] + 1;
                    q.push(a);
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (dis[i] == INT_MAX)
                dis[i] = -1;
        }
        return dis;
    }
};

//------------------------------------------------ Dijkstra's Algo-----------------------------------------------------
// TC: O(E logV)
// use for weighted graphs
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    int n = adj.size();
    vector<int> dis(n, INT_MAX);
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<int, int> temp = pq.top();
        pq.pop();
        for (auto &a : adj[temp.second])
        {
            int node = a.first;
            int dis_node = a.second;
            if (dis[node] > dis[temp.second] + dis_node)
            {
                dis[node] = dis[temp.second] + dis_node;
                pq.push({dis[node], node});
            }
        }
    }

    return dis;
};

// printing the path
//  what we do is store the parent of each node if satisfy condition  in a vector, and loop over each's parent till we find the src.
// parent vector can take the respective node values at assignment but will chnage as new shorter paths will reach and it is dependent on dis vector,
// apart form src in this case 1 you can give rest any value

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<pair<int, int>>> graph(n + 1);
    if (m == 0)
        return {-1};
    for (auto a : edges)
    {
        graph[a[0]].push_back({a[1], a[2]});
        graph[a[1]].push_back({a[0], a[2]});
    }

    vector<int> dis(n, INT_MAX);
    dis[0] = 0;
    vector<int> par(n);
    for (int i = 0; i < n; i++)
        par[i] = i + 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        pair<int, int> temp = pq.top();
        pq.pop();
        for (auto &a : graph[temp.second])
        {
            if (dis[a.first - 1] > temp.first + a.second)
            {
                dis[a.first - 1] = temp.first + a.second;
                par[a.first - 1] = temp.second;
                pq.push({dis[a.first - 1], a.first});
            }
        }
    }

    stack<int> st;
    st.push(n);
    if (dis[n - 1] == INT_MAX)
        return {-1};
    while (st.top() != 1)
    {
        st.push(par[st.top() - 1]);
    }
    vector<int> ans;
    ans.push_back(dis[n - 1]);
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

// counting all shortest path, Dijsktra's + DP

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<long long, int>>> graph(n);
        for (auto &a : roads)
        {
            graph[a[0]].push_back({a[1], a[2]});
            graph[a[1]].push_back({a[0], a[2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dis(n, LLONG_MAX);
        long long mini = LLONG_MAX;
        vector<int> cnt(n, 0);

        cnt[0] = 1;
        dis[0] = 0;
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto [time, node] = pq.top();
            pq.pop();
            if (time > dis[node])
                continue;
            for (auto &a : graph[node])
            {
                // if first visit and will definitely be small count will be node and push to the queue
                if (a.second + time < dis[a.first])
                {
                    dis[a.first] = a.second + time;
                    cnt[a.first] = cnt[node];
                    pq.push({dis[a.first], a.first});
                }
                // if other route gives same dis, add the cnt,this saves from tle
                else if (a.second + time == dis[a.first])
                    cnt[a.first] = (cnt[a.first] + cnt[node]) % 1000000007;
            }
        }
        // return the max cnt
        return cnt[n - 1];
    }
};
