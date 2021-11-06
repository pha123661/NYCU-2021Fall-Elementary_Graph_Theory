#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
struct edge
{
    int u;
    int v;
    int cost;
};
#define MAX_N 200005
#define MAX_LOG_N 19
int d[MAX_N];
int groups;
void initialize(int n)
{
    for (int i = 0; i <= n; i++)
        d[i] = i;
}
int Find(int x)
{
    return d[x] == x ? x : d[x] = Find(d[x]);
}
void Union(int x, int y)
{
    groups--;
    d[Find(x)] = Find(y);
}
bool IsSame(int x, int y)
{
    return Find(x) == Find(y);
}
vector<edge> Edges;
vector<edge> NotMSTEdges;
vector<pii> G[MAX_N];
int n, m;
int logn;
int depth[MAX_N];
int maxcost[MAX_LOG_N][MAX_N];
int parent[MAX_LOG_N][MAX_N];
void DFS(int u, int par, int dep)
{
    depth[u] = dep;
    parent[0][u] = par;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i].first;
        int c = G[u][i].second;
        if (v != par)
        {
            maxcost[0][v] = c;
            DFS(v, u, dep + 1);
        }
    }
}
void build()
{
    memset(depth, 0, sizeof(depth));
    memset(parent, 0, sizeof(parent));
    memset(maxcost, 0, sizeof(maxcost));
    DFS(1, 0, 0);
    for (int i = 0; i + 1 < logn; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            if (parent[i][u] == 0 || parent[i][parent[i][u]] == 0)
            {
                parent[i + 1][u] = 0;
                maxcost[i + 1][u] = 0;
            }
            else
            {
                parent[i + 1][u] = parent[i][parent[i][u]];
                maxcost[i + 1][u] = max(maxcost[i][u], maxcost[i][parent[i][u]]);
            }
        }
    }
}
int lca(int u, int v)
{
    int mx = -1;
    if (depth[u] > depth[v])
        swap(u, v);
    int diff = depth[v] - depth[u];
    for (int i = logn - 1; i >= 0; i--)
    {
        if (diff & (1 << i))
        {
            mx = max(mx, maxcost[i][v]);
            v = parent[i][v];
        }
    }
    if (u == v)
        return mx;
    for (int i = logn - 1; i >= 0; i--)
    {
        if (parent[i][u] != parent[i][v])
        {
            mx = max(mx, max(maxcost[i][u], maxcost[i][v]));
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    mx = max(mx, max(maxcost[0][u], maxcost[0][v]));
    return mx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin >> n >> m;
    Edges.clear();
    NotMSTEdges.clear();
    for (int i = 1; i <= n; i++)
    {
        G[i].clear();
    }
    logn = log2(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        Edges.push_back({u, v, c});
    }
    sort(Edges.begin(), Edges.end(),
         [](const edge &a, const edge &b)
         {
             return a.cost < b.cost;
         });
    long long costsum = 0;
    initialize(n);
    groups = n;
    for (int i = 0; i < Edges.size(); i++)
    {
        int u = Edges[i].u;
        int v = Edges[i].v;
        int c = Edges[i].cost;
        if (!IsSame(u, v))
        {
            costsum += c;
            Union(u, v);
            G[u].push_back({v, c});
            G[v].push_back({u, c});
        }
        else
        {
            NotMSTEdges.push_back(Edges[i]);
        }
    }
    if (groups != 1)
        cout << -1 << endl;
    build();
    long long ans = LLONG_MAX;
    for (int i = 0; i < NotMSTEdges.size(); i++)
    {
        int u = NotMSTEdges[i].u;
        int v = NotMSTEdges[i].v;
        int c = NotMSTEdges[i].cost;
        ans = min(ans, (costsum + c - lca(u, v)));
    }
    cout << costsum << endl;
    if (costsum != ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
