#include <cstdio>
#include <bitset>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 105
ll n, m, ans, u, v;
bitset<mn> f[mn];
signed main()
{
    sc(n), sc(m);
    while (m--)
        sc(u), sc(v), f[v][u] = 1;
    for (ll k = 1; k <= n; ++k)
        for (ll i = 1; i <= n; ++i)
            if (f[i][k])
                f[i] |= f[k];
    for (ll i = 1; i <= n; ++i)
    {
        ll cnt = 0;
        for (ll j = 1; j <= n; ++j)
            cnt += (f[i][j] | f[j][i]);
        ans += cnt == n - 1;
    }
    printf("%lld", ans);
    return 0;
}