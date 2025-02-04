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

// freopen('input.txt', 'r', stdin);
// freopen('output.txt', 'w', stdout);

// method 1 using vis array, ( method 2 is better)
class Solution
{
public:
    vector<vector<int>> ans;

    void findper(vector<int> &nums, vector<int> &temp, vector<int> &vis)
    {
        if (temp.size() == nums.size())
        {
            ans.push_back(temp); // Store the valid permutation
            return;
        }

        for (int j = 0; j < nums.size(); j++)
        {
            if (!vis[j])
            {
                vis[j] = 1;              // Mark as used
                temp.push_back(nums[j]); // Select element

                findper(nums, temp, vis); // Recurse

                temp.pop_back(); // Undo selection (backtrack)
                vis[j] = 0;      // Mark as unused
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> temp;
        vector<int> vis(nums.size(), 0);

        findper(nums, temp, vis);
        return ans;
    }
};

// better Method (using swap)

class Solution
{
public:
    vector<vector<int>> ans;

    void findper(vector<int> &nums, int i)
    {
        if (i == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            findper(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        findper(nums, 0);
        return ans;
    }
};

// imp removing duplicates using set as due to swap consecutive check fails

class Solution
{
public:
    vector<vector<int>> ans;

    void findper(vector<int> &nums, int i)
    {
        if (i == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> seen;
        for (int j = i; j < nums.size(); j++)
        {
            if (seen.count(nums[j]))
                continue;
            seen.insert(nums[j]);

            swap(nums[i], nums[j]);
            findper(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        findper(nums, 0);
        return ans;
    }
};
