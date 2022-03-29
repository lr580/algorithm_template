#include <bits/stdc++.h> //https://oj.socoding.cn/p/1464
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define repe(i, a, b) for (ll i = a; i <= b; ++i)
#define mn 804
ll n, k, a[mn][mn], s[mn][mn], lf, rf = 1e9, cf, res, t;
bool check()
{ //利用前缀和快速检验中位数
    repe(i, 1, n) repe(j, 1, n) s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (a[i][j] >= cf);
    repe(i, k, n) repe(j, k, n)
    {
        t = s[i][j] + s[i - k][j - k] - s[i][j - k] - s[i - k][j];
        if (t < k * k / 2 + 1)
            return false;
    }
    return true;
}
signed main()
{
    sc(n), sc(k);
    repe(i, 1, n) repe(j, 1, n) sc(a[i][j]);
    while (lf <= rf)
    {
        cf = (lf + rf) >> 1;       //假设存在一个子矩阵的中位数是cf
        if (check())               //如果以cf为中位数不少于k*k/2+1个元素大于它
            lf = cf + 1, res = cf; //那么中位数大于等于cf
        else
            rf = cf - 1; //否则中位数小于cf
    }
    printf("%d", res);
    return 0;
}
