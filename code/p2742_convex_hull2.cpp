#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define sc(x) scanf("%lld", &x)
#define mn 100010
#define cp const point &
ll n, ss, top;
struct point
{
    db x, y;
    point(db a = 0, db b = 0) : x(a), y(b) {}
    point operator+(cp r) const { return point(x + r.x, y + r.y); }
    point operator-(cp r) const { return point(x - r.x, y - r.y); }
    db norm() const { return x * x + y * y; }
} p[mn], s[mn * 2];
db cross(cp a, cp b) { return a.x * b.y - a.y * b.x; }
bool operator<(cp a, cp b)
{
    return a.x != b.x ? a.x < b.x : a.y < b.y;
}
void f(ll i)
{
    while (ss > top && cross(s[ss] - s[ss - 1], p[i] - s[ss]) < 0)
    { //根据题目要求选择 < 或 <=
        --ss;
    }
    s[++ss] = p[i];
}
signed main()
{
    sc(n);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    sort(p + 1, p + 1 + n);
    top = 1, s[ss = 1] = p[1];
    for (ll i = 2; i <= n; ++i)
    {
        f(i);
    }
    top = ss;
    for (ll i = n - 1; i >= 1; --i)
    {
        f(i);
    }
    for (ll i = 1; i < ss; ++i) //输出各点
    {
        printf("%lf %lf\n", s[i].x, s[i].y);
    }
    return 0;
}