#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define MAXN 1000002
ll ans[MAXN], n, a[MAXN], mx, vis[MAXN];
signed main()
{
    scanf("%d", &n);
    for (ll i = 1; i <= n; ++i)
        scanf("%d", &a[i]), ++vis[a[i]], mx = max(a[i], mx);
    for (ll i = 1; i <= mx; ++i)
    {
        if (!vis[i])
            continue;
        for (ll j = 1; j * i <= mx; ++j)
            if (vis[i * j])
                ans[i * j] += vis[i];
        --ans[i];
    }
    for (ll i = 1; i <= n; ++i)
        printf("%d\n", ans[a[i]]);
    return 0;
}