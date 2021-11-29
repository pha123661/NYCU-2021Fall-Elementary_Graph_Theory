#include <bits/stdc++.h>
#include <climits>
using namespace std;

int inf = 100000000;

int floyd(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<vector<int>> dist;
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < n; j++)
            tmp.push_back(adj[i][j]);
        dist.push_back(tmp);
    }

    int ans = inf;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < i; j++)
            {
                ans = min(ans, dist[i][j] + adj[i][k] + adj[k][j]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    if (ans == inf)
        return -1;
    else
        return ans;
}

int main()
{
    cin.tie();
    cin.sync_with_stdio(0);
    int n, e, type;
    cin >> n >> e >> type;
    if (type == 1)
    {
        vector<vector<int>> adj(n, vector<int>(n, inf));
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
        vector<vector<int>> adj(n, vector<int>(n, inf));
        for (int i = 0; i < e; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u = min(u, n) - 1;
            v = min(v, n) - 1;
            adj[u][v] = w;
            adj[v][u] = w;
        }
        cout << floyd(adj) << endl;
    }
}