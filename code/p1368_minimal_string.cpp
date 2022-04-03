#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans, a[300002], i, j = 1, k;
signed main()
{
	scanf("%lld", &n);
	for(ll i=0;i<n;++i) scanf("%lld", a + i);
	while (i < n && j < n && k < n)
	{
		if (a[(i + k) % n] == a[(j + k) % n]) ++k;
		else
		{
			if (a[(i + k) % n] > a[(j + k) % n]) i += k + 1;
			else j += k + 1;
			if (i == j) ++i; 
			k = 0;
		}
	}
	ans = min(i, j);
	for(ll i=0;i<n;++i) printf("%lld ", a[(i + ans) % n]);
	return 0;
}