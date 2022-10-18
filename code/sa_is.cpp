#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
const ll mn = 1.2e6 + 5;
char s[mn];
// begin SA-IS
ll sa[mn], rk[mn], lcp[mn];
ll str[mn * 2], ty[mn * 2], p[mn], cnt[mn], cur[mn];
#define pushs(x) sa[cur[str[x]]--] = x
#define pushl(x) sa[cur[str[x]]++] = x
void sais(ll n, ll m, ll *str, ll *ty, ll *p)
{
    ll n1 = ty[n - 1] = 0, ch = rk[0] = -1, *s1 = str + n;
    for (ll i = n - 2; ~i; --i)
    {
        ty[i] = str[i] == str[i + 1] ? ty[i + 1] : str[i] > str[i + 1];
    }
    for (ll i = 1; i < n; ++i)
    {
        rk[i] = ty[i - 1] && !ty[i] ? (p[n1] = i, n1++) : -1;
    }

    auto induce_sort = [&](ll *v)
    {
        fill_n(sa, n, -1);
        fill_n(cnt, m, 0);
        for (ll i = 0; i < n; ++i)
        {
            cnt[str[i]]++;
        }
        for (ll i = 1; i < m; ++i)
        {
            cnt[i] += cnt[i - 1];
        }
        for (ll i = 0; i < m; ++i)
        {
            cur[i] = cnt[i] - 1;
        }
        for (ll i = n1 - 1; ~i; --i)
        {
            pushs(v[i]);
        }
        for (ll i = 1; i < m; ++i)
        {
            cur[i] = cnt[i - 1];
        }
        for (ll i = 0; i < n; ++i)
        {
            if (sa[i] > 0 && ty[sa[i] - 1])
            {
                pushl(sa[i] - 1);
            }
        }
        for (ll i = 0; i < m; ++i)
        {
            cur[i] = cnt[i] - 1;
        }
        for (ll i = n - 1; ~i; --i)
        {
            if (sa[i] > 0 && !ty[sa[i] - 1])
            {
                pushs(sa[i] - 1);
            }
        }
    };
    induce_sort(p);
    for (ll i = 0, x, y; i < n; ++i)
    {
        if (~(x = rk[sa[i]]))
        {
            if (ch < 1 || p[x + 1] - p[x] != p[y + 1] - p[y])
            {
                ++ch;
            }
            else
            {
                for (ll j = p[x], k = p[y]; j <= p[x + 1]; ++j, ++k)
                {
                    if ((str[j] << 1 | ty[j]) != (str[k] << 1 | ty[k]))
                    {
                        ++ch;
                        break;
                    }
                }
            }
            s1[y = x] = ch;
        }
    }
    if (ch + 1 < n1)
    {
        sais(n1, ch + 1, s1, ty + n, p + n1);
    }
    else
    {
        for (ll i = 0; i < n1; ++i)
        {
            sa[s1[i]] = i;
        }
    }
    for (ll i = 0; i < n1; ++i)
    {
        s1[i] = p[sa[i]];
    }
    induce_sort(s1);
}
ll cti(ll n)
{
    ll m = *max_element(s, s + n);
    fill_n(rk, m + 1, 0);
    for (ll i = 0; i < n; ++i)
    {
        rk[s[i]] = 1;
    }
    for (ll i = 0; i < m; ++i)
    {
        rk[i + 1] += rk[i];
    }
    for (ll i = 0; i < n; ++i)
    {
        str[i] = rk[s[i]] - 1;
    }
    return rk[m];
}
void make_sa(ll n)
{
    // s[n] 一定要比 s 中所有字符 ascii 值小, s[n+1] 倒无所谓
    s[n] = '!', s[n + 1] = '\0';
    ll m = cti(++n);
    sais(n, m, str, ty, p);
    for (ll i = 0; i < n; ++i)
    {
        rk[sa[i]] = i;
    }
    for (ll i = 0, h = lcp[0] = 0; i < n - 1; ++i)
    {
        ll j = sa[rk[i] - 1];
        while (i + h < n && j + h < n && s[i + h] == s[j + h])
        {
            ++h;
        }
        lcp[rk[i] - 1] = h;
        if (lcp[rk[i] - 1])
        {
            --h;
        }
    }
    s[n] = '\0';
}
// end SA-IS
const ll mm = 1e5 + 5, mlg = 20;
ll st[mm][mlg], lg[mm], prf[mm];
void build_st(ll n)
{
    for (ll i = 1; i <= n; ++i)
    {
        st[i][0] = prf[i];
    }
    for (ll k = 1, len = 2; len <= n; len <<= 1, ++k)
    {
        for (ll i = 1; i + len - 1 <= n; ++i)
        {
            st[i][k] = max(st[i][k - 1], st[i + len / 2][k - 1]);
        }
    }
}
ll query(ll x, ll y)
{
    ll k = lg[y - x + 1];
    return max(st[x][k], st[y - (1 << k) + 1][k]);
}
ll v[mm], bg_pos[mm], ans[mm], maps[mn], n, m, k;
signed main()
{
    lg[1] = 0;
    for (ll i = 2; i < mm; ++i)
    {
        lg[i] = lg[i >> 1] + 1;
    }
    sc(n), sc(m), sc(k), scanf("%s", s);
    for (ll i = 1; i <= m; ++i)
    {
        sc(v[i]);
    }

    ll tot = n - 1;
    for (ll i = 1; i <= k; ++i)
    {
        ++tot;
        s[tot] = '$', maps[tot] = -1;
        bg_pos[i] = tot + 1;
        scanf("%s", s + tot + 1);
        for (ll j = tot + 1; j <= tot + m; ++j)
        {
            maps[j] = i;
        }
        tot += m;
    }
    s[n] = '#';
    ++tot;
    make_sa(tot);

    // printf("%s\n", s);
    // for (ll i = 0; i <= tot; ++i)
    // {
    //     printf("%3lld %3lld %3lld %s\n", i, sa[i], lcp[i], s + sa[i]);
    // }

    for (ll i = 1; i <= m; ++i)
    {
        prf[i] = prf[i - 1] + v[i];
    }
    build_st(m);

    ll mi = 0;
    for (ll i = 1; i <= tot; ++i)
    {
        ll j = maps[sa[i]];
        if (j == 0)
        {
            mi = lcp[i];
        }
        else
        {
            if (j > 0 && mi > 0) //不是分隔符，有公共
            {
                ll idx = sa[i] - bg_pos[j] + 1; // B_j起始下标
                ll mx = query(idx, idx + mi - 1);
                ans[j] = max(ans[j], mx - prf[idx - 1]);
            }
            mi = min(mi, lcp[i]);
        }
    }

    mi = 0;
    for (ll i = tot; i; --i)
    {
        ll j = maps[sa[i]];
        if (j == 0)
        {
            mi = lcp[i - 1];
        }
        else
        {
            if (j > 0 && mi > 0) //不是分隔符，有公共
            {
                ll idx = sa[i] - bg_pos[j] + 1; // B_j起始下标
                ll mx = query(idx, idx + mi - 1);
                ans[j] = max(ans[j], mx - prf[idx - 1]);
            }
            mi = min(mi, lcp[i - 1]);
        }
    }
    for (ll i = 1; i <= k; ++i)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}