#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int inf=1e9;
int n,m,w[2000000],lg2[1500000];
int pos[1500000],lst[1500000],dep[1500000],id,mm,S,ch[1500000][2],stack[1500000];
struct LIM_RMQ
{
	int w[1500000],bl[1500000],blo,L[150000],R[150000],pos[10000],val[150000],minn[150000],minpos[150000],t[1000],n_st;
	struct ST_node{int f,id;bool operator <(const ST_node &tmp)const{return f<tmp.f;}};
	struct STable
	{
		ST_node a[4][12];//n=1e6的话logn/2只有9...所以放心开
		void make(int w[],int n)
		{
			for(int i=1;i<=n;i++)a[0][i]=(ST_node){w[i],i};
			for(int i=1;(1<<i)<=n;i++)//st表，不过要同时处理出最小值所在的位置
				for(int j=1;j+(1<<i)-1<=n;j++)
					a[i][j]=min(a[i-1][j],a[i-1][j+(1<<(i-1))]);
		}
		ST_node query(int l,int r)
		{
			int len=lg2[r-l+1];
			return min(a[len][l],a[len][r-(1<<len)+1]);
		}
	}st[10000];//这里只有sqrt(n)个，也不用开这么大
	struct STable_block
	{
		ST_node a[20][150000];//这个占空间最大了吧...不过也只是O(n)的
		void make(int w[],int n)
		{
			for(int i=1;i<=n;i++)a[0][i]=(ST_node){w[i],i};
			for(int i=1;(1<<i)<=n;i++)
				for(int j=1;j+(1<<i)-1<=n;j++)
					a[i][j]=min(a[i-1][j],a[i-1][j+(1<<(i-1))]);
		}
		ST_node query(int l,int r)
		{
			int len=lg2[r-l+1];//细节，math库的log2函数不能看做O(1)的，要提前处理
			return min(a[len][l],a[len][r-(1<<len)+1]);
		}
	}st_block;
	void make(int a[],int n)
	{
		for(int i=1;i<=n;i++)w[i]=a[i];
		lg2[1]=0;for(int i=2;i<=n;i++)lg2[i]=lg2[i>>1]+1;//处理log2
		blo=max(lg2[n]>>1,1);//分块
		for(int i=1;i<=n;i++)bl[i]=(i-1)/blo+1;
		for(int i=1;i<=bl[n];i++)L[i]=(i-1)*blo+1,R[i]=min(i*blo,n),minn[i]=inf;
		w[0]=w[1]-1;
		for(int i=1;i<=bl[n];i++)
		{
			int tmp=0,nn=0;
			for(int j=L[i];j<=R[i];j++)
			{
				t[++nn]=w[j],tmp=tmp<<1|(w[j]-w[j-1]==1?1:0);
				if(w[j]<minn[i])minn[i]=w[j],minpos[i]=j;
                //可以用一个状压来表示本质
			}
			if(!pos[tmp])st[pos[tmp]=++n_st].make(t,nn);
			val[i]=pos[tmp];//记下每个块属于哪一个本质
		}
		st_block.make(minn,bl[n]);//块间rmq
	}
	ST_node query_block(int id,int l,int r){ST_node t=st[val[id]].query(l-L[id]+1,r-L[id]+1);return (ST_node){t.f,t.id+L[id]-1};}
    //实际位置=块左端点+块内查询位置-1，如果你把块内查询从0开始写就可以省略-1
	int query(int l,int r)
	{
		int bll=bl[l],blr=bl[r];
		if(bll==blr)return query_block(bll,l,r).id;//一个块
		int ml=query_block(bll,l,R[bll]).id,mr=query_block(blr,L[blr],r).id,mm;
		if(w[ml]<w[mr])mm=ml;else mm=mr;//两端零散块
		if(bll+1<=blr-1)//整块
		{
			int mmid=minpos[st_block.query(bll+1,blr-1).id];
			if(w[mmid]<w[mm])mm=mmid;
		}
		return mm;
	}
}a;
void dfs(int u,int depth)
{
	lst[u]=++id,pos[id]=u;dep[id]=depth;//处理欧拉序列
	for(int i=0;i<=1;i++)
		if(ch[u][i])
		{
			dfs(ch[u][i],depth+1);
			pos[++id]=u,dep[id]=depth;
		}
}
int getin()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
	return x;
}
int wt[30];
void putout(int x)
{
	if(!x){putchar('0');return;}
	int l=0;
	while(x)wt[++l]=x%10,x/=10;
	while(l)putchar(wt[l--]+48);
	puts("");
}
void build_tree()//笛卡尔树
{
	int top=1;stack[1]=S=1;//开始根为1
	for(int i=2;i<=n;i++)
	{
		int lst=0;
		while(top&&w[i]>w[stack[top]])lst=stack[top--];
		if(lst)ch[i][0]=lst;
		if(top)ch[stack[top]][1]=i;else S=i;
		stack[++top]=i;
	}
	dfs(S,1);
}
int main()
{
	n=getin(),m=getin();
	for(int i=1;i<=n;i++)w[i]=getin();
	build_tree();
	a.make(dep,id);
	for(int i=1;i<=m;i++)
	{
		int l=lst[getin()],r=lst[getin()];
		if(l>r)swap(l,r);//可能第一次出现的位置是反过来的
		putout(w[pos[a.query(l,r)]]);
	}
} 