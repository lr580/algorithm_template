#include <bits/stdc++.h>
using namespace std;
#define MAXN 6002
struct edge
{
    int to, nx;
} e[MAXN];
int n, ui, vi, hd[MAXN], cnt, dp[MAXN][2], v[MAXN], root;
bool fa[MAXN];
inline void adde(int &u, int &v)
{
    e[++cnt].to = v;
    e[cnt].nx = hd[u];
    hd[u] = cnt;
}
void dfs(int h)
{
    dp[h][0] = 0;
    dp[h][1] = v[h];
    for (int i = hd[h]; i; i = e[i].nx)
    {
        int toi = e[i].to;
        dfs(toi);
        dp[h][0] += max(dp[toi][0], dp[toi][1]);
        dp[h][1] += dp[toi][0];
    }
}
signed main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &v[i]);
    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d", &vi, &ui);
        adde(ui, vi);
        fa[vi] = true;
    }
    for (int i = 1; i <= n; ++i)
        if (!fa[i])
        {
            root = i;
            break;
        }
    dfs(root);
    printf("%d", max(dp[root][0], dp[root][1]));
    return 0;
}