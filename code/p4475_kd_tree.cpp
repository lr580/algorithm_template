#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=5e5+50;
int n,now,m,rt;
ll a,b,c;
struct data
{
	int d[2],mx[2],mn[2],lc,rc,val;
	ll sum;
	friend bool operator < (data a,data b)
		{return a.d[now]<b.d[now];}
}dat[N],t[N];
void getmax(int&a,int b){if(a<b)a=b;}
void getmin(int&a,int b){if(a>b)a=b;}
void pushup(int x)
{
	int lc=t[x].lc,rc=t[x].rc;
	for(int i=0;i<2;i++)
	{
		t[x].mn[i]=t[x].mx[i]=t[x].d[i];
		if(lc)  getmin(t[x].mn[i],t[lc].mn[i]),
			getmax(t[x].mx[i],t[lc].mx[i]);
		if(rc)  getmin(t[x].mn[i],t[rc].mn[i]),
			getmax(t[x].mx[i],t[rc].mx[i]);
	}
	t[x].sum=t[lc].sum+t[rc].sum+t[x].val;
}

int build(int l,int r,int pl)
{
	now=pl; int mid=(l+r)>>1;
	nth_element(dat+l,dat+mid,dat+r+1);
	t[mid]=dat[mid];
	if(l<mid) t[mid].lc=build(l,mid-1,!pl);
	if(r>mid) t[mid].rc=build(mid+1,r,!pl);
	pushup(mid); return mid;
}
bool check(ll x,ll y) {return x*a+y*b<c;}
ll query(int x)
{
	int tot=0;
	tot+=check(t[x].mx[0],t[x].mx[1]);
	tot+=check(t[x].mn[0],t[x].mx[1]);
	tot+=check(t[x].mx[0],t[x].mn[1]);
	tot+=check(t[x].mn[0],t[x].mn[1]);
	if(tot==4) return t[x].sum; // 都满足
	if(tot==0) return 0; // 都不满足
	ll res=0;
	if(check(t[x].d[0],t[x].d[1])) res+=t[x].val;
	if(t[x].lc) res+=query(t[x].lc);
	if(t[x].rc) res+=query(t[x].rc);
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
		scanf("%d%d%d",&dat[i].d[0],&dat[i].d[1],&dat[i].val);
	rt=build(1,n,0); while(m--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		printf("%lld\n",query(rt));
	}
	return 0;
}