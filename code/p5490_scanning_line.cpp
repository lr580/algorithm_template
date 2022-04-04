#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 300010
unordered_map<ll, ll> h;
struct scline
{
    ll x, ay, by, c;
    bool operator<(const scline &p) const { return x < p.x; }
} sc[mn];
ll ax, ay, bx, by, n, xs[mn], xss, c[mn << 2], lp[mn << 2], rp[mn << 2], v[mn << 2], lf, rf, k, ans;
#define lfs h << 1
#define rfs h << 1 | 1
#define mkcf ll cf = (lf + rf) >> 1
void init(ll lf, ll rf, ll h)
{
    lp[h] = lf, rp[h] = rf;
    if (lf != rf)
    {
        mkcf;
        init(lf, cf, lfs);
        init(cf + 1, rf, rfs);
    }
}
void add(ll h)
{
    if (rf < lp[h] || lf > rp[h])
        return;
    if (lf <= lp[h] && rp[h] <= rf)
        c[h] += k;
    else
        add(lfs), add(rfs);
    if (c[h])
        v[h] = xs[rp[h] + 1] - xs[lp[h]];
    else
        v[h] = v[lfs] + v[rfs];
}
signed main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lld%lld%lld%lld", &ax, &ay, &bx, &by);
        sc[i] = {ax, ay, by, 1};
        sc[i + n] = {bx, ay, by, -1};
        xs[++xss] = by;
        xs[++xss] = ay;
    }
    n <<= 1;
    sort(sc + 1, sc + 1 + n);
    sort(xs + 1, xs + 1 + n);
    xss = unique(xs + 1, xs + 1 + n) - xs - 1;
    for (ll i = 1; i <= xss; ++i)
        h[xs[i]] = i;
    init(1, n, 1);
    for (ll i = 1; i < n; ++i)
    {
        lf = h[sc[i].ay], rf = h[sc[i].by] - 1, k = sc[i].c;
        add(1);
        ans += v[1] * (sc[i + 1].x - sc[i].x);
    }
    printf("%lld", ans);
    return 0;
}