#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 500010
#define mm 20
struct edge
{
    ll to, nx;
} e[mn << 1];
ll fa[mn][mm], n, m, hd[mn], cnt, d[mn], u, v, lg[mn], s;
void adde(ll &u, ll &v)
{
    e[++cnt] = {v, hd[u]};
    hd[u] = cnt;
}
void dfs(ll h, ll faa)
{
    fa[h][0] = faa;
    d[h] = d[faa] + 1;
    for (ll i = 1; i <= lg[d[h]]; ++i)
    {
        fa[h][i] = fa[fa[h][i - 1]][i - 1];
    }
    for (ll i = hd[h]; i; i = e[i].nx)
    {
        ll toi = e[i].to;
        if (toi != faa)
            dfs(toi, h);
    }
}
ll lca(ll u, ll v)
{
    if (d[u] < d[v])
        swap(u, v);
    while (d[u] > d[v])
        u = fa[u][lg[d[u] - d[v]] - 1];
    assert(d[u] == d[v]);
    if (u == v)
        return u;
    for (ll k = lg[d[u]] - 1; k >= 0; --k)
    {
        if (fa[u][k] != fa[v][k])
        {
            u = fa[u][k];
            v = fa[v][k];
        }
    }
    return fa[u][0];
}
signed main()
{
    sc(n), sc(m), sc(s);
    for (ll i = 1; i < n; ++i)
        sc(u), sc(v), adde(u, v), adde(v, u);
    for (ll i = 1; i <= n; ++i) // 1+floor(log(,2))
        lg[i] = lg[i / 2] + 1;  //如1,2,2,3,3
    dfs(s, 0);
    while (m--)
    {
        sc(u), sc(v);
        printf("%lld\n", lca(u, v));
    }
    return 0;
}
