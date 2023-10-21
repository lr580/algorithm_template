// #pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define N 524293
#define p 998244353
using ll = long long;
#define add(x,y) (x+y>=p?x+y-p:x+y)
#define dec(x,y) (x<y?x-y+p:x-y)
using namespace std;

inline int power(int a,int t){
    int res = 1;
    while(t){
        if(t&1) res = (ll)res*a%p;
        a = (ll)a*a%p;
        t >>= 1;
    }
    return res;
}

struct poly{
    int a[N];
    int t;
    inline int operator [] (const int& x) const{ return a[x]; }
    inline int& operator [] (const int& x){ return a[x]; }
};

int rev[N],rt[N],inv[N],fac[N],ifac[N],pw[N],pr[N>>1];
int siz;

void init(int n){
    int w,lim = 1;
    while(lim<=n) lim <<= 1,++siz;
    for(int i=1;i!=lim;++i) rev[i] = (rev[i>>1]>>1)|((i&1)<<(siz-1));
    inv[1] = rt[lim>>1] = 1;
    w = power(3,(p-1)>>siz);
    for(int i=(lim>>1)+1;i!=lim;++i) rt[i] = (ll)rt[i-1]*w%p;
    for(int i=(lim>>1)-1;i;--i) rt[i] = rt[i<<1];
    for(int i=2;i<=lim;++i) inv[i] = (ll)(p-p/i)*inv[p%i]%p;
}

inline int getlen(int n){
	return 1<<(32-__builtin_clz(n));
}

inline void NTT(poly &f,int type,int lim){
    if(type==1) reverse(f.a+1,f.a+lim);
    static unsigned long long a[N];
    int x,shift = siz-__builtin_ctz(lim);
    for(int i=0;i!=lim;++i) a[rev[i]>>shift] = f[i];
    for(int mid=1;mid!=lim;mid<<=1)
    for(int j=0;j!=lim;j+=(mid<<1))
    for(int k=0;k!=mid;++k){
        x = a[j|k|mid]*rt[mid|k]%p;
        a[j|k|mid] = a[j|k]-x+p;
        a[j|k] += x;
    }
    for(int i=0;i!=lim;++i) f[i] = a[i]%p;
    if(type==1) return;
    x = inv[lim];
    for(int i=0;i!=lim;++i) f[i] = (ll)f[i]*x%p;
}

poly inverse(poly f){
	poly g,h,q;
	memset(g.a,0,sizeof(g.a));
	int lim = 1,n = f.t,top = 0;
	int s[30];
	while(n){
		s[++top] = n;
		n >>= 1;
	}
	g[0] = power(f[0],p-2);
	while(top--){
		g.t = n = s[top+1];
		while(lim<=(n<<1)) lim <<= 1;
		memcpy(h.a,f.a,(n+1)<<2);
		memcpy(q.a,g.a,(n+1)<<2);
		memset(h.a+n+1,0,(lim-n)<<2);
		NTT(g,1,lim),NTT(h,1,lim);
		for(int i=0;i!=lim;++i) g[i] = (ll)g[i]*g[i]%p*h[i]%p;
		NTT(g,-1,lim);
		for(int i=0;i<=n;++i) g[i] = dec(add(q[i],q[i]),g[i]);
		memset(g.a+n+1,0,(lim-n)<<2);
	}
	return g;
} 

inline poly deriv(poly f){ //多项式求导
	for(int i=0;i!=f.t;++i) f[i] = (ll)f[i+1]*(i+1)%p;
	f[f.t] = 0;
	return f;
}

inline poly integ(poly f){ //多项式积分
	for(int i=f.t;i;--i) f[i] = (ll)f[i-1]*inv[i]%p;
	f[0] = 0;
	return f;
}

inline poly log(poly f){
	poly g = inverse(f);
	f = deriv(f);
	int lim = getlen(f.t<<1);
	NTT(f,1,lim),NTT(g,1,lim);
	for(int i=0;i!=lim;++i) f[i] = (ll)f[i]*g[i]%p;
	NTT(f,-1,lim);
	memset(f.a+f.t+1,0,(lim-f.t)<<2);
	return integ(f);
}

poly exp(poly f){
	poly g,h;
	memset(g.a,0,sizeof(g.a));
	int n = f.t,lim = 1,top = 0;
	int s[30];
	while(n){
		s[++top] = n;
		n >>= 1;
	}
	g[0] = 1;
	while(top--){
		g.t = n = s[top+1];
		while(lim<=(n<<1)) lim <<= 1;
		memcpy(h.a,g.a,(n+1)<<2);
		memset(h.a+n+1,0,(lim-n)<<2);
		g = log(g);
		for(int i=0;i<=n;++i) g[i] = dec(f[i],g[i]);
		g[0] = add(g[0],1);
		NTT(g,1,lim),NTT(h,1,lim);
		for(int i=0;i!=lim;++i) g[i] = (ll)g[i]*h[i]%p;
		NTT(g,-1,lim);
		memset(g.a+n+1,0,(lim-n)<<2);
	}
	return g;
}

inline int C(int n,int m){
    if(n<m) return 0;
    return (ll)fac[n]*ifac[m]%p*ifac[n-m]%p;
}

inline int A(int n,int m){
    if(n<m) return 0;
    return (ll)fac[n]*ifac[n-m]%p;
}

void sieve(int lim,int k){
    int cnt = 0;
    pw[1] = 1; //利用积性函数求 pw[i]=i^k
    for(int i=2;i<=lim;++i){
        if(!pw[i]){
            pr[++cnt] = i; //欧拉筛
            pw[i] = power(i,k);
        }
        for(int j=1;j<=cnt&&i*pr[j]<=lim;++j){
            pw[i*pr[j]] = (ll)pw[i]*pw[pr[j]]%p;
            if(i%pr[j]==0) break;
        }
    }
}

int n,m,lim,sum;
poly F,G;

int main(){
    scanf("%d%d",&n,&m);
    lim = max(n,m);
    sieve(lim,n);
    printf("%d\n",pw[m]); // I1
    init(lim<<1);
    fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
    for(int i=2;i<=n+m;++i) ifac[i] = fac[i] = (ll)fac[i-1]*i%p;
    ifac[n+m] = power(fac[n+m],p-2);
    for(int i=n+m-1;i;--i) ifac[i] = (ll)ifac[i+1]*(i+1)%p;
    printf("%d\n",A(m,n)); // II2
    for(int i=0;i<=n;++i){
        F[i] = (ll)pw[i]*ifac[i]%p;
        G[i] = (i&1)?p-ifac[i]:ifac[i];
    }
    lim = getlen(n<<1);
    NTT(F,1,lim),NTT(G,1,lim);
    for(int i=0;i!=lim;++i) F[i] = (ll)F[i]*G[i]%p;
    NTT(F,-1,lim);
    memset(F.a+n+1,0,(lim-n+2)<<2);
    printf("%lld\n",(ll)fac[m]*F[m]%p); // III3
    for(int i=1;i<=m;++i) sum = add(sum,F[i]);
    printf("%d\n",sum); // IV4
    printf("%d\n",n<=m); // V5
    printf("%d\n",F[m]);  // VI6
    printf("%d\n",C(n+m-1,n)); // VII7
    printf("%d\n",C(m,n)); // VIII8
    printf("%d\n",C(n-1,m-1)); // IX9
	F.t = n;
	memset(F.a,0,sizeof(F.a));
	for(int i=1;i<=m;++i){
		for(int j=i;j<=n;j+=i)
			F[j] = add(F[j],inv[j/i]);
	}
	F = exp(F);
	printf("%d\n",F[n]); // X10
	printf("%d\n",n<=m); // XI11
	printf("%d\n",n<m?0:F[n-m]); // XII12
	return 0;	
}