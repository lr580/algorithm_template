#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <const int mn, class ty = int>
struct MinCostMaxFlow
{
    const ty inf = numeric_limits<ty>::max();
    struct edge
    {
        int v;
        ty cap, cost;
        int rev;
    };
    vector<edge> g[mn];
    ty sum{}, dis[mn]{};
    int n, s, t, aug[mn]{};
    ty flow{}, cost{};
    bool augment()
    {
        fill(dis, dis + n + 1, inf);
        priority_queue<pair<int, int>> q;
        dis[t] = 0;
        q.push({dis[t], t});
        for (int u, v; !q.empty() && q.top().first != inf;)
        {
            u = q.top().second;
            q.pop();
            for (auto e : g[u])
            {
                v = e.v;
                if (g[v][e.rev].cap && dis[v] > dis[u] - e.cost)
                {
                    dis[v] = dis[u] - e.cost;
                    q.push({dis[v], v});
                }
            }
        }
        sum += dis[s];
        for (int u = 1; u <= n; ++u)
        {
            for (auto &e : g[u])
            {
                e.cost += dis[e.v] - dis[u];
            }
        }
        return dis[s] != inf;
    }

    ty dfs(int u, ty lim)
    {
        if (u == t)
        {
            cost += lim * sum;
            return lim;
        }
        ty f = 0;
        aug[u] = 1;
        for (auto &e : g[u])
        {
            int v = e.v;
            if (!e.cost && e.cap && !aug[v])
            {
                ty t = dfs(v, min(lim - f, e.cap));
                e.cap -= t;
                g[v][e.rev].cap += t;
                f += t;
                if (f == lim)
                {
                    break;
                }
            }
        }
        if (f == lim)
        {
            aug[u] = 0;
        }
        return f;
    }

    void add(int u, int v, ty cap, ty cost)
    {
        g[u].push_back({v, cap, cost, (int)g[v].size()});
        g[v].push_back({u, 0, -cost, (int)g[u].size() - 1});
    }

    pair<ty, ty> solve(int _n, int _s, int _t)
    {
        n = _n, s = _s, t = _t, flow = cost = 0;
        do
        {
            ty f;
            do
            {
                memset(aug, 0, (n + 1) << 2);
                f = dfs(s, inf);
                flow += f;
            } while (f > 0);
        } while (augment());
        return {flow, cost};
    }
};

const ll mn = 405;
MinCostMaxFlow<mn * 2, int> d;
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    int n, m;
    char a[mn];
    cin >> n >> m;
    int s = n + m + 1, t = s + 1;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> (a + 1);
        d.add(s, i, 1, 0);
        for (ll j = 1; j <= m; ++j)
        {
            if (a[j] == '1')
            {
                d.add(i, n + j, 1, 0);
            }
        }
    }
    for (ll i = 1; i <= m; ++i)
    {
        for (ll j = 1; j <= n; ++j)
        {
            d.add(n + i, t, 1, j);
        }
    }
    auto f = d.solve(t, s, t);
    if (f.first != n)
    {
        cout << -1;
        return 0;
    }
    for (ll i = 1; i <= n; ++i)
    {
        for (auto e : d.g[i])
        {
            if (!e.cap && e.v > n)
            {
                cout << (e.v - n) << ' ';
                break;
            }
        }
    }
    return 0;
}