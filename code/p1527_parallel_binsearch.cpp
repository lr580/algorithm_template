#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 510
#define mm 60010
ll n, t, n2, b[mn][mn];
struct matrix
{ //结构体排序方便
    ll i, j, v;
    bool operator<(const matrix &r) const { return v < r.v; }
} a[mn * mn];
struct queries
{
    ll ax, ay, bx, by, k;
} q[mm];
ll qid[mm], tmp1[mm], tmp2[mm], ans[mm], now[mm];
ll lowbit(ll x) { return x & -x; }
void add(ll x, ll y, ll v)
{
    for (ll i = x; i <= n; i += lowbit(i))
        for (ll j = y; j <= n; j += lowbit(j))
            b[i][j] += v;
}
ll get(ll x, ll y)
{
    ll res = 0;
    for (ll i = x; i; i -= lowbit(i))
        for (ll j = y; j; j -= lowbit(j))
            res += b[i][j];
    return res;
}
ll gets(queries p)
{
    return get(p.bx, p.by) - get(p.ax - 1, p.by) - get(p.bx, p.ay - 1) + get(p.ax - 1, p.ay - 1);
}
void solve(ll lf, ll rf, ll lc, ll rc)
{
    if (lc > rc)
        return;
    if (lf == rf)
    {
        for (ll i = lc; i <= rc; ++i)
            ans[qid[i]] = a[lf].v;
        return;
    }
    ll cf = (lf + rf) >> 1;
    for (ll i = lf; i <= cf; ++i)
        add(a[i].i, a[i].j, 1);
    ll cnt1 = 0, cnt2 = 0;
    for (ll i = lc, u; i <= rc; ++i)
    {
        u = qid[i];
        ll s = now[u] + gets(q[u]);
        if (s >= q[u].k)
            tmp1[++cnt1] = u;
        else
            tmp2[++cnt2] = u, now[u] = s; // 本质为u-s
    }
    ll j = lc - 1;
    for (ll i = 1; i <= cnt1; ++i)
        qid[++j] = tmp1[i];
    for (ll i = 1; i <= cnt2; ++i)
        qid[++j] = tmp2[i];
    for (ll i = lf; i <= cf; ++i)
        add(a[i].i, a[i].j, -1);
    solve(lf, cf, lc, lc + cnt1 - 1);
    solve(cf + 1, rf, lc + cnt1, rc);
}
signed main()
{
    sc(n), sc(t);
    for (ll i = 1; i <= n; ++i)
    {
        for (ll j = 1, v; j <= n; ++j)
        {
            sc(v);
            a[++n2] = {i, j, v};
        }
    }
    sort(a + 1, a + 1 + n2);
    for (ll i = 1; i <= t; ++i)
    {
        sc(q[i].ax), sc(q[i].ay), sc(q[i].bx), sc(q[i].by), sc(q[i].k);
        qid[i] = i;
    }
    solve(1, n2, 1, t);
    for (ll i = 1; i <= t; ++i)
        printf("%lld\n", ans[i]);
    return 0;
}