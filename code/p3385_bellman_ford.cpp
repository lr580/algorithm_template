#include <bits/stdc++.h>
using namespace std;
typedef int ll;
const ll N = 10010, big = 0x7fffffff;
ll cnt = 0;
struct node
{
    ll x, y, v;
} e[N];
void add(ll x, ll y, ll v) { e[++cnt] = {x, y, v}; }
ll n;
bool bellman()
{
    static ll d[N];
    d[1] = 0;
    for (ll i = 2; i <= n; i++)
        d[i] = big;
    for (ll i = 1; i <= n - 1; i++)
        for (ll j = 1; j <= cnt; j++)
        {
            if (d[e[j].x] != big &&
                d[e[j].x] + e[j].v < d[e[j].y])
                d[e[j].y] = d[e[j].x] + e[j].v;
        }
    for (ll i = 1; i <= cnt; i++)
    {
        if (d[e[i].x] == big || d[e[i].y] == big)
            continue;
        if (d[e[i].x] + e[i].v < d[e[i].y])
            return true; // 负权回路
    }
    return false;
}
signed main()
{
    ll t;
    scanf("%d", &t);
    while (t--)
    {
        memset(e, 0, sizeof(e));
        cnt = 0;
        ll m;
        scanf("%d%d", &n, &m);
        for (ll i = 1; i <= m; i++)
        {
            ll x, y, v;
            scanf("%d%d%d", &x, &y, &v);
            if (v < 0)
                add(x, y, v);
            if (v >= 0)
                add(x, y, v), add(y, x, v);
        }
        if (bellman())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}