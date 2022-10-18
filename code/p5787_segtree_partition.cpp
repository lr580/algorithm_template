#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
using ll = int;
using trip = tuple<ll, ll, ll>; //感觉pair就行
struct stk
{
    vector<trip> a;
    ll top;
    void push(trip v) { a[++top] = v; }
    trip pop() { return a[top--]; }
} s;
signed main()
{
    ll n, m, k;
    sc(n), sc(m), sc(k);
    using edge = pair<ll, ll>;
    vector<vector<edge>> e(4 * k + 10, vector<edge>());
#define lfs p << 1
#define rfs p << 1 | 1
#define mkcf ll cf = (lf + rf) >> 1
    auto insert = [&](auto self, ll p, ll lf, ll rf, ll lc, ll rc, edge v) -> void
    {
        if (lf >= lc && rf <= rc)
        {
            e[p].push_back(v);
            return;
        }
        mkcf;
        if (lc <= cf)
        {
            self(self, lfs, lf, cf, lc, rc, v);
        }
        if (rc >= cf + 1)
        {
            self(self, rfs, cf + 1, rf, lc, rc, v);
        }
    };
    for (ll i = 1, x, y, l, r; i <= m; ++i)
    {
        sc(x), sc(y), sc(l), sc(r), ++l;
        insert(insert, 1, 1, k, l, r, {x, y});
    }
    vector<ll> fa(2 * n + 10), h(2 * n + 10, 1);
    for (ll i = 1; i <= 2 * n; ++i)
    {
        fa[i] = i;
    }
    auto findf = [&](ll x)
    {
        while (x != fa[x])
        {
            x = fa[x] = fa[fa[x]];
        }
        return x;
    };
    ll cnt = 0;
    for (ll i = 1; i <= 4 * k; ++i)
    {
        cnt += e[i].size();
    }
    s.a.resize(cnt * 2 + 10); //我也不知道怎么定的,cnt都行
    auto merge = [&](ll x, ll y)
    {
        ll fx = findf(x), fy = findf(y);
        if (h[fx] > h[fy])
        {
            swap(fx, fy);
        }
        s.push({fx, fy, h[fx] == h[fy]});
        fa[fx] = fy, h[fy] += h[fx] == h[fy];
    };
    auto solve = [&](auto self, ll p, ll lf, ll rf) -> void
    {
        bool ok = true;
        ll lastTop = s.top;
        for (edge x : e[p])
        {
            ll u = x.first, v = x.second;
            if (findf(u) == findf(v))
            {
                ok = false;
                for (ll i = lf; i <= rf; ++i)
                {
                    printf("No\n");
                }
                break;
            }
            merge(u, v + n), merge(u + n, v);
        }
        if (ok)
        {
            if (lf == rf)
            {
                printf("Yes\n");
                return;
            }
            mkcf;
            self(self, lfs, lf, cf), self(self, rfs, cf + 1, rf);
        }
        while (s.top > lastTop)
        {
            trip nd = s.pop();
            ll x, y, dt;
            tie(x, y, dt) = nd;
            h[fa[x]] -= dt;
            fa[x] = x;
        }
    };
    solve(solve, 1, 1, k);
    return 0;
}