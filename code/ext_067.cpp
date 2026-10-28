#include <bits/stdc++.h>
#define MAXN 100002
#define y1 dy
using namespace std;
int n,a[MAXN],uf[MAXN],df[MAXN],ufl,dfl,x[MAXN],y[MAXN],x1,y1;
int main()
{
    while(EOF!=scanf("%d",&a[++n]));//这样的n比真实+1
    uf[++ufl]=df[++dfl]=a[1];
    x[++x1]=y[++y1]=a[1];
    for(int i=2;i<n;i++)
    {
        if(uf[ufl]>=a[i])uf[++ufl]=a[i];//最长不上升
        else *upper_bound(uf+1,uf+1+ufl,a[i],greater<int>())=a[i];
        
        if(df[dfl]<a[i])df[++dfl]=a[i];//最长上升,与上面互为定律
        else *lower_bound(df+1,df+1+dfl,a[i])=a[i];
        
        if(x[x1]>a[i])x[++x1]=a[i];//最长下降
        else *upper_bound(x+1,x+1+x1,a[i],greater<int>())=a[i];
        
        if(y[y1]<=a[i])y[++y1]=a[i];//最长不下降,与上面互为定律
        else *lower_bound(y+1,y+1+y1,a[i])=a[i];
    }
    printf("\n%d\n%d\n%d\n%d",ufl,dfl,x1,y1);
    return 0;
}
