#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define sc(x) scanf("%lld", &x)
ll dp[12][12][2]; //后i位,最高位为j,是否出现过1,相邻数位和为素数的方案数
ll prime[] = {2, 3, 5, 7, 11, 13, 17}, ps = 7;
ll l, r, res;
ll dd[12]; //[1,10^(i-1)-1]内的答案
ll ispr(ll x)
{
    for (ll i = 0; i < ps; ++i)
    {
        if (x == prime[i])
        {
            return 1;
        }
    }
    return 0;
}
ll ask(ll rf)
{
    res = 0;
    if (rf <= 9 && rf >= 1)
    {
        return 1;
    }
    ll bs = 0;
    ll b[12] = {};
    for (ll i = rf; i; i /= 10)
    {
        ++bs;
        b[bs] = i % 10;
    }
    ll ever1 = 0, ever2 = 0;
    for (ll i = bs; i >= 1; --i)
    {
        ll je = b[i] + (i == 1);
        if (je > 0 && i > 1 && !ever2)
        {
            res += dd[i];
            ever2 = 1;
        }
        ll jb = 1 - (i != bs);
        for (ll j = jb; j < je; ++j)
        {
            ll k = (i > 1) ? 1 : ((j == 1) ? 1 : !ever1);
            if (i != bs && !ispr(b[i + 1] + j))
            {
                continue;
            }
            res += dp[i][j][k];
            if (ever1)
            {
                res += dp[i][j][k ^ 1];
            }
        }
        ever1 |= (b[i] == 1);
        if (i != bs && !ispr(b[i] + b[i + 1]))
        {
            break;
        }
    }
    return res;
}
ll bfcheck(ll lf, ll rf)
{
    ll cnt = 0;
    for (ll h = lf; h <= rf; ++h)
    {
        ll has1 = 0;
        ll bs = 0;
        ll b[12] = {};
        for (ll j = h; j; j /= 10)
        {
            ++bs;
            b[bs] = j % 10;
            has1 |= (b[bs] == 1);
        }
        if (bs == 1)
        {
            cnt += (h == 1);
            continue;
        }
        ll ok = 1;
        for (ll i = 1; i < bs; ++i)
        {
            ll isprime = ispr(b[i] + b[i + 1]);
            if (isprime == 0)
            {
                ok = 0;
                break;
            }
        }
        if (ok && has1)
        {
            ++cnt;
        }
    }
    return cnt;
}
signed main()
{
    dp[1][1][1] = 1;
    for (ll i = 2; i <= 9; ++i)
    {
        dp[1][i][0] = 1; //没有相邻，条件1恒成立
    }
    dp[1][0][0] = 1;
    for (ll i = 2; i <= 11; ++i)
    {
        for (ll x = 0; x <= 9; ++x)
        {
            ll now0 = (x == 1);
            for (ll y = 0; y <= 9; ++y)
            {
                for (ll pr = 0; pr <= 1; ++pr)
                {
                    ll has0 = now0 || ((y == 1) || pr);
                    ll s = x + y;
                    ll isprime = 0;
                    for (ll j = 0; j < ps; ++j)
                    {
                        if (s == prime[j])
                        {
                            isprime = 1;
                            break;
                        }
                    }
                    if (!isprime)
                    {
                        continue;
                    }
                    dp[i][x][has0] += dp[i - 1][y][pr];
                }
            }
        }
    }
    for (ll i = 2; i <= 11; ++i)
    {
        dd[i] = dd[i - 1];
        for (ll j = 1; j <= 9; ++j)
        {
            dd[i] += dp[i - 1][j][1];
        }
    }
    sc(l), sc(r);
    ll ar = ask(r), al = ask(l - 1);
    printf("%lld", ar - al);
    return 0;
}