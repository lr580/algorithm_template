#include <bits/stdc++.h> //洛谷p1908
using namespace std;
#define mn 500010
typedef long long ll;
ll n, a[mn], b[mn], ans;
void mergesort(ll lf, ll rf)
{
    if (lf < rf)
    {
        ll cf = (lf + rf) >> 1; // left-face; center-face; right-face
        mergesort(lf, cf);
        mergesort(cf + 1, rf);
        ll i = lf, j = cf + 1, je = rf, ie = cf, k = 0; //左[i,ie],右[j,je]
        while (i <= ie && j <= je)
        {
            if (a[i] <= a[j])
            {
                b[k++] = a[i++];
            }
            else
            {
                ans += ie - i + 1;
                b[k++] = a[j++];
            }
        }
        while (i <= ie)
        {
            b[k++] = a[i++];
        }
        while (j <= je)
        {
            b[k++] = a[j++];
        }
        for (ll h = 0; h < k; ++h)
        {
            a[lf + h] = b[h];
        }
    }
}
signed main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
    }
    mergesort(1, n);
    printf("%lld", ans);
    return 0;
}