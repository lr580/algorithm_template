#include <bits/stdc++.h>//https://oj.socoding.cn/p/1433
using namespace std;
typedef long long ll;
#define mn 2000002
#define nemp hd<=ed
ll q[mn],hd,ed=-1,s[mn],p[mn],d[mn],n,n2;
bool ok[mn];
signed main()
{
    scanf("%lld",&n); n2=n<<1;
    for(ll i=1;i<=n;++i) scanf("%lld%lld",p+i,d+i),s[i]=s[i+n]=p[i]-d[i];
    for(ll i=1;i<=n2;++i) s[i]+=s[i-1];
    for(ll i=n2;i;--i)
    {
        while(nemp&&q[hd]-i>=n) ++hd;
        while(nemp&&s[q[ed]]>=s[i]) --ed;
        q[++ed]=i;
        if(i<=n&&s[q[hd]]-s[i-1]>=0) ok[i]=true;
    } hd=0,ed=-1;  d[0]=d[n];
    for(ll i=1;i<=n;++i) s[i]=s[i+n]=p[i]-d[i-1];
    for(ll i=1;i<=n2;++i) s[i]+=s[i-1];
    for(ll i=1;i<=n2;++i)
    {
        while(nemp&&i-q[hd]>=n) ++hd;
        if(i>n&&s[i]-s[q[hd]]>=0) ok[i-n]=true;
        while(nemp&&s[q[ed]]<=s[i]) --ed;
        q[++ed]=i;
    }
    for(ll i=1;i<=n;++i) printf(ok[i]?"YES\n":"NO\n");
    return 0;
}