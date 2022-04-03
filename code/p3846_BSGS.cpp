#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 1000700
#define mod 1000007
struct hasht
{
    ll mp[mn], hsh[mn]; //避免关键字冲突map,hash
    ll find(ll x)       //拉链法构造散列表
    {
        ll t = x % mod;
        for (; mp[t] != x && mp[t] != -1; (t += 107) %= mod)
            ;
        return t;
    }
    void insert(ll x, ll i)
    {
        ll f = find(x);
        mp[f] = x, hsh[f] = i;
    }
    bool in(ll x)
    {
        return mp[find(x)] == x;
    }
    ll get_hash(ll x)
    {
        return hsh[find(x)];
    }
    void init()
    {
        memset(hsh, -1, sizeof hsh), memset(mp, -1, sizeof mp);
    }
} h;
ll a, b, p, m, s;
signed main()
{
    scanf("%lld%lld%lld", &p, &a, &b);
    h.init();
    if (b == 1)
    {
        return !printf("0");
    }
    m = ceil(sqrt((double)p)) + 1, s = 1;
    for (ll i = 1; i <= m; ++i)
    {
        h.insert(b, i);
        s = (1LL * s * a) % p, b = (1LL * a * b) % p;
    }
    a = s;
    for (ll i = 1; i <= m; ++i)
    {
        if (h.in(a))
        {
            return printf("%lld", i * m - h.get_hash(a) + 1) & 0;
        }
        a = (1LL * a * s) % p;
    }
    return printf("no solution"), 0;
}