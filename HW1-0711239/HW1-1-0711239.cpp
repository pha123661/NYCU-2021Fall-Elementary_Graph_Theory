#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k, a, b, c;
    int tmp;
    cin >> n >> k >> a >> b >> c;
    vector<int> scores;
    vector<vector<int>> rsts;
    for (int i = 0; i < n; i++)
    {
        int score = 0;
        vector<int> tmpv;
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            tmpv.push_back(tmp);
            if (i == j)
                continue;
            if (tmp == 0)
                score += b;
            else if (tmp == 1)
                score += a;
            else if (tmp == 2)
                score += c;
        }
        rsts.push_back(tmpv);
        scores.push_back(score);
    }
    for (int r = 0; r < k; r++)
    {
        int i, j, new_rst, old_rst;
        cin >> i >> j >> new_rst;
        i -= 1;
        j -= 1;
        old_rst = rsts[i][j];
        if (old_rst == 0)
        {
            scores[i] -= b;
            scores[j] -= a;
        }
        else if (old_rst == 1)
        {
            scores[i] -= a;
            scores[j] -= b;
        }
        else if (old_rst == 2)
        {
            scores[i] -= c;
            scores[j] -= c;
        }

        if (new_rst == 0)
        {
            scores[i] += b;
            scores[j] += a;
            rsts[i][j] = 0;
            rsts[j][i] = 1;
        }
        else if (new_rst == 1)
        {
            scores[i] += a;
            scores[j] += b;
            rsts[i][j] = 1;
            rsts[j][i] = 0;
        }
        else if (new_rst == 2)
        {
            scores[i] += c;
            scores[j] += c;
            rsts[i][j] = 2;
            rsts[j][i] = 2;
        }

        auto ans = minmax_element(scores.begin(), scores.end());
        cout << (*(ans.second) - *(ans.first)) << ' ';
    }
}