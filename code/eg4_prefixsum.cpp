#include <bits/stdc++.h>//https://oj.socoding.cn/p/1193
using namespace std;
typedef long long ll;
map<ll,ll> m;
ll n,c,v,ans;
signed main()
{
	for(scanf("%lld",&n),++m[0];n;--n)
		scanf("%lld",&v),ans+=m[c^=v]++;
	return printf("%lld",ans)&0;
}