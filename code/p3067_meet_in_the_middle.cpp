#include <bits/stdc++.h>
using namespace std;
#define mn (1<<20)+5
int n,half,mc,ans,a[21];
bool memo[mn];
vector<int> d[mn];//有多少种nowstate可以拼出情况mc(mc即nowsum)
map<int,int> m;//m[v]->mc 求和值与情况mc一一对应
void dfs1(int i, int nowsum, int nowstate)
{
    if(i==half)
    {
        if(!m.count(nowsum)) m[nowsum]=++mc;//和为nowsum时对应一个独一无二的mc
        d[m[nowsum]].push_back(nowstate);
        return;
    }
    dfs1(i+1,nowsum,nowstate); //两边都不选
    dfs1(i+1,nowsum+a[i],nowstate|(1<<i)); //左边选了
    dfs1(i+1,nowsum-a[i],nowstate|(1<<i)); //右边选了
}
void dfs2(int i, int nowsum, int nowstate)//这次+ -的意义跟上次相反
{
    if(i==n)
    {
        if(m.count(nowsum))//如果可以拼出nowsum
        {
            int x=m[nowsum];
            for(int i=0,ds=d[x].size();i<ds;++i) memo[d[x][i]|nowstate]=true;//起到了去重
        }
        return;
    }
    dfs2(i+1,nowsum,nowstate);
    dfs2(i+1,nowsum+a[i],nowstate|(1<<i));//位运算(状态压缩)里i从0开始
    dfs2(i+1,nowsum-a[i],nowstate|(1<<i));
}
signed main()
{
    scanf("%d",&n);
    half=n>>1;
    for(int i=0;i<n;++i) scanf("%d",a+i);
    dfs1(0,0,0);
    dfs2(half,0,0);
    for(int i=1,n2=1<<n;i<=n2;++i) ans+=memo[i];
    return printf("%d",ans),0;
}
