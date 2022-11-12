#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll bsgs(ll a, ll b, ll p)
{ // min x of a^x%p=b
    if (a % p == 0 && b)
    {
        return -1;
    }
    if (b == 1)
    {
        return 0;
    }
    map<ll, ll> h;
    ll m = sqrt(p) + 1, s = 1;
    for (ll i = 1; i <= m; ++i)
    {
        h[b] = i;
        s = s * a % p, b = b * a % p;
    }
    a = s;
    for (ll i = 1; i <= m; ++i)
    {
        if (h.count(a))
        {
            return i * m - h[a] + 1;
        }
        a = a * s % p;
    }
    return -1;
}
signed main()
{
    ll a, b, p;
    cin >> p >> a >> b;
    ll ans = bsgs(a, b, p);
    cout << (ans == -1 ? "no solution" : to_string(ans));
    return 0;
}