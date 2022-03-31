#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
typedef pair<int, int> pii;
const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;
const int maxt = 4e6;//4n+mlogn
#define fi first
#define se second
struct Node
{
    int ls, rs, val, rnk;
};
#define mid ((l + r) / 2)
int n, m;
int rt[maxm];
struct SegTree
{
    Node s[maxt];
    int tot;
    int build(int l, int r)
    {
        int k = ++tot;
        if (l == r)
            s[k] = {0, 0, l, 1};
        else
            s[k] = {build(l, mid), build(mid + 1, r), 0, 0};
        return k;
    }
    pii new_node(int l, int r, int u, int p)
    {
        int k = ++tot;
        s[k] = s[u];
        if (l == r)
            return {k, k};
        int res;
        if (p <= mid)
        {
            pii pos = new_node(l, mid, s[u].ls, p);
            s[k].ls = pos.fi, res = pos.se;
        }
        else
        {
            pii pos = new_node(mid + 1, r, s[u].rs, p);
            s[k].rs = pos.fi, res = pos.se;
        }
        return {k, res};
    }
    int qry(int l, int r, int k, int p)
    { // node
        if (l == r)
            return k;
        if (p <= mid)
            return qry(l, mid, s[k].ls, p);
        else
            return qry(mid + 1, r, s[k].rs, p);
    }
    int merge(int k, int u, int v)
    { // node
        pii p1 = new_node(1, n, k, s[u].val);
        s[p1.se].val = s[v].val;
        pii p2 = new_node(1, n, p1.fi, s[v].val);
        s[p2.se].rnk = max(s[p2.se].rnk, s[p1.se].rnk + 1);
        return p2.fi;
    }
} sgt;

struct DSU
{
    Node *s;
    void init()
    {
        rt[0] = sgt.build(1, n);
        s = sgt.s;
    }
    int fd(int k, int u)
    { // node
        int fa = sgt.qry(1, n, k, u);
        if (s[fa].val == u)
            return fa;
        int res = fd(k, s[fa].val);
        s[fa].rnk = s[res].rnk + 1;
        return res;
    }
    int mg(int k, int u, int v)
    {
        u = fd(k, u), v = fd(k, v);
        if (s[u].val == s[v].val)
            return k;
        if (s[u].rnk < s[v].rnk)
            return sgt.merge(k, u, v);
        else
            return sgt.merge(k, v, u);
    }
} dsu;

int main()
{
    sc(n), sc(m);
    dsu.init();
    for (int i = 1, o, x, y; i <= m; ++i)
    {
        sc(o);
        if (o == 1)
            sc(x), sc(y), rt[i] = dsu.mg(rt[i - 1], x, y);
        if (o == 2)
            sc(x), rt[i] = rt[x];
        if (o == 3)
        {
            sc(x), sc(y);
            rt[i] = rt[i - 1];
            int u = dsu.fd(rt[i], x), v = dsu.fd(rt[i], y);
            printf("%d\n", u == v);
        }
    }
    return 0;
}