#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
vector<ll> nxt[28], f;
ll dfs(int u)
{
    if (f[u])
        return f[u];
    ll ans = 1;
    for (auto i = 1; i <= 26; ++i)
    {
        if (nxt[i][u])
        {
            (ans += dfs(nxt[i][u])) %= mod;
        }
    }
    return f[u] = ans;
}
int distinctSubseqII(string s)
{
    ll n = s.size();
    for (ll j = 1; j <= 26; ++j)
        nxt[j].resize(n + 2, 0);
    for (ll i = n; i >= 1; --i)
    {
        for (ll j = 1; j <= 26; ++j)
            nxt[j][i - 1] = nxt[j][i];
        nxt[s[i - 1] - 'a' + 1][i - 1] = i;
    }
    f.resize(n + 2, 0);
    return (dfs(0) - 1 + mod) % mod;
}
