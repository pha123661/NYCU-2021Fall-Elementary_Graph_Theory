#include <bits/stdc++.h>
using namespace std;

int ln, rn;
vector<vector<int>> graph;
vector<int> R, L;
vector<bool> visited;

bool kuhn(int v)
{
    if (visited[v])
        return false;
    visited[v] = true;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int to = graph[v][i] - ln;
        if (R[to] == -1 || kuhn(R[to]))
        {
            R[to] = v;
            L[v] = to;
            return true;
        }
    }
    return false;
}

int matching()
{
    R.assign(rn, -1);
    L.assign(ln, -1);

    bool found = false;
    do
    {
        visited.assign(ln, false);
        found = false;
        for (int i = 0; i < ln; i++)
        {
            if (L[i] == -1 && !visited[i])
                found = found || kuhn(i);
        }
    } while (found);
    int ans = 0;
    for (int i = 0; i < R.size(); i++)
        if (R[i] != -1)
            ans += 1;
    return ans;
}

int main()
{
    cin.tie();
    cin.sync_with_stdio(0);
    int v1, v2, n, e;
    cin >> v1 >> v2 >> e;
    n = v1 + v2;
    ln = v1;
    rn = v2;
    int tmp;
    for (int i = 0; i < v1; i++)
        cin >> tmp;
    for (int j = 0; j < v2; j++)
        cin >> tmp;
    graph.assign(n, vector<int>());
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        v += v1;
        graph[u].push_back(v);
    }
    auto ans = matching();
    cout << ans << endl;
}