#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define sc(x) scanf("%d", &x)
#define mn 2050
ll n, m, a, b, c, d, delta;
char op[3];
ll lowbit(ll &x) { return x & -x; }
struct BIT
{
    ll t[mn][mn];
    void add(ll lf, ll rf, ll v)
    {
        for (ll i = lf; i <= n; i += lowbit(i))
            for (ll j = rf; j <= m; j += lowbit(j))
                t[i][j] += v;
    }
    ll query(ll lf, ll rf)
    {
        ll res = 0;
        for (ll i = lf; i; i -= lowbit(i))
            for (ll j = rf; j; j -= lowbit(j))
                res += t[i][j];
        return res;
    }
} x, xi, xj, xij;
void add(ll lf, ll rf, ll v)
{
    x.add(lf, rf, v), xi.add(lf, rf, v * lf), xj.add(lf, rf, v * rf), xij.add(lf, rf, v * lf * rf);
}
ll query(ll lf, ll rf)
{
    return x.query(lf, rf) * (lf * rf + lf + rf + 1) - xi.query(lf, rf) * (rf + 1) - xj.query(lf, rf) * (lf + 1) + xij.query(lf, rf);
}
signed main()
{
    scanf("X"), sc(n), sc(m);
    while (~scanf("%s", op))
    {
        sc(a), sc(b), sc(c), sc(d);
        if (op[0] == 'L')
        {
            sc(delta);
            add(a, b, delta), add(a, d + 1, -delta), add(c + 1, b, -delta), add(c + 1, d + 1, delta);
        }
        else
            printf("%d\n", query(c, d) - query(a - 1, d) - query(c, b - 1) + query(a - 1, b - 1));
    }
    return 0;
}