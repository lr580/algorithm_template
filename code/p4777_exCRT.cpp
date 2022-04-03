#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC diagnostic ignored "-Wpedantic" using int128 = __int128; //忽略警告
#define mn 100002
ll n, ai[mn], bi[mn], x, y, k, m, ans, a, b, c, gcc, bg;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    ll d = a;
    if (!b)
        x = 1, y = 0;
    else
        d = exgcd(b, a % b, y, x), y -= a / b * x;
    return d;
}
signed main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i)
        scanf("%lld%lld", ai + i, bi + i);
    m = ai[1], ans = bi[1];
    for (ll i = 2; i <= n; ++i)
    {
        a = m, b = ai[i], c = (bi[i] - ans % b + b) % b;
        gcc = exgcd(a, b, x, y), bg = b / gcc;
        if (c % gcc != 0)
            return printf("-1") & 0;
        x = (__int128)x * (c / gcc) % bg;
        ans += x * m, m *= bg, ans = (ans % m + m) % m;
    }
    printf("%lld", (ans % m + m) % m);
    return 0;
}