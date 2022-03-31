#include <bits/stdc++.h>
using namespace std;
#define mn 5010
typedef long long ll;
struct edge
{
    ll to, nx;
} e[500010];
ll hd[mn], n, cnt, m, ru[mn];
void adde(ll u, ll v)
{
    e[++cnt] = {v, hd[u]};
    hd[u] = cnt, ++ru[v];
}
#define sc(x) scanf("%lld", &x)
queue<ll> q;
vector<ll> vis;
signed main()
{
    sc(n), sc(m);
    for (ll i = 1, u, v; i <= m; ++i)
    {
        sc(u), sc(v), adde(u, v);
    }
    for (ll i = 1; i <= n; ++i)
    {
        if (ru[i] == 0)
        {
            q.push(i);
        }
    }
    if (q.empty())
    {
        return printf("YE5"), 0;
    }
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        vis.emplace_back(u);
        for (ll i = hd[u], v; i; i = e[i].nx)
        {
            v = e[i].to;
            --ru[v];
            if (!ru[v])
            {
                q.push(v);
            }
        }
    }
    return printf((ll)vis.size() == n ? "N0" : "YE5"), 0;
}
/*
4 4
1 2
2 3
3 4
4 2

4 2
1 2
2 1

2 2
1 2
2 1

3 4
1 2
1 2
2 3
1 3

1 1
1 1

3 3
1 2
2 3
2 2

4 2
1 2
3 4
*/