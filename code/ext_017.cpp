#include <bits/stdc++.h>
using namespace std;
typedef double db;
#define sc(x) scanf("%lf", &x)
db a, b, c, d, l, r, eps = 1e-8; // eps可以比题目要求的细一两位
db f(db x)                       //这里根据题目不同输写不同的f
{
    return (c * x + d) / (a * x + b);
}
db simpson(db lf, db rf)
{
    return (rf - lf) * (f(lf) + f(rf) + 4 * f((lf + rf) / 2)) / 6;
}
db solve(db lf, db rf, db now) //当前区间估计值为now
{
    db cf = (lf + rf) / 2;
    db lfans = simpson(lf, cf), rfans = simpson(cf, rf);
    if (abs(lfans + rfans - now) <= eps) //二分后也是now
    {                                    //那就不需要细分了
        return lfans + rfans;
    }
    return solve(lf, cf, lfans) + solve(cf, rf, rfans);
}
signed main()
{
    sc(a), sc(b), sc(c), sc(d), sc(l), sc(r);
    printf("%lf", solve(l, r, 0)); //估计值随便填一个值
    return 0;
}
