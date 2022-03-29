#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct op
{
    int type;
    // type==0 Change i means position; j means ispositive; k means the number after change
    // type==1 Query i means left; r means right; k means kth-number
    int i, j, k;
    int id;
};
int n, m, a[10050], ans[10050], f[50050];
vector<op> q;
int lowbit(int x)
{
    return x & -x;
}
void add(int x, int k)
{
    while (x <= n)
    {
        f[x] += k;
        x += lowbit(x);
    }
}
int query(int k)
{
    int ans = 0;
    while (k > 0)
    {
        ans += f[k];
        k -= lowbit(k);
    }
    return ans;
}
void solve(int lb, int ub, vector<op> &q)
{
    vector<op> Left;
    vector<op> Right;
    int mb = (lb + ub) >> 1;
    if (ub - lb == 1)
    {
        for (int i = 0; i < q.size(); i++)
        {
            if (q[i].type == 1)
                ans[q[i].id] = lb;
        }
        return;
    }
    else if (q.empty())
        return;
    for (int i = 0; i < q.size(); i++)
    {
        op tmp = q[i];
        if (tmp.type == 0)
        {
            if (tmp.k < mb)
            {
                add(tmp.i, tmp.j); // i:pos j:num
                Left.push_back(tmp);
            }
            else
                Right.push_back(tmp);
        }
        else
        {
            int kth = query(tmp.j) - query(tmp.i - 1);
            if (kth >= tmp.k)
                Left.push_back(tmp);
            else
            {
                tmp.k -= kth;
                Right.push_back(tmp);
            }
        }
    }
    for (int x = 0; x < Left.size(); x++)
        if (Left[x].type == 0)
            add(Left[x].i, -Left[x].j);
    solve(lb, mb, Left);
    solve(mb, ub, Right);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        op tmp = {0, i, 1, a[i]};
        q.push_back(tmp);
    }
    for (int x = 0; x < m; x++)
    {
        char cmd;
        int i;
        scanf("%s%d", &cmd, &i);
        if (cmd == 'C')
        {
            int t;
            scanf("%d", &t);
            op tmp = {0, i, -1, a[i], 0};
            q.push_back(tmp);
            a[i] = t;
            tmp = {0, i, 1, t, 0};
            q.push_back(tmp);
        }
        else
        {
            int j, k;
            scanf("%d%d", &j, &k);
            op tmp = {1, i, j, k, x};
            q.push_back(tmp);
        }
    }
    for (int i = 0; i < m; i++)
        ans[i] = -1;
    solve(0, 1e9, q);
    for (int i = 0; i < m; i++)
        if (ans[i] != -1)
            printf("%d\n", ans[i]);
    return 0;
}