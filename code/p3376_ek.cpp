#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define me 5010
#define mn 205
ll n, m, s, t, u, v;
ll w, ans, dis[mn];
ll tot = 1, vis[mn], pre[mn], head[mn], flag[mn][mn];
struct node
{
    ll to, net;
    ll val;
} e[me * 2];
void add(ll u, ll v, ll w)
{
    e[++tot] = {v, head[u], w};
    head[u] = tot;
}
ll bfs()
{ // bfs寻找增广路
    for (ll i = 1; i <= n; i++)
        vis[i] = 0;
    queue<ll> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 0x7fffffffffff;
    while (!q.empty())
    {
        ll x = q.front();
        q.pop();
        for (ll i = head[x]; i; i = e[i].net)
        {
            if (e[i].val == 0)
                continue; //我们只关心剩余流量>0的边
            ll v = e[i].to;
            if (vis[v] == 1)
                continue; //这一条增广路没有访问过
            dis[v] = min(dis[x], e[i].val);
            pre[v] = i; //记录前驱，方便修改边权
            q.push(v);
            vis[v] = 1;
            if (v == t)
                return 1; //找到了一条增广路
        }
    }
    return 0;
}
void update()
{ //更新所经过边的正向边权以及反向边权
    ll x = t;
    while (x != s)
    {
        ll v = pre[x];
        e[v].val -= dis[t];
        e[v ^ 1].val += dis[t];
        x = e[v ^ 1].to;
    }
    ans += dis[t]; //累加每一条增广路经的最小流量值
}
signed main()
{
    scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
    for (ll i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld", &u, &v, &w);
        if (flag[u][v] == 0)
        { //处理重边的操作（加上这个模板题就可以用Ek算法过了）
            add(u, v, w), add(v, u, 0);
            flag[u][v] = tot;
        }
        else
        {
            e[flag[u][v] - 1].val += w;
        }
    }
    while (bfs() != 0)
    { //直到网络中不存在增广路
        update();
    }
    printf("%lld", ans);
    return 0;
}