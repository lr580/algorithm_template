#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll a, b, m, t, phi, ans = 1;
char c; bool flag;
signed main()
{
  scanf("%d%d", &a, &m);
  t = phi = m;
  for (ll i = 2; i * i <= m; ++i) if (t % i == 0)
  {
    phi = phi - phi / i;
    while (t % i == 0) t /= i;
  }
  if (t > 1) phi = phi - phi / t;
  while (!isdigit(c = getchar()));
  for (; isdigit(c); c = getchar())
  {
    b = (b << 1) + (b << 3) + (c ^ '0');
    if (b >= phi) flag = true, b %= phi;
  }
  if (flag) b += phi;
  for (ans = 1; b; b >>= 1, a = 1LL * a * a % m) if (b & 1)
    ans = 1LL * ans * a % m;
  printf("%d", ans);
  return 0;
}
