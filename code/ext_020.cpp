#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mn = 3e5 + 10, mt = mn * 4;

// 比 unordered_map 更快的哈希表
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash
{
    int operator()(int x) const { return x ^ RANDOM; }
};
typedef gp_hash_table<int, int, chash> hash_t;

ll s[mt];
hash_t h[mt];
#define lfs p << 1
#define rfs p << 1 | 1
#define mkcf ll cf = (lf + rf) >> 1
#define ci const int &
void modifyS(int p, int lf, int rf, ci pos, ci v)
{
    if (lf == rf)
    {
        s[p] += v;
        return;
    }
    mkcf;
    if (pos <= cf)
    {
        modifyS(lfs, lf, cf, pos, v);
    }
    else
    {
        modifyS(rfs, cf + 1, rf, pos, v);
    }
    s[p] = s[lfs] + s[rfs];
}
ll queryS(int p, int lf, int rf, ci lc, ci rc)
{
    if (lc <= lf && rf <= rc)
    {
        return s[p];
    }
    mkcf;
    ll ans = 0;
    if (lc <= cf)
    {
        ans += queryS(lfs, lf, cf, lc, rc);
    }
    if (cf + 1 <= rc)
    {
        ans += queryS(rfs, cf + 1, rf, lc, rc);
    }
    return ans;
}
void modifyC(int p, int lf, int rf, ci pos, ci c, ci v)
{
    h[p][c] += v;
    if (lf == rf)
    {
        return;
    }
    mkcf;
    if (pos <= cf)
    {
        modifyC(lfs, lf, cf, pos, c, v);
    }
    else
    {
        modifyC(rfs, cf + 1, rf, pos, c, v);
    }
}
#define colors const vector<ll> &
ll check(ll p, ll lf, ll rf, colors cs)
{
    ll sum = 0;
    for (auto &c : cs)
    {
        sum += h[p][c];
    }
    return sum == rf - lf + 1;
}
const ll fail = -1;
ll queryCR(int p, int lf, int rf, int lc, colors cs)
{
    if (rf < lc)
    {
        return fail;
    }
    if (lc <= lf)
    {
        if (check(p, lf, rf, cs))
        { // still ok, move right
            return -1;
        }
        if (lf == rf)
        { // first to fail is lf, then ok is lf-1
            return lf - 1;
        }
    }
    mkcf;
    ll pos = queryCR(lfs, lf, cf, lc, cs);
    if (pos != fail)
    {
        return pos;
    }
    return queryCR(rfs, cf + 1, rf, lc, cs);
}
ll queryCL(int p, int lf, int rf, int rc, colors cs)
{
    if (lf > rc)
    {
        return fail;
    }
    if (rf <= rc)
    {
        if (check(p, lf, rf, cs))
        {
            return -1;
        }
        if (lf == rf)
        {
            return lf + 1;
        }
    }
    mkcf;
    ll pos = queryCL(rfs, cf + 1, rf, rc, cs);
    if (pos != fail)
    {
        return pos;
    }
    return queryCL(lfs, lf, cf, rc, cs);
}

ll n, q, c[mn], v[mn];
void solve()
{
    cin >> n >> q;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> c[i];
        modifyC(1, 1, n, i, c[i], 1);
    }
    for (ll i = 1; i <= n; ++i)
    {
        cin >> v[i];
        modifyS(1, 1, n, i, v[i]);
    }
    for (ll op, x, y; q--;)
    {
        cin >> op >> x >> y;
        if (op == 1)
        {
            modifyC(1, 1, n, x, c[x], -1);
            c[x] = y;
            modifyC(1, 1, n, x, c[x], 1);
        }
        else if (op == 2)
        {
            modifyS(1, 1, n, x, y - v[x]);
            v[x] = y;
        }
        else
        {
            bool ok = false;
            vector<ll> vec;
            for (ll i = 1, z; i <= y; ++i)
            {
                cin >> z;
                if (c[x] == z)
                {
                    ok = true;
                }
                vec.emplace_back(z);
            }
            if (!ok)
            {
                cout << "0\n";
                continue;
            }

            ll l = queryCL(1, 1, n, x, vec);
            ll r = queryCR(1, 1, n, x, vec);
            l = l == fail ? 1 : l;
            r = r == fail ? n : r;
            cout << queryS(1, 1, n, l, r) << '\n';
        }
    }

    for (ll i = 1; i <= 4 * n; ++i)
    {
        h[i].clear();
        s[i] = 0;
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
