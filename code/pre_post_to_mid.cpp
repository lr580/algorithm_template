#include <bits/stdc++.h> //题目链接 https://oj.socoding.cn/p/1423
#define mod 1000000007
#define mn 100002
typedef long long ll;
ll n, a[mn], b[mn], c[mn], r = 1;
signed main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i) //先序
        scanf("%lld", a + i);
    for (ll i = 1; i <= n; ++i) //后序
        scanf("%lld", b + i), c[b[i]] = i;
    for (ll i = 1; i <= n; ++i)
    {
        ll k = c[a[i]];
        if (i != n && a[i + 1] == b[k - 1])
            (r *= 2) %= mod;
    }
    printf("%lld", r);
    return 0;
}