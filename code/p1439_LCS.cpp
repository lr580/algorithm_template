#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 100010
ll a[mn], b[mn], n, dp[mn], m, h[mn];
signed main()
{
    sc(n);
    for (ll i = 1; i <= n; ++i)
    {
        sc(a[i]);
        h[a[i]] = i;
    }
    for (ll i = 1; i <= n; ++i)
    {
        sc(b[i]);
        b[i] = h[b[i]];
    }
    dp[++m] = b[1];
    for (ll i = 2; i <= n; ++i)
    {
        if (b[i] > dp[m])
        {
            dp[++m] = b[i];
        }
        else
        {
            *lower_bound(dp + 1, dp + 1 + m, b[i]) = b[i];
        }
    }
    printf("%lld", m);
    return 0;
}