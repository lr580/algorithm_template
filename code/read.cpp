#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read()
{
    ll num = 0;
    char c = getchar(), up = c;
    while (c < '0' || c > '9')
        up = c, c = getchar();
    while (c >= '0' && c <= '9')
        num = (num << 1) + (num << 3) + (c ^ '0'), c = getchar();
    return up == '-' ? -num : num;
}
#define sc(x) x = read()
signed main()
{
    ll a, b;
    sc(a), sc(b), printf("%lld", a + b);
    return 0;
}