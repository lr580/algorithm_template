#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define sc(x) scanf("%d", &x)
#define mn 1000010
#define lg 24 // log(mn)+4mn
struct node
{
    ll l, r, v;
} t[mn * lg];
ll n, m, rot[mn], a[mn], cnt, cmd, loc, ver, x;
#define mkcf ll cf = (lf + rf) >> 1
ll build(ll lf, ll rf)
{
    ll p = ++cnt;
    if (lf == rf)
    {
        t[p].v = a[lf];
    }
    else
    {
        mkcf;
        t[p].l = build(lf, cf);
        t[p].r = build(cf + 1, rf);
    }
    return p;
}
ll update(ll r, ll lf, ll rf)
{
    ll p = ++cnt;
    if (lf == rf)
    {
        t[p].v = x;
    }
    else
    {
        mkcf;
        if (loc <= cf)
        {
            t[p].l = update(t[r].l, lf, cf);
            t[p].r = t[r].r;
        }
        else
        {
            t[p].l = t[r].l;
            t[p].r = update(t[r].r, cf + 1, rf);
        }
    }
    return p;
}
void query(ll r, ll lf, ll rf)
{
    if (lf == rf)
    {
        x = t[r].v;
        return;
    }
    mkcf;
    if (loc <= cf)
    {
        query(t[r].l, lf, cf);
    }
    else
    {
        query(t[r].r, cf + 1, rf);
    }
}
signed main()
{
    sc(n), sc(m);
    for (ll i = 1; i <= n; ++i)
    {
        sc(a[i]);
    }
    rot[0] = build(1, n);
    for (ll i = 1; i <= m; ++i)
    {
        sc(ver), sc(cmd), sc(loc);
        if (cmd == 1)
        {
            sc(x);
            rot[i] = update(rot[ver], 1, n);
        }
        else
        {
            query(rot[ver], 1, n);
            rot[i] = rot[ver];
            printf("%d\n", x);
        }
    }
    return 0;
}