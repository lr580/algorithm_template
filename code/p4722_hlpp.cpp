#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using std::min;
using std::vector;
using std::queue;
using std::priority_queue;
const int N=2e4+5,M=2e5+5,inf=0x3f3f3f3f;
int n,s,t,tot;
int v[M<<1],w[M<<1],first[N],next[M<<1];
int h[N],e[N],gap[N<<1],inq[N];//节点高度是可以到达2n-1的
struct cmp
{
	inline bool operator()(int a,int b) const
	{
		return h[a]<h[b];//因为在优先队列中的节点高度不会改变，所以可以直接比较
	}
};
queue<int> Q;
priority_queue<int,vector<int>,cmp> pQ;
inline void add_edge(int from,int to,int flow)
{
	tot+=2;
	v[tot+1]=from;v[tot]=to;w[tot]=flow;w[tot+1]=0;
	next[tot]=first[from];first[from]=tot;
	next[tot+1]=first[to];first[to]=tot+1;
	return;
}
inline bool bfs()
{
	int now;
	register int go;
	memset(h+1,0x3f,sizeof(int)*n);
	h[t]=0;Q.push(t);
	while(!Q.empty())
	{
		now=Q.front();Q.pop();
		for(go=first[now];go;go=next[go])
			if(w[go^1]&&h[v[go]]>h[now]+1)
				h[v[go]]=h[now]+1,Q.push(v[go]);
	}
	return h[s]!=inf;
}
inline void push(int now)//推送
{
	int d;
	register int go;
	for(go=first[now];go;go=next[go])
		if(w[go]&&h[v[go]]+1==h[now])
		{
			d=min(e[now],w[go]);
			w[go]-=d;w[go^1]+=d;e[now]-=d;e[v[go]]+=d;
			if(v[go]!=s&&v[go]!=t&&!inq[v[go]])
				pQ.push(v[go]),inq[v[go]]=1;
			if(!e[now])//已经推送完毕可以直接退出
				break;
		}
	return;
}
inline void relabel(int now)//重贴标签
{
	register int go;
	h[now]=inf;
	for(go=first[now];go;go=next[go])
		if(w[go]&&h[v[go]]+1<h[now])
			h[now]=h[v[go]]+1;
	return;
}
inline int hlpp()
{
	int now,d;
	register int i,go;
	if(!bfs())//s和t不连通
		return 0;
	h[s]=n;
	memset(gap,0,sizeof(int)*(n<<1));
	for(i=1;i<=n;i++)
		if(h[i]<inf)
			++gap[h[i]];
	for(go=first[s];go;go=next[go])
		if(d=w[go])
		{
			w[go]-=d;w[go^1]+=d;e[s]-=d;e[v[go]]+=d;
			if(v[go]!=s&&v[go]!=t&&!inq[v[go]])
				pQ.push(v[go]),inq[v[go]]=1;
		}
	while(!pQ.empty())
	{
		inq[now=pQ.top()]=0;pQ.pop();push(now);
		if(e[now])
		{
			if(!--gap[h[now]])//gap优化，因为当前节点是最高的所以修改的节点一定不在优先队列中，不必担心修改对优先队列会造成影响
				for(i=1;i<=n;i++)
					if(i!=s&&i!=t&&h[i]>h[now]&&h[i]<n+1)
						h[i]=n+1;
			relabel(now);++gap[h[now]];
			pQ.push(now);inq[now]=1;
		}
	}
	return e[t];
}
int m;
signed main()
{
	int u,v,w;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	while(m--)
	{
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
	}
	printf("%d\n",hlpp());
	return 0;
}