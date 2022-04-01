#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 10000002
#define MOD 998244353
ll a, c[MAXN], f[MAXN], ans, v, n, lb[MAXN], k;
ll sum(ll p)
{
	ll res = 0;
	while (p) res += c[p], p -= lb[p];
	return res;
}
void add(ll x, ll&& k)
{
	while (x <= n) c[x] += k, x += lb[x];
}
signed main()
{
	scanf("%lld", &n);
	f[0] = 1;
	for(ll i = 1; i <= n; ++i) f[i] = f[i - 1] * i % MOD;
	for(ll i = 1; i <= n; ++i) lb[i] = i & -i;
	for(ll i = 1; i <= n; ++i) add(i, 1);
	for(ll i = 1; i <= n; ++i)
	{
		scanf("%lld", &a);
		(ans += (sum(a) - 1) * f[n - i] % MOD) %= MOD;
		add(a, -1);
	}
	printf("%lld", (++ans)%MOD);
	return 0;
}