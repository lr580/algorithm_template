#include <bits/stdc++.h>
#define MAXN 203
const int BIG = 0x7fffffff;
using namespace std;
int mi, mx, n, dpmi[MAXN][MAXN], dpmx[MAXN][MAXN], s[MAXN], a[MAXN], kd;
signed main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    }
    for (int i = 1; i < n + n; ++i)
    {
        s[i] = s[i - 1] + a[i];
    }
    for (int h = 1; h < n; ++h)
    {
        for (int i = 1, j = i + h; i < n + n && j < n + n; i++, j = i + h)
        {
            dpmi[i][j] = BIG;
            kd = s[j] - s[i - 1];
            for (int k = i; k < j; ++k)
            {
                dpmi[i][j] = min(dpmi[i][j], dpmi[i][k] + dpmi[k + 1][j] + kd);
                dpmx[i][j] = max(dpmx[i][j], dpmx[i][k] + dpmx[k + 1][j] + kd);
            }
        }
    }
    mi = BIG;
    for (int i = 1; i <= n; ++i)
    {
        mx = max(mx, dpmx[i][i + n - 1]);
        mi = min(mi, dpmi[i][i + n - 1]);
    }
    printf("%d\n%d", mi, mx);
    return 0;
}