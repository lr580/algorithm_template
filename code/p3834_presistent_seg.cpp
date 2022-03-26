#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define lg 22
#define mn 200010
ll m, n, q, a[mn], l[mn * lg], r[mn * lg], v[mn * lg], rot[mn], lc, rc, k, cnt, a0[mn];
#define mkcf ll cf = (lf + rf) >> 1
ll build(ll lf, ll rf)
{
    ll p = ++cnt;
    if (lf != rf)
    {
        mkcf;
        l[p] = build(lf, cf);
        r[p] = build(cf + 1, rf);
    }
    return p;
}
ll update(ll q, ll lf, ll rf)
{
    ll p = ++cnt;
    l[p] = l[q], r[p] = r[q], v[p] = v[q] + 1;
    if (lf != rf)
    {
        mkcf;
        if (k <= cf)
        {
            l[p] = update(l[q], lf, cf);
        }
        else
        {
            r[p] = update(r[q], cf + 1, rf);
        }
    }
    return p;
}
ll query(ll p, ll q, ll lf, ll rf, ll i)
{
    if (lf == rf)
    {
        return lf;
    }
    mkcf;
    ll j = v[l[q]] - v[l[p]];
    if (j >= i)
    {
        return query(l[p], l[q], lf, cf, i);
    }
    else
    {
        return query(r[p], r[q], cf + 1, rf, i - j);
    }
}
signed main()
{
    sc(m), sc(q);
    for (ll i = 1; i <= m; ++i)
    {
        sc(a[i]);
        a0[i] = a[i];
    }
    sort(a + 1, a + 1 + m);
    n = unique(a + 1, a + 1 + m) - (a + 1);
    rot[0] = build(1, n);
    for (ll i = 1; i <= m; ++i)
    {
        k = lower_bound(a + 1, a + 1 + n, a0[i]) - a;
        rot[i] = update(rot[i - 1], 1, n);
    }
    while (q--)
    {
        sc(lc), sc(rc), sc(k);
        ll i = query(rot[lc - 1], rot[rc], 1, n, k);
        printf("%lld\n", a[i]);
    }
    return 0;
}