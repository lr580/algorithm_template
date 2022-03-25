#include <bits/stdc++.h> //https://oj.socoding.cn/p/1395
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 200002
ll n, cnt, hd[mn], rot, mxd;
bool vis[mn];
struct edge
{
    ll to, nx;
} e[mn << 1];
void adde(ll &u, ll &v)
{
    e[++cnt] = {v, hd[u]};
    hd[u] = cnt;
}
void dfs(ll x, ll fa, ll d)
{
    vis[x] = true;
    if (d > mxd)
    {
        mxd = d, rot = x;
    }
    for (ll i = hd[x]; i; i = e[i].nx)
    {
        ll toi = e[i].to;
        if (!vis[toi])
            dfs(toi, x, d + 1);
    }
}
signed main()
{
    sc(n);
    for (ll i = 1, u, v; i < n; ++i)
        sc(u), sc(v), adde(u, v), adde(v, u);
    dfs(1, 0, 0);
    mxd = 0;
    memset(vis, 0, sizeof vis);
    dfs(rot, 0, 0);
    printf("%lld", mxd);
    return 0;
}