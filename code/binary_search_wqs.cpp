// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/
// https://oi-oj.socoding.cn/p/1069
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main()
{
    ll k, n;
    cin >> n >> k;
    vector<ll> p(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
    }
    ll lf = 1, rf = *max_element(p.begin(), p.end());
    ll ans = -1;
    while (lf <= rf)
    {
        ll cf = (lf + rf) >> 1; // 斜率
        ll buycnt = 0, sellcnt = 0;
        ll buyp = -p[0], sellp = 0;
        for (int i = 1; i < n; ++i) // 贪心
        {
            if (sellp - p[i] >= buyp)
            {
                buyp = sellp - p[i];
                buycnt = sellcnt;
            }
            if (buyp + p[i] - cf >= sellp)
            {
                sellp = buyp + p[i] - cf;
                sellcnt = buycnt + 1;
            }
        }
        // cout << cf << ' ' << sellp << ' ' << sellcnt << '\n';
        if (sellcnt >= k)
        {
            ans = sellp + k * cf; // 注意不是+sellcnt,是+k
            lf = cf + 1;
        }
        else
        {
            rf = cf - 1;
        }
    }
    if (ans == -1)
    {
        ans = 0;
        for (int i = 1; i < n; ++i)
        {
            ans += max(p[i] - p[i - 1], 0LL);
        }
    }
    cout << ans;
    return 0;
}
/*
8 3
1 100 1 4 1 4 1 4
*/