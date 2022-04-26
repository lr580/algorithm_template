#include <bits/stdc++.h> //SCNUOJ1731 https://oj.socoding.cn/p/1731
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
ll n;
struct node_t
{
    ll l, r;
    mutable ll v; // mutable使得const可变(set元素是const)
    node_t(const ll &il, const ll &ir, const ll &iv) : l(il), r(ir), v(iv) {}
    inline bool operator<(const node_t &o) const { return l < o.l; }
};
set<node_t> odt; //建立一棵珂朵莉树
auto split(ll x) //珂朵莉基操
{
    if (x > n)
        return odt.end();
    auto it = --odt.upper_bound(node_t{x, 0, 0});
    if (it->l == x)
        return it;
    ll l = it->l, r = it->r, v = it->v;
    odt.erase(it);
    odt.insert(node_t(l, x - 1, v));
    return odt.insert(node_t(x, r, v)).first;
}
void assign(ll l, ll r, ll v) //区间赋值为v, 均摊O(loglogn)
{
    auto itr = split(r + 1), itl = split(l);
    odt.erase(itl, itr);
    odt.insert(node_t(l, r, v));
}
void add(ll l, ll r, ll v) //区间增加v, 均摊O(loglogn)
{
    auto itr = split(r + 1), itl = split(l);
    for (; itl != itr; ++itl) //枚举每个子区间
    {
        itl->v = itl->v + v;
    }
}
ll query(ll l, ll r) //区间查询, 均摊O(loglogn)
{
    ll res = 0;
    auto itr = split(r + 1), itl = split(l);
    for (; itl != itr; ++itl)
    { // itl->l, itl->r, itl->v 是当前子区间的左右端点和值
        res += (itl->r - itl->l + 1) * (itl->v);
    }
    return res;
}
signed main()
{
    sc(n);
    odt.insert({1, n, 1236895}); //初始化区间
    ll m, cmd, l, r, x;
    for (sc(m); m--;)
    {
        sc(cmd), sc(l), sc(r);
        if (cmd == 1)
        {
            sc(x), assign(l, r, x);
        }
        else if (cmd == 2)
        {
            sc(x), add(l, r, x);
        }
        else
        {
            printf("%lld\n", query(l, r));
        }
    }
    return 0;
}