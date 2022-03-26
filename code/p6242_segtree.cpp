#include<bits/stdc++.h>																																							请勿抄袭 
#define ll long long
using namespace std;
int n,m,op,l,r,k;
struct tree{
	ll sum;
	int add_a,add_a1,add_b,add_b1;
	int l,r,maxa,se,maxb,cnt;
}s[2000005];
char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<21],*o=obuf;
#define g()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
    int s=0,f=1;char c=g();
    for(;c<'0'||c>'9';c=g())
		if(c=='-')f=-1;
    for(;c>='0'&&c<='9';c=g())
		s=s*10+c-'0';
    return s*f;
}
inline void write(ll x)
{
    static char buf[16];
    static int len=-1;
    if(x<0)putchar('-'),x=-x;
    do buf[++len]=x%10,x/=10;while(x);
    while(len>=0)putchar(buf[len--]+'0');
    putchar('\n');
}
inline void push_up(int p)
{
	s[p].maxa=max(s[p*2].maxa,s[p*2+1].maxa);
	s[p].maxb=max(s[p*2].maxb,s[p*2+1].maxb);
	s[p].sum=s[p*2].sum+s[p*2+1].sum;
	if(s[p*2].maxa==s[p*2+1].maxa)
	{
		s[p].se=max(s[p*2].se,s[p*2+1].se);
		s[p].cnt=s[p*2].cnt+s[p*2+1].cnt;
	}
	if(s[p*2].maxa>s[p*2+1].maxa)
	{
		s[p].se=max(s[p*2].se,s[p*2+1].maxa);
		s[p].cnt=s[p*2].cnt;
	}
	if(s[p*2].maxa<s[p*2+1].maxa)
	{
		s[p].se=max(s[p*2].maxa,s[p*2+1].se);
		s[p].cnt=s[p*2+1].cnt;
	}
}
void build(int l,int r,int p)
{
	s[p].l=l,s[p].r=r;
	if(l==r)
	{
		s[p].sum=s[p].maxa=s[p].maxb=read();
		s[p].se=-1e9;
		s[p].cnt=1;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	push_up(p);
}
inline void update(int k1,int k2,int k3,int k4,int p)
{
	s[p].sum+=1ll*k1*s[p].cnt+1ll*k3*(s[p].r-s[p].l+1-s[p].cnt);
	s[p].maxb=max(s[p].maxb,s[p].maxa+k2);
	s[p].add_b=max(s[p].add_b,s[p].add_a+k2);
	s[p].add_b1=max(s[p].add_b1,s[p].add_a1+k4);
	s[p].maxa+=k1,s[p].add_a+=k1;
	s[p].add_a1+=k3;
	if(s[p].se!=-1e18)s[p].se+=k3;
}
inline void push_down(int p)
{
	int maxn=max(s[p*2].maxa,s[p*2+1].maxa);
	if(s[p*2].maxa==maxn)
	    update(s[p].add_a,s[p].add_b,s[p].add_a1,s[p].add_b1,p*2);
	else update(s[p].add_a1,s[p].add_b1,s[p].add_a1,s[p].add_b1,p*2);
	if(s[p*2+1].maxa==maxn)
		update(s[p].add_a,s[p].add_b,s[p].add_a1,s[p].add_b1,p*2+1);
	else update(s[p].add_a1,s[p].add_b1,s[p].add_a1,s[p].add_b1,p*2+1);
	s[p].add_a=s[p].add_b=s[p].add_a1=s[p].add_b1=0;
}
void update_add(int p)
{
	if(s[p].l>r||s[p].r<l)return;
	if(l<=s[p].l&&s[p].r<=r)
	    return update(k,k,k,k,p);
	push_down(p);
	update_add(p*2),update_add(p*2+1);
	push_up(p);
}
void update_min(int p)
{
	if(s[p].l>r||s[p].r<l||k>=s[p].maxa)return;
	if(l<=s[p].l&&s[p].r<=r&&k>s[p].se)
	    return update(k-s[p].maxa,k-s[p].maxa,0,0,p);
	push_down(p);
	update_min(p*2),update_min(p*2+1);
	push_up(p);
}
ll query_add(int p)
{
	if(s[p].l>r||s[p].r<l)return 0;
	if(l<=s[p].l&&s[p].r<=r)return s[p].sum;
	push_down(p);
	return query_add(p*2)+query_add(p*2+1);
}
int query_maxa(int p)
{
	if(s[p].l>r||s[p].r<l)return -1e9;
	if(l<=s[p].l&&s[p].r<=r)return s[p].maxa;
	push_down(p);
	return max(query_maxa(p*2),query_maxa(p*2+1));
}
int query_maxb(int p)
{
	if(s[p].l>r||s[p].r<l)return -1e9;
	if(l<=s[p].l&&s[p].r<=r)return s[p].maxb;
	push_down(p);
	return max(query_maxb(p*2),query_maxb(p*2+1));
}
int main()
{
	n=read(),m=read();
	build(1,n,1);
	while(m--)
	{
		op=read(),l=read(),r=read();
		if(op==1)k=read(),update_add(1);
		if(op==2)k=read(),update_min(1);
		if(op==3)write(query_add(1));
		if(op==4)write(query_maxa(1));
		if(op==5)write(query_maxb(1));
	}
	return 0;
}