#include <bits/stdc++.h>
using namespace std;

unsigned long long adj[1001][1001], dist[1001][1001];
int n, e, type;

unsigned long long minimum_cycle()
{
    for (int i = 0; i < n; i++)
        dist[i][i] = 1000000;
    unsigned long long w = 1000000;

    for (int k = 0; k < n; k++)
    {
        // min cycle for 0 ~ k-1
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (i == j)
                    continue;
                w = min(adj[j][k] + adj[k][i] + dist[i][j], w);
            }
        }
        // append point k
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
    }

    if (w != 1000000)
        return w;
    else
        return -1;
}

int main()
{
    cin.tie();
    cin.sync_with_stdio(0);
    cin >> n >> e >> type;
    memset(adj, 1000000, sizeof(adj));
    int u, v, w;
    if (type == 0)
    {
        for (int i = 0; i < e; i++)
        {
            cin >> u >> v >> w;
            u -= 1;
            v -= 1;
            adj[u][v] = adj[v][u] = w;
        }
    }
    else
    {
        for (int i = 0; i < e; i++)
        {
            cin >> u >> v >> w;
            u -= 1;
            v -= 1;
            adj[u][v] = w;
        }
    }
    memcpy(dist, adj, sizeof(adj));
    cout << minimum_cycle() << endl;
}