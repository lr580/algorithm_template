#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mn = 1e2 + 10;
ll n, m, d[mn][mn], nx[mn][mn];
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    memset(d, 0x3f, sizeof d);
    for (ll i = 1; i <= n; ++i)
    {
        d[i][i] = 0, nx[i][i] = i;
    }
    for (ll i = 1, u, v, w; i <= m; ++i)
    {
        cin >> u >> v >> w;
        d[u][v] = w, nx[u][v] = v;
    }
    for (ll k = 1; k <= n; ++k)
    {
        for (ll i = 1; i <= n; ++i)
        {
            for (ll j = 1; j <= n; ++j)
            {
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    nx[i][j] = nx[i][k];
                }
            }
        }
    }
    ll q;
    cin >> q;
    for (ll u, v; q--;)
    {
        cin >> u >> v;
        cout << u << ' ';
        while (u != v)
        {
            cout << nx[u][v] << ' ';
            u = nx[u][v];
        }
        cout << '\n';
    }
    return 0;
}
/*
5 5
1 2 1
2 3 2
3 4 1
1 5 1
5 3 1
1
1 4
*/