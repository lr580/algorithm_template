#include <bits/stdc++.h>
using namespace std;
#define Maxn 410
#define Maxm 160010
#define LL long long
const LL INF = 1LL << 62;
int N, n, m;
int match[Maxn], op[Maxn];
LL eg[Maxn][Maxn], lx[Maxn], ly[Maxn], slack[Maxn];
int visx[Maxn], visy[Maxn], pre[Maxn];
void mh(int y)
{
    for (int x, z; y > 0; y = z)
    {
        x = pre[y];
        z = op[x];
        op[x] = y;
        match[y] = x;
    }
}

int nt;
void ffind(int st)
{
    for (int i = 1; i <= N; i++)
        slack[i] = INF;
    queue<int> q;
    nt++;
    q.push(st);
    visx[st] = nt;
    while (1)
    {
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int y = 1; y <= N; y++)
                if (visy[y] != nt)
                {
                    if (lx[x] + ly[y] == eg[x][y])
                    {
                        pre[y] = x;
                        if (!match[y])
                        {
                            mh(y);
                            return;
                        }
                        q.push(match[y]);
                        visx[match[y]] = nt;
                        visy[y] = nt;
                    }
                    else if (slack[y] > lx[x] + ly[y] - eg[x][y])
                        slack[y] = lx[x] + ly[y] - eg[x][y], pre[y] = x;
                }
        }
        LL delta = INF;
        for (int y = 1; y <= N; y++)
            if (visy[y] != nt)
                delta = min(delta, slack[y]);
        for (int i = 1; i <= N; i++)
        {
            if (visx[i] == nt)
                lx[i] -= delta;
            if (visy[i] == nt)
                ly[i] += delta;
            else
                slack[i] -= delta;
        }
        for (int i = 1; i <= N; i++)
            if (visy[i] != nt && slack[i] == 0)
            {
                if (!match[i])
                {
                    mh(i);
                    return;
                }
                q.push(match[i]);
                visx[match[i]] = nt;
                visy[i] = nt;
            }
    }
}
void KM()
{
    for (int i = 1; i <= N; i++)
        lx[i] = ly[i] = 0, op[i] = match[i] = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            lx[i] = max(lx[i], eg[i][j]);
    for (int i = 1; i <= N; i++)
        ffind(i);
}
void output()
{
    LL ans = 0;
    for (int i = 1; i <= N; i++)
        ans += lx[i] + ly[i];
    printf("%lld\n", ans);
    for (int i = 1; i <= n; i++)
        if (eg[i][op[i]] != 0)
            printf("%d ", op[i]);
        else
            printf("0 ");
}
void init()
{
    int l;
    scanf("%d%d%d", &n, &m, &l);
    for (int i = 1; i <= l; i++)
    {
        int x, y;
        LL c;
        scanf("%d%d%lld", &x, &y, &c);
        eg[x][y] = max(eg[x][y], c);
    }
    N = max(n, m);
}
int main()
{
    init();
    KM();
    output();
    return 0;
}