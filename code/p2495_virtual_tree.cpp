#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 500010
#define mm 10000
#define big 0x3ffffffffffffffa
#define mlg 20
struct edge
{
    ll to, nx, w;
} e[mn << 1], e2[mn << 1];
ll hd[mn], hd2[mn], cnt, cnt2, n, q, k;
void adde(const ll &u, const ll &v, const ll &w, ll *hd, ll &cnt, edge *e)
{
    e[++cnt] = {v, hd[u], w};
    hd[u] = cnt;
}
ll dfn[mn], dep[mn], fa[mn][mlg], mi[mn], m[mn], lst[mn];
bool vis[mn];
ll num, top, dfscnt, stk[mn];

void dfs1(ll u)
{
    ll k = 0;
    for (; fa[u][k]; ++k)
    {
        fa[u][k + 1] = fa[fa[u][k]][k];
    }
    m[u] = k;
    dfn[u] = ++dfscnt;
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (!dfn[v])
        {
            dep[v] = dep[u] + 1;
            mi[v] = min(mi[u], e[i].w);
            fa[v][0] = u;
            dfs1(v);
        }
    }
}

ll lca(ll x, ll y)
{
    if (dep[x] < dep[y])
    {
        swap(x, y);
    }
    for (ll i = m[x]; i >= 0; --i)
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
    for (ll i = m[x]; i >= 0; --i)
    {
        if (fa[x][i] != fa[y][i])
        {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}

ll dfs2(ll u) //dp
{
    ll sum = 0;
    for (ll i = hd2[u], v; i; i = e2[i].nx)
    {
        v = e2[i].to;
        sum += dfs2(v);
    }
    ll res = vis[u] ? mi[u] : min(mi[u], sum); //vis[u] hd.d af
    hd2[u] = 0, vis[u] = false;                //clear
    return res;
}

#define sc(x) scanf("%lld", &x)
signed main()
{
    sc(n);
    for (ll i = 1, u, v, w; i < n; ++i)
    {
        sc(u), sc(v), sc(w);
        adde(u, v, w, hd, cnt, e), adde(v, u, w, hd, cnt, e);
    }
    mi[1] = big;
    dfs1(1);
    for (sc(q); q; --q)
    {
        sc(k);
        for (ll i = 1; i <= k; ++i)
        {
            sc(lst[i]), vis[lst[i]] = true;
        }
        sort(lst + 1, lst + 1 + k, [](const ll &x, const ll &y)
             { return dfn[x] < dfn[y]; });
        stk[top = 1] = lst[1];
        for (ll i = 2; i <= k; ++i)
        {
            ll now = lst[i], lc = lca(now, stk[top]);
            while (true)
            {
                if (dep[lc] >= dep[stk[top - 1]])
                {
                    if (lc != stk[top])
                    {
                        adde(lc, stk[top], 0, hd2, cnt2, e2);
                        if (lc != stk[top - 1])
                        {
                            stk[top] = lc;
                        }
                        else
                        {
                            --top;
                        }
                    }
                    break;
                }
                else
                {
                    adde(stk[top - 1], stk[top], 0, hd2, cnt2, e2);
                    --top;
                }
            }
            stk[++top] = now;
        }
        while (--top)
        {
            adde(stk[top], stk[top + 1], 0, hd2, cnt2, e2);
        }
        printf("%lld\n", dfs2(stk[1])), cnt2 = 0;
    }
    return 0;
}