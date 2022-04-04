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
    point operator+(cp r) const { return point(x + r.x, y + r.y); }
    point operator-(cp r) const { return point(x - r.x, y - r.y); }
    db norm() const { return x * x + y * y; }
} p[mn], s[mn];
db cross(cp a, cp b) { return a.x * b.y - a.y * b.x; }
bool operator<(cp a, cp b)
{
    db v = cross(a - p[1], b - p[1]);
    return v > 0 || (v == 0 && a.norm() < b.norm());
}
signed main()
{
    sc(n);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lf%lf", &p[i].x, &p[i].y);
        if (p[i].y < p[1].y || (p[i].y == p[1].y && p[i].x < p[1].x))
        {
            swap(p[i], p[1]);
        }
    }
    sort(p + 2, p + 1 + n);
    s[++ss] = p[1];
    for (ll i = 2; i <= n; ++i)
    {
        while (ss > 1 && cross(s[ss] - s[ss - 1], p[i] - s[ss]) < 0)
        { //根据题目要求选择 < 或 <=
            --ss;
        }
        s[++ss] = p[i];
    }
    for (ll i = 1; i <= ss; ++i) //输出各点
    {
        printf("%lf %lf\n", s[i].x, s[i].y);
    }
    return 0;
}