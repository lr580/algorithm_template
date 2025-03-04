#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
ll qpow(ll a, ll b, ll p)
{
    ll r = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
            r = (__int128)r * a % p;
        a = (__int128)a * a % p;
    }
    return r;
}
bool millerRabin(ll p)
{ // 判断素数
    if (p < 2)
        return 0;
    if (p == 2)
        return 1;
    if (p == 3)
        return 1;
    ll d = p - 1, r = 0;
    while (!(d & 1))
        ++r, d >>= 1; // 将d处理为奇数
    for (ll k = 0; k < 10; ++k)
    {
        ll a = rand() % (p - 2) + 2;
        ll x = qpow(a, d, p);
        if (x == 1 || x == p - 1)
            continue;
        for (int i = 0; i < r - 1; ++i)
        {
            x = (__int128)x * x % p;
            if (x == p - 1)
                break;
        }
        if (x != p - 1)
            return 0;
    }
    return 1;
}
ll pollard_rho(ll x)
{
    ll s = 0, t = 0, c = (ll)rand() % (x - 1) + 1;
    ll step = 0, goal = 1, val = 1;
    for (goal = 1;; goal <<= 1, s = t, val = 1)
    {
        for (step = 1; step <= goal; ++step)
        {
            t = ((__int128)t * t + c) % x; //随机数生成器
            val = ((__int128)val * abs(t - s)) % x;
            if (step % 127 == 0)
            {
                ll d = __gcd(val, x);
                if (d > 1)
                    return d;
            }
        }
        ll d = __gcd(val, x);
        if (d > 1)
            return d;
    }
}
ll mx;
void fac(ll x)
{
    if (x <= mx || x < 2)
        return;
    if (millerRabin(x))
    {
        mx = max(mx, x); //最大质因子
        return;
    }
    ll p = x;
    while (p >= x) //直到找到平凡
    {
        p = pollard_rho(x);
    }
    while (x % p == 0)
    {
        x /= p;
    }
    fac(x), fac(p); // x*p=raw x
}
signed main()
{
    ll t, n;
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        srand(time(0));
        cin >> n;
        mx = 0;
        fac(n);
        if (mx == n)
        {
            cout << "Prime\n";
        }
        else
        {
            cout << mx << '\n';
        }
    }
    return 0;
}