#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 100010
ll n, x[mn], t[mn], m, k, ans[mn], bin[mn], cnt[mn];
ll sq, bn, bel[mn], lf[mn], rf[mn];
struct query
{
    ll l, r, i;
    bool operator<(const query &x) const
    { //一定要这么排序
        return bel[l] == bel[x.l] ? r < x.r : bel[l] < bel[x.l];
    }
} q[mn];
void del(ll v) { --bin[v]; }
void add(ll v, ll &tmp) { tmp = max(tmp, (++bin[v]) * t[v]); }
signed main()
{
    sc(n), sc(m), sq = sqrt(n), bn = n / sq;
    for (ll i = 1; i <= n; ++i)
    {
        sc(x[i]), t[i] = x[i];
    }
    for (ll i = 1; i <= m; ++i)
    {
        sc(q[i].l), sc(q[i].r), q[i].i = i;
    }
    for (ll i = 1; i <= bn; ++i) //一定要这么分块，不能/sq，不然会炸
        lf[i] = (i - 1) * sq + 1, rf[i] = i * sq;
    if (rf[bn] < n)
        ++bn, lf[bn] = rf[bn - 1] + 1, rf[bn] = n;
    for (ll i = 1; i <= bn; ++i)
        for (ll j = lf[i]; j <= rf[i]; ++j)
            bel[j] = i;
    sort(q + 1, q + 1 + m);
    sort(t + 1, t + 1 + n);
    k = unique(t + 1, t + 1 + n) - (t + 1);
    for (ll i = 1; i <= n; ++i)
    { // x[i]是输入的a[i]排在第x[i]位,离散化压[1,1e9]到[1,1e5]
        x[i] = lower_bound(t + 1, t + 1 + k, x[i]) - t;
    }
    ll l = 1, r = 0, la = 0, sum = 0, l2 = 0, sum2 = 0;
    for (ll i = 1; i <= m; ++i)
    {
        if (bel[q[i].l] == bel[q[i].r])
        { // 询问的左右端点同属于一个块则暴力扫描回答
            for (ll j = q[i].l; j <= q[i].r; ++j)
            {
                ++cnt[x[j]]; //入桶
            }
            for (ll j = q[i].l; j <= q[i].r; ++j)
            { //按题意计算
                ans[q[i].i] = max(ans[q[i].i], t[x[j]] * cnt[x[j]]);
            }
            for (ll j = q[i].l; j <= q[i].r; ++j)
            {
                --cnt[x[j]]; //清理记忆
            }
            continue;
        }
        if (bel[q[i].l] != la) // 访问到了新的块则重新初始化莫队区间
        {
            while (r > rf[bel[q[i].l]])
                del(x[r--]);
            while (l < rf[bel[q[i].l]] + 1)
                del(x[l++]);
            sum = 0, la = bel[q[i].l];
        }
        while (r < q[i].r) // 扩展右端点
            add(x[++r], sum);
        l2 = l, sum2 = sum;
        while (l2 > q[i].l) // 扩展左端点
            add(x[--l2], sum2);
        ans[q[i].i] = sum2;
        while (l2 < l) // 回滚
            del(x[l2++]);
    }
    for (ll i = 1; i <= m; ++i)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}