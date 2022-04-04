#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 30
ll n, m, t, dp[mn][mn]; //考虑前i个生成函数, x^j系数
signed main()
{
    dp[0][0] = 1;
    for (ll i = 1; i < mn; ++i) //暴力多项式乘法
    {
        for (ll j = 0; j < mn; j += i) // 1+x^i+x^{2i}+...
        {
            for (ll k = 0; k + j < mn; ++k) // 枚举dp[i-1][k]
            {
                dp[i][k + j] += dp[i - 1][k];
            }
        }
    }
    for (sc(t); t--;)
    {
        sc(m), sc(n); // m无区别球放n无区别盒,可空盒
        printf("%lld\n", dp[n][m]);
    } //等价于前n个生成函数,系数为x^m
    return 0;
}