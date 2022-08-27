#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
const ll mn = 3e6 + 10, p = 998244353, g = 3, gi = 332748118;
ll n, m, lim = 1, l, r[mn], a[mn], b[mn]; // 2^l=lim
ll qpow(ll a, ll b)
{
    ll r = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
        {
            r = r * a % p;
        }
        a = a * a % p;
    }
    return r;
}
void ntt(ll *a, ll type)
{
    for (ll i = 0; i < lim; ++i)
    {
        if (i < r[i])
        {
            swap(a[i], a[r[i]]);
        }
    }
    for (ll mid = 1; mid < lim; mid <<= 1)
    {
        ll wn = qpow(type == 1 ? g : gi, (p - 1) / (mid << 1));
        for (ll j = 0; j < lim; j += (mid << 1))
        {
            ll w = 1;
            for (ll k = 0; k < mid; ++k, w = w * wn % p)
            {
                ll x = a[j + k], y = w * a[j + k + mid] % p;
                a[j + k] = (x + y) % p;
                a[j + k + mid] = (x - y + p) % p;
            }
        }
    }
}
signed main()
{
    sc(n), sc(m);
    for (ll i = 0; i <= n; ++i)
    {
        sc(a[i]);
    }
    for (ll i = 0; i <= m; ++i)
    {
        sc(b[i]);
    }
    while (lim <= n + m)
    {
        ++l, lim <<= 1;
    }
    for (ll i = 0; i < lim; ++i)
    {
        r[i] = (r[i >> 1] >> 1 | ((i & 1) << (l - 1)));
    }
    ntt(a, 1), ntt(b, 1);
    for (ll i = 0; i < lim; ++i)
    {
        a[i] = a[i] * b[i] % p;
    }
    ntt(a, -1);
    ll inv = qpow(lim, p - 2);
    for (ll i = 0; i <= n + m; ++i)
    {
        printf("%lld ", a[i] * inv % p);
    }
    return 0;
}