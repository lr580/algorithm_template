#include <bits/stdc++.h>
//#pragma warning(disable:6031)
#define MAXN 100002
const int BIG = 0x7fffffff;
using namespace std;
int tr[MAXN], n, m, lf, rf, a[MAXN];
inline int lowbit(int& k)
{
  return k & -k;
}
inline void add(int x, int& k)
{
  while (x <= n)
  {
    if (k < tr[x]) tr[x] = k;//这两行换成min(tr[x],k)也可
    else return;//但是那样的话会慢些
    x += lowbit(x);
  }
}
inline int query(int lf, int rf)
{
  int drt = rf, res = BIG;
  while (drt >= lf)
  {
    if (drt - lowbit(drt) > lf)
    {
      res = min(res, tr[drt]);
      drt -= lowbit(drt);
    }
    else
    {
      res = min(res, a[drt]);
      --drt;
    }
  }
  return res;
}
signed main()
{
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)//不能在下面那个for
  {
    tr[i] = BIG;
  }
  for (int i = 1; i <= n; ++i)
  {
    scanf("%d", &a[i]);
    add(i, a[i]);
  }
  while (m--)
  {
    scanf("%d%d", &lf, &rf);
    printf("%d ", query(lf, rf));
  }
  return 0;
}
