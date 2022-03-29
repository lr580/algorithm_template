#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long lt;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
char ss[15];
int ans[4][4]=
{{0,0,0,0},
 {0,1,2,3},
 {0,8,0,4},
 {0,7,6,5}};
int a[5][5],k,judge;
int nxtx[]={0,1,-1,0};//特殊构造
int nxty[]={1,0,0,-1};//pre+i==3时两两互逆，即pre和i互为相反步
int check()
{
    for(int i=1;i<=3;++i)
    for(int j=1;j<=3;++j)
    if(ans[i][j]!=a[i][j])return 0;
    return 1;
}
int test(int step)//预测还要走多少步，启发假设有一个不等就走多一步
{
    int cnt=0;
    for(int i=1;i<=3;++i)
    for(int j=1;j<=3;++j)
    if(ans[i][j]!=a[i][j]){ if(++cnt+step>k) return 0;}
    return 1;
}
void A_star(int step,int x,int y,int pre)//pre防止下一次走回上一步
{
    if(step==k){ if(check())judge=1; return;}//达到当前限制的最大深度
    if(judge) return;
    for(int i=0;i<4;++i)
    {
        int nx=x+nxtx[i],ny=y+nxty[i];
        if(nx<1||nx>3||ny<1||ny>3||pre+i==3) continue;//加入了上述最优性剪枝
        swap(a[x][y],a[nx][ny]);
        if(test(step)&&!judge) A_star(step+1,nx,ny,i);//A*估价合法再向下搜索
        swap(a[x][y],a[nx][ny]);
    }
}
int main()
{
    int x,y;
    scanf("%s",&ss);
    for(int i=0;i<9;++i)
    {
        a[i/3+1][i%3+1]=ss[i]-'0';
        if(ss[i]-'0'==0)x=i/3+1,y=i%3+1;
    }
    if(check()){printf("0");return 0;}//特判不用移动
    while(++k)//枚举最大深度
    {
        A_star(0,x,y,-1);
        if(judge){printf("%d",k);break;}
    }
    return 0;
}