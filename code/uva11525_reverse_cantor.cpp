#include<iostream>
#include<cstdio>
#define N (500000+21)
//define一定一定要记得加括号
using namespace std;
struct SegmentTree{int l,r,cnt;}t[N*4];//线段树数组要开四倍
int T,n,x;
//下面是线段树模板，基本和区间加差不多，就是注意查询操作类似于平衡树找第k名
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].cnt=1;
		return;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p].cnt=t[p*2].cnt+t[p*2+1].cnt;
}
int modify(int p,int v){
	if(t[p].l==t[p].r){
		t[p].cnt=0;//这里随着查询也改变了数值
		return t[p].l;
	}
	int res=0;
	if(v<=t[p*2].cnt) res=modify(p*2,v);
	else res=modify(p*2+1,v-t[p*2].cnt);
	t[p].cnt=t[p*2].cnt+t[p*2+1].cnt;
	return res;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		build(1,1,n);
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			printf("%d",modify(1,x+1));//因为从0开始所以要把x加1
			if(i!=n) printf(" ");
		}
		printf("\n");
	}
	return 0;
}