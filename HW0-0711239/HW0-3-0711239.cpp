#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n, a, b, c;
    int tmp;
    cin >> n >> a >> b >> c;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
    {
        long long int score = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            if (i == j)
                continue;
            if (tmp == 0)
                score += b;
            else if (tmp == 1)
                score += a;
            else if (tmp == 2)
                score += c;
        }
        cout << score << ' ';
    }
    cout << endl;
}