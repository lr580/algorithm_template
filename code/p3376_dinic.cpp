#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 202
#define me 10002
ll n, m, s, t, hd[mn], cnt = 1, ui, vi, wi, res, tot, dep[mn];
ll q[mn], lf, rf;
struct edge
{
    ll to, v, nx;
} e[me];
bool vis[mn];
void adde(ll &u, ll &v, const ll &w)
{
    e[++cnt] = {v, w, hd[u]};
    hd[u] = cnt;
}
bool bfs()
{
    memset(dep, 0, (n + 2) * (sizeof n));
    q[lf = rf = 1] = s;
    dep[s] = 1;
    while (lf <= rf)
    {
        ll u = q[lf++];
        for (ll i = hd[u]; i; i = e[i].nx)
        {
            ll v = e[i].to;
            if (e[i].v && !dep[v])
                dep[v] = dep[u] + 1, q[++rf] = v;
        }
    }
    return dep[t];
}
ll dfs(ll u, ll flow)
{
    if (u == t)
        return flow;
    ll out = 0;
    for (ll i = hd[u]; i; i = e[i].nx)
    {
        ll v = e[i].to;
        if (e[i].v && dep[v] == dep[u] + 1)
        {
            ll res = dfs(v, min(e[i].v, flow));
            e[i].v -= res;
            e[i ^ 1].v += res;
            out += res;
            flow -= res;
        }
    }
    return !out ? (dep[u] = 0) : out;
}
signed main()
{
    scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
    for (ll i = 1; i <= m; ++i)
    {
        scanf("%lld%lld%lld", &ui, &vi, &wi);
        adde(ui, vi, wi), adde(vi, ui, 0);
    }
    while (bfs())
        tot += dfs(s, 1e18);
    printf("%lld", tot);
    return 0;
}