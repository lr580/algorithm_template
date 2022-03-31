#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int qq=110;
const int MAX=1e8+5;
int n,m;
int vis[qq];
int dis[qq];
int map[qq][qq];
int maxn[qq][qq];	//记录最小生成树中点i到点j的最大距离、 
int use[qq][qq];	//记录每一条边是否被使用过、 
int pre[qq];
int Prim()
{
	memset(vis,0,sizeof(vis));
	memset(use,0,sizeof(use));
	memset(maxn,0,sizeof(maxn)); 
	for(int i=1; i<=n; ++i)	dis[i]=map[1][i],pre[i]=1;
	vis[1]=1;
	dis[1]=0;
	pre[1]=-1; 
	int ans=0,minx,k;
	for(int i=1; i<n; ++i){
		minx=MAX;
		for(int j=1; j<=n; ++j)
			if(!vis[j] && dis[j]<minx)
				minx=dis[k=j];
		if(minx==MAX)	return -1; 
		ans+=minx;
		use[k][pre[k]]=use[pre[k]][k]=1;
		vis[k]=1;
		for(int j=1; j<=n; ++j){
			if(vis[j])	maxn[j][k]=maxn[k][j]=max(dis[k],maxn[j][pre[k]]);
			if(!vis[j] && map[k][j]<dis[j])
				pre[j]=k,dis[j]=map[k][j];
		}
	}
	return ans;
}
int main()
{
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		int u,v,w;
		for(int i=0; i<=n; ++i)
			for(int j=0; j<=n; ++j)	
				if(i!=j)	map[i][j]=MAX;
				else map[i][j]=0; 
		for(int i=0; i<m; ++i){
			scanf("%d%d%d",&u,&v,&w);
			map[u][v]=map[v][u]=w;
		}
		int ans=Prim();
		if(ans==-1){
			printf("Not Unique!\n");
            continue;
		}
		int Min=MAX;
		for(int j,i=1; i<=n; ++i)
			for(j=i+1; j<=n; ++j)
				if(!use[i][j] && map[i][j]!=MAX)
					Min=min(Min,ans-maxn[i][j]+map[i][j]);
		if(Min==ans)	printf("Not Unique!\n");
		else	printf("%d\n",ans);
	}
	return 0;
}