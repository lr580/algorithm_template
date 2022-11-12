#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
        x = 1, y = 0;
    else
        exgcd(b, a % b, y, x), y -= a / b * x;
}
ll inv(ll a, ll p)
{
    ll x, y;
    exgcd(a, p, x, y);
    return (x + p) % p;
}
ll qpow(ll a, ll b, ll p)
{
    ll r = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            r = r * a % p;
    return r;
}
ll CRT(int n, ll *a, ll *m)
{
    ll M = 1, p = 0;
    for (int i = 1; i <= n; i++)
        M = M * m[i];
    for (int i = 1; i <= n; i++)
    {
        ll w = M / m[i], x, y;
        exgcd(w, m[i], x, y);
        p = (p + a[i] * w * x % M) % M;
    }
    return (p % M + M) % M;
}
ll calc(ll n, ll x, ll P)
{
    if (!n)
        return 1;
    ll s = 1;
    for (ll i = 1; i <= P; i++)
        if (i % x)
            s = s * i % P;
    s = qpow(s, n / P, P);
    for (ll i = n / P * P + 1; i <= n; i++)
        if (i % x)
            s = i % P * s % P;
    return s * calc(n / x, x, P) % P;
}
ll multilucas(ll n, ll m, ll x, ll P)
{
    if (n < m)
        return 0;
    int cnt = 0;
    for (ll i = n; i; i /= x)
        cnt += i / x;
    for (ll i = m; i; i /= x)
        cnt -= i / x;
    for (ll i = n - m; i; i /= x)
        cnt -= i / x;
    return qpow(x, cnt, P) % P * calc(n, x, P) % P * inv(calc(m, x, P), P) %
           P * inv(calc(n - m, x, P), P) % P;
}
ll exlucas(ll n, ll m, ll P)
{
    int cnt = 0;
    ll p[20], a[20];
    for (ll i = 2; i * i <= P; i++)
    {
        if (P % i == 0)
        {
            p[++cnt] = 1;
            while (P % i == 0)
                p[cnt] = p[cnt] * i, P /= i;
            a[cnt] = multilucas(n, m, i, p[cnt]);
        }
    }
    if (P > 1)
        p[++cnt] = P, a[cnt] = multilucas(n, m, P, P);
    return CRT(cnt, a, p);
}
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    ll n, m, p;
    cin >> n >> m >> p;
    cout << exlucas(n, m, p);
    return 0;
}