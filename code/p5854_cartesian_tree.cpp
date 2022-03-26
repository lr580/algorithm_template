#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define MAXN 10000002
inline ll read()
{
    char p = 0;
    ll r = 0, o = 0;
    for (; p < '0' || p > '9'; o |= p == '-', p = getchar())
        ;
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar())
        ;
    return o ? (~r) + 1 : r;
}
ll n, a[MAXN], stk[MAXN], ls[MAXN], rs[MAXN], pos, top;
long long lf, rf;
signed main()
{
    n = read();
    for (ll i = 1; i <= n; ++i)
    {
        a[i] = read();
        while (pos && a[stk[pos]] > a[i])
            --pos;
        if (pos)
            rs[stk[pos]] = i;
        if (pos < top)
            ls[i] = stk[pos + 1];
        stk[top = ++pos] = i;
    }
    for (long long i = 1; i <= n; ++i)
        lf ^= i * (ls[i] + 1), rf ^= i * (rs[i] + 1);
    printf("%lld %lld", lf, rf);
    return 0;
}