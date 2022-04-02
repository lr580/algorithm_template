#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    ll d = a;
    if (!b)
        x = 1, y = 0;
    else
        d = exgcd(b, a % b, y, x), y -= a / b * x;
    return d;
}
ll a, b, c, x, y, t, d, p, q, k;
signed main()
{
    for (scanf("%lld", &t); t; --t)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        d = exgcd(a, b, x, y);
        if (c % d != 0)
            printf("-1\n");
        else
        {
            x *= c / d, y *= c / d, p = b / d, q = a / d;
            if (x < 0)
                k = ceil((1.0 - x) / p), x += p * k, y -= q * k;
            else
                k = (x - 1) / p, x -= p * k, y += q * k;
            if (y > 0)
            {
                printf("%lld ", (y - 1) / q + 1);
                printf("%lld %lld ", x, (y - 1) % q + 1);
                printf("%lld %lld\n", x + (y - 1) / q * p, y);
            }
            else
                printf("%lld %lld\n", x, y + q * (ll)ceil((1.0 - y) / q));
        }
    }
    return 0;
}