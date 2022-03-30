#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 500010
ll t[mn << 2], n, N, m, c, x, y;
signed main()
{
    sc(n), sc(m);
    for (N = 1; N <= n + 1; N <<= 1)
        ;
    for (ll i = N + 1; i <= N + n; ++i)
    {
        sc(t[i]);
    }
    for (ll i = N - 1; i >= 1; --i)
    {
        t[i] = t[i << 1] + t[i << 1 | 1];
    }
    while (m--)
    {
        sc(c), sc(x), sc(y);
        if (c == 1)
        {
            for (ll i = x + N; i; i >>= 1)
            {
                t[i] += y;
            }
        }
        else
        {
            ll ans = 0;
            for (ll s = N + x - 1, r = N + y + 1; s ^ r ^ 1; s >>= 1, r >>= 1)
            {
                if (~s & 1)
                {
                    ans += t[s ^ 1];
                }
                if (r & 1)
                {
                    ans += t[r ^ 1];
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}