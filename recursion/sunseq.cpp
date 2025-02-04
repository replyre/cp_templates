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

// print values
void subseq(vector<int> &arr, int i, vector<int> &ans)
{
    if (i == arr.size())
    {
        for (auto a : ans)
            cout << a;
        cout << endl;
        return;
    }
    ans.push_back(arr[i]);
    subseq(arr, i + 1, ans);
    ans.pop_back();
    subseq(arr, i + 1, ans);
}

// for sum
void subseqsum(vector<int> &arr, int i, int sum)
{
    if (i == arr.size())
    {
        cout << sum << endl;
        return;
    }
    sum += arr[i];
    subseqsum(arr, i + 1, sum);
    sum -= arr[i];
    subseqsum(arr, i + 1, sum);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int _t;cin>>_t; while(_t--)
    vector<int> arr = {1, 2, 3};
    vector<int> ans;
    // subseq(arr, 0, ans);
    int sum = 0;
    subseqsum(arr, 0, sum);
    return 0;
}