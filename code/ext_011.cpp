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
