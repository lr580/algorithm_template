#include <bits/stdc++.h>
#define mn 100002
typedef long long ll;
struct pupil
{
	ll v,m;
} a[mn],b[mn];
ll ans,n;
void merges(ll lf, ll rf)
{
	if(lf==rf) return;
	ll cf=lf+rf>>1;
	merges(lf,cf);
	merges(cf+1,rf);
	ll p=lf,q=cf+1,t=lf;
	while(p<=cf&&q<=rf)
	{
		if(a[p].v>a[q].v) a[q].m+=cf+1-p,b[t++]=a[q++];
		else a[p].m+=q-1-cf,b[t++]=a[p++];
	}
	while(q<=rf) b[t++]=a[q++];//+=写成=暴死
	while(p<=cf) a[p].m+=q-1-cf,b[t++]=a[p++];
	for(int i=lf;i<=rf;++i) a[i]=b[i];
}
signed main()
{
	scanf("%lld",&n);
	for(int i=0;i<n;++i) scanf("%lld",&a[i].v);
	merges(0,n-1);
	for(int i=0;i<n;++i) ans+=(a[i].m+1)*a[i].m>>1;
	printf("%lld",ans);
	return 0;
}