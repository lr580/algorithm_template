#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 400010
ll n, ans = 1e18;
struct node
{
    ll x, y;
    bool operator<(const node &r) const { return x < r.x; }
} p[mn];
void solve(ll lc, ll rc)
{
    if (lc == rc)
    {
        return;
    }
    ll cc = (lc + rc) >> 1;
    ll cx = p[cc].x; //修改前的
    solve(lc, cc), solve(cc + 1, rc);
    inplace_merge(p + lc, p + cc + 1, p + rc + 1, [](const node &x, const node &y)
                  { return x.y < y.y; });
    vector<node> v;
    for (ll i = lc; i <= rc; ++i)
    {
        if ((cx - p[i].x) * (cx - p[i].x) <= ans)
        {
            v.emplace_back(p[i]);
        }
    }
    for (auto lf = v.begin(), rf = lf; lf != v.end(); lf++)
    {
        double sans = sqrt(ans);
        while (rf != v.end() && rf->y <= lf->y + sans)
        {
            ++rf;
        }
        for (auto i = lf + 1; i != rf; ++i)
        {
            ans = min(ans, (lf->x - i->x) * (lf->x - i->x) + (lf->y - i->y) * (lf->y - i->y));
        }
    }
}
signed main()
{
    sc(n);
    for (ll i = 1; i <= n; ++i)
    {
        sc(p[i].x), sc(p[i].y);
    }
    sort(p + 1, p + 1 + n);
    solve(1, n);
    printf("%lld", ans);
    return 0;
}