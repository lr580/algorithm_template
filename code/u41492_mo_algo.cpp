#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 100010
ll n, m, sq, ans[mn], bin[mn], sum, a[mn], hd[mn], cnt;
ll dfn[mn], st, mx[mn], id[mn];
struct query
{
    ll l, r, i;
    bool operator<(const query &x) const
    {
        if (l / sq != x.l / sq)
            return l < x.l;
        return l / sq & 1 ? r < x.r : r > x.r;
    }
} q[mn];
struct edge
{
    ll to, nx;
} e[mn * 2];
signed main()
{
    sc(n), sq = sqrt(n);
    auto adde = [&](ll u, ll v)
    { e[++cnt] = {v, hd[u]}, hd[u] = cnt; };
    for (ll i = 1, u, v; i < n; ++i)
    {
        sc(u), sc(v), adde(u, v), adde(v, u);
    }
    for (ll i = 1; i <= n; ++i)
    {
        sc(a[i]);
    }
    auto dfs = [&](auto self, ll u, ll fa) -> ll
    {
        dfn[u] = ++st, mx[u] = st, id[st] = a[u];
        for (ll i = hd[u], v; i; i = e[i].nx)
        {
            if ((v = e[i].to) != fa)
            {
                mx[u] = max(mx[u], self(self, v, u));
            }
        }
        return mx[u];
    };
    dfs(dfs, 1, 0);

    sc(m);
    for (ll i = 1, x; i <= m; ++i)
    {
        sc(x), q[i].l = dfn[x], q[i].r = mx[x], q[i].i = i;
    }
    sort(q + 1, q + 1 + m);
    auto add = [&](ll i)
    { sum += bin[id[i]]++ == 0; };
    auto del = [&](ll i)
    { sum -= --bin[id[i]] == 0; };
    for (ll i = 1, l = 1, r = 0; i <= n; ++i)
    { //不要像我一样r不初始化犯低级错误DEBUG半个钟QwQ, r=0!r=0!r=0!
        while (l > q[i].l)
            add(--l);
        while (r < q[i].r)
            add(++r);
        while (l < q[i].l)
            del(l++);
        while (r > q[i].r)
            del(r--);
        ans[q[i].i] = sum;
    }
    for (ll i = 1; i <= m; ++i)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}