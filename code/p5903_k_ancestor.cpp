#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define MAXN 500002
#define ui unsigned int
#define sc(x) scanf("%d", &x)
ll n, g[MAXN], d[MAXN], f[MAXN][20], son[MAXN], dep[MAXN], top[MAXN];
ll q, rt, ans, o, x, k;
vector<ll> e[MAXN], u[MAXN], v[MAXN];
long long res;
ui s;
inline ui get(ui x)
{
    x ^= x << 13, x ^= x >> 17, x ^= x << 5;
    return s = x;
}
void dfs1(ll x)
{
    dep[x] = d[x] = d[f[x][0]] + 1;
    for (auto y : e[x])
    {
        f[y][0] = x;
        for (ll i = 0; f[y][i]; ++i)
            f[y][i + 1] = f[f[y][i]][i];
        dfs1(y);
        if (dep[y] > dep[x])
            dep[x] = dep[y], son[x] = y;
    }
}
void dfs2(ll x, ll p)
{
    top[x] = p;
    if (x == p)
    {
        o = x;
        for (ll i = 0; i <= dep[x] - d[x]; ++i)
            u[x].push_back(o), o = f[o][0];
        o = x;
        for (ll i = 0; i <= dep[x] - d[x]; ++i)
            v[x].push_back(o), o = son[o];
    }
    if (son[x])
        dfs2(son[x], p);
    for (auto y : e[x])
        if (y != son[x])
            dfs2(y, y);
}
inline ll ask(ll x, ll k)
{
    if (!k)
        return x;
    x = f[x][g[k]], k -= 1 << g[k];
    k -= d[x] - d[top[x]], x = top[x];
    return k >= 0 ? u[x][k] : v[x][-k];
}
signed main()
{
    scanf("%d%d%d", &n, &q, &s);
    g[0] = -1;
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%d", &f[i][0]);
        e[f[i][0]].push_back(i), g[i] = g[i >> 1] + 1;
    }
    rt = e[0][0];
    dfs1(rt);
    dfs2(rt, rt);
    for (ll i = 1; i <= q; ++i)
    {
        x = (get(s) ^ ans) % n + 1;
        k = (get(s) ^ ans) % d[x];
        res ^= 1LL * i * (ans = ask(x, k));
    }
    printf("%lld", res);
    return 0;
}