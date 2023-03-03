#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
int mod = 1e9 + 7;
int fun(int i, int j, const vector<vector<char>> &grid, vector<vector<int>> &dp)
{

    if (i < 0 || j < 0)
        return 0;
    if (grid.at(i).at(j) == '*')
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (dp.at(i).at(j) != -1)
        return dp.at(i).at(j);
    int up = 0, left = 0;
    up += fun(i - 1, j, grid, dp);
    left += fun(i, j - 1, grid, dp);
    return dp[i][j] = (up + left) % mod;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // cout << fun(n - 1, n - 1, grid, dp);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid.at(i).at(j) == '*')
                dp.at(i).at(j) = 0;
            else if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up += dp.at(i - 1).at(j);
                if (j > 0)
                    left += dp.at(i).at(j - 1);
                dp.at(i).at(j) = (up + left) % mod;
            }
        }
    }
    cout << dp.at(n - 1).at(n - 1) << endl;

    return 0;
}