#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll s;
int ans = -1;
int a[100];
int b[100];
bool xuli(int k)
{
    ll sum = 0;
    for (int i = 1; i <= k; i++)
    {
        sum += a[b[i]];
    }
    return sum == s;
}
void quaylui(int i, int k)
{
    if (k <= n)
    {
        for (int j = b[i - 1] + 1; j <= n - k + i; j++)
        {
            b[i] = j;
            if (i == k)
            {
                if (xuli(k))
                {
                    ans = k;
                    break;
                }
                else
                    quaylui(1, k + 1);
            }
            else
                quaylui(i + 1, k);
        }
    }
}
int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    quaylui(1, 1);
    cout << ans;
}