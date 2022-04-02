#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 1000002
#define MOD 666623333
ll l, r, ans, cnt, prime[MAXN], a[MAXN], b[MAXN];
bool vis[MAXN];
signed main()
{
	for(ll i=2;i<=MAXN;++i)
	{
		if (!vis[i]) prime[++cnt] = i;
		for (ll j = i << 1; j <= MAXN; j += i) vis[j] = true;
	}
	scanf("%lld%lld", &l, &r);
	for(ll i=l;i<=r;++i) a[i - l] = b[i - l] = i;
	ll i = 1;
	while (prime[i] * prime[i] <= r)
	{
		ll p = prime[i];
		for (ll x = (p - l % p) % p; x + l <= r; x += p)
		{
			(a[x] /= p) *= p - 1;
			while (b[x] % p == 0) b[x] /= p;
		}
		++i;
	}
	for(ll i=0;i<=r-l;++i)
	{
		if (b[i] != 1) (a[i] /= b[i]) *= b[i] - 1;
		(ans += l + i - a[i]) %= MOD;
	}
	printf("%lld", ans);
	return 0;
}