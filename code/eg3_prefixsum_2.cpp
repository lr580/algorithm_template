#include <bits/stdc++.h>
#define mn 100002
int vis[mn],n,k,cnt,v;
long long sum;
signed main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&v);
		(cnt+=v)%=k;
		sum+=vis[cnt]++;
	}
	printf("%lld",sum+vis[0]);
	return 0;
}