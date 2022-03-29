#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define mn (1<<21)+5
ll n,m,x[62],ac,bc,as[mn],bs[mn],cf,ans;
void dfs(ll lf, ll& rf, ll v, ll& cnt, ll* arr)
{
    if(v>m) return;
    if(lf==rf){arr[cnt++]=v; return;}
    dfs(lf+1,rf,v+x[lf],cnt,arr);
    dfs(lf+1,rf,v,cnt,arr);
}
signed main()
{
    scanf("%lld%lld",&n,&m); cf=n>>1;
    for(int i=0;i<n;++i) scanf("%lld",x+i);
    dfs(0,cf,0,ac,as);
    dfs(cf,n,0,bc,bs);
    sort(bs,bs+bc);
    for(int i=0;i<ac;++i)
        ans+=upper_bound(bs,bs+bc,m-as[i])-bs;
    return printf("%lld",ans),0;
}