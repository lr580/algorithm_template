#include <bits/stdc++.h>
using namespace std;
#define mn 100010
typedef long long ll;
ll n, m, ru[mn], cu[mn], s = 1, fail, vis[mn], bgs, eds;
vector<ll> e[mn];
stack<ll> ans;
void dfs(ll u)
{
    for (ll i = vis[u]; i < e[u].size(); i = vis[u])
    { //不i++是可能被后续dfs更新过
        vis[u] = i + 1;
        dfs(e[u][i]);
    }
    ans.push(u);
}
signed main()
{
    scanf("%lld%lld", &n, &m);
    for (ll i = 0, u, v; i < m; ++i)
    {
        scanf("%lld%lld", &u, &v);
        ++cu[u], ++ru[v];
        e[u].emplace_back(v);
    }
    for (ll i = 1; i <= n; ++i)
    {
        if (cu[i] == ru[i] + 1)
        {
            s = i;
            ++bgs;
        }
        else if (ru[i] == cu[i] + 1)
        {
            ++eds;
        }
        if (ru[i] != cu[i])
        {
            ++fail;
        }
        sort(e[i].begin(), e[i].end());
    }
    if (!(fail == 0 || (fail == 2 && bgs == 1 && eds == 1)))
    {
        printf("No");
        return 0;
    }
    dfs(s);
    while (!ans.empty())
    {
        printf("%lld ", ans.top());
        ans.pop();
    }
    return 0;
}