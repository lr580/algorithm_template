#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define N 1024
int c[N+1][N+1];//c[i][j]代表Xi与Yj的LCS长度
int lcs(string X, string Y)
{
    int m = X.size();
    int n = Y.size();
    int maxl = 0;
    X = ' ' + X;
    Y = ' ' + Y;
    for(int i=1;i<=m;i++) c[i][0] = 0;
    for(int j=1;j<=n;j++) c[0][j] = 0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(X[i]==Y[j]) c[i][j] = c[i-1][j-1] + 1;
            else c[i][j] = max(c[i-1][j], c[i][j-1]);
            maxl = max(maxl, c[i][j]);
        }
    }
    return maxl;
}