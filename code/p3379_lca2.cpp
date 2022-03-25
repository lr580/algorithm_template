#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
typedef int ll;
const ll N = 1e6 + 10; //开二倍长
ll n, m, s, tot, cnt;
ll head[N], to[N], Next[N], Log[N];
inline void addedge(ll x, ll y)
{
    to[++tot] = y;
    Next[tot] = head[x];
    head[x] = tot;
}
ll a[N], dep[N], mn[21][N], p[N];
inline void dfs(ll x, ll fa)
{
    a[++cnt] = x;
    p[x] = cnt;
    dep[x] = dep[fa] + 1;
    for (ll i = head[x]; i; i = Next[i])
    {
        ll u = to[i];
        if (u == fa)
            continue;
        dfs(u, x);
        a[++cnt] = x;
    }
}
signed main()
{
    sc(n), sc(m), sc(s);
    Log[0] = -1;
    for (ll i = 1, x, y; i < n; ++i)
        sc(x), sc(y), addedge(x, y), addedge(y, x);
    dfs(s, 0);
    for (ll i = 1; i <= cnt; ++i)
        mn[0][i] = a[i];
    for (ll i = 1; i <= 20; ++i)
        for (ll j = 1; j + (1 << i) <= cnt; ++j)
            if (dep[mn[i - 1][j]] < dep[mn[i - 1][j + (1 << (i - 1))]])
                mn[i][j] = mn[i - 1][j];
            else
                mn[i][j] = mn[i - 1][j + (1 << (i - 1))];
    for (ll i = 1; i <= cnt; ++i)
        Log[i] = Log[i >> 1] + 1;
    for (ll i = 1, x, y; i <= m; ++i)
    {
        sc(x), sc(y);
        if (p[x] > p[y])
            swap(x, y);
        ll k = Log[p[y] - p[x] + 1], ans;
        if (dep[mn[k][p[x]]] < dep[mn[k][p[y] - (1 << k) + 1]])
            ans = mn[k][p[x]];
        else
            ans = mn[k][p[y] - (1 << k) + 1];
        printf("%d\n", ans);
    }
    return 0;
}