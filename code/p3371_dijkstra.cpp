#include <bits/stdc++.h>
#define MAXN 100002
#define MAXM 200002
#define BIG (1 << 31) - 1
using namespace std;
int n, m, s, ui, vi, wi, p[MAXN], d[MAXN];
vector<pair<int, int>> g[MAXN];
bool vis[MAXN];
void dijkstra()
{
    for (int i = 1; i <= n; i++)
        d[i] = BIG;
    d[s] = 0;
    int minv, minu;
    for (int h = 0; h + 1 < n; h++)
    {
        minv = BIG;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && d[i] < minv)
            {
                minv = d[i];
                minu = i;
            }
        }
        minv = BIG;
        vis[minu] = true;
        for (auto i : g[minu])
        {
            if (!vis[i.first] && d[minu] + i.second < d[i.first])
            {
                d[i.first] = d[minu] + i.second;
            }
        }
    }
}
signed main()
{
    scanf("%d%d%d", &n, &m, &s);
    while (m--)
    {
        scanf("%d%d%d", &ui, &vi, &wi);
        g[ui].push_back({vi, wi});
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
        printf("%d ", d[i]);
    return 0;
}
