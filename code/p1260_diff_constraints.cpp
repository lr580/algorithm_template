#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mn = 5e3 + 10, inf = 1e9;
ll n, d[mn], m, vis[mn], cnt[mn];
vector<pair<ll, ll>> e[mn];
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m;
    for (ll i = 1, a, b, c; i <= m; ++i)
    {
        cin >> a >> b >> c;
        e[b].push_back({a, c});
    }
    for (ll i = 1; i <= n; ++i)
    {
        e[0].push_back({i, 0});
    }
    fill_n(d, n + 3, inf);
    d[0] = 0, vis[0] = true;
    queue<ll> q;
    q.push(0);
    while (!q.empty())
    {
        ll u = q.front();
        vis[u] = false;
        q.pop();
        for (auto pr : e[u])
        {
            ll v = pr.first, w = pr.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if (!vis[v])
                {
                    if (++cnt[v] >= n + 1)
                    {
                        printf("NO SOLUTION\n");
                        return 0;
                    }
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    ll mi = *min_element(d + 1, d + 1 + n);
    for (ll u = 1; u <= n; ++u)
    {
        cout << d[u] - mi << '\n';
        for (auto pr : e[u])
        {
            ll v = pr.first, w = pr.second;
            assert(d[v] <= d[u] + w);
        }
    }
    return 0;
}