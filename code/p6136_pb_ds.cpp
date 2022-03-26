#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
__gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> tr;
ll n, m, lastans, dig, ans;
signed main()
{
    scanf("%lld%lld", &n, &m);
    dig = n + m;
    for (ll i = 1, a; i <= n; ++i)
    {
        scanf("%lld", &a);
        tr.insert(a * dig + i);
    }
    for (ll i = n + 1, opt, x; i <= m + n; ++i)
    {
        scanf("%lld%lld", &opt, &x);
        x ^= lastans;
        if (opt == 1)
        {
            tr.insert((x * dig) + i);
        }
        else if (opt == 2)
        {
            tr.erase(tr.lower_bound(x * dig));
        }
        else
        {
            if (opt == 3)
            {
                lastans = tr.order_of_key(x * dig) + 1;
            }
            else if (opt == 4)
            {
                lastans = (*tr.find_by_order(x - 1)) / dig;
            }
            else if (opt == 5)
            {
                lastans = (*--tr.lower_bound(x * dig)) / dig;
            }
            else if (opt == 6)
            {
                lastans = (*tr.upper_bound(x * dig + dig)) / dig;
            }
            ans ^= lastans;
        }
    }
    printf("%lld\n", ans);
    return 0;
}