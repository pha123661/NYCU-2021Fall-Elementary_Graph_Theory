#include <bits/stdc++.h>
using namespace std;

long long inf = 10000000000;

int main()
{
    int n, e, c;
    cin >> n >> e >> c;

    vector<int> color;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        color.push_back(c);
    }

    vector<vector<long long>> adj(n, vector<long long>(n, inf));
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        s -= 1;
        d -= 1;
        adj[s][d] = adj[d][s] = w;
    }

    // all pair shortest path
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    for (int cur = 0; cur < n; cur++)
    {
        long long best = inf;
        int self_color = color[cur];
        for (int i = 0; i < n; i++)
        {
            if (i == cur)
                continue;
            if (color[i] != self_color)
                best = min(best, adj[cur][i]);
        }
        cout << best << ' ';
    }
    cout << endl;
}