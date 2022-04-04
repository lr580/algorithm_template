#include <cstdio>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 200
ll t, n, x[mn], y[mn], s, edge, kase;
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}
ll abs(ll x)
{
    return x < 0 ? -x : x;
}
signed main()
{
    for (sc(t); t--;)
    {
        sc(n);
        s = edge = 0;
        for (ll i = 1, dx, dy; i <= n; ++i)
        {
            sc(dx), sc(dy);
            x[i] = x[i - 1] + dx, y[i] = y[i - 1] + dy;
            edge += gcd(abs(dx), abs(dy));
        }
        x[n + 1] = x[1], y[n + 1] = y[1];
        for (ll i = 1, dx, dy; i <= n; ++i)
        {
            s += x[i] * y[i + 1] - x[i + 1] * y[i];
        }
        s = abs(s);
        printf("Scenario #%lld:\n%lld %lld %.1f\n\n", ++kase, (s - edge + 2) / 2, edge, s * 0.5f);
    }
    return 0;
}