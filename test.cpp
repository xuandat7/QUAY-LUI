#include <bits/stdc++.h>
using namespace std;
int t, n, k, a[100], b[100];
vector<vector<int>> res;
bool kt = false;
void Try(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        b[i] = j;
        if (i == n)
        {
            int s = 0;
            for (int l = 1; l <= n; l++)
            {
                if (b[l] == 1)
                {
                    s += a[l];
                }
            }
            if (s == k)
            {
                vector<int> x;
                for (int l = 1; l <= n; l++)
                {
                    if (b[l] == 1)
                    {
                        x.push_back(a[l]);
                    }
                }
                res.push_back(x);
            }
        }
        else
        {
            Try(i + 1);
        }
    }
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        res.clear();
        Try(1);
        if (res.size() == 0)
        {
            cout << -1;
        }
        else
        {
            sort(res.begin(), res.end());
            for (int i = 0; i < res.size(); i++)
            {
                cout << "[";
                for (int j = 0; j < res[i].size() - 1; j++)
                {
                    cout << res[i][j] << " ";
                }
                cout << res[i][res[i].size() - 1] << "] ";
            }
        }
        cout << endl;
    }
}