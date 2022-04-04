#include <bits/stdc++.h>
#define mn 10002
using namespace std;
typedef long long ll;
ll n,ax,ay,bx,by,xs[mn],m,bf,ans;
struct scline
{
    ll y,ax,bx,c;
    bool inline operator < (const scline& b) const
    {
        if(y==b.y) return c>b.c;
        return y<b.y;
    }
} sc[mn];
struct segtr
{
    ll c,s,l,r,len;
    bool lc,rc;
} t[mn<<2];
#define lfi (i<<1)
#define rfi (i<<1|1)
void init(ll i, ll lf, ll rf)
{
    t[i].l=lf,t[i].r=rf;
    if(lf!=rf)
    {
        ll cf=lf+rf>>1;
        init(lfi,lf,cf);
        init(rfi,cf+1,rf);
    }
}
void pushup(ll i)
{
    ll l=t[i].l,r=t[i].r;
    if(t[i].s)
    {
        t[i].len=xs[r+1]-xs[l];
        t[i].lc=t[i].rc=true;
        t[i].c=1;
        return;
    }
    t[i].len=t[lfi].len+t[rfi].len;
    t[i].lc=t[lfi].lc,t[i].rc=t[rfi].rc;
    t[i].c=t[lfi].c+t[rfi].c;
    if(t[lfi].rc&&t[rfi].lc) t[i].c--;
}
void add(ll i, ll lf, ll rf, ll ci)
{
    ll lt=xs[t[i].l],rt=xs[t[i].r+1];
    if(lt>=rf||rt<=lf) return;
    if(lt>=lf&&rt<=rf)
    {
        t[i].s+=ci;
        pushup(i);
        return;
    }
    add(lfi,lf,rf,ci);
    add(rfi,lf,rf,ci);
    pushup(i);
}
signed main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;++i)
    {
        scanf("%lld%lld%lld%lld",&ax,&ay,&bx,&by);
        sc[i]={ay,ax,bx,1};
        sc[i+n]={by,ax,bx,-1};
        xs[i]=ax;
        xs[i+n]=bx;
    }
    n<<=1;
    sort(sc+1,sc+1+n);
    sort(xs+1,xs+1+n);
    m=unique(xs+1,xs+1+n)-xs-1;
    init(1,1,m-1);
    for(ll i=1;i<n;++i)
    {
        add(1,sc[i].ax,sc[i].bx,sc[i].c);
        ans+=abs(bf-t[1].len); bf=t[1].len;
        ans+=2*t[1].c*(sc[i+1].y-sc[i].y);
    }
    printf("%lld",ans+sc[n].bx-sc[n].ax);
    return 0;
}