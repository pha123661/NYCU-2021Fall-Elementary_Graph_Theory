#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> cartesian(vector<vector<int>> &v)
{
    vector<vector<int>> ret;
    auto product = [](long long a, vector<int> &b)
    { return a * b.size(); };
    const long long N = accumulate(v.begin(), v.end(), 1LL, product);
    vector<int> u(v.size());
    for (long long n = 0; n < N; ++n)
    {
        lldiv_t q{n, 0};
        for (long long i = v.size() - 1; 0 <= i; --i)
        {
            q = div(q.quot, v[i].size());
            u[i] = v[i][q.rem];
        }
        ret.push_back(u);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, e, k;
    cin >> n >> e >> k;
    vector<vector<int>> colors_cities(k, vector<int>()); // colors_cities[color] = vector of cities
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        tmp -= 1;
        colors_cities[tmp].push_back(i);
    }
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u -= 1;
        v -= 1;
        dist[u][v] = dist[v][u] = w;
    }
    vector<vector<int>> colors_product = cartesian(colors_cities);
    long long int min_cost = INT_MAX;
    for (auto v : colors_product)
    {
        do
        {
            long long int cost = 0;
            for (int i = 1; i < v.size(); i++)
                cost += dist[v[i - 1]][v[i]];
            min_cost = min(cost, min_cost);
        } while (next_permutation(v.begin(), v.end()));
    }
    cout << min_cost << endl;
    return 0;
}
