#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 1000010
char s[mn];
ll n, sa[mn], rk[mn], oldrk[mn << 1], id[mn], px[mn], cnt[mn];
bool cmp(ll x, ll y, ll w)
{
    return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];
}
ll m = 300, i, p, w; //ASCII范围<300为计数排序值域,p是新值域
signed main()
{
    scanf("%s", s + 1), n = strlen(s + 1);
    for (ll i = 1; i <= n; ++i)
    { //暂时以第一关键字为排序值，有很多同名并列
        ++cnt[rk[i] = s[i]];
    }
    for (ll i = 1; i <= m; ++i)
    {
        cnt[i] += cnt[i - 1];
    }
    for (ll i = n; i >= 1; --i)
    {
        sa[cnt[rk[i]]--] = i;
    }
    for (w = 1;; w <<= 1, m = p)
    {
        for (p = 0, i = n; i > n - w; --i)
        { //第二关键字排序；无穷小区域
            id[++p] = i;
        }
        for (ll i = 1; i <= n; ++i)
        {
            if (sa[i] > w)
            {
                id[++p] = sa[i] - w;
            }
        }
        memset(cnt, 0, sizeof cnt);
        for (ll i = 1; i <= n; ++i) //第一关键字排序
        {
            ++cnt[px[i] = rk[id[i]]];
        }
        for (ll i = 1; i <= m; ++i)
        {
            cnt[i] += cnt[i - 1];
        }
        for (ll i = n; i >= 1; --i)
        {
            sa[cnt[px[i]]--] = id[i];
        }
        memcpy(oldrk, rk, sizeof rk);
        for (p = 0, i = 1; i <= n; ++i)
        {
            rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
        }
        if (p == n)
        {
            for (ll i = 1; i <= n; ++i)
            {
                sa[rk[i]] = i;
            }
            break;
        }
    }
    for (ll i = 1; i <= n; ++i)
    {
        printf("%lld ", sa[i]);
    }
    return 0;
}