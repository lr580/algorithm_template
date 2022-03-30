#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 131082 // 1<<log(1e5,2)+10
#define ml 20
ll n, m, a[mn], n2, lg[mn * 2], l, r;
ll pos[mn], gcd[mn][ml];
#define lfs p << 1
#define rfs p << 1 | 1
#define mkcf ll cf = (lf + rf) >> 1
void build(ll p, ll lf, ll rf, ll dep)
{
    if (lf == rf)
    {
        pos[lf] = p;
        return;
    }
    mkcf;
    build(lfs, lf, cf, dep + 1);
    build(rfs, cf + 1, rf, dep + 1);
    gcd[cf][dep] = a[cf];
    for (ll i = cf - 1; i >= lf; --i)
    {
        gcd[i][dep] = max(gcd[i + 1][dep], a[i]);
    }
    for (ll i = cf + 1; i <= rf; ++i)
    {
        gcd[i][dep] = max(gcd[i - 1][dep], a[i]);
    }
}
signed main()
{
    sc(n), sc(m);
    for (ll i = 1; i <= n; ++i)
    {
        sc(a[i]);
    }
    for (n2 = 1; n2 < n; n2 <<= 1) //满二叉树下节点有n2个
        ;
    for (ll i = 2; i <= n2 * 2; ++i)
    {
        lg[i] = lg[i / 2] + 1;
    }
    build(1, 1, n2, 1);
    while (m--)
    {
        sc(l), sc(r);
        if (l == r) //猫树不存叶子节点
        {
            printf("%lld\n", a[l]);
            continue;
        }
        ll k = lg[pos[r]] - lg[pos[l] ^ pos[r]];
        printf("%lld\n", max(gcd[l][k], gcd[r][k]));
    }
    return 0;
}