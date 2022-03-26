#include <bits/stdc++.h>
using namespace std;
#define MAXN 150002
#define ANS       \
    {             \
        ++ans;    \
        continue; \
    }
int fa[MAXN], n, k, ans, cmd, x, y, n3;
inline int finds(int k)
{
    while (k != fa[k])
        k = fa[k] = fa[fa[k]];
    return k;
}
signed main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= 3 * n; ++i)
        fa[i] = i;
    while (k--)
    {
        scanf("%d%d%d", &cmd, &x, &y);
        if (x > n || y > n)
            ANS;
        if (cmd == 1)
        {
            if (finds(x + n) == finds(y) || finds(x) == finds(y + n))
                ANS; //或后者改为x+2n与y
            fa[finds(x)] = finds(y);
            fa[finds(x + n)] = finds(y + n);
            fa[finds(x + n + n)] = finds(y + n + n);
        }
        else
        {
            if (finds(x) == finds(y) || finds(x) == finds(y + n))
                ANS; //如果同类相食或反向捕食(y+n是天敌)，是谬论
            fa[finds(x + n)] = finds(y);
            fa[finds(x + n + n)] = finds(y + n);
            fa[finds(x)] = finds(y + n + n);
        }
    }
    printf("%d", ans);
    return 0;
}