#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 100010
#define lg 310
ll v[mn * lg], l[mn * lg], r[mn * lg], cnt, rot[mn];
ll n, m, a[mn], h[mn * 2], hs;
#define mkcf ll cf = (lf + rf) >> 1
#define lowbit(x) (x & -x)
void update(ll &p, ll lf, ll rf, const ll &pos, const ll &x)
{
    if (!p)
    {
        p = ++cnt;
    }
    v[p] += x;
    if (lf != rf)
    {
        mkcf;
        if (pos <= cf)
        {
            update(l[p], lf, cf, pos, x);
        }
        else
        {
            update(r[p], cf + 1, rf, pos, x);
        }
    }
}
void updates(ll pos, ll x)
{
    ll k = lower_bound(h + 1, h + 1 + hs, a[pos]) - h;
    for (ll i = pos; i <= n; i += lowbit(i))
    {
        update(rot[i], 1, hs, k, x);
    }
}
ll addcnt, addid[lg], subcnt, subid[lg];
ll query(ll lf, ll rf, ll k)
{
    if (lf == rf)
    {
        return lf;
    }
    mkcf;
    ll res = 0;
    for (ll i = 1; i <= addcnt; ++i)
    {
        res += v[l[addid[i]]];
    }
    for (ll i = 1; i <= subcnt; ++i)
    {
        res -= v[l[subid[i]]];
    }
    if (k <= res)
    {
        for (ll i = 1; i <= addcnt; ++i)
        {
            addid[i] = l[addid[i]];
        }
        for (ll i = 1; i <= subcnt; ++i)
        {
            subid[i] = l[subid[i]];
        }
        return query(lf, cf, k);
    }
    else
    {
        for (ll i = 1; i <= addcnt; ++i)
        {
            addid[i] = r[addid[i]];
        }
        for (ll i = 1; i <= subcnt; ++i)
        {
            subid[i] = r[subid[i]];
        }
        return query(cf + 1, rf, k - res);
    }
}
ll querys(ll lf, ll rf, ll k)
{
    addcnt = subcnt = 0;
    for (ll i = rf; i; i -= lowbit(i))
    {
        addid[++addcnt] = rot[i];
    }
    for (ll i = lf - 1; i; i -= lowbit(i))
    {
        subid[++subcnt] = rot[i];
    }
    return query(1, hs, k);
}
struct queries
{
    ll cmd, l, r, k;
} q[mn * 2];
char c[10];
signed main()
{
    sc(n), sc(m), hs = n;
    for (ll i = 1; i <= n; ++i)
    {
        sc(a[i]), h[i] = a[i];
    }
    for (ll i = 1; i <= m; ++i)
    {
        scanf("%s", c), sc(q[i].l), sc(q[i].r);
        if (c[0] == 'Q')
        {
            sc(q[i].k);
        }
        else
        {
            q[i].cmd = 1, h[++hs] = q[i].r;
        }
    }
    sort(h + 1, h + 1 + hs);
    hs = unique(h + 1, h + 1 + hs) - (h + 1);
    for (ll i = 1; i <= n; ++i)
    {
        updates(i, 1);
    }
    for (ll i = 1; i <= m; ++i)
    {
        if (q[i].cmd == 0)
        {
            printf("%lld\n", h[querys(q[i].l, q[i].r, q[i].k)]);
        }
        else
        {
            updates(q[i].l, -1);
            a[q[i].l] = q[i].r;
            updates(q[i].l, 1);
        }
    }
    return 0;
}