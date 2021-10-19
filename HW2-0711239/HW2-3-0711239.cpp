#include <bits/stdc++.h>
using namespace std;

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