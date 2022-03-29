#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define MAXN 100002
ll n, s, t, q[MAXN];
double c[MAXN], lf = -1e4, rf = 1e4, cf, a[MAXN];
inline bool ck(double &v)
{
    int l = 1, r = 0;
    for (ll i = 1; i <= n; ++i)
        c[i] = c[i - 1] + a[i] - v;
    for (ll i = 1; i <= n; ++i)
    {
        if (i >= s) //单调队列法
        {
            while (r >= l && c[i - s] < c[q[r]])
                --r;
            q[++r] = i - s;
        }
        if (l <= r && q[l] < i - t)
            ++l;
        if (l <= r && c[i] >= c[q[l]])
            return true;
    }
    return false;
}
signed main()
{
    scanf("%d%d%d", &n, &s, &t);
    for (ll i = 1; i <= n; ++i)
        scanf("%lf", &a[i]);
    while (rf - lf > 1e-5)
    {
        cf = (lf + rf) / 2;
        if (ck(cf))
            lf = cf;
        else
            rf = cf;
    }
    printf("%.3lf", lf);
    return 0;
}