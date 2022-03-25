#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    char p = 0;
    ll r = 0, o = 0;
    for (; p < '0' || p > '9'; o |= p == '-', p = getchar())
        ;
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar())
        ;
    return o ? (~r) + 1 : r;
}
#define sc(x) x = read()
signed main()
{
    ll a, b;
    sc(a), sc(b), printf("%lld", a + b);
    return 0;
}