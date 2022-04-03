#include <bits/stdc++.h> //题目https://oj.socoding.cn/p/1713
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mn 2000010
char s[mn], t[mn];
ull p = 131, pw[mn], h[mn], ht, n, m, cnt;
signed main()
{
    pw[0] = 1;
    for (ll i = 1; i < mn; ++i)
    {
        pw[i] = pw[i - 1] * p;
    }
    scanf("%s%s", s, t);
    n = strlen(s), m = strlen(t);
    for (ull i = 0; i < n; ++i)
    {
        h[i + 1] = h[i] * p + s[i];
    }
    for (ull i = 0; i < m; ++i)
    {
        ht = ht * p + t[i];
    }
    for (ull lf = 1, rf = m; rf <= n; ++lf, ++rf)
    {
        if (h[rf] - h[lf - 1] * pw[rf - lf + 1] == ht)
        {
            printf("%lld ", lf), ++cnt;
        }
    }
    if (!cnt)
    {
        printf("-1"); // not found
    }
    return 0;
}