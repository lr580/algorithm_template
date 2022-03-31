#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define MAXN 100002
bool vis[MAXN];
ll n, m, s, t, x, y, z, f, dis[MAXN], pre[MAXN], last[MAXN], flow[MAXN];
ll mxflow, micost, cnt, hd[MAXN];
struct edge
{
    ll to, nx, f, d;
} e[MAXN];
queue<ll> q;
void adde(ll &u, ll &v, ll f, ll d)
{
    e[++cnt] = {v, hd[u], f, d};
    hd[u] = cnt;
}
bool spfa(ll s, ll t)
{
    memset(dis, 0x7f, sizeof dis);
    memset(flow, 0x7f, sizeof flow);
    memset(vis, 0, sizeof vis);
    q.push(s);
    vis[s] = true, dis[s] = 0, pre[t] = -1;
    while (!q.empty())
    {
        ll no = q.front();
        q.pop();
        vis[no] = false;
        for (ll i = hd[no]; i != -1; i = e[i].nx)
        {
            ll toi = e[i].to;
            if (e[i].f > 0 && dis[toi] > dis[no] + e[i].d)
            {
                dis[toi] = dis[no] + e[i].d;
                pre[toi] = no;
                last[toi] = i;
                flow[toi] = min(e[i].f, flow[no]);
                if (!vis[toi])
                    vis[toi] = true, q.push(toi);
            }
        }
    }
    return pre[t] != -1;
}
void mcmf()
{
    while (spfa(s, t))
    {
        ll no = t;
        mxflow += flow[t];
        micost += flow[t] * dis[t];
        while (no != s)
        {
            e[last[no]].f -= flow[t];
            e[last[no] ^ 1].f += flow[t];
            no = pre[no];
        }
    }
}
signed main()
{
    memset(hd, -1, sizeof hd);
    cnt = -1; //因为有异或操作，从0开始，否则TLE
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (ll i = 1; i <= m; ++i)
    {
        scanf("%d%d%d%d", &x, &y, &z, &f);
        adde(x, y, z, f);
        adde(y, x, 0, -f);
    }
    mcmf();
    printf("%d %d", mxflow, micost);
    return 0;
}