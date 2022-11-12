#include <bits/stdc++.h>
using namespace std;
#define LL long long
int read()
{
    register int x = 0;
    register int y = 1;
    register char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            y = 0;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + (c ^ 48);
        c = getchar();
    }
    return y ? x : -x;
}
unordered_map<int, int> mp;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int BSGS(int a, int n, int p, int ad)
{
    mp.clear();
    int m = ceil(sqrt(p));
    int s = 1;
    for (int i = 0; i < m; i++, s = 1ll * s * a % p)
        mp[1ll * s * n % p] = i;
    for (int i = 0, tmp = s, s = ad; i <= m; i++, s = 1ll * s * tmp % p)
        if (mp.find(s) != mp.end())
            if (1ll * i * m - mp[s] >= 0)
                return 1ll * i * m - mp[s];
    return -1;
}
int exBSGS(int a, int n, int p)
{
    a %= p;
    n %= p;
    if (n == 1 || p == 1)
        return 0;
    int cnt = 0;
    int d, ad = 1;
    while ((d = gcd(a, p)) ^ 1)
    {
        if (n % d)
            return -1;
        cnt++;
        n /= d;
        p /= d;
        ad = (1ll * ad * a / d) % p;
        if (ad == n)
            return cnt;
    }
    LL ans = BSGS(a, n, p, ad);
    if (ans == -1)
        return -1;
    return ans + cnt;
}
signed main()
{
    int a = read(), p = read(), n = read();
    while (a || p || n)
    {
        int ans = exBSGS(a, n, p);
        if (~ans)
            printf("%d\n", ans);
        else
            puts("No Solution");
        a = read();
        p = read();
        n = read();
    }
    return 0;
}