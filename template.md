

<hr/>
<div style="font-size:36px;font-weight:900;margin:-14px 10px" align="center">lr580's 算法模板</div>
<hr/>

![image-20220325120131181](img/image-20220325120131181.png)

<div align="center" style="font-size:18px">Last built at Mar. 25, 2022</div>

<div STYLE="page-break-after: always;"></div>

[toc]

<div STYLE="page-break-after: always;"></div>



# lr580's 算法模板

## 数学

### 公式

#### 常用符号

1. $x|y$ 表示 $x$ 整除 $y$ ，例如 $2|8$
2. $x\bot y$ 表示 $x,y$ 互质
3. $gcd(x,y)=(x,y)$ 最大公约数
4. $lcm(x,y)=[x,y]$ 最小公倍数
5. $\lfloor x\rfloor$ 向下取整
6. $\lceil x\rceil$ 向上取整
7. $C^m_n=C(n,m)=(\matrix{n\\m})=\dfrac{n!}{m!(n-m)!}$ ，若 $n < m$ 得 $0$ 
8. $A_n^m=P_n^m=P(n,m)=\dfrac{n!}{(n-m)!}=\prod_{i=n-m+1}^ni$ ，若 $n < m$ 得 $0$ 



#### 组合数学

##### 排列组合

元素依次排成一个圆圈的排列称作环排列，$S$的$r$环排列数等于$\dfrac{P(n,r)}r$

组合数性质：设正整数 $n,r$，有

- $C(n,r)=\dfrac nrC(n-1,r-1)$
- $C(n,r)=\dfrac{n-r+1}{r}C(n,r-1)$
- $C(n,r)=C(n,n-r)$
- $C(n,r)=C(n-1,r-1)+C(n-1,r)$  (Pascal公式/杨辉三角)

二项式定理 $n$ 是正整数，对一切 $x,y$ ，有：
$$
(x+y)^n=\sum_{k=0}^n\begin{pmatrix}n\\k\end{pmatrix}x^ky^{n-k}
$$

推论：

- $\sum_{k=0}^n\begin{pmatrix}n\\k\end{pmatrix}=2^n,n\in N$
- $\sum_{k=0}^n(-1)^k\begin{pmatrix}n\\k\end{pmatrix}=0,n\in N$
- $\sum_{l=0}^n\begin{pmatrix}l\\k\end{pmatrix}=\begin{pmatrix}n+1\\k+1\end{pmatrix},n,k\in N$
- $\begin{pmatrix}n\\r\end{pmatrix}\begin{pmatrix}r\\k\end{pmatrix}=\begin{pmatrix}n\\k\end{pmatrix}\begin{pmatrix}n-k\\r-k\end{pmatrix},n\ge r\ge k,n,r,k\in N$
- $\sum_{k=0}^r\begin{pmatrix}m\\k\end{pmatrix}\begin{pmatrix}n\\r-k\end{pmatrix}=\begin{pmatrix}n+m\\r\end{pmatrix},n,m,r\in N,r\le\min(m,n)$
- $\sum_{k=0}^n\begin{pmatrix}m\\k\end{pmatrix}\begin{pmatrix}n\\k\end{pmatrix}=\begin{pmatrix}m+n\\m\end{pmatrix},m,n\in N$

> 某些时候可以两边求导再求

**容斥原理：**
$$
|\bigcup_{i=1}^nS_i|=\sum_{m=1}^n(-1)^{m-1}\sum_{a_i<a_{i+1}}|\bigcap_{i=1}^mS_{a_i}|
$$
**抽屉原理：**

把 $mn+1$ 个物体放到 $n$ 个抽屉里，至少有一个抽屉至少有 $m+1$ 个物体

把 $mn-1$ 个物体放到 $n$ 个抽屉里，至少有一个抽屉至少有 $m-1$ 个物体



##### 卡特兰数

$$
c[0]=1\\
c[n+1]=\sum_{i=0}^nc[i]\cdot c[n-i-1]
$$

从 $0$ 到 $5$ 分别是 $1,1,2,5,14,42$ ，`c[35]`  为 19 位长度，`c[36]` 爆long long 
$$
c[n]=c[n-1]\times\dfrac{4n-2}{n+1}\\
c[n]=\dfrac{C(2n,n)}{n+1}\\
c[n]=C(2n,n)-C(2n,n-1)
$$
意义：

- 矩阵连乘： P=a1×a2×a3×……×an，依据乘法结合律，不改变其顺序，只用括号表示成对的乘积，试问有几种括号化的方案。h(n) 种
- 一个栈(无穷大)的进栈序列为1，2，3，…，n，有多少个不同的出栈序列
- 在一个凸多边形中，通过若干条互不相交的对角线，把这个多边形划分成了若干个三角形。任务是键盘上输入凸多边形的边数n，求不同划分的方案数 f（n）。比如当n=6时，f（6）=14。
- 给定N个节点，能构成多少种不同的二叉搜索树
- 给定n对括号，求括号正确配对的字符串数
- $2n$ 个黑白，使得前缀黑色小于白色的方案数
- 圆上 $2n$ 点用 $n$ 条不相交线段连接的方案数
- $n$ 人有 $50$ 元，$n$ 人有 $100$ 元买 $50$ 元物品，排队方案数使得 $2n$ 人都可找零



##### 斯特林数

第一类：(无符号:)将n个不同元素构成m个圆排列的数目。无符号为 $s_u(n,m)$ 或$\left[\matrix{n\\m}\right]$ ，有符号为 $s_s(n,m)$ ，分别表现升阶函数和降阶函数的各项系数。
$$
\begin{align}
x^{n\downarrow}&=x(x-1)(x-2)\dots(x-n+1)=\sum_{k=0}^ns_s(n,k)x^k\\
x^{n\uparrow}&=x(x+1)(x+2)\dots(x+n-1)=\sum_{k=0}^ns_u(n,k)x^k\\
s_s(n,u)&=(-1)^{n+m}s_u(n,m)\\
s_u(n+1,m)&=s_u(n,m-1)+n\cdot s_u(n,m)\\
s_s(n+1,m)&=s_s(n,m-1)-n\cdot s_s(n,m)\\
\end{align}
$$

> 例题：有n个仓库，每个仓库有两把钥匙，共2n把钥匙。同时又有n位官员。问如何放置钥匙使得所有官员都能够打开所有仓库？（只考虑钥匙怎么放到仓库中，而不考虑官员拿哪把钥匙。）那如果官员分成m个不同的部，部中的官员数量和管理的仓库数量一致。那么有多少方案使得，同部的所有官员可以打开所有本部管理的仓库，而无法打开其他部管理的仓库？（同样只考虑钥匙的放置。）
>
> 第一问就是打开将钥匙放入仓库构成一个环：1号仓库放2号钥匙，2号仓库放3号钥匙……n号仓库放1号钥匙。这种情况相当于钥匙和仓库编号构成一个圆排列方案数是$(n-1)!$种。
>
> 而第二问就对应的将n个元素分成m个圆排列，方案数就是第一类无符号Stirling数$s_u(n,m)$。如要要考虑官员的情况，只需再乘上$n!$即可。

第二类：把n+1个元素分成m个集合，记为$S(n,m)$或$\left\{\matrix{n\\m}\right\}$。
$$
\begin{align}
S(n,m)&=\frac{1}{m!}\sum_{k=0}^m(-1)^k\left(\matrix{m\\k}\right)(m-k)^n\\
S(n+1,m)&=S(n,m-1)+m\cdot S(n,m)
\end{align}
$$

递推上与第一类的区别在于$m$还是$n$作系数和正负问题。

求斯特林数，可以套用公式二，使用 $dp$ 。注意到初始状态是$S(n,1)=S(n,n)=1$ 。



##### 球盒问题

| 球区别 | 盒区别 | 空盒 | 模型       | 方案计数                                        |
| ------ | ------ | ---- | ---------- | ----------------------------------------------- |
| 有     | 有     | 有   | 选取       | $m^n$                                           |
| 有     | 有     | 无   | 放球       | $m!\left\{\matrix{n\\m}\right\}$                |
| 有     | 无     | 有   | 放球       | $\sum_{k=1}^m\left\{\matrix{n\\k}\right\}$      |
| 有     | 无     | 无   | 放球       | $\left\{\matrix{n\\m}\right\}$                  |
| 无     | 有     | 有   | 不定方程   | $C_{n+m-1}^n$                                   |
| 无     | 有     | 无   | 不定方程   | $C_{n-1}^{m-1}$                                 |
| 无     | 无     | 有   | 正整数拆分 | $G(x)=\frac1{\prod_{i=1}^m(1-x^i)},x^n$系数     |
| 无     | 无     | 无   | 正整数拆分 | $G(x)=\frac{x^m}{\prod_{i=1}^m(1-x^i)},x^n$系数 |



#### 复杂度

若递归算法存在分治递推式：
$$
T(n)=\begin{cases}c&n=1\\aT(\dfrac nb)+cn^k&n>1\end{cases}
$$
其中 $a,b,c,k$ 是常数，$T(n)$ 是非递减函数，则：
$$
T(n)=\begin{cases}\Omicron(n^{\log_ba})&a>b^k\\
\Omicron(n^k\log_bn)&a=b^k\\
\Omicron(n^k)&a<b^k\end{cases}
$$

注： $b=1$ 不适用，这是因为 $T(n)=aT(n)+cn^k$ 显然是死循环



常用复杂度对 $10^8$ ：$n!(n=11),2^n(n=26),n^3(n=464),n^2\log n(n=3000,n\log n(n=4.5\times10^6)$



#### 数列

> A.P.   Arithmetic progression

$$
a_n=a_1+(n-1)d=a_m+(n-m)d
$$

$$
d=\dfrac{a_m-a_n}{m-n}
$$

$$
\begin{align}
S_n&=\dfrac{n(a_1+a_n)}2\\
&=\dfrac{n(a_m+a_{n-m+1})}2\\
&=na_1+\dfrac{n(n-1)}2d\\&=\dfrac d2n^2+(a_1-\dfrac d2)n\\&=na_{\frac{n+1}2}
\end{align}
$$

部分性质：

1. $$
   m+n=p+q\Rightarrow a_m+a_n=a_p+a_q
   $$

2. $$
   \dfrac{a_n}{b_n}=\dfrac{S_{2n-1}}{T_{2n-1}}
   $$

3. $$
   a_n=\dfrac{S_{2n-1}}{2n-1}
   $$




> G.P.    Geometric progression

$$
a_n=a_1q^{n-1}=a_mq^{n-m}
$$

$$
q=\large{\sqrt[n-m]{\dfrac{a_n}{a_m}}}
$$

$$
S_n=\dfrac{a_1(1-q^n)}{1-q},\quad(q\neq1)
$$

部分性质：

1. $$
   m+n=p+q\Rightarrow a_m\times a_n=a_p\times a_q
   $$

2. $$
   S_{n+m}=S_m+q^mS_n
   $$



求和公式：
$$
\begin{align}
\sum_{i=1}^ni&=\dfrac{n(n+1)}2\\
\sum_{i=1}^ni^2&=\dfrac{n(n+1)(2n+1)}2\\
\sum_{i=1}^ni^3&=\left(\dfrac{n(n+1)}2\right)^2
\end{align}
$$


$$
\sum_{i=1}^n\dfrac1i\approx0.57722+\ln n\\
\sum_{i=1}^\infty\left(\dfrac1k\right)^i=\dfrac1{k-1}
$$

求 $a_n$ ：

- $a_{n+1}=pa_n+q$ 构造新数列，使得 $b_{n+1}=pb_n$

- $a_{n+1}=a_n+f(n)$ 累加法

- $a_{n+1}=a_n\cdot f(n)$ 累乘法

- $a_{n+1}=\dfrac{pa_n}{ka_n+m}$ 倒数法，令 $b_n=a_n^{-1}$

- $\overline{k},\overline{kk},\overline{kkk}\cdots$ $a_n=\dfrac k9(10^n-1)$

- $a,b,a,b,\cdots$ $a_n=\dfrac{a+b+(-1)^n(b-a)}2$

求 $S_n$ ：

- 裂项相消 $b_n=\dfrac1{a_n\cdot a_{n+k}},a_n\in A.P.$

- 错位相减 $c_n=a_n\cdot b_n,a_n\in A.P.,b_n\in G.P.$
  $$
  (1-q)S_n=a_1b_1-a_nb_{n+1}+\dfrac{db_2}{1-q}(1-q^{n-1})
  $$
  $c_n=(an+b)q^{n-1}$ ，则 $S_n=(An+B)q^n-B$ ，其中 $A=\dfrac a{q-1},B=\dfrac{b-A}{q-1}$

- 分组求和

- 倒序相加



### 数论

#### 拓展欧几里得定理

求下列关于$x,y$的不定方程的一组可行解：($a,b,x,y$都是整数)
$$
ax+by=(a,b)
$$
费马小定理又称贝祖定理（Bézout's lemma）,设 $a,b\in\Z,ab\neq0$ ,则 $\exist x,y\in\Z$：
$$
ax+by=(a,b)
$$

```c++
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
} // 或 exgcd(b, a % b, y, x); y -= a / b * x;
```

循环：

```c++
ll gcd(ll a, ll b, ll &x, ll &y)
{
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
```







### 计算几何



## 数据结构



## 字符串







## 杂项

### 排序

归并、计数、基数是稳定排序。

#### 计数排序

参考代码：(设值域是 $[1,k]$ 的整数)

```c++
for (int i = 1; i <= n; ++i)
{
    ++c[a[i]]; // c 初始值均 0; a 数组使用下标范围 [1,n] 存值
}
for (int i = 1; i <= k; ++i) // k 是 a 的最大值
{
    for (int j = 1; j <= c[i]; ++j)
    {
        a[++p] = i; // p 初始值为 0
    }
}
```

前缀和写法：

```c++
for (int i = 1; i <= n; ++i)
{
    ++cnt[a[i]];
}
for (int i = 1; i <= k; ++i)
{
    cnt[i] += cnt[i - 1];
}
for (int i = n; i >= 1; --i) //顺着i到n遍历也行
{
    b[cnt[a[i]]--] = a[i];
}
```



#### 基数排序

以下代码以 $1\le n\le8\times 10^6$ ，值域在 $2^{31}$ ， $q$ 次询问排序后位置为例(下标从 $1$ 开始) (SCNUOJ 1577)

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define il inline
il ll read()
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
```



#### 归并求逆序对

参考代码：(洛谷P1908)

```c++
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
```



### 高精度

#### C++

以下给出高精度之间的、带负数的加减乘除模运算 (洛谷P1932)：

其中高精度间乘法复杂度是 $O(n^2)$ ，高精度间除法使用二分答案，复杂度大概是 $O(n\log n)$

```c++
// luogu-judger-enable-o2 
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cassert>

typedef int i32;
typedef unsigned u32;
typedef unsigned long long u64;

struct BigInt
{
    const static u32 exp = 9;
    const static u32 mod = 1000000000;

    static i32 abs_comp(const BigInt &lhs, const BigInt &rhs)
    {
        if (lhs.len != rhs.len)
            return lhs.len < rhs.len ? -1 : 1;
        for (u32 i = lhs.len - 1; ~i; --i)
            if (lhs.val[i] != rhs.val[i])
                return lhs.val[i] < rhs.val[i] ? -1 : 1;
        return 0;
    }

    u32 *val, len, sgn;

    BigInt(u32 *val = nullptr, u32 len = 0, u32 sgn = 0) : val(val), len(len), sgn(sgn) {}

    // copy_to cannot guarantee val[x] == 0 for x >= len
    // other function should set (the position they assume to be zero) as zero
    void copy_to(BigInt &dst) const
    {
        dst.len = len, dst.sgn = sgn;
        memcpy(dst.val, val, sizeof(u32) * len);
    }

    void trim()
    {
        while (len && !val[len - 1])
            --len;
        if (len == 0)
            sgn = 0;
    }

    void add(BigInt &x)
    {
        if (sgn ^ x.sgn)
            return x.sgn ^= 1, sub(x);
        val[len = std::max(len, x.len)] = 0;
        for (u32 i = 0; i < x.len; ++i)
            if ((val[i] += x.val[i]) >= mod)
                val[i] -= mod, ++val[i + 1];
        for (u32 i = x.len; i < len && val[i] >= mod; ++i)
            val[i] -= mod, ++val[i + 1];
        if (val[len])
            ++len;
    }

    void sub(BigInt &x)
    {
        if (sgn ^ x.sgn)
            return x.sgn ^= 1, add(x);
        if (abs_comp(*this, x) < 0)
            std::swap(*this, x), sgn ^= 1;
        val[len] = 0;
        for (u32 i = 0; i < x.len; ++i)
            if ((val[i] -= x.val[i]) & 0x80000000)
                val[i] += mod, --val[i + 1];
        for (u32 i = x.len; i < len && val[i] & 0x80000000; ++i)
            val[i] += mod, --val[i + 1];
        trim();
    }

    void mul(BigInt &x, u32 *ext_mem)
    {
        assert(this != &x);
        memcpy(ext_mem, val, sizeof(u32) * len);
        memset(val, 0, sizeof(u32) * (len + x.len));
        for (u32 i = 0; i < len; ++i)
            for (u32 j = 0; j < x.len; ++j)
            {
                u64 tmp = (u64)ext_mem[i] * x.val[j] + val[i + j];
                val[i + j] = tmp % mod;
                val[i + j + 1] += tmp / mod;
            }
        len += x.len, sgn ^= x.sgn;
        trim();
    }

    void mul(u32 x)
    {
        if (x & 0x80000000)
            x = -x, sgn ^= 1;
        u64 carry = 0;
        for (u32 i = 0; i < len; ++i)
        {
            carry += (u64)val[i] * x;
            val[i] = carry % mod;
            carry /= mod;
        }
        if (carry)
            val[len++] = carry;
        trim();
    }

    void div(BigInt &x, BigInt &remainder, u32 *ext_mem)
    {
        assert(this != &x && this != &remainder);
        copy_to(remainder), memset(val, 0, sizeof(u32) * len);
        u32 shift = len - x.len;
        if (shift & 0x80000000)
            return void(len = sgn = 0);
        while (~shift)
        {
            u32 l = 0, r = mod;
            BigInt mul_test{ext_mem}, remainder_high{remainder.val + shift, remainder.len - shift};
            while (l <= r)
            {
                u32 mid = (l + r) / 2;
                x.copy_to(mul_test), mul_test.mul(mid);
                abs_comp(mul_test, remainder_high) < 0 ? l = mid + 1 : r = mid - 1;
            }
            val[shift] = r;
            x.copy_to(mul_test), mul_test.mul(r);
            remainder_high.sub(mul_test), remainder.trim();
            --shift;
        }
        sgn ^= x.sgn;
        trim();
    }

    void div(u32 x)
    {
        if (x & 0x80000000)
            x = -x, sgn ^= 1;
        u64 carry = 0;
        for (u32 i = len - 1; ~i; --i)
        {
            carry = carry * mod + val[i];
            val[i] = carry / x;
            carry %= x;
        }
        trim();
    }

    void read(const char *s)
    {
        sgn = len = 0;
        i32 bound = 0, pos;
        if (s[0] == '-')
            sgn = bound = 1;
        u64 cur = 0, pow = 1;
        for (pos = strlen(s) - 1; pos + 1 >= exp + bound; pos -= exp, val[len++] = cur, cur = 0, pow = 1)
            for (i32 i = pos; i + exp > pos; --i)
                cur += (s[i] - '0') * pow, pow *= 10;
        for (cur = 0, pow = 1; pos >= bound; --pos)
            cur += (s[pos] - '0') * pow, pow *= 10;
        if (cur)
            val[len++] = cur;
    }

    void print()
    {
        if (len)
        {
            if (sgn)
                putchar('-');
            printf("%u", val[len - 1]);
            for (u32 i = len - 2; ~i; --i)
                printf("%0*u", exp, val[i]);
        }
        else
            putchar('0');
        puts("");
    }
};

const int N = 1e4 + 20;
u32 a_[N], b_[N], r_[N], tmp[N * 2];
char sa[N], sb[N];

int main()
{
    scanf("%s%s", sa, sb);
    {
        BigInt a{a_}, b{b_};
        a.read(sa), b.read(sb), a.add(b), a.print();
    }
    {
        BigInt a{a_}, b{b_};
        a.read(sa), b.read(sb), a.sub(b), a.print();
    }
    {
        BigInt a{a_}, b{b_};
        a.read(sa), b.read(sb), a.mul(b, tmp), a.print();
    }
    {
        BigInt a{a_}, b{b_}, r{r_};
        a.read(sa), b.read(sb), a.div(b, r, tmp), a.print();
        r.print();
    }
}
```



#### FFT 乘法

复杂度 $O(n\log n)$ ，可以通过 $10^6$ 数据量

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define sc(x) x = read()
#define mn ((1 << 21) + 1)
ll n1, n2, rev[mn], ans[mn], k, s = 1, len, n;
db pi = acos(-1), v;
typedef complex<db> cp;
cp a[mn], b[mn];
char s1[mn], s2[mn];
void fft(cp *a, ll n, ll flag)
{
    for (ll i = 0; i < n; ++i)
    {
        if (i < rev[i])
        {
            swap(a[i], a[rev[i]]);
        }
    }
    for (ll h = 1; h < n; h <<= 1)
    {
        cp wn = exp(cp(0, flag * pi / h));
        for (ll j = 0; j < n; j += h << 1)
        {
            cp w(1, 0);
            for (ll k = j; k < j + h; ++k)
            {
                cp x = a[k], y = w * a[k + h];
                a[k] = x + y;
                a[k + h] = x - y;
                w *= wn;
            }
        }
    }
    if (flag == -1)
    {
        for (ll i = 0; i < n; ++i)
        {
            a[i] /= n;
        }
    }
}

signed main()
{
    scanf("%s%s", s1, s2);
    n1 = strlen(s1), n2 = strlen(s2), n = max(n1, n2);
    for (ll i = 0; i < n1; ++i)
    {
        a[i] = (db)(s1[n1 - i - 1] - '0');
    }
    for (ll i = 0; i < n2; ++i)
    {
        b[i] = (db)(s2[n2 - i - 1] - '0');
    }
    k = 1, s = 2;
    while ((1 << k) < (n << 1) - 1)
    {
        ++k, s <<= 1;
    }
    // while (s <= n)
    // {
    //     s <<= 1, ++k;
    // }
    for (ll i = 0; i < s; ++i)
    {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
    }
    fft(a, s, 1), fft(b, s, 1);
    for (ll i = 0; i <= s; ++i)
    {
        a[i] *= b[i];
    }
    fft(a, s, -1);
    for (ll i = 0; i < s; ++i)
    {
        ans[i] += (ll)(a[i].real() + 0.5);
        ans[i + 1] += ans[i] / 10, ans[i] %= 10;
    }
    while (!ans[s] && s > -1)
    {
        --s;
    }
    if (s == -1)
    {
        puts("0");
    }
    else
    {
        for (ll i = s; i >= 0; --i)
        {
            printf("%lld", ans[i]);
        }
    }
    return 0;
}
```



#### java 高精度

`java.math.BigInteger`,`java.math.BigDecimal` 高精度运算 JAVA8为例

构造函数只能传字符串。可以直接输出。

`BigInteger` 方法：(注意不会改变lhs本身,需要用新变量存结果)

- add, subtract, multiply, divide
- remainder 取模
- divideAndRemainder 返回数组，第一个是商，第二个是余
- pow(指数是int不是BigInteger) (应该不是快速幂)
- negate 相反数
- shiftLeft 左移<<(负数右移) 参数是int
- shiftRight 右移>>(负数左移) 参数是int
- and or 位运算
- compareTo
- equals 参数rhs是Ojbect
- min,max
- isProbablePrime(值) 值越大，得到的结果越准确
- toString(进制) 可以返回16进制字符串

`BigDecimal` 方法：

- add subtract multiply divide

divide的设置方法处理小数位：

- ROUND_UP 商的最后一位大于0时向前进位，正负号均如此
- ROUND_DOWN 商的最后一位忽略
- ROUND_CEILING 正up负down 故近似值$\ge$实际值
- ROUND_FLOOR 负up正down 故近似值$\le$实际值
- ROUND_HALF_DOWN 商四舍五入$\le5$舍弃否则进位
- ROUND_HALF_UP $<$5舍弃否则进位
- ROUND_HALF_EVEN 商倒数第二位奇数halfup否则halfdown

要调用，三个参数，第一个是rhs,第二个是商小数点保留位数，第三个是处理方式，如 `BigDecimal.ROUND_UP`

```java
import java.util.Scanner; // 洛谷P1932
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger a = new BigInteger(sc.next());
        BigInteger b = new BigInteger(sc.next());
        System.out.println(a.add(b));
        System.out.println(a.subtract(b));
        System.out.println(a.multiply(b));
        System.out.println(a.divide(b));
        System.out.println(a.mod(b));
        sc.close();
    }
}
```

除法必须规定位数(java9后当前函数会报 warning)，如：

```java
BigDecimal a = new BigDecimal(sc.next());
BigDecimal b = new BigDecimal(sc.next());
System.out.println(a.divide(b, 2, BigDecimal.ROUND_HALF_DOWN));
```



#### python 高精度

以例子说明：(正常使用四则运算，输入输出和格式化，设置精度即可)

```python
from decimal import *
getcontext().prec = 20
x = Decimal('1')
y = Decimal('7.0')
print((x / y * y * y).quantize(Decimal('0.00'), ROUND_HALF_DOWN))
#第二个参数可以不填
```

> 精度：(官方文档)
>
> ROUND_CEILING (towards Infinity),
> ROUND_DOWN (towards zero),
> ROUND_FLOOR (towards -Infinity),
> ROUND_HALF_DOWN (to nearest with ties going towards zero),
> ROUND_HALF_EVEN (to nearest with ties going to nearest even integer),
> ROUND_HALF_UP (to nearest with ties going away from zero), or
> ROUND_UP (away from zero).
> ROUND_05UP (away from zero if last digit after rounding towards zero would have been 0 or 5; otherwise towards zero)



### 程序语法

#### 常规运算

- `__int128` $[-2^{127},2^{127}-1]$ ， $16$ 字节，其中 $2^{127}\approx8.5\times10^{37}$
- `double` 有效位数约 $15$ 位， $8$ 字节，范围约为 $[-1.79\times10^{308},1.79\times10^{308}]$
- `long double` 通常有效位数约 $20$ 位，$16$ 字节，范围约为 $[-1.2\times10^{4932},1.2\times10^{4932}]$

注意：

- 浮点数除，被除数为 $0$ ，被除数和除数存在一个负数，结果为负零
- 取模只可以是整型之间的；负数运算结果等于取绝对值计算，最后正负号与被除数一致，如 $(-5)\bmod 3=-2,5\bmod (-3)=2$  (JAVA同)

> Python : `-17%10=-7,17%-10=7,-17%-10=-7` (除时取取比实际结果稍小的最大整数)

整数上取整公式：
$$
\lceil\dfrac ab\rceil=\dfrac{a+b-1}b=\dfrac{a-1}b+1
$$



#### 位运算

异或的性质：

- 交换律、结合律、消去律，有单位元$0$，自己与自己运算得单位元

- $a\oplus b\le a+b=(a|b)+(a\&b)$ 

  前半句：因异或是不进位的加法；后半句：因 $a\&b$ 是进位部分



注意要点：

- 优先级： `~; +, -; <<, >>; ==, !=; &; ^; |; &&; ||; ?:`
- 移位结果为 ll 时应该是 `1LL << k`
- 右移位，等同于round(x/2.0)，负数的移位结果不会大于-1



常见应用：

- 取正数 `x` 的从左往右(从零数)第 `i` 位：`(x>>i)&1`

- 对某个正数 `x` 从左往右(从零数)第 `k` 位修改取反： `x^=(1<<k)`

- `c&15`  或 `c^'0'` 优化 数字字符转数值

- > `~` 运算仅对 $-1$ 得 $0$ ，可以用于递减到 0 的循环枚举常数优化

- 交换两个数 `a^=b^=a^=b`



内建函数：

- 注：对 `unsigned long long` 每个函数名后面加上 `ll`

**1.__builtin_popcount(unsigned int n)**

该函数时判断n的二进制中有多少个1

```c
int n = 15; //二进制为1111
cout<<__builtin_popcount(n)<<endl;//输出4
```

**2.__builtin_parity(unsigned int n)**
该函数是判断n的二进制中1的个数的奇偶性

```c
int n = 15;//二进制为1111
int m = 7;//111
cout<<__builtin_parity(n)<<endl;//偶数个，输出0
cout<<__builtin_parity(m)<<endl;//奇数个，输出1
```

**3.__builtin_ffs(unsigned int n)**
该函数判断n的二进制末尾最后一个1的位置，从一开始

```c
int n = 1;//1
int m = 8;//1000
cout<<__builtin_ffs(n)<<endl;//输出1
cout<<__builtin_ffs(m)<<endl;//输出4
```

**4.__builtin_ctz(unsigned int n)**
该函数判断n的二进制末尾后面0的个数，当n为0时，和n的类型有关

```c
int n = 1;//1
int m = 8;//1000
cout<<__builtin_ctzll(n)<<endl;//输出0
cout<<__builtin_ctz(m)<<endl;//输出3
```

**5. __builtin_clz (unsigned int x)**
返回前导的0的个数。

```c++
int n = 1;	//1
int m = 8;	//1000
cout<< 32 - __builtin_clz(n) <<endl;	//输出1
cout<< 64 - __builtin_clzll(m) <<endl;	//输出4
```



#### 指针

```c++
指针数组 int *p[3];
指向二维数组的指针(第二维为3) int (*p)[3];//即列指针
```

```c++
#include <stdio.h>
int fx(int x)
{
    return x*x;
}
int add(int x, int y)
{
    return x*y;
}
int h(int (*f)(), int a, int b)
{
    return f(a,b);
}
signed main()
{
    int (*g)();
    g=fx;
    printf("%d\n",g(5));
    printf("%d",h(add,5,-1));
    return 0;
}
```

```c++
例如：void f(int n, int (*compare)(int a, int b));
int g(int a, int b);
使用时：g(3, f);
```



#### I/O

cout 输出小数： `cout<<setprecision(n)`

cout 输出不同进制： 

```c++
cout<<hex<<17<<endl;
cout<<dec<<18<<endl;
cout<<oct<<9<<endl;
cout<<bitset<sizeof(unsigned long) * 8>(1UL << 27)<<endl;
```



#### 其他

decltype

```c++
int x;
decltype((x)) z;//z为int & ,da ck
decltype(x) y;//y为int
typedef decltype(f(x)+g(x)) dt;
dt var1;
```

使用了万能头时，不允许使用这些变量名：`y1` , `y0` , `yn` , `prev` , `tm` 等 



### STL

#### 函数

##### xx_bound

bound函数，参数`起始迭代器,终止迭代器,值` ，二分查找`[起,止)`

**upper_bound** 大于 x 的第一个位置

**lower_bound** 大于等于 x 的第一个位置



对升序序列：

`lower_bound(begin, end, v)`  在 $[begin,end)$ 找第一个大于等于 $v$ 的值，返回该值的迭代器

`upper_bound(begin, end, v)`  在 $[begin,end)$ 找第一个大于 $v$ 的值，返回该值的迭代器

若找不到返回 $end$



对降序序列：

`lower_bound(begin, end, v, greater<type>())`  在 $[begin,end)$ 找第一个小于等于 $v$ 的值，返回该值的迭代器

`upper_bound(begin, end, v, greater<type>())`  在 $[begin,end)$ 找第一个小于 $v$ 的值，返回该值的迭代器

若找不到返回 $end$



以二分搜索向左第一个数为例：

```c++
int d = lower_bound(a,a+n,f)-a;
if(f!=a[d]) printf("-1");
else printf("%d", d+1);
```

默认对非降序列使用，如果要对下降序列使用，需要加greater如下(指针写法)：

```c++
*upper_bound(d1+1,d1+1+len1,a[i],greater<int>())=a[i];
```

二分查找值区间 $[a,b]$ 长：`u(,,b)-l(,,a)`



##### 字符串

C 风格字符串

常用函数：

- `cin.getline(char* s, int len)` 读整行
- `strcat(char* s1, char* s2)` $s1=s1+s2$ 
- `strstr(char* s1, char* s2)` 在主串 $s1$ 进行模式匹配 ，返回首个匹配成功地址或 `NULL` 
- `strchr(char* s1, char s2)` 模式匹配
- `strchr(char* s1, char s2)` 模式匹配(从右开始)
- `strtok(char* s1, const char* sep)` 子串分割(用法见下方示例代码)



##### 正则表达式

```c++
char data[] = "he...ll..o, worl..d!";
std::regex reg("\\.");
std::cout << std::regex_replace(data, reg, "");
```

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string s, t;
signed main()
{
    scanf("%lld%*c", &n);
    while (n--)
    {
        getline(cin, s);
        cin >> t;
        cin.ignore();
        regex reg("\\b" + t + "\\b");
        smatch m;
        auto lf = s.cbegin(); // begin(),end()参数不匹配
        auto rf = s.cend();
        ll ans = 0;
        for (; regex_search(lf, rf, m, reg); lf = m.suffix().first)
            ++ans;
        cout << ans << '\n' ;
    }
    return 0;
}
```



##### 随机数

```c++
#include <iostream>
#include <chrono>
#include <random>
using namespace std;
int main()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	mt19937 rand_num(seed);
	uniform_int_distribution<long long> dist(0, 1000000000);
	cout << dist(rand_num) << endl;
	return 0;
}
```



##### 杂项

**unique** : 排序后使用，返回去重后下界。

```c++
ll m = unique(a + 1, a + 6) - (a + 1);
```

**nth\_element** : (a,a+k,a+n); 使容器a+k所在元素左边都小于它，右边都大于它(a+k通常移位)

**partial\_sort** : 保证\[lf,cf)有序，\[cf,rf\]按本来的相对顺序。

```c++
partial_sort(lf,cf,rf);
```

**stable_sort** : 用法同 `std::sort` ，区别在于是稳定排序

**advance**：使迭代器前进n个元素，适用于所有迭代器，第一个参数是迭代器引用，第二个参数是整数距离，表示前进或后退的单位(正负控制)。

**max\_element** : 返回首个最大元素所在位置迭代器

**inplace\_merge** : (lf,cf,rf,cmp) 对 $(lf,cf]$ 和 $(cf,rf)$ 就地归并排序 

**merge** : (lf1, rf1, lf2, rf2, res, cmp) 归并排序并放到结果迭代器

**random\_shuffle** : 打乱元素(传入首尾迭代器)



#### 数据结构

##### string

构造函数

```c++
string two(20, '*');
string five(one, 10);
string six(one+1,one+10);
string eight(one, 1, 16);
```

常用方法：(复杂度都是暴力实现的复杂度)

- `substr(int start[, int len])` 从下标 start 开始截长度len的子串

- `append(string s)` 或 `push_back(char c)` 末尾增加，等效于 `+=`  

- `find(char/string s, start=0)` 从 start 下标开始找第一个出现的子串，返回出现下标或 $-1$

  此外还有 `find_first_of` , `find_last_of` , `find_first_not_of` , `find_last_not_of` 

- `substr(int start[, int len])` 从 start 下标开始截长为 len 的子串(缺省则截到尾)

- `erase(int pos, int n)` 删除 pos 下标开始的 n 个字符

- `insert(int pos, string s)` 在 pos 位置插入字符串 s 

- `append(string s, int pos, int n)` 等于 `append(s.substr(pos,n))` 

- `back()` 取最后一个字符

常用函数：

- `reverse(首迭代器, 尾迭代器)` 反转传入的字符串
- `getline(cin, string)` 读整行(注意跟 `cin.getline` 区分)
- `to_string(any)` 其它数值类型转 `std::string` (注：char 会视为 int，不能传C风格字符串)
- `stoi` , `stol` , `stof` , `stod` ，字符串转 `int, long long, float, double`
- `lexicographical_compare(迭代器a首, 迭代器a尾, 迭代器b首, 迭代器b尾)` 字典序比较两容器(不一定是字符串)
- `replace(首迭代器, 尾迭代器, 待替换字符, 替换成的字符)` 批量替换
- `count(首迭代器, 尾迭代器, 字符)` 字符出现次数统计



##### vector

```c++
vector<数据类型>变量名 {元素数};
vector<数据类型>变量名 (长度);
vector<数据类型>变量名 (长度, 初始值);
vector<数据类型>变量名 = 变量名2;
vector<数据类型>变量名(变量名2);
```

多维：

```c++
vector<vector<int> > x(10, vector<int>(20));
vector< vector< vector<int> > > x(5,vector<vector<int>>(8,vector<int>(10)));
vector< vector< vector<int> > > x(5,vector<vector<int>>(8,vector<int>(10, 1)));
//1是初始值
vector< vector< vector<int> > > vector_3D_5(n，vector_2D_4);                                   
vector< vector< vector<int> > > vector_3D_5(n);
//仅仅指定一维大小。当然二维也可以这样的。
vector<vector<vector<vector<int>>>>  x(3,vector<vector<vector<int>>>(5,vector< vector<int>>(7,vector<int>(10,1))));
```

resize(size, value)方法改变大小并初始化，默认value0

copy(a.begin(),a.end(),b.begin())，注意b要有足够的空间，可以初始化时给。

emplace_back()在容器尾部添加一个元素，这个元素原地构造，不需要触发拷贝构造和转移构造。而且调用形式更加简洁，直接根据参数初始化临时对象的成员。(当然int之类的也能用)

rbegin(),rend()可以进行反向输出。(返回reverse_iterartor)

```c++
for(auto p = a.rbegin();p != a.rend();p++) cout<<*p<<endl;
```

front()方法返回首元素的引用，例如：c.front() = 3;

back()方法同理

insert(p, value)插入 O(n)

insert(p, b1, b2);将[b1,b2]内元素插入到p位置前面

erase(p)删除 也可以用诸如x.end()-1;O(n) 

erase(p, q)删除区间[p,q)的元素

> 如：erase(s.begin(),s.begin()+2)删除头两个元素。



##### set

想要元素可变尝试设置结构体/类成员属性为 `mutable` 。

可以set<类型> var{数组, 数组+len}来获取数组的set化

insert(sp, se)方法植入闭区间

erase(元素值)方法

erase(迭代器)方法 ，如x.end()

find()有，返回迭代器，无，返回末尾end()

并集set_union(Ab, Ae, Bp, Be, 输出迭代器)//algorithm

交集set_intersection

差set_difference



##### map

count方法：若有查找key，返回1，否则0

erase(key)

pair<key类型,value类型> target = \*T.find(key)  //注意区分[]



##### bitset

```c++
bitset<位数> var;
bitset<d> s1(12);
string str="100110";
bitset<d> s2(str);
//如果是整型，那么填充时会自动转换为二进制，如果是字符串，但是其中出现了 0/1 以外的字符，就会爆炸
```

方法：

1. 基本的位操作，如：$s|=s<<w[i];$
2. .count()计算1的个数
3. .any()是否存在1
4. .none()是否不存在1
5. .set()全设为1
6. .reset()全设为0
7. .flip()按位取反

上述函数可以传一个参数，则只对该位操作



##### tuple

直接用 `{}` 构造

取出(如 `map` 迭代器里的可能要先 `second` 一下)，然后用 `tie(a,b,c)=tuple变量` 的方法获得每个元素



##### 其他

list

双向链表

deque

array, valarray



#### pb_ds

```c++
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
__gnu_pbds::tree<类型, __gnu_pbds::null_type, less<类型>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> 变量名;
```

- `order_of_key(x)` 返回值 $x$ 在 `set` 的下标
- `find_by_order(x)` 返回下标为 $x$ 的迭代器

使用示例：(洛谷P6136)

> 题意：输入 $n,m(1\le n\le10^5,1\le m\le10^6)$ ，输入 $a_i(0\le a_i < 2^{30})$ ，接下来有 $6$ 种在线操作 ( $x=x\oplus last$ )：
>
> 1. 插入整数 $x(0\le x < 2^{30})$
> 2. 删除整数 $x$ (若有多个相同，只删一个)
> 3. 查询整数 $x$ 的排名(比它小的数个数 $+1$ )
> 4. 查询排名为 $x$ 的数(不存在时查小于 $x$ 的最大数，保证 $x$ 不越当前界)
> 5. 求 $x$ 前驱(小于 $x$ 的最大的数)
> 6. 求 $x$ 后继(大于 $x$ 的最小的数)

```c++
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
```





### 卡常

#### 快读/写

关闭同步流略。好看版快读：

```c++
ll read()
{
    ll num = 0;
    char c = getchar(), up = c;
    while (c < '0' || c > '9')
        up = c, c = getchar();
    while (c >= '0' && c <= '9')
        num = (num << 1) + (num << 3) + (c ^ '0'), c = getchar();
    return up == '-' ? -num : num;
}
```

位运算快读：

```c++
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
```

快写：

```c++
void write(ll x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
    {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}
```

更快的读写：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
const ll MAXSIZE = 1 << 20;
char buf[MAXSIZE], *p1, *p2;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) ? EOF : *p1++)
inline ll rd()
{
    ll x = 0, f = 1;
    char c = gc();
    while (!isdigit(c))
    {
        if (c == '-')
            f = -1;
        c = gc();
    }
    while (isdigit(c))
        x = x * 10 + (c ^ 48), c = gc();
    return x * f;
}
char pbuf[1 << 20], *pp = pbuf;
inline void push(const char &c)
{
    if (pp - pbuf == 1 << 20)
        fwrite(pbuf, 1, 1 << 20, stdout), pp = pbuf;
    *pp++ = c;
}
inline void write(ll x)
{
    if (x < 0)
        x = -x, push('-');
    static ll sta[35];
    ll top = 0;
    do
    {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top)
        push(sta[--top] + '0');
}
signed main()
{
    ll a = rd(), b = rd();
    write(a + b);
    fwrite(pbuf, 1, pp - pbuf, stdout);
    return 0;
}
```





Python:

```python
import sys
input = sys.stdin.readline
print = sys.stdout.write # 仅字符串输出
```

Java:





#### 其他

```c++
#pragma GCC optimize(2)
```

