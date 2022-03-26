#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define mn 200002
struct node
{
    ll ch[2], ff, v, size, mark;
    void init(ll x, ll fa)
    {
        ff = ch[0] = ch[1] = 0;
        size = 1;
        v = x;
        ff = fa;
    }
} t[mn];
ll n, rot, m, tot, lf, rf;
void pushuf(ll x)
{
    t[x].size = t[t[x].ch[0]].size + t[t[x].ch[1]].size + 1;
}
void pushdf(ll x)
{
    if (t[x].mark)
    {
        t[t[x].ch[0]].mark ^= 1;
        t[t[x].ch[1]].mark ^= 1;
        t[x].mark = 0;
        swap(t[x].ch[0], t[x].ch[1]);
    }
}
void rotate(ll x)
{
    ll y = t[x].ff;
    ll z = t[y].ff;
    ll k = (t[y].ch[1] == x);
    t[z].ch[t[z].ch[1] == y] = x;
    t[x].ff = z;
    t[y].ch[k] = t[x].ch[k ^ 1];
    t[t[x].ch[k ^ 1]].ff = y;
    t[x].ch[k ^ 1] = y;
    t[y].ff = x;
    pushuf(y), pushuf(x);
}
void splay(ll x, ll tg)
{
    while (t[x].ff != tg)
    {
        ll y = t[x].ff;
        ll z = t[y].ff;
        if (z != tg)
            ((t[z].ch[1] == y) ^ (t[y].ch[1] == x)) ? rotate(x) : rotate(y);
        rotate(x);
    }
    if (!tg)
        rot = x;
}
void insert(ll x)
{
    ll u = rot, ff = 0;
    while (u)
        ff = u, u = t[u].ch[x > t[u].v];
    u = ++tot;
    if (ff)
        t[ff].ch[x > t[ff].v] = u;
    t[u].init(x, ff);
    splay(u, 0);
}
ll kth(ll k)
{
    ll u = rot;
    while (1)
    {
        pushdf(u);
        if (t[t[u].ch[0]].size >= k)
            u = t[u].ch[0];
        else if (t[t[u].ch[0]].size + 1 == k)
            return u;
        else
            k -= t[t[u].ch[0]].size + 1, u = t[u].ch[1];
    }
}
void write(ll u)
{
    pushdf(u);
    if (t[u].ch[0])
        write(t[u].ch[0]);
    if (t[u].v > 1 && t[u].v < n + 2)
        printf("%d ", t[u].v - 1);
    if (t[u].ch[1])
        write(t[u].ch[1]);
}
void wk(ll lf, ll rf)
{
    lf = kth(lf), rf = kth(rf + 2);
    splay(lf, 0), splay(rf, lf);
    t[t[t[rot].ch[1]].ch[0]].mark ^= 1;
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (ll i = 1; i <= n + 2; ++i)
        insert(i);
    while (m--)
        scanf("%d%d", &lf, &rf), wk(lf, rf);
    write(rot);
    return 0;
}