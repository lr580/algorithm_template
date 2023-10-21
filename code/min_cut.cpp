#include <bits/stdc++.h>
using namespace std;
// https://oj.socoding.cn/p/1975
const int N = 1e5 + 5, M = 2e5 + 5;
int n, m, s, t, tot = 1, lnk[N], ter[M], nxt[M], val[M], dep[N], cur[N];

void add(int u, int v, int w)
{
    ter[++tot] = v, nxt[tot] = lnk[u], lnk[u] = tot, val[tot] = w;
}

void addedge(int u, int v, int w) { add(u, v, w), add(v, u, 0); }

int bfs(int s, int t)
{
    memset(dep, 0, sizeof(dep));
    memcpy(cur, lnk, sizeof(lnk));
    std::queue<int> q;
    q.push(s), dep[s] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = lnk[u]; i; i = nxt[i])
        {
            int v = ter[i];
            if (val[i] && !dep[v])
                q.push(v), dep[v] = dep[u] + 1;
        }
    }
    return dep[t];
}

int dfs(int u, int t, int flow)
{
    if (u == t)
        return flow;
    int ans = 0;
    for (int &i = cur[u]; i && ans < flow; i = nxt[i])
    {
        int v = ter[i];
        if (val[i] && dep[v] == dep[u] + 1)
        {
            int x = dfs(v, t, std::min(val[i], flow - ans));
            if (x)
                val[i] -= x, val[i ^ 1] += x, ans += x;
        }
    }
    if (ans < flow)
        dep[u] = -1;
    return ans;
}

int dinic(int s, int t)
{
    int ans = 0;
    while (bfs(s, t))
    {
        int x;
        while ((x = dfs(s, t, 1 << 30)))
            ans += x;
    }
    return ans;
}

int vis[N];
void dfs(int u)
{
    vis[u] = 1;
    for (int i = lnk[u]; i; i = nxt[i])
    {
        int v = ter[i];
        if (!vis[v] && val[i])
            dfs(v);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    s = 1, t = n;
    while (m--)
    {
        int u, v, w = 1;
        scanf("%d%d", &u, &v);
        addedge(u, v, w);
    }
    printf("%d\n", dinic(s, t));
    dfs(s);
    for (int u = 1; u <= n; u++)
    {
        for (int i = lnk[u]; i; i = nxt[i])
        {
            int v = ter[i];
            if (vis[u] == 1 && vis[v] == 0 && val[i] == 0)
            {
                printf("%d %d\n", u, v);
            }
        }
    }
    return 0;
}