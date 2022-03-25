#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 105
#define sc(x) scanf("%lld", &x)
struct edge
{
    ll to, nx;
} e[mn << 1];
ll hd[mn], cnt, siz[mn], w[mn], dp[mn], n, ans = 0x7fffffff;
void adde(ll u, ll v)
{
    e[++cnt] = {v, hd[u]};
    hd[u] = cnt;
}
void dfs1(ll u, ll fa, ll d)
{
    siz[u] = w[u];
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (v == fa)
        {
            continue;
        }
        dfs1(v, u, d + 1);
        siz[u] += siz[v];
    }
    dp[1] += d * w[u];
}
void dfs2(ll u, ll fa)
{
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (v == fa)
        {
            continue;
        }
        dp[v] = dp[u] + (siz[1] - siz[v]) - siz[v];
        dfs2(v, u);
    }
    ans = min(ans, dp[u]);
}
signed main()
{
    scanf("%lld", &n);
    for (ll i = 1, x, y; i <= n; ++i)
    {
        sc(w[i]), sc(x), sc(y);
        if (x)
        {
            adde(i, x), adde(x, i);
        }
        if (y)
        {
            adde(i, y), adde(y, i);
        }
    }
    dfs1(1, 0, 0);
    dfs2(1, 0);
    printf("%lld", ans);
    return 0;
}