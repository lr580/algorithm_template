#include <bits/stdc++.h> //LOJ 162
using namespace std;
using ll = long long;
const ll mn = 65536, mod = 998244352;
ll x, n, a, pw[mn + 10], pw2[mn + 10];
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> x >> n;
    pw[0] = pw2[0] = 1;
    for (ll i = 1; i <= mn; ++i) pw[i] = pw[i - 1] * x % mod;
    for (ll i = 1; i <= mn; ++i) pw2[i] = pw2[i - 1] * pw[mn] % mod;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> a;
        cout << (pw2[a / mn] * pw[a % mn] % mod) << ' ';
    }
    return 0;
}
