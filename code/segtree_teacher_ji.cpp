#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 400010
#define lfs p << 1
#define rfs p << 1 | 1
#define mkcf ll cf = (lf + rf) >> 1
#define neg -1
ll n, m, c, lc, rc, v, a[mn], s[mn], mx[mn], se[mn], cnt[mn], laz[mn], ans;
void pushup(ll p)
{
    s[p] = s[lfs] + s[rfs];
    if (mx[lfs] == mx[rfs])
    {
        mx[p] = mx[lfs];
        cnt[p] = cnt[lfs] + cnt[rfs];
        se[p] = max(se[lfs], se[rfs]);
    }
    else if (mx[lfs] > mx[rfs])
    {
        mx[p] = mx[lfs];
        cnt[p] = cnt[lfs];
        se[p] = max(se[lfs], mx[rfs]);
    }
    else if (mx[lfs] < mx[rfs])
    {
        mx[p] = mx[rfs];
        cnt[p] = cnt[rfs];
        se[p] = max(se[rfs], mx[lfs]);
    }
}
void build(ll p, ll lf, ll rf)
{
    laz[p] = -1;
    if (lf == rf)
    {
        s[p] = mx[p] = a[lf];
        cnt[p] = 1;
        se[p] = -1;
        return;
    }
    mkcf;
    build(lfs, lf, cf);
    build(rfs, cf + 1, rf);
    pushup(p);
}
void pushd(ll p, ll nw)
{
    if (mx[p] <= nw)
    {
        return;
    }
    s[p] += cnt[p] * (nw - mx[p]);
    mx[p] = laz[p] = nw;
}
void pushdown(ll p)
{
    if (laz[p] == -1)
    {
        return;
    }
    pushd(lfs, laz[p]);
    pushd(rfs, laz[p]);
    laz[p] = -1;
}
void update(ll p, ll lf, ll rf)
{
    if (mx[p] <= v)
    {
        return;
    }
    if (lf >= lc && rf <= rc && se[p] < v)
    {
        return pushd(p, v);
    }
    pushdown(p);
    mkcf;
    if (cf >= lc)
    {
        update(lfs, lf, cf);
    }
    if (cf < rc)
    {
        update(rfs, cf + 1, rf);
    }
    pushup(p);
}
void query_mx(ll p, ll lf, ll rf)
{
    if (lf >= lc && rf <= rc)
    {
        ans = max(ans, mx[p]);
        return;
    }
    pushdown(p);
    mkcf;
    if (cf >= lc)
    {
        query_mx(lfs, lf, cf);
    }
    if (cf < rc)
    {
        query_mx(rfs, cf + 1, rf);
    }
}
void query_sum(ll p, ll lf, ll rf)
{
    if (lf >= lc && rf <= rc)
    {
        ans += s[p];
        return;
    }
    pushdown(p);
    mkcf;
    if (cf >= lc)
    {
        query_sum(lfs, lf, cf);
    }
    if (cf < rc)
    {
        query_sum(rfs, cf + 1, rf);
    }
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
        if (c == 0)
        {
            sc(v);
            update(1, 1, n);
        }
        else if (c == 1)
        {
            ans = -1;
            query_mx(1, 1, n);
            printf("%lld\n", ans);
        }
        else
        {
            ans = 0;
            query_sum(1, 1, n);
            printf("%lld\n", ans);
        }
    }
    return 0;
}