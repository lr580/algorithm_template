#include <bits/stdc++.h>
using namespace std;
#define mn 22000010
char s[mn], ch;
int p[mn], n, ans, r, c;
signed main()
{
    s[0] = '#', s[++n] = '#';
    while (EOF != (ch = getchar()))
    {
        s[++n] = ch, s[++n] = '#';
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i <= r)
        {
            p[i] = min(p[c * 2 - i], r - i + 1);
        }
        while (s[i + p[i]] == s[i - p[i]])
        {
            ++p[i];
        }
        if (i + p[i] > r)
        {
            r = p[i] + i - 1, c = i;
        }
        ans = max(ans, p[i]);
    }
    printf("%d", ans - 1);
    return 0;
}