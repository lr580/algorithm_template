#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 1000010
int tr[mn][26], cnt, e[mn], fail[mn];
ll n, ans;
char s[mn];
queue<int> q;
signed main()
{
    sc(n);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%s", s + 1);
        int u = 0;
        for (int i = 1; s[i]; ++i)
        {
            int a = s[i] - 'a';
            if (!tr[u][a])
            {
                tr[u][a] = ++cnt;
            }
            u = tr[u][a];
        }
        ++e[u];
    }
    for (ll i = 0; i < 26; ++i)
    {
        if (tr[0][i])
        {
            q.push(tr[0][i]);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; ++i)
        {
            if (tr[u][i])
            {
                fail[tr[u][i]] = tr[fail[u]][i];
                q.push(tr[u][i]);
            }
            else
            {
                tr[u][i] = tr[fail[u]][i];
            }
        }
    }
    scanf("%s", s + 1);
    int u = 0;
    for (int i = 1; s[i]; ++i)
    {
        int a = s[i] - 'a';
        u = tr[u][a];
        for (int j = u; j && e[j] != -1; j = fail[j])
        {
            ans += e[j], e[j] = -1;
        }
    }
    printf("%lld", ans);
    return 0;
}