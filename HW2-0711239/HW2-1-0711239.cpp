#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    graph(int N)
    {
        n = N;
        arr = vector<vector<int>>(n, vector<int>());
    }
    void add_edge(int s, int v)
    {
        arr[s].push_back(v);
        arr[v].push_back(s);
    }
    void DFS_util(int s, int distance)
    {
        visited[s] = 1;
        if (distance > diameter)
        {
            diameter = distance;
            maxNode = s;
        }
        for (int v : arr[s])
            if (visited[v] == 0)
                DFS_util(v, distance + 1);
    }
    int find_diameter()
    {
        visited = vector<int>(n, 0);
        DFS_util(0, 0);
        // apply DFS again
        diameter = -1;
        visited = vector<int>(n, 0);
        DFS_util(maxNode, 0);

        return diameter;
    }

private:
    int n = 0, diameter = -1, maxNode = -1;
    vector<vector<int>> arr;
    vector<int> visited;
};

int main()
{
    int n, s, v;
    cin >> n;
    graph g(n);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> s >> v;
        s--;
        v--;
        g.add_edge(s, v);
    }
    cout << g.find_diameter() << endl;
}