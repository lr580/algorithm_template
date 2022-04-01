#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 100010
#define mm 2000010
struct edge
{
    ll to, nx;
} e[mm * 2];
ll hd[mn], cnt, n, ans, dfn[mn], low[mn], st;
vector<pair<ll, ll>> res;
void adde(ll u, ll v)
{
    e[++cnt] = {v, hd[u]};
    hd[u] = cnt;
}
void tarjan(ll u, ll fa)
{
    dfn[u] = low[u] = ++st;
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (v != fa)
        {
            if (!dfn[v])
            {
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u])
                    ++ans, res.emplace_back(min(u, v), max(u, v));
            }
            else
                low[u] = min(low[u], dfn[v]);
        }
    }
}
signed main()
{
    while (EOF != scanf("%lld", &n))
    {
        cnt = ans = st = 0, res.clear();
        for (ll i = 1, m, u, v; i <= n; ++i)
        {
            hd[i] = 0, dfn[i] = low[i] = 0;
            scanf("%lld (%lld)", &u, &m), ++u;
            while (m--)
                scanf("%lld", &v), ++v, adde(u, v);
        }
        for (ll i = 1; i <= n; ++i)
            if (!dfn[i])
                tarjan(i, i);
        sort(res.begin(), res.end());
        printf("%lld critical links\n", ans);
        for (auto &i : res)
            printf("%lld - %lld\n", i.first - 1, i.second - 1);
        putchar('\n');
    }
    return 0;
}