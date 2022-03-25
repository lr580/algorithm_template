#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef double db;
#define sc(x) scanf("%d", &x)
#define mn 2000010
#define lg 23
ll n, m, st[mn][lg], l, r, lg2[mn];
signed main()
{
    sc(n), sc(m);
    for (ll i = 1; i <= n; ++i)
    {
        sc(st[i][0]);
    }
    for (ll i = 2; i <= n; ++i)
    {
        lg2[i] = lg2[i / 2] + 1;
    }
    for (ll j = 1; j < lg; ++j)
    {
        for (ll i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (m--)
    {
        sc(l), sc(r);
        ll p = lg2[r - l + 1];
        ll ans = __gcd(st[l][p], st[r - (1 << p) + 1][p]);
        printf("%d\n", ans);
    }
    return 0;
}