#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 5010
#define me 200010
struct edge
{
    ll u, v, w;
    bool operator<(const edge &r) const { return w < r.w; }
} e[me];
ll fa[mn], n, m, suc, ans;
ll findf(ll x)
{
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}
signed main()
{
    sc(n), sc(m);
    for (ll i = 1; i <= m; ++i)
        sc(e[i].u), sc(e[i].v), sc(e[i].w);
    sort(e + 1, e + 1 + m);
    for (ll i = 1; i <= n; ++i)
        fa[i] = i;
    for (ll i = 1, fu, fv; i <= m && suc <= n - 1; ++i)
    {
        fu = findf(e[i].u), fv = findf(e[i].v);
        if (fu != fv)
            fa[fu] = fv, ans += e[i].w, ++suc;
    }
    suc == n - 1 ? printf("%lld", ans) : printf("orz");
    return 0;
}