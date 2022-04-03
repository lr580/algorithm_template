#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define mn ((1 << 21) + 1)
ll n1, n2, rev[mn], ans[mn], k, s = 1, len, n;
db pi = acos(-1), v;
typedef complex<db> cp;
cp a[mn], b[mn];
void fft(cp *a, ll n, ll flag)
{
    for (ll i = 0; i < n; ++i)
    {
        if (i < rev[i])
        {
            swap(a[i], a[rev[i]]);
        }
    }
    for (ll h = 1; h < n; h <<= 1)
    {
        cp wn = exp(cp(0, flag * pi / h));
        for (ll j = 0; j < n; j += h << 1)
        {
            cp w(1, 0);
            for (ll k = j; k < j + h; ++k)
            {
                cp x = a[k], y = w * a[k + h];
                a[k] = x + y;
                a[k + h] = x - y;
                w *= wn;
            }
        }
    }
    if (flag == -1)
    {
        for (ll i = 0; i < n; ++i)
        {
            a[i] /= n;
        }
    }
}
#pragma GCC diagnostic ignored "-Wformat" //忽略db转complex警告
signed main()
{
    scanf("%lld%lld", &n1, &n2), n = n1 + n2;
    for (ll i = 0; i <= n1; ++i)
    {
        scanf("%lf", a + i);
    }
    for (ll i = 0; i <= n2; ++i)
    {
        scanf("%lf", b + i);
    }
    while (s <= n)
    {
        s <<= 1, ++k;
    }
    for (ll i = 0; i < s; ++i)
    {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
    }
    fft(a, s, 1), fft(b, s, 1);
    for (ll i = 0; i <= s; ++i)
    {
        a[i] *= b[i];
    }
    fft(a, s, -1);
    for (ll i = 0; i <= n; ++i)
    {
        printf("%lld ", (ll)(a[i].real() + 0.5));
    }
    return 0;
}