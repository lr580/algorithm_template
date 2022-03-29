#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 100010
ll n, a[mn], dpnd[mn], dpu[mn], ans, x, nnd, nu;
signed main()
{
    while (EOF != scanf("%lld", &x)) a[++n] = x;
    dpnd[++nnd] = dpu[++nu] = a[1];
    for (ll i = 2; i <= n; ++i)
    {
        if (a[i] <= dpnd[nnd])dpnd[++nnd] = a[i];
        else *upper_bound(dpnd + 1, dpnd + 1 + nnd, a[i], greater<ll>()) = a[i];
        if (a[i] > dpu[nu]) dpu[++nu] = a[i];
        else *lower_bound(dpu + 1, dpu + 1 + nu, a[i]) = a[i];
    }
    printf("%lld\n%lld", nnd, nu);
    return 0;
}