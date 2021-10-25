#include <bits/stdc++.h>
using namespace std;
vector<list<int>> arr;
vector<bool> visited;
vector<int> depth_count, low;
int depth;
int ans;

int dfs_util(int v, int p)
{

    visited[v] = true;
    depth_count[v] = low[v] = depth;
    depth += 1;
    for (auto u : arr[v])
    {
        if (u == p)
            continue;
        if (visited[u])
        {
            if (depth_count[u] < low[v])
                low[v] = depth_count[u];
        }
        else
        {
            dfs_util(u, v);
            if (low[u] < low[v])
                low[v] = low[u];
            if (low[u] > depth_count[v])
                ans += 1;
        }
    }
    return ans;
}

int find_bridge()
{
    ans = 0;
    depth = 0;
    int n = arr.size();
    visited = vector<bool>(n, false);
    depth_count = vector<int>(n, -1);
    low = vector<int>(n, -1);
    for (int v = 0; v < n; v++)
    {
        if (!visited[v])
            dfs_util(v, -1);
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    arr.assign(n, list<int>());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    cout << find_bridge() << endl;
}