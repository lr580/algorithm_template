#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
class Point
{
public:
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point &p) const { return Point(x - p.x, y - +p.y); }
    Point operator*(const double &a) const { return Point(x * a, y * a); }
    Point operator/(const double &a) const { return Point(x / a, y / a); }
    double norm() const { return x * x + y * y; }
    double abs() const { return sqrt(norm()); }
    bool operator<(const Point &p) const
    {
        return x != p.x ? x < p.x : y < p.y;
    }
    bool operator==(const Point &p) const
    {
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }
};
typedef Point Vector;
double dot(const Point &a, const Point &b)
{
    return a.x * b.x + a.y * b.y;
}
double cross(const Point &a, const Point &b)
{
    return a.x * b.y - a.y * b.x;
}
bool isParallel(const Vector &a, const Vector &b)
{
    return equals(cross(a, b), 0.0);
}
bool isOrthogonal(const Vector &a, const Vector &b)
{
    return equals(dot(a, b), 0.0);
}
double getDistance(const Point &a, const Point &b)
{
    return (a - b).abs();
}
//极坐标互换
double arg(const Vector &p) { return atan2(p.y, p.x); }
Vector polar(const double &a, const double &r)
{
    return Point(cos(r) * a, sin(r) * a);
}
double dis_lp(const Point &a, const Point &b, const Point &p)
{
    return abs(cross(b - a, p - a)) / (b - a).abs();
}
double dis_sp(const Point &a, const Point &b, const Point &p)
{
    if (dot(b - a, p - a) < 0.0)
    {
        return (p - a).abs();
    }
    if (dot(a - b, p - b) < 0.0)
    {
        return (p - b).abs();
    }
    return dis_lp(a, b, p);
}
// bool isIntersect(const Point &a, const Point &b, const Point &c, const Point &d)
// {
//     return cross(c - a, d - a) * cross(c - b, d - b) <= 0.0 && cross(a - c, b - c) * cross(a - d, b - d) <= 0.0;
// } // 条件: AB,CD不在一条直线上
ll f(const Point &a, const Point &b)
{
    if (cross(a, b) > EPS)
    {
        return 1; //逆时针
    }
    if (cross(a, b) < -EPS)
    {
        return -1; //顺时针
    }
    if (dot(a, b) < -EPS)
    {
        return 2; // P在AB左方
    }
    if (a.abs() < b.abs())
    {
        return -2; // P在AB右方
    }
    return 0; // P在AB内部
}
bool isIntersect(const Point &a, const Point &b, const Point &c, const Point &d)
{
    return f(c - a, d - a) * f(c - b, d - b) <= 0 && f(a - c, b - c) * f(a - d, b - d) <= 0;
}
Point intersect(const Point &a, const Point &b, const Point &c, const Point &d)
{
    return c + (d - c) * (cross(a - c, b - a) / cross(d - c, b - a));
}
Point project(const Point &a, const Point &b, const Point &p)
{
    return a + (b - a) * (dot(b - a, p - a) / (b - a).norm());
}
signed main()
{

    return 0;
}