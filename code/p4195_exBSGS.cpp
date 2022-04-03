#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 100000
#define mod 1000007
#define big 0xfffffffffffffa
ll a, b, p, baby[mn + 3], giant[mn + 3], key[mod], comment[2][mod];
ll stk[mod << 1 | 1];
ll mhash(ll v)
{
    ll w = v * v % mod;
    while (key[w] && key[w] != v)
    {
        (w += 1) %= mod;
    }
    if (!key[w])
    {
        stk[++stk[0]] = w;
    }
    return w;
}
ll phi(ll x)
{
    ll r = x;
    for (ll i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            r = r / i * (i - 1);
            while (x % i == 0)
            {
                x /= i;
            }
        }
    }
    if (x > 1)
    {
        r = r / x * (x - 1);
    }
    return r;
}
ll exbsgs()
{
    ll res = big, block = ceil(sqrt(2 * phi(p)));
    baby[0] = 1;
    for (ll i = 1; i <= block; ++i)
    {
        baby[i] = baby[i - 1] * a % p;
    }
    comment[0][mhash(1)] = 0;
    giant[0] = 1;
    for (ll i = 1; i <= block; ++i)
    {
        giant[i] = giant[i - 1] * baby[block] % p;
        ll now = mhash(giant[i]);
        if (!comment[0][now])
        {
            comment[0][now] = i;
        }
        else if (!comment[1][now])
        {
            comment[1][now] = i;
        }
    }
    for (ll i = 0; i <= block; ++i)
    {
        ll now = mhash(b * baby[i] % p);
        ll t0 = comment[0][now], t1 = comment[1][now];
        if (t0 && giant[t0 - 1] * baby[block - i] % p == b)
        {
            res = min(res, t0 * block - i);
        }
        else if (t1 && giant[t1 - 1] * baby[block - i] % p == b)
        {
            res = min(res, t1 * block - i);
        }
    }
    return res;
}
signed main()
{
    while (scanf("%lld%lld%lld", &a, &p, &b) != EOF)
    {
        if (!p && !a && !b)
        {
            break;
        }
        b %= p, a %= p;
        while (stk[0])
        {
            key[stk[stk[0]]] = 0;
            comment[0][stk[stk[0]]] = 0;
            comment[1][stk[stk[0]]] = 0;
            --stk[0];
        }
        ll res = exbsgs();
        if (res == big)
        {
            printf("No Solution\n");
        }
        else
        {
            printf("%lld\n", res);
        }
    }
    return 0;
}