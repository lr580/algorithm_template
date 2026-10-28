#include <bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN = 2e4 + 10, MAXM = 2e5 + 10;
struct edge
{
    ll to, nx;
} e[MAXM];
ll hd[MAXN], cnt, n, m, dfn[MAXN], low[MAXN], co[MAXN], num[MAXN], conum, st;
bool vis[MAXN];
stack<ll> s;
void adde(ll &u, ll &v)
{
    e[++cnt] = {v, hd[u]};
    hd[u] = cnt;
}
void paint(ll &x)
{
    s.pop();
    co[x] = conum;  //点x属于第conum个分量
    ++num[conum];   //该分量有多少点
    vis[x] = false; //出栈
}
void tarjan(ll x)
{
    dfn[x] = low[x] = ++st;
    s.push(x);
    vis[x] = true;
    for (ll i = hd[x]; i; i = e[i].nx)
    {
        ll toi = e[i].to;
        if (!dfn[toi]) //小心别写成x
        {
            tarjan(toi); //小心别写成x
            low[x] = min(low[x], low[toi]);
        }
        else if (vis[toi])
            low[x] = min(low[x], dfn[toi]);
    }
    if (low[x] == dfn[x])
    {
        ++conum;
        while (s.top() != x)
            paint(s.top());
        paint(x);
    }
}
signed main()
{
    ll ui, vi, ans = 0;
    scanf("%d%d", &n, &m);
    while (m--)
        scanf("%d%d", &ui, &vi), adde(ui, vi);
    for (ll i = 1; i <= n; ++i)
        if (!dfn[i])
            tarjan(i);
    for (ll i = 1; i <= conum; ++i)
        if (num[i] > 1)
            ++ans;
    printf("%d", ans);
    return 0;
}
