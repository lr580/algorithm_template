#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 100010
ll t[mn << 2], laz[mn << 2], n, m, c, lc, rc, v, a[mn], ans;
#define lfs p << 1
#define rfs p << 1 | 1
#define mkcf ll cf = (lf + rf) >> 1
void build(ll p, ll lf, ll rf)
{
    if (lf == rf)
    {
        t[p] = a[lf];
        return;
    }
    mkcf;
    build(lfs, lf, cf);
    build(rfs, cf + 1, rf);
    t[p] = t[lfs] + t[rfs];
}
void pushdown(ll p, ll lf, ll rf)
{
    mkcf;
    t[lfs] += (cf - lf + 1) * laz[p];
    t[rfs] += (rf - cf) * laz[p];
    laz[lfs] += laz[p];
    laz[rfs] += laz[p];
    laz[p] = 0;
}
void update(ll p, ll lf, ll rf)
{
    if (lf >= lc && rf <= rc)
    {
        t[p] += v * (rf - lf + 1);
        laz[p] += v;
        return;
    }
    pushdown(p, lf, rf);
    mkcf;
    if (cf >= lc)
    {
        update(lfs, lf, cf);
    }
    if (cf < rc)
    {
        update(rfs, cf + 1, rf);
    }
    t[p] = t[lfs] + t[rfs];
}
void query(ll p, ll lf, ll rf)
{
    if (lf >= lc && rf <= rc)
    {
        ans += t[p];
        return;
    }
    pushdown(p, lf, rf);
    mkcf;
    if (cf >= lc)
    {
        query(lfs, lf, cf);
    }
    if (cf < rc)
    {
        query(rfs, cf + 1, rf);
    }
    //t[p] = t[lfs] + t[rfs];
}
signed main()
{
    sc(n), sc(m);
    for (ll i = 1; i <= n; ++i)
    {
        sc(a[i]);
    }
    build(1, 1, n);
    while (m--)
    {
        sc(c), sc(lc), sc(rc);
        if (c == 1)
        {
            sc(v);
            update(1, 1, n);
        }
        else
        {
            ans = 0;
            query(1, 1, n);
            printf("%lld\n", ans);
        }
    }
    return 0;
}