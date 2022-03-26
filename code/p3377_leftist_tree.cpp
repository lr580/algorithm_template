#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define MAXN 100002
ll n, m, op, x, y, lc[MAXN], rc[MAXN], d[MAXN], rt[MAXN];
bool tf[MAXN];
struct node
{
    ll i, v;
    bool operator<(const node &x) const
    {
        return v == x.v ? i < x.i : v < x.v;
    }
} v[MAXN];
inline ll finds(ll x)
{
    while (x != rt[x])
        x = rt[x] = rt[rt[x]];
    return x;
}
ll merge(ll x, ll y)
{
    if (!x || !y)
        return x + y;
    if (v[y] < v[x])
        swap(x, y);
    rc[x] = merge(rc[x], y);
    if (d[lc[x]] < d[rc[x]])
        swap(lc[x], rc[x]);
    d[x] = d[rc[x]] + 1;
    return x;
}
signed main()
{
    d[0] = -1;
    scanf("%d%d", &n, &m);
    for (ll i = 1; i <= n; ++i)
        scanf("%d", &v[i].v), v[i].i = i, rt[i] = i;
    while (m--)
    {
        scanf("%d%d", &op, &x);
        if (op == 1)
        {
            scanf("%d", &y);
            if (tf[x] || tf[y])
                continue;
            x = finds(x), y = finds(y);
            if (x != y)
                rt[x] = rt[y] = merge(x, y);
        }
        else
        {
            if (tf[x])
            {
                printf("-1\n");
                continue;
            }
            x = finds(x);
            printf("%d\n", v[x].v);
            tf[x] = true;
            rt[lc[x]] = rt[rc[x]] = rt[x] = merge(lc[x], rc[x]);
            lc[x] = rc[x] = d[x] = 0;
        }
    }
    return 0;
}