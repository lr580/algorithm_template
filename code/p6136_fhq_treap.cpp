#include<cstdio>
#define maxn 1100010
struct pair{
	int a,b;
	pair(int a_=0,int b_=0) { a=a_; b=b_; }
};
int read(){
    int ans=0; char ch=getchar();
    while(ch>'9'||ch<'0')ch=getchar();
    while(ch<='9'&&ch>='0'){
        ans=ans*10+ch-'0';
        ch=getchar();
    }
    return ans;
}
int key[maxn],wei[maxn],size[maxn],son[maxn][2];
int n,m,cnt,ans,seed=1,root,last;
int rand1() { return seed*=19260817; }
inline void pushup(int u)
	{ size[u]=size[son[u][0]]+size[son[u][1]]+1; }
pair split(int u,int k){
	if(!u) return pair(0,0);
	if(key[u]<k){
		pair t=split(son[u][1],k);
		son[u][1]=t.a;
		pushup(u);
		return pair(u,t.b);
	}else{
		pair t=split(son[u][0],k);
		son[u][0]=t.b;
		pushup(u);
		return pair(t.a,u);
	}
}
int merge(int u,int v){
	if(!u||!v) return u+v;
	if(wei[u]<wei[v]){
		son[u][1]=merge(son[u][1],v);
		pushup(u);
		return u;
	}else{
		son[v][0]=merge(u,son[v][0]);
		pushup(v);
		return v;
	}
}
void insert(int k){
	key[++cnt]=k; wei[cnt]=rand1(); size[cnt]=1;
	pair t=split(root,k);
	root=merge(merge(t.a,cnt),t.b);
}
void eraser(int k){
	pair x,y;
	x=split(root,k);
	y=split(x.b,k+1);
	y.a=merge(son[y.a][0],son[y.a][1]);
	root=merge(x.a,merge(y.a,y.b));
}
int find1(int k){
	int re;
	pair t=split(root,k);
	re=size[t.a]+1;
	root=merge(t.a,t.b);
	return re;
}
int find2(int k){
	int pos=root;
	while(pos){
		if(k==size[son[pos][0]]+1) return key[pos];
		if(k<=size[son[pos][0]]) pos=son[pos][0];
		else { k-=size[son[pos][0]]+1; pos=son[pos][1]; }
	}
}
int lst(int k) { return find2(find1(k)-1); }
int nxt(int k) { return find2(find1(k+1)); }
int main(){
	n=read(); m=read();
	for(int i=1;i<=n;i++){
		int a=read();
		insert(a);
	}
	for(int i=1;i<=m;i++){
		int o=read(),x; x=read();
		if(o==1) insert(x^last);
		if(o==2) eraser(x^last);
		if(o==3) { last=find1(x^last); ans^=last; }
		if(o==4) { last=find2(x^last); ans^=last; }
		if(o==5) { last=lst(x^last); ans^=last; }
		if(o==6) { last=nxt(x^last); ans^=last; }
	}
	printf("%d\n",ans);
	return 0;
}