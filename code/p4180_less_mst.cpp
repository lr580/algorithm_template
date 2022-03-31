#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 400010
#define ml 19
#define big 0x7fffffffffffff
struct edge
{
    ll u, v, w, nx;
    bool operator<(const edge &x) const { return w < x.w; }
} e[mn << 1], a[mn << 1];
ll cnt, hd[mn], fa[mn][ml], mx[mn][ml], nd[mn][ml], dep[mn], n, m, ffa[mn];
bool vis[mn << 1];
void adde(ll &u, ll &v, ll &w)
{
    e[++cnt] = {u, v, w, hd[u]};
    hd[u] = cnt;
}
void dfs(ll u, ll f)
{
    fa[u][0] = f;
    for (ll i = hd[u]; i; i = e[i].nx)
    {
        ll v = e[i].v;
        if (v == f)
        {
            continue;
        }
        dep[v] = dep[u] + 1;
        mx[v][0] = e[i].w;
        nd[v][0] = -big;
        dfs(v, u);
    }
}
void cal()
{
    for (ll i = 1; i < ml; ++i)
    {
        for (ll j = 1; j <= n; ++j)
        {
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
            mx[j][i] = max(mx[j][i - 1], mx[fa[j][i - 1]][i - 1]);
            nd[j][i] = max(nd[j][i - 1], nd[fa[j][i - 1]][i - 1]);
            if (mx[j][i - 1] != mx[fa[j][i - 1]][i - 1])
            {
                nd[j][i] = max(nd[j][i], min(mx[j][i - 1], mx[fa[j][i - 1]][i - 1]));
            }
        }
    }
}
ll lca(ll x, ll y)
{
    if (dep[x] < dep[y])
    {
        swap(x, y);
    }
    for (ll i = ml - 1; i >= 0; --i)
    {
        if (dep[fa[x][i]] >= dep[y])
        {
            x = fa[x][i];
        }
    }
    if (x == y)
    {
        return x;
    }
    for (ll i = ml - 1; i >= 0; --i)
    {
        if (fa[x][i] ^ fa[y][i])
        {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}
ll qmax(ll u, ll v, ll mxv)
{
    ll ans = -big;
    for (ll i = ml - 1; i >= 0; --i)
    {
        if (dep[fa[u][i]] >= dep[v])
        {
            if (mxv != mx[u][i])
            {
                ans = max(ans, mx[u][i]);
            }
            else
            {
                ans = max(ans, nd[u][i]);
            }
            u = fa[u][i];
        }
    }
    return ans;
}
ll finds(ll x)
{
    while (x != ffa[x])
    {
        x = ffa[x] = ffa[ffa[x]];
    }
    return x;
}
signed main()
{
    sc(n), sc(m);
    for (ll i = 1; i <= m; ++i)
    {
        sc(a[i].u), sc(a[i].v), sc(a[i].w);
    }
    sort(a + 1, a + 1 + m);
    for (ll i = 1; i <= n; ++i)
    {
        ffa[i] = i;
    }
    ll suc = 0, res = big;
    for (ll i = 1; i <= m; ++i)
    {
        ll fu = finds(a[i].u), fv = finds(a[i].v);
        if (fu != fv)
        {
            suc += a[i].w;
            ffa[fu] = fv, vis[i] = true;
            adde(a[i].u, a[i].v, a[i].w), adde(a[i].v, a[i].u, a[i].w);
        }
    }
    nd[1][0] = -big, dep[1] = 1;
    dfs(1, -1), cal();
    for (ll i = 1, u, v, w, ca, mxu, mxv; i <= m; ++i)
    {
        if (!vis[i])
        {
            u = a[i].u, v = a[i].v, w = a[i].w;
            ca = lca(u, v);
            mxu = qmax(u, ca, w), mxv = qmax(v, ca, w);
            res = min(res, suc - max(mxu, mxv) + w);
        }
    }
    printf("%lld", res);
    return 0;
}