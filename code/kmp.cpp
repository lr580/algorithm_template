#include <bits/stdc++.h> //题目https://oj.socoding.cn/p/1713
using namespace std;
typedef long long ll;
#define mn 2000010
char s[mn], t[mn];
ll kmp[mn], ns, nt, cnt;
signed main()
{
    scanf("%s%s", s + 1, t + 1);
    ns = strlen(s + 1), nt = strlen(t + 1);
    for (ll i = 2, j = 0; i <= nt; ++i)
    {
        while (j > 0 && t[j + 1] != t[i])
        {
            j = kmp[j];
        }
        if (t[j + 1] == t[i])
        {
            ++j;
        }
        kmp[i] = j;
    }
    for (ll i = 1, j = 0; i <= ns; ++i)
    {
        while (j > 0 && t[j + 1] != s[i])
        {
            j = kmp[j];
        }
        if (t[j + 1] == s[i])
        {
            ++j;
        }
        if (j == nt)
        {
            ++cnt;
            printf("%lld ", i - j + 1);
            j = kmp[j];
        }
    }
    if (cnt == 0)
    {
        printf("-1");
    }
    return 0;
}