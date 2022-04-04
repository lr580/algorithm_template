#include <bits/stdc++.h>
using namespace std;
#define MAXN 2002
#define repe(i,a,b) for(int i=a;i<=b;++i)
int n,dp[MAXN][MAXN];
char x[MAXN],y[MAXN];
int edit(int a, int b)
{
    if(dp[a][b]!=-1) return dp[a][b];
    if(!a) return dp[a][b]=b;
    if(!b) return dp[a][b]=a;
    return dp[a][b]=min(min(edit(a-1,b)+1,edit(a,b-1)+1),edit(a-1,b-1)+(int)(x[a]!=y[b]));
}
signed main()
{
    scanf("%s%s",x+1,y+1);
    repe(i,0,2000) repe(j,0,2000) dp[i][j]=-1;
    printf("%d", edit(strlen(x+1),strlen(y+1)));
    return 0;
}