#include <bits/stdc++.h> //https://oj.socoding.cn/p/1454
using namespace std;
typedef int ll;
#define sc(x) scanf("%d", &x)
#define mn 500010
ll n, q, a[mn], v, i;
// 维护编号为v的双向链表
ll index_before[mn]; //第i个柜子的编号上一次出现的下标 即 链表prev
ll last_pos[mn];     //v最后一次出现的下标是last_pos[v] 即链表v的尾部指针
ll index_after[mn];  //第i个柜子的编号下一次出现的下标 即 链表next

//区间[lc,rc]内不重复的充要条件是index_before[i]或index_after[i]均不在这个区间内
//任取其一判断即可，这里取index_before[i]
//合并物品，构造线段树，每个节点维护的区间代表这个区间内的编号最近会在上一次重复的下标
//只需要对区间内每个index_before取最值；显然max操作可以维护线段树
ll t[mn << 2], lc, rc, res, cmd, pos;
#define lfs p << 1
#define rfs p << 1 | 1
#define mkcf ll cf = (lf + rf) >> 1
void build(ll lf, ll rf, ll p)
{
    if (lf == rf)
    {
        t[p] = index_before[lf];
        return;
    }
    mkcf;
    build(lf, cf, lfs);
    build(cf + 1, rf, rfs);
    t[p] = max(t[lfs], t[rfs]);
}
void query(ll lf, ll rf, ll p)
{
    if (lc <= lf && rf <= rc)
    {
        res = max(res, t[p]);
        return;
    }
    mkcf;
    if (cf >= lc)
        query(lf, cf, lfs);
    if (cf < rc)
        query(cf + 1, rf, rfs);
}
void fix(ll lf, ll rf, ll p)
{
    if (lf == rf)
    {
        t[p] = v;
        return;
    }
    mkcf;
    if (cf >= pos)
        fix(lf, cf, lfs);
    else
        fix(cf + 1, rf, rfs);
    t[p] = max(t[lfs], t[rfs]);
}

signed main()
{
    sc(n), sc(q);
    for (ll i = 1; i <= n; ++i)
    {
        sc(v);
        //下面三行代码实际上在维护编号为v的双向链表
        index_before[i] = last_pos[v];
        index_after[last_pos[v]] = i;
        last_pos[v] = i;
        a[i] = v;
    }
    build(1, n, 1); //不build见祖宗
    while (q--)
    {
        sc(cmd);
        if (cmd == 2)
        {
            sc(lc), sc(rc), res = 0;
            query(1, n, 1);
            printf("%d\n", res >= lc);
        }
        else
        {
            sc(i);
            //双向链表删除节点
            lc = index_before[i], rc = index_after[i];
            if (lc)
                index_after[lc] = rc;
            if (rc)
                index_before[rc] = lc;

            //线段树修改
            //编号为0的双向链表不计重复，均头结点指向0
            pos = i, v = 0, fix(1, n, 1);
            //双向链表的后继节点指向更新 对线段树生效
            if (rc)
                pos = rc, v = lc, fix(1, n, 1);
        }
    }
    return 0;
}