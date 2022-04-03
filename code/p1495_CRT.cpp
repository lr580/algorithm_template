#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 13
ll n, a[mn], b[mn], pd = 1, c, ci, z, ans;
void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
        x = 1, y = 0;
    else
        exgcd(b, a % b, y, x), y -= a / b * x;
}
signed main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lld%lld", &a[i], &b[i]);
        pd *= a[i];
    }
    for (ll i = 1; i <= n; ++i)
    {
        c = pd / a[i], z = 0, ci = 0;
        exgcd(c, a[i], ci, z);
        ans += b[i] * c * ((ci + a[i]) % a[i]);
    }
    printf("%lld", ans % pd);
    return 0;
}
