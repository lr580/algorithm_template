#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 30
ll n, m, t, dp[mn][mn]; // m球n盒方案数
signed main()
{
    for (ll i = 0; i < mn; ++i) //无球或单盒为1
        dp[0][i] = dp[i][1] = 1;
    for (ll i = 1; i < mn; ++i)
        for (ll j = 1; j < mn; ++j)
            if (j > i) //盒比球多,(?,0)=(?)
                dp[i][j] = dp[i][i];
            else //放满时每盒拿走一个;放不满时拿走空盒一个
                dp[i][j] = dp[i - j][j] + dp[i][j - 1];
    for (sc(t); t--;)
        sc(m), sc(n), printf("%lld\n", dp[m][n]);
    return 0;
}