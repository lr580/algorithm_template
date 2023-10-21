#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll P = 998244353;
ll qpow(ll a, ll b = P - 2)
{
    ll r = 1;
    for (; b; b >>= 1, a = a * a % P)
        if (b & 1)
            r = r * a % P;
    return r;
}
struct modint
{
    ll v;
    modint(ll v_ = 0) : v(v_) {}
    modint operator+(const modint &o) const { return modint((v + o.v) % P); }
    modint operator-(const modint &o) const { return modint((v - o.v + P) % P); }
    modint operator*(const modint &o) const { return modint(v * o.v % P); }
    modint operator/(const modint &o) const { return modint(v * qpow(o.v) % P); }
    modint operator+=(const modint &o) { return *this = *this + o; }
    modint operator-=(const modint &o) { return *this = *this - o; }
    modint operator*=(const modint &o) { return *this = *this * o; }
    modint operator/=(const modint &o) { return *this = *this / o; }
};
#define rd(x) scanf("%d", &x)
const int N = 1 << 17 | 1;
int n, m;
modint A[N], B[N], a[N], b[N];

inline void in()
{
    for (int i = 0; i < n; i++)
        a[i] = A[i], b[i] = B[i];
}

inline void get()
{
    for (int i = 0; i < n; i++)
        a[i] *= b[i];
}

inline void out()
{
    for (int i = 0; i < n; i++)
        printf("%d%c", a[i], " \n"[i == n - 1]);
}

inline void OR(modint *f, modint x = 1)
{
    for (int o = 2, k = 1; o <= n; o <<= 1, k <<= 1)
        for (int i = 0; i < n; i += o)
            for (int j = 0; j < k; j++)
                f[i + j + k] += f[i + j] * x;
}

inline void AND(modint *f, modint x = 1)
{
    for (int o = 2, k = 1; o <= n; o <<= 1, k <<= 1)
        for (int i = 0; i < n; i += o)
            for (int j = 0; j < k; j++)
                f[i + j] += f[i + j + k] * x;
}

inline void XOR(modint *f, modint x = 1)
{
    for (int o = 2, k = 1; o <= n; o <<= 1, k <<= 1)
        for (int i = 0; i < n; i += o)
            for (int j = 0; j < k; j++)
            {
                f[i + j] += f[i + j + k];
                f[i + j + k] = f[i + j] - f[i + j + k] - f[i + j + k];
                f[i + j] *= x, f[i + j + k] *= x;
            }
}

int main()
{
    rd(m), n = 1 << m;
    for (int i = 0; i < n; i++)
        rd(A[i]);
    for (int i = 0; i < n; i++)
        rd(B[i]);
    in(), OR(a), OR(b), get(), OR(a, P - 1), out();
    in(), AND(a), AND(b), get(), AND(a, P - 1), out();
    in(), XOR(a), XOR(b), get(), XOR(a, (modint)1 / 2), out();
    return 0;
}