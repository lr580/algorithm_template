#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 50010
ll n, k, fa[mn], ty[mn], fake;
ll findf(ll x)
{
    if (x == fa[x])
    {
        return x;
    }
    ll res = findf(fa[x]);
    ty[x] = (ty[x] + ty[fa[x]]) % 3;
    return fa[x] = res;
}
signed main()
{
    sc(n), sc(k);
    for (ll i = 1; i <= n; ++i)
    {
        fa[i] = i;
    }
    while (k--)
    {
        ll cmd, u, v, fu, fv;
        sc(cmd), sc(u), sc(v), fu = findf(u), fv = findf(v);
        if (u > n || v > n || (u == v && cmd == 2))
        {
            ++fake;
            continue;
        }
        if (cmd == 1)
        {
            if (fu == fv && ty[u] != ty[v])
            {
                ++fake;
            }
            else
            {
                ty[fu] = (3 - ty[u] + ty[v]) % 3;
                fa[fu] = fv;
            }
        }
        else
        {
            if (fu == fv && (ty[u] - ty[v] + 3) % 3 != 1)
            {
                ++fake;
            }
            else
            {
                ty[fu] = (3 - ty[u] + ty[v] + 1) % 3;
                fa[fu] = fv;
            }
        }
    }
    printf("%lld", fake);
    return 0;
}