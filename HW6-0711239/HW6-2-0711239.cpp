#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int ans = 0;
vector<int> color;
vector<vector<int>> graph;

bool check_color(int v, int c)
{
    for (auto u : graph[v])
        if (color[u] == c)
            return false;
    return true;
}

void Colorable(int v, int n)
{
    if (v == n) // Done
    {
        ans += 1;
        return;
    }

    for (int c = 1; c <= 3; c++)
    {
        if (check_color(v, c))
        {
            color[v] = c;

            Colorable(v + 1, n);

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
    graph.assign(n, vector<int>());
    color.assign(n, 0);
    for (int i = 0; i < e; i++)
    {
        int s, d;
        cin >> s >> d;
        s -= 1;
        d -= 1;
        graph[s].push_back(d);
        graph[d].push_back(s);
    }

    Colorable(0, n);

    cout << ans << endl;
}