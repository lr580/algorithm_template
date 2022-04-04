#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define sc(x) scanf("%lld", &x)
#define mn 200010
ll n;
db ans = 1e21;
struct node
{
    ll x, y;
    bool operator<(const node &r) const { return x < r.x; }
} p[mn];
db dis(const node &a, const node &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
db tri(const node &a, const node &b, const node &c)
{
    return dis(a, b) + dis(b, c) + dis(c, a);
}
void solve(ll lc, ll rc)
{
    if (lc == rc)
        return;
    ll cc = (lc + rc) >> 1;
    ll cx = p[cc].x; //修改前的
    solve(lc, cc), solve(cc + 1, rc);
    inplace_merge(p + lc, p + cc + 1, p + rc + 1, [](const node &x, const node &y)
                  { return x.y < y.y; });
    vector<node> v;
    for (ll i = lc; i <= rc; ++i)
        if (abs(cx - p[i].x) < ans / 2)
            v.emplace_back(p[i]);
    for (auto lf = v.begin(), rf = lf; lf != v.end(); lf++)
    {
        while (rf != v.end() && abs(rf->y - lf->y) < ans / 2)
            ++rf;
        for (auto i = lf + 1; i != rf; ++i)
            for (auto j = lf + 1; j != i; ++j)
                ans = min(ans, tri(*lf, *i, *j));
    }
}
signed main()
{
    sc(n);
    for (ll i = 1; i <= n; ++i)
        sc(p[i].x), sc(p[i].y);
    sort(p + 1, p + 1 + n);
    solve(1, n);
    printf("%lf", ans);
    return 0;
}