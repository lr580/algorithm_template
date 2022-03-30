#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 101
ll n, m, f[mn][mn], e[mn][mn], ans, big = 1e9, u, v, w;
signed main()
{
    while (EOF != scanf("%lld%lld", &n, &m))
    {
        for (ll i = 1; i <= n; ++i)
            for (ll j = 1; j <= n; ++j)
                f[i][j] = e[i][j] = big;
        while (m--)
        {
            sc(u), sc(v), sc(w); //防重边
            e[u][v] = e[v][u] = f[u][v] = f[v][u] = min(e[u][v], w);
        }
        ans = big;
        for (ll k = 1; k <= n; ++k)
        {
            for (ll i = 1; i < k; ++i)
                for (ll j = i + 1; j < k; ++j)
                    ans = min(ans, f[i][j] + e[j][k] + e[k][i]);
            for (ll i = 1; i <= n; ++i)
                for (ll j = 1; j <= n; ++j)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        }
        ans == big ? printf("It's impossible.\n") : printf("%lld\n", ans);
    }
    return 0;
}