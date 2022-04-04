#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define mn 100010
#define cp const point &
ll n;
struct point
{
    db x = 0, y = 0;
    point(db a = 0, db b = 0) : x(a), y(b) {}
    point operator+(cp r) const { return point(x + r.x, y + r.y); }
    point operator-(cp r) const { return point(x - r.x, y - r.y); }
    point operator*(const db r) const { return point(x * r, y * r); }
    point operator/(const db r) const { return point(x / r, y / r); }
    db norm() const { return x * x + y * y; }
    point rotate() const { return point(y, -x); } //顺90
} p[mn], o;
db r2; // r*r
db cross(cp a, cp b) { return a.x * b.y - a.y * b.x; }
point intersect(cp p0, cp v0, cp p1, cp v1)
{
    return p0 + v0 * (cross(p1 - p0, v1) / cross(v0, v1));
}
void solve(cp a, cp b, cp c)
{
    o = intersect((a + b) / 2, (a - b).rotate(), (a + c) / 2, (a - c).rotate());
    r2 = (a - o).norm();
}
signed main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    random_shuffle(p + 1, p + 1 + n);
    for (ll i = 1; i <= n; ++i)
    {
        if ((p[i] - o).norm() > r2)
        {
            o = p[i], r2 = 0;
            for (ll j = 1; j < i; ++j)
            {
                if ((p[j] - o).norm() > r2)
                {
                    o = (p[i] + p[j]) / 2, r2 = ((p[i] - p[j]) / 2).norm();
                    for (ll k = 1; k < j; ++k)
                    {
                        if ((p[k] - o).norm() > r2)
                        {
                            solve(p[i], p[j], p[k]);
                        }
                    }
                }
            }
        }
    }
    printf("%.12lf\n%.12lf %.12lf", sqrt(r2), o.x, o.y);
    return 0;
}