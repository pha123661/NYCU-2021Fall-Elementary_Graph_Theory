#include <bits/stdc++.h>
#define N 200001
#define LOGN 18
// 次小生成樹
using namespace std;
class Edge
{
public:
    int u, v, w;
    Edge(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
};

int n, m, logn;

vector<int> ranks, d;
vector<vector<pair<int, int>>> G;
vector<Edge> edges, else_edges;

vector<vector<int>> cost, parents;

bool my_comp(const Edge &a, const Edge &b)
{
    return a.w < b.w;
}

int find_root(int x)
{
    if (d[x] == x)
        return x;
    else
        return d[x] = find_root(d[x]);
}

void unite(int x, int y)
{
    d[find_root(x)] = find_root(y);
}

void DFS(int u, int parent, int rank)
{
    ranks[u] = rank;
    parents[0][u] = parent;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i].first;
        int w = G[u][i].second;
        if (v != parent)
        {
            cost[0][v] = w;
            DFS(v, u, rank + 1);
        }
    }
}

void build()
{
    ranks.assign(N, 0);
    parents.assign(LOGN, vector<int>(N, 0));
    cost.assign(LOGN, vector<int>(N, 0));
    DFS(1, 0, 0);
    for (int i = 0; i < logn - 1; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            if (parents[i][u] != 0 && parents[i][parents[i][u]] != 0)
            {
                parents[i + 1][u] = parents[i][parents[i][u]];
                cost[i + 1][u] = max(cost[i][u], cost[i][parents[i][u]]);
            }
            else
            {
                parents[i + 1][u] = 0;
                cost[i + 1][u] = 0;
            }
        }
    }
}

int LCA(int u, int v)
{
    int maxx = -1;
    if (ranks[u] > ranks[v]) // swap
    {
        int tmp = u;
        u = v;
        v = tmp;
    }
    int delta = ranks[v] - ranks[u];
    for (int i = logn - 1; i >= 0; i--)
    {
        if ((delta >> i) & 1)
        {
            maxx = max(maxx, cost[i][v]);
            v = parents[i][v];
        }
    }
    if (u == v)
        return maxx;
    for (int i = logn - 1; i >= 0; i--)
    {
        if (parents[i][u] != parents[i][v])
        {
            maxx = max(maxx, max(cost[i][u], cost[i][v]));
            u = parents[i][u];
            v = parents[i][v];
        }
    }
    maxx = max(maxx, max(cost[0][u], cost[0][v]));
    return maxx;
}

int main()
{
    cin.tie();
    cin.sync_with_stdio(false);
    cin >> n >> m;
    G.assign(N, vector<pair<int, int>>());
    logn = log2(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    sort(edges.begin(), edges.end(), my_comp);
    long long ans1 = 0;
    d.assign(N, 0);
    for (int i = 0; i <= n; i++)
        d[i] = i;

    for (Edge now : edges)
    {
        int u, v, w;
        u = now.u;
        v = now.v;
        w = now.w;
        if (find_root(u) == find_root(v)) // cycle
        {
            else_edges.push_back(now);
        }
        else
        {
            ans1 += w;
            unite(u, v);
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
    }
    build();
    long long int ans2 = LLONG_MAX;
    for (Edge now : else_edges)
    {
        int u, v, w;
        u = now.u;
        v = now.v;
        w = now.w;
        ans2 = min(ans2, (ans1 + w - LCA(u, v)));
    }
    cout << ans1 << endl;
    if (ans1 != ans2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}