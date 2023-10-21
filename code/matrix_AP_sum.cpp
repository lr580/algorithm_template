#include <bits/stdc++.h> //https://oi-oj.socoding.cn/p/1068
using namespace std;
using ll = long long;
const ll mod = 998244353;
using arr = vector<vector<ll>>;
struct matrix
{
    ll n;
    arr a;
    matrix(ll nn) : n(nn)
    {
        a = arr(n, vector<ll>(n));
    }
    matrix(arr aa) : n(aa.size()), a(aa) {}
    friend matrix operator+(const matrix &x, const matrix &y)
    {
        matrix r = matrix(x.n);
        for (ll i = 0; i < x.n; ++i)
        {
            for (ll j = 0; j < x.n; ++j)
            {
                r.a[i][j] = (x.a[i][j] + y.a[i][j]) % mod;
            }
        }
        return r;
    }
    friend matrix operator*(const matrix &x, const matrix &y)
    {
        matrix r = matrix(x.n);
        for (ll i = 0; i < x.n; ++i)
        {
            for (ll j = 0; j < x.n; ++j)
            {
                for (ll k = 0; k < x.n; ++k)
                {
                    r.a[i][j] = (r.a[i][j] + x.a[i][k] * y.a[k][j]) % mod;
                }
            }
        }
        return r;
    }
    matrix static unit(ll k)
    { // 单位阵
        matrix r = matrix(k);
        for (ll i = 0; i < k; ++i)
        {
            r.a[i][i] = 1;
        }
        return r;
    }
    matrix pow(ll k)
    {
        matrix c = *this, r = unit(n);
        for (; k; k >>= 1)
        {
            if (k & 1)
            {
                r = r * c;
            }
            c = c * c;
        }
        return r;
    }
    matrix psum(ll k)
    {
        if (k == 0)
            return matrix(n);
        if (k == 1)
            return *this;
        if (k % 2 == 1)
            return psum(k - 1) + pow(k);
        return (unit(n) + this->pow(k / 2)) * psum(k / 2);
    }
};
using mat = matrix;
ll n, m, k;
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m >> k;
    assert(n>=1&&n<=50&&m>=0&&m<=1e5&&k>=0&&k<=1e9);
    mat e = mat(n * 2);
    for (ll u, v, w; m--;)
    {
        cin >> u >> v >> w;
        assert(1<=u&&u<=n&&1<=v&&v<=n&&0<=w&&w<=1e9);
        --u, --v;
        mat f = mat({{1, w}, {0, 1}});
        (e.a[u * 2][v * 2] += f.a[0][0]) %= mod;
        (e.a[u * 2][v * 2 + 1] += f.a[0][1]) %= mod;
        (e.a[u * 2 + 1][v * 2] += f.a[1][0]) %= mod;
        (e.a[u * 2 + 1][v * 2 + 1] += f.a[1][1]) %= mod;
    }
    e = e.psum(k);
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < n; ++j)
        {
            cout << e.a[2 * i][2 * j + 1] << ' ';
        }
        cout << '\n';
    }
    return 0;
}