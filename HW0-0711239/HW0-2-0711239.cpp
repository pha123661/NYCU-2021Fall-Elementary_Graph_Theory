#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, tmp;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }

    vector<int> count(n, 0);
    for (auto m : a)
        count[m]++;

    int ans, h_max = -1;

    for (int key = 0; key < n; key++)
    {
        if (count[key] >= h_max)
        {
            h_max = count[key];
            ans = key;
        }
    }
    cout << ans << ' ' << h_max << endl;
}