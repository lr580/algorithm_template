#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 200010
#define alp 26
ll n, cnt, ss;
ll tr[mn][alp], idx[mn], nti[mn], fail[mn], in[mn], ans[mn], vis[mn];
char t[mn], s[mn * 10];
signed main()
{
    sc(n);
    for (ll i = 1, ts; i <= n; ++i)
    {
        scanf("%s", t + 1);
        ts = strlen(t + 1);
        ll p = 0;
        for (ll j = 1, ti; j <= ts; ++j)
        {
            ti = t[j] - 'a';
            if (tr[p][ti] == 0)
            {
                tr[p][ti] = ++cnt;
            }
            p = tr[p][ti];
        }
        if (idx[p] == 0)
        {
            idx[p] = i;
        }
        nti[i] = idx[p];
    }
    queue<ll> q;
    for (ll i = 0; i < alp; ++i)
    {
        if (tr[0][i])
        {
            q.push(tr[0][i]);
        }
    }
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (ll i = 0; i < alp; ++i)
        {
            if (tr[u][i])
            {
                fail[tr[u][i]] = tr[fail[u]][i];
                ++in[fail[tr[u][i]]];
                q.push(tr[u][i]);
            }
            else
            {
                tr[u][i] = tr[fail[u]][i];
            }
        }
    }
    scanf("%s", s + 1);
    ss = strlen(s + 1);
    for (ll i = 1, p = 0; i <= ss; ++i)
    {
        p = tr[p][s[i] - 'a'];
        ++ans[p];
    }
    for (ll i = 0; i <= cnt; ++i)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        vis[idx[u]] = ans[u];
        ll v = fail[u];
        ans[v] += ans[u];
        if (--in[v] == 0)
        {
            q.push(v);
        }
    }
    for (ll i = 1; i <= n; ++i)
    {
        printf("%lld\n", vis[nti[i]]);
    }
    return 0;
}