//https://codeforces.com/gym/102992/problem/F
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
ll t, n, m, p;
db q;
db f(ll x)
{
    return (x * n + m) / (1 - pow(q, x));
}
signed main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld%lld", &n, &m, &p);
        q = 1 - 1e-4 * p;
        ll lf = 1, rf = 1e9;
        db ans = 1e21;
        while (lf < rf)
        {
            ll tri = (rf - lf) / 3;
			ll lc = lf + tri, rc = rf - tri;
            db lv = f(lc), rv = f(rc);
            ans = min({ans, lv, rv});
            if (lv < rv)
            {
                rf = rc - 1;
            }
            else
			
            {
                lf = lc + 1;
            }
        }
        printf("%.12lf\n", ans);
    }
    return 0;
}
/*
3
1 1 5000
1 1 1
1 2 10000
*/