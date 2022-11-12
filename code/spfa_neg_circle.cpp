//https://oj.socoding.cn/p/1885
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mn = 5e3 + 10, big = 1e18;
ll n, m, d[mn], pr[mn];
struct edge
{
    ll u, v, w;
} e[mn * 2];
bool spfa(ll s)
{
    fill_n(d, n + 3, 1e18);
    d[s] = 0;
    for (ll i = 1; i <= n; ++i)
    {
        for (ll j = 1; j <= m; ++j)
        {
            ll u = e[j].u, v = e[j].v, w = e[j].w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pr[v] = j;
            }
        }
    }
    for (ll j = 1; j <= m; ++j)
    {
        ll u = e[j].u, v = e[j].v, w = e[j].w;
        if (d[v] > d[u] + w)
        {
            ll a = u;
            for (ll i = 1; i <= n; ++i)
            {
                a = e[pr[a]].u;
            }
            stack<ll> ans;
            ans.push(a);
            for (ll b = e[pr[a]].u; b != a; b = e[pr[b]].u)
            {
                ans.push(b);
            }
            cout << "exists\n"
                 << ans.size() << '\n';
            while (!ans.empty())
            {
                ll c = ans.top();
                ans.pop();
                cout << c << ' ';
            }
            return false;
        }
    }
    cout << "not exists\n";
    return true;
}
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m;
    for (ll i = 1, u, v, w; i <= m; ++i)
    {
        cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    for (ll i = 1; i <= n; ++i)
    {
        e[++m] = {0, i, 0};
    }
    spfa(0);
    return 0;
}