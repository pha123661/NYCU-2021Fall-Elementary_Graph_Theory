#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int ans = 0;

bool check_color(vector<vector<int>> &graph, vector<int> &color, int v, int c)
{
    for (auto u : graph[v])
        if (color[u] == c)
            return false;
    return true;
}

void Colorable(vector<vector<int>> &graph, vector<int> &color, int v, int n)
{
    if (v == n) // Done
    {
        ans += 1;
        return;
    }

    for (int c = 1; c <= 3; c++)
    {
        if (check_color(graph, color, v, c))
        {
            color[v] = c;

            Colorable(graph, color, v + 1, n);

            color[v] = 0;
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    if (e == 0)
    {
        cout << int(pow(3, n)) << endl;
        return 0;
    }
    vector<vector<int>> graph(n, vector<int>());

    for (int i = 0; i < e; i++)
    {
        int s, d;
        cin >> s >> d;
        s -= 1;
        d -= 1;
        graph[s].push_back(d);
        graph[d].push_back(s);
    }
    vector<int> color(n, 0);
    Colorable(graph, color, 0, n);

    cout << ans << endl;
}