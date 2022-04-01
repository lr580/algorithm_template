#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define limn 102
db a[limn][limn];
ll n;
signed main()
{
	scanf("%d", &n);
	repe(i, 1, n) repe(j, 1, n + 1) scanf("%lf", &a[i][j]);
	repe(i, 1, n)
	{
		ll mx = i;
		repe(j, i + 1, n) if (fabs(a[j][i]) > fabs(a[mx][i])) mx = j;
		repe(j, 1, n + 1) swap(a[i][j], a[mx][j]);
		if (!a[i][i]) return !printf("No Solution");
		repe(j, 1, n) if(j!=i)
		{
			db tmp = a[j][i] / a[i][i];
			repe(k, i + 1, n + 1) a[j][k] -= a[i][k] * tmp;
		}
	}
	repe(i, 1, n) printf("%.2lf\n", a[i][n + 1] / a[i][i]);
	return 0;
}