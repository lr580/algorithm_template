#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 100010
ll n, m, x, bin[mn], ans[mn], sq, a[mn], sum;
struct query
{
    ll l, r, i;
    bool operator<(const query &x) const
    {
        if (l / sq != x.l / sq)
            return l < x.l;
        if (l / sq & 1)
            return r < x.r;
        return r > x.r;
    }
} q[mn];
void add(ll i)
{
    sum += bin[a[i]]++ == 0;
}
void del(ll i)
{
    sum -= --bin[a[i]] == 0;
}
signed main()
{
    sc(n), sc(m), sq = sqrt(n);
    for (ll i = 1; i <= n; ++i)
    {
        sc(a[i]);
    }
    for (ll i = 1; i <= m; ++i)
    {
        sc(q[i].l), sc(q[i].r), q[i].i = i;
    }
    sort(q + 1, q + 1 + m);
    for (ll i = 1, l = 1, r = 0; i <= m; ++i)
    {
        while (l > q[i].l)
            add(--l);
        while (r < q[i].r)
            add(++r);
        while (l < q[i].l)
            del(l++);
        while (r > q[i].r)
            del(r--);
        ans[q[i].i] = sum == (q[i].r - q[i].l + 1);
    }
    for (ll i = 1; i <= m; ++i)
    {
        printf("%s\n", ans[i] ? "Yes" : "No");
    }
    return 0;
}