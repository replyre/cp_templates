#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define forn(i, n) for (int i = 0; i < int(n); i++)

// Topological sort
// first check for DAG ->Directed Acyclic graph (unidirection, no cycles)

// dfs
// check for all connected parts while loop over dfs
// check cycles which will eventually check for directed or not (simple)
// the answer is reversed, or use a stack to store

stack<int> ans;
bool topo_dfs(vector<vector<int>> &adj, vector<int> &vis, int i)
{
    vis[i] = 2;

    for (auto &a : adj[i])
    {
        if (!vis[a])
        {
            if (topo_dfs(adj, vis, a))
                return true;
        }
        else if (vis[a] == 2)
            return true;
    }
    vis[i] = 1;
    ans.push(i);
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // course schedule problem LC:210 {v,u} -> u must be completed before v, that is dependency, i.e., u is visited before v(basic idea for topo sort)
    vector<vector<int>> graph = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    // other eg1 : {{5, 0}, {4, 0}, {4, 1}, {5, 2}, {2, 3}, {3, 1}};
    // eg2 : {{1, 0}, {2, 0}, {3, 1}, {3, 2}, {0, 3}};
    vector<vector<int>> adj(4);
    vector<int> vis(4, 0);
    for (auto &a : graph)
    {
        adj[a[1]].push_back(a[0]);
    }

    // ---------------------------------------------dfs-----------------------------------------------------------

    // for (int i = 0; i < adj.size(); i++)
    // {
    //     if (!vis[i])
    //     {
    //         if (topo_dfs(adj, vis, i))
    //         {
    //             cout << -1;
    //             return 0;
    //         }
    //     }
    // }

    // while (!ans.empty())
    // {
    //     cout << ans.top() << " ";
    //     ans.pop();
    // }

    // ---------------------------------------------------bfs-----------------------------------------------------
    // kahn's algo
    // get all indegree (coming to)
    // if res values size !=total size return -1 (it's cyclic)
    // if the question asks to find the nodes without cycle or something use outdegree or reverse the graph
    int N = adj.size();
    int indegree[N] = {0};
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        for (auto &it : adj[i])
        {
            indegree[it]++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for (auto &it : adj[temp])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    if (ans.size() != N)
        cout << -1;
    for (auto a : ans)
        cout << a << " ";
    return 0;
}
