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
