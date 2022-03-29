#include <bits/stdc++.h>//蓝桥-最大子阵
using namespace std;
#define mn 502
int s[mn][mn],n,m,mx=-0x7ffffffa,v;
signed main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) 
		scanf("%d",&v),s[i][j]=s[i-1][j]+v;//当前行前缀和 
	for(int i=1;i<=n;++i) for(int j=1;j<=i;++j) //矩阵右下角为(i,j) 
		for(int k=1,v=0;k<=m;++k) //使用O(m)计算二维前缀和 
		{
			v+=s[i][k]-s[j-1][k];//当前矩阵前缀和 
			mx=max(mx,v);
			v=max(v,0); //负数特判 
		}
	printf("%d",mx);
	return 0;
} 