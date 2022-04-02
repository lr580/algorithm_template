#include<bits/stdc++.h>
#define N 216000
#define ll long long
using namespace std;
int mn[N],pri[N/10],fl[N];
int tot,cnt,num,n;
int f[20005][55];
int inf=2e9;
int dp(int x,int y){
    if (x<=20000&&y<=50) return f[x][y];
    if (x==0||y==0) return x;
    if (1ll*pri[y]*pri[y]>=x&&x<N) return max(0,mn[x]-y);
    return dp(x,y-1)-dp(x/pri[y],y-1);
}
void pre(){
    for (int i=2;i<N;i++){
        if (!fl[i]) pri[++tot]=i;
        for (int j=1;i*pri[j]<N&&j<=tot;j++){
            fl[i*pri[j]]=1;
            if (i%pri[j]==0) break;
        }
    }
    for (int i=1;i<N;i++)
        mn[i]=(cnt+=1-fl[i]);
    for (int i=1;i<=20000;i++) f[i][0]=i;
    for (int i=1;i<=20000;i++)
        for (int j=1;j<=50;j++)
            f[i][j]=f[i][j-1]-f[i/pri[j]][j-1];
}
int power(int x,int y){
    int s=1;
    while (y!=0){
        if (y&1){
            if (s>=inf/x) s=inf;
            else s=s*x;
        }
        y/=2;
        if (x>=inf/x) x=inf;
        else x=x*x;
    }
    return s;
}
int yroot(ll x,int y){
    int l=2,r=6666,ans=1;
    while (l<=r){
        int mid=(l+r)/2;
        if (power(mid,y)<=x) ans=mid,l=mid+1;
        else r=mid-1;
    }
    return ans;
}
int work(int m){
    if (m<N) return mn[m]-1;
    int y=yroot(m,3),n=mn[y];
    int ans=dp(m,n)+n-1;
    for (n++;pri[n]*pri[n]<=m;n++)
        ans-=mn[m/pri[n]]-mn[pri[n]]+1;
    return ans;
}
int main(){
    pre();
    scanf("%d",&n);
    int an=work(n);
    printf("%d\n",an);
    for(int i=1;i<=an;++i) printf("%d ",pri[i]);
}