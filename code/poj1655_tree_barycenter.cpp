#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
#define mn 20010
struct edge
{
    ll to, nx;
} e[mn << 1];
ll t, n, hd[mn], cnt, cf, cfv, siz[mn], w[mn];
void adde(ll u, ll v)
{
    e[++cnt] = {v, hd[u]};
    hd[u] = cnt;
}
#define sc(x) scanf("%lld", &x)
void dfs(ll u, ll fa)
{
    siz[u] = 1, w[u] = 0;
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (v == fa)
        {
            continue;
        }
        dfs(v, u);
        siz[u] += siz[v];
        w[u] = max(w[u], siz[v]);
    }
    w[u] = max(w[u], n - siz[u]);
    if (w[u] <= n / 2 && u < cf)
    {
        cf = u, cfv = w[u];
    }
}
signed main()
{
    for (sc(t); t; --t)
    {
        sc(n), cnt = 0, memset(hd, 0, sizeof hd), cf = n + 1;
        for (ll i = 1, u, v; i < n; ++i)
        {
            sc(u), sc(v), adde(u, v), adde(v, u);
        }
        dfs(1, 0);
        printf("%lld %lld\n", cf, cfv);
    }
    return 0;
}