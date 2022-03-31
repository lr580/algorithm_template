#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 5010
#define me 200010
struct
{
    ll to, nx, w;
} e[me * 2];
ll hd[mn], cnt, d[mn], ans, suc, n, m, vis[mn];
void adde(ll u, ll v, ll w)
{
    e[++cnt] = {v, hd[u], w};
    hd[u] = cnt;
}
typedef pair<ll, ll> pr; // first:w, second:i
priority_queue<pr, vector<pr>, greater<pr>> q;
signed main()
{
    sc(n), sc(m);
    for (ll i = 1, u, v, w; i <= m; ++i)
        sc(u), sc(v), sc(w), adde(u, v, w), adde(v, u, w);
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    q.push({0, 1});
    while (!q.empty() && suc <= n - 1)
    {
        ll w = q.top().first, u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        ans += w, vis[u] = true, ++suc;
        for (ll i = hd[u], v; i; i = e[i].nx)
        {
            v = e[i].to;
            if (e[i].w < d[v])
                d[v] = e[i].w, q.push({d[v], v});
        }
    }
    suc == n ? printf("%lld", ans) : printf("orz");
    return 0;
}