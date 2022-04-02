#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
#define mn 100002
ll a[mn], p, t, n, m;//i!=a[i]
ll qpow(ll a, ll b)
{
	ll res = 1;
	for (; b; b >>= 1, a = a * a % p) if (b & 1)
		res = res * a % p;
	return res;
}
ll C(ll n, ll m)
{
	if (m > n) return 0;
	return ((a[n] * qpow(a[m], p - 2)) % p * qpow(a[n - m], p - 2) % p);
}
ll lucas(ll n, ll m)
{
	if (!m) return 1;
	return C(n % p, m % p) * lucas(n / p, m / p) % p;
}
signed main()
{
	a[0] = 1;
	for (scanf("%lld", &t); t; --t)
	{
		scanf("%lld%lld%lld", &n, &m, &p);
		for(ll i = 1; i <= p; ++i) a[i] = a[i - 1] * i % p;
		printf("%lld\n", lucas(n + m, n));//原题算C(m+n,n)
	}
	return 0;
}