#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define sc(x) scanf("%lld", &x)
#define cp const point &
struct point
{
    db x, y;
    point(db a = 0, db b = 0) : x(a), y(b) {}
    point operator-(cp r) const { return point(x - r.x, y - r.y); }
    db ang() const { return atan2(y, x); }
    db norm() const { return x * x + y * y; }
} p[1010], p0;
db cross(cp a, cp b) { return a.x * b.y - a.y * b.x; }
bool operator<(cp a, cp b)
{
    point p1 = (a - p[1]), p2 = (b - p[1]);
    return p1.ang() != p2.ang() ? p1.ang() < p2.ang() : p1.norm() < p2.norm();
}
ll n, b;
signed main()
{
    sc(n);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    sort(p + 2, p + 1 + n); //假设以第一个点为坐标原点
    for (ll i = 1; i <= n; ++i)
    {
        printf("(%lf, %lf) %lf\n", p[i].x, p[i].y, (p[i] - p[1]).ang());
    }
    return 0;
}