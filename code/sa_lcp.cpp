#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mn = 1e6 + 10;
struct suffixArray
{
    ll n, m; // m是字符集(char)大小
    ll sa[mn], rk[mn * 2], hei[mn], ct[mn], s2[mn], r1[mn];
    char *s;
    void calcSA()
    {
        for (ll i = 0; i <= m; ++i)
        {
            ct[i] = 0;
        }
        for (ll i = n + 1; i <= n * 2; ++i)
        {
            rk[i] = 0;
        }
        for (ll i = 1; i <= n; ++i)
        {
            rk[i] = s[i];
            ct[rk[i]]++;
        }
        for (ll i = 1; i <= m; ++i)
        {
            ct[i] += ct[i - 1];
        }
        for (ll i = n; i >= 1; --i)
        {
            sa[ct[rk[i]]--] = i;
        }
        ll mx = m;
        for (ll j = 1, k = 0; k < n; j *= 2, mx = k)
        {
            ll p = 0;
            for (ll i = n - j + 1; i <= n; ++i)
            {
                s2[++p] = i;
            }
            for (ll i = 1; i <= n; ++i)
            {
                if (sa[i] > j)
                {
                    s2[++p] = sa[i] - j;
                }
            }
            for (ll i = 0; i <= mx; ++i)
            {
                ct[i] = 0;
            }
            for (ll i = 1; i <= n; ++i)
            {
                ct[rk[s2[i]]]++;
            }
            for (ll i = 1; i <= mx; ++i)
            {
                ct[i] += ct[i - 1];
            }
            for (ll i = n; i >= 1; --i)
            {
                sa[ct[rk[s2[i]]]--] = s2[i];
            }
            r1[sa[1]] = k = 1;
            for (ll i = 2; i <= n; ++i)
            {
                if (rk[sa[i - 1]] == rk[sa[i]] && rk[sa[i - 1] + j] == rk[sa[i] + j])
                {
                    r1[sa[i]] = k;
                }
                else
                {
                    r1[sa[i]] = ++k;
                }
            }
            for (ll i = 1; i <= n; ++i)
            {
                rk[i] = r1[i];
            }
        }
    }
    void calcHeight()
    {
		memset(hei, 0, sizeof hei);
        for (ll i = 1, j; i <= n; ++i)
        {
            if (rk[i] == 1)
            {
                continue;
            }
            j = max(hei[rk[i - 1]] - 1, 0LL);
            while (s[i + j] == s[sa[rk[i] - 1] + j])
            {
                ++j;
            }
            hei[rk[i]] = j;
        }
    }
    ll t1[mn][20], lg2[mn];
    void initLCP()
    {
        for (ll i = 2; i <= n; ++i)
        {
            lg2[i] = lg2[i / 2] + 1;
        }
        for (ll i = 1; i <= n; ++i)
        {
            t1[i][0] = hei[i];
        }
        for (ll j = 1; j <= 20; ++j)
        {
            for (ll i = 1; i + (1 << j) - 1 <= n; ++i)
            {
                t1[i][j] = min(t1[i][j - 1], t1[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    void build(char *t)
    {
        s = t, n = strlen(s + 1), m = 'z';
        calcSA();
        calcHeight();
        initLCP();
    }
    ll lcp(ll x, ll y)
    {
        ll l = rk[x], r = rk[y];
        if (l > r)
        {
            swap(l, r);
        }
        ++l;
        ll k = lg2[r - l + 1]; // or __lg(r-l+1);
        return min(t1[l][k], t1[r - (1 << k) + 1][k]);
    }
} s1, s2;
char s[mn];
ll n, t, l, r;
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> s + 1;
    n = strlen(s + 1);
    s1.build(s);
    reverse(s + 1, s + 1 + n);
    s2.build(s);
    for (cin >> t; t; --t)
    {
        cin >> l >> r;
        cout << s1.lcp(l, r) << ' ' << s2.lcp(n - l + 1, n - r + 1) << '\n';
    }
    return 0;
}