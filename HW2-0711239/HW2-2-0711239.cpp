#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    graph(int V)
    {
        v = V;
        adj = new list<pair<int, int>>[v];
    }
    void add_edge(int s, int d, int w)
    {
        adj[s].push_back(make_pair(d, w));
        adj[d].push_back(make_pair(s, w));
    }
    int get_cost(int s, vector<int> &cost)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(v, 10000000);
        pq.push(make_pair(0, s));
        dist[s] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for (auto p : adj[u])
            {
                int v = p.first, w = p.second;
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        // calculate cost
        int ans = INT_MAX;
        for (int i = 0; i < v; i++)
        {
            ans = min(ans, dist[i] + cost[i]);
        }
        return ans;
    }

private:
    int v;
    list<pair<int, int>> *adj;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, e, tmp;
    cin >> n >> e;

    graph g(n);
    vector<int> cost;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        cost.push_back(tmp);
    }

    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        s--;
        d--;
        g.add_edge(s, d, w);
    }
    for (int i = 0; i < n; i++)
        cout << g.get_cost(i, cost) << ' ';
    cout << endl;
}