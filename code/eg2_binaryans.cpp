#include <bits/stdc++.h> //https://oj.socoding.cn/p/1479
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 200010
ll n, m, e[mn][2], u, v, lf, rf, cf, res, s[mn];
bool check(ll k)
{
    memset(s, 0, sizeof s);
    for (ll i = 0; i < m; ++i)
    {
        //只能在[a,b)这一段删，不然会走[a,b)使得答案>k
        //所以不能走这一段的补集
        if (e[i][1] - e[i][0] > k)
        {
            ++s[1];
            --s[e[i][0]];
            ++s[e[i][1]];
        }
        if (n - (e[i][1] - e[i][0]) > k)
        {
            ++s[e[i][0]];
            --s[e[i][1]];
        }
    }
    for (ll i = 1; i <= n; ++i)
    {
        s[i] += s[i - 1];
        if (!s[i])
        {
            return true;
        }
    }
    return false;
}
signed main()
{
    while (EOF != scanf("%d%d", &n, &m))
    {
        for (ll i = 0; i < m; ++i)
        {
            sc(u), sc(v); //输入不保证a<=b所以要这样
            e[i][0] = min(u, v), e[i][1] = max(u, v);
        }
        lf = 0, rf = n - 1;
        while (lf <= rf) 
        {
            cf = (lf + rf) >> 1;
            if (check(cf)) //如果有答案，那么找一下更小的
            {
                rf = cf - 1;
            }
            else
            {
                lf = cf + 1;
            }
        }
        printf("%d\n", rf + 1);
    }
    return 0;
}