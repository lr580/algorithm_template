#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 10008
#define MAXE 100008
#define BIG 1000000008
struct edge { ll to, w, nx; } e[MAXE];
ll n, m, cnt, hd[MAXN], hp, b[MAXN], c[MAXN], d[MAXN], rf, lf, cf;
bool vis[MAXN];
struct node
{
	ll d, p;
	bool operator<(const node& x) const { return x.d < d; }
};
inline void adde(ll& u, ll& v, ll& w)
{
	e[++cnt] = { v,w,hd[u] };
	hd[u] = cnt;
}
inline bool ck(ll x)
{
	priority_queue<node> q;
	if (x < b[1] || x < b[n]) return false;
	repe(i, 1, n) d[i] = BIG;
	repe(i, 1, n)
	{
		if (x < b[i]) vis[i] = true;
		else vis[i] = false;
	}
	d[1] = 0;
	q.push({ 0,1 });
	while (!q.empty())
	{
		node no = q.top(); q.pop();
		if (vis[no.p]) continue;
		vis[no.p] = true;
		for (ll i = hd[no.p]; i; i = e[i].nx)
		{
			if (d[e[i].to] > e[i].w + d[no.p])
			{
				d[e[i].to] = e[i].w + d[no.p];
				if (!vis[e[i].to])
					//vis[e[i].to]=true,
					q.push({ d[e[i].to],e[i].to });
			}
			//if (e[i].to == n) return d[n] < hp;
		}
	}
	return d[n] < hp;
}
ll ui, vi, wi, ans;
signed main()
{
	scanf("%d%d%d", &n, &m, &hp);
	repe(i, 1, n) scanf("%d", b + i), c[i] = b[i];
	repe(i, 1, m)
	{
		scanf("%d%d%d", &ui, &vi, &wi);
		if (ui == vi) continue;
		adde(ui, vi, wi), adde(vi, ui, wi);
	}
	sort(c + 1, c + 1 + n);
	if (!ck(c[n])) return printf("AFK"), 0;
	lf = 1, rf = n, ans = c[n];
	while (lf <= rf)
	{
		cf = lf + rf >> 1;
		if (ck(c[cf])) ans = c[cf], rf = cf - 1;
		else lf = cf + 1;
	}
	printf("%d", ans);
	return 0;
}