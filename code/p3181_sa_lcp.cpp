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
        hei[1] = 0;
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
    void build(char *t)
    {
        s = t, n = strlen(s + 1), m = 'z';
        calcSA();
        calcHeight();
    }
    ll lc[mn], rc[mn];
    ll calcLCPsum()
    {
        stack<ll> a;
        ll sum = 0;
        for (ll i = 1; i <= n + 1; ++i)
        {
            while (!a.empty() && hei[a.top()] > hei[i])
            {
                ll j = a.top();
                a.pop();
                rc[j] = i - j;
            }
            a.push(i);
        }
        stack<ll> b;
        for (ll i = n; i >= 0; --i)
        {
            while (!b.empty() && hei[b.top()] >= hei[i])
            {
                ll j = b.top();
                b.pop();
                lc[j] = j - i;
            }
            b.push(i);
        }
        for (ll i = 1; i <= n; ++i)
        {
            sum += hei[i] * lc[i] * rc[i];
        }
        return sum;
    }
} s1, s2, s3;
char sa[mn], sb[mn], st[mn];
ll n1, n2, ans;
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> sa + 1;
    n1 = strlen(sa + 1);
    s1.build(sa);
    cin >> sb + 1;
    n2 = strlen(sb + 1);
    s2.build(sb);
    ll idx = 1;
    for (ll i = 1; i <= n1; ++i)
    {
        st[idx++] = sa[i];
    }
    st[idx++] = '#';
    for (ll i = 1; i <= n2; ++i)
    {
        st[idx++] = sb[i];
    }
    s3.build(st);
    ll ans = s3.calcLCPsum() - s1.calcLCPsum() - s2.calcLCPsum();
    cout << ans;
    return 0;
}