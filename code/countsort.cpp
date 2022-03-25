#include <iostream>
using namespace std;
#define mn 10000002
int a[mn], b[mn], c[mn], n, m, bi, mod = 1e9 + 7;
long long ans;
signed main()
{ //题目链接 https://oj.socoding.cn/p/1638
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        ++c[a[i]];
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= c[i]; ++j)
        {
            b[++bi] = i;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        (ans += 1LL * i * b[i]) %= mod;
    }
    printf("%lld\n", ans);
    return 0;
}