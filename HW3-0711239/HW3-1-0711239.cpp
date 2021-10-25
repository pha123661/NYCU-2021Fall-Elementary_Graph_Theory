#include <bits/stdc++.h>
using namespace std;
vector<list<int>> adj;
vector<bool> visited;

void dfs_util(int v)
{
    visited[v] = true;
    for (auto u : adj[v])
        if (!visited[u])
            dfs_util(u);
}

bool connected()
{
    int n = adj.size();
    visited.assign(n, false);

    // find non-zero degree as root
    int root;
    for (root = 0; root < n; root++)
        if (adj[root].size())
            break;
    dfs_util(root);

    for (int i = 0; i < n; i++)
        if (!visited[i] && adj[i].size())
            return false;
    return true;
}

bool Eulerian_Path()
{
    if (!connected())
        return false;
    int odd_v = 0, n = adj.size();
    for (int i = 0; i < n; i++)
        if (adj[i].size() % 2)
            odd_v += 1;

    if (odd_v == 2 || odd_v == 0)
        return true;
    else
        return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj.assign(n, list<int>());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (Eulerian_Path())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}