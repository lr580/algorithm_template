#include <bits/stdc++.h>
using namespace std;
typedef long long ln;
typedef int ll;
#define mn  10000002
#define mod 1000000007
ll n, k, p[mn], pri[mn], e[mn], pe[mn], g[mn], cnt; ln ans = 1;
void euler(ll n)
{//e[i]是i质因数分解得到的最大的幂a_i,pe[i]是对应最大的(p^e[i])
	for(ll i=2;i<=n;++i)
	{
		if (!p[i]) p[i] = i, pri[++cnt] = i, pe[i] = i, e[i] = 1;
		for (ll j = 1; i * pri[j] <= n; ++j)
		{
			p[i * pri[j]] = pri[j];
			if (pri[j] == p[i])
			{
				e[i * pri[j]] = e[i] + 1;
				pe[i * pri[j]] = pe[i] * pri[j];
				break;
			}
			e[i * pri[j]] = 1;
			pe[i * pri[j]] = pri[j];		
        }
	}
}
ln qpow(ln a, ln b)
{
	ln res = 1;
	for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
	return res;
}
signed main()
{
    euler(100); g[1] = 1;
	scanf("%d%d",&n,&k);
	for(ll i=1;i<=n;++i)
	{
		if (pe[i] == i) g[i] = (qpow(p[i], 1LL * e[i] * k + 1) - 1 + mod) % mod * qpow(p[i] - 1, mod - 2) % mod;
		else g[i] = 1LL * g[i / pe[i]] * g[pe[i]] % mod;
		(ans += g[i]) %= mod;
	}
	return printf("%lld", ans) & 0;
}