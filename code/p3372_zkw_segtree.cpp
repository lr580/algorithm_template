#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 400010
#define sc(x) scanf("%lld", &x)
ll n, m, a[mn], dt, laz[mn], c, x, y, k;
signed main()
{
    sc(n), sc(m);
    for (dt = 1; dt <= n + 1; dt <<= 1)
        ;
    for (ll i = dt + 1; i <= dt + n; ++i)
    {
        sc(a[i]);
    }
    for (ll i = dt - 1; i >= 1; --i)
    {
        a[i] = a[i << 1] + a[i << 1 | 1];
    }
    while (m--)
    {
        sc(c), sc(x), sc(y);
        if (c == 1)
        {
            sc(k);
            ll lf = 0, rf = 0, layer = 1, s = dt + x - 1, t = dt + y + 1;
            for (; s ^ t ^ 1; s >>= 1, t >>= 1, layer <<= 1)
            {
                a[s] += k * lf, a[t] += k * rf;
                if (~s & 1)
                {
                    laz[s ^ 1] += k, a[s ^ 1] += k * layer, lf += layer;
                }
                if (t & 1)
                {
                    laz[t ^ 1] += k, a[t ^ 1] += k * layer, rf += layer;
                }
            }
            for (; s; s >>= 1, t >>= 1)
            {
                a[s] += k * lf, a[t] += k * rf;
            }
        }
        else
        {
            ll lf = 0, rf = 0, layer = 1, s = dt + x - 1, t = dt + y + 1;
            ll ans = 0;
            for (; s ^ t ^ 1; s >>= 1, t >>= 1, layer <<= 1)
            {
                if (laz[s])
                {
                    ans += laz[s] * lf;
                }
                if (laz[t])
                {
                    ans += laz[t] * rf;
                }
                if (~s & 1)
                {
                    ans += a[s ^ 1], lf += layer;
                }
                if (t & 1)
                {
                    ans += a[t ^ 1], rf += layer;
                }
            }
            for (; s; s >>= 1, t >>= 1)
            {
                ans += laz[s] * lf + laz[t] * rf;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}