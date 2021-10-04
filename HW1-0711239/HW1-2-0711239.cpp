#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    graph(int V)
    {
        v = V;
        adj = vector<vector<int>>(V, vector<int>());
    }
    void add_edge(int s, int d)
    {
        s -= 1;
        d -= 1;
        adj[s].push_back(d);
        adj[d].push_back(s);
    }
    pair<int, int> color_bfs(int s)
    {
        vector<int> color(v, -1), ans(2, 0);
        color[s] = 1;
        ans[color[s]] += 1;
        queue<int> q;
        q.push(s);

        while (!q.empty())
        {
            int w = q.front();
            q.pop();
            for (int d : adj[w])
            {
                if (color[d] == -1)
                {
                    color[d] = 1 - color[w];
                    ans[color[d]] += 1;
                    q.push(d);
                }
                else if (color[d] == color[w])
                    return make_pair(-1, -1);
            }
        }
        return make_pair(ans[1], ans[0]);
    }
    int v;
    vector<vector<int>> adj;
};

int main()
{
    int n, m;
    cin >> n >> m;
    graph g(n);
    for (int i = 0; i < m; i++)
    {
        int s, d;
        cin >> s >> d;
        g.add_edge(s, d);
    }
    auto ans = g.color_bfs(0);
    if (ans.first != -1)
        cout
            << ans.first << ' ' << ans.second << endl;
    else
        cout << -1;
}