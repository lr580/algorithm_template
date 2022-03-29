

<hr/>
<div style="font-size:36px;font-weight:900;margin:-14px 10px" align="center">lr580's 算法模板</div>
<hr/>

![image-20220325120131181](img/image-20220325120131181.png)

<div align="center" style="font-size:18px">Last built at Mar. 26, 2022</div>

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

多重全排列公式：
$$
P(n;r_1,r_2,\cdots, r_t)=\dfrac{n!}{r_1!r_2!\cdots r_t!}
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

### ST表

以区间 gcd 为例(时间复杂没有两个 $\log$ 乘积)

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef double db;
#define sc(x) scanf("%d", &x)
#define mn 2000010
#define lg 23
ll n, m, st[mn][lg], l, r, lg2[mn];
signed main()
{
    sc(n), sc(m);
    for (ll i = 1; i <= n; ++i)
    {
        sc(st[i][0]);
    }
    for (ll i = 2; i <= n; ++i)
    {
        lg2[i] = lg2[i / 2] + 1;
    }
    for (ll j = 1; j < lg; ++j)
    {
        for (ll i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (m--)
    {
        sc(l), sc(r);
        ll p = lg2[r - l + 1];
        ll ans = __gcd(st[l][p], st[r - (1 << p) + 1][p]);
        printf("%d\n", ans);
    }
    return 0;
}
```



### 线段树

凡是符合结合律的二目操作都可以使用线段树

#### 常见应用

##### 区间加法

> 洛谷P3372：给定长为 $n(1\le n\le10^5)$ 的序列和 $m(1\le m\le10^5)$ 次操作：
>
> 1. `1 x y k` 区间 $[x,y]$ 每个数加上 $k$
> 2. `2 x y` 输出区间 $[x,y]$ 的和

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 100010
ll t[mn << 2], laz[mn << 2], n, m, c, lc, rc, v, a[mn], ans;
#define lfs p << 1
#define rfs p << 1 | 1
#define mkcf ll cf = (lf + rf) >> 1
void build(ll p, ll lf, ll rf)
{
    if (lf == rf)
    {
        t[p] = a[lf];
        return;
    }
    mkcf;
    build(lfs, lf, cf);
    build(rfs, cf + 1, rf);
    t[p] = t[lfs] + t[rfs];
}
void pushdown(ll p, ll lf, ll rf)
{
    mkcf;
    t[lfs] += (cf - lf + 1) * laz[p];
    t[rfs] += (rf - cf) * laz[p];
    laz[lfs] += laz[p];
    laz[rfs] += laz[p];
    laz[p] = 0;
}
void update(ll p, ll lf, ll rf)
{
    if (lf >= lc && rf <= rc)
    {
        t[p] += v * (rf - lf + 1);
        laz[p] += v;
        return;
    }
    pushdown(p, lf, rf);
    mkcf;
    if (cf >= lc)
    {
        update(lfs, lf, cf);
    }
    if (cf < rc)
    {
        update(rfs, cf + 1, rf);
    }
    t[p] = t[lfs] + t[rfs];
}
void query(ll p, ll lf, ll rf)
{
    if (lf >= lc && rf <= rc)
    {
        ans += t[p];
        return;
    }
    pushdown(p, lf, rf);
    mkcf;
    if (cf >= lc)
    {
        query(lfs, lf, cf);
    }
    if (cf < rc)
    {
        query(rfs, cf + 1, rf);
    }
    //t[p] = t[lfs] + t[rfs];
}
signed main()
{
    sc(n), sc(m);
    for (ll i = 1; i <= n; ++i)
    {
        sc(a[i]);
    }
    build(1, 1, n);
    while (m--)
    {
        sc(c), sc(lc), sc(rc);
        if (c == 1)
        {
            sc(v);
            update(1, 1, n);
        }
        else
        {
            ans = 0;
            query(1, 1, n);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
```



##### 区间加乘

> 洛谷P3373，给定长为 $n(1\le n\le10^5)$ 的序列和 $m(1\le m\le10^5)$ 次操作和 $p$ ：
>
> 1. `1 x y k` 区间每个数乘 $k$
> 2. `2 x y k` 区间每个数加 $k$
> 3. `3 x y` 输出区间每个数的和对 $p$ 取模

先乘后加

```c++
#include <iostream>
#include <cstdio>
using namespace std;
int p;
long long a[100007];
//线段树结构体，v表示此时的答案，mul表示乘法意义上的lazytag，add是加法意义上的
struct node{
    long long v, mul, add;
}st[400007];
void bt(int root, int l, int r){
//初始化lazytag
    st[root].mul=1;
    st[root].add=0;
    if(l==r){
        st[root].v=a[l];
    }
    else{
        int m=(l+r)/2;
        bt(root*2, l, m);
        bt(root*2+1, m+1, r);
        st[root].v=st[root*2].v+st[root*2+1].v;
    }
    st[root].v%=p;
    return ;
}
//核心代码，维护lazytag
void pushdown(int root, int l, int r){
    int m=(l+r)/2;
//根据我们规定的优先度，儿子的值=此刻儿子的值*父亲的乘法lazytag+儿子的区间长度*父亲的加法lazytag
    st[root*2].v=(st[root*2].v*st[root].mul+st[root].add*(m-l+1))%p;
    st[root*2+1].v=(st[root*2+1].v*st[root].mul+st[root].add*(r-m))%p;
//很好维护的lazytag
    st[root*2].mul=(st[root*2].mul*st[root].mul)%p;
    st[root*2+1].mul=(st[root*2+1].mul*st[root].mul)%p;
    st[root*2].add=(st[root*2].add*st[root].mul+st[root].add)%p;
    st[root*2+1].add=(st[root*2+1].add*st[root].mul+st[root].add)%p;
//把父节点的值初始化
    st[root].mul=1;
    st[root].add=0;
    return ;
}
//update1，乘法，stdl此刻区间的左边，stdr此刻区间的右边，l给出的左边，r给出的右边
void ud1(int root, int stdl, int stdr, int l, int r, long long k){
//假如本区间和给出的区间没有交集
    if(r<stdl || stdr<l){
        return ;
    }
//假如给出的区间包含本区间
    if(l<=stdl && stdr<=r){
        st[root].v=(st[root].v*k)%p;
        st[root].mul=(st[root].mul*k)%p;
        st[root].add=(st[root].add*k)%p;
        return ;
    }
//假如给出的区间和本区间有交集，但是也有不交叉的部分
//先传递lazytag
    pushdown(root, stdl, stdr);
    int m=(stdl+stdr)/2;
    ud1(root*2, stdl, m, l, r, k);
    ud1(root*2+1, m+1, stdr, l, r, k);
    st[root].v=(st[root*2].v+st[root*2+1].v)%p;
    return ;
}
//update2，加法，和乘法同理
void ud2(int root, int stdl, int stdr, int l, int r, long long k){
    if(r<stdl || stdr<l){
        return ;
    }
    if(l<=stdl && stdr<=r){
        st[root].add=(st[root].add+k)%p;
        st[root].v=(st[root].v+k*(stdr-stdl+1))%p;
        return ;
    }
    pushdown(root, stdl, stdr);
    int m=(stdl+stdr)/2;
    ud2(root*2, stdl, m, l, r, k);
    ud2(root*2+1, m+1, stdr, l, r, k);
    st[root].v=(st[root*2].v+st[root*2+1].v)%p;
    return ;
}
//访问，和update一样
long long query(int root, int stdl, int stdr, int l, int r){
    if(r<stdl || stdr<l){
        return 0;
    }
    if(l<=stdl && stdr<=r){
        return st[root].v;
    }
    pushdown(root, stdl, stdr);
    int m=(stdl+stdr)/2;
    return (query(root*2, stdl, m, l, r)+query(root*2+1, m+1, stdr, l, r))%p;
}
int main(){
    int n, m;
    scanf("%d%d%d", &n, &m, &p);
    for(int i=1; i<=n; i++){
        scanf("%lld", &a[i]);
    }
    bt(1, 1, n);
    while(m--){
        int chk;
        scanf("%d", &chk);
        int x, y;
        long long k;
        if(chk==1){
            scanf("%d%d%lld", &x, &y, &k);
            ud1(1, 1, n, x, y, k);
        }
        else if(chk==2){
            scanf("%d%d%lld", &x, &y, &k);
            ud2(1, 1, n, x, y, k);
        }
        else{
            scanf("%d%d", &x, &y);
            printf("%lld\n", query(1, 1, n, x, y));
        }
    }
    return 0;
}
```



##### 区间查重

> SCNUOJ1454 $n$个柜子(编号从1开始)，每个柜子一开始放了一个编号为$a_i$的物品。维护下面的操作：
>
> - `1 x` 取走第$x$个柜子的物品(保证此时存在物品)
> - `2 l r` 判断$[l,r]$内的未被取走的物品是否有两个编号相同
>
> $1\le n,q\le 5\times10^5,1\le a_i\le10^6,1\le x,l\le r\le n$

思路见代码注释：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define sc(x) scanf("%d", &x)
#define mn 500010
ll n, q, a[mn], v, i;
// 维护编号为v的双向链表
ll index_before[mn]; //第i个柜子的编号上一次出现的下标 即 链表prev
ll last_pos[mn];     //v最后一次出现的下标是last_pos[v] 即链表v的尾部指针
ll index_after[mn];  //第i个柜子的编号下一次出现的下标 即 链表next

//区间[lc,rc]内不重复的充要条件是index_before[i]或index_after[i]均不在这个区间内
//任取其一判断即可，这里取index_before[i]
//合并物品，构造线段树，每个节点维护的区间代表这个区间内的编号最近会在上一次重复的下标
//只需要对区间内每个index_before取最值；显然max操作可以维护线段树
ll t[mn << 2], lc, rc, res, cmd, pos;
#define lfs p << 1
#define rfs p << 1 | 1
#define mkcf ll cf = (lf + rf) >> 1
void build(ll lf, ll rf, ll p)
{
    if (lf == rf)
    {
        t[p] = index_before[lf];
        return;
    }
    mkcf;
    build(lf, cf, lfs);
    build(cf + 1, rf, rfs);
    t[p] = max(t[lfs], t[rfs]);
}
void query(ll lf, ll rf, ll p)
{
    if (lc <= lf && rf <= rc)
    {
        res = max(res, t[p]);
        return;
    }
    mkcf;
    if (cf >= lc)
        query(lf, cf, lfs);
    if (cf < rc)
        query(cf + 1, rf, rfs);
}
void fix(ll lf, ll rf, ll p)
{
    if (lf == rf)
    {
        t[p] = v;
        return;
    }
    mkcf;
    if (cf >= pos)
        fix(lf, cf, lfs);
    else
        fix(cf + 1, rf, rfs);
    t[p] = max(t[lfs], t[rfs]);
}

signed main()
{
    sc(n), sc(q);
    for (ll i = 1; i <= n; ++i)
    {
        sc(v);
        //下面三行代码实际上在维护编号为v的双向链表
        index_before[i] = last_pos[v];
        index_after[last_pos[v]] = i;
        last_pos[v] = i;
        a[i] = v;
    }
    build(1, n, 1); //不build见祖宗
    while (q--)
    {
        sc(cmd);
        if (cmd == 2)
        {
            sc(lc), sc(rc), res = 0;
            query(1, n, 1);
            printf("%d\n", res >= lc);
        }
        else
        {
            sc(i);
            //双向链表删除节点
            lc = index_before[i], rc = index_after[i];
            if (lc)
                index_after[lc] = rc;
            if (rc)
                index_before[rc] = lc;

            //线段树修改
            //编号为0的双向链表不计重复，均头结点指向0
            pos = i, v = 0, fix(1, n, 1);
            //双向链表的后继节点指向更新 对线段树生效
            if (rc)
                pos = rc, v = lc, fix(1, n, 1);
        }
    }
    return 0;
}
```



##### 区间最值

维护操作：① 区间每个数与 $t$ 取 $\min$ ② 输出区间和 ③ 输出区间最大值

对每个节点区间：维护该区间最大值 $mx$、最大值出现次数 $se$ 、严格次大值 $cnt$ 

对操作 $1$ ：

- 若 $mx\le t$ ，整个区间都没 $t$ 大，不操作 (相等也等于没操作)
- 若 $se < t < mx$  ，那么所有最大值都变成 $t$ ，次大值和更小的值都不变，所以 $cnt$ 个 $mx$ 被删掉，再加上 $cnt$ 个 $t$ ，即区间更新 $cnt(t-mx)$ ，并记录懒标记
- 若 $t\le se$ ，递归往下处理子区间

对操作 $2,3$ ，有手就行

处理 `pushup` ：

- 若左右子区间最值一样， $cnt$ 翻倍， $se$ 取左右 $se$ 较大者， $mx$ 任取左右(都一样)
- 否则， $mx,cnt$ 取大者， $se$ 让小区间 $mx$ 和大区间 $se$ 取最值

处理 `pushdown` ：

- 懒标记是 $t$ 的懒标记，根据题意可以取一些诸如无穷小代表无懒标记

处理建树：

- 初始次大值建无穷小

势能分析法知，对 $m$ 次询问，复杂度为 $O(m\log n)$ 

> 以 SCNUOJ1703 为例

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 400010
#define lfs p << 1
#define rfs p << 1 | 1
#define mkcf ll cf = (lf + rf) >> 1
#define neg -1
ll n, m, c, lc, rc, v, a[mn], s[mn], mx[mn], se[mn], cnt[mn], laz[mn], ans;
void pushup(ll p)
{
    s[p] = s[lfs] + s[rfs];
    if (mx[lfs] == mx[rfs])
    {
        mx[p] = mx[lfs];
        cnt[p] = cnt[lfs] + cnt[rfs];
        se[p] = max(se[lfs], se[rfs]);
    }
    else if (mx[lfs] > mx[rfs])
    {
        mx[p] = mx[lfs];
        cnt[p] = cnt[lfs];
        se[p] = max(se[lfs], mx[rfs]);
    }
    else if (mx[lfs] < mx[rfs])
    {
        mx[p] = mx[rfs];
        cnt[p] = cnt[rfs];
        se[p] = max(se[rfs], mx[lfs]);
    }
}
void build(ll p, ll lf, ll rf)
{
    laz[p] = -1;
    if (lf == rf)
    {
        s[p] = mx[p] = a[lf];
        cnt[p] = 1;
        se[p] = -1;
        return;
    }
    mkcf;
    build(lfs, lf, cf);
    build(rfs, cf + 1, rf);
    pushup(p);
}
void pushd(ll p, ll nw)
{
    if (mx[p] <= nw)
    {
        return;
    }
    s[p] += cnt[p] * (nw - mx[p]);
    mx[p] = laz[p] = nw;
}
void pushdown(ll p)
{
    if (laz[p] == -1)
    {
        return;
    }
    pushd(lfs, laz[p]);
    pushd(rfs, laz[p]);
    laz[p] = -1;
}
void update(ll p, ll lf, ll rf)
{
    if (mx[p] <= v)
    {
        return;
    }
    if (lf >= lc && rf <= rc && se[p] < v)
    {
        return pushd(p, v);
    }
    pushdown(p);
    mkcf;
    if (cf >= lc)
    {
        update(lfs, lf, cf);
    }
    if (cf < rc)
    {
        update(rfs, cf + 1, rf);
    }
    pushup(p);
}
void query_mx(ll p, ll lf, ll rf)
{
    if (lf >= lc && rf <= rc)
    {
        ans = max(ans, mx[p]);
        return;
    }
    pushdown(p);
    mkcf;
    if (cf >= lc)
    {
        query_mx(lfs, lf, cf);
    }
    if (cf < rc)
    {
        query_mx(rfs, cf + 1, rf);
    }
}
void query_sum(ll p, ll lf, ll rf)
{
    if (lf >= lc && rf <= rc)
    {
        ans += s[p];
        return;
    }
    pushdown(p);
    mkcf;
    if (cf >= lc)
    {
        query_sum(lfs, lf, cf);
    }
    if (cf < rc)
    {
        query_sum(rfs, cf + 1, rf);
    }
}
signed main()
{
    sc(n), sc(m);
    for (ll i = 1; i <= n; ++i)
    {
        sc(a[i]);
    }
    build(1, 1, n);
    while (m--)
    {
        sc(c), sc(lc), sc(rc);
        if (c == 0)
        {
            sc(v);
            update(1, 1, n);
        }
        else if (c == 1)
        {
            ans = -1;
            query_mx(1, 1, n);
            printf("%lld\n", ans);
        }
        else
        {
            ans = 0;
            query_sum(1, 1, n);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
```



##### 历史最值

> 洛谷P6242:长为 $n$ 的数列 $A$ , $m$ 次操作，每次操作后 $B_i=\max(B_i,A_i)$ ：
>
> 1. `1 l r k` 对 $A$ 区间加法( $k$ 可以是负数 )
> 2. `2 l r v` 区间求 $A_i=\min(A_i,v)$
> 3. `3 l r` 对 $A$ 区间求和
> 4. `4 l r` 对 $A$ 求区间最大值
> 5. `5 l r` 对 $B$ 求区间最大值
>
> $1\le n,m\le5\times10^5,-5\times10^8\le A_i,v\le5\times10^8,-2000\le k\le2000$

代码解释：

四种不同的懒标记：

- add\_a ：该区间最大值的加法的懒标记。
- add\_a1 ：该区间非最大值的加法的懒标记。
- add\_b ：该区间最大的历史最大值的加法的懒标记。
- add\_b1 ：该区间非最大的历史最大值的加法的懒标记。

可能后面两个懒标记比较难理解，但是一定要理解。

其他就简单了：

- l：该区间的左端点。
- r ：该区间的右端点。
- sum：该区间的的和。
- maxa ：该区间的最大值。
- se ：该区间的严格次大值。
- cnt ：该区间最大值的个数。
- maxb ：该区间的历史最大值。

- k1：最大值要加的数。
- k2：最大的历史最大值要加的数。
- k3：非最大值要加的数。
- k4：非最大的历史最大值要加的数。

```c++
#include<bits/stdc++.h>																																							请勿抄袭 
#define ll long long
using namespace std;
int n,m,op,l,r,k;
struct tree{
	ll sum;
	int add_a,add_a1,add_b,add_b1;
	int l,r,maxa,se,maxb,cnt;
}s[2000005];
char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<21],*o=obuf;
#define g()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
    int s=0,f=1;char c=g();
    for(;c<'0'||c>'9';c=g())
		if(c=='-')f=-1;
    for(;c>='0'&&c<='9';c=g())
		s=s*10+c-'0';
    return s*f;
}
inline void write(ll x)
{
    static char buf[16];
    static int len=-1;
    if(x<0)putchar('-'),x=-x;
    do buf[++len]=x%10,x/=10;while(x);
    while(len>=0)putchar(buf[len--]+'0');
    putchar('\n');
}
inline void push_up(int p)
{
	s[p].maxa=max(s[p*2].maxa,s[p*2+1].maxa);
	s[p].maxb=max(s[p*2].maxb,s[p*2+1].maxb);
	s[p].sum=s[p*2].sum+s[p*2+1].sum;
	if(s[p*2].maxa==s[p*2+1].maxa)
	{
		s[p].se=max(s[p*2].se,s[p*2+1].se);
		s[p].cnt=s[p*2].cnt+s[p*2+1].cnt;
	}
	if(s[p*2].maxa>s[p*2+1].maxa)
	{
		s[p].se=max(s[p*2].se,s[p*2+1].maxa);
		s[p].cnt=s[p*2].cnt;
	}
	if(s[p*2].maxa<s[p*2+1].maxa)
	{
		s[p].se=max(s[p*2].maxa,s[p*2+1].se);
		s[p].cnt=s[p*2+1].cnt;
	}
}
void build(int l,int r,int p)
{
	s[p].l=l,s[p].r=r;
	if(l==r)
	{
		s[p].sum=s[p].maxa=s[p].maxb=read();
		s[p].se=-1e9;
		s[p].cnt=1;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	push_up(p);
}
inline void update(int k1,int k2,int k3,int k4,int p)
{
	s[p].sum+=1ll*k1*s[p].cnt+1ll*k3*(s[p].r-s[p].l+1-s[p].cnt);
	s[p].maxb=max(s[p].maxb,s[p].maxa+k2);
	s[p].add_b=max(s[p].add_b,s[p].add_a+k2);
	s[p].add_b1=max(s[p].add_b1,s[p].add_a1+k4);
	s[p].maxa+=k1,s[p].add_a+=k1;
	s[p].add_a1+=k3;
	if(s[p].se!=-1e18)s[p].se+=k3;
}
inline void push_down(int p)
{
	int maxn=max(s[p*2].maxa,s[p*2+1].maxa);
	if(s[p*2].maxa==maxn)
	    update(s[p].add_a,s[p].add_b,s[p].add_a1,s[p].add_b1,p*2);
	else update(s[p].add_a1,s[p].add_b1,s[p].add_a1,s[p].add_b1,p*2);
	if(s[p*2+1].maxa==maxn)
		update(s[p].add_a,s[p].add_b,s[p].add_a1,s[p].add_b1,p*2+1);
	else update(s[p].add_a1,s[p].add_b1,s[p].add_a1,s[p].add_b1,p*2+1);
	s[p].add_a=s[p].add_b=s[p].add_a1=s[p].add_b1=0;
}
void update_add(int p)
{
	if(s[p].l>r||s[p].r<l)return;
	if(l<=s[p].l&&s[p].r<=r)
	    return update(k,k,k,k,p);
	push_down(p);
	update_add(p*2),update_add(p*2+1);
	push_up(p);
}
void update_min(int p)
{
	if(s[p].l>r||s[p].r<l||k>=s[p].maxa)return;
	if(l<=s[p].l&&s[p].r<=r&&k>s[p].se)
	    return update(k-s[p].maxa,k-s[p].maxa,0,0,p);
	push_down(p);
	update_min(p*2),update_min(p*2+1);
	push_up(p);
}
ll query_add(int p)
{
	if(s[p].l>r||s[p].r<l)return 0;
	if(l<=s[p].l&&s[p].r<=r)return s[p].sum;
	push_down(p);
	return query_add(p*2)+query_add(p*2+1);
}
int query_maxa(int p)
{
	if(s[p].l>r||s[p].r<l)return -1e9;
	if(l<=s[p].l&&s[p].r<=r)return s[p].maxa;
	push_down(p);
	return max(query_maxa(p*2),query_maxa(p*2+1));
}
int query_maxb(int p)
{
	if(s[p].l>r||s[p].r<l)return -1e9;
	if(l<=s[p].l&&s[p].r<=r)return s[p].maxb;
	push_down(p);
	return max(query_maxb(p*2),query_maxb(p*2+1));
}
int main()
{
	n=read(),m=read();
	build(1,n,1);
	while(m--)
	{
		op=read(),l=read(),r=read();
		if(op==1)k=read(),update_add(1);
		if(op==2)k=read(),update_min(1);
		if(op==3)write(query_add(1));
		if(op==4)write(query_maxa(1));
		if(op==5)write(query_maxb(1));
	}
	return 0;
}
```



#### zkw线段树





#### 主席树

##### 可持久化数组

> 洛谷P3919：给定长为 $n(1\le n\le10^6)$ 值域在 $[-10^9,10^9]$ 初始版本号为 $0$ 的数组，有 $m(1\le m\le 10^6)$ 次操作：
>
> 1. 修改版本号为 $ver$ 的数组下标为 $loc$ 位置值为 $x$
> 2. 查询版本为 $ver$ 的数组下标为 $loc$ 位置值
>
> 每次操作结束后，将当前版本号数组复制为 $ver$ 数组。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define sc(x) scanf("%d", &x)
#define mn 1000010
#define lg 24 // log(mn)+4mn
struct node
{
    ll l, r, v;
} t[mn * lg];
ll n, m, rot[mn], a[mn], cnt, cmd, loc, ver, x;
#define mkcf ll cf = (lf + rf) >> 1
ll build(ll lf, ll rf)
{
    ll p = ++cnt;
    if (lf == rf)
    {
        t[p].v = a[lf];
    }
    else
    {
        mkcf;
        t[p].l = build(lf, cf);
        t[p].r = build(cf + 1, rf);
    }
    return p;
}
ll update(ll r, ll lf, ll rf)
{
    ll p = ++cnt;
    if (lf == rf)
    {
        t[p].v = x;
    }
    else
    {
        mkcf;
        if (loc <= cf)
        {
            t[p].l = update(t[r].l, lf, cf);
            t[p].r = t[r].r;
        }
        else
        {
            t[p].l = t[r].l;
            t[p].r = update(t[r].r, cf + 1, rf);
        }
    }
    return p;
}
void query(ll r, ll lf, ll rf)
{
    if (lf == rf)
    {
        x = t[r].v;
        return;
    }
    mkcf;
    if (loc <= cf)
    {
        query(t[r].l, lf, cf);
    }
    else
    {
        query(t[r].r, cf + 1, rf);
    }
}
signed main()
{
    sc(n), sc(m);
    for (ll i = 1; i <= n; ++i)
    {
        sc(a[i]);
    }
    rot[0] = build(1, n);
    for (ll i = 1; i <= m; ++i)
    {
        sc(ver), sc(cmd), sc(loc);
        if (cmd == 1)
        {
            sc(x);
            rot[i] = update(rot[ver], 1, n);
        }
        else
        {
            query(rot[ver], 1, n);
            rot[i] = rot[ver];
            printf("%d\n", x);
        }
    }
    return 0;
}
```



##### 静态区间第k小

> 洛谷P3824：长为 $n(1\le n\le2\times 10^5)$ 值域的序列，有 $m(1\le m\le2\times 10^5)$ 次询问，问区间 $[l,r]$ 内严格第 $k$ 小(即去重后)的值是什么

设去重后长度为 $n'$ ，设主席树，版本为 $i(0\le i\le n)$ 的主席树代表前 $i$ 个数，当前节点维护排名(从小到大)区间 $[l,r]$ ，其值代表在该区间内有多少个数。对叶子节点，表示特定排名数字数目。

可以通过前缀和思想来建树，每次继承上一个根节点主席树。通过二分查找找到第 $i$ 个数的排名。

对于查询，对前缀和求差分，对查询的 $[l,r]$ 区间，取版本为 $r$ 的主席树节点与版本为 $l-1$ 的同一区间主席树节点作差，即得 $[1,r]$ 出现个数减去 $[1,l-1]$ 出现个数即 $[l,r]$ 出现个数。如果左子区间出现个数 $s$ 大于等于 $k$ ，也就是说左子区间里有当前子区间的第 $1$ 到第 $s$ 小，包含了第 $k$ 小，所以需要在左子区间里继续找。否则，证明第 $k$ 小在右子区间，因为左子区间有前 $s$ 小，所以分配到右子时，要减去 $s$ 。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define lg 22
#define mn 200010
ll m, n, q, a[mn], l[mn * lg], r[mn * lg], v[mn * lg], rot[mn], lc, rc, k, cnt, a0[mn];
#define mkcf ll cf = (lf + rf) >> 1
ll build(ll lf, ll rf)
{
    ll p = ++cnt;
    if (lf != rf)
    {
        mkcf;
        l[p] = build(lf, cf);
        r[p] = build(cf + 1, rf);
    }
    return p;
}
ll update(ll q, ll lf, ll rf)
{
    ll p = ++cnt;
    l[p] = l[q], r[p] = r[q], v[p] = v[q] + 1;
    if (lf != rf)
    {
        mkcf;
        if (k <= cf)
        {
            l[p] = update(l[q], lf, cf);
        }
        else
        {
            r[p] = update(r[q], cf + 1, rf);
        }
    }
    return p;
}
ll query(ll p, ll q, ll lf, ll rf, ll i)
{
    if (lf == rf)
    {
        return lf;
    }
    mkcf;
    ll j = v[l[q]] - v[l[p]];
    if (j >= i)
    {
        return query(l[p], l[q], lf, cf, i);
    }
    else
    {
        return query(r[p], r[q], cf + 1, rf, i - j);
    }
}
signed main()
{
    sc(m), sc(q);
    for (ll i = 1; i <= m; ++i)
    {
        sc(a[i]);
        a0[i] = a[i];
    }
    sort(a + 1, a + 1 + m);
    n = unique(a + 1, a + 1 + m) - (a + 1);
    rot[0] = build(1, n);
    for (ll i = 1; i <= m; ++i)
    {
        k = lower_bound(a + 1, a + 1 + n, a0[i]) - a;
        rot[i] = update(rot[i - 1], 1, n);
    }
    while (q--)
    {
        sc(lc), sc(rc), sc(k);
        ll i = query(rot[lc - 1], rot[rc], 1, n, k);
        printf("%lld\n", a[i]);
    }
    return 0;
}
```



### 树状数组

一种 $O(n)$ 建树方法：

```c++
// C++ Version
// O(n)建树
void init() {
  for (int i = 1; i <= n; ++i) {
    t[i] += a[i];
    int j = i + lowbit(i);
    if (j <= n) t[j] += t[i];
  }
}
```



#### 静态区间最值

以静态区间最小值为例。不支持可以反向变化的最值维护

```c++
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
```



#### 动态整体第k小

> 洛谷P1168以求数组前 $1,3,5,\cdots$ 项中位数为例 $n\le10^5,a\le10^9$

```c++
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,tot;
const int maxn=1e5+10;
int bit[maxn];
int a[maxn],b[maxn];

inline int lowbit(int x)
{
	return x&-x;
}
inline void add(int pos,int x)
{
	for(int i=pos;i<=tot;i+=lowbit(i))bit[i]+=x;
}
inline int find_kth(int k)
{
	int ans=0,now=0;				//这里主要解释一下这个的原理 ans就是答案，now是比当前找到的数的小的数字的个数。 
	for(int i=20;i>=0;i--)			//2^20可以说很大了，满足我们的需求了，我们按照20倍增就可以 
	{
		ans+=(1<<i);			//先让答案加上去，试试 
		if(ans>tot||now+bit[ans]>=k)ans-=(1<<i);//如果超了总体的最大值（防止数组越界），或者是 超过了k个，就退回去，这里注意是大于等于，因为要考虑有重复元素，所以我们找的其实是一个满足小于他的个数小于k的最大数
		else now+=bit[ans];//能加就加上，这里不用怕加到了原来的数，因为树状数组的结构使这个新倍增出来的数就是多出来的那一条枝 
	}
	return ans+1;//然后加上1就是答案啦 
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[++tot]);		//读个入 
		b[tot]=a[tot];
	}
	sort(a+1,a+1+n);				//排个序 
	tot=unique(a+1,a+1+tot)-a-1;	//去个重 
	for(int i=1;i<=n;i++)b[i]=lower_bound(a+1,a+1+tot,b[i])-a;//离散化一下 
	for(int i=1;i<=n;i++)
	{
		add(b[i],1);			//动态加点 
		if(i&1)printf("%d\n",a[find_kth((i+1)>>1)]);//查kth 
	}
	return 0;
}
```



#### 动态区间第k小

> 洛谷P2617:给定长为 $n$ 的数列 $a$ ，支持 $m$ 次两种操作：$1\le n,m\le10^5,0\le a_i,y\le10^9$
>
> - `Q l r k` 查询区间第 $k$ 小
> - `C x y` 将 $a_x$ 改为 $y$

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 100010
#define lg 310
ll v[mn * lg], l[mn * lg], r[mn * lg], cnt, rot[mn];
ll n, m, a[mn], h[mn * 2], hs;
#define mkcf ll cf = (lf + rf) >> 1
#define lowbit(x) (x & -x)
void update(ll &p, ll lf, ll rf, const ll &pos, const ll &x)
{
    if (!p)
    {
        p = ++cnt;
    }
    v[p] += x;
    if (lf != rf)
    {
        mkcf;
        if (pos <= cf)
        {
            update(l[p], lf, cf, pos, x);
        }
        else
        {
            update(r[p], cf + 1, rf, pos, x);
        }
    }
}
void updates(ll pos, ll x)
{
    ll k = lower_bound(h + 1, h + 1 + hs, a[pos]) - h;
    for (ll i = pos; i <= n; i += lowbit(i))
    {
        update(rot[i], 1, hs, k, x);
    }
}
ll addcnt, addid[lg], subcnt, subid[lg];
ll query(ll lf, ll rf, ll k)
{
    if (lf == rf)
    {
        return lf;
    }
    mkcf;
    ll res = 0;
    for (ll i = 1; i <= addcnt; ++i)
    {
        res += v[l[addid[i]]];
    }
    for (ll i = 1; i <= subcnt; ++i)
    {
        res -= v[l[subid[i]]];
    }
    if (k <= res)
    {
        for (ll i = 1; i <= addcnt; ++i)
        {
            addid[i] = l[addid[i]];
        }
        for (ll i = 1; i <= subcnt; ++i)
        {
            subid[i] = l[subid[i]];
        }
        return query(lf, cf, k);
    }
    else
    {
        for (ll i = 1; i <= addcnt; ++i)
        {
            addid[i] = r[addid[i]];
        }
        for (ll i = 1; i <= subcnt; ++i)
        {
            subid[i] = r[subid[i]];
        }
        return query(cf + 1, rf, k - res);
    }
}
ll querys(ll lf, ll rf, ll k)
{
    addcnt = subcnt = 0;
    for (ll i = rf; i; i -= lowbit(i))
    {
        addid[++addcnt] = rot[i];
    }
    for (ll i = lf - 1; i; i -= lowbit(i))
    {
        subid[++subcnt] = rot[i];
    }
    return query(1, hs, k);
}
struct queries
{
    ll cmd, l, r, k;
} q[mn * 2];
char c[10];
signed main()
{
    sc(n), sc(m), hs = n;
    for (ll i = 1; i <= n; ++i)
    {
        sc(a[i]), h[i] = a[i];
    }
    for (ll i = 1; i <= m; ++i)
    {
        scanf("%s", c), sc(q[i].l), sc(q[i].r);
        if (c[0] == 'Q')
        {
            sc(q[i].k);
        }
        else
        {
            q[i].cmd = 1, h[++hs] = q[i].r;
        }
    }
    sort(h + 1, h + 1 + hs);
    hs = unique(h + 1, h + 1 + hs) - (h + 1);
    for (ll i = 1; i <= n; ++i)
    {
        updates(i, 1);
    }
    for (ll i = 1; i <= m; ++i)
    {
        if (q[i].cmd == 0)
        {
            printf("%lld\n", h[querys(q[i].l, q[i].r, q[i].k)]);
        }
        else
        {
            updates(q[i].l, -1);
            a[q[i].l] = q[i].r;
            updates(q[i].l, 1);
        }
    }
    return 0;
}
```



#### 二维树状数组

维护矩阵，支持单点修改和区间查询。可以维护一维能维护的内容，区间即二维上的子矩阵。注意空间复杂度是 $O(n^2)$ 

以区间求和为例，更新和查询函数如下：

```c++
for (int x = i; x < A.length; x += lowbit(x))
    for (int y = j; y < A[i].length; y += lowbit(y))
        C[x][y] += delta;
```

```c++
int result = 0;
for (int x = i; x > 0; x -= lowbit(x))
    for (int y = j; y > 0; y -= lowbit(y))
        result += C[x][y];
return result;
```

> 输入`X n m`给定$n\times m$矩阵，接下来输入若干行，每行可能输入`L a b c d delta`代表将顶点为$(a,b),(c,d)$的矩形区域每个数字加上$delta$，或输入`k a b c d`代表求矩形区域和。
>
> $1\le n,m\le2048,-500\le delta\le500,line\le2\times10^5$，过程在int内

考虑用二维差分数组$d[n][m]$维护区间修改的二维前缀和查询。设原数组为$a[n][m]$，二维前缀和数组为$s[n][m]$，则：
$$
s[x][y]=\sum_{h=1}^x\sum_{k=1}^ya[h][k]\\
a[i][j]=\sum_{i=1}^h\sum_{j=1}^kd[i][j]\\
\therefore s[x][y]=\sum_{h=1}^x\sum_{k=1}^y\sum_{i=1}^h\sum_{j=1}^kd[i][j]
$$
对求和化简，容易可得：
$$
s[x][y]=\sum_{i=1}^x\sum_{j=1}^yd[i][j]\times(x-i+1)\times(y-j+1)
$$
分解得：
$$
\sum_{i=1}^x\sum_{j=1}^yd[i][j]\cdot(xy+x+y+1)-d[i][j]\cdot i(y+1)-d[i][j]\cdot j(x+1)+d[i][j]\cdot ij
$$
可以维护四个差分数组：$d[i][j],d[i][j]\cdot i,d[i][j]\cdot j,d[i][j]\cdot ij$。

接下来就可以跑二维差分模板和二维树状数组模板了：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define sc(x) scanf("%d", &x)
#define mn 2050
ll n, m, a, b, c, d, delta;
char op[3];
ll lowbit(ll &x) { return x & -x; }
struct BIT
{
    ll t[mn][mn];
    void add(ll lf, ll rf, ll v)
    {
        for (ll i = lf; i <= n; i += lowbit(i))
            for (ll j = rf; j <= m; j += lowbit(j))
                t[i][j] += v;
    }
    ll query(ll lf, ll rf)
    {
        ll res = 0;
        for (ll i = lf; i; i -= lowbit(i))
            for (ll j = rf; j; j -= lowbit(j))
                res += t[i][j];
        return res;
    }
} x, xi, xj, xij;
void add(ll lf, ll rf, ll v)
{
    x.add(lf, rf, v), xi.add(lf, rf, v * lf), xj.add(lf, rf, v * rf), xij.add(lf, rf, v * lf * rf);
}
ll query(ll lf, ll rf)
{
    return x.query(lf, rf) * (lf * rf + lf + rf + 1) - xi.query(lf, rf) * (rf + 1) - xj.query(lf, rf) * (lf + 1) + xij.query(lf, rf);
}
signed main()
{
    scanf("X"), sc(n), sc(m);
    while (~scanf("%s", op))
    {
        sc(a), sc(b), sc(c), sc(d);
        if (op[0] == 'L')
        {
            sc(delta);
            add(a, b, delta), add(a, d + 1, -delta), add(c + 1, b, -delta), add(c + 1, d + 1, delta);
        }
        else
            printf("%d\n", query(c, d) - query(a - 1, d) - query(c, b - 1) + query(a - 1, b - 1));
    }
    return 0;
}
```





### 平衡树

使用示例：(洛谷P6136) (目前该题平衡树均为别人的代码,后续版本可能改)

> 题意：输入 $n,m(1\le n\le10^5,1\le m\le10^6)$ ，输入 $a_i(0\le a_i < 2^{30})$ ，接下来有 $6$ 种在线操作 ( $x=x\oplus last$ )：
>
> 1. 插入整数 $x(0\le x < 2^{30})$
> 2. 删除整数 $x$ (若有多个相同，只删一个)
> 3. 查询整数 $x$ 的排名(比它小的数个数 $+1$ )
> 4. 查询排名为 $x$ 的数(不存在时查小于 $x$ 的最大数，保证 $x$ 不越当前界)
> 5. 求 $x$ 前驱(小于 $x$ 的最大的数)
> 6. 求 $x$ 后继(大于 $x$ 的最小的数)

> 此题用 `pb_ds` 解法见本模板后面

#### FHQ-Treap

```c++
#include<cstdio>
#define maxn 1100010
struct pair{
	int a,b;
	pair(int a_=0,int b_=0) { a=a_; b=b_; }
};
int read(){
    int ans=0; char ch=getchar();
    while(ch>'9'||ch<'0')ch=getchar();
    while(ch<='9'&&ch>='0'){
        ans=ans*10+ch-'0';
        ch=getchar();
    }
    return ans;
}
int key[maxn],wei[maxn],size[maxn],son[maxn][2];
int n,m,cnt,ans,seed=1,root,last;
int rand1() { return seed*=19260817; }
inline void pushup(int u)
	{ size[u]=size[son[u][0]]+size[son[u][1]]+1; }
pair split(int u,int k){
	if(!u) return pair(0,0);
	if(key[u]<k){
		pair t=split(son[u][1],k);
		son[u][1]=t.a;
		pushup(u);
		return pair(u,t.b);
	}else{
		pair t=split(son[u][0],k);
		son[u][0]=t.b;
		pushup(u);
		return pair(t.a,u);
	}
}
int merge(int u,int v){
	if(!u||!v) return u+v;
	if(wei[u]<wei[v]){
		son[u][1]=merge(son[u][1],v);
		pushup(u);
		return u;
	}else{
		son[v][0]=merge(u,son[v][0]);
		pushup(v);
		return v;
	}
}
void insert(int k){
	key[++cnt]=k; wei[cnt]=rand1(); size[cnt]=1;
	pair t=split(root,k);
	root=merge(merge(t.a,cnt),t.b);
}
void eraser(int k){
	pair x,y;
	x=split(root,k);
	y=split(x.b,k+1);
	y.a=merge(son[y.a][0],son[y.a][1]);
	root=merge(x.a,merge(y.a,y.b));
}
int find1(int k){
	int re;
	pair t=split(root,k);
	re=size[t.a]+1;
	root=merge(t.a,t.b);
	return re;
}
int find2(int k){
	int pos=root;
	while(pos){
		if(k==size[son[pos][0]]+1) return key[pos];
		if(k<=size[son[pos][0]]) pos=son[pos][0];
		else { k-=size[son[pos][0]]+1; pos=son[pos][1]; }
	}
}
int lst(int k) { return find2(find1(k)-1); }
int nxt(int k) { return find2(find1(k+1)); }
int main(){
	n=read(); m=read();
	for(int i=1;i<=n;i++){
		int a=read();
		insert(a);
	}
	for(int i=1;i<=m;i++){
		int o=read(),x; x=read();
		if(o==1) insert(x^last);
		if(o==2) eraser(x^last);
		if(o==3) { last=find1(x^last); ans^=last; }
		if(o==4) { last=find2(x^last); ans^=last; }
		if(o==5) { last=lst(x^last); ans^=last; }
		if(o==6) { last=nxt(x^last); ans^=last; }
	}
	printf("%d\n",ans);
	return 0;
}
```



#### AVL

```c++
#include <cstdio>
const int N=1e5+1e6+5;
int n,m,k,x,cnt,root,last,ans;
struct jd {
	int l,r,val,size;
	int ht;//树高
}t[N]; 
inline int read(){
	int x=0,flag=0;char ch=getchar();
	while(ch<'0'||ch>'9'){flag|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return flag?-x:x;
}
inline int newt(int val) {
	t[++cnt]=(jd) {0,0,val,1,0};
	return cnt;
}
inline int mx(int x,int y) {return x>y?x:y;}

inline int bf(int now) {return t[t[now].l].ht-t[t[now].r].ht;}
inline void update(int now) {
	t[now].size=t[t[now].l].size+t[t[now].r].size+1;
	t[now].ht=mx(t[t[now].l].ht,t[t[now].r].ht)+1;
}
inline void lt(int &now) {//左旋
	int y=t[now].r;
	t[now].r=t[y].l;
	t[y].l=now;
	now=y;
	update(t[now].l);
	update(now); 
}
inline void rt(int &now) {//右旋
	int y=t[now].l;
	t[now].l=t[y].r;
	t[y].r=now;
	now=y;
	update(t[now].r);
	update(now);
}

inline void ch(int &now) {//对now子树进行维护
	int s=bf(now);
	if(s>1) {
		int ss=bf(t[now].l);
		if(ss>0) rt(now);//LL
		else lt(t[now].l),rt(now);//LR
	}
	else if(s<-1){
		int ss=bf(t[now].r);
		if(ss<0) lt(now);//RR
		else rt(t[now].r),lt(now);//RL
	}
	else if(now) update(now);
}

void ins(int &now,int val) {
	if(!now) now=newt(val);
	else if(t[now].val<=val) ins(t[now].r,val);
	else ins(t[now].l,val);
	ch(now);
}

void del(int &now,int val) {//我是使用将其旋转至叶子节点后删除的
	if(t[now].val==val) {
		if(!t[now].l||!t[now].r)now=t[now].l^t[now].r;
		else if(bf(now)<0) rt(now),del(now,val);//右子树高，旋转至左儿子位置可略减小维护的常数
		else lt(now),del(now,val);//同上
	}
	else if(val>=t[now].val) del(t[now].r,val);
	else del(t[now].l,val);
	ch(now);
}

inline int rank(int val) {
	int now=root,s=0;
	while(now) {
		if(t[now].val>=val) now=t[now].l;
		else s+=t[t[now].l].size+1,now=t[now].r;
	}
	return s+1;
}

inline int num(int val) {
	int now=root;
	while(now) {
		if(t[t[now].l].size+1==val)
			return t[now].val;
		if(t[t[now].l].size>=val) now=t[now].l;
		else val=val-t[t[now].l].size-1,now=t[now].r;
	}
}
int main() {
	n=read();m=read();
	for(int i=1;i<=n;++i)
		ins(root,read());
	while(m--) {
		k=read();x=read();
		x^=last;
		switch(k) {
			case 1:
				ins(root,x);
				break;
			case 2:
				del(root,x);
				break;
			case 3:
				ans^=last=rank(x);
				break;
			case 4:
				ans^=last=num(x);
				break;
			case 5:
				ans^=last=num(rank(x)-1);
				break;
			case 6:
				ans^=last=num(rank(x+1));
				break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
```



#### Splay

> 洛谷P3391：对长为 $n(1\le n\le10^5)$ 的区间，进行 $m(1\le m\le10^5)$ 次 $[l,r]$ 翻转，输出最后结果

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define mn 200002
struct node
{
    ll ch[2], ff, v, size, mark;
    void init(ll x, ll fa)
    {
        ff = ch[0] = ch[1] = 0;
        size = 1;
        v = x;
        ff = fa;
    }
} t[mn];
ll n, rot, m, tot, lf, rf;
void pushuf(ll x)
{
    t[x].size = t[t[x].ch[0]].size + t[t[x].ch[1]].size + 1;
}
void pushdf(ll x)
{
    if (t[x].mark)
    {
        t[t[x].ch[0]].mark ^= 1;
        t[t[x].ch[1]].mark ^= 1;
        t[x].mark = 0;
        swap(t[x].ch[0], t[x].ch[1]);
    }
}
void rotate(ll x)
{
    ll y = t[x].ff;
    ll z = t[y].ff;
    ll k = (t[y].ch[1] == x);
    t[z].ch[t[z].ch[1] == y] = x;
    t[x].ff = z;
    t[y].ch[k] = t[x].ch[k ^ 1];
    t[t[x].ch[k ^ 1]].ff = y;
    t[x].ch[k ^ 1] = y;
    t[y].ff = x;
    pushuf(y), pushuf(x);
}
void splay(ll x, ll tg)
{
    while (t[x].ff != tg)
    {
        ll y = t[x].ff;
        ll z = t[y].ff;
        if (z != tg)
            ((t[z].ch[1] == y) ^ (t[y].ch[1] == x)) ? rotate(x) : rotate(y);
        rotate(x);
    }
    if (!tg)
        rot = x;
}
void insert(ll x)
{
    ll u = rot, ff = 0;
    while (u)
        ff = u, u = t[u].ch[x > t[u].v];
    u = ++tot;
    if (ff)
        t[ff].ch[x > t[ff].v] = u;
    t[u].init(x, ff);
    splay(u, 0);
}
ll kth(ll k)
{
    ll u = rot;
    while (1)
    {
        pushdf(u);
        if (t[t[u].ch[0]].size >= k)
            u = t[u].ch[0];
        else if (t[t[u].ch[0]].size + 1 == k)
            return u;
        else
            k -= t[t[u].ch[0]].size + 1, u = t[u].ch[1];
    }
}
void write(ll u)
{
    pushdf(u);
    if (t[u].ch[0])
        write(t[u].ch[0]);
    if (t[u].v > 1 && t[u].v < n + 2)
        printf("%d ", t[u].v - 1);
    if (t[u].ch[1])
        write(t[u].ch[1]);
}
void wk(ll lf, ll rf)
{
    lf = kth(lf), rf = kth(rf + 2);
    splay(lf, 0), splay(rf, lf);
    t[t[t[rot].ch[1]].ch[0]].mark ^= 1;
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (ll i = 1; i <= n + 2; ++i)
        insert(i);
    while (m--)
        scanf("%d%d", &lf, &rf), wk(lf, rf);
    write(rot);
    return 0;
}
```



#### 笛卡尔树

节点由 $(k,w)$ 组成， $k$ 满足二叉搜索树， $w$ 满足堆，若 $(k,w)$ 分别互不相同，那么结构唯一

可以 $O(n)$ 构建。 例题P5854：给定排列，构建笛卡尔树，输出me给节点 $i$ 的左右儿子(不存在为 $0$ )的 $\oplus_{i=1}^ni(l_i+1),\oplus_{i=1}^ni(r_i+1)$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define MAXN 10000002
inline ll read()
{
    char p = 0;
    ll r = 0, o = 0;
    for (; p < '0' || p > '9'; o |= p == '-', p = getchar())
        ;
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar())
        ;
    return o ? (~r) + 1 : r;
}
ll n, a[MAXN], stk[MAXN], ls[MAXN], rs[MAXN], pos, top;
long long lf, rf;
signed main()
{
    n = read();
    for (ll i = 1; i <= n; ++i)
    {
        a[i] = read();
        while (pos && a[stk[pos]] > a[i])
            --pos;
        if (pos)
            rs[stk[pos]] = i;
        if (pos < top)
            ls[i] = stk[pos + 1];
        stk[top = ++pos] = i;
    }
    for (long long i = 1; i <= n; ++i)
        lf ^= i * (ls[i] + 1), rf ^= i * (rs[i] + 1);
    printf("%lld %lld", lf, rf);
    return 0;
}
```



> ### 树套树



### 可并堆

左偏树。支持在 $O(\log n)$ 的时间复杂度内进行合并的堆式数据结构

**外结点** ：左儿子或右儿子是空结点的结点。

**距离** ： 一个结点 x 的距离 $dist_x$ 定义为其子树中与结点 x 最近的外结点到 x 的距离。特别地，定义空结点的距离为 -1。

满足小根堆/大根堆性质，且满足左偏：每个节点 $dist_{lc}\ge dist_{rc}$

基本结论：

- 节点 $x$ 的距离 $dist_x=dist_{rc}+1$
- 距离为 $n$ 的左偏树至少有 $2^{n+1}-1$ 节点且是满二叉树

> 但是向左的链也是左偏树

> 例题洛谷P3377：一开始有 $n(\le10^5)$ 个小根堆，实现 $m(\le10^5)$ 次操作：
>
> - `1 x y` 将第 $x$ 个数和第 $y$ 个数所在堆合并(若删掉或已在无视)
> - `2 x` 输出第 $x$ 个数所在堆最小数，并删掉这个数(多个最小删先输入的)，已删输出 `-1` 并无视

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define MAXN 100002
ll n, m, op, x, y, lc[MAXN], rc[MAXN], d[MAXN], rt[MAXN];
bool tf[MAXN];
struct node
{
    ll i, v;
    bool operator<(const node &x) const
    {
        return v == x.v ? i < x.i : v < x.v;
    }
} v[MAXN];
inline ll finds(ll x)
{
    while (x != rt[x])
        x = rt[x] = rt[rt[x]];
    return x;
}
ll merge(ll x, ll y)
{
    if (!x || !y)
        return x + y;
    if (v[y] < v[x])
        swap(x, y);
    rc[x] = merge(rc[x], y);
    if (d[lc[x]] < d[rc[x]])
        swap(lc[x], rc[x]);
    d[x] = d[rc[x]] + 1;
    return x;
}
signed main()
{
    d[0] = -1;
    scanf("%d%d", &n, &m);
    for (ll i = 1; i <= n; ++i)
        scanf("%d", &v[i].v), v[i].i = i, rt[i] = i;
    while (m--)
    {
        scanf("%d%d", &op, &x);
        if (op == 1)
        {
            scanf("%d", &y);
            if (tf[x] || tf[y])
                continue;
            x = finds(x), y = finds(y);
            if (x != y)
                rt[x] = rt[y] = merge(x, y);
        }
        else
        {
            if (tf[x])
            {
                printf("-1\n");
                continue;
            }
            x = finds(x);
            printf("%d\n", v[x].v);
            tf[x] = true;
            rt[lc[x]] = rt[rc[x]] = rt[x] = merge(lc[x], rc[x]);
            lc[x] = rc[x] = d[x] = 0;
        }
    }
    return 0;
}
```



### 珂朵莉树

骗分数据结构。核心操作：把值相同的区间合并成一个结点保存在 set 里面。在数据随机的情况下，复杂度为 $O(n\log\log n)$ ，链表为 $O(n\log n)$

进行求取区间左右端点操作时，必须先 split 右端点，再 split 左端点。若先 split 左端点，返回的迭代器可能在 split 右端点的时候失效，可能会导致 RE

节点：

```c++
struct Node_t {
  int l, r;
  mutable int v;

  Node_t(const int &il, const int &ir, const int &iv) : l(il), r(ir), v(iv) {}

  inline bool operator<(const Node_t &o) const { return l < o.l; }
};
auto split(int x) {
  if (x > n) return odt.end();
  auto it = --odt.upper_bound(Node_t{x, 0, 0});
  if (it->l == x) return it;
  int l = it->l, r = it->r, v = it->v;
  odt.erase(it);
  odt.insert(Node_t(l, x - 1, v));
  return odt.insert(Node_t(x, r, v)).first;
}
```

区间赋值：

```c++
void assign(int l, int r, int v) {
  auto itr = split(r + 1), itl = split(l);
  odt.erase(itl, itr);
  odt.insert(Node_t(l, r, v));
}
```

区间遍历：

```c++
void performance(int l, int r) {
  auto itr = split(r + 1), itl = split(l);
  for (; itl != itr; ++itl) {
    // Perform Operations here
  }
}
```





### 并查集

#### 种类并查集

种类并查集就是有多少个种类开多少倍长即可。

> 洛谷P1892：有n个人m条关系，E a b代表a和b是敌人，F a b代表a和b是朋友；敌人的敌人是朋友，朋友的朋友是朋友；朋友间一定会结成同一帮派，求帮派数

使用反集。解法二是照搬二分图。

```c++
#include<bits/stdc++.h>
using namespace std;
int s,n,m,a,b,f[2500];
char ch;
int find(int x){
    if(f[x]!=x)f[x]=find(f[x]);
    return f[x];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=2*n;i++){
        f[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>ch>>a>>b;
        if(ch=='F'){
            f[find(a)]=find(b);//合并
        }else{
            f[find(a+n)]=find(b);
            f[find(b+n)]=find(a);//反集合并
        }
    }
    for(int i=1;i<=n;i++){
        if(f[i]==i)s++;
    }
    cout<<s;//祖先数就是团伙数
}
```

> 例题洛谷P2024:存在食物环A->B->C->A，有n种动物，m条判断。判断类型为1 i j表示i,j同属A/B/C大类,2 i j表示i->j。先出现的判断在不产生矛盾的情况下变成真理。求m条判断中谬论数。(输入n,m,依次输入判断) $1\le n\le5\times10^5,1\le k\le10^5$

构建三倍并查集，其中i是自身，i+n是匿名猎物，i+2n是匿名天敌。另一种解法是加权并查集，三种关系分别是 $0,1,2$ ，用向量加减模 $3$ 得到新关系。加权并查集写法见下文

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 150002
#define ANS       \
    {             \
        ++ans;    \
        continue; \
    }
int fa[MAXN], n, k, ans, cmd, x, y, n3;
inline int finds(int k)
{
    while (k != fa[k])
        k = fa[k] = fa[fa[k]];
    return k;
}
signed main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= 3 * n; ++i)
        fa[i] = i;
    while (k--)
    {
        scanf("%d%d%d", &cmd, &x, &y);
        if (x > n || y > n)
            ANS;
        if (cmd == 1)
        {
            if (finds(x + n) == finds(y) || finds(x) == finds(y + n))
                ANS; //或后者改为x+2n与y
            fa[finds(x)] = finds(y);
            fa[finds(x + n)] = finds(y + n);
            fa[finds(x + n + n)] = finds(y + n + n);
        }
        else
        {
            if (finds(x) == finds(y) || finds(x) == finds(y + n))
                ANS; //如果同类相食或反向捕食(y+n是天敌)，是谬论
            fa[finds(x + n)] = finds(y);
            fa[finds(x + n + n)] = finds(y + n);
            fa[finds(x)] = finds(y + n + n);
        }
    }
    printf("%d", ans);
    return 0;
}
```



#### 加权并查集

> 洛谷P1196 有 $30000$ 战舰，每次 `M i j` 将 $i$ 所在编队连在 $j$ 所在编队尾部成链。每次 `C i j` 查询 $i,j$ 链之间有多少个战舰。若 $i,j$ 不同编队输出 `-1` 。 $t\le 5\times10^5$

设前缀和 `cnt` 为离队首的距离，则所求为 $|cnt_i-cnt_j|+1-2$ 

每次合并并查集时， `fa[find(i)]=find(j)` ，在这之前，更新 $cnt_x$ ，距离增加 $num_y$ ，即舰队数。且 $num_y$ 增加 $num_x$ ，并且清零 $num_x$ (否则反复合并会出锅)。`find` 用递归式，每次 `find` 时更新 $cnt_x=cnt_{fa_x}$ ，注意在更新 $fa$ 之前做，不然等于我赋值我自己。

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 500010
ll t, fa[mn], cnt[mn], sum[mn];
char cmd[5];
ll findf(ll x)
{
    if (x == fa[x])
    {
        return x;
    }
    ll res = findf(fa[x]);
    cnt[x] += cnt[fa[x]];
    return fa[x] = res;
}
signed main()
{
    sc(t);
    for (ll i = 1; i < mn; ++i)
    {
        fa[i] = i, sum[i] = 1;
    }
    while (t--)
    {
        ll u, v, fu, fv;
        scanf("%s%lld%lld", cmd, &u, &v);
        fu = findf(u), fv = findf(v);
        if (cmd[0] == 'M')
        {
            cnt[fu] += sum[fv];
            fa[fu] = fv;
            sum[fv] += sum[fu];
            sum[fu] = 0;
        }
        else
        {
            if (fu != fv)
            {
                printf("-1\n");
            }
            else
            {
                printf("%lld\n", abs(cnt[u] - cnt[v]) - 1);
            }
        }
    }
    return 0;
}
```



> 洛谷P2024 题面见上文

构造关系 $u\to v$ ，设为 $ty[u]$ 表示 $u$ 与根 $v$ 的关系，设 $0$ 表示同类， $1$ 表示捕食， $2$ 表示被捕食，显然构造出来的关系模 $3$ 结果符合传递性，即满足性质 $\because u\to v\to w\therefore ty[u\to w]=(ty[u\to v]+ty[v\to w])\bmod 3$ 

那么可以构造加权并查集，使得压缩路径后，若 $u,v$ 同根，则根据向量加法， $u,v$ 见关系可以表示为 $(ty[u]-ty[v])\bmod 3$ 。并且如果要新建 $u,v$ 之间的关系，那么新建的 $fa_u,fa_v$ 之间，若设 $fa[fa_u]=fa_v$ ，则 $ty[fa_u]=(-ty[u]+new+ty[v])\bmod 3$ 

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 50010
ll n, k, fa[mn], ty[mn], fake;
ll findf(ll x)
{
    if (x == fa[x])
    {
        return x;
    }
    ll res = findf(fa[x]);
    ty[x] = (ty[x] + ty[fa[x]]) % 3;
    return fa[x] = res;
}
signed main()
{
    sc(n), sc(k);
    for (ll i = 1; i <= n; ++i)
    {
        fa[i] = i;
    }
    while (k--)
    {
        ll cmd, u, v, fu, fv;
        sc(cmd), sc(u), sc(v), fu = findf(u), fv = findf(v);
        if (u > n || v > n || (u == v && cmd == 2))
        {
            ++fake;
            continue;
        }
        if (cmd == 1)
        {
            if (fu == fv && ty[u] != ty[v])
            {
                ++fake;
            }
            else
            {
                ty[fu] = (3 - ty[u] + ty[v]) % 3;
                fa[fu] = fv;
            }
        }
        else
        {
            if (fu == fv && (ty[u] - ty[v] + 3) % 3 != 1)
            {
                ++fake;
            }
            else
            {
                ty[fu] = (3 - ty[u] + ty[v] + 1) % 3;
                fa[fu] = fv;
            }
        }
    }
    printf("%lld", fake);
    return 0;
}
```



## 图论

### 树

#### 重心

以树的重心为根时，所有子树的大小都不超过整棵树大小的一半。

树中所有点到某个点的距离和中，到重心的距离和是最小的；如果有两个重心，那么到它们的距离和一样。

把两棵树通过一条边相连得到一棵新的树，那么新的树的重心在连接原来两棵树的重心的路径上。

在一棵树上添加或删除一个叶子，那么它的重心最多只移动一条边的距离。

> 例题POJ1655：给定 $t(\le 20)$ 询问，每次节点为 $n(n\le2\times10^4)$ 的树，求最小编号重心及其最大子树节点数

```c++
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
#define mn 20010
struct edge
{
    ll to, nx;
} e[mn << 1];
ll t, n, hd[mn], cnt, cf, cfv, siz[mn], w[mn];
void adde(ll u, ll v)
{
    e[++cnt] = {v, hd[u]};
    hd[u] = cnt;
}
#define sc(x) scanf("%lld", &x)
void dfs(ll u, ll fa)
{
    siz[u] = 1, w[u] = 0;
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (v == fa)
        {
            continue;
        }
        dfs(v, u);
        siz[u] += siz[v];
        w[u] = max(w[u], siz[v]);
    }
    w[u] = max(w[u], n - siz[u]);
    if (w[u] <= n / 2 && u < cf)
    {
        cf = u, cfv = w[u];
    }
}
signed main()
{
    for (sc(t); t; --t)
    {
        sc(n), cnt = 0, memset(hd, 0, sizeof hd), cf = n + 1;
        for (ll i = 1, u, v; i < n; ++i)
        {
            sc(u), sc(v), adde(u, v), adde(v, u);
        }
        dfs(1, 0);
        printf("%lld %lld\n", cf, cfv);
    }
    return 0;
}
```



#### 直径

两次 DFS 法求直径

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 200002
ll n, cnt, hd[mn], rot, mxd;
bool vis[mn];
struct edge
{
    ll to, nx;
} e[mn << 1];
void adde(ll &u, ll &v)
{
    e[++cnt] = {v, hd[u]};
    hd[u] = cnt;
}
void dfs(ll x, ll fa, ll d)
{
    vis[x] = true;
    if (d > mxd)
    {
        mxd = d, rot = x;
    }
    for (ll i = hd[x]; i; i = e[i].nx)
    {
        ll toi = e[i].to;
        if (!vis[toi])
            dfs(toi, x, d + 1);
    }
}
signed main()
{
    sc(n);
    for (ll i = 1, u, v; i < n; ++i)
        sc(u), sc(v), adde(u, v), adde(v, u);
    dfs(1, 0, 0);
    mxd = 0;
    memset(vis, 0, sizeof vis);
    dfs(rot, 0, 0);
    printf("%lld", mxd);
    return 0;
}
```



#### 最近公共祖先

解法一：倍增法求 LCA 可以 $O(n\log n)$ 预处理和 $O(\log n)$ 查询

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 500010
#define mm 20
struct edge
{
    ll to, nx;
} e[mn << 1];
ll fa[mn][mm], n, m, hd[mn], cnt, d[mn], u, v, lg[mn], s;
void adde(ll &u, ll &v)
{
    e[++cnt] = {v, hd[u]};
    hd[u] = cnt;
}
void dfs(ll h, ll faa)
{
    fa[h][0] = faa;
    d[h] = d[faa] + 1;
    for (ll i = 1; i <= lg[d[h]]; ++i)
    {
        fa[h][i] = fa[fa[h][i - 1]][i - 1];
    }
    for (ll i = hd[h]; i; i = e[i].nx)
    {
        ll toi = e[i].to;
        if (toi != faa)
            dfs(toi, h);
    }
}
ll lca(ll u, ll v)
{
    if (d[u] < d[v])
        swap(u, v);
    while (d[u] > d[v])
        u = fa[u][lg[d[u] - d[v]] - 1];
    assert(d[u] == d[v]);
    if (u == v)
        return u;
    for (ll k = lg[d[u]] - 1; k >= 0; --k)
    {
        if (fa[u][k] != fa[v][k])
        {
            u = fa[u][k];
            v = fa[v][k];
        }
    }
    return fa[u][0];
}
signed main()
{
    sc(n), sc(m), sc(s); // s是根节点
    for (ll i = 1; i < n; ++i)
        sc(u), sc(v), adde(u, v), adde(v, u);
    for (ll i = 1; i <= n; ++i) // 1+floor(log(,2))
        lg[i] = lg[i / 2] + 1;  // 如1,2,2,3,3
    dfs(s, 0);
    while (m--)
    {
        sc(u), sc(v);
        printf("%lld\n", lca(u, v));
    }
    return 0;
}
```

解法二：欧拉序上 RMQ ，可以 $O(n\log n)$ 预处理和 $O(1)$ 查询

欧拉序就是每个点进入时记录一次，从每一个子树出来时记录一次

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
typedef int ll;
const ll N = 1e6 + 10; //开二倍长
ll n, m, s, tot, cnt;
ll head[N], to[N], Next[N], Log[N];
inline void addedge(ll x, ll y)
{
    to[++tot] = y;
    Next[tot] = head[x];
    head[x] = tot;
}
ll a[N], dep[N], mn[21][N], p[N];
inline void dfs(ll x, ll fa)
{
    a[++cnt] = x;
    p[x] = cnt;
    dep[x] = dep[fa] + 1;
    for (ll i = head[x]; i; i = Next[i])
    {
        ll u = to[i];
        if (u == fa)
            continue;
        dfs(u, x);
        a[++cnt] = x;
    }
}
signed main()
{
    sc(n), sc(m), sc(s);
    Log[0] = -1;
    for (ll i = 1, x, y; i < n; ++i)
        sc(x), sc(y), addedge(x, y), addedge(y, x);
    dfs(s, 0);
    for (ll i = 1; i <= cnt; ++i)
        mn[0][i] = a[i];
    for (ll i = 1; i <= 20; ++i)
        for (ll j = 1; j + (1 << i) <= cnt; ++j)
            if (dep[mn[i - 1][j]] < dep[mn[i - 1][j + (1 << (i - 1))]])
                mn[i][j] = mn[i - 1][j];
            else
                mn[i][j] = mn[i - 1][j + (1 << (i - 1))];
    for (ll i = 1; i <= cnt; ++i)
        Log[i] = Log[i >> 1] + 1;
    for (ll i = 1, x, y; i <= m; ++i)
    {
        sc(x), sc(y);
        if (p[x] > p[y])
            swap(x, y);
        ll k = Log[p[y] - p[x] + 1], ans;
        if (dep[mn[k][p[x]]] < dep[mn[k][p[y] - (1 << k) + 1]])
            ans = mn[k][p[x]];
        else
            ans = mn[k][p[y] - (1 << k) + 1];
        printf("%d\n", ans);
    }
    return 0;
}
```



#### 树上k级祖先

> 例题P5903：给定 $n(2\le n\le5\times10^5)$ 点有根树， $q(1\le q\le5\times10^6)$ 询问，随机种子 $s$ 。接下来输入每个点的父亲 ( $0$ 为根)，然后有根据随机种子生成的询问，每次求节点 $x$ 的 $k$ 级祖先。输出 $\oplus_{i=1}^qi\times ans_i$ 。s

长链剖分，先一次性跳到长链，而后在链上 $O(1)$ 解决。结论：跳 $\lceil\log k\rceil$ 次一定在长链上

长链： 重子节点表示其子节点中子树深度最大的子结点。长链剖分从一个节点到根的路径的轻边切换条数是 $\sqrt n$ 级别的

设重链长 $d$ ，且存在 $i$ 满足 $2^i < k < 2^{i+1}$ ，那么 $k-2^i < 2^i\le d$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define MAXN 500002
#define ui unsigned int
#define sc(x) scanf("%d", &x)
ll n, g[MAXN], d[MAXN], f[MAXN][20], son[MAXN], dep[MAXN], top[MAXN];
ll q, rt, ans, o, x, k;
vector<ll> e[MAXN], u[MAXN], v[MAXN];
long long res;
ui s;
inline ui get(ui x)
{
    x ^= x << 13, x ^= x >> 17, x ^= x << 5;
    return s = x;
}
void dfs1(ll x)
{
    dep[x] = d[x] = d[f[x][0]] + 1;
    for (auto y : e[x])
    {
        f[y][0] = x;
        for (ll i = 0; f[y][i]; ++i)
            f[y][i + 1] = f[f[y][i]][i];
        dfs1(y);
        if (dep[y] > dep[x])
            dep[x] = dep[y], son[x] = y;
    }
}
void dfs2(ll x, ll p)
{
    top[x] = p;
    if (x == p)
    {
        o = x;
        for (ll i = 0; i <= dep[x] - d[x]; ++i)
            u[x].push_back(o), o = f[o][0];
        o = x;
        for (ll i = 0; i <= dep[x] - d[x]; ++i)
            v[x].push_back(o), o = son[o];
    }
    if (son[x])
        dfs2(son[x], p);
    for (auto y : e[x])
        if (y != son[x])
            dfs2(y, y);
}
inline ll ask(ll x, ll k)
{
    if (!k)
        return x;
    x = f[x][g[k]], k -= 1 << g[k];
    k -= d[x] - d[top[x]], x = top[x];
    return k >= 0 ? u[x][k] : v[x][-k];
}
signed main()
{
    scanf("%d%d%d", &n, &q, &s);
    g[0] = -1;
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%d", &f[i][0]);
        e[f[i][0]].push_back(i), g[i] = g[i >> 1] + 1;
    }
    rt = e[0][0];
    dfs1(rt);
    dfs2(rt, rt);
    for (ll i = 1; i <= q; ++i)
    {
        x = (get(s) ^ ans) % n + 1;
        k = (get(s) ^ ans) % d[x];
        res ^= 1LL * i * (ans = ask(x, k));
    }
    printf("%lld", res);
    return 0;
}
```



#### LCA应用

##### 前缀和差分

路径点权和：$s[u]+s[v]-s[lca]-s[fa_{lca}]$

路径边权和： $s[u]+s[v]-2s[lca]$

路径点差分：$s[u],s[v]$ 加一， $s[lca],s[fa_{lca}]$ 减一

路径边差分：$s[u],s[v]$ 加一， $s[lca]$ 减二



##### 两点距离

在 LCA 的基础上，设深度为 $d[x]$ ，则距离为 $d[u]+d[v]-2d[lca]$ 。

> 也可以表示为：$|d[u]-d[LCA]|+|d[v]-d[LCA]|$



##### 路径相交

对 $AB,CD$ ，分别求出 $LCA$ 为 $X,Y$ ，若两点距离满足 $|AY|+|BY|=|AB|$ 或 $|CX|+|DX|=|CD|$ ，证明相交



##### 其他

从树上三个点出发，求一个目的点，使得路径和最小，输出最小路径和

两两求LCA，可以发现必然有一个重复点，并且可以发现不重复点必然是最优解，设深度为d，最小路径和为：
$$
d_a+d_b+d_c-(d_{lca(a)}+d_{lca(b)}+d_{lca(c)})
$$
此外，目的是三个LCA深度最大的一个，可以得知，最深的是不重复的



#### 树链剖分

性质：

1. DFS序新编号的重建树，保证子树`x`的节点范围是`[x,x+siz[x]-1]`。因此，对于重建树，可以使用线段树等结构维护节点值。
2. 任意一条路径可以表示为不超过$\Omicron(\log n)$条连续重链(或部分重链)。

因此初始化的时间复杂度是$\Omicron(n)$，使用线段树维护时，单路径查询的时间复杂度是$\Omicron(\log^2n)$，单子树查询的时间复杂度是$\Omicron(\log n)$。



> P3384例题：给定 $n,m,r,p$ ，$r$ 是根节点编号。对 $m$ 次操作：
>
> 1. `1 x y z` 将 $x,y$ 路径上全部点加上 $z$
> 2. `2 x y` 查询路径和对 $p$ 取模 
> 3. `3 x z` 将 $x$ 为根节点的子树(含根下同)全部点加上 $z$
> 4. `4 x` 查询子树节点和对 $p$ 取模 
>
> $1\le n,m\le10^5,1\le p\le2^{31}-1$ 

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 100020
ll n, m, r, mod, ui, vi, k, x, y, z;
#define mkcf ll cf = (lf + rf) >> 1
#define lfs p << 1
#define rfs p << 1 | 1
ll hd[mn], cnt, w[mn], wt[mn];
struct edge
{
    ll to, nx;
} e[mn];
void adde(ll u, ll v)
{
    e[++cnt] = {v, hd[u]};
    hd[u] = cnt;
}
ll a[mn << 2], laz[mn << 2], lc, rc, res, updv;
ll hvson[mn], id[mn], fa[mn], dfn, dep[mn], siz[mn], top[mn];

void pushdown(ll lf, ll rf, ll p)
{
    mkcf;
    laz[lfs] += laz[p], laz[rfs] += laz[p];
    (a[lfs] += laz[p] * (cf - lf + 1)) %= mod;
    (a[rfs] += laz[p] * (rf - cf)) %= mod;
    laz[p] = 0;
}
void build(ll lf = 1, ll rf = n, ll p = 1)
{
    if (lf == rf)
    {
        a[p] = wt[lf] % mod;
        return;
    }
    mkcf;
    build(lf, cf, lfs), build(cf + 1, rf, rfs);
    a[p] = (a[lfs] + a[rfs]) % mod;
}
void query(ll lf = 1, ll rf = n, ll p = 1)
{
    if (lc <= lf && rf <= rc)
    {
        (res += a[p]) %= mod;
        return;
    }
    pushdown(lf, rf, p);
    mkcf;
    if (lc <= cf)
    {
        query(lf, cf, lfs);
    }
    if (rc > cf)
    {
        query(cf + 1, rf, rfs);
    }
}
void update(ll lf = 1, ll rf = n, ll p = 1)
{
    if (lc <= lf && rf <= rc)
    {
        laz[p] += updv;
        a[p] += updv * (rf - lf + 1) % mod;
        return;
    }
    pushdown(lf, rf, p);
    mkcf;
    if (lc <= cf)
    {
        update(lf, cf, lfs);
    }
    if (rc > cf)
    {
        update(cf + 1, rf, rfs);
    }
    a[p] = (a[lfs] + a[rfs]) % mod;
}

ll qrange(ll x, ll y)
{
    ll ans = 0;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
        {
            swap(x, y);
        }
        res = 0, lc = id[top[x]], rc = id[x], query();
        (ans += res) %= mod;
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
    {
        swap(x, y);
    }
    res = 0, lc = id[x], rc = id[y], query();
    return (ans + res) % mod;
}

void frange(ll x, ll y, ll k)
{
    updv = k % mod;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
        {
            swap(x, y);
        }
        lc = id[top[x]], rc = id[x], update();
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
    {
        swap(x, y);
    }
    lc = id[x], rc = id[y], update();
}

ll qson(ll x)
{
    res = 0, lc = id[x], rc = id[x] + siz[x] - 1, query();
    return res;
}

void fson(ll x, ll k)
{
    updv = k % mod, lc = id[x], rc = id[x] + siz[x] - 1, update();
}

void dfs(ll x, ll f, ll deep)
{
    dep[x] = deep, fa[x] = f, siz[x] = 1;
    ll hvsonv = -1, y;
    for (ll i = hd[x]; i; i = e[i].nx)
    {
        y = e[i].to;
        if (y == f)
        {
            continue;
        }
        dfs(y, x, deep + 1);
        siz[x] += siz[y];
        if (siz[y] > hvsonv)
        {
            hvson[x] = y, hvsonv = siz[y];
        }
    }
}

void dfs(ll x, ll topi)
{
    id[x] = ++dfn, wt[dfn] = w[x], top[x] = topi;
    if (!hvson[x])
    {
        return;
    }
    dfs(hvson[x], topi);
    for (ll i = hd[x]; i; i = e[i].nx)
    {
        ll y = e[i].to;
        if (y == fa[x] || y == hvson[x])
        {
            continue;
        }
        dfs(y, y);
    }
}

signed main()
{
    sc(n), sc(m), sc(r), sc(mod);
    for (ll i = 1; i <= n; ++i)
    {
        sc(w[i]);
    }
    for (ll i = 1; i < n; ++i)
    {
        sc(ui), sc(vi), adde(ui, vi), adde(vi, ui);
    }
    dfs(r, 0, 1), dfs(r, r), build();
    while (m--)
    {
        sc(k), sc(x);
        if (k == 1)
        {
            sc(y), sc(z), frange(x, y, z);
        }
        else if (k == 2)
        {
            sc(y), printf("%lld\n", qrange(x, y));
        }
        else if (k == 3)
        {
            sc(y), fson(x, y);
        }
        else
        {
            printf("%lld\n", qson(x));
        }
    }
    return 0;
}
```





#### 启发式合并

dsu on tree

预处理过程：DFS 一次，得到轻重儿子关系和 DFN 序(后者可选)

核心 DFS 合并过程：

1. DFS 轻儿子，合并所有轻子树上答案值
2. DFS 重儿子，合并重子树上的答案并保存当前总合并答案
3. 遍历当前节点的轻子树和当前节点，累加子树各点的答案值，保存答案
4. 遍历当前节点的轻子树，删掉轻子树合并值

简单理解就是，先 DFS 轻的部分，然后直接计算并保存其答案；然后因为其兄弟节点子树也有轻的，而当前子树不会给兄弟节点子树贡献，所以要把当前的答案全部丢弃，然后再计算兄弟节点子树。当轻子树都计算完后，计算重子树，但是不进行丢弃，此时回到当前的根，再次遍历全部轻子树永久加上轻子树的贡献。

在树上启发式合并里，整个板子是基本不用动的，唯一需要更改的地方是合并函数的增删处理。

用途：求出静态有根树的每个子树(显然共 $n$ 个子树)的某个要求的值，这个过程是 $O(n\log n)$ 的

根据轻重链剖分的性质可知，经过一条轻边时，子树的大小至少会除以二，所以树上任意一条路径最多包含 $\log n$ 条轻边。如果某点到根节点经过了 $x$ 条轻边，那么它的大小 $y$ 满足： $y <\dfrac n{2^x}$ 

一个节点被遍历的次数等于它到根节点上轻边的数目+1(重节点只被遍历一次)，根据上述性质，即一个节点最多被遍历 $\log n+1$ 次，所以时间复杂度为 $O(n\log n)$

边权问题可以把边权在 DFS1 时叠到点权(`v==fa continue`后)，把 `add(u)` 和 `ans[u]=tot` 顺序对换

> 例题洛谷U41492：$n(n\le 10^5)$ 个节点的树，每个节点有不同的颜色( $10^5$ 种)，问每个节点为根的子树中，所有节点有多少种不同的颜色；$m(m\le 10^5)$ 次询问，每次问一棵子树 

写法一：DFN序

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define sc(x) scanf("%lld", &x)
#define mn 100010
ll n, m, cnt, dfn[mn], big[mn], siz[mn], tot, c[mn], ecnt, hd[mn];
ll lf[mn], rf[mn], s[mn], ans[mn], x;
struct edge
{
    ll to, nx;
} e[mn * 2];
void adde(ll u, ll v)
{
    e[++ecnt] = {v, hd[u]};
    hd[u] = ecnt;
}
void dfs1(ll u, ll fa)
{
    lf[u] = ++cnt, dfn[cnt] = u, siz[u] = 1;
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (v == fa)
        {
            continue;
        }
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[big[u]] < siz[v])
        {
            big[u] = v;
        }
    }
    rf[u] = cnt;
}
void add(ll u)
{
    tot += (s[c[u]]++ == 0);
}
void remove(ll u)
{
    tot -= (--s[c[u]] == 0);
}
void dfs2(ll u, ll fa, bool save)
{
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (v != fa && v != big[u])
        {
            dfs2(v, u, false);
        }
    }
    if (big[u])
    {
        dfs2(big[u], u, true);
    }
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (v != fa && v != big[u])
        {
            for (ll j = lf[v]; j <= rf[v]; ++j)
            {
                add(dfn[j]);
            }
        }
    }
    add(u);
    ans[u] = tot;
    if (!save)
    {
        for (ll j = lf[u]; j <= rf[u]; ++j)
        {
            remove(dfn[j]);
        }
    }
}
signed main()
{
    sc(n);
    for (ll i = 1, u, v; i < n; ++i)
    {
        sc(u), sc(v), adde(u, v), adde(v, u);
    }
    for (ll i = 1; i <= n; ++i)
    {
        sc(c[i]);
    }
    dfs1(1, 0), dfs2(1, 0, false);
    for (sc(m); m; --m)
    {
        sc(x);
        printf("%lld\n", ans[x]);
    }
    return 0;
}
```

写法二：不带DFN序

```c++
#include <cstdio>
#include <cstring>
#define maxn 100010

int n,m,col[maxn];
struct edge{int y,next;};
edge e[maxn*2];
int first[maxn];
void buildroad(int x,int y)
{
	static int len=0;
	e[++len]=(edge){y,first[x]};
	first[x]=len;
}
int size[maxn],mson[maxn];
void dfs1(int x,int fa)//求重儿子
{
	size[x]=1;
	for(int i=first[x];i;i=e[i].next)
	{
		int y=e[i].y;
		if(y==fa)continue;
		dfs1(y,x);
		if(size[y]>size[mson[x]])mson[x]=y;
		size[x]+=size[y];
	}
}
int tong[maxn],ans[maxn],now_ans=0;
void go(int x,int fa,int type)
{
	tong[col[x]]+=type;
	if(type==1&&tong[col[x]]==1)now_ans++;
	if(type==-1&&tong[col[x]]==0)now_ans--;
	for(int i=first[x];i;i=e[i].next)
	if(e[i].y!=fa)go(e[i].y,x,type);
}
void dfs2(int x,int fa,bool del)
//求解，del表示求完x的子树的答案后需不需要清空x的子树的信息
{
	for(int i=first[x];i;i=e[i].next)//先统计轻儿子的答案
	if(e[i].y!=fa&&e[i].y!=mson[x])dfs2(e[i].y,x,true);
	if(mson[x]!=0)dfs2(mson[x],x,false);//最后统计重儿子的答案
	
	tong[col[x]]++;if(tong[col[x]]==1)now_ans++;//统计自己以及轻子树的信息
	for(int i=first[x];i;i=e[i].next)
	if(e[i].y!=fa&&e[i].y!=mson[x])go(e[i].y,x,1);
	ans[x]=now_ans;//得到自己的答案
	
	if(del)go(x,fa,-1);//假如要删掉自己的信息，就暴力地删掉
}

int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)
	scanf("%d %d",&x,&y),buildroad(x,y),buildroad(y,x);
	for(int i=1;i<=n;i++)
	scanf("%d",&col[i]);
	dfs1(1,0);
	dfs2(1,0,false);
	scanf("%d",&m);
	for(int i=1,x;i<=m;i++)
	scanf("%d",&x),printf("%d\n",ans[x]);
}

```





#### 虚树

virtual tree

对于原树上的 $k$ 个关键点，它们及其两两LCA所组成的树是虚树

实现方法是把关键点按 DFS 序排序，对两两相邻的关键点求 LCA，哈希表判重。根据原树的祖先后代关系建树。

在虚树里，只要保证祖先后代的关系没有改变，就可以随意添加原树的非关键点。

使用单调栈建立虚树。先把根节点 $1$ 加入栈。按 DFS 序遍历节点，若当前节点与栈顶节点的 LCA 是栈顶，直接入栈；否则，把 LCA 连栈顶建虚树，栈顶弹栈。根据栈顶节点 DFS 序和次大节点(栈顶下方节点) DFS 序与 LCA 作比较，判断 LCA 是否入栈过，如果 LCA 未入栈，则 LCA 入栈。然后才新节点入栈。遍历结束后，栈内形成链，两两相连即可。

细节优化是可以把清空邻接表改成有一个从未入栈的元素入栈的时候清空该元素对应的邻接表。

> 例题洛谷P2495：有 $n(2\le n\le2.5\times10^5)$ 节点的树，边带权，有 $m(1\le m\le5\times10^5)$ 次询问，每次询问有 $k(1\le k\le n,\sum k\le5\times10^5)$ 个点，对每次询问，删掉树上若干边，使得删的边权和最小，满足删后根节点 $1$ 不能到达任一个给定询问点

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 500010
#define mm 10000
#define big 0x3ffffffffffffffa
#define mlg 20
struct edge
{
    ll to, nx, w;
} e[mn << 1], e2[mn << 1];
ll hd[mn], hd2[mn], cnt, cnt2, n, q, k;
void adde(const ll &u, const ll &v, const ll &w, ll *hd, ll &cnt, edge *e)
{
    e[++cnt] = {v, hd[u], w};
    hd[u] = cnt;
}
ll dfn[mn], dep[mn], fa[mn][mlg], mi[mn], m[mn], lst[mn];
bool vis[mn];
ll num, top, dfscnt, stk[mn];

void dfs1(ll u)
{
    ll k = 0;
    for (; fa[u][k]; ++k)
    {
        fa[u][k + 1] = fa[fa[u][k]][k];
    }
    m[u] = k;
    dfn[u] = ++dfscnt;
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (!dfn[v])
        {
            dep[v] = dep[u] + 1;
            mi[v] = min(mi[u], e[i].w);
            fa[v][0] = u;
            dfs1(v);
        }
    }
}

ll lca(ll x, ll y)
{
    if (dep[x] < dep[y])
    {
        swap(x, y);
    }
    for (ll i = m[x]; i >= 0; --i)
    {
        if (dep[fa[x][i]] >= dep[y])
        {
            x = fa[x][i];
        }
    }
    if (x == y)
    {
        return x;
    }
    for (ll i = m[x]; i >= 0; --i)
    {
        if (fa[x][i] != fa[y][i])
        {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}

ll dfs2(ll u) //dp
{
    ll sum = 0;
    for (ll i = hd2[u], v; i; i = e2[i].nx)
    {
        v = e2[i].to;
        sum += dfs2(v);
    }
    ll res = vis[u] ? mi[u] : min(mi[u], sum); //vis[u] hd.d af
    hd2[u] = 0, vis[u] = false;                //clear
    return res;
}

#define sc(x) scanf("%lld", &x)
signed main()
{
    sc(n);
    for (ll i = 1, u, v, w; i < n; ++i)
    {
        sc(u), sc(v), sc(w);
        adde(u, v, w, hd, cnt, e), adde(v, u, w, hd, cnt, e);
    }
    mi[1] = big;
    dfs1(1);
    for (sc(q); q; --q)
    {
        sc(k);
        for (ll i = 1; i <= k; ++i)
        {
            sc(lst[i]), vis[lst[i]] = true;
        }
        sort(lst + 1, lst + 1 + k, [](const ll &x, const ll &y)
             { return dfn[x] < dfn[y]; });
        stk[top = 1] = lst[1];
        for (ll i = 2; i <= k; ++i)
        {
            ll now = lst[i], lc = lca(now, stk[top]);
            while (true)
            {
                if (dep[lc] >= dep[stk[top - 1]])
                {
                    if (lc != stk[top])
                    {
                        adde(lc, stk[top], 0, hd2, cnt2, e2);
                        if (lc != stk[top - 1])
                        {
                            stk[top] = lc;
                        }
                        else
                        {
                            --top;
                        }
                    }
                    break;
                }
                else
                {
                    adde(stk[top - 1], stk[top], 0, hd2, cnt2, e2);
                    --top;
                }
            }
            stk[++top] = now;
        }
        while (--top)
        {
            adde(stk[top], stk[top + 1], 0, hd2, cnt2, e2);
        }
        printf("%lld\n", dfs2(stk[1])), cnt2 = 0;
    }
    return 0;
}
```



#### 点分治

求解问题：枚举所有路径，计算相关的信息

树上路径可以分为两种：一种是经过根的，一种是不经过的；对前者，一种根作为端点，一种不作为端点，其中后者等效于两条前者。

预处理：求重心，然后求以重心为根各子树的大小。然后从重心开始点分治。

在每次点分治过程：当前重心为根，DFS计算所有以该点为端点的路径所要求的值，然后删掉该点，对该点的每个子树，再次求重心，然后求新重心为根各子树大小，然后以新重心为根继续递归执行上述过程。

经过点分治，可以求出满足可加的每一条路径的值。点分治的复杂度是 $O(n\log n)$

> 例题洛谷P3806：$n(1\le n\le10^4)$ 点带权树，$m(1\le m\le100)$ 次询问，每次询问求树上是否有距离为 $k$ 个点对，有就输出 `AYE` 
>

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 10010
#define mm 105
#define mb 10000010
struct edge
{
    ll to, nx, w;
} e[mn << 2];
ll hd[mn], ecnt;
void adde(ll &u, ll &v, ll &w)
{
    e[++ecnt] = {v, hd[u], w};
    hd[u] = ecnt;
}
bool died[mn], bin[mb], suc[mm];
ll n, m, q[mn];
ll p, sz[mn], n2, smx[mn];
void dfs(ll u, ll fa)
{
    sz[u] = 1, smx[u] = 0;
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (v == fa || died[v])
        {
            continue;
        }
        dfs(v, u);
        sz[u] += sz[v];
        smx[u] = max(smx[u], sz[v]);
    }
    smx[u] = max(smx[u], n2 - smx[u]);
    if (smx[u] < smx[p])
    {
        p = u;
    }
}
ll ds[mn], dcnt, d[mn];
void dfs2(ll u, ll fa)
{
    ds[++dcnt] = d[u];
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (v == fa || died[v])
        {
            continue;
        }
        d[v] = d[u] + e[i].w;
        dfs2(v, u);
    }
}
stack<ll> qd;
void dfz(ll u, ll fa)
{
    bin[0] = true;
    qd.push(0);
    died[u] = true;
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (v == fa || died[v])
        {
            continue;
        }
        d[v] = e[i].w;
        dfs2(v, u);
        for (ll j = 1; j <= dcnt; ++j)
        {
            for (ll k = 1; k <= m; ++k)
            {
                if (q[k] >= ds[j])
                {
                    suc[k] |= bin[q[k] - ds[j]];
                }
            }
        }
        for (ll j = 1; j <= dcnt; ++j)
        {
            if (ds[j] < mb)
            {
                bin[ds[j]] = true;
                qd.push(ds[j]);
            }
        }
        dcnt = 0;
    }
    while (!qd.empty())
    {
        bin[qd.top()] = false;
        qd.pop();
    }
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (v == fa || died[v])
        {
            continue;
        }
        n2 = sz[v], p = 0;
        dfs(v, u), dfs(p, 0);
        dfz(p, u);
    }
}
signed main()
{
    sc(n), sc(m), n2 = n, smx[0] = 0x7fffffff;
    for (ll i = 1, u, v, w; i < n; ++i)
    {
        sc(u), sc(v), sc(w), adde(u, v, w), adde(v, u, w);
    }
    for (ll i = 1; i <= m; ++i)
    {
        sc(q[i]);
    }
    dfs(1, 0), dfs(p, 0);
    dfz(p, 0);
    for (ll i = 1; i <= m; ++i)
    {
        printf(suc[i] ? "AYE\n" : "NAY\n");
    }
    return 0;
}
```



#### Prufer 序列

常用于解决与度数相关的树上计数问题

将无根代表号树与整数序列一一对应的方法

树转 Prufer 序列：每次选择一个编号最小的叶结点并删掉它，然后在序列中记录下它连接到的那个结点。重复 $n-2$ 次后就只剩下两个结点

Prufer 序列转树：每次选择度为 $1$ 的节点与当前点连接

Prufer 序列性质：剩下的 $2$ 个节点其中一个是编号最大节点；每个节点在序列出现的次数是度数减一

Cayley 公式：完全图 $K_n$ 有 $n^{n-2}$ 棵生成树

> 有 $n$ 点树，给定度数，则树可能的形态数为 $\dfrac{(n-2)!}{\prod_{i=1}^n(d_i-1)!}$
>
> 含未知度数时，设已知点数为 $k$ ，已知度数和为 $\sum(d_i-1)=s$ ，则答案为 $\dfrac{C_{n-2}^ss!(n-k)^{n-2-s}}{\prod_{i=1}^k(d_i-1)!}$
>
> $n$ 点 $m$ 边带标号无向图有 $k$ 个连通块，添加 $k-1$ 条边使得图连通，方案数为 $n^{k-2}\prod_{i=1}^k s_i$ ， $s_i$ 是每个连通块数量，有 $\sum_{i=1}^ns_i=n$ 

> 例题洛谷P6086：输入 $n,m(2\le n\le5\times10^6,1\le m\le2)$ ，设根为 $n$ ，$m=1$ 时输入 $[1,n-1]$ 的父亲序列，$m=2$ 输入 Prufer 序列，将其转为另一方。设一个序列的值为 $\oplus_{i=1}^{len}i\times a_i$ ，求转换后序列权值

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define MAXN 5000002
ll n, m, f[MAXN], p[MAXN], d[MAXN];
long long ans;
signed main()
{
    scanf("%d%d", &n, &m);
    if (m == 1) //树转Prufer
    {
        for (ll i = 1; i < n; ++i)
            scanf("%d", f + i), ++d[f[i]];
        for (ll i = 1, j = 1; i <= n - 1; ++i, ++j)
        {
            while (d[j])
                ++j;
            p[i] = f[j];
            while (i <= n - 2 && !--d[p[i]] && p[i] < j)
                p[i + 1] = f[p[i]], ++i;
        }
        for (ll i = 1; i <= n - 2; ++i)
            ans ^= 1LL * i * p[i];
    }
    else // Prufer转树
    {
        for (ll i = 1; i <= n - 2; ++i)
            scanf("%d", p + i), ++d[p[i]];
        p[n - 1] = n;
        for (ll i = 1, j = 1; i < n; ++i, ++j)
        {
            while (d[j])
                ++j;
            f[j] = p[i];
            while (i < n && !--d[p[i]] && p[i] < j)
                f[p[i]] = p[i + 1], ++i;
        }
        for (ll i = 1; i < n; ++i)
            ans ^= 1LL * i * f[i];
    }
    printf("%lld", ans);
    return 0;
}
```



#### 二叉树遍历

##### 先中求后

离散化优化，复杂度 $O(n)$ ，以洛谷P1827为例(顶点值不重复)

```c++
#include <bits/stdc++.h>
using namespace std;
string pre, mid, post;
typedef long long ll;
ll n, idx, h[256];     // index of pre
void dfs(ll lf, ll rf) // search in [lf,rf)
{
    if (lf >= rf || idx == n)
        return;
    char v = pre[idx++];
    ll cf = h[v];
    dfs(lf, cf);
    dfs(cf + 1, rf);
    post.push_back(v);
}
signed main()
{
    cin >> mid >> pre;
    n = mid.size();
    for (ll i = 0, ie = mid.size(); i < ie; ++i)
        h[mid[i]] = i;
    dfs(0, n);
    cout << post;
    return 0;
}
```



##### 中后求先

离散化优化，复杂度 $O(n)$ ，洛谷P1030为例

```c++
//输入中序和后续，返回先序
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll h[256], n;
char mid[256], post[256];
void dfs(ll mlf, ll mrf, ll plf, ll prf) // mid,post
{
    if (mlf > mrf || plf > prf)
        return;
    char c = post[prf];
    int cf = h[(ll)c];
    cout << c;
    dfs(mlf, cf - 1, plf, plf + cf - mlf - 1);
    dfs(cf + 1, n - 1, plf + cf - mlf, prf - 1);
}
signed main()
{
    cin >> mid >> post;
    n = strlen(mid);
    for (ll i = 0, ie = n; i < ie; ++i)
        h[(ll)mid[i]] = i;
    dfs(0, n - 1, 0, n - 1); //[0,n-1],[0,n-1]
    return 0;
}
```



##### 先后求中

离散化，答案数为先序中 $AB$ 与后序中 $BA$ 相等数 $x$ 的 $2^x$ ，复杂度 $O(n)$ (SCNUOJ 1423为例)

```c++
#include <bits/stdc++.h>
#define mod 1000000007
#define mn 100002
typedef long long ll;
ll n, a[mn], b[mn], c[mn], r = 1;
signed main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i) //先序
        scanf("%lld", a + i);
    for (ll i = 1; i <= n; ++i) //后序
        scanf("%lld", b + i), c[b[i]] = i;
    for (ll i = 1; i <= n; ++i)
    {
        ll k = c[a[i]];
        if (i != n && a[i + 1] == b[k - 1])
            (r *= 2) %= mod;
    }
    printf("%lld", r);
    return 0;
}
```





#### 杂项

##### 最小距离和

> 例题P1364：给定 $n(1\le n\le100)$ 节点二叉树(输入为 $w,u,v$ 为第 $i$ 个节点点权和左右儿子( $0$ 是无子))，求最小距离和(以某点为原点各点点权乘以路径长)( $1\le w\le10^5$ )

设 $dp$ 为距离和，对 $u$ 的邻点 $v$ ，有 $dp[v]=dp[u]+size[1]-2size[v]$

在dp[u]的基础上当根从u变为v的时候，v的子树的所有结点的距离都减少1，那么总距离就减少size[v]，同时，以v为根的子树以外的所有节点路程都增加了1，总路程就增加了size[1]-size[v]

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 105
#define sc(x) scanf("%lld", &x)
struct edge
{
    ll to, nx;
} e[mn << 1];
ll hd[mn], cnt, siz[mn], w[mn], dp[mn], n, ans = 0x7fffffff;
void adde(ll u, ll v)
{
    e[++cnt] = {v, hd[u]};
    hd[u] = cnt;
}
void dfs1(ll u, ll fa, ll d)
{
    siz[u] = w[u];
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (v == fa)
        {
            continue;
        }
        dfs1(v, u, d + 1);
        siz[u] += siz[v];
    }
    dp[1] += d * w[u];
}
void dfs2(ll u, ll fa)
{
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (v == fa)
        {
            continue;
        }
        dp[v] = dp[u] + (siz[1] - siz[v]) - siz[v];
        dfs2(v, u);
    }
    ans = min(ans, dp[u]);
}
signed main()
{
    scanf("%lld", &n);
    for (ll i = 1, x, y; i <= n; ++i)
    {
        sc(w[i]), sc(x), sc(y);
        if (x)
        {
            adde(i, x), adde(x, i);
        }
        if (y)
        {
            adde(i, y), adde(y, i);
        }
    }
    dfs1(1, 0, 0);
    dfs2(1, 0);
    printf("%lld", ans);
    return 0;
}
```





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

