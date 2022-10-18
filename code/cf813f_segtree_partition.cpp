#include <bits/stdc++.h>
const int N = 200000 + 10;
int n, m, ans[N];
struct E
{
    int u, v;
    E(int a, int b) : u(a), v(b) {}
};
std::map<int, int> g[N];

int L[N << 2], R[N << 2];
std::vector<E> tag[N << 2];
#define lc (o << 1)
#define rc ((o << 1) | 1)
void build(int o, int l, int r)
{
    L[o] = l;
    R[o] = r;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
}
// 把一条边拆到logm个区间上去.
// 可以说线段树只是用来保证复杂度的...
void query(int o, int l, int r, const E &e)
{
    if (L[o] > r || R[o] < l)
        return;
    if (l <= L[o] && R[o] <= r)
    {
        tag[o].push_back(e);
        return;
    }
    query(lc, l, r, e);
    query(rc, l, r, e);
}

// merged tree(root=x)->tree(root=y)
struct P
{
    int x, y;
    P(int a, int b) : x(a), y(b) {}
};
int fa[N], size[N], dis[N];
inline int getpar(int x)
{
    while (fa[x] != x)
        x = fa[x];
    return x;
}

// 到并查集根所经过的边数mod2.
// mod2意义下的加法即为xor.
// 用来查询x和根是不是相同颜色.
inline int getdis(int x)
{
    int d = 0;
    while (fa[x] != x)
    {
        d ^= dis[x];
        x = fa[x];
    }
    return d;
}
/// 按照size合并.
inline int solve(int x, int y, std::stack<P> &stk)
{
    int dx = getdis(x), dy = getdis(y);
    x = getpar(x);
    y = getpar(y);
    if (x == y)
        return (dx ^ dy);
    if (size[x] > size[y])
    {
        std::swap(x, y);
        std::swap(dx, dy);
    }
    size[y] += size[x];
    fa[x] = y;
    dis[x] = (dx ^ dy ^ 1);
    stk.push(P(x, y));
    return 1;
}
// 撤销(x->y)的合并.拆出来,size改回去.dis改成0
inline void back(P p)
{
    int x = p.x, y = p.y;
    size[y] -= size[x];
    dis[fa[x] = x] = 0;
}
// 递归线段树,进入区间[l,r]时
// 保证时间轴上[l,r]范围内一直可用的边都被加入了
void dfs(int o, int flag)
{
    std::stack<P> stk;
    for (auto e : tag[o])
        flag &= solve(e.u, e.v, stk);
    if (L[o] == R[o])
        ans[L[o]] = flag;
    else
    {
        dfs(lc, flag);
        dfs(rc, flag);
    }
    // 撤销操作...不然从爸爸进入兄弟节点的时候开始讲到的那个性质会被破坏.
    // 注意撤销顺序...
    while (!stk.empty())
    {
        back(stk.top());
        stk.pop();
    }
}

int read()
{
    int x = 0;
    char c;
    do
    {
        c = getchar();
    } while (!isdigit(c));
    do
    {
        x = x * 10 + c - '0';
        c = getchar();
    } while (isdigit(c));
    return x;
}
int main()
{
    n = read();
    m = read();
    build(1, 1, m);
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        x = read();
        y = read();
        if (x > y)
            std::swap(x, y);
        if (g[x][y] == 0)
            g[x][y] = i;
        else
        {
            query(1, g[x][y], i - 1, E(x, y));
            g[x][y] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        size[fa[i] = i] = 1;
        for (auto p : g[i])
            if (p.second > 0)
                query(1, p.second, m, E(i, p.first));
    }
    dfs(1, 1);
    for (int i = 1; i <= m; i++)
        puts(ans[i] ? "YES" : "NO");
    return 0;
}
