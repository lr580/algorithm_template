#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define sc(x) scanf("%lld", &x)
#define mn 105
vector<ll> e[mn];
ll m, n, ui, vi, t, mch[mn], vis[mn], r;
bool dfs(ll u, ll st)
{
    if (vis[u] == st)
    {
        return false;
    }
    vis[u] = st;
    for (auto &v : e[u])
    {
        if (!mch[v] || dfs(mch[v], st))
        {
            mch[v] = u;
            return true;
        }
    }
    return false;
}
signed main()
{
    sc(m), sc(n);
    while (true)
    {
        sc(ui), sc(vi);
        if (ui == -1 && vi == -1)
        {
            break;
        }
        e[ui].emplace_back(vi);
    }
    for (ll i = 1; i <= m; ++i)
    {
        if (dfs(i, i))
        {
            ++r;
        }
    }
    printf("%lld\n", r);
    for (ll i = m + 1; i <= n; ++i)
    {
        if (mch[i])
        {
            printf("%lld %lld\n", mch[i], i);
        }
    }
    return 0;
}