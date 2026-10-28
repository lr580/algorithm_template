#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 504
#define big 0x7fffffffffffffff
ll n, m, e[mn][mn], mb[mn], vb[mn], ka[mn], kb[mn], p[mn], c[mn];
ll qf, qb, q[mn], u, v, w;
void bfs(ll u)
{
    ll a, v = 0, v1 = 0, d;
    fill(p + 1, p + n + 1, 0), fill(c + 1, c + n + 1, big), mb[v] = u;
    do
    {
        a = mb[v], d = big, vb[v] = 1;
        for (ll b = 1; b <= n; ++b)
        {
            if (!vb[b])
            {
                if (c[b] > ka[a] + kb[b] - e[a][b])
                {
                    c[b] = ka[a] + kb[b] - e[a][b], p[b] = v;
                }
                if (c[b] < d)
                {
                    d = c[b], v1 = b;
                }
            }
        }
        for (ll b = 0; b <= n; ++b)
        {
            if (vb[b])
            {
                ka[mb[b]] -= d, kb[b] += d;
            }
            else
            {
                c[b] -= d;
            }
        }
        v = v1;
    } while (mb[v]);
    while (v)
    {
        mb[v] = mb[p[v]], v = p[v];
    }
}
ll km()
{ // memset mb,ka,kb->0
    for (ll a = 1; a <= n; ++a)
    {
        fill(vb, vb + n + 1, 0);
        bfs(a);
    }
    ll res = 0;
    for (ll b = 1; b <= n; ++b)
    {
        res += e[mb[b]][b];
    }
    return res;
}
signed main()
{
    sc(n), sc(m);
    memset(e, -127, sizeof e); //-big暴毙
    while (m--)
    {
        sc(u), sc(v), sc(w);
        e[u][v] = max(e[u][v], w);
    }
    printf("%lld\n", km());
    for (ll i = 1; i <= n; ++i)
    {
        printf("%lld ", mb[i]);
    }
    return 0;
}
