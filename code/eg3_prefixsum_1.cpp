#include <bits/stdc++.h>//蓝桥 k倍区间
#define mn 100002
long long sum,vis[mn],n,k,cnt,v;
signed main()
{
	scanf("%lld%lld",&n,&k); ++vis[0];
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&v);
		(cnt+=v)%=k;
		++vis[cnt];
	}//注意下面的循环，i<k不是i<n,vis[i]不是vis[cnt]
	for(int i=0;i<k;++i) sum+=vis[i]*(vis[i]-1)>>1;
	printf("%lld",sum);
	return 0;
}