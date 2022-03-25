#include <bits/stdc++.h> //例题 https://oj.socoding.cn/p/1577
using namespace std;
typedef int ll;
ll read()
{
    char p = 0;
    ll r = 0, o = 0;
    for (; p < '0' || p > '9'; o |= p == '-', p = getchar())
        ;
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar())
        ;
    return o ? (~r) + 1 : r;
}
#define sc(x) x = read()
#define mn 8000010
ll n, a[mn], q, x, b[mn], cnt[1 << 8];
void radixsort(ll n)
{
    ll mask = (1 << 8) - 1;
    ll *x = a, *y = b;
    for (ll i = 0; i < 32; i += 8) //每八位每八位拆分，int拆为四个关键字
    {
        for (ll j = 0; j != (1 << 8); ++j) //[0,255)
        {
            cnt[j] = 0; //计数排序归零
        }
        for (ll j = 0; j != n; ++j)
        {
            ++cnt[x[j] >> i & mask]; //当前的八个位，注意位运算优先级
        }
        for (ll sum = 0, j = 0; j != (1 << 8); ++j)
        { //计数排序变式，cnt代表同值元素段的开头下标;即减去前缀和前自己
            sum += cnt[j], cnt[j] = sum - cnt[j];
        }
        for (ll j = 0; j != n; ++j)
        { //计数排序变式
            y[cnt[x[j] >> i & mask]++] = x[j];
        }
        swap(x, y); // y是排序好的,x是未排序的;换过来，继续操作
    }
}
signed main()
{
    sc(n);
    for (ll i = 0; i < n; ++i)
    {
        sc(a[i]);
    }
    radixsort(n);
    sc(q);
    while (q--)
    {
        sc(x);
        printf("%d\n", a[x - 1]);
    }
    return 0;
}