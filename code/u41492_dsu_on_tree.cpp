#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define sc(x) scanf("%lld", &x)
#define mn 100010
ll n, m, cnt, dfn[mn], big[mn], siz[mn], tot, c[mn], ecnt, hd[mn];
ll lf[mn], rf[mn], s[mn], ans[mn], x;
struct edge
{
    ll to, nx;
} e[mn * 2];
void adde(ll u, ll v)
{
    e[++ecnt] = {v, hd[u]};
    hd[u] = ecnt;
}
void dfs1(ll u, ll fa)
{
    lf[u] = ++cnt, dfn[cnt] = u, siz[u] = 1;
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (v == fa)
        {
            continue;
        }
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[big[u]] < siz[v])
        {
            big[u] = v;
        }
    }
    rf[u] = cnt;
}
void add(ll u)
{
    tot += (s[c[u]]++ == 0);
}
void remove(ll u)
{
    tot -= (--s[c[u]] == 0);
}
void dfs2(ll u, ll fa, bool save)
{
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (v != fa && v != big[u])
        {
            dfs2(v, u, false);
        }
    }
    if (big[u])
    {
        dfs2(big[u], u, true);
    }
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (v != fa && v != big[u])
        {
            for (ll j = lf[v]; j <= rf[v]; ++j)
            {
                add(dfn[j]);
            }
        }
    }
    add(u);
    ans[u] = tot;
    if (!save)
    {
        for (ll j = lf[u]; j <= rf[u]; ++j)
        {
            remove(dfn[j]);
        }
    }
}
signed main()
{
    sc(n);
    for (ll i = 1, u, v; i < n; ++i)
    {
        sc(u), sc(v), adde(u, v), adde(v, u);
    }
    for (ll i = 1; i <= n; ++i)
    {
        sc(c[i]);
    }
    dfs1(1, 0), dfs2(1, 0, false);
    for (sc(m); m; --m)
    {
        sc(x);
        printf("%lld\n", ans[x]);
    }
    return 0;
}