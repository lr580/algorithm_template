#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 2002
#define MOD 998244353
ll n, k, x[MAXN], y[MAXN], ans, s1, s2;
ll qpow(ll a, ll x)
{
	ll res = 1, t = a;
	for (; x; t = t * t % MOD, x >>= 1) if (x & 1)
		res = res * t % MOD;
	return res;
}
inline ll inv(ll x) { return qpow(x, MOD - 2); }
signed main()
{
	scanf("%lld%lld", &n, &k);
	for(ll i = 1; i <= n; ++i) scanf("%lld%lld", x + i, y + i);
	for(ll i = 1; i <= n; ++i)
	{
		s1 = y[i] % MOD, s2 = 1;
		for(ll j = 1; j <= n; ++j) if (i != j)
			s1 = s1 * (k - x[j]) % MOD,
			s2 = s2 * ((x[i] - x[j] % MOD) % MOD) % MOD;
		ans += s1 * inv(s2) % MOD;
		ans = (ans + MOD) % MOD;
	}
	printf("%lld", ans);
	return 0;
}