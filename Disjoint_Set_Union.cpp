// Dynamic Graphs
// DSU for ranks
// 2 vectors ultimate parent[] and rank[]
// initially all ranks are 0 and parents are parent of each other

// Steps
//  find ultimate parent of v and v ( pu, pv)
// find rank of pu and pv
// connect smaller (or equal rank) to larger one always.
// increase rank of larger one if both are equal in above case

// Data Structure
#include <bits/stdc++.h>
using namespace std;
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

int main()
{ // manual test
    DisjointSet DS(7);
    // DS.unionByRank(1, 2);
    // DS.unionByRank(2, 3);
    // DS.unionByRank(4, 5);
    // DS.unionByRank(5, 6);
    // DS.unionByRank(5, 7);
    // // check for parent
    // DS.findParent(3) == DS.findParent(7) ? cout << "true" : cout << "false";
    // DS.unionByRank(3, 7);
    // DS.findParent(3) == DS.findParent(7) ? cout << "true" : cout << "false";
    DS.unionBySize(1, 2);
    DS.unionBySize(2, 3);
    DS.unionBySize(4, 5);
    DS.unionBySize(5, 6);
    DS.unionBySize(5, 7);
    // check for parent
    DS.findParent(3) == DS.findParent(7) ? cout << "true" : cout << "false";
    DS.unionBySize(3, 7);
    DS.findParent(3) == DS.findParent(7) ? cout << "true" : cout << "false";
    // DS.display_Size();
    return 0;
}