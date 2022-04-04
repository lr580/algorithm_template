#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define sc(x) scanf("%lld", &x)
#define mn 100010
#define cp const point &
ll n, ss;
struct point
{
    db x, y;
    point(db a = 0, db b = 0) : x(a), y(b) {}
    point operator-(cp r) const { return point(x - r.x, y - r.y); }
    db norm() const { return x * x + y * y; }
    ll quadrant() const
    {
        return 1 * (x > 0 && y >= 0) + 2 * (x <= 0 && y > 0) + 3 * (x < 0 && y <= 0) + 4 * (x >= 0 && y < 0);
    }
} p[mn], s[mn], p0;
db cross(cp a, cp b) { return a.x * b.y - a.y * b.x; }
bool operator<(cp a, cp b)
{
    if ((a - p0).quadrant() != (b - p0).quadrant())
    {
        return (a - p0).quadrant() < (b - p0).quadrant();
    }
    db v = cross(a - p0, b - p0);
    return v > 0 || (v == 0 && (a - p0).norm() < (b - p0).norm());
}
signed main()
{
    sc(n);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    sort(p + 1, p + 1 + n);
    for (ll i = 1; i <= n; ++i)
    {
        printf("(%lf, %lf)\n", p[i].x, p[i].y);
    }
    return 0;
}