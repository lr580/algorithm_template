#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define big 0x3ffffffa
#define mn 100010
ll read() {ll r; scanf("%d", &r); return r; }
struct edge
{
    ll to, nx, w;
} e[mn << 1];
ll hd[mn], cnt, n, m, u, v, w, d[mn], s, vis[mn];
void adde(ll &u, ll &v, ll &w)
{
    e[++cnt] = {v, hd[u], w};
    hd[u] = cnt;
}
struct node
{
    ll i, d;
    bool operator<(const node &x) const { return d > x.d; }
};
priority_queue<node> q;
signed main()
{
    n = read(), m = read(), s = read();
    for (ll i = 1; i <= m; ++i)
        u = read(), v = read(), w = read(), adde(u, v, w);
    memset(d, 127, sizeof d);
    d[s] = 0;
    q.push({s, 0});
    while (!q.empty())
    {
        node p = q.top();
        q.pop();
        if (vis[p.i])
            continue;
        vis[p.i] = true;
        for (ll i = hd[p.i]; i; i = e[i].nx)
        {
            ll toi = e[i].to;
            if (d[toi] > d[p.i] + e[i].w)
            {
                d[toi] = d[p.i] + e[i].w;
                q.push({toi, d[toi]});
            }
        }
    }
    for (ll i = 1; i <= n; ++i)
        printf("%d ", d[i]);
    return 0;
}