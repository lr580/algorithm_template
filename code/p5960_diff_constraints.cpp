 #include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 5002
struct edge { ll u, v, w; } e[MAXN];
ll d[MAXN], n, m, c0, c1, y;
signed main()
{
	scanf("%d%d", &n, &m);
	repe(i, 1, m) scanf("%d%d%d", &c0, &c1, &y), e[i] = { c1,c0,y };
	repe(i, 1, n) d[i] = (i == 1 ? 0 : 0x3f3f3f3f);
	rep(i, 1, n) repe(j, 1, m) 
		d[e[j].v] = min(d[e[j].u] + e[j].w, d[e[j].v]);
	repe(i, 1, m) if (d[e[i].v] > d[e[i].u] + e[i].w)
		return !printf("NO");
	repe(i, 1, n) printf("%d ", d[i]);
	return 0;
}