#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define mn 100002
ll n, q, m, type, ii;
vector<ll> v[mn];
signed main()
{
	scanf("%d%d%d%d", &type, &n, &q, &m);
	for(ll i=1;i<=n;++i) scanf("%d", &ii), v[ii].push_back(i);
	while (q--)
	{
		ll len, at = 0, x;
		bool suc = true;
		scanf("%d", &len);
		while (len--)
		{
			scanf("%d", &x);
			if (!suc) continue;
			auto it = lower_bound(v[x].begin(), v[x].end(), at + 1);
			if (it == v[x].end()) suc = false;
			else at = *it;
		}
		printf(suc ? "Yes\n" : "No\n");
	}
	return 0;
}