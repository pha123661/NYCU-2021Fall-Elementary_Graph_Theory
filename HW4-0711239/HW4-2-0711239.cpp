#include <bits/stdc++.h>
using namespace std;

int s, t;
int v1, v2, e, vnum;
int graph[4020][4020], res[4020][4020];

bool bfs(int parent[])
{
    memset(parent, -1, sizeof(int) * vnum);
    vector<bool> visited(vnum, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u;
        u = q.front();
        q.pop();
        for (int v = vnum - 1; v >= 0; v--)
        {
            if (!visited[v] && res[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
                if (v == t)
                    break;
            }
            if (visited[v] && (v == t))
                break;
        }
    }
    return (visited[t] == true);
}

int ff()
{
    int u, v;
    for (int i = 0; i < vnum; i++)
        for (int j = 0; j < vnum; j++)
            res[i][j] = graph[i][j];
    int parent[vnum];
    int max_flow = 0;

    while (bfs(parent))
    {
        int path_flow = 1000000;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, res[u][v]);
        }
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            res[u][v] -= path_flow;
            res[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main()
{
    cin.tie();
    cin.sync_with_stdio(0);
    memset(graph, 0, sizeof(graph));
    cin >> v1 >> v2 >> e;
    s = 0;
    t = v1 + v2 + 1;
    vnum = v1 + v2 + 2;
    for (int i = 1; i <= v1; i++)
    {
        int w;
        cin >> w;
        graph[s][i] = w;
    }
    for (int j = v1 + 1; j <= v1 + v2; j++)
    {
        int w;
        cin >> w;
        graph[j][t] = w;
    }
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        v += v1;
        graph[u][v] = 1;
    }
    cout << ff() << endl;
    return 0;
}