#include <bits/stdc++.h> //SCNUOJ1679 http://10.191.65.243:5000/p/1679
using namespace std;
typedef long long ll;
typedef double db;
ll p, a, b, q;
db k, t = 0.5, d, minx = 0.5, nowx = 0.5;
db f(db x) // assume k=1
{
    return sqrt(p - a + x * x) + sqrt(p - b + (k - x) * (k - x));
}
signed main()
{
    scanf("%lld%lld%lld%lld", &p, &a, &b, &q);
    while (q--)
    {
        scanf("%lf", &k);
        minx = nowx = k / 2;
        t = k / 2;
        while (t > 1e-6) // t是温度参数
        {
            db x1 = nowx + t;
            db x2 = nowx - t;
            db newx = f(x1) < f(x2) ? x1 : x2;
            nowx = newx;
            if (f(newx) < f(minx))
            {
                minx = newx;
            }
            t *= 0.9; // 降温系数
        }
        printf("%lf %lf\n", minx, (k - minx));
    }
    return 0;
}