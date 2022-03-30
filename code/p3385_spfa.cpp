#include <bits/stdc++.h>
using namespace std;
#define MAXN 2002
#define MAXM 6002
#define BIG (1 << 31) - 1
#define inita(a, n, v) for (int i = 0; i <= n; i++) a[i] = v
int n, m, hd[MAXN], cnt, d[MAXN], cnts[MAXN], ui, vi, wi, ttn;
bool vis[MAXN];
queue<int> q;
struct edege
{
    int to, d, nx;
} e[MAXM];
inline void adde(int u, int v, int w)
{
    e[++cnt].d = w;
    e[cnt].to = v;
    e[cnt].nx = hd[u];
    hd[u] = cnt;
}
void spfa()
{
    inita(d, n, BIG);
    inita(cnts, n, 0);
    inita(vis, n, false);
    while (!q.empty())
        q.pop();
    d[1] = 0;
    vis[1] = true;
    q.push(1);
    int u;
    while (!q.empty())
    {
        u = q.front();
        vis[u] = false;
        q.pop();
        for (int i = hd[u]; i != -1; i = e[i].nx)
        {
            if (d[u] + e[i].d < d[e[i].to])
            {
                d[e[i].to] = d[u] + e[i].d;
                if (!vis[e[i].to])
                {
                    if (++cnts[e[i].to] >= n)
                    {
                        printf("YES\n");
                        return;
                    }
                    vis[e[i].to] = true;
                    q.push(e[i].to);
                }
            }
        }
    }
    printf("NO\n");
    return;
}
int main()
{
    scanf("%d", &ttn);
    while (ttn--)
    {
        scanf("%d%d", &n, &m);
        cnt = -1;
        inita(hd, n, -1);
        while (m--)
        {
            scanf("%d%d%d", &ui, &vi, &wi);
            adde(ui, vi, wi);
            if (wi >= 0)
                adde(vi, ui, wi);
        }
        spfa();
    }
    return 0;
}