#include<bits/stdc++.h>
int fa[105],cha[105];  
int find(int x)
{  
    if(x!=fa[x])
    {
        int t=find(fa[x]);
        cha[x]+=cha[fa[x]];
        fa[x]=t;  
    }  
    return fa[x];  
}  
int main()  
{  
    int T,n,m,i,x,y,z,flag;  
    scanf("%d",&T);  
    while (T--) 
    {  
        flag=0;  
        scanf("%d%d",&n,&m);  
        for(i=0;i<=n;i++)
        {  
            fa[i]=i;  
            cha[i]=0;  
        }  
        for(i=1;i<=m;i++)  
        {  
            scanf("%d%d%d",&x,&y,&z);  
            x--;  
            if(find(x)!=find(y))  
            {  
                cha[fa[y]]=cha[x]-cha[y]-z;  
                fa[fa[y]]=fa[x];
            }  
            else  
            if(cha[x]-cha[y]!=z) flag=1;  
        }  
        if(flag==0) printf("true\n"); else printf("false\n");  
    }  
    return 0;  
}