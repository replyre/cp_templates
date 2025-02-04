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

// for removal of duplicates use : ⭐ sort and if (j > i && candidates[j] == candidates[j - 1]) continue;

class Solution
{
public:
    vector<vector<int>> ans;

    void CombinedSum2(vector<int> &candidates, int target, int i, vector<int> &temp)
    {

        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }

        for (int j = i; j < candidates.size(); j++)
        {
            // note: the removal of duplicates
            if (j > i && candidates[j] == candidates[j - 1])
                continue;
            if (candidates[j] > target)
                break;

            temp.push_back(candidates[j]);
            CombinedSum2(candidates, target - candidates[j], j + 1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {

        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        CombinedSum2(candidates, target, 0, temp);
        return ans;
    }
};