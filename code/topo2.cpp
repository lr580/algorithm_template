#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 100010
struct edge
{
    ll to, nx;
    edge(ll a = 0, ll b = 0) : to(a), nx(b) {}
} e[mn * 2];
ll hd[mn], cnt, n, m, du[mn];
void adde(ll u, ll v)
{
    e[++cnt] = edge(v, hd[u]);
    ++du[v], hd[u] = cnt;
}
signed main()
{
    sc(n);
    for (ll i = 1, u, v; i <= n; ++i)
        sc(u), sc(v), adde(u, v), adde(v, u);
    queue<ll> q;
    for (ll i = 1; i <= n; ++i)
        if (du[i] == 1)
            q.push(i);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (ll i = hd[u], v; i; i = e[i].nx)
        {
            v = e[i].to;
            if (--du[v] == 1)
                q.push(v);
        }
    }
    for (ll i = 1; i <= n; ++i)
        if (du[i] == 2)
            printf("%lld ", i);
    return 0;
}