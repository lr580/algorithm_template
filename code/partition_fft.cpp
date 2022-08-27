//https://oj.socoding.cn/p/1778
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll mod = 998244353;

ll qui(ll a, ll x)
{
    ll ret = 1;
    while (x)
    {
        if (x & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return ret;
}

using Poly = vector<ll>;
const int BIT = 20;
int p[1 << BIT];
const ll maxn = 1e5 + 10;
ll fac[maxn], inv[maxn];

Poly operator*(const Poly &a, const Poly &b)
{
    int n = a.size() - 1, m = b.size() - 1;
    int L, l = 0;
    for (L = 1; L <= n + m; l++, L = L << 1)
        ;

    vector<int> p(L);

    for (int i = 1; i < L; i++)
        p[i] = ((p[i >> 1] >> 1) | ((i & 1) << (l - 1)));
    auto u = a, v = b;
    u.resize(L, 0), v.resize(L, 0);
    auto ntt = [&L, &l, &p](Poly &g, int type)
    {
        for (int i = 0; i < L; i++)
            if (i < p[i])
                swap(g[i], g[p[i]]);
        for (int i = 1; i < L; (i <<= 1))
        {
            ll wn = qui(3, (mod - 1) / (i << 1));
            for (int j = 0; j < L; j += (i << 1))
            {
                ll w = 1;
                for (int k = j; k < j + i; w = w * wn % mod, k++)
                {
                    assert(k + i < L);
                    assert(k < L);
                    ll t = g[k + i] * w % mod;
                    g[k + i] = (g[k] - t + mod) % mod;
                    g[k] = (g[k] + t) % mod;
                }
            }
        }
        if (type == 1)
            return;
        reverse(g.begin() + 1, g.begin() + L);
        ll ni = qui(L, mod - 2);
        for (int i = 0; i < L; i++)
            g[i] = g[i] * ni % mod;
    };
    ntt(u, 1), ntt(v, 1);

    Poly g(L, 0);
    for (int i = 0; i < L; i++)
        g[i] = u[i] * v[i] % mod;
    ntt(g, -1);

    return g;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    function<Poly(int, int)> calc = [&](int l, int r)
    {
        if (l >= r)
        {
            assert(l == r);
            return Poly{1, b[l]};
        }
        int mid = (l + r) / 2;
        return calc(l, mid) * calc(mid + 1, r);
    };

    Poly ep = calc(0, n);
    cout << ep[k];
    return 0;
}