#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 2000010
ll n, m, hd[mn], cnt, st, low[mn], dfn[mn], ins[mn], scc, c[mn];
stack<ll> s;
struct edge
{
    ll to, nx;
} e[mn * 2];
void tarjan(ll u)
{
    low[u] = dfn[u] = ++st, ins[u] = true;
    s.push(u);
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (ins[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u])
    {
        ++scc;
        do
        {
            c[u] = scc;
            u = s.top();
            s.pop();
            ins[u] = false;
        } while (low[u] != dfn[u]);
    }
}
signed main()
{
    sc(n), sc(m);
    auto adde = [&](ll u, ll v)
    { e[++cnt] = {v, hd[u]}, hd[u] = cnt; };
    for (ll i = 1, a, va, b, vb; i <= m; ++i)
    {
        sc(a), sc(va), sc(b), sc(vb);
        if (va && vb)
        {
            adde(a + n, b), adde(b + n, a);
        }
        else if (!va && vb)
        {
            adde(a, b), adde(b + n, a + n);
        }
        else if (va && !vb)
        {
            adde(a + n, b + n), adde(b, a);
        }
        else if (!va && !vb)
        {
            adde(a, b + n), adde(b, a + n);
        }
        // i.e. adde(a+n*va,b+n*(vb^1)),adde(b+n*vb,a+n*(va^1))
    }
    for (ll i = 1; i <= 2 * n; ++i)
    {
        if (!dfn[i])
        {
            tarjan(i);
        }
    }
    for (ll i = 1; i <= n; ++i)
    {
        if (c[i] == c[i + n])
        {
            printf("IMPOSSIBLE");
            return 0;
        }
    }
    printf("POSSIBLE\n");
    for (ll i = 1; i <= n; ++i)
    { // tarjan逆拓扑序
        printf("%d ", c[i] < c[i + n]);
    }
    return 0;
}