#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mn = 1e2 + 10, inf = 1e9;
ll n, d[mn], m, vis[mn], cnt[mn];
vector<pair<ll, ll>> e[mn];
void solve()
{
    cin >> n >> m;
    for (ll i = 0; i <= n; ++i)
    {
        e[i].clear();
    }
    for (ll i = 1, a, b, c; i <= m; ++i)
    {
        cin >> a >> b >> c;
        e[b].push_back({a - 1, -c});
        e[a - 1].push_back({b, c});
    }
    fill_n(d, n + 3, inf), fill_n(vis, n + 3, 0), fill_n(cnt, n + 3, 0);
    auto spfa = [&](ll s)
    {
        d[s] = 0, vis[s] = true;
        queue<ll> q;
        q.push(s);
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
                            return false;
                        }
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        return true;
    };
    bool fail = false;
    for (ll i = 0; i <= n; ++i)
    {
        if (!cnt[i])
        {
            fail |= spfa(i) == false;
        }
    }
    cout << (fail ? "false\n" : "true\n");
}
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}