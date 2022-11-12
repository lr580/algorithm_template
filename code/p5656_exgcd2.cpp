#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
ll t, a, b, c, x, y, xmi, xmx, ymi, ymx;
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        ll g = exgcd(a, b, x, y);
        if (c % g)
        {
            cout << "-1\n";
            continue;
        }
        a /= g, b /= g, c /= g;
        x *= c, y *= c;
        x = (x % b + b) % b;
        x = x == 0 ? b : x;
        y = (c - a * x) / b;
        if (y > 0)
        {
            xmi = x, ymx = y;
            y %= a;
            y = y == 0 ? a : y;
            x = (c - b * y) / a;
            xmx = x, ymi = y;
            cout << (xmx - xmi) / b + 1 << ' ';
            cout << xmi << ' ' << ymi << ' ' << xmx << ' ' << ymx << '\n';
        }
        else
        {
            cout << x << ' ' << y % a + a << '\n';
        }
    }
    return 0;
}
