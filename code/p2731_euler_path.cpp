#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 512
ll m, s = 1, g[mn][mn], du[mn], n;
stack<ll> ans;
void dfs(ll u)
{
    for (ll v = 1; v <= n; ++v)
    {
        if (g[u][v] > 0)
        {
            --g[u][v], --g[v][u];
            dfs(v);
        }
    }
    ans.push(u);
}
signed main()
{
    scanf("%lld", &m);
    for (ll i = 0, u, v; i < m; ++i)
    {
        scanf("%lld%lld", &u, &v);
        ++du[u], ++du[v], ++g[u][v], ++g[v][u];
        n = max(n, max(u, v));
    }
    for (ll i = 1; i <= n; ++i)
    {
        if (du[i] & 1)
        {
            s = i;
            break;
        }
    }
    dfs(s);
    while (!ans.empty())
    {
        printf("%lld\n", ans.top());
        ans.pop();
    }
    return 0;
}