#include <bits/stdc++.h>
using namespace std;
string pre, mid, post;
typedef long long ll;
ll n, idx, h[256];     // index of pre
void dfs(ll lf, ll rf) // search in [lf,rf)
{
    if (lf >= rf || idx == n)
        return;
    char v = pre[idx++];
    ll cf = h[v];
    dfs(lf, cf);
    dfs(cf + 1, rf);
    post.push_back(v);
}
signed main()
{
    cin >> mid >> pre;
    n = mid.size();
    for (ll i = 0, ie = mid.size(); i < ie; ++i)
        h[mid[i]] = i;
    dfs(0, n);
    cout << post;
    return 0;
}