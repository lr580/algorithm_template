#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 1000002
#define SQRTR 50000
ll prime[MAXN], k, ans, lf, rf, p, bg;
bool vis[MAXN];
inline void euler()
{
	for(ll i = 2; i <= SQRTR; ++i)
	{
		if (!vis[i]) prime[++k] = i;
		for (ll j = 1; i * prime[j] <= SQRTR; ++j)
		{
			vis[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}
signed main()
{
	scanf("%lld%lld", &lf, &rf);
	lf = (lf == 1) ? 2 : lf;
	euler();
	memset(vis,0,sizeof vis);
	for(ll i = 1; i <= k; ++i)
	{
		p = prime[i];
		bg = (lf + p - 1) / p * p > 2 * p ? (lf + p - 1) / p * p : 2 * p;
		for (ll j = bg; j <= rf; j += p) vis[j - lf + 1] = true;
	}
	for(ll i = 1; i <= rf - lf + 1; ++i) if (!vis[i]) ++ans;
	printf("%lld", ans);
	return 0;
}