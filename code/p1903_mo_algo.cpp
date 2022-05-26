#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 133340
ll n, m, sq, a[mn], a0[mn], ans[mn], m1, m2, sum, bin[1000010];
struct query1
{
    ll l, r, i, c;
    bool operator<(const query1 &x) const
    {
        if (l / sq == x.l / sq)
        {
            return r / sq == x.r / sq ? i < x.i : r < x.r;
        }
        return l < x.l;
    }
} q1[mn];
struct query2
{
    ll i, f, t;
} q2[mn];
void add(ll i)
{
    sum += bin[i]++ == 0;
}
void del(ll i)
{
    sum -= --bin[i] == 0;
}
ll l = 1, r;
void addt(ll t)
{
    if (l <= q2[t].i && q2[t].i <= r)
        del(q2[t].f), add(q2[t].t);
    a0[q2[t].i] = q2[t].t;
}
void delt(ll t)
{
    if (l <= q2[t].i && q2[t].i <= r)
        del(q2[t].t), add(q2[t].f);
    a0[q2[t].i] = q2[t].f;
}
signed main()
{
    sc(n), sc(m), sq = pow(n, 2. / 3);
    for (ll i = 1; i <= n; ++i)
    {
        sc(a[i]), a0[i] = a[i];
    }
    char ch[5] = {};
    for (ll i = 1, x, y; i <= m; ++i)
    {
        scanf("%s%lld%lld", ch, &x, &y);
        if (ch[0] == 'Q')
        {
            ++m1, q1[m1] = {x, y, m1, m2 + 1};
        }
        else
        {
            ++m2, q2[m2] = {x, a[x], y}, a[x] = y;
        }
    }
    sort(q1 + 1, q1 + 1 + m1);
    for (ll i = 1, t = 1; i <= m1; ++i)
    {
        while (t < q1[i].c)
            addt(t++);
        while (t > q1[i].c)
            delt(--t);
        while (l > q1[i].l)
            add(a0[--l]);
        while (r < q1[i].r)
            add(a0[++r]);
        while (l < q1[i].l)
            del(a0[l++]);
        while (r > q1[i].r)
            del(a0[r--]);
        ans[q1[i].i] = sum;
    }
    for (ll i = 1; i <= m1; ++i)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}