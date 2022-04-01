#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define MAXN 20002
#define MAXM 100002
struct edge
{
    ll to, nx;
} e[MAXM << 1];
ll n, m, idx, cnt, tot, hd[MAXN], dfn[MAXN], low[MAXN], ui, vi;
bool cut[MAXN];
inline void adde(ll &x, ll &y)
{
    e[++cnt] = {y, hd[x]};
    hd[x] = cnt;
}
void tarjan(ll u, ll fa)
{
    dfn[u] = low[u] = ++idx;
    ll child = 0;
    for (ll i = hd[u]; i; i = e[i].nx)
    {
        ll toi = e[i].to;
        if (!dfn[toi]) //尚未访问
        {
            tarjan(toi, fa);
            low[u] = min(low[u], low[toi]);
            if (low[toi] >= dfn[u] && u != fa)
                cut[u] = true;
            if (u == fa)
                ++child;
        }
        low[u] = min(low[u], dfn[toi]);
    }
    if (child >= 2 && u == fa)
        cut[u] = true;
}
signed main()
{
    scanf("%d%d", &n, &m);
    while(m--)
        scanf("%d%d", &ui, &vi), adde(ui, vi), adde(vi, ui);
    for(ll i = 1; i <= n; ++i) if (!dfn[i]) tarjan(i, i);
    for(ll i = 1; i <= n; ++i) if (cut[i]) ++tot;
    printf("%d\n", tot);
    for(ll i = 1; i <= n; ++i) if (cut[i]) printf("%d ", i);
    return 0;
}