#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 500010
ll t, fa[mn], cnt[mn], sum[mn];
char cmd[5];
ll findf(ll x)
{
    if (x == fa[x])
    {
        return x;
    }
    ll res = findf(fa[x]);
    cnt[x] += cnt[fa[x]];
    return fa[x] = res;
}
signed main()
{
    sc(t);
    for (ll i = 1; i < mn; ++i)
    {
        fa[i] = i, sum[i] = 1;
    }
    while (t--)
    {
        ll u, v, fu, fv;
        scanf("%s%lld%lld", cmd, &u, &v);
        fu = findf(u), fv = findf(v);
        if (cmd[0] == 'M')
        {
            cnt[fu] += sum[fv];
            fa[fu] = fv;
            sum[fv] += sum[fu];
            sum[fu] = 0;
        }
        else
        {
            if (fu != fv)
            {
                printf("-1\n");
            }
            else
            {
                printf("%lld\n", abs(cnt[u] - cnt[v]) - 1);
            }
        }
    }
    return 0;
}