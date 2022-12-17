#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const ll mn = 5e3 + 10;
ll n, x[mn], y[mn], suc, vis[mn];
db d[mn], ans;
ll sol[mn]; //如果要输出方案
signed main()
{
    cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> x[i] >> y[i];
        d[i] = 1e21;
    }
    d[1] = 0;
    for (ll t = 1; t <= n - 1; ++t)
    {
        ll a = 0;
        for (ll j = 1; j <= n; ++j)
        {
            if (!vis[j] && (!a || d[j] < d[a]))
            {
                a = j;
            }
        }
        vis[a] = true;
        for (ll b = 1; b <= n; ++b)
        {
            if (!vis[b])
            {
                db dis = sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
                if (dis < d[b])
                {
                    d[b] = dis;
                    // sol[b] = a;
                }
            }
        }
    }
    for (ll i = 1; i <= n; ++i)
    {
        ans += d[i];
        // cout << i << ' ' << sol[i] << '\n'; [2,n] 有效
    }
    printf("%.2lf", ans);
    return 0;
}