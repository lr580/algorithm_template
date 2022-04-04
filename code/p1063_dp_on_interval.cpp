#include <bits/stdc++.h>
#define MAXN 205
#define pr pair<int, int>
using namespace std;
int n, e, a[MAXN][MAXN], b[MAXN], ans;//a为[i,j]内答案
signed main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &b[i]);
		b[i + n] = b[i];
	}
	for (int i = 2; i <= n + 1; ++i)//区间长
	{
		for (int lf = 1, rf = lf + i - 1; rf <= n + n; ++lf, ++rf)
		{
			for (int k = lf + 1; k <= rf - 1; ++k)
			{
				a[lf][rf] = max(a[lf][rf], a[lf][k] + a[k][rf] + b[lf] * b[k] * b[rf]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) ans = max(ans, a[i][i + n]);
	printf("%d", ans);
	return 0;
}