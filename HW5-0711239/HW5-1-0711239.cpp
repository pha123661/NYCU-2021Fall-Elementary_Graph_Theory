#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    cin.tie();
    cin.sync_with_stdio(0);
    int n, e, type;
    cin >> n >> e >> type;
    if (type == 1)
    {
        vector<vector<int>> adj(n, vector<int>(n, 100000000));
        for (int i = 0; i < e; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u = min(u, n) - 1;
            v = min(v, n) - 1;
            adj[u][v] = w;
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (adj[i][j] > adj[i][k] + adj[k][j])
                        adj[i][j] = adj[i][k] + adj[k][j];
        int ans = numeric_limits<int>::max();
        for (int i = 0; i < n; i++)
            ans = min(ans, adj[i][i]);
        if (ans != numeric_limits<int>::max())
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    else
    {
    }
}