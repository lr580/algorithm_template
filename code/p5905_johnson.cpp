#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define MAXN 5006
#define BIG 1000000000
struct edge { ll to, nx, w; } e[MAXN<<1];
struct node
{
	ll d, i;
	bool operator<(const node& x)const { return d > x.d; }
	node(ll x, ll y) { d = x, i = y; }
};
ll hd[MAXN], t[MAXN], cnt, n, m, h[MAXN], dis[MAXN], ui, vi, wi, ans;
bool vis[MAXN];
inline void adde(ll& u, ll& v, ll& w)
{
	e[++cnt] = { v,hd[u],w };
	hd[u] = cnt;
}
inline bool spfa(ll x)
{
	queue<ll> q;
	memset(h, 63, sizeof h);
	h[x] = 0, vis[x] = true; q.push(x);
	while (!q.empty())
	{
		ll y = q.front(); q.pop();
		vis[y] = false;
		for (ll i = hd[y]; i; i = e[i].nx)
		{
			ll z = e[i].to;
			if (h[z] > h[y] + e[i].w)
			{
				h[z] = h[y] + e[i].w;
				if (!vis[z])
				{
					vis[z] = true, ++t[z];
					q.push(z);
					if (t[z] > n) return false;
				}
			}
		}
	}
	return true;
}
inline void dijkstra(ll x)
{
	priority_queue<node> q;
	repe(i, 1, n) dis[i] = BIG;
	memset(vis, 0, sizeof vis);
	dis[x] = 0;
	q.push(node(0, x));
	while (!q.empty())
	{
		ll u = q.top().i; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (ll i = hd[u]; i; i = e[i].nx)
		{
			ll v = e[i].to;
			if (dis[v] > dis[u] + e[i].w)
			{
				dis[v] = dis[u] + e[i].w;
				if (!vis[v]) q.push(node(dis[v], v));
			}
		}
	}
}
signed main()
{
	scanf("%lld%lld", &n, &m);
	repe(i, 1, m) scanf("%lld%lld%lld", &ui, &vi, &wi), adde(ui, vi, wi);
	repe(i, 1, n) adde(ans, i, ans);
	if (!spfa(0)) return !printf("-1");
	repe(u, 1, n) for (ll i = hd[u]; i; i = e[i].nx)
		e[i].w += h[u] - h[e[i].to];
	repe(i,1,n)
	{
		dijkstra(i);
		ans = 0;
		repe(j, 1, n)
		{
			if (dis[j] == BIG) ans += j * BIG;
			else ans += j * (dis[j] + h[j] - h[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}