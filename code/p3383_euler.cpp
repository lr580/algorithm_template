#include <bits/stdc++.h>
#define MAXN 100000002
#define MAXP 6000002
using namespace std;
bool vis[MAXN]; //vis[0] = vis[1] = 1;
int Prime[MAXP], k, n, q, c;
void euler(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!vis[i]) Prime[++k]=i;
        for(int j=1;j<=k;j++)
        {
            if(Prime[j]*i>n) break;
            vis[Prime[j]*i]=true;
            if(i%Prime[j]==0) break;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &q);
    euler(n);
    while(q--)
    {
        scanf("%d", &c);
        printf("%d\n", Prime[c]);
    }
    return 0;
}
