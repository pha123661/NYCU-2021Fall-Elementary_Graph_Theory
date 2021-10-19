#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> dp;
vector<vector<long long int>> dist;
vector<int> colors;
set<int> ans;
int n, color_types;

long long int solve(int mask, int pos)
{
    // solved
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    // mask = 1's, return home
    if (mask == (1 << n) - 1)
        return dist[0][pos];

    long long int minD = INT_MAX;
    for (int k = 0; k < n; k++)
    {
        if ((mask & (1 << k)) == 0) // not visited
        {
            int new_mask = mask | (1 << k);
            long long int new_dist = dist[pos][k] + solve(new_mask, k);
            minD = min(minD, new_dist);
        }
    }
    return dp[mask][pos] = minD;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int e, tmp;
    cin >> n >> e >> color_types;

    for (int i = 0; i < color_types; i++)
    {
        cin >> tmp;
        colors.push_back(tmp);
    }

    dist = vector<vector<long long int>>(n, vector<long long int>(n, INT_MAX));
    int u, v, w;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        u--;
        v--;
        dist[u][v] = w;
        dist[v][u] = w;
    }

    dp = vector<vector<long long int>>(1 << n, vector<long long int>(n, -1));
    cout << solve(1, 0) / 2;
    return 0;
}