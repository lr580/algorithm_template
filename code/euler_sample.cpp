//https://oj.socoding.cn/p/1745
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 1000002
ll n, k, p[mn], pri[mn], e[mn], pe[mn], g[mn], cnt, ans = 1, mod = 1e9 + 7;
void euler(ll n)
{ // e[i]是i质因数分解得到的最大的幂a_i,pe[i]是对应最大的(p^e[i])
    for (ll i = 2; i <= n; ++i)
    {
        if (!p[i])
        {
            p[i] = i, pri[++cnt] = i, pe[i] = i, e[i] = 1;
        }
        for (ll j = 1; i * pri[j] <= n; ++j)
        {
            p[i * pri[j]] = pri[j];
            if (pri[j] == p[i])
            {
                e[i * pri[j]] = e[i] + 1;
                pe[i * pri[j]] = pe[i] * pri[j];
                break;
            }
            e[i * pri[j]] = 1;
            pe[i * pri[j]] = pri[j];
        }
    }
}
ll qpow(ll a, ll b)
{
    ll res = 1;
    for (; b > 0; b >>= 1)
    {
        if (b & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
    }
    return res;
}
signed main()
{
    sc(n), sc(k);
    g[1] = 1;
    euler(n);
    for (ll i = 2; i <= n; ++i)
    {
        if (pe[i] == i)
        {
            g[i] = (qpow(p[i], e[i] * k + 1) - 1 + mod) % mod * qpow(p[i] - 1, mod - 2) % mod;
            g[i] = g[i] * (qpow(p[i], e[i] * k) - qpow(p[i], e[i] * k - 1) + mod) % mod;
        }
        else
        {
            g[i] = g[i / pe[i]] * g[pe[i]] % mod;
        }
        ans = (ans + g[i]) % mod;
    }
    printf("%lld", ans);
    return 0;
}