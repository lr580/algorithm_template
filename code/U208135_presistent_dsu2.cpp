#include<stdio.h>
const int N=1e5+5;
int L[N<<6],R[N<<6],rt[N<<6],fa[N<<6],sz[N<<6],cnt;
#define mid (l+r>>1)
#define ls L[k],l,mid
#define rs R[k],mid+1,r
int n,m;
void swap(int &x,int &y){
	int z=x;x=y;y=z;
}
void build(int &k,int l,int r){
	k=++cnt;
	if(l==r)return fa[k]=l,sz[k]=1,void();
	build(ls),build(rs);
}
void modify(int &k,int l,int r,int x,int y,int z){
	++cnt;L[cnt]=L[k],R[cnt]=R[k],fa[cnt]=fa[k],sz[cnt]=sz[k];k=cnt;
	if(l==r)return fa[k]=y,sz[k]=z,void();
	if(x<=mid)modify(ls,x,y,z);
	else modify(rs,x,y,z);
}
int query(int k,int l,int r,int x){
	if(l==r)return k;
	if(x<=mid)return query(ls,x);
	else return query(rs,x);
}
int find(int k,int x){
	int F=query(k,1,n,x);
	if(fa[F]==x)return F;
	return find(k,fa[F]);
}
int main(){
	scanf("%d%d",&n,&m);
	build(rt[0],1,n);
	for(int i=1,opt,x,y;i<=m;i++){
		scanf("%d%d",&opt,&x);rt[i]=rt[i-1];
		if(opt!=2)scanf("%d",&y);
		if(opt==1){
			int fx=find(rt[i],x),fy=find(rt[i],y);
			if(fa[fx]!=fa[fy]){
				if(sz[fx]>sz[fy])swap(fx,fy);
				modify(rt[i],1,n,fa[fx],fa[fy],sz[fx]);
				modify(rt[i],1,n,fa[fy],fa[fy],sz[fx]+sz[fy]);
			}
		}
		else if(opt==2)rt[i]=rt[x];
		else{
			int fx=find(rt[i],x),fy=find(rt[i],y);
			printf("%d\n",fa[fx]==fa[fy]);
		}
	}
	return 0;
}