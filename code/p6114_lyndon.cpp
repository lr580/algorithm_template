#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll n, ans, i = 1, j, k;
char s[5000002];
signed main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	while (i <= n)
	{
		j = i, k = i + 1;
		while (k <= n && s[j] <= s[k]) j = s[j] == s[k++] ? j + 1 : i;
		while (i <= j) i += k - j, ans ^= i - 1;
	}
	printf("%d", ans);
	return 0;
}