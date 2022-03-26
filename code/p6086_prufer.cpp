#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define MAXN 5000002
ll n, m, f[MAXN], p[MAXN], d[MAXN];
long long ans;
signed main()
{
    scanf("%d%d", &n, &m);
    if (m == 1) //树转Prufer
    {
        for (ll i = 1; i < n; ++i)
            scanf("%d", f + i), ++d[f[i]];
        for (ll i = 1, j = 1; i <= n - 1; ++i, ++j)
        {
            while (d[j])
                ++j;
            p[i] = f[j];
            while (i <= n - 2 && !--d[p[i]] && p[i] < j)
                p[i + 1] = f[p[i]], ++i;
        }
        for (ll i = 1; i <= n - 2; ++i)
            ans ^= 1LL * i * p[i];
    }
    else // Prufer转树
    {
        for (ll i = 1; i <= n - 2; ++i)
            scanf("%d", p + i), ++d[p[i]];
        p[n - 1] = n;
        for (ll i = 1, j = 1; i < n; ++i, ++j)
        {
            while (d[j])
                ++j;
            f[j] = p[i];
            while (i < n && !--d[p[i]] && p[i] < j)
                f[p[i]] = p[i + 1], ++i;
        }
        for (ll i = 1; i < n; ++i)
            ans ^= 1LL * i * f[i];
    }
    printf("%lld", ans);
    return 0;
}