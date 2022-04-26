#include <bits/stdc++.h> //SCNUOJ1730 https://oj.socoding.cn/p/1730
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
typedef double db;
ll a, b, c, d, e, l, r;
db x, t, now, mx, ans = -6;
db f(db x)
{
    return sin(x / a) + sin(x / b) + sin(x / c) + sin(x / d) + sin(x / e);
}
void solve()
{
    static ll rd = 1; //也可以用random_device生成种子
    mt19937 mt(rd + time(0));
    rd *= 2;
    uniform_real_distribution<db> dist0(0, 1);
    now = (l + r) / 2, t = r - l;
    while (t > 1e-6)
    {
        uniform_real_distribution<db> dist(-t, t);
        db newx = now + dist(mt);
        newx = max(1. * l, min(1. * r, newx));
        db fnow = f(now), fnew = f(newx);
        db dt = (-fnew) - (-fnow);
        if (fnow < fnew || exp(-dt / t) > dist0(mt))
        {
            now = newx;
        }
        if (ans < fnew)
        {
            ans = fnew;
        }
        t *= 0.999;
    }
    for (ll i = 0; i < 1000; ++i) //在终温随机多次
    {                             //优化效果不明显
        uniform_real_distribution<db> dist(-t, t);
        db newx = now + dist(mt);
        newx = max(1. * l, min(1. * r, newx));
        db fnow = f(now), fnew = f(newx);
        if (fnow < fnew)
        {
            now = newx;
        }
        if (ans < fnew)
        {
            ans = fnew;
        }
    }
}
signed main()
{
    sc(a), sc(b), sc(c), sc(d), sc(e), sc(l), sc(r);
    for (ll i = 0; i < 20; ++i) //重要：多次退火
    {
        solve();
    }
    printf("%lf", ans);
    return 0;
}