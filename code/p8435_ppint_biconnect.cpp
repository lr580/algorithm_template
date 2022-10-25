#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mn = 5e5 + 10;
ll n, m, dfn[mn], low[mn], st, stk[mn], stop, cn;
vector<ll> c[mn], g[mn];
void tarjan(ll u, ll fa)
{
    ll son = 0;
    dfn[u] = low[u] = ++st;
    stk[++stop] = u;
    for (auto v : g[u])
    {
        if (!dfn[v])
        {
            ++son;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u])
            {
                c[++cn].push_back(u);
                for (ll w = 0; w != v;)
                {
                    w = stk[stop--];
                    c[cn].push_back(w);
                }
            }
        }
        else
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (!fa && !son)
    {
        c[++cn].push_back(u);
    }
}
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m;
    for (ll i = 1, u, v; i <= m; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    for (ll i = 1; i <= n; ++i)
    {
        if (!dfn[i])
        {
            stop = 0, tarjan(i, 0);
        }
    }
    cout << cn << '\n';
    for (ll i = 1; i <= cn; ++i)
    {
        cout << c[i].size() << ' ';
        for (auto u : c[i])
        {
            cout << u << ' ';
        }
        cout << '\n';
    }
    return 0;
}
