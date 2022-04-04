#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 50010
#define cp const point &
struct point
{
    ll x, y;
    point(ll a = 0, ll b = 0) : x(a), y(b) {}
    point operator-(cp r) const { return point(x - r.x, y - r.y); }
    ll norm() const { return x * x + y * y; }
} p[mn], s[mn];
ll cross(cp a, cp b) { return a.x * b.y - a.y * b.x; }
bool operator<(cp a, cp b)
{
    ll v = cross(a - p[1], b - p[1]);
    return v > 0 || (v == 0 && (a - p[1]).norm() < (b - p[1]).norm());
}
ll area(cp a, cp b, cp c) { return cross(b - a, c - a); }
ll n, ss, ans;
signed main()
{
    sc(n);
    for (ll i = 1; i <= n; ++i)
    {
        sc(p[i].x), sc(p[i].y);
        if (p[i].x < p[1].x || (p[i].x == p[1].x && p[i].y < p[1].y))
        {
            swap(p[i], p[1]);
        }
    }
    sort(p + 2, p + 1 + n);
    for (ll i = 1; i <= n; ++i)
    {
        while (ss > 1 && cross(s[ss] - s[ss - 1], p[i] - s[ss]) <= 0)
        {
            --ss;
        }
        s[++ss] = p[i];
    }
    s[ss + 1] = s[1];
    if (ss == 2) // not n==2
    {
        printf("%lld", (s[2] - s[1]).norm());
        return 0;
    }
    for (ll i = 1, j = 3; i <= ss; ++i)
    {
        while (area(s[i], s[i + 1], s[j]) <= area(s[i], s[i + 1], s[j % ss + 1]))
        {
            j = j % ss + 1;
        }
        ans = max(ans, max((s[j] - s[i]).norm(), (s[j] - s[i + 1]).norm()));
    }
    printf("%lld", ans);
    return 0;
}