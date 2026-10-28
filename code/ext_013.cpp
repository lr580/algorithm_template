ll f(const Point &a, const Point &b)
{
    if (cross(a, b) > eps)
    {
        return 1; //逆时针
    }
    if (cross(a, b) < -eps)
    {
        return -1; //顺时针
    }
    if (dot(a, b) < -eps)
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
    return f(b - a, c - a) * f(b - a, d - a) <= 0 && f(d - c, a - c) * f(d - c, b - c) <= 0;
}
