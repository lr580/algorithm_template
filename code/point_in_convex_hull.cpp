#include <cstdio> //https://vjudge.net/problem/UVALive-7281
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1e-10;
int dcmp(double x)
{
    if (fabs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}
struct Point
{
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    bool operator==(const Point &B) const
    {
        return dcmp(x - B.x) == 0 && dcmp(y - B.y) == 0;
    }
    bool operator<(const Point &B) const
    {
        return dcmp(x - B.x) < 0 || (dcmp(x - B.x) == 0 && dcmp(y - B.y) < 0);
    }
};
typedef Point Vector;
Vector operator-(Point A, Point B)
{
    return Vector(A.x - B.x, A.y - B.y);
}
double Cross(Vector A, Vector B)
{
    return A.x * B.y - A.y * B.x;
}
int ConvexHull(Point *p, int n, Point *ch)
{
    sort(p, p + n);
    n = unique(p, p + n) - p;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)
            m--;
        ch[m++] = p[i];
    }
    int k = m;
    for (int i = n - 2; i >= 0; i--)
    {
        while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)
            m--;
        ch[m++] = p[i];
    }
    if (n > 1)
        m--;
    return m;
}

bool check(Point A, Point *p, int n) // 判断点在凸包内模板 O（logn）
{
    int l = 1, r = n - 2, mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        double a1 = Cross(p[mid] - p[0], A - p[0]);
        double a2 = Cross(p[mid + 1] - p[0], A - p[0]);
        if (a1 >= 0 && a2 <= 0)
        {
            if (Cross(p[mid + 1] - p[mid], A - p[mid]) >= 0)
                return true;
            return false;
        }
        else if (a1 < 0)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return false;
}

const int maxn = 50000 + 500;
Point p[maxn], ch[maxn];

int main()
{
    int n, m;
    scanf("%d", &n);
    {
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        m = ConvexHull(p, n, ch);
        n = m;
        scanf("%d", &m);
        int cnt = 0;
        for (int i = 0; i < m; ++i)
        {
            Point q;
            scanf("%lf%lf", &q.x, &q.y);
            if (check(q, ch, n))
                cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}