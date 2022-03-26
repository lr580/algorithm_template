//输入中序和后续，返回先序
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll h[256], n;
char mid[256], post[256];
void dfs(ll mlf, ll mrf, ll plf, ll prf) // mid,post
{
    if (mlf > mrf || plf > prf)
        return;
    char c = post[prf];
    int cf = h[(ll)c];
    cout << c;
    dfs(mlf, cf - 1, plf, plf + cf - mlf - 1);
    dfs(cf + 1, n - 1, plf + cf - mlf, prf - 1);
}
signed main()
{
    cin >> mid >> post;
    n = strlen(mid);
    for (ll i = 0, ie = n; i < ie; ++i)
        h[(ll)mid[i]] = i;
    dfs(0, n - 1, 0, n - 1); //[0,n-1],[0,n-1]
    return 0;
}