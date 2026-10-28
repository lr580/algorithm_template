#include<cstdio>
#include<algorithm>
using namespace std;const int N=3*1e6+10;typedef long long ll;
char mde[N];int nl;ll res;
struct suffixautomation
{
    int mp[N][30];int fa[N];int ed;int ct;int len[N];int siz[N];
    suffixautomation(){ed=ct=1;}
    int v[N];int x[N];int al[N];int cnt;
    inline void add(int u,int V){v[++cnt]=V;x[cnt]=al[u];al[u]=cnt;}
    inline void ins(int c) 
    {
        int p=ed;siz[ed=++ct]=1;len[ed]=nl;//先初始化size和len 
        for(;p&&mp[p][c]==0;p=fa[p]){mp[p][c]=ed;}//然后顺着parent树的路径向上找 
        if(p==0){fa[ed]=1;return;}int q=mp[p][c];//case1 
        if(len[p]+1==len[q]){fa[ed]=q;return;}//case2
        len[++ct]=len[p]+1;//case 3
        for(int i=1;i<=26;i++){mp[ct][i]=mp[q][i];}
        fa[ct]=fa[q];fa[q]=ct;fa[ed]=ct;
        for(int i=p;mp[i][c]==q;i=fa[i]){mp[i][c]=ct;}
    }
    inline void bt(){for(int i=2;i<=ct;i++){add(fa[i],i);}}//暴力建树 
    void dfs(int u)//dfs 
    {
        for(int i=al[u];i;i=x[i]){dfs(v[i]);siz[u]+=siz[v[i]];}
        if(siz[u]!=1){res=max(res,(ll)siz[u]*len[u]);}
    }
}sam;
int main()
{
    scanf("%s",mde+1);
    for(nl=1;mde[nl]!='\0';nl++){sam.ins(mde[nl]-'a'+1);}
    sam.bt();sam.dfs(1);printf("%lld",res);return 0;
}
