#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define MAXN 402
#define MOD 1000000007
ll n, m, f[MAXN][MAXN << 1], r, ret;
ll inv(ll u, ll v)
{
	for (ret = 1; v; u = u * u % MOD, v >>= 1) if (v & 1)
		ret = ret * u % MOD;
	return ret;
}
signed main()
{
	scanf("%lld", &n), m = n << 1;
	repe(i, 1, n)
	{
		repe(j, 1, n) scanf("%lld", &f[i][j]);
		f[i][n + i] = 1;
	}
	repe(i, 1, n)
	{
		repe(j, i, n) if (f[j][i])
		{
			repe(k, 1, m) swap(f[i][k], f[j][k]);
			break;
		}
		if (!f[i][i]) return !printf("No Solution");
		r = inv(f[i][i], MOD - 2);
		repe(j, i, m) f[i][j] = f[i][j] * r % MOD;
		repe(j,1,n) if (j != i)
		{
			r = f[j][i];
			repe(k, i, m) f[j][k] = (f[j][k] - r * f[i][k] % MOD + MOD) % MOD;
		}
	}
	repe(i, 1, n)
	{
		repe(j, n + 1, m) printf("%lld ", f[i][j]);
		printf("\n");
	}
	return 0;
}