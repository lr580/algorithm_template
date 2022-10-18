// https://ac.nowcoder.com/acm/contest/view-submission?submissionId=53577891
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
const ll mn = 1e5 + 10;
ll n, m, hd[mn], cnt, w[mn], eu[mn], ev[mn];
struct edge
{
    ll to, nx, idx, w = 0, isbridge = false;
} e[mn * 2], e2[mn * 2];
ll st, dfn[mn], low[mn], dcnt, vis[mn];
vector<ll> dcc[mn]; //边双
ll hd2[mn], cnt2, h[mn], d[mn], cur[mn];
signed main()
{
    sc(n), sc(m);
    auto adde = [&](ll u, ll v, ll w, ll idx)
    {
        e[++cnt] = {v, hd[u], idx};
        hd[u] = cnt;
        ::w[idx] = w, eu[idx] = u, ev[idx] = v;
    };
    for (ll i = 1, u, v, w; i <= m; ++i)
    {
        sc(u), sc(v), sc(w), adde(u, v, w, i), adde(v, u, w, i);
    }
    auto tarjan = [&](auto self, ll u, ll fa) -> void
    {
        dfn[u] = low[u] = ++st;
        for (ll i = hd[u]; i; i = e[i].nx)
        {
            ll v = e[i].to, idx = e[i].idx;
            if (!dfn[v])
            {
                self(self, v, u);
                low[u] = min(low[u], low[v]);
                if (dfn[u] < low[v])
                {
                    e[idx].isbridge = true;
                }
            }
            else if (v != fa)
            {
                low[u] = min(low[u], dfn[v]);
            }
        }
    };
    tarjan(tarjan, 1, 0);
    auto dfs = [&](auto self, ll u) -> void
    {
        vis[u] = true;
        for (ll i = hd[u]; i; i = e[i].nx)
        {
            ll v = e[i].to, idx = e[i].idx;
            if (!e[idx].isbridge)
            {
                dcc[dcnt].push_back(idx);
                if (!vis[v])
                {
                    self(self, v);
                }
            }
        }
    };
    for (ll i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            ++dcnt;
            dfs(dfs, i);
        }
    }
    ll res = -1, id = 0;
    for (ll i = 1; i <= dcnt; ++i)
    {
        sort(dcc[i].begin(), dcc[i].end());
        dcc[i].erase(unique(dcc[i].begin(), dcc[i].end()), dcc[i].end());
        sort(dcc[i].begin(), dcc[i].end(), [&](ll u, ll v)
             { return w[u] < w[v]; });
        if (dcc[i].size() >= 2)
        {
            ll x = w[dcc[i].back()] - w[dcc[i].front()];
            if (x > res)
            {
                res = x, id = i;
            }
        }
    }
    printf("%lld\n", res);

    //网络流是有向图，所以要重建图
    memset(hd2, -1, sizeof hd2);
    ll s = n + 1, t = n + 2, mxi = dcc[id].back(), mii = dcc[id].front();
    auto adde2 = [&](ll u, ll v, ll w = 1)
    {
        e2[cnt2] = {v, hd2[u], 0, w};
        hd2[u] = cnt2++;
    };
    adde2(s, eu[mxi]), adde2(eu[mxi], s, 0); //注意顺序
    adde2(s, ev[mxi]), adde2(ev[mxi], s, 0);
    adde2(eu[mii], t), adde2(t, eu[mii], 0);
    adde2(ev[mii], t), adde2(t, ev[mii], 0);
    for (auto i : dcc[id])
    {
        if (i != mxi && i != mii)
        {
            adde2(eu[i], ev[i]), adde2(ev[i], eu[i]);
        }
    }

    auto dinic_dfs = [&](auto self, ll u, ll limit) -> ll
    {
        // printf("<%lld %lld\n", u, limit);
        if (u == t)
        {
            return limit;
        }
        ll flow = 0;
        for (ll i = cur[u]; i != -1 && flow < limit; i = e2[i].nx)
        {
            cur[u] = i; //输出路径
            ll v = e2[i].to;
            if (d[v] == d[u] + 1 && e2[i].w)
            {
                ll dlt = self(self, v, min(e2[i].w, limit - flow));
                if (!dlt)
                {
                    d[v] = -1;
                }
                e2[i].w -= dlt;
                e2[i].idx += dlt;
                e2[i ^ 1].w += dlt;
                e2[i ^ 1].idx -= dlt;
                flow += dlt;
            }
        }
        return flow;
    };
    auto dinic_bfs = [&]() -> bool
    {
        memset(d, -1, sizeof d);
        queue<ll> q;
        q.push(s);
        d[s] = 0, cur[s] = hd2[s];
        while (!q.empty())
        {
            ll u = q.front();
            q.pop();
            for (ll i = hd2[u]; i != -1; i = e2[i].nx)
            {
                ll v = e2[i].to;
                // printf("?%lld %lld\n", u, v);
                if (d[v] == -1 && e2[i].w)
                {
                    d[v] = d[u] + 1, cur[v] = hd2[v];
                    if (v == t)
                    {
                        return true;
                    }
                    q.push(v);
                }
            }
        }
        return false;
    };
    auto dinic = [&]()
    {
        ll res = 0;
        while (dinic_bfs())
        {
            res += dinic_dfs(dinic_dfs, s, 1e18);
        }
        return res;
    };
    dinic();

    vector<ll> res1, res2;
    auto dfs2 = [&](auto self, ll u, vector<ll> &res) -> void
    {
        res.push_back(u);
        for (ll i = hd2[u]; i != -1; i = e2[i].nx)
        {
            ll v = e2[i].to;
            if (e2[i].idx > 0)
            {
                e2[i].idx--;
                self(self, v, res);
                break;
            }
        }
    };
    dfs2(dfs2, s, res1);
    dfs2(dfs2, s, res2);
    reverse(res2.begin(), res2.end());
    printf("%lld\n", res1.size() + res2.size() - 4);
    auto print = [&](vector<ll> &res)
    {
        for (auto i : res)
        {
            if (i != s && i != t)
            {
                printf("%lld ", i);
            }
        }
    };
    print(res1), print(res2);
    return 0;
}