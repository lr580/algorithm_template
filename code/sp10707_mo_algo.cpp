#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 40010
#define mm 100010
#define mlg 17
ll n, m, sq;
ll a[mn], b[mn], bs;
ll hd[mn], cnt;
struct edge
{
    ll to, nx;
} e[mn * 2];
ll ocnt, ord[mn * 2], st[mn], nd[mn], fa[mn][mlg], dep[mn], lg[mn];
struct query
{
    ll l, r, i, c;
    bool operator<(const query &x) const
    {
        if (l / sq != x.l / sq)
            return l < x.l;
        return l / sq & 1 ? r < x.r : r > x.r;
    }
} q[mm];
ll bin[mn * 2], sum, vis[mn], ans[mm];
signed main()
{
    sc(n), sc(m), sq = sqrt(n);

    for (ll i = 1; i <= n; ++i)
    {
        sc(a[i]), b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    bs = unique(b + 1, b + 1 + n) - (b + 1);
    for (ll i = 1; i <= n; ++i)
    {
        a[i] = lower_bound(b + 1, b + 1 + bs, a[i]) - b;
    }

    auto adde = [&](ll u, ll v)
    {e[++cnt]={v,hd[u]};hd[u]=cnt; };
    for (ll i = 1, u, v; i < n; ++i)
    {
        sc(u), sc(v), adde(u, v), adde(v, u);
    }
    for (ll i = 1; i <= n; ++i)
    {
        lg[i] = lg[i / 2] + 1;
    }
    auto dfs = [&](auto self, ll u) -> void
    {
        ord[++ocnt] = u;
        st[u] = ocnt;
        for (ll i = hd[u], v; i; i = e[i].nx)
        {
            if ((v = e[i].to) != fa[u][0])
            {
                dep[v] = dep[u] + 1;
                fa[v][0] = u;
                for (ll i = 1; i <= lg[dep[v]]; ++i)
                {
                    fa[v][i] = fa[fa[v][i - 1]][i - 1];
                }
                self(self, v);
            }
        }
        ord[++ocnt] = u;
        nd[u] = ocnt;
    };
    dfs(dfs, 1);

    auto lca = [&](ll u, ll v)
    {
        if (dep[u] < dep[v])
        {
            swap(u, v);
        }
        while (dep[u] > dep[v])
        {
            u = fa[u][lg[dep[u] - dep[v]] - 1];
        }
        if (u == v)
        {
            return u;
        }
        for (ll i = lg[dep[u]] - 1; i >= 0; --i)
        {
            if (fa[u][i] != fa[v][i])
            {
                u = fa[u][i], v = fa[v][i];
            }
        }
        return fa[u][0];
    };

    for (ll i = 1, l, r, c; i <= m; ++i)
    {
        sc(l), sc(r), c = lca(l, r), q[i].i = i;
        if (st[l] > st[r])
        {
            swap(l, r);
        }
        if (l == c)
        {
            q[i].l = st[l], q[i].r = st[r];
        }
        else
        {
            q[i].l = nd[l], q[i].r = st[r], q[i].c = c;
        }
    }

    sort(q + 1, q + 1 + m);
    auto work = [&](ll i)
    {
        if (vis[i])
        {
            sum -= --bin[a[i]] == 0;
        }
        else
        {
            sum += bin[a[i]]++ == 0;
        }
        vis[i] ^= 1;
    };
    for (ll i = 1, l = 1, r = 0; i <= m; ++i)
    {
        while (l < q[i].l)
            work(ord[l++]);
        while (l > q[i].l)
            work(ord[--l]);
        while (r < q[i].r)
            work(ord[++r]);
        while (r > q[i].r)
            work(ord[r--]);
        if (q[i].c)
            work(q[i].c);
        ans[q[i].i] = sum;
        if (q[i].c)
            work(q[i].c);
    }
    for (ll i = 1; i <= m; ++i)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}