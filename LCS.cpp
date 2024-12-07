int dp[10001][10001]; // maxlimit: 10^4*10^4

// recursion + dp (memoization)
int LCS(string &s1, string &s2, int i, int j)
{
    if (i == s1.size() || j == s2.size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
        return dp[i][j] = 1 + LCS(s1, s2, i + 1, j + 1);
    else
        return dp[i][j] = max(LCS(s1, s2, i + 1, j), (LCS(s1, s2, i, j + 1)));
}

// dp tabulation
int longestCommonSubsequence(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int _t;cin>>_t; while(_t--)
    memset(dp, -1, sizeof(dp));
    string s1 = "bl";
    string s2 = "yby";

    cout << LCS(s1, s2, 0, 0);

    return 0;
}
