#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 100020
ll n, m, r, mod, ui, vi, k, x, y, z;
#define mkcf ll cf = (lf + rf) >> 1
#define lfs p << 1
#define rfs p << 1 | 1
ll hd[mn], cnt, w[mn], wt[mn];
struct edge
{
    ll to, nx;
} e[mn];
void adde(ll u, ll v)
{
    e[++cnt] = {v, hd[u]};
    hd[u] = cnt;
}
ll a[mn << 2], laz[mn << 2], lc, rc, res, updv;
ll hvson[mn], id[mn], fa[mn], dfn, dep[mn], siz[mn], top[mn];

void pushdown(ll lf, ll rf, ll p)
{
    mkcf;
    laz[lfs] += laz[p], laz[rfs] += laz[p];
    (a[lfs] += laz[p] * (cf - lf + 1)) %= mod;
    (a[rfs] += laz[p] * (rf - cf)) %= mod;
    laz[p] = 0;
}
void build(ll lf = 1, ll rf = n, ll p = 1)
{
    if (lf == rf)
    {
        a[p] = wt[lf] % mod;
        return;
    }
    mkcf;
    build(lf, cf, lfs), build(cf + 1, rf, rfs);
    a[p] = (a[lfs] + a[rfs]) % mod;
}
void query(ll lf = 1, ll rf = n, ll p = 1)
{
    if (lc <= lf && rf <= rc)
    {
        (res += a[p]) %= mod;
        return;
    }
    pushdown(lf, rf, p);
    mkcf;
    if (lc <= cf)
    {
        query(lf, cf, lfs);
    }
    if (rc > cf)
    {
        query(cf + 1, rf, rfs);
    }
}
void update(ll lf = 1, ll rf = n, ll p = 1)
{
    if (lc <= lf && rf <= rc)
    {
        laz[p] += updv;
        a[p] += updv * (rf - lf + 1) % mod;
        return;
    }
    pushdown(lf, rf, p);
    mkcf;
    if (lc <= cf)
    {
        update(lf, cf, lfs);
    }
    if (rc > cf)
    {
        update(cf + 1, rf, rfs);
    }
    a[p] = (a[lfs] + a[rfs]) % mod;
}

ll qrange(ll x, ll y)
{
    ll ans = 0;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
        {
            swap(x, y);
        }
        res = 0, lc = id[top[x]], rc = id[x], query();
        (ans += res) %= mod;
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
    {
        swap(x, y);
    }
    res = 0, lc = id[x], rc = id[y], query();
    return (ans + res) % mod;
}

void frange(ll x, ll y, ll k)
{
    updv = k % mod;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
        {
            swap(x, y);
        }
        lc = id[top[x]], rc = id[x], update();
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
    {
        swap(x, y);
    }
    lc = id[x], rc = id[y], update();
}

ll qson(ll x)
{
    res = 0, lc = id[x], rc = id[x] + siz[x] - 1, query();
    return res;
}

void fson(ll x, ll k)
{
    updv = k % mod, lc = id[x], rc = id[x] + siz[x] - 1, update();
}

void dfs(ll x, ll f, ll deep)
{
    dep[x] = deep, fa[x] = f, siz[x] = 1;
    ll hvsonv = -1, y;
    for (ll i = hd[x]; i; i = e[i].nx)
    {
        y = e[i].to;
        if (y == f)
        {
            continue;
        }
        dfs(y, x, deep + 1);
        siz[x] += siz[y];
        if (siz[y] > hvsonv)
        {
            hvson[x] = y, hvsonv = siz[y];
        }
    }
}

void dfs(ll x, ll topi)
{
    id[x] = ++dfn, wt[dfn] = w[x], top[x] = topi;
    if (!hvson[x])
    {
        return;
    }
    dfs(hvson[x], topi);
    for (ll i = hd[x]; i; i = e[i].nx)
    {
        ll y = e[i].to;
        if (y == fa[x] || y == hvson[x])
        {
            continue;
        }
        dfs(y, y);
    }
}

signed main()
{
    sc(n), sc(m), sc(r), sc(mod);
    for (ll i = 1; i <= n; ++i)
    {
        sc(w[i]);
    }
    for (ll i = 1; i < n; ++i)
    {
        sc(ui), sc(vi), adde(ui, vi), adde(vi, ui);
    }
    dfs(r, 0, 1), dfs(r, r), build();
    while (m--)
    {
        sc(k), sc(x);
        if (k == 1)
        {
            sc(y), sc(z), frange(x, y, z);
        }
        else if (k == 2)
        {
            sc(y), printf("%lld\n", qrange(x, y));
        }
        else if (k == 3)
        {
            sc(y), fson(x, y);
        }
        else
        {
            printf("%lld\n", qson(x));
        }
    }
    return 0;
}