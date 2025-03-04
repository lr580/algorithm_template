<hr/>
<div style="font-size:36px;font-weight:900;margin:-14px 10px" align="center">lr580's 算法模板</div>
<hr/>

![image-20220325120131181](img/image-20220325120131181.png)

<div align="center" style="font-size:18px">Version 1.2.3, last built at 2025/3/5</div>

<div STYLE="page-break-after: always;"></div>

[toc]

<div STYLE="page-break-after: always;"></div>



# lr580's 算法模板

## 数学

### 公式

#### 常用符号

1. $x|y$ 表示 $x$ 整除 $y$ ，例如 $2|8$ ，
2. $x\bot y$ 表示 $x,y$ 互质
3. $gcd(x,y)=(x,y)$ 最大公约数
4. $lcm(x,y)=[x,y]$ 最小公倍数
5. $\lfloor x\rfloor$ 向下取整
6. $\lceil x\rceil$ 向上取整
7. $C^m_n=C(n,m)=(\matrix{n\\m})=\dfrac{n!}{m!(n-m)!}$ ，若 $n < m$ 或 $m < 0$ 得 $0$，$C(n,0)=1$
8. $A_n^m=P_n^m=P(n,m)=\dfrac{n!}{(n-m)!}=\prod_{i=n-m+1}^ni$ ，若 $n < m$ 得 $0$ 



#### 组合数学

##### 排列组合

元素依次排成一个圆圈的排列称作环排列，$S$ 的 $r$ 环排列数等于$\dfrac{P(n,r)}r$

组合数性质：设正整数 $n,r$，有

- $C(n,r)=\dfrac nrC(n-1,r-1)$
- $C(n,r)=\dfrac{n-r+1}{r}C(n,r-1)$
- $C(n,r)=C(n,n-r)$
- $C(n,r)=C(n-1,r-1)+C(n-1,r)$  (Pascal公式/杨辉三角)

二项式定理 $n$ 是正整数，对一切 $x,y$ ，有：
$$
(x+y)^n=\sum_{k=0}^n\begin{pmatrix}n\\k\end{pmatrix}x^ky^{n-k}
$$



多重组合数(即多重集的全排列)公式：
$$
\begin{pmatrix}n\\n_1,n_2,\cdots n_r\end{pmatrix}=\dfrac{n!}{n_1!n_2!\cdots n_t!}
$$
二项式定理的多项式形式：
$$
(x_1+\cdots+x_t)^n=\sum_{满足n_1+\cdots+n_t=n的非负整数解}
\begin{pmatrix}n\\n_1,n_2,\cdots n_t\end{pmatrix}
x_1^{n_1}x_2^{n_2}\cdots x_t^{n_t}
$$
从多重集 $S=\{n_1\cdot a_1,\cdots n_k\cdot a_k\}$ 选 $r$ 个元素的多重集组合数，为 $x_1+\cdots +x_k=r$ 的非负整数解数目，插板法知为 $\begin{pmatrix}r+k-1\\k-1\end{pmatrix}$ (条件： $r < \min n_i$ )，任意条件为：
$$
\sum_{p=0}^k(-1)^p\sum_{A}
\begin{pmatrix}
k+r-1-\sum_An_{A_i}-p\\k-1
\end{pmatrix}
$$
$A$ 是枚举子集，满足 $|A|=p,A_i < A_{i+1}$ 



$n$ 个自然数选 $k$ 个，任两个数都不相邻： $\begin{pmatrix}n-k+1\\k\end{pmatrix}$

$i$ 数错位排列数公式： $d[0]=d[1]=0,d[2]=1$
$$
d[n]=(n-1)(d[n-1]+d[n-2])=n!(1-\dfrac{1}{1!}+-\dfrac{1}{2!}+\cdots+(-1)^n\dfrac1{n!})
$$
$d_n=(n-1)(d_{n-1}+d_{n-2})=nd_{n-1}+(-1)^n$。且增长速度 $\lim_{n\to\infty}\dfrac{d_n}{n}=\dfrac1e$

$n$ 个数有 $m$ 个乱的情况数： $C_n^md[m]$ 

$n$ 人围圈排列数 $Q_n^n=(n-1)!$ ，部分圆排列公式 $Q_n^r=\dfrac{A_n^r}r$



排序不等式：逆序和 $\le$ 乱序和 $\le$ 顺序和。给定升序数组 $a,b$，设 $c$ 是 $b$ 的排列，则求和 $\sum_{i=1}^na_ib_{n-i+1}\le \sum_{i=1}^na_ic_i\le \sum_{i=1}^na_ib_i$



推论：

- $\sum_{k=0}^n\begin{pmatrix}n\\k\end{pmatrix}=2^n,n\in N$
- $\sum_{k=0}^n(-1)^k\begin{pmatrix}n\\k\end{pmatrix}=0,n\in N$
- $\sum_{l=0}^n\begin{pmatrix}l\\k\end{pmatrix}=\begin{pmatrix}n+1\\k+1\end{pmatrix},n,k\in N$
- $\sum_{i=0}^m\begin{pmatrix}n\\i\end{pmatrix}\begin{pmatrix}m\\m-i\end{pmatrix}=\begin{pmatrix}m+n\\m\end{pmatrix},n\ge m$
- $\sum_{i=0}^n\begin{pmatrix}n\\i\end{pmatrix}^2=\begin{pmatrix}2n\\n\end{pmatrix}$
- $\begin{pmatrix}n\\r\end{pmatrix}\begin{pmatrix}r\\k\end{pmatrix}=\begin{pmatrix}n\\k\end{pmatrix}\begin{pmatrix}n-k\\r-k\end{pmatrix},n\ge r\ge k,n,r,k\in N$
- $\sum_{k=0}^r\begin{pmatrix}m\\k\end{pmatrix}\begin{pmatrix}n\\r-k\end{pmatrix}=\begin{pmatrix}n+m\\r\end{pmatrix},n,m,r\in N,r\le\min(m,n)$
- $\sum_{k=0}^n\begin{pmatrix}m\\k\end{pmatrix}\begin{pmatrix}n\\k\end{pmatrix}=\begin{pmatrix}m+n\\m\end{pmatrix},m,n\in N$
- $\sum_{i=0}^ni\begin{pmatrix}n\\i\end{pmatrix}=n2^{n-1}$
- $\sum_{i=0}^n\begin{pmatrix}n-i\\i\end{pmatrix}=fib_{n+1}$

> 某些时候可以两边求导再求

> 枚举所有组合可以使用 Gosper's Hack 技巧：
>
> ```c++
> unsigned int nextSubset(unsigned int subset) {
>     unsigned int u = subset & -subset;
>     unsigned int v = subset + u;
>     return v | (((v ^ subset) / u) >> 2);
> }
> void gospersHack(int k, int n) {
>     unsigned int subset = (1 << k) - 1;
>     unsigned int limit = (1 << n);
>     while (subset < limit) {
>         for (int i = 0; i < n; ++i) {
>             if (subset & (1 << i)) {
>                 std::cout << i + 1 << " ";
>             }// Process the subset here
>         }// For example, printing it out
>         std::cout << std::endl;
>         subset = nextSubset(subset);
>     }
> }
> ```
>
> 

**容斥原理：**

$U$ 中元素有 $n$ 种不同属性 $p_i$ ，拥有属性 $p_i$ 的元素构成集合 $S_i$
$$
|\bigcup_{i=1}^nS_i|=\sum_{m=1}^n(-1)^{m-1}\sum_{a_i<a_{i+1}}|\bigcap_{i=1}^mS_{a_i}|
\\
|\bigcap_{i=1}^nS_i|=|U|-|\bigcup_{i=1}^n\overline{S_i}|
$$


**抽屉原理：**

把 $mn+1$ 个物体放到 $n$ 个抽屉里，至少有一个抽屉至少有 $m+1$ 个物体

把 $mn-1$ 个物体放到 $n$ 个抽屉里，至少有一个抽屉至少有 $m-1$ 个物体

将 $n$ 物放到 $k$ 抽屉，至少一个有不少于 $\lceil\dfrac nk\rceil$ 个物体

> 应用：选 $n$ 个正整数的若干个数， $n\ge m$ 时选出的数必然存在可以被 $m$ 整除



##### 卡特兰数

$$
H[0]=1\\
H[n+1]=\sum_{i=0}^nH[i]\cdot H[n-i-1]
$$

从 $0$ 到 $5$ 分别是 $1,1,2,5,14,42$ ，`H[35]`  为 19 位长度，`H[36]` 爆long long 
$$
H[n]=H[n-1]\times\dfrac{4n-2}{n+1}\\
H[n]=\dfrac{C(2n,n)}{n+1}\\
H[n]=C(2n,n)-C(2n,n-1)
$$
常见应用：

- 矩阵连乘： P=a1×a2×a3×……×an，依据乘法结合律，不改变其顺序，只用括号表示成对的乘积，试问有几种括号化的方案。h(n) 种
- 一个栈(无穷大)的进栈序列为 1，2，3，…，n，有多少个不同的出栈序列
- 在一个凸多边形中，通过若干条互不相交的对角线，把这个多边形划分成若干个三角形方案数如 n=6,f(6)=14
- 给定 n 个节点，能构成多少不同的二叉搜索树
- 给定 n 对括号，求括号正确配对的字符串数
- $2n$ 个黑白，使得前缀黑色小于白色的方案数
- 圆上 $2n$ 点用 $n$ 条不相交线段连接的方案数
- $n$ 人有 $50$ 元，$n$ 人有 $100$ 元买 $50$ 元物品，排队方案数使得 $2n$ 人都可找零
- $2n$ 人交 $5$ 元， $n$ 人只有 $5$ 元一张，另 $n$ 人 $10$ 元一张，问多少种方案只要有 $10$ 元人交钱就有 $5$ 元找零
- $n$ 个 $+1$ 和 $n$ 个 $-1$ 构成 $2n$ 项 $a_1,\cdots a_{2n}$ 满足前缀和 $a_1+\cdots+a_k\ge0(k=1,2,\cdots2 n)$ 的数列方案数
- 从 $(0,0)$ 到 $(m,n)$ 的非降路径数 $\begin{pmatrix}n+m\\m\end{pmatrix}$
- 从 $(0,0)$ 到 $(n,n)$ 除端点不接触 $y=x$ 非降路径数 $2\begin{pmatrix}2n-2\\n-1\end{pmatrix}-2\begin{pmatrix}2n-2\\n\end{pmatrix}$
- 从 $(0,0)$ 到 $(n,n)$ 除端点不穿过 $y=x$ 非降路径数 $\dfrac2{n+1}\begin{pmatrix}2n\\n\end{pmatrix}$



##### 斯特林数

**第一类**：(无符号:)将n个不同元素构成m个非空圆排列的数目( $[A,B,C]\neq[C,B,A]$ 为不同圆排列(轮换) )。(斯特林轮换数)无符号为 $s_u(n,m),s(n,m)$ 或$\left[\matrix{n\\m}\right]$ ，有符号为 $s_s(n,m)$ ，分别表现升阶函数和降阶函数的各项系数。
$$
\begin{align}
x^{n\downarrow}&=x(x-1)(x-2)\dots(x-n+1)=\sum_{k=0}^ns_s(n,k)x^k\\
x^{n\uparrow}&=x(x+1)(x+2)\dots(x+n-1)=\sum_{k=0}^ns_u(n,k)x^k\\
s_s(n,u)&=(-1)^{n+m}s_u(n,m)\\
s_u(n+1,m)&=s_u(n,m-1)+n\cdot s_u(n,m)\\
s_s(n+1,m)&=s_s(n,m-1)-n\cdot s_s(n,m)\\
\end{align}
$$

> 例题：有 n 个仓库，每个仓库有两把钥匙，共 2n 把钥匙。同时又有 n 位官员。问如何放置钥匙使得所有官员都能够打开所有仓库？（只考虑钥匙怎么放到仓库中，而不考虑官员拿哪把钥匙。）那如果官员分成 m 个不同的部，部中的官员数量和管理的仓库数量一致。那么有多少方案使得，同部的所有官员可以打开所有本部管理的仓库，而无法打开其他部管理的仓库？（同样只考虑钥匙的放置。）
>
> 第一问就是打开将钥匙放入仓库构成一个环：1号仓库放2号钥匙，2号仓库放3号钥匙……n号仓库放1号钥匙。这种情况相当于钥匙和仓库编号构成一个圆排列方案数是$(n-1)!$种。
>
> 而第二问就对应的将n个元素分成m个圆排列，方案数就是第一类无符号Stirling数$s_u(n,m)$。如要要考虑官员的情况，只需再乘上$n!$即可。

p5409/p5408



**第二类**：(斯特林子集数)把n个互异元素分成m个互不区分非空集合，记为$S(n,m)$或$\left\{\matrix{n\\m}\right\}$ 
$$
\begin{align}
S(n,m)&=\frac{1}{m!}\sum_{k=0}^m(-1)^k\left(\matrix{m\\k}\right)(m-k)^n=\sum_{i=0}^m\dfrac{(-1)^{m-i}i^n}{i!(m-i)!}\\
S(n+1,m)&=S(n,m-1)+m\cdot S(n,m)
\end{align}
$$

递推上与第一类的区别在于$m$还是$n$作系数和正负问题。

求斯特林数，可以套用公式二，使用 $dp$ 。注意到初始状态是$S(n,1)=S(n,n)=1$ 。$S(n,0)=0^n$ 。求同一行( $n$ 相同)斯特林数可以用通项卷积，复杂度 $O(n\log n)$

(p5396/p5395)



##### 生成函数

可以解决组合问题(排列则乘一个阶乘变成组合)
$$
\begin{align}
e^x&=\sum_{n=0}^\infty\frac{x^n}{n!}=1+\dfrac x{1!}+\dfrac{x^2}{2!}+\cdots,x\in\mathbf{R}
\\
e^{-x}&=1-\dfrac{x}{1!}+\dfrac{x^2}{2!}-\cdots
\\
\dfrac{e^x+e^{-x}}2&=(1+\dfrac{x^2}{2!}+\dfrac {x^4}{4!}\cdots)
\\
\dfrac1{1-x^a}&=1+x^a+x^{2a}+\cdots
\end{align}
$$




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

不定方程 $\sum_{i=1}^mx_i=n$ 非负整数解个数是 $C_{n+m-1}^{m-1}=C_{n+m-1}^n$

正整数 $n$ 拆分为 $m$ 个正整数即 $a_1x_1+a_2x_2+\cdots+a_mx_m=n$ ，若不允许重复，生成函数为 $\prod_{i=1}^m(1+x^{a_i})$ ，若允许重复，为 $\prod_{i=1}^m\dfrac1{1-x^i}$ 。均取系数 $x^n$。不允许就先每个至少取 $1$ 所以乘 $x^m$ 

> 例洛谷P2386- $m$ 个相同苹果放 $n$ 相同盘子,可空盘, 求方案数

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 30
ll n, m, t, dp[mn][mn]; //考虑前i个生成函数, x^j系数
signed main()
{
    dp[0][0] = 1;
    for (ll i = 1; i < mn; ++i) //暴力多项式乘法
        for (ll j = 0; j < mn; j += i) // 1+x^i+x^{2i}+...
            for (ll k = 0; k + j < mn; ++k) // 枚举dp[i-1][k]
                dp[i][k + j] += dp[i - 1][k];
    for (sc(t); t--;)
    {
        sc(m), sc(n); // m无区别球放n无区别盒,可空盒
        printf("%lld\n", dp[n][m]);
    } //等价于前n个生成函数,系数为x^m
    return 0;
}
```

一种非正整数划分的 DP 解法 (时空 $O(nm)$ )

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 30
ll n, m, t, dp[mn][mn]; // m球n盒方案数
signed main()
{
    for (ll i = 0; i < mn; ++i) //无球或单盒为1
        dp[0][i] = dp[i][1] = 1;
    for (ll i = 1; i < mn; ++i)
        for (ll j = 1; j < mn; ++j)
            if (j > i) //盒比球多,(?,0)=(?)
                dp[i][j] = dp[i][i];
            else //放满时每盒拿走一个;放不满时拿走空盒一个
                dp[i][j] = dp[i - j][j] + dp[i][j - 1];
    for (sc(t); t--;)
        sc(m), sc(n), printf("%lld\n", dp[m][n]);
    return 0;
}
```

> P5824-$n$ 球 $m$ 盒 $(1\le n,m\le2\times 10^5)$，求放球方案对 $998244343$ 取模。

1. 球互不同，盒互不同。$m^n$
2. 球互不同，盒互不同，每盒最多装一个球。$A_m^n$
3. 球互不同，盒互不同，每盒最少装一个球。容斥枚举空盒数 $\sum_{i=0}^m(-1)^iC_m^i(m-i)^n$
4. 球互不同，盒相同。二项式反演求第二类斯特林数 $\sum_{i=1}^m S(n,i)$
5. 球互不同，盒相同，每盒最多装一个球。$[n\le m]$
6. 球互不同，盒相同，每盒最少装一个球。$S(n,m)$
7. 球相同，盒互不同。隔板法 $C_{n+m-1}^{m-1}$
8. 球相同，盒互不同，每盒最多装一个球。$C_m^n$
9. 球相同，盒互不同，每盒最少装一个球。隔板法 $C_{n-1}^{m-1}$
10. 球相同，盒相同。分拆数 $p(n,m)$，使用生成函数多项式求 $\exp$ 后求逆
11. 球相同，盒相同，每盒最多装一个球。$[n\le m]$
12. 球相同，盒相同，每盒最少装一个球。$p(n-m,m)$

含：

- 排列组合，快速幂，欧拉筛求线性 $i^k$
- NTT，多项式的求逆、求导、积分、指数、对数
- 求整行第二类斯特林数、求同 $k$ 部的整列分拆数

的综合模板题：

```c++
// #pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define N 524293
#define p 998244353
using ll = long long;
#define add(x,y) (x+y>=p?x+y-p:x+y)
#define dec(x,y) (x<y?x-y+p:x-y)
using namespace std;

inline int power(int a,int t){
    int res = 1;
    while(t){
        if(t&1) res = (ll)res*a%p;
        a = (ll)a*a%p;
        t >>= 1;
    }
    return res;
}

struct poly{
    int a[N];
    int t;
    inline int operator [] (const int& x) const{ return a[x]; }
    inline int& operator [] (const int& x){ return a[x]; }
};

int rev[N],rt[N],inv[N],fac[N],ifac[N],pw[N],pr[N>>1];
int siz;

void init(int n){
    int w,lim = 1;
    while(lim<=n) lim <<= 1,++siz;
    for(int i=1;i!=lim;++i) rev[i] = (rev[i>>1]>>1)|((i&1)<<(siz-1));
    inv[1] = rt[lim>>1] = 1;
    w = power(3,(p-1)>>siz);
    for(int i=(lim>>1)+1;i!=lim;++i) rt[i] = (ll)rt[i-1]*w%p;
    for(int i=(lim>>1)-1;i;--i) rt[i] = rt[i<<1];
    for(int i=2;i<=lim;++i) inv[i] = (ll)(p-p/i)*inv[p%i]%p;
}

inline int getlen(int n){
	return 1<<(32-__builtin_clz(n));
}

inline void NTT(poly &f,int type,int lim){
    if(type==1) reverse(f.a+1,f.a+lim);
    static unsigned long long a[N];
    int x,shift = siz-__builtin_ctz(lim);
    for(int i=0;i!=lim;++i) a[rev[i]>>shift] = f[i];
    for(int mid=1;mid!=lim;mid<<=1)
    for(int j=0;j!=lim;j+=(mid<<1))
    for(int k=0;k!=mid;++k){
        x = a[j|k|mid]*rt[mid|k]%p;
        a[j|k|mid] = a[j|k]-x+p;
        a[j|k] += x;
    }
    for(int i=0;i!=lim;++i) f[i] = a[i]%p;
    if(type==1) return;
    x = inv[lim];
    for(int i=0;i!=lim;++i) f[i] = (ll)f[i]*x%p;
}

poly inverse(poly f){
	poly g,h,q;
	memset(g.a,0,sizeof(g.a));
	int lim = 1,n = f.t,top = 0;
	int s[30];
	while(n){
		s[++top] = n;
		n >>= 1;
	}
	g[0] = power(f[0],p-2);
	while(top--){
		g.t = n = s[top+1];
		while(lim<=(n<<1)) lim <<= 1;
		memcpy(h.a,f.a,(n+1)<<2);
		memcpy(q.a,g.a,(n+1)<<2);
		memset(h.a+n+1,0,(lim-n)<<2);
		NTT(g,1,lim),NTT(h,1,lim);
		for(int i=0;i!=lim;++i) g[i] = (ll)g[i]*g[i]%p*h[i]%p;
		NTT(g,-1,lim);
		for(int i=0;i<=n;++i) g[i] = dec(add(q[i],q[i]),g[i]);
		memset(g.a+n+1,0,(lim-n)<<2);
	}
	return g;
} 

inline poly deriv(poly f){ //多项式求导
	for(int i=0;i!=f.t;++i) f[i] = (ll)f[i+1]*(i+1)%p;
	f[f.t] = 0;
	return f;
}

inline poly integ(poly f){ //多项式积分
	for(int i=f.t;i;--i) f[i] = (ll)f[i-1]*inv[i]%p;
	f[0] = 0;
	return f;
}

inline poly log(poly f){
	poly g = inverse(f);
	f = deriv(f);
	int lim = getlen(f.t<<1);
	NTT(f,1,lim),NTT(g,1,lim);
	for(int i=0;i!=lim;++i) f[i] = (ll)f[i]*g[i]%p;
	NTT(f,-1,lim);
	memset(f.a+f.t+1,0,(lim-f.t)<<2);
	return integ(f);
}

poly exp(poly f){
	poly g,h;
	memset(g.a,0,sizeof(g.a));
	int n = f.t,lim = 1,top = 0;
	int s[30];
	while(n){
		s[++top] = n;
		n >>= 1;
	}
	g[0] = 1;
	while(top--){
		g.t = n = s[top+1];
		while(lim<=(n<<1)) lim <<= 1;
		memcpy(h.a,g.a,(n+1)<<2);
		memset(h.a+n+1,0,(lim-n)<<2);
		g = log(g);
		for(int i=0;i<=n;++i) g[i] = dec(f[i],g[i]);
		g[0] = add(g[0],1);
		NTT(g,1,lim),NTT(h,1,lim);
		for(int i=0;i!=lim;++i) g[i] = (ll)g[i]*h[i]%p;
		NTT(g,-1,lim);
		memset(g.a+n+1,0,(lim-n)<<2);
	}
	return g;
}

inline int C(int n,int m){
    if(n<m) return 0;
    return (ll)fac[n]*ifac[m]%p*ifac[n-m]%p;
}

inline int A(int n,int m){
    if(n<m) return 0;
    return (ll)fac[n]*ifac[n-m]%p;
}

void sieve(int lim,int k){
    int cnt = 0;
    pw[1] = 1; //利用积性函数求 pw[i]=i^k
    for(int i=2;i<=lim;++i){
        if(!pw[i]){
            pr[++cnt] = i; //欧拉筛
            pw[i] = power(i,k);
        }
        for(int j=1;j<=cnt&&i*pr[j]<=lim;++j){
            pw[i*pr[j]] = (ll)pw[i]*pw[pr[j]]%p;
            if(i%pr[j]==0) break;
        }
    }
}

int n,m,lim,sum;
poly F,G;

int main(){
    scanf("%d%d",&n,&m);
    lim = max(n,m);
    sieve(lim,n);
    printf("%d\n",pw[m]); // I1
    init(lim<<1);
    fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
    for(int i=2;i<=n+m;++i) ifac[i] = fac[i] = (ll)fac[i-1]*i%p;
    ifac[n+m] = power(fac[n+m],p-2);
    for(int i=n+m-1;i;--i) ifac[i] = (ll)ifac[i+1]*(i+1)%p;
    printf("%d\n",A(m,n)); // II2
    for(int i=0;i<=n;++i){
        F[i] = (ll)pw[i]*ifac[i]%p;
        G[i] = (i&1)?p-ifac[i]:ifac[i];
    }
    lim = getlen(n<<1);
    NTT(F,1,lim),NTT(G,1,lim);
    for(int i=0;i!=lim;++i) F[i] = (ll)F[i]*G[i]%p;
    NTT(F,-1,lim);
    memset(F.a+n+1,0,(lim-n+2)<<2);
    printf("%lld\n",(ll)fac[m]*F[m]%p); // III3
    for(int i=1;i<=m;++i) sum = add(sum,F[i]);
    printf("%d\n",sum); // IV4
    printf("%d\n",n<=m); // V5
    printf("%d\n",F[m]);  // VI6
    printf("%d\n",C(n+m-1,n)); // VII7
    printf("%d\n",C(m,n)); // VIII8
    printf("%d\n",C(n-1,m-1)); // IX9
	F.t = n;
	memset(F.a,0,sizeof(F.a));
	for(int i=1;i<=m;++i){
		for(int j=i;j<=n;j+=i)
			F[j] = add(F[j],inv[j/i]);
	}
	F = exp(F);
	printf("%d\n",F[n]); // X10
	printf("%d\n",n<=m); // XI11
	printf("%d\n",n<m?0:F[n-m]); // XII12
	return 0;	
}
```



##### 其他

###### 分拆数

若 $n,r\in\Z^+$，正整数 $n_1,\cdots,n_r$ 满足 $n=\sum_{i=1}^rn_i$ 则为 $n$ 的一个 $r$ 拆分。

分拆数 $p_n$ 是自然数 $n$ 的分拆方法数，有 $p_0=p_1=1,p_2=2,p_3=3,p_4=5,p_5=7,p_6=11,p_7=15,p_8=22$。

将 $n$ 拆分为恰有 $k$ 部分的分拆称为 $k$ 部分分拆，记作 $p(n,k)$。初始值为 $p(0,0)=1$。当且仅当 $n\ge k$ 有解。
$$
p(n,k)=p(n-1,k-1)+p(n-k,k)
$$
$k$ 部分拆数的生成函数为：(p4389/p5824)
$$
\sum_{n,k=0}^\infty p(n,k)x^ny^k=\dfrac1{1-xy}\dfrac1{1-x^2y}\dfrac1{1-x^3y}\cdots
$$
互异分拆数 $pd_n$，自然数 $n$ 各部分不相同的分拆数。如 $pd_0=pd_1=pd_2=1,pd_3=pd_4=2,pd_5=3,pd_6=4,pd_7=5,pd_8=6$
$$
pd(n,k)=pd(n-k,k-1)+pd(n-k,k)
$$
计算可以压缩第二维，使得时间复杂度 $O(nk)$ 空间复杂度 $O(n)$。

奇分拆数 $po_n$，拆分出各部分都是奇数的拆分方法数。有：$po_n=pd_n$。

最左边是互异拆分的生成函数，最右边是奇分拆数的生成函数。


$$
\prod_{i=1}^\infty(1+x^i)=\dfrac{\prod_{i=1}^\infty(1-x^{2i})}{\prod_{i=1}^\infty(1-x^{i})}=\prod_{i=1}^\infty\dfrac1{1-x^{2i-1}}
$$
互异偶分拆数 $pde_n$ 与互异奇分拆数 $pdo_n$ 满足 $pd_n=pde_n+pdo_n$。

广义五边形数为 $a_{2i}=\dfrac{i(3i-1)}2$，$a_{2i+1}=\dfrac{i(3i+1)}2$。

递推式：$p_n=p_{n-1}+p_{n-2}-p_{n-5}-p_{n-7}+\cdots$。即下标是五边形数，且两正两负交替。

那么可以简化为：
$$
p_i=\sum_{j=1}^{a_j\le i}(-1)^{\lfloor\frac{j+1}{2}\rfloor+1}p_{i-a_{j}}
$$
可以计算到 $n=5\times10^4$ 的 $O(n^2)$。



###### 贝尔数

**贝尔数**：$n$ 元素集合划分方法数(开首是 $B_0=B_1=1,B_2=2,B_3=5,B_4=15$ )
$$
B_{n+1}=\sum_{k=0}^n\begin{pmatrix}n\\k\end{pmatrix}B_k,\quad B_n=\sum_{k=0}^nS(n,k)
$$
可以用贝尔三角形 $a_{1,1}=1,a_{n,1}=a_{n-1,n-1},a_{n,m}=a_{n,m-1}+a_{n-1,m-1}$ 求 $B_i=a_{i,i}$



###### 欧拉数

**欧拉数**：$n$ 元素排列有 $m$ 个元素大于上一个元素 $A(n,m)$ ，如 $A(3,1)=4$ 。

$A(n,m)=0(m\ge n), A(0,m)=0, A(n,0)=1$ 

否则 $A(n,m)=(n-m)A(n-1,m-1)+(m+1)A(n-1,m)$



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



常用复杂度对 $10^8$ ：$n!(n=11),2^n(n=26),n^3(n=464),n^2\log n(n=3000),n\log n(n=4.5\times10^6)$



#### 数列

**等差数列** A.P.   Arithmetic progression 
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



**等比数列**  G.P.    Geometric progression 
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



#### 高等数学

> 含部分初等数学

$$
\cot x=\dfrac 1{\tan x},\sec x=\dfrac 1{\cos x},\csc x=\dfrac{1}{\sin x}
$$

$$
\tan\frac{x}{2}=\frac{1-\cos x}{\sin x}
=\frac{\sin x}{1+\cos x}
$$

$$
\sin a=\frac{2\tan\frac{a}{2}}{1+\tan^2\frac{a}{2}}\\
\cos a=\frac{1-\tan^2\frac{a}{2}}{1+\tan^2\frac{a}{2}}\\
\tan a=\frac{2\tan\frac{a}{2}}{1-\tan^2\frac{a}{2}}
$$

$$
\begin{align}
\sin\alpha+\sin\beta&=2\sin\frac{\alpha+\beta}{2}\cos\frac{\alpha-\beta}{2}\\
\sin\alpha-\sin\beta&=2\cos\frac{\alpha+\beta}{2}\sin\frac{\alpha-\beta}{2}\\
\cos\alpha+\cos\beta&=2\cos\frac{\alpha+\beta}{2}\cos\frac{\alpha-\beta}{2}\\
\cos\alpha-\cos\beta&=-2\sin\frac{\alpha+\beta}{2}\sin\frac{\alpha-\beta}{2}\\
\sin\alpha\cos\beta&=\frac{1}{2}\Bigl(\sin(\alpha+\beta)+\sin(\alpha-\beta)\Bigr)\\
\cos\alpha\sin\beta&=\frac{1}{2}\Bigl(\sin(\alpha+\beta)-sin(\alpha-\beta)\Bigr)\\
\cos\alpha\cos\beta&=\frac{1}{2}\Bigl(\cos(\alpha+\beta)+\cos(\alpha-\beta)\Bigr)\\
\sin\alpha\sin\beta&=-\frac{1}{2}\Bigl(\cos(\alpha+\beta)-\cos(\alpha-\beta)\Bigr)\\
\end{align}
$$



等价无穷小： $a^x-1\sim x\ln a,\arcsin(ax)\sim\sin(ax)\sim ax$ $,\arctan(ax)\sim\tan(ax)\sim ax,$ $\ln(1+x)\sim x$ , $\sqrt{1+x}-\sqrt{1-x}\sim x,$ $(1+ax)^b-1\sim abx,$ $\sqrt[b]{1+ax}-1\sim\dfrac abx$ $,1-\cos x\sim\dfrac{x^2}2,$ $x-\ln(1+x)\sim\dfrac{x^2}2,$ $\tan x-\sin x\sim\dfrac{x^3}2,$ $x-\arctan x\sim\dfrac{x^3}3$ $,x-\sin x\sim\dfrac{x^3}6$ $,\arcsin x-x\sim\dfrac{x^3}6$  

泰勒展开 (幂级数展开式)： (通常取 $x_0=0$ )
$$
f(x)=f(x_0)+\dfrac{f'(x_0)}{1!}(x-x_0)
%+\dfrac{f''(x_0)}{2!}(x-x_0)^2
+\cdots+\dfrac{f^{n}(x_0)}{n!}(x-x_0)^n
+R_n
$$

$$
\begin{align}
e^x&=1+\dfrac1{1!}x+\dfrac1{2!}x^2+\cdots\\
\ln(1+x)&=x-\dfrac12x^2+\dfrac13x^3+\cdots\\
\sin x&=x-\dfrac1{3!}x^3+\dfrac1{5!}x^5+\cdots\\
\arcsin x&=x+\dfrac12\dfrac{x^3}3+\dfrac{1\times3}{2\times4}\dfrac{x^5}5+\cdots\\
\cos x&=1-\dfrac1{2!}x^2+\dfrac1{4!}x^4\\
\dfrac1{1-x}&=1+x+x^2+x^3+\cdots\\
(1+x)^a&=1+\dfrac{a}{1!}x+\dfrac{a(a-1)}{2!}x^2+\cdots\\
\end{align}
$$

求导公式：

$$
\begin{align}
(C)'&=0\\
(x^\mu)'&=\mu x^{\mu-1}\\
(\sin x)'&=\cos x\\
(\cos x)'&=-\sin x\\
(\tan x)'&=\sec^2 x\\
(\cot x)'&=-\csc^2 x=-\csc x\cot x\\
(\sec x)'&=\sec x\tan x\\
(\csc x)'&=-\csc x\cot x\\
(a^x)'&=a^x\ln a\ (a > 0,a\neq 1)\\
(e^x)'&=e^x\\
(\log_ax)'&=\dfrac1{x\ln a}\ (a > 0,a\neq 1)\\
(\ln x)'&=\dfrac1x\\
(\arcsin x)'&=\dfrac1{\sqrt{ 1-x^2}}\\
(\arccos x)'&=-\dfrac1{\sqrt{ 1-x^2}}\\
(\arctan x)'&=\dfrac1{1+x^2}\\
(\mathrm{arccot}\ x)'&=-\dfrac1{1+x^2}\\
\ln(x+\sqrt{a^2+x^2})'&=\frac 1{\sqrt{a^2+x^2}}
\end{align}
$$

$$
\begin{align}
(x^a)^{(n)}&=\begin{cases}A_a^nx^{a-n}&(n\le a)\\0&(n>a)\end{cases},a\in Z_+\\
(\sin x)^{(n)}&=\sin\bigl(x+\frac {n\pi}2\bigr),n\in Z_+\\
(\cos x)^{(n)}&=\cos\bigl(x+\frac {n\pi}2\bigr),n\in Z_+\\
\bigl(\ln(1+x)\bigr)^{(n)}&=(-1)^{n-1}\frac{(n-1)!}{(1+x)^n},n\in Z_+\\
(a^x)^{(n)}&=a^x\ln^na,n\in Z_+
\end{align}
$$

积分公式：

$$
\begin{align}
\int kdx&=kx+C\ (k\ 是常数)\\
\int x^\mu dx&=\dfrac{x^{\mu+1}}{\mu+1}+C\ (\mu\neq -1)\\
\int\dfrac{dx}x&=\ln |x|+C\\
\int\dfrac{dx}{1+x^2}&=\arctan x+C\\
\int\dfrac{dx}{\sqrt{1-x^2}}&=\arcsin x+C\\
\int\cos xdx&=\sin x+C\\
\int\sin xdx&=-\cos x+C\\
\int\dfrac{dx}{\cos^2x}&=\int\sec^2 xdx=\tan x+C\\
\int\dfrac{dx}{\sin^2x}&=\int\csc^2 xdx=-\cot x+C\\
\int\sec x\tan xdx&=\sec x+C\\
\int\csc x\cot xdx&=-\csc x+C\\
\int e^xdx&=e^x+C\\
\int a^xdx&=\dfrac{a^x}{\ln a}+C
\end{align}
$$

$$
\begin{align}
\int\tan xdx=&-\ln|\cos x|+C\\
\int\cot xdx=&\ \ln|\sin x|+C\\
\int\sec xdx=&\ \ln|\sec x+\tan x|+C=\ln|\tan(\frac x2+\frac\pi4)|\\
\int\csc xdx=&\ \ln|\csc x-\cot x|+C=\ln|\tan\frac x2|\\
\int\frac{dx}{\sqrt{a^2-x^2}}=&\ \arcsin\frac{x}{a}+C\\
\int\frac{dx}{x^2+a^2}=&\ \frac{1}{a}\arctan\frac{x}{a}+C\\
\int\frac{dx}{x^2-a^2}=&\ \frac{1}{2a}\ln\biggl|\frac{x-a}{x+a}\biggr|+C\\
\int\frac{xdx}{\sqrt{x^2\pm a^2}}=&\ \sqrt{x^2\pm a^2}+C\\
\int\frac{dx}{\sqrt{x^2\pm a^2}}=&\ \ln \Bigl|x+\sqrt{x^2\pm a^2}\Bigr|+C\\
\int\sqrt{a^2-x^2}dx=&\ \frac{x}{2}\sqrt{a^2-x^2}+\frac{a^2}{2}\arcsin\frac{x}{a}+C\\
\int\sqrt{x^2\pm a^2}dx=&\ \frac{x}{2}\sqrt{x^2\pm a^2}\pm\frac{a^2}{2}\ln\Bigl|x+\sqrt{x^2\pm a^2}\Bigr|+C
\end{align}
$$

$$
\begin{align}
\int\frac A{x-a}dx&=A\ln|x-a|+C\\
\int\frac A{(x-a)^n}dx&=-\frac A{(n-1)(x-a)^{n-1}}+C\\
\int\frac{Bx+C}{x^2+px+q}dx&\quad(p^2-4q<0)\\
=\frac B2\ln(x^2+px+q)&+\frac{2C-Bp}{\sqrt{4q-p^2}}\arctan\frac{2x+p}{\sqrt{4q-p^2}}+C\\
\end{align}
$$

$$
\int\frac{Bx+C}{(x^2+px+q)^n}dx\quad(p^2-4q<0)\\
=\frac B{2(1-n)(x^2+px+q)^{n-1}}
+(C-\frac{Bp}2)\int\frac{dx}{\Bigl(\bigl(x+\frac p2\bigr)^2+\bigl(\sqrt{q-\frac{p^2}4}\bigr)^2\Bigr)^n}
$$

> 分部积分技巧：
>
> - 不动：反三角函数、对数函数、幂函数(幂不动性差些)
> - 动：三角函数、常数函数、指数函数



偏导数定义： $\lim_{\Delta x\to0}\frac{f(x_0+\Delta x,y_0)-f(x_0,y_0)}{\Delta x}$

全微分： $\Delta z=f(x+\Delta x,y+\Delta y)-f(x,y)$

多元函数极值：$u$在开区域$G\subset\R^2$内有二阶连续偏导数，且$P_0(x_0,y_0)\in G$是$f$的驻点，令：
$$
f''_{xx}(x_0,y_0)=A,f''_{xy}(x_0,y_0)=B,f''_{yy}(x_0,y_0)=C
$$
则：

1. 若$AC-B^2>0$，则在点$P_0$取得极值，$A<0$极大值，$A>0$极小值
2. 若$AC-B^2<0$，则在点$P_0$不取极值
3. 若$AC-B^2=0$，则无法判断

拉格朗日乘数法：$n$元函数在开区域内有一阶连续偏导数，且不全为$0$，则在条件下的极值点一定是拉格朗日函数($n+1$元函数，新元是$\lambda$)$f+\lambda\varphi$的驻点



三元积分变换：

柱坐标：是仅变换$x,y$为极坐标(和$x,y$区域)的变换公式。
$$
\iiint_\Omega f(x,y,z)dv=\iiint_{\Omega'}f(r\cos\theta,r\sin\theta,z)rdrd\theta dz
$$
球坐标：$\theta$同柱坐标，$\varphi$是与$z$轴正向的夹角
$$
\iiint_\Omega f(x,y,z)dv=f(r\sin\varphi\cos\theta,r\sin\varphi\sin\theta,r\cos\varphi)r^2\sin\varphi drd\varphi d\theta
$$

设曲线$L$由参数方程$x=x(t),y=y(t)(\alpha\ge t\ge\beta)$表示，$x=x(t),y=y(t)$在$[\alpha,\beta]$上有一阶连续偏导数，且$x'^2(t)+y'^(2)\neq0$(即曲线$L$是光滑简单曲线)，函数$f(x,y)$在曲线上连续，则：
$$
\int_Lf(x,y)ds=\int_\alpha^\beta f(x(t),y(t))\sqrt{x'^2(t)+y'^2(t)}dt
$$
显然如果是显函数$y=f(x)$，则直接化为$f(x)dx$，$x=f(y)$同理。


$$
\iint_\Sigma f(x,y,z)dS=\iint_D f(x,y,z(x,y))\sqrt{1+\left(\cfrac{\partial z}{\partial x}\right)^2+\left(\cfrac{\partial z}{\partial y}\right)^2}dxdy
$$
计算时需要满足投影面面积$S\neq0$，如果不为零，需要更换投影面，换元投影。

设有界闭区域$D$由分段光滑曲线$L$所围，函数$P(x,y),Q(x,y)$在$D$上具有一阶连续偏导数，$L$是$D$取正向的边界曲线：
$$
\iint_D\left|\matrix{\cfrac{\partial}{\partial x}&\cfrac{\partial}{\partial y}\\P&Q}\right|dxdy=\iint_D\left(\cfrac{\partial Q}{\partial x}-\cfrac{\partial P}{\partial y}\right)dxdy=\oint_LPdx+Qdy
$$
对于多连通区域，格林公式右端应包括沿区域$D$的全部边界正向曲线积分

有向曲线弧$x=\varphi(t),y=\psi(t)$，起点和终点对应参数$\alpha,\beta(\alpha<\beta)$，在$[\alpha,\beta]$上具有一阶连续导数，且$\varphi'^2(t)+\psi'^2(t)\neq0$，切向量是$\vec t=(\varphi'(t),\psi'(t))$，指向$t$增大的方向，那么显然方向余弦是：
$$
\cos\alpha=\cfrac{\varphi'(t)}{\sqrt{\varphi'^2(t)+\psi'^2(t)}}\quad\cos\beta=\cfrac{\psi'(t)}{\sqrt{\varphi'^2(t)+\psi'^2(t)}}
$$
则两类积分的转换公式为：
$$
\int_LPdx+Qdy=\int_L(P\cos\alpha+Q\cos\beta)ds
$$

$$
ds=\sqrt{\varphi'^2(t)+\psi'^2(t)}dt,dx=\varphi'(t)dt,dy=\psi'(t)dt
$$

高斯公式：设空间闭区域$\Omega$是由分片光滑的闭曲线$\Sigma$所围成，函数$P(x,y,z),Q(x,y,z),R(x,y,z)$在$\Omega$以及$\Sigma$上具有关于$x,y,z$的连续偏导数，$\Sigma$是$\Omega$整个边界曲面的外侧，则有：
$$
\iint_\Omega(\cfrac{\partial P}{\partial x}+\cfrac{\partial Q}{\partial y}+\cfrac{\partial R}{\partial z})dxdydz=\oiint_\Sigma Pdydz+Qdzdx+Pdxdy
\\=\iint_{\partial\Omega}P\cos\alpha+Q\cos\beta+R\cos\gamma dS
$$
注：$P=0,Q=0,R=0$也是函数，所以也就是说缺少了一部分也是可用的

$z=z(x,y)$表示有向曲面$\Sigma$，在$xOy$的投影区域是$D_{xy}$，函数$z=z(x,y)$在$D_{xy}$上具有一阶连续偏导数，$R(x,y,z)$在$\Sigma$连续且$\Sigma$取上侧，曲面$\Sigma$上一点的法向量方向余弦是：
$$
\cos\alpha=\cfrac{-z_x}{\sqrt{1+z^2_x+z^2_y}},
\cos\beta=\cfrac{-z_x}{\sqrt{1+z^2_x+z^2_y}},
\cos\gamma=\cfrac{1}{\sqrt{1+z^2_x+z^2_y}}
$$

$$
\iint_\Sigma Pdydz+Qdzdx+Rdxdy=\iint_\Sigma P\cos\alpha+Q\cos\beta+R\cos\gamma dS
$$



#### 线性代数

齐次线性方程组(等式右边全是 $0$ )必有零解。
$$
\mathbf{A}\times\mathbf{B}=(\sum_{k=1}^na_{ik}\cdot b_{kj})
$$
矩阵乘法符合结合律、分配律，不符合交换律

运算可行的前提下，转置满足如下运算规律：

- $(A^T)^T=A$
- $(A+B)^T=A^T+B^T$
- $(\lambda A)^T=\lambda A^T$
- $(AB)^T=B^TA^T$

矩阵$\mathbf{A=O}$的充要条件是$\mathbf{AA^T=O}$


$$
\left|\matrix{a_{11}&a_{12}&a_{13}\\a_{21}&a_{22}&a_{23}\\a_{31}&a_{32}&a_{33}}\right|\\=a_{11}(a_{22}a_{33}-a_{23}a_{32})-a_{12}(a_{21}a_{33}-a_{23}a_{31})+a_{13}(a_{21}a_{32}-a_{22}a_{31})
$$
行列式 $\det$ 的性质：

- 行列式和它的转置行列式相等

- 对换行列式的相邻两行或两列，行列式变号

  $\to$如果行列式存在两行或两列完全相同，则行列式为 $0$

- 行列式某一行或某一列所有元素同时乘以同一个数$k$，等于用$k$乘以整个行列式

  $\to$行列式某一行或某一列所有公因子可以提取到行列式外面

- 行列式如果有两行或两列元素成比例，则这个行列式为$0$

- 若行列式某一行元素都是两数之和，那么可以将该行列式拆成两个行列式，这两个行列式除了这一行值分别是两数外，其他行不变；列同理

- 行列式某一行或列各元素乘以同一个数加到另一行或列对应元素上，行列式不变

- $|\lambda A|=\lambda^n|A|$

- $|AB|=|A||B|$

在$n$阶行列式中，把$a_{ij}$所在行和列去掉后，留下的$n-1$阶行列式叫做$a_{ij}$的余子式$M_{ij}$。且有代数余子式$A_{ij}$定义如下：
$$
A_{ij}=(-1)^{i+j}M_{ij}
$$

行列式的按行（列）展开法则：行列式等于它的任一行（列）各元素与其对应的代数余子式乘积之和：
$$
D=\sum_{i=1}^na_{ij}A_{ij}=\sum_{j=1}^na_{ij}A_{ij}
$$

一个$n$阶矩阵$\mathbf{A}$各个元素的代数余子式$A_{ij}$的转置矩阵构成了矩阵$\mathbf{A}$的伴随矩阵$\mathbf{A^*}$：
$$
\mathbf{A^*}=(A_{ij})^T=(A_{ji})=\left(\matrix{A_{11}&A_{21}&\cdots&A_{n1}\\A_{12}&A_{22}&\cdots&A_{n2}\\\vdots&\vdots&\ddots&\vdots\\A_{1n}&A_{2n}&\cdots&A_{nn}}\right)
$$
伴随阵满足如下运算：(可以求逆矩阵)
$$
\mathbf{AA^*=A^*A=|A|E}
$$

若矩阵$\mathbf{A}$可逆，则$|\mathbf{A}|\neq0$ ，称为非奇异矩阵。
$$
\left(\matrix{a&b\\c&d}\right)^{-1}=\frac1{ad-bc}\left(\matrix{d&-b\\-c&a}\right)
$$

- $\lambda\neq0,(\lambda\mathbf{A})^{-1}=\frac1\lambda\mathbf{A^{-1}}$
- $\mathbf{(AB)^{-1}=B^{-1}A^{-1}}$
- $\Lambda^{-1}=diag(\lambda_1^{-1},\cdots,\lambda_m^{-1})$ 

初等变换得到的等价关系具有传递性。$\mathbf{A\sim B}$的充要条件是存在$m$阶可逆矩阵$\mathbf{P}$、$n$阶可逆矩阵$\mathbf{Q}$使得$\mathbf{PAQ=B}$ 。方阵$\mathbf A$可逆的充要条件是$\mathbf{A\overset{c}{\sim}B}$或$\mathbf{A\overset{c}{\sim}B}$或$\mathbf{A\sim B}$ 

若矩阵$\mathbf A$中有不为$0$的$r$阶子式$D$，且所有$r+1$阶子式(若存在)均为$0$，则$D$称为$\mathbf A$的**最高阶非零子式**，且$r$称为$\mathbf A$的**秩**，记作$R(\mathbf A)$ 。可逆矩阵的秩等于矩阵阶数，不可逆矩阵的秩小于矩阵阶数

向量方程组 $\mathbf A\mathbf x=\mathbf b$ ，解为 $\mathbf x=\mathbf A^{-1}\mathbf b$

- 无解的充要条件是$R(\mathbf A)<R(\mathbf A,\mathbf b)$
- 有唯一解的充要条件是$R(\mathbf A)=R(\mathbf A,\mathbf b)=n$
- 有无穷解的充要条件是$R(\mathbf A)=R(\mathbf A,\mathbf b)<n$



#### 概率论

事件的运算规律：

- 若 $A\subset B$ 则 $A\cup B=B,AB=A$

- $A-B=A\overline B=A-AB,A\cup B=A\cup(B-A)$

- 结合律 $(A\cup B)\cup C=A\cup(B\cup C)$, $(A\cap B)\cap C=A\cap(B\cap C)$

- 分配律 $(A\cup B)\cap C=(A\cap C)\cup(B\cap C)$

  $$(A\cap B)\cup C=(A\cap C)\cup(B\cup C)$$

- 对偶律 $\overline{A\cup B}=\overline A\cap \overline B$ , $\overline{A\cap B}=\overline A\cup \overline B$

概率公式：

- $P(A-B)=P(A)-P(AB)$ 
- 若 $B\subset A$ ，有：$P(A-B)=P(A)-P(B)$ , $P(A)\ge P(B)$
- $P(A\cup B)=P(A)+P(B)-P(AB)$ ，可由容斥原理推广到任意多事件

在事件 $A$ 发生的条件下，事件 $B$ 的条件概率 $P(B|A)=\dfrac{P(AB)}{P(A)}$
$$
P(A_1\cup\cdots\cup A_n|A)=P(A_1|A)+\cdots+P(A_n|A)
$$

$$
P(A_1\cdots A_n)=P(A_1)P(A_2|A_1)\cdots P(A_n|A_1\cdots A_{n-1})
$$

如两个事件 $A,B$ 满足：$P(AB)=P(A)P(B)$ ，那么称 $A,B$ 独立

两点分布方差为 $p(1-p)$ ，二项分布方差为 $np(1-p)$ ，均匀分布期望 $\dfrac{a+b}2$ ，方差 $\dfrac{(b-a)^2}{12}$

数学期望的性质：

- 若 $C$ 是常数，则 $E(C)=C,E(CX)=CE(X)$

- $E(X_1+X_2)=E(X_1)+E(X_2)$ 

- 若 $X,Y$ 相互独立，则 $E(XY)=E(X)E(Y)$

方差计算公式 $D(X)=E(X^2)-[E(X)]^2$ 

- 设 $C$ 是常数，则 $D(C)=0$ ，$D(CX)=C^2D(X)$

- 若 $X,Y$ 相互独立，则 $D(X\pm Y)=D(X)+D(Y)$ (注意都是加)



#### 其他

**阶乘** 极限值：13!刚好爆int , 21!刚好爆long long



**斐波那契数列**：f(47)刚好爆int, f(93)刚好爆long long

通项 $f_n=\left(\left(\dfrac{1+\sqrt 5}2\right)^n-\left(\dfrac{1-\sqrt 5}2\right)^n\right)\div\sqrt 5$。约等于去掉减式的最近整数

快速倍增 $[\matrix{F_{n-1}&F_n}]=[\matrix{F_{n-2}&F_{n-1}}]\cdot[\matrix{0&1\\1&1}]$，则 $F_{2k}=F_k(2F_{k+1}-F_k),F_{2k+1}=F^2_{k+1}+F^2_k$。

- 卡西尼性质 $f_{n-1}f_{n+1}-f^2_n=(-1)^n$

- 附加性质 $f(n+m)=f(n+1)f(m)+f(n)f(m-1)$

  令 $m=n$ 得 $f_{2n}=f_n(f_{n+1}+f_{n-1})$，

  可推导出 $f_n|f_{nk}$，且可逆即 $\forall f_a|f_b,a|b$

- $\gcd(f_m,f_n)=f_{\gcd(m,n)}$

- $\sum_{i=1}^nf(n)=f(n+2)-1$

- $\sum_{i=1}^nf^2(i)=f(n)\times f(n+1)$

- $f(n+1)<2f(n)<f(n+2)$

- $f(n+2)<3f(n)$

- $4f(n)<3f(n+1)\Rightarrow f(n)<f(n+1)<3f(n-1)$

> 齐肯多夫定理：任何正整数可以表示为若干个不连续的 Fibonacci 数之和

模数为 $p$，则 $f\bmod p$ 的循环节长度 $\pi(p)\le 6p$。(皮萨诺周期)

- $\pi(2)=3,\pi(5)=20$
- 若模数 $a,b$ 互质，则 $\pi(ab)=\gcd(\pi(a),\pi(b))$
- 对奇素数 $p\equiv1,4\pmod5$，$p-1|\pi(p)$
- 对奇素数 $p\equiv2,3\pmod5$，$2p+2|\pi(p)$
- 若 $\pi(p^{k-1})|m$，则 $\pi(p^k)|mp$。若 $\pi(p^{k-1})=m$ 则 $\pi(p^k)=mp$



牛顿法求函数零点：$x_{i+1}=x_i-\dfrac{f(x_i)}{f'(x_i)}$



尾 $0$ 数目可以将大数质因数分解，求 $\min(num_2,num_5)$ 即可。其他质因数都不能乘出 $0$ 



任意整数转 Excel 列名：(列名本质是从 $1('A')$ 计数的 $27$ 进制)

```c++
#include <bits/stdc++.h>
int n; std::string x;
signed main()
{   for(scanf("%d",&n);n;n=(n-1)/26) x=(char)('A'+(n-1)%26 )+x;
    return std::cout<<x,0;  }
```



闰年公式：满足其一 ① 为 $4$ 的倍数不为 $100$ 的倍数； ② 为 $400$ 的倍数



### 数论

#### 基础性质

设 $a,b,m\in Z^+$，有：$\lfloor\dfrac ab\rfloor=\lceil\dfrac{a+1}b\rceil-1$, $\lceil\dfrac ab\rceil=\lfloor\dfrac{a-1}b\rfloor+1$。
$$
\begin{align}
ab\ge m\Leftrightarrow a\ge\lceil\dfrac mb\rceil \Leftrightarrow b\ge\lceil\dfrac ma\rceil\\
ab > m\Leftrightarrow a > \lceil\dfrac mb\rceil \Leftrightarrow b > \lceil\dfrac ma\rceil\\
ab\le m\Leftrightarrow a\le\lfloor\dfrac mb\rfloor \Leftrightarrow b\le\lfloor\dfrac ma\rfloor\\
ab <  m\Leftrightarrow a < \lfloor\dfrac mb\rfloor\Leftrightarrow b < \lfloor\dfrac ma\rfloor
\end{align}
$$
**整除**的性质：( $x|y$ 那么 $x$ 是 $y$ 倍数，$y$ 是 $x$ 因数(约数)， $x,y\in Z,x\neq 0$ )

- $a|b\Leftrightarrow-a|b\Leftrightarrow a|-b\Leftrightarrow|a|\ |\ |b|$
- $a|b$ 且 $b|c$ $\Rightarrow a|c$
- $a|b$ 且 $a|c\Leftrightarrow \forall x,y\in Z,a|\gcd(xb+yc)$  (字面理解： $a$ 是 $b,c$ 公因数)
- $a|b$ 且 $b|a$ $\Rightarrow b=\pm a$
- $m\neq 0$ 且 $a|b\Leftrightarrow ma|mb$
- $b\neq 0$ 且 $a|b\Leftrightarrow |a|\le |b|$
- $a\neq 0,b=qa+c,a|b\Leftrightarrow a|c$ 
- $0$ 是所有非零整数的倍数，即 $0|x,x\neq 0$  

> 真因数是对 $b\neq 0$ 时除去 $\pm 1,\pm b$ 外的全部因数。

**素数**的性质：

- 对合数 $a$ ，一定存在素数 $p\le\sqrt a$ 使得 $p|a$ 
- 所有大于 $3$ 的素数都可以表示为 $6n\pm 1$ 的形式
- 素数定理： $\pi(x)$ 为不超过 $x$ 的素数个数，则 $\pi(x)\approx \dfrac{x}{\ln x}$ ( $\pi(x)$ 一般大于后者，误差率约为 $10\%$ )

**同余**($a\equiv b(\bmod m)$ 是 $m\neq 0,m|(a-b)$ ,称 $a$ 同余于 $b$ 模 $m,b$ 是 $a$ 对模 $m$ 的剩余)的性质：

- 传递性：若 $a\equiv b(\bmod m),b\equiv c(\bmod m)$ 则 $a\equiv c(\bmod m)$

- 线性运算：若 $a,b,c,d\in Z,m\in N^*,a\equiv b(\bmod m),c\equiv d(\bmod m)$ 则：

  $a\pm c\equiv b\pm d(\bmod m),ac\equiv bd(\bmod m)$

- 若 $a,b\in Z,k,m\in N^*,a\equiv b(\bmod m)$ 则 $ak\equiv bk(\bmod mk)$

- 若 $a,b\in Z,d,m\in N^*,d|a,d|b,d|m,a\equiv b(\bmod m)$ 则 $\dfrac ad\equiv\dfrac bd(\bmod \dfrac md)$

- 若 $a,b\in Z,d,m\in N^*,d|m,a\equiv b(\bmod m)$ 则 $a\equiv b(\bmod d)$ 

- 若 $a,b\in Z,d,m\in N^*,a\equiv b(\bmod m)$ 则 $\gcd(a,m)=\gcd(b,m)$ ,若 $m|d$ 且 $a|d,b|d$ 成立其一，那么 $a|d,b|d$ 均成立

定义域是正整数的函数称为数论函数。

**积性函数**是 $f(1)=1,\forall x,y\in N^*,\gcd(x,y)=1\Rightarrow f(xy)=f(x)f(y)$ 

**完全积性函数**是  $f(1)=1,\forall x,y\in N^*\Rightarrow f(xy)=f(x)f(y)$ 

若 $f,g$ 是积性函数，则 $f(x^p),f^p(x),f(x)g(x),\sum_{d|x}f(d)g(\dfrac xd)$ 都是积性函数。

设 $x=\prod p_i^{k_i}$ ，积性函数满足 $f(x)=\prod f(p_i^{k_i})$ ，完全积性函数满足 $f(x)=\prod f(p_i)^{k_i}$ 

> 单位函数 $\epsilon(n)=[n=1]$ ,除数函数 $\sigma_k(n)=\sum_{d|n}d^k,\sigma_0(n)=d(n)=\tau(n),\sigma_1(n)=\sigma(n)$ 
>
> 莫比乌斯函数 $\mu(n)=\begin{cases}1&n=1\\0&\exists d > 1,d^2|n\\(-1)^{\omega(n)}&otherwise\end{cases}$ , $\omega(n)$ 是 $n$ 的本质不同因子个数, $\omega$ 是加性函数



> 利用唯一分解定理质因数分解的复杂度为 $O(\sqrt n)$ ，最坏复杂度在质数时取得 (也可以枚举素数，复杂度为 $O(\dfrac{n}{\ln n})$ ，但是需要素数筛预处理)

设 $x=\prod p_i^{a_i}$ ，则 $x$ 因子数、因子和分别为 $\prod(a_i+1),\prod(\sum_{j=0}^{a_i}p_i^j)=\prod\dfrac{p_i^{a_i+1}-1}{p_i-1}$

> 根据上式可知完全平方数(1,4,9,...)有奇数个因数，其他数有偶数个因数。因子和是积性函数，设 $x$ 分解出一个素数 $p$ ，则 $f(x)=f(\dfrac xp)f(p)$ ，其中显然 $f(p)=p+1$



互质/最大公因数/最小公倍数的性质：

- (辗转相除法) `gcd(a,b)=b?gcd(b,a%b):a` 复杂度 $O(\log n)$ ; $[a,b]=\dfrac{ab}{(a,b)}$
- 若 $a,b\in N^*,(a,b)=k$ 则 $(\dfrac ak,\dfrac bk)=1$ ；若 $[a,b]=k$ 则 $(\dfrac ka,\dfrac kb)=1$
- 若 $p\bot q$ ，则 $(p^n,q^m)=1$ ，也意味着 $p^n\bmod q^m\neq 0$ 
- 若 $x(a,b)=a,y(a,b)=b$ 则 $(x,y)=1$ 即 $(\dfrac{a}{(a,b)},\dfrac{b}{(a,b)})=1$ 
- 若 $(a\cdot b)\bot(c\cdot d)$ 则 $a\bot c,a\bot d,b\bot c,b\bot d$ 

> 应用：从长为 $n$ 的环任意位置开始循环每次跳 $m$ 格走，能遍历全部位置充要条件是 $(n,m)=1$ 



> 四平方和定理：所有自然数至多只要用四个数的平方和就可以表示



#### 素数

##### 素性测试

判断单个数是否是素数模板 ( $O(n)$ )：

```c++
bool isprime(ll p)
{
    if(p==2||p==3) return true;
    if(p<2||(p%6!=1&&p%6!=5)) return false;
    for(ll i=5;i*i<=p;i+=6) if(p%i==0||p%(i+2)==0) return false;
    return true;
}
```

**Miller Rabin算法**，复杂度 $O(k\log n)$ ，$k$ 是设定参数，能够以较高准确率判定是否为素数，建议设 $10$，见 `pollard-rho` 代码。

> $100$ 内质数为  $25$ 个 `2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97`



##### 埃氏筛

埃氏筛(复杂度 $O(n\log\log n)$ )

```c++
// C++ Version
int Eratosthenes(int n) {
  int p = 0;
  for (int i = 0; i <= n; ++i) is_prime[i] = 1;
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      prime[p++] = i;  // prime[p]是i,后置自增运算代表当前素数数量
      if ((long long)i * i <= n)
        for (int j = i * i; j <= n; j += i)
          // 因为从 2 到 i - 1 的倍数我们之前筛过了，这里直接从 i
          // 的倍数开始，提高了运行速度
          is_prime[j] = 0;  // 是i的倍数的均不是素数
    }
  }
  return p;
}
```



##### 欧拉筛

欧拉筛：(洛谷P3383)

```c++
#include <bits/stdc++.h>
#define MAXN 100000002
#define MAXP 6000002
using namespace std;
bool vis[MAXN]; //vis[0] = vis[1] = 1;
int Prime[MAXP], k, n, q, c;
void euler(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!vis[i]) Prime[++k]=i;
        for(int j=1;j<=k;j++)
        {
            if(Prime[j]*i>n) break;
            vis[Prime[j]*i]=true;
            if(i%Prime[j]==0) break;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &q);
    euler(n);
    while(q--)
    {
        scanf("%d", &c);
        printf("%d\n", Prime[c]);
    }
    return 0;
}
```

求任意连续区间素数：(洛谷P1835-求素数个数 $1\le l\le r < 2^{31},r-l\le10^6$ )

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 1000002
#define SQRTR 50000
ll prime[MAXN], k, ans, lf, rf, p, bg;
bool vis[MAXN];
inline void euler()
{
	for(ll i = 2; i <= SQRTR; ++i)
	{
		if (!vis[i]) prime[++k] = i;
		for (ll j = 1; i * prime[j] <= SQRTR; ++j)
		{
			vis[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}
signed main()
{
	scanf("%lld%lld", &lf, &rf);
	lf = (lf == 1) ? 2 : lf;
	euler();
	memset(vis,0,sizeof vis);
	for(ll i = 1; i <= k; ++i)
	{
		p = prime[i];
		bg = (lf + p - 1) / p * p > 2 * p ? (lf + p - 1) / p * p : 2 * p;
		for (ll j = bg; j <= rf; j += p) vis[j - lf + 1] = true;
	}
	for(ll i = 1; i <= rf - lf + 1; ++i) if (!vis[i]) ++ans;
	printf("%lld", ans);
	return 0;
}
```

> SCNUOJ1745 求 $\sum_{i=1}^n\varphi(i^k)\cdot\sigma(i^k)\bmod(10^9+7)$ ，$1\le n,k\le10^6$

对素数 $p$ 和正整数 $k$ ，有 $\varphi(p^k)=p^k-p^{k-1},\sigma(p^k)=\dfrac{p^k-1}{p-1}$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 1000002
ll n, k, p[mn], pri[mn], e[mn], pe[mn], g[mn], cnt, ans = 1, mod = 1e9 + 7;
void euler(ll n)
{ // e[i]是i质因数分解得到的最大的幂a_i,pe[i]是对应最大的(p^e[i])
    for (ll i = 2; i <= n; ++i)
    {
        if (!p[i])
        {
            p[i] = i, pri[++cnt] = i, pe[i] = i, e[i] = 1;
        }
        for (ll j = 1; i * pri[j] <= n; ++j)
        {
            p[i * pri[j]] = pri[j];
            if (pri[j] == p[i])
            {
                e[i * pri[j]] = e[i] + 1;
                pe[i * pri[j]] = pe[i] * pri[j];
                break;
            }
            e[i * pri[j]] = 1;
            pe[i * pri[j]] = pri[j];
        }
    }
}
ll qpow(ll a, ll b)
{
    ll res = 1;
    for (; b > 0; b >>= 1)
    {
        if (b & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
    }
    return res;
}
signed main()
{
    sc(n), sc(k);
    g[1] = 1;
    euler(n);
    for (ll i = 2; i <= n; ++i)
    {
        if (pe[i] == i)
        {
            g[i] = (qpow(p[i], e[i] * k + 1) - 1 + mod) % mod * qpow(p[i] - 1, mod - 2) % mod;
            g[i] = g[i] * (qpow(p[i], e[i] * k) - qpow(p[i], e[i] * k - 1) + mod) % mod;
        }
        else
        {
            g[i] = g[i / pe[i]] * g[pe[i]] % mod;
        }
        ans = (ans + g[i]) % mod;
    }
    printf("%lld", ans);
    return 0;
}
```

$O(n)$ 求积性函数 $f$ ，条件：任意质数 $p$ 和正整数 $k$ ，可以 $O(1)$ 求出 $f(p^k)$ ，那么设合数 $n=\prod_{i=1}^kp_i^{\alpha_i}$ ，线性筛记录 $g_n=p_1^{\alpha_1}$ (即 $n$ 的第一个质数幂)，若 $n$ 被 $x\cdot p$ 筛掉( $p$ 是质数)，那么：
$$
g_n=\begin{cases}g_x\cdot p&x\bmod p=0\\p&otherwise\end{cases}
$$
若 $n=g_n$ ，直接算 $f(n)$ ，否则 $f(n)=f(\dfrac n{g_n})f(g_n)$ 



> 用欧拉筛可以在筛的时候求一些其他值，如例题：求 $\sum_{i=1}^nf(i^k)\bmod10^9+7,f$ 是因子和

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ln;
typedef int ll;
#define mn  10000002
#define mod 1000000007
ll n, k, p[mn], pri[mn], e[mn], pe[mn], g[mn], cnt; ln ans = 1;
void euler(ll n)
{//e[i]是i质因数分解得到的最大的幂a_i,pe[i]是对应最大的(p^e[i])
	for(ll i=2;i<=n;++i)
	{
		if (!p[i]) p[i] = i, pri[++cnt] = i, pe[i] = i, e[i] = 1;
		for (ll j = 1; i * pri[j] <= n; ++j)
		{
			p[i * pri[j]] = pri[j];
			if (pri[j] == p[i])
			{
				e[i * pri[j]] = e[i] + 1;
				pe[i * pri[j]] = pe[i] * pri[j];
				break;
			}
			e[i * pri[j]] = 1;
			pe[i * pri[j]] = pri[j];		
        }
	}
}
ln qpow(ln a, ln b)
{
	ln res = 1;
	for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
	return res;
}
signed main()
{
    euler(100); g[1] = 1;
	scanf("%d%d",&n,&k);
	for(ll i=1;i<=n;++i)
	{
		if (pe[i] == i) g[i] = (qpow(p[i], 1LL * e[i] * k + 1) - 1 + mod) % mod * qpow(p[i] - 1, mod - 2) % mod;
		else g[i] = 1LL * g[i / pe[i]] * g[pe[i]] % mod;
		(ans += g[i]) %= mod;
	}
	return printf("%lld", ans) & 0;
}
```



##### pollard-rho算法

质因数分解的朴素复杂度是 $O(\sqrt n)$，在预处理素数表的情况下质因数分解复杂度为 $O(\sqrt{\dfrac n{\ln n}})$。注意不能只预处理 $\sqrt n$，以防大质数乘小质数情况(此时对大质数可以除法求出，然后做素性测试)和本身是大质数。

若 $x|n,1 < x < n$(即 $1$ 和自身外的因子)，则 $x$ 是非平凡因子。能以 $O(n^{0.25})$ 分解出随机一个非平凡因数。 

> P4718 给定 $t(\le 350)$ 个 $n(1 < n\le10^{18})$，判断 $n$ 为质数或输出它的最大质因子

[by NULL-SF](https://github.com/NULL-SF)

```c++
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

#define int long long

using namespace std;

typedef long long ll;

auto seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 gen(seed);
    
uniform_int_distribution<long long> dis(1, (long long)1e18);

ll qpow(ll a, ll b, ll mod)
{
    ll r = 1;
    
    for (; b; b >>= 1)
    {
        if (b & 1)
            r = (__int128)r * a % mod;
        a = (__int128)a * a % mod;
    }
    
    return r;
}

bool miller_rabin(ll p, ll k = 30) // 判断素数
{
    if (p < 2) return false;
    if (p == 2) return true;
    if (p == 3) return true;
    
    ll d = p - 1, r = 0;
    while (!(d & 1)) ++r, d >>= 1; // 将d处理为奇数
    
    while(k--) // k次随机运算提高准确率
    {
        ll a = dis(gen) % (p - 2) + 2;
        ll x = qpow(a, d, p);
        
        if (x == 1 || x == p - 1) continue;
        
        for (ll i = 0; i < r - 1; ++i)
        {
            x = (__int128)x * x % p;
            
			if (x == p - 1) break;
        }
        
        if (x != p - 1) return false;
    }
    
    return true;
}

ll pollard_rho(ll x)
{
    ll c = dis(gen) % (x - 1) + 1;
    
    for (ll goal = 1, s = 0, t; true; goal <<= 1, s = t)
    {
    	ll val = 1;
    	
        for (ll step = 1; step <= goal; ++step)
        {
            t = ((__int128)t * t + c) % x; //随机数生成器
            val = ((__int128)val * abs(t - s)) % x;
            
            if (step % 127 == 0)
            {
                ll d = __gcd(val, x);
                if (d > 1) return d;
            }
        }
        
        ll d = __gcd(val, x);
        if (d > 1) return d;
    }
}

ll get_maxi_prime_factor(ll x)
{
    if (x < 2) return 0;
    
    if (miller_rabin(x)) return x;
    
    ll p = x;
    while (p >= x) p = pollard_rho(x); //直到找到平凡
    while (x % p == 0) x /= p;
    
    return max(get_maxi_prime_factor(x), get_maxi_prime_factor(p)); //返回最大质因子
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    
	ll t, n;
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        
        ll mx = get_maxi_prime_factor(n);
        
        if (mx == n) cout << "Prime\n";
        else cout << mx << '\n';
    }
    
    return 0;
}

/* 因式分解：
void get_prime_factors(ll base, ll index, map<ll, ll>& cnt_prime_fac)
{
    if (base < 2) return;
    
    if (miller_rabin(base))
    {
        cnt_prime_fac[base]+=index;
        
        return;
    }
    
    ll new_fac= base, multimes = 0;
    while (new_fac >= base) new_fac = pollard_rho(base); //直到找到平凡
    while (base % new_fac == 0) base /= new_fac, multimes++;
    
    get_prime_factors(base, index, cnt_prime_fac);
	get_prime_factors(new_fac, index * multimes, cnt_prime_fac);
    
    return;
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    
	map<ll,ll> prime_factors;
	get_prime_factors(27, 2, prime_factors);
	
	for(auto x:prime_factors) cout<<x.first<<':'<<x.second<<'\n';
    
    return 0;
}

*/
```



##### Meissel-Lehmer算法

作用：准确地求出 $\pi(x)$ 值和 $[1,x]$ 内各素数，时间复杂度为 $O(\dfrac{x^{\frac23}}{\log^2x})$ ，空间复杂度为 $O(x^\frac13\log^3x\log\log x)$

```c++
#include<bits/stdc++.h>
#define N 216000
#define ll long long
using namespace std;
int mn[N],pri[N/10],fl[N];
int tot,cnt,num,n;
int f[20005][55];
int inf=2e9;
int dp(int x,int y){
    if (x<=20000&&y<=50) return f[x][y];
    if (x==0||y==0) return x;
    if (1ll*pri[y]*pri[y]>=x&&x<N) return max(0,mn[x]-y);
    return dp(x,y-1)-dp(x/pri[y],y-1);
}
void pre(){
    for (int i=2;i<N;i++){
        if (!fl[i]) pri[++tot]=i;
        for (int j=1;i*pri[j]<N&&j<=tot;j++){
            fl[i*pri[j]]=1;
            if (i%pri[j]==0) break;
        }
    }
    for (int i=1;i<N;i++)
        mn[i]=(cnt+=1-fl[i]);
    for (int i=1;i<=20000;i++) f[i][0]=i;
    for (int i=1;i<=20000;i++)
        for (int j=1;j<=50;j++)
            f[i][j]=f[i][j-1]-f[i/pri[j]][j-1];
}
int power(int x,int y){
    int s=1;
    while (y!=0){
        if (y&1){
            if (s>=inf/x) s=inf;
            else s=s*x;
        }
        y/=2;
        if (x>=inf/x) x=inf;
        else x=x*x;
    }
    return s;
}
int yroot(ll x,int y){
    int l=2,r=6666,ans=1;
    while (l<=r){
        int mid=(l+r)/2;
        if (power(mid,y)<=x) ans=mid,l=mid+1;
        else r=mid-1;
    }
    return ans;
}
int work(int m){
    if (m<N) return mn[m]-1;
    int y=yroot(m,3),n=mn[y];
    int ans=dp(m,n)+n-1;
    for (n++;pri[n]*pri[n]<=m;n++)
        ans-=mn[m/pri[n]]-mn[pri[n]]+1;
    return ans;
}
int main(){
    pre();
    scanf("%d",&n);
    int an=work(n);
    printf("%d\n",an);
    for(int i=1;i<=an;++i) printf("%d ",pri[i]);
}
```

```c++
#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;
using namespace std;

ull count_primes(ull x)
{
    if (x <= 1)
        return 0;

    const int eps = 128;
    const int eps_bit = 8;

    uint S2 = sqrtl(x);
    uint S3 = powl(x, 1.0 / 3);
    uint S4 = sqrtl(S2);
    uint B = std::max(2ull, std::min(ull(S2), ull(S3 * std::max(1.0, pow(log(x), 3) * 0.001))));
    uint U = x / B + eps;

    uint a, b, t;
    register uint p, q, r, u, v;
    ll sum = 0;

    vector<char> mu(B + 1);
    mu[1] = 1;
    for (a = 2; a <= B; ++a)
        if (!mu[a])
            for (b = a; b <= B; b += a)
                mu[b] = mu[b] < 0 ? 1 : -1;
    for (a = 2; a * a <= B; ++a)
        if (mu[a * a])
            for (b = a * a; b <= B; b += a * a)
                mu[b] = 0;

    vector<int> pi(U), primes(uint(U / log(U) * 1.25506)), md(U);
    uint count = 0;
    md[1] = 1 << 30, primes[0] = 1;
    for (a = 6; a < U; a += 3)
        md[a] = 3;
    for (a = 4; a < U; a += 2)
        md[a] = 2;
    for (a = 4; a * a < U; ++a)
        if (!md[a])
        {
            for (b = a * a; b < U; b += 6 * a)
                if (!md[b])
                    md[b] = a;
            for (b = a * (a + (3 - a % 3) * 2); b < U; b += 6 * a)
                if (!md[b])
                    md[b] = a;
        }
    for (a = 2; a < U; ++a)
        pi[a] = md[a] ? pi[a - 1] : (primes[++count] = md[a] = a, pi[a - 1] + 1);

    sum += pi[B] - 1;
    for (p = pi[B] + 1; primes[p] <= S2; ++p)
        sum -= pi[x / primes[p]] - p + 1;
    for (a = 1; a <= B; ++a)
        if (mu[a])
            sum += mu[a] * (x / a);
    for (p = sqrtl(x / primes[pi[B]]) + 1; p <= B; ++p)
        if (pi[p] != pi[p - 1])
            sum += pi[B] - pi[std::max(uint(x / p / p), p)];

    for (p = S4 + 1; p <= S3; ++p)
        if (pi[p] != pi[p - 1])
        {
            uint L = p + 1, R = std::min((ull)B, x / p / p);
            sum += (ll)(2 - pi[p]) * (pi[R] - pi[L - 1]);
            ull m = x / p;
            for (u = L; u <= R; u = v + 1)
            {
                t = pi[m / primes[pi[u - 1] + 1]];
                v = m / primes[t];
                if (v > R)
                    v = R;
                sum += (ll)(pi[v] - pi[u - 1]) * t;
            }
        }

    vector<int> bit(U);
    vector<int> nxt(B + 2);
    for (q = 1; q <= B; ++q)
        nxt[q] = q + !mu[q];
    nxt[B + 1] = B + 1;
    for (r = 1; r <= U - eps; ++r)
        bit[r] = r;
    for (p = 1; p <= S4; ++p)
        if (pi[p] != pi[p - 1])
        {
            ull m = x / p;
            if (p <= eps_bit)
            {
                for (q = std::max(p, B / p) + 1; q <= B; ++q)
                {
                    while (q != nxt[q])
                        q = nxt[q] = nxt[nxt[q]];
                    if (q > B)
                        break;
                    if (md[q] <= p)
                    {
                        nxt[q] = q + 1;
                        continue;
                    }
                    sum -= mu[q] * bit[m / q];
                }
                for (r = 1; r < U; ++r)
                    bit[r] = md[r] > p;
                if (pi[p] < count && primes[pi[p] + 1] > eps_bit)
                {
                    for (r = 1; r < U; ++r)
                        if (r + lowbit(r) < U)
                            bit[r + lowbit(r)] += bit[r];
                }
                else
                {
                    for (r = 1; r < U; ++r)
                        bit[r] += bit[r - 1];
                }
            }
            else
            {
                for (q = std::max(p, B / p) + 1; q <= B; ++q)
                {
                    while (q != nxt[q])
                        q = nxt[q] = nxt[nxt[q]];
                    if (q > B)
                        break;
                    if (md[q] <= p)
                    {
                        nxt[q] = q + 1;
                        continue;
                    }
                    if (mu[q] == 1)
                    {
                        for (a = m / q; a; a -= lowbit(a))
                            sum -= bit[a];
                    }
                    else
                    {
                        for (a = m / q; a; a -= lowbit(a))
                            sum += bit[a];
                    }
                }
                for (a = p; a < U; a += lowbit(a))
                    --bit[a];
                for (r = p * p; r < U; r += 6 * p)
                    if (md[r] == p)
                        for (a = r; a < U; a += lowbit(a))
                            --bit[a];
                for (r = p * (p + (3 - p % 3) * 2); r < U; r += 6 * p)
                    if (md[r] == p)
                        for (a = r; a < U; a += lowbit(a))
                            --bit[a];
            }
        }

    return sum;
}

int main()
{
    ull n;
    cin >> n;
    cout << count_primes(n);
}
```



#### 拓展欧几里得定理

求下列关于$x,y$的不定方程的一组可行解：($a,b,x,y$都是整数)
$$
ax+by=(a,b)
$$
裴蜀定理又称贝祖定理（Bézout's lemma）,设 $a,b\in\Z,ab\neq0$ ,则 $\exist x,y\in\Z$：
$$
ax+by=(a,b)
$$

```c++
void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b) x = 1, y = 0;
    else exgcd(b, a % b, y, x), y -= a / b * x;
}
```



若要求 $ax+by=c$ 的一组整数解，需要先求出 $ax_0+by_0=(a,b)$ 的一组解，然后得到 $ax_0\times\dfrac{c}{(a,b)}+by_0\times\dfrac{c}{(a,b)}=(a,b)\times\dfrac{c}{(a,b)}$ ，若 $\dfrac{c}{(a,b)}$ 非整数，无解。

显然有恒等式 $a(x+db)+b(y-da)=c$ ，令 $d=\dfrac1{(a,b)}$ ，可以得到最小非负数解 $x'=(x\bmod \dfrac b{(a,b)}+\dfrac b{(a,b)})\bmod \dfrac b{(a,b)}$ 。特别地若 $a<0$ 可以两边同时取负。



> 洛谷P1082-求 $ax\equiv 1(\bmod b)$ 的最小正整数解 $x$ ，保证有解

本质是 $ax=by+1\to ax-by=1$ ,有解条件是 $(a,b)=1$ ,输出 $(x\bmod b+x)\bmod b$ 即可



> 洛谷P5656-输入 $1\le a,b,c\le 10^9$ ，求 $ax+by=c$ 的整数解。无解输出 `-1` ，有正整数解( $x,y\in Z_+$ )输出正整数解数量，所有正整数解中 $x,y$ 的最小值，最大值。若无正整数解，输出 $x,y$ 代表整数解里 $x,y$ 的最小正整数值

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    ll d = a;
    if (!b)
        x = 1, y = 0;
    else
        d = exgcd(b, a % b, y, x), y -= a / b * x;
    return d;
}
ll a, b, c, x, y, t, d, p, q, k;
signed main()
{
    for (scanf("%lld", &t); t; --t)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        d = exgcd(a, b, x, y);
        if (c % d != 0)
            printf("-1\n");
        else
        {
            x *= c / d, y *= c / d, p = b / d, q = a / d;
            if (x < 0)
                k = ceil((1.0 - x) / p), x += p * k, y -= q * k;
            else
                k = (x - 1) / p, x -= p * k, y += q * k;
            if (y > 0)
            {
                printf("%lld ", (y - 1) / q + 1);
                printf("%lld %lld ", x, (y - 1) % q + 1);
                printf("%lld %lld\n", x + (y - 1) / q * p, y);
            }
            else
                printf("%lld %lld\n", x, y + q * (ll)ceil((1.0 - y) / q));
        }
    }
    return 0;
}
```

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
ll t, a, b, c, x, y, xmi, xmx, ymi, ymx;
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        ll g = exgcd(a, b, x, y);
        if (c % g)
        {
            cout << "-1\n";
            continue;
        }
        a /= g, b /= g, c /= g;
        x *= c, y *= c;
        x = (x % b + b) % b;
        x = x == 0 ? b : x;
        y = (c - a * x) / b;
        if (y > 0)
        {
            xmi = x, ymx = y;
            y %= a;
            y = y == 0 ? a : y;
            x = (c - b * y) / a;
            xmx = x, ymi = y;
            cout << (xmx - xmi) / b + 1 << ' ';
            cout << xmi << ' ' << ymi << ' ' << xmx << ' ' << ymx << '\n';
        }
        else
        {
            cout << x << ' ' << y % a + a << '\n';
        }
    }
    return 0;
}
```



#### 取模公式

##### 费马小定理

若 $p$ 为素数， $a\in Z_+,a\bot p$ ，则 $a^{p-1}\equiv 1(\bmod p)$ 

线性逆元公式(从 $1$ 开始)：$i^{-1}\equiv-\lfloor\dfrac pi\rfloor\times(p\bmod i)^{-1}(\bmod p)$   (实现时 $+p$ 再取模)

任意 $n$ 数线性求逆元公式：记 $s_i$ 是前缀积，则 $a_i^{-1}\equiv s_{i-1}\cdot (s_i)^{-1}\bmod p$ (预处理 $s_{i-1}^{-1}\equiv s_i^{-1}\cdot a_i\bmod p$ )

阶乘线性逆元公式：$((i-1)!)^{-1}=i\times(i!)^{-1}$  (推论： $\dfrac 1i\equiv({i!})^{-1}\times(i-1)!\bmod p$)



##### 卢卡斯定理

$$
n=sp+q,m=tp+r,0\le q,r\le p-1,p是质数，则\\
\begin{pmatrix}n\\m\end{pmatrix}\mod p=
\begin{pmatrix}\lfloor\frac np\rfloor\\\lfloor\frac mp\rfloor\end{pmatrix}
\cdot\begin{pmatrix}n\mod p\\m\mod p\end{pmatrix}\mod p
$$
时间复杂度为$\Omicron(f+g\log n)$,f是预处理组合数复杂度(如阶乘逆元)，g是单次求组合数复杂度

> 洛谷P3807-求 $C_{n+m}^n\bmod p,p$ 是质数， $1\le n,m,p\le10^5,1\le T\le10$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
#define mn 100002
ll a[mn], p, t, n, m;//i!=a[i]
ll qpow(ll a, ll b)
{
	ll res = 1;
	for (; b; b >>= 1, a = a * a % p) if (b & 1)
		res = res * a % p;
	return res;
}
ll C(ll n, ll m)
{
	if (m > n) return 0;
	return ((a[n] * qpow(a[m], p - 2)) % p * qpow(a[n - m], p - 2) % p);
}
ll lucas(ll n, ll m)
{
	if (!m) return 1;
	return C(n % p, m % p) * lucas(n / p, m / p) % p;
}
signed main()
{
	a[0] = 1;
	for (scanf("%lld", &t); t; --t)
	{
		scanf("%lld%lld%lld", &n, &m, &p);
		for(ll i = 1; i <= p; ++i) a[i] = a[i - 1] * i % p;
		printf("%lld\n", lucas(n + m, n));//原题算C(m+n,n)
	}
	return 0;
}
```

**扩展卢卡斯定理**

求 $C_n^m\bmod p$，将 $p$ 质因数分解为 $p_1^{\alpha_1}p_2^{\alpha_2}\cdots$，用中国剩余定理求方程组 $C_n^m\bmod p_1^{\alpha_i}$ 的最小解 $x$。如果 $p_i^{\alpha_1}$ 都是素数且较小可以预处理阶乘，直接对每个子算式上 lucas，否则用下述代码：

不考虑 exCRT 复杂度时，预处理 $n!\div n内p所有倍数乘积\bmod p$ 复杂度为 $O(p+T\log p)$

> 洛谷P4720-求 $C_n^m\bmod p,1\le m\le n\le 10^{18},2\le p\le 10^6$。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
        x = 1, y = 0;
    else
        exgcd(b, a % b, y, x), y -= a / b * x;
}
ll inv(ll a, ll p)
{
    ll x, y;
    exgcd(a, p, x, y);
    return (x + p) % p;
}
ll qpow(ll a, ll b, ll p)
{
    ll r = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            r = r * a % p;
    return r;
}
ll CRT(int n, ll *a, ll *m)
{
    ll M = 1, p = 0;
    for (int i = 1; i <= n; i++)
        M = M * m[i];
    for (int i = 1; i <= n; i++)
    {
        ll w = M / m[i], x, y;
        exgcd(w, m[i], x, y);
        p = (p + a[i] * w * x % M) % M;
    }
    return (p % M + M) % M;
}
ll calc(ll n, ll x, ll P)
{
    if (!n)
        return 1;
    ll s = 1;
    for (ll i = 1; i <= P; i++)
        if (i % x)
            s = s * i % P;
    s = qpow(s, n / P, P);
    for (ll i = n / P * P + 1; i <= n; i++)
        if (i % x)
            s = i % P * s % P;
    return s * calc(n / x, x, P) % P;
}
ll multilucas(ll n, ll m, ll x, ll P)
{
    if (n < m)
        return 0;
    int cnt = 0;
    for (ll i = n; i; i /= x)
        cnt += i / x;
    for (ll i = m; i; i /= x)
        cnt -= i / x;
    for (ll i = n - m; i; i /= x)
        cnt -= i / x;
    return qpow(x, cnt, P) % P * calc(n, x, P) % P * inv(calc(m, x, P), P) %
           P * inv(calc(n - m, x, P), P) % P;
}
ll exlucas(ll n, ll m, ll P)
{
    int cnt = 0;
    ll p[20], a[20];
    for (ll i = 2; i * i <= P; i++)
    {
        if (P % i == 0)
        {
            p[++cnt] = 1;
            while (P % i == 0)
                p[cnt] = p[cnt] * i, P /= i;
            a[cnt] = multilucas(n, m, i, p[cnt]);
        }
    }
    if (P > 1)
        p[++cnt] = P, a[cnt] = multilucas(n, m, P, P);
    return CRT(cnt, a, p);
}
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    ll n, m, p;
    cin >> n >> m >> p;
    cout << exlucas(n, m, p);
    return 0;
}
```



##### 欧拉定理

欧拉定理： $\gcd(a,m)=1$ 则 $a^{\varphi(m)}\equiv 1(\bmod m)$ 

拓展欧拉定理
$$
a^b\equiv\begin{cases}
a^{b\ \bmod\ \varphi(p)},&\gcd(a,p)=1\\
a^b,&\gcd(a,p)\neq1,b < \varphi(p)\\
a^{b\ \bmod\ \varphi(p)+\varphi(p)},&\gcd(a,p)\neq1,b\ge\varphi(p)
\end{cases}(\bmod p)
$$

合并为 $a^b\equiv a^{b\bmod\varphi(p)}\pmod p$。

> SCNUOJ2117-求 $(n!)^{n!}\bmod998244353$，$1\le n\le5000$，$T\le5000$ 次询问

```python
p, phi, f, fp = 998244353, 998244352, [1, 1], [1, 1]
for i in range(2, 5001):
    f.append((f[-1] * i) % p)
    fp.append((fp[-1] * i) % phi)
for _ in range(int(input())):
    n = int(input())
    print(pow(f[n], fp[n], p))
```

> 洛谷P5091-求 $a^b\bmod m,1\le a\le10^9,1\le m\le10^8,1\le b\le10^{2\times10^7}$

```c++
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
```



##### 线性快速幂

同底数和模数，即对变化的 $x$ 求 $a^x\bmod p$，可以时空 $O(\sqrt p)$ 预处理并 $O(1)$ 计算快速幂。

对 $a^b\bmod p$，令 $s=\sqrt p$ 或 $2^k$(如 $k=16$)，可以将 $b$ 拆成 $\lfloor\dfrac bs\rfloor s+(b\bmod s)$，线性预处理出 $a^i,a^{is},0\le i\le s$。即计算 $(a^{\lfloor\frac bs\rfloor s}\times a^{b\ \bmod \ s})\bmod s$。

> LOJ 162 求 $n(\le5\times10^6)$ 次 $x^a\bmod 998244352(1 \le a < p)$

```c++
#include <bits/stdc++.h> //LOJ 162
using namespace std;
using ll = long long;
const ll mn = 65536, mod = 998244352;
ll x, n, a, pw[mn + 10], pw2[mn + 10];
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> x >> n;
    pw[0] = pw2[0] = 1;
    for (ll i = 1; i <= mn; ++i) pw[i] = pw[i - 1] * x % mod;
    for (ll i = 1; i <= mn; ++i) pw2[i] = pw2[i - 1] * pw[mn] % mod;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> a;
        cout << (pw2[a / mn] * pw[a % mn] % mod) << ' ';
    }
    return 0;
}
```

##### 威尔逊定理

对素数 $p$ 有 $(p-1)!\equiv -1\pmod p$

> 杂项：一个数对9取模等于数位和对9取模

#### 欧拉函数

$\varphi(n)$ 表示正整数 $[1,n]$ 中与 $n$ 互质的数的个数，如 $\varphi(0)=0,\varphi(1)=1,\varphi(8)=len\{1,3,5,7\}=4$
$$
\varphi(x)=x\cdot\prod_{i=1}^n(1-\frac 1{p_i}),p_i为x的所有质因数,x\in\N_+
$$
欧拉函数性质：

1. $p$ 是素数时,  $\varphi(p)=p-1$
2. $p$ 是素数时,  $k\in N^*$ , $\varphi(p^k)=p^k-p^{k-1}$
3. 欧拉函数是积性函数， $\forall a,b\in Z,(a,b)=1$ , 有 $\varphi(ab)=\varphi(a)\varphi(b)$
4. $\varphi(n)=\prod_{i=1}^m\varphi(p_i^{k_i})$ 
5. 若 $p$ 是素数，$\varphi(i\cdot p)=\begin{cases}\varphi(i)\cdot(p-1)&,p\nmid i\\\varphi(i)\cdot p&,p\mid i\end{cases}$
6. $n=\sum_{d|n}\varphi(d)$ 

求一个数的欧拉函数： $O(\sqrt n)$

```c++
ll t = phi = m;
for (ll i = 2; i * i <= m; ++i) if (t % i == 0)
{
    phi = phi - phi / i;
    while (t % i == 0) t /= i;
}
if (t > 1) phi = phi - phi / t; //phi为所求
```

埃氏筛求 $[1,n]$ 欧拉函数：

```c++
// C++ Version
void pre() {
  memset(is_prime, 1, sizeof(is_prime));
  int cnt = 0;
  is_prime[1] = 0;
  phi[1] = 1;
  for (int i = 2; i <= 5000000; i++) {
    if (is_prime[i]) {
      prime[++cnt] = i;
      phi[i] = i - 1;
    }
    for (int j = 1; j <= cnt && i * prime[j] <= 5000000; j++) {
      is_prime[i * prime[j]] = 0;
      if (i % prime[j])
        phi[i * prime[j]] = phi[i] * phi[prime[j]];
      else {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      }
    }
  }
}
```

 (洛谷P3601, 求 $\sum_{i=l}^r(i-\varphi(i))\bmod666623333,1\le l\le r\le10^{12},r-l\le10^6$ )

求区间欧拉函数，复杂度为 $\sum_{p\in prime}\dfrac{r-l}p+1=\sqrt r+(r-l)\ln r$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 1000002
#define MOD 666623333
ll l, r, ans, cnt, prime[MAXN], a[MAXN], b[MAXN];
bool vis[MAXN];
signed main()
{
	for(ll i=2;i<=MAXN;++i)
	{
		if (!vis[i]) prime[++cnt] = i;
		for (ll j = i << 1; j <= MAXN; j += i) vis[j] = true;
	}
	scanf("%lld%lld", &l, &r);
	for(ll i=l;i<=r;++i) a[i - l] = b[i - l] = i;
	ll i = 1;
	while (prime[i] * prime[i] <= r)
	{
		ll p = prime[i];
		for (ll x = (p - l % p) % p; x + l <= r; x += p)
		{
			(a[x] /= p) *= p - 1;
			while (b[x] % p == 0) b[x] /= p;
		}
		++i;
	}
	for(ll i=0;i<=r-l;++i)
	{
		if (b[i] != 1) (a[i] /= b[i]) *= b[i] - 1;
		(ans += l + i - a[i]) %= MOD;
	}
	printf("%lld", ans);
	return 0;
}
```



#### 中国剩余定理

CRT(Chnese Remainder Theorem) 求解如下方程最小正元 $x$ ：( $a_i$ 两两互质)

$$
\begin{cases}
x\equiv b_1(\mod a_1)\\
x\equiv b_2(\mod a_2)\\
\quad\quad\quad\ \ \ \vdots\\
x\equiv b_k(\mod a_k)\\
\end{cases}
$$

设 $p=\prod a$，通解为 $x+kp$。方程组数为 $n$ 则复杂度为 $O(n\log n)$。(exCRT 同)

> 洛谷P1495-输入不等式数 $n$ 和 $a_i,b_i$ ( $a_i$ 互质)，求最小 $x$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 13
ll n, a[mn], b[mn], pd = 1, c, ci, z, ans;
void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
        x = 1, y = 0;
    else
        exgcd(b, a % b, y, x), y -= a / b * x;
}
signed main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lld%lld", &a[i], &b[i]);
        pd *= a[i];
    }
    for (ll i = 1; i <= n; ++i)
    {
        c = pd / a[i], z = 0, ci = 0;
        exgcd(c, a[i], ci, z);
        ans += b[i] * c * ((ci + a[i]) % a[i]);
    }
    printf("%lld", ans % pd);
    return 0;
}
```

**拓展中国定理：** ( $a_i$ 不互质) 洛谷P4777- $n\le10^5,\gcd\le10^{18},1\le b_i,a_i\le10^{18}$

设前 $i-1$ 个不定方程式的答案是 $ans$，前 $i-1$ 个模数的 $lcm$ 为 $m$，有：$ans+mx\equiv a_i\pmod{p_i}$，用 exgcd 求出新的 $x$，则新的 $ans+mx$ 为新答案。

如果要求 $b_i x\equiv a_i\pmod{p_i}$，由于 $b_i$ 逆元不一定存在不能拉过去。转化为求不定方程 $b_i(ans+mx)\equiv a_i\pmod{p_i}$(那么初始值是 $an=0,m=1$ 从 $i=1$ 开始推) 

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC diagnostic ignored "-Wpedantic" using int128 = __int128; //忽略警告
#define mn 100002
ll n, ai[mn], bi[mn], x, y, k, m, ans, a, b, c, gcc, bg;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    ll d = a;
    if (!b)
        x = 1, y = 0;
    else
        d = exgcd(b, a % b, y, x), y -= a / b * x;
    return d;
}
signed main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i)
        scanf("%lld%lld", ai + i, bi + i);
    m = ai[1], ans = bi[1];
    for (ll i = 2; i <= n; ++i)
    {
        a = m, b = ai[i], c = (bi[i] - ans % b + b) % b;
        gcc = exgcd(a, b, x, y), bg = b / gcc;
        if (c % gcc != 0)
            return printf("-1") & 0;
        x = (__int128)x * (c / gcc) % bg;
        ans += x * m, m *= bg, ans = (ans % m + m) % m;
    }
    printf("%lld", ans);
    return 0;
}
```



#### BSGS

求最小非负整数 $x$ ，满足 $a^x\equiv b(\bmod p), p$ 是质数， $O(\sqrt p)$  (洛谷P4195)

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll bsgs(ll a, ll b, ll p)
{ // min x of a^x%p=b
    if (a % p == 0 && b)
    {
        return -1;
    }
    if (b == 1)
    {
        return 0;
    }
    map<ll, ll> h;
    ll m = sqrt(p) + 1, s = 1;
    for (ll i = 1; i <= m; ++i)
    {
        h[b] = i;
        s = s * a % p, b = b * a % p;
    }
    a = s;
    for (ll i = 1; i <= m; ++i)
    {
        if (h.count(a))
        {
            return i * m - h[a] + 1;
        }
        a = a * s % p;
    }
    return -1;
}
signed main()
{
    ll a, b, p;
    cin >> p >> a >> b;
    ll ans = bsgs(a, b, p);
    cout << (ans == -1 ? "no solution" : to_string(ans));
    return 0;
}
```

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 1000700
#define mod 1000007
struct hasht
{
    ll mp[mn], hsh[mn]; //避免关键字冲突map,hash
    ll find(ll x)       //拉链法构造散列表
    {
        ll t = x % mod;
        for (; mp[t] != x && mp[t] != -1; (t += 107) %= mod)
            ;
        return t;
    }
    void insert(ll x, ll i)
    {
        ll f = find(x);
        mp[f] = x, hsh[f] = i;
    }
    bool in(ll x)
    {
        return mp[find(x)] == x;
    }
    ll get_hash(ll x)
    {
        return hsh[find(x)];
    }
    void init()
    {
        memset(hsh, -1, sizeof hsh), memset(mp, -1, sizeof mp);
    }
} h;
ll a, b, p, m, s;
signed main()
{
    scanf("%lld%lld%lld", &p, &a, &b);//a%=p,b%=p
    h.init();
    if (a % p == 0 && b)
    {
        return printf("no solution"), 0;
    }
    if (b == 1)
    {
        return !printf("0");
    }
    m = ceil(sqrt((double)p)) + 1, s = 1;
    for (ll i = 1; i <= m; ++i)
    {
        h.insert(b, i);
        s = (1LL * s * a) % p, b = (1LL * a * b) % p;
    }
    a = s;
    for (ll i = 1; i <= m; ++i)
    {
        if (h.in(a))
        {
            return printf("%lld", i * m - h.get_hash(a) + 1) & 0;
        }
        a = (1LL * a * s) % p;
    }
    return printf("no solution"), 0;
}
```

若 $p$ 不是质数，使用 exBSGS 算法 (洛谷P4195) 复杂度 $O(\sqrt{\varphi(p)})$

```c++
#include <bits/stdc++.h>
using namespace std;
#define LL long long
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
```

BSGS 的结构是一条链(exBSGS cnt 部分)加一条环。可以用 BSGS 求环长的依据：有环必然存在 $a^p\equiv a\pmod p$ 即 $a^{p-1}\equiv 1\pmod p$，故环长为 $p-1$。



### 计算几何

三角函数： 使用**弧度制**，弧度制 `deg` 跟角度制 `arg` 的转换公式：( $\pi=180°$ )
$$
1=\dfrac{deg}{180°}=\dfrac{arg}{\pi}\Rightarrow 
\begin{cases}
arg=\dfrac{\pi\cdot deg}{180°}\\
deg=\dfrac{180°\cdot arg}{\pi}
\end{cases}
$$
三角函数是 `sin, cos, tan` ，反三角函数是 `asin, acos, atan, atan2(y, x)` ，其中 `atan2(y, x)=atan(y/x)` 。反三角函数求出的角度值域范围是：`asin, atan` 为 $[-\dfrac\pi2,\dfrac\pi2]$ ，`acos` 为 $[0,\pi]$ ，`atan2` 为 $[-\pi,\pi]$ 。

注意这里 `atan2` 的含义是：向量 $(x,y)$ 与 $x$ 正半轴夹角的大小，即从 $X$ 轴逆时针旋转的角度，如果为负数就表示顺时针旋转的角度。与 `atan` 是本质不同的函数



#### 向量

向量点乘，有结论： $\vec a\cdot \vec b$ 的符号大于 $0$ 夹角在 $[0,90°)$ ，等于 $0$ 为 $90°$ ；小于 $0$ 为 $(90°,180°]$ 。点乘的几何意义是 $\vec a$ 长度与 $\vec b$ 投影到 $\vec a$ 的长度的乘积或 $\vec b$ 长度与 $\vec a$ 投影到 $\vec b$ 的长度的乘积。即 $\vec a\cdot \vec b=|\vec a|\cdot|\vec b|\cos<\vec a,\vec b>$ 。如果是正的，说明投影后朝向一致，否则说明投影后朝向不一致

向量 $\vec a,\vec b$ 叉乘得到一个向量 $\vec c$，其方向垂直这两向量形成的平面，如果 $\vec b$ 满足 $\vec a$ 经由 $180°$ 内的逆时针旋转可以与其平行，那么 $\vec c$ 的竖坐标是正的；如果是 $180°$ 内的顺时针，那么是负的。可以用右手定则表示：当右手的四指从 $\vec a$ 以不超过 $180°$ 的转角转向 $\vec b$ 时，竖起的大拇指指向是 $\vec a\times \vec b$ 的方向(向上正，向下负)，叉乘满足： $(\lambda \vec a)\times \vec b=\vec a \times(\lambda\vec b)=\lambda (\vec a\times \vec b)$ ,  $(\vec a+\vec b)\times\vec c=\vec a\times\vec c+\vec b\times \vec c$ 

判断向量共线(平行)：两非零向量 $\vec a,\vec b$ 共线当且仅当存在唯一实数 $\lambda$ ，使得 $\vec b=\lambda \vec a$ ，或 $|\vec{a}\cdot \vec{b}|=|\vec a||\vec b|$ (也可以用 $\vec a\times \vec b=0$ )

判断向量垂直： $a\cdot b=0$

向量与原点的夹角： $\theta=\arctan\dfrac{y}{x}$ ，由角和长度 $l$ 逆求坐标 $(l\cos\theta,l\sin\theta)$

两向量的夹角：$\cos<\vec a,\vec b>=\dfrac{\vec a\cdot\vec b}{|\vec a||\vec b|}$ ，再来个反三角函数  $\arccos$ 即可。

> 若 $A,B,C$ 三点共线：那么对任意点 $O$ 有 $\vec{OB}=\lambda \vec{OA}+(1-\lambda)\vec{OC}$

向量旋转公式：设向量 $\vec a=(x,y)$ ，倾角为 $\alpha$ ，长度为 $l=\sqrt{x^2+y^2}$ ，即 $\vec a=(l\cos\alpha,l\sin\alpha)$ ，逆时针旋转 $\beta$ ，得到 $\vec{a'}=(l\cos(\alpha+\beta),l\sin(\alpha+\beta))$ 。展开化简得：
$$
\begin{align}
\vec{a'}&=(l(\cos\alpha\cos\beta-\sin\alpha\sin\beta),l(\sin\alpha\cos\beta+\cos\beta\sin\alpha))\\
&=(x\cos\beta-y\sin\beta,x\sin\beta+y\cos\beta)
\end{align}
$$

依次取 $\beta=90°,180°,270°$ ，对 $(x,y)$ 得到的分别为： $(-y,x),(-x,-y),(y,-x)$ 

```c++
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
class Point
{
public:
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point &p) const { return Point(x - p.x, y - +p.y); }
    Point operator*(const double &a) const { return Point(x * a, y * a); }
    Point operator/(const double &a) const { return Point(x / a, y / a); }
    double norm() const { return x * x + y * y; }
    double abs() const { return sqrt(norm()); }
    bool operator<(const Point &p) const
    {
        return x != p.x ? x < p.x : y < p.y;
    }
    bool operator==(const Point &p) const
    {
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }
};
typedef Point Vector;
double dot(const Point &a, const Point &b)
{
    return a.x * b.x + a.y * b.y;
}
double cross(const Point &a, const Point &b)
{
    return a.x * b.y - a.y * b.x;
}
bool isParallel(const Vector &a, const Vector &b)
{
    return equals(cross(a, b), 0.0);
}
bool isOrthogonal(const Vector &a, const Vector &b)
{
    return equals(dot(a, b), 0.0);
}
double getDistance(const Point &a, const Point &b)
{
    return (a - b).abs();
}
//极坐标互换
double arg(const Vector &p) { return atan2(p.y, p.x); }
Vector polar(const double &a, const double &r)
{
    return Point(cos(r) * a, sin(r) * a);
}
```



#### 线段

##### 点到直线距离

点 $P$ 到直线 $AB$ 的距离 $|PD|=\dfrac{|\vec{AB}\times \vec{AP}|}{|AB|}$

```c++
double dis_lp(const Point &a, const Point &b, const Point &p)
{
    return abs(cross(b - a, p - a)) / (b - a).abs();
}
```

点到线段的距离：

```c++
double dis_sp(const Point &a, const Point &b, const Point &p)
{
    if (dot(b - a, p - a) < 0.0)
    {
        return (p - a).abs();
    }
    if (dot(a - b, p - b) < 0.0)
    {
        return (p - b).abs();
    }
    return dis_lp(a, b, p);
}
```



##### 线段相交判定

判断线段 $AB,CD$ 是是否相交：

```c++
bool isIntersect(const Point &a, const Point &b, const Point &c, const Point &d)
{
    return cross(b - a, c - a) * cross(b - a, d - a) <= 0 && cross(d - c, a - c) * cross(d - c, b - c) <= 0;
} // 条件: A,B,C,D 不共线
```

```c++
ll f(const Point &a, const Point &b)
{
    if (cross(a, b) > eps)
    {
        return 1; //逆时针
    }
    if (cross(a, b) < -eps)
    {
        return -1; //顺时针
    }
    if (dot(a, b) < -eps)
    {
        return 2; // P在AB左方
    }
    if (a.abs() < b.abs())
    {
        return -2; // P在AB右方
    }
    return 0; // P在AB内部
}
bool isIntersect(const Point &a, const Point &b, const Point &c, const Point &d)
{
    return f(b - a, c - a) * f(b - a, d - a) <= 0 && f(d - c, a - c) * f(d - c, b - c) <= 0;
}
```

直线 $AB$ 与线段 $CD$ ，那么只需要判断 $C,D$ 是否在 $AB$ 两端即可，不必反过来再判断一次，即只需要判断：
$$
f(\vec{AB},\vec{AC})\cdot f(\vec{AB},\vec{AD})\le 0
$$
线段 $AB,CD$ 的距离，如果两线段相交，距离为 $0$ ，否则分别计算 $A,B$ 到线段 $CD$ 的 $C,D$ 到线段 $AB$ 的距离，取四者最小值即可



##### 直线交点

直线 $AB,CD$ 交于点 $P$  ，则 $\vec{OP}=\vec{OC}+\dfrac{\vec{CA}\times\vec{AB}}{\vec{CD}\times\vec{AB}}\cdot\vec OD$

```c++
Point intersect(const Point &a, const Point &b, const Point &c, const Point &d)
{
    return c + (d - c) * (cross(a - c, b - a) / cross(d - c, b - a));
}
```

线段 $AB,CD$ 交点，那么可以先判断 $AB,CD$ 是否相交，如果是的话同直线交点的处理方法，如果不相交，输出不存在



##### 点在直线投影

点 $P$ 在直线 $AB$ 上投影点 $C$ 满足 $\vec{OC}=\vec{OA}+\dfrac{\vec{AB}\cdot\vec{AP}}{|AB|^2}\cdot\vec{AB}$

```c++
Point project(const Point &a, const Point &b, const Point &p)
{
    return a + (b - a) * (dot(b - a, p - a) / (b - a).norm());
}
```

 $P$ 关于 $AB$ 对称的点 $P'$ ，可以先求投影点 $P_0$ ，那么根据 $\vec{PP'}=2\vec{PP_0}$ ，可知 $\vec{OP'}=\vec{OP}+\vec{PP'}=\vec{OP}+2\vec{PP_0}$ 



求圆 $P$ 与直线 $AB$ 的交点 $C,D$，求出 $P$ 在 $AB$ 的投影点及距离 $|PE|$ ，则：
$$
\vec{OC}=\vec{OE}+\vec{EC}=\vec{OE}-\dfrac{\sqrt{r^2-|PE|^2}}{|AB|}\vec{AB}
\\
\vec{OD}=\vec{OE}-\vec{EC}=\vec{OE}+\dfrac{\sqrt{r^2-|PE|^2}}{|AB|}\vec{AB}
$$
求两圆 $P,Q$ 的交点：由余弦定理，求出夹角 $\cos\theta=\cos\ang APQ=\cos\ang BPQ=\dfrac{|PQ|^2+r_1^2-r_2^2}{2r_1|PQ|}$ ，可得角度 $\theta$ 。根据反三角函数可知 $\vec{OP}$ 的夹角 $\alpha$ ，则 $\vec{PA}=(r_1\cos(\alpha+\theta),r_1\sin(\alpha+\theta))$ 且 $\vec{PB}=(r_1\cos(\alpha-\theta),r_1\sin(\alpha-\theta))$ ，那么 $\vec{OA}=\vec{OP}+\vec{PA},\vec{OB}=\vec{OP}+\vec{PB}$ 

两圆是否相交(等)：圆心距离 $d$ 小于等于 $r_1+r_2$ 即 $d^2\le(r_1+r_2)^2$



#### 多边形

由在同一平面且<u>不在同一直线上</u>的三条或三条以上的线段首尾顺次连结且<u>不相交</u>所组成的封闭图形叫做多边形。又称简单多边形。不满足“不相交”的就是复杂多边形。

凸多边形是没有任何一个内角为优角(范围在区间 $(180°,360°)$ 的角)的多边形。凹多边形则至少有一个优角。凸多边形以任意一条边延长为直线，其他所有边都必然在直线的同一侧。凹多边形则存在不在同一侧的情况。凸多边形上的点或内部点间连线位于多边形都在多边形内部或边上。凹多边形存在两个点的连线不全在多边形内部

多边形的性质：

- 无论凹凸， $n$ 边形的内角和是 $180°\cdot (n-2)$

- 凸多边形外角和是 $360°$

- $n$ 边形的对角线数量是 $\dfrac{n(n-3)}2$ 

三角形的性质：

- 设 $p=\dfrac12(a+b+c),R$ 是外接圆半径， $r$ 是内接圆半径，则面积公式：

- $S=\sqrt{p(p-a)(p-b)(p-c)}=\dfrac{abc}{4R}=rp$ 

- 三角形重心坐标是三点坐标的平均值。

- 三角形外角和是 $360°$ ，等于不相邻内角之和。

- 三角形中线将三角形划分为面积相等的两部分。

- 直角三角形斜边中线等于斜边一半。

- 三线合一：等腰三角形顶角平分线、底边中线、底边高是同一条直线

**多边形面积公式**：(点按逆时针排序)
$$
S=\dfrac12\sum_{i=1}^n\vec{OA_i}\times \vec{OA_{i+1}}
$$
**PIP 问题**：点是否在多边形内部(或边上)问题。

- **光线投射算法**，从该点出发作射线(注意不是直线)，如果与奇数个点相交在多边形内，偶数个点相交在多边形外。实现上，可以作平行 $x$ 轴的射线，枚举每条线段，如果线段两端点坐标值都小于该点，那么忽略该线段，否则套用上文直线与线段相交的模板进行判断即可。特别注意，如果相交在端点，那么应当算相交了两次(相交时特判横坐标是否与其中一个端点相同即可)。
- **回转数算法**求这个问题。计算该点与每相邻两个顶点的夹角弧度制(取范围 $[-\pi,\pi]$ )，然后将其求和，判断是否为 $0$ ，是就在多边形外。实现上，$O(n)$ 枚举相邻边，利用 $<\vec a,\vec b>=\arccos\dfrac{\vec a\cdot\vec b}{|\vec a||\vec b|}$ 求角，累加，最后与 $0$ 判断即可(注意浮点误差)

是否位于多边形边上，可以通过检查p与相邻两端点的向量(p为起点)是否在同一直线且方向相反(相同是可以内包的)

```c++
int contains(Polygon g, Point p) //伪代码
{
    int n = g.size();
    bool x = false;
    for(int i=0;i<n;i++)
    {
        Point a = g[i] - p, b = g[(i+1)%n]-p;
        if(abs(cross(a,b))<EPS&&dot(a,b)<EPS)
            return 1;
        if(a.y<b.y) swap(a,b);
        if(a.y<EPS && EPS<b.y && cross(a,b)>EPS)
            x=!x;
    }
    return (x?2:0);
}
```

p3454-任意多边形的对称轴数：边长平方-两边差积(内角)交替组成序列，化环为二倍链，使用字符串哈希求每个长为 $2n$ 的序列区间是否是回文串。(/KMP/mahacher)



#### 极角排序

如果极角大小值相同，可以规定按照离原点的远近排序(越近越小)

atan2 参考代码：(范围是 $[-\pi,\pi]$ )

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define sc(x) scanf("%lld", &x)
#define cp const point &
struct point
{
    db x, y;
    point(db a = 0, db b = 0) : x(a), y(b) {}
    point operator-(cp r) const { return point(x - r.x, y - r.y); }
    db ang() const { return atan2(y, x); }
    db norm() const { return x * x + y * y; }
} p[1010], p0;
db cross(cp a, cp b) { return a.x * b.y - a.y * b.x; }
bool operator<(cp a, cp b)
{
    point p1 = (a - p[1]), p2 = (b - p[1]);
    return p1.ang() != p2.ang() ? p1.ang() < p2.ang() : p1.norm() < p2.norm();
}
ll n, b;
signed main()
{
    sc(n);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    sort(p + 2, p + 1 + n); //假设以第一个点为坐标原点
    for (ll i = 1; i <= n; ++i)
    {
        printf("(%lf, %lf) %lf\n", p[i].x, p[i].y, (p[i] - p[1]).ang());
    }
    return 0;
}
```

如果范围要求 $[0,2\pi]$ 的排序，那么更改 `ang` 函数的定义：

```c++
db ang() const
{
    db v = atan2(y, x);
    return v < 0 ? v + 2 * acos(-1) : v;
}
```



叉乘 (极角取值为 $[0,2\pi]$ ，最左下为原点):

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define sc(x) scanf("%lld", &x)
#define mn 100010
#define cp const point &
ll n, ss;
struct point
{
    db x, y;
    point(db a = 0, db b = 0) : x(a), y(b) {}
    point operator-(cp r) const { return point(x - r.x, y - r.y); }
    db norm() const { return x * x + y * y; }
} p[mn];
db cross(cp a, cp b) { return a.x * b.y - a.y * b.x; }
bool operator<(cp a, cp b)
{
    db v = cross(a - p[1], b - p[1]);
    return v > 0 || (v == 0 && (a - p[1]).norm() < (b - p[1]).norm());
}
signed main()
{
    sc(n);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lf%lf", &p[i].x, &p[i].y);
        if (p[i].y < p[1].y || (p[i].y == p[1].y && p[i].x < p[1].x))
        {
            swap(p[i], p[1]);
        }
    }
    sort(p + 2, p + 1 + n);
    for (ll i = 1; i <= n; ++i)
    {
        printf("(%lf, %lf)\n", p[i].x, p[i].y);
    }
    return 0;
}
```

任意点为原点：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define sc(x) scanf("%lld", &x)
#define mn 100010
#define cp const point &
ll n, ss;
struct point
{
    db x, y;
    point(db a = 0, db b = 0) : x(a), y(b) {}
    point operator-(cp r) const { return point(x - r.x, y - r.y); }
    db norm() const { return x * x + y * y; }
    ll quadrant() const
    {
        return 1 * (x > 0 && y >= 0) + 2 * (x <= 0 && y > 0) + 3 * (x < 0 && y <= 0) + 4 * (x >= 0 && y < 0);
    }
} p[mn], s[mn], p0;
db cross(cp a, cp b) { return a.x * b.y - a.y * b.x; }
bool operator<(cp a, cp b)
{
    if ((a - p0).quadrant() != (b - p0).quadrant())
    {
        return (a - p0).quadrant() < (b - p0).quadrant();
    }
    db v = cross(a - p0, b - p0);
    return v > 0 || (v == 0 && (a - p0).norm() < (b - p0).norm());
}
signed main()
{
    sc(n);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    sort(p + 1, p + 1 + n);
    for (ll i = 1; i <= n; ++i)
    {
        printf("(%lf, %lf)\n", p[i].x, p[i].y);
    }
    return 0;
}
```



#### 凸包

平面上能包含所有给定点的周长最小的凸多边形是凸包。(注意不是面积最小)。上凸壳是圆的第一第二象限逆时针方向朝向(含 $x$ 负半轴)，其余是下凸壳。

##### Graham

Graham算法：(洛谷P2742)

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define sc(x) scanf("%lld", &x)
#define mn 100010
#define cp const point &
ll n, ss;
struct point
{
    db x, y;
    point(db a = 0, db b = 0) : x(a), y(b) {}
    point operator+(cp r) const { return point(x + r.x, y + r.y); }
    point operator-(cp r) const { return point(x - r.x, y - r.y); }
    db norm() const { return x * x + y * y; }
} p[mn], s[mn];
db cross(cp a, cp b) { return a.x * b.y - a.y * b.x; }
bool operator<(cp a, cp b)
{
    db v = cross(a - p[1], b - p[1]);
    return v > 0 || (v == 0 && a.norm() < b.norm());
}
signed main()
{
    sc(n);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lf%lf", &p[i].x, &p[i].y);
        if (p[i].y < p[1].y || (p[i].y == p[1].y && p[i].x < p[1].x))
        {
            swap(p[i], p[1]);
        }
    }
    sort(p + 2, p + 1 + n);
    s[++ss] = p[1];
    for (ll i = 2; i <= n; ++i)
    {
        while (ss > 1 && cross(s[ss] - s[ss - 1], p[i] - s[ss]) < 0)
        { //根据题目要求选择 < 或 <=
            --ss;
        }
        s[++ss] = p[i];
    }
    for (ll i = 1; i <= ss; ++i) //输出各点
    {
        printf("%lf %lf\n", s[i].x, s[i].y);
    }
    return 0;
}
```

##### Andrew

Andrew算法：(洛谷P2742)

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define sc(x) scanf("%lld", &x)
#define mn 100010
#define cp const point &
ll n, ss, top;
struct point
{
    db x, y;
    point(db a = 0, db b = 0) : x(a), y(b) {}
    point operator+(cp r) const { return point(x + r.x, y + r.y); }
    point operator-(cp r) const { return point(x - r.x, y - r.y); }
    db norm() const { return x * x + y * y; }
} p[mn], s[mn * 2];
db cross(cp a, cp b) { return a.x * b.y - a.y * b.x; }
bool operator<(cp a, cp b)
{
    return a.x != b.x ? a.x < b.x : a.y < b.y;
}
void f(ll i)
{
    while (ss > top && cross(s[ss] - s[ss - 1], p[i] - s[ss]) < 0)
    { //根据题目要求选择 < 或 <=
        --ss;
    }
    s[++ss] = p[i];
}
signed main()
{
    sc(n);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    sort(p + 1, p + 1 + n);
    top = 1, s[ss = 1] = p[1];
    for (ll i = 2; i <= n; ++i)
    {
        f(i);
    }
    top = ss;
    for (ll i = n - 1; i >= 1; --i)
    {
        f(i);
    }
    for (ll i = 1; i < ss; ++i) //输出各点
    {
        printf("%lf %lf\n", s[i].x, s[i].y);
    }
    return 0;
}
```

##### 直径

旋转卡壳模板-求凸包直径：(洛谷P1452)

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 50010
#define cp const point &
struct point
{
    ll x, y;
    point(ll a = 0, ll b = 0) : x(a), y(b) {}
    point operator-(cp r) const { return point(x - r.x, y - r.y); }
    ll norm() const { return x * x + y * y; }
} p[mn], s[mn];
ll cross(cp a, cp b) { return a.x * b.y - a.y * b.x; }
bool operator<(cp a, cp b)
{
    ll v = cross(a - p[1], b - p[1]);
    return v > 0 || (v == 0 && (a - p[1]).norm() < (b - p[1]).norm());
}
ll area(cp a, cp b, cp c) { return cross(b - a, c - a); }
ll n, ss, ans;
signed main()
{
    sc(n);
    for (ll i = 1; i <= n; ++i)
    {
        sc(p[i].x), sc(p[i].y);
        if (p[i].x < p[1].x || (p[i].x == p[1].x && p[i].y < p[1].y))
        {
            swap(p[i], p[1]);
        }
    }
    sort(p + 2, p + 1 + n);
    for (ll i = 1; i <= n; ++i)
    {
        while (ss > 1 && cross(s[ss] - s[ss - 1], p[i] - s[ss]) <= 0)
        {
            --ss;
        }
        s[++ss] = p[i];
    }
    s[ss + 1] = s[1];
    if (ss == 2) // not n==2
    {
        printf("%lld", (s[2] - s[1]).norm());
        return 0;
    }
    for (ll i = 1, j = 3; i <= ss; ++i)
    {
        while (area(s[i], s[i + 1], s[j]) <= area(s[i], s[i + 1], s[j % ss + 1]))
        {
            j = j % ss + 1;
        }
        ans = max(ans, max((s[j] - s[i]).norm(), (s[j] - s[i + 1]).norm()));
    }
    printf("%lld", ans);
    return 0;
}
```

如果每次以某个端点为原点进行极角排序，再枚举线段第二端点，配合单调栈，可以用 $O(n^2\log n)$ 实现枚举(但是处理概率连乘积乘除特别是 $1$ (对应概率为 $0$ )比较麻烦)，暂时没有什么好的实现方法

##### 点与凸包相交

取其中的一个点，他和其他点可以组成n-2个三角形，利用二分判断差积，判断他是在当前三角形内，还是在三角形左边，还是在三角形右边，或者是三角形外 (UVALive 7281)

或者用另一个实现(下文)。

```c++
bool check(Point A,Point*p,int n )//判断点在凸包内模板 O（logn）
{
    int l=1,r=n-2,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        double a1=Cross(p[mid]-p[0],A-p[0]);
        double a2=Cross(p[mid+1]-p[0],A-p[0]);
        if(a1>=0&&a2<=0)
        {
            if(Cross(p[mid+1]-p[mid],A-p[mid])>=0)return true;
            return false;
        }
        else if(a1<0)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return false;
}
```

##### 两凸包相交

点集 $A,B$ 的闵可夫斯基和(Mincowski sum)是 $A+B=\{a+b|a\in A,b\in B\}$，即对 $a$ 每个点位置放一个 $B$ 的并。

两凸包的闵可夫斯基和是凸包，可以 $O(n\log n)$ 求出。使用滑窗拼出然后复杂度在凸包重排。

应用：判断凸多边形是否相交。(如果不凸，枚举一多边形每点 PIP $O(nm)$)

判定：$\exists a\in A,b\in B,a=b$ 即 $a-b=0$，故设 $B=-B$，求 $A+B$ 的闵可夫斯基和，然后判断原点($B$ 左下角)是否在凸包内。

> p4557-给定凸包(不全共线，点不同) $A,B(n,m\le 10^5)$，有 $q\le10^5$ 个询问，每次将 $B$ 每个点平移 $d(dx,dy)$，问移动后 $A,B$ 交不交。

$A=B+d$ 可以转化为 $A-B=d$，所以对每个 $d$ 判断在不在闵可夫斯基和凸包即可。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=1e5+10;
struct Node
{
	ll x,y;
	Node operator - (Node A) {return (Node){x-A.x,y-A.y};}
	Node operator + (Node A) {return (Node){x+A.x,y+A.y};}
	ll operator * (Node A) const {return x*A.y-y*A.x;}
	ll len() const {return x*x+y*y;}
}A[N],C1[N],C2[N],s1[N],s2[N],bs;
ll cmp1(const Node&A,const Node&B) {return A.y<B.y||(A.y==B.y&&A.x<B.x);}
ll cmp2(const Node&A,const Node&B) {return A*B>0||(A*B==0&&A.len()<B.len());}
ll n,m,sta[N],top,q,tot;
void Convex(Node *A,ll &n)
{
	sort(A+1,A+n+1,cmp1);
	bs=A[1];sta[top=1]=1;
	for(ll i=1;i<=n;i++) A[i]=A[i]-bs;
	sort(A+2,A+n+1,cmp2);
	for(ll i=2;i<=n;sta[++top]=i,i++)
		while(top>=2&&(A[i]-A[sta[top-1]])*(A[sta[top]]-A[sta[top-1]])>=0) top--;
	for(ll i=1;i<=top;i++) A[i]=A[sta[i]]+bs;
	n=top;A[n+1]=A[1];
}
void Minkowski()
{
	for(ll i=1;i<n;i++) s1[i]=C1[i+1]-C1[i];s1[n]=C1[1]-C1[n];
	for(ll i=1;i<m;i++) s2[i]=C2[i+1]-C2[i];s2[m]=C2[1]-C2[m];
	A[tot=1]=C1[1]+C2[1];
	ll p1=1,p2=1;
	while(p1<=n&&p2<=m) ++tot,A[tot]=A[tot-1]+(s1[p1]*s2[p2]>=0?s1[p1++]:s2[p2++]);
	while(p1<=n) ++tot,A[tot]=A[tot-1]+s1[p1++];
	while(p2<=m) ++tot,A[tot]=A[tot-1]+s2[p2++];
}
ll in(Node a)
{
	if(a*A[1]>0||A[tot]*a>0) return 0;
	ll ps=lower_bound(A+1,A+tot+1,a,cmp2)-A-1;
	return (a-A[ps])*(A[ps%tot+1]-A[ps])<=0;
}
int main()
{
	cin>>n>>m>>q;
	for(ll i=1;i<=n;i++)
		scanf("%lld%lld",&C1[i].x,&C1[i].y);
	Convex(C1,n);
	for(ll i=1;i<=m;i++)
	{
		scanf("%lld%lld",&C2[i].x,&C2[i].y);
		C2[i].x=-C2[i].x;C2[i].y=-C2[i].y;
	}
	Convex(C2,m);
	Minkowski();
	Convex(A,tot);
	bs=A[1];for(ll i=tot;i>=1;i--) A[i]=A[i]-A[1];
	while(q--)
	{
		scanf("%lld%lld",&A[0].x,&A[0].y);
		printf("%lld\n",in(A[0]-bs));
	}
	return 0;
}
```



#### 扫描线

矩形面积并

> 洛谷P5490-输入 $n$ 和矩形左下角、右上角，输出 $n$ 矩形并集总面积

复杂度 $O(n\log n)$ ，先离散化，再线段树维护

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 300010
unordered_map<ll, ll> h;
struct scline
{
    ll x, ay, by, c;
    bool operator<(const scline &p) const { return x < p.x; }
} sc[mn];
ll ax, ay, bx, by, n, xs[mn], xss, c[mn << 2], lp[mn << 2], rp[mn << 2], v[mn << 2], lf, rf, k, ans;
#define lfs h << 1
#define rfs h << 1 | 1
#define mkcf ll cf = (lf + rf) >> 1
void init(ll lf, ll rf, ll h)
{
    lp[h] = lf, rp[h] = rf;
    if (lf != rf)
    {
        mkcf;
        init(lf, cf, lfs);
        init(cf + 1, rf, rfs);
    }
}
void add(ll h)
{
    if (rf < lp[h] || lf > rp[h])
        return;
    if (lf <= lp[h] && rp[h] <= rf)
        c[h] += k;
    else
        add(lfs), add(rfs);
    if (c[h])
        v[h] = xs[rp[h] + 1] - xs[lp[h]];
    else
        v[h] = v[lfs] + v[rfs];
}
signed main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lld%lld%lld%lld", &ax, &ay, &bx, &by);
        sc[i] = {ax, ay, by, 1};
        sc[i + n] = {bx, ay, by, -1};
        xs[++xss] = by;
        xs[++xss] = ay;
    }
    n <<= 1;
    sort(sc + 1, sc + 1 + n);
    sort(xs + 1, xs + 1 + n);
    xss = unique(xs + 1, xs + 1 + n) - xs - 1;
    for (ll i = 1; i <= xss; ++i)
        h[xs[i]] = i;
    init(1, n, 1);
    for (ll i = 1; i < n; ++i)
    {
        lf = h[sc[i].ay], rf = h[sc[i].by] - 1, k = sc[i].c;
        add(1);
        ans += v[1] * (sc[i + 1].x - sc[i].x);
    }
    printf("%lld", ans);
    return 0;
}
```



矩形周长并 (洛谷P1856)

```c++
#include <bits/stdc++.h>
#define mn 10002
using namespace std;
typedef long long ll;
ll n,ax,ay,bx,by,xs[mn],m,bf,ans;
struct scline
{
    ll y,ax,bx,c;
    bool inline operator < (const scline& b) const
    {
        if(y==b.y) return c>b.c;
        return y<b.y;
    }
} sc[mn];
struct segtr
{
    ll c,s,l,r,len;
    bool lc,rc;
} t[mn<<2];
#define lfi (i<<1)
#define rfi (i<<1|1)
void init(ll i, ll lf, ll rf)
{
    t[i].l=lf,t[i].r=rf;
    if(lf!=rf)
    {
        ll cf=lf+rf>>1;
        init(lfi,lf,cf);
        init(rfi,cf+1,rf);
    }
}
void pushup(ll i)
{
    ll l=t[i].l,r=t[i].r;
    if(t[i].s)
    {
        t[i].len=xs[r+1]-xs[l];
        t[i].lc=t[i].rc=true;
        t[i].c=1;
        return;
    }
    t[i].len=t[lfi].len+t[rfi].len;
    t[i].lc=t[lfi].lc,t[i].rc=t[rfi].rc;
    t[i].c=t[lfi].c+t[rfi].c;
    if(t[lfi].rc&&t[rfi].lc) t[i].c--;
}
void add(ll i, ll lf, ll rf, ll ci)
{
    ll lt=xs[t[i].l],rt=xs[t[i].r+1];
    if(lt>=rf||rt<=lf) return;
    if(lt>=lf&&rt<=rf)
    {
        t[i].s+=ci;
        pushup(i);
        return;
    }
    add(lfi,lf,rf,ci);
    add(rfi,lf,rf,ci);
    pushup(i);
}
signed main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;++i)
    {
        scanf("%lld%lld%lld%lld",&ax,&ay,&bx,&by);
        sc[i]={ay,ax,bx,1};
        sc[i+n]={by,ax,bx,-1};
        xs[i]=ax;
        xs[i+n]=bx;
    }
    n<<=1;
    sort(sc+1,sc+1+n);
    sort(xs+1,xs+1+n);
    m=unique(xs+1,xs+1+n)-xs-1;
    init(1,1,m-1);
    for(ll i=1;i<n;++i)
    {
        add(1,sc[i].ax,sc[i].bx,sc[i].c);
        ans+=abs(bf-t[1].len); bf=t[1].len;
        ans+=2*t[1].c*(sc[i+1].y-sc[i].y);
    }
    printf("%lld",ans+sc[n].bx-sc[n].ax);
    return 0;
}
```



#### 杂项

##### Pick定理

顶点为整点的简单多边形，面积 $A$ ，内部格点数目 $i$ ，边上格点数目 $b$ 满足：$A=i+\dfrac b2-1$ ，其中 $1$ 是多边形的欧拉特征数。

边上格点数目，对于每一条边，其贡献量为：$\gcd(\Delta x,\Delta y)$ (闭环之后刚好每个顶点都被算了一次，所以不需要额外 $+1$ ，单边时就需要)，于是可以根据公式求出 $i$ 

> 如果是平行四边形格点，同上；如果是三角形格点， $A=2i+b-2$ ；高维推广 Ehrhart 多项式

欧拉公式：$V-E+F=2$ ，$V,E,F$ 是简单几何体顶点数、边数、面数

> POJ1265-有多组测试，每组测试 $n(3\le n\le100)$ 个点，接下来输入若干坐标偏量，代表当前点离上一个点的坐标位移。求这个多边形的内部包含格点整点数、边上包含的格点整点数和多边形面积

```c++
#include <cstdio>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 200
ll t, n, x[mn], y[mn], s, edge, kase;
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}
ll abs(ll x)
{
    return x < 0 ? -x : x;
}
signed main()
{
    for (sc(t); t--;)
    {
        sc(n);
        s = edge = 0;
        for (ll i = 1, dx, dy; i <= n; ++i)
        {
            sc(dx), sc(dy);
            x[i] = x[i - 1] + dx, y[i] = y[i - 1] + dy;
            edge += gcd(abs(dx), abs(dy));
        }
        x[n + 1] = x[1], y[n + 1] = y[1];
        for (ll i = 1, dx, dy; i <= n; ++i)
        {
            s += x[i] * y[i + 1] - x[i + 1] * y[i];
        }
        s = abs(s);
        printf("Scenario #%lld:\n%lld %lld %.1f\n\n", ++kase, (s - edge + 2) / 2, edge, s * 0.5f);
    }
    return 0;
}
```



##### 平面最近点对

(洛谷P7883) 归并排序复杂度 $O(n\log n)$ ，若快排复杂度 $O(n\log^2n)$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 400010
ll n, ans = 1e18;
struct node
{
    ll x, y;
    bool operator<(const node &r) const { return x < r.x; }
} p[mn];
void solve(ll lc, ll rc)
{
    if (lc == rc)
    {
        return;
    }
    ll cc = (lc + rc) >> 1;
    ll cx = p[cc].x; //修改前的
    solve(lc, cc), solve(cc + 1, rc);
    inplace_merge(p + lc, p + cc + 1, p + rc + 1, [](const node &x, const node &y)
                  { return x.y < y.y; });
    vector<node> v;
    for (ll i = lc; i <= rc; ++i)
    {
        if ((cx - p[i].x) * (cx - p[i].x) <= ans)
        {
            v.emplace_back(p[i]);
        }
    }
    for (auto lf = v.begin(), rf = lf; lf != v.end(); lf++)
    {
        double sans = sqrt(ans);
        while (rf != v.end() && rf->y <= lf->y + sans)
        {
            ++rf;
        }
        for (auto i = lf + 1; i != rf; ++i)
        {
            ans = min(ans, (lf->x - i->x) * (lf->x - i->x) + (lf->y - i->y) * (lf->y - i->y));
        }
    }
}
signed main()
{
    sc(n);
    for (ll i = 1; i <= n; ++i)
    {
        sc(p[i].x), sc(p[i].y);
    }
    sort(p + 1, p + 1 + n);
    solve(1, n);
    printf("%lld", ans);
    return 0;
}
```

> 拓展-洛谷P4423-求平面周长最小三角形(含共线三点)

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define sc(x) scanf("%lld", &x)
#define mn 200010
ll n;
db ans = 1e21;
struct node
{
    ll x, y;
    bool operator<(const node &r) const { return x < r.x; }
} p[mn];
db dis(const node &a, const node &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
db tri(const node &a, const node &b, const node &c)
{
    return dis(a, b) + dis(b, c) + dis(c, a);
}
void solve(ll lc, ll rc)
{
    if (lc == rc)
        return;
    ll cc = (lc + rc) >> 1;
    ll cx = p[cc].x; //修改前的
    solve(lc, cc), solve(cc + 1, rc);
    inplace_merge(p + lc, p + cc + 1, p + rc + 1, [](const node &x, const node &y)
                  { return x.y < y.y; });
    vector<node> v;
    for (ll i = lc; i <= rc; ++i)
        if (abs(cx - p[i].x) < ans / 2)
            v.emplace_back(p[i]);
    for (auto lf = v.begin(), rf = lf; lf != v.end(); lf++)
    {
        while (rf != v.end() && abs(rf->y - lf->y) < ans / 2)
            ++rf;
        for (auto i = lf + 1; i != rf; ++i)
            for (auto j = lf + 1; j != i; ++j)
                ans = min(ans, tri(*lf, *i, *j));
    }
}
signed main()
{
    sc(n);
    for (ll i = 1; i <= n; ++i)
        sc(p[i].x), sc(p[i].y);
    sort(p + 1, p + 1 + n);
    solve(1, n);
    printf("%lf", ans);
    return 0;
}
```



##### 随机增量法

洛谷P1742-最小圆覆盖(求圆的半径和坐标，使得圆覆盖 $n$ 个给定点) $O(n)$ 

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define mn 100010
#define cp const point &
ll n;
struct point
{
    db x = 0, y = 0;
    point(db a = 0, db b = 0) : x(a), y(b) {}
    point operator+(cp r) const { return point(x + r.x, y + r.y); }
    point operator-(cp r) const { return point(x - r.x, y - r.y); }
    point operator*(const db r) const { return point(x * r, y * r); }
    point operator/(const db r) const { return point(x / r, y / r); }
    db norm() const { return x * x + y * y; }
    point rotate() const { return point(y, -x); } //顺90
} p[mn], o;
db r2; // r*r
db cross(cp a, cp b) { return a.x * b.y - a.y * b.x; }
point intersect(cp p0, cp v0, cp p1, cp v1)
{
    return p0 + v0 * (cross(p1 - p0, v1) / cross(v0, v1));
}
void solve(cp a, cp b, cp c)
{
    o = intersect((a + b) / 2, (a - b).rotate(), (a + c) / 2, (a - c).rotate());
    r2 = (a - o).norm();
}
signed main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    random_shuffle(p + 1, p + 1 + n);
    for (ll i = 1; i <= n; ++i)
    {
        if ((p[i] - o).norm() > r2)
        {
            o = p[i], r2 = 0;
            for (ll j = 1; j < i; ++j)
            {
                if ((p[j] - o).norm() > r2)
                {
                    o = (p[i] + p[j]) / 2, r2 = ((p[i] - p[j]) / 2).norm();
                    for (ll k = 1; k < j; ++k)
                    {
                        if ((p[k] - o).norm() > r2)
                        {
                            solve(p[i], p[j], p[k]);
                        }
                    }
                }
            }
        }
    }
    printf("%.12lf\n%.12lf %.12lf", sqrt(r2), o.x, o.y);
    return 0;
}
```

### 立体几何

直线参数方程：$A+t\vec{AB}$

点 $P(x,y,z)$ 到直线 $A(x_0,y_0,z_0)+t(a,b,c)$ 的距离 $\dfrac{|\vec{PA} \times (a,b,c)|}{\sqrt{a^2+b^2+c^2}}$ (四边形面积(叉乘)=底($AB$ 长度)乘以高(距离)) 

直线夹角 $\cos\varphi=\dfrac{|m_1m_2+n_1n_2+p_1p_2|}{\sqrt{m_1^2+n_1^2+p_1^2}\sqrt{m_2^2+n_2^2+p_2^2}}$

直线垂直：$m_1m_2+n_1n_2+p_1p_2=0$ 

空间向量的叉乘：

$$
\vec a\times\vec b=\left|\matrix{\vec i&\vec j&\vec k\\a_x&a_y&a_z\\b_x&b_y&b_z}\right|=(a_zb_x-a_xb_z)\vec i+(a_xb_y-a_yb_x)\vec j+(a_yb_z-a_zb_y)\vec k
$$

> 叉乘绝对值：$\vec i,\vec j,\vec k$ 的系数平方和开根。

直线平行：$a_zb_x-a_xb_z=a_xb_y-a_yb_x=a_yb_z-a_zb_y=0$ 等价于 $\dfrac{x_1}{x_2}=\dfrac{y_1}{y_2}=\dfrac{z_1}{z_2}$ 



求过不共线三点 $A,B,C$ 的平面 $ax+by+cz+d=0$

- 求 $\vec{AB},\vec{AC}$，求出法向量为 $\vec{n} =\vec{AB}\times\vec{AC}=(a,b,c)$

- 法向量垂直平面任一点 $P(x,y,z)$，设存在投影点 $P_0(x_0,y_0,z_0)$ 在平面内，则与其点积为 $\vec n\cdot\vec{PP_0}=0$，即 $a(x-x_0)+b(y-y_0)+c(z-z_0)$

  用 $A,B,C$ 任一取代 $P_0$，求出 $d=-(ax_0+by_0+cz_0)$

直线 $(n,m,p)$ 与平面的夹角正弦值 $\sin\varphi=\dfrac{|am+bn+cp|}{\sqrt{a^2+b^2+c^2}\sqrt{m^2+n^2+p^2}}$

直线与平面平行 $am+bn+cp=0$，垂直 $\dfrac am=\dfrac bn=\dfrac cp$

点到平面距离公式：$d=\dfrac{|Ax+By+Cz+D|}{\sqrt{A^2+B^2+C^2}}$



> 球面一般方程：$x^2+y^2+z^2+Ax+By+Cz+D=0$ 若$A^2+B^2+C^2-4D>0$，是球面
>
> 圆锥面方程：$z^2=k^2(x^2+y^2)$ , $z=\pm k\sqrt{x^2+y^2}$
>
> 椭球面方程： $\frac{x^2}{a^2}+\frac{y^2}{b^2}+\frac{z^2}{c^2}=1$
>
> 单叶双曲面(沿着 $z$ 延展的曲线)方程： $\frac{x^2}{a^2}+\frac{y^2}{b^2}-\frac{z^2}{c^2}=1$ ，双叶： $\frac{x^2}{a^2}+\frac{y^2}{b^2}-\frac{z^2}{c^2}=-1$
>
> 抛物面(沿着 $z$ 正向)方程： $\frac{x^2}p+\frac{y^2}q=2z$ 
>
> 双曲面方程： $\frac{x^2}p-\frac{y^2}q=2z$

### 博弈论

P-position: (p:previous) 先手必败,  N-position: (n:next) 先手必胜

局面的性质：(总结：只要能移动到 $P$ 就是 $N$ ，否则都是 $P$ )

1. 合法操作集合为空的局面是P-position
2. 可以移动到P-position的局面是N-position
3. 所有移动都只能到N-position的局面是P-position

mex 函数：最小不属于某集合的非负整数 $mex(A)=\min\{k|k\in\complement_NA\}$

SG 函数：所有后继中都未出现的最小值 $sg(x)=mex\{sg(y)|y为x的直接儿子\}$

> 输出任意先手必胜方案： 找最大 sg 将它变成剩余的 sg 和，可证一定能找到

顶点 $x$ 所代表的局面是 P-position 当且仅当 $sg(x)=0$

**SG定理**：由 n 个有向图组成的ICG，设它们的起点分别为 $s_1,s_2,\dots,s_n$ ，当且仅当 $SG(s_1)\oplus SG(s_2)\oplus\dots\oplus SG(s_1)\ne0$ 时，这个游戏先手必胜

经典博弈：

- **巴什博奕** 有 n 个物品，两人轮流取物，每次至少取一个，最多取 m 个，最后取完者胜

  先手必败条件： $n\bmod (m+1)=0$

- **Nim游戏** (所有ICG游戏都可以转化为Nim游戏求解) 有 n 堆数，每堆有 $s_i$ 个，每次可以从任意堆里取 1 到任意多个数

  先手必败条件： $\oplus_{i=1}^ns_i=0$

  先手必胜方案输出：当前异或和 $x\neq0$ 时，$O(\log a)$ 找 $b_i\oplus x < b_i$ ，将 $b_i$ 更改为 $b_i\oplus x$ ；否则任取完一堆；回合数可以不超 $2n$ (SCNUOJ1701)

- **威佐夫博弈**  有两堆物品，轮流从一堆拿任意个或同时从两堆拿同样的任意个，取完者胜

  先手必败条件为 $(b,a),a > b, b=\lfloor\dfrac{1+\sqrt5}2\times(a-b)\rfloor$

- **斐波那契博弈** 一堆物品，先手最少取一个且不能取完，之后每次取不能少于1或超过上次的二倍，取完者胜

  先手必败条件： 物品是斐波那契数列

在普通SG游戏的基础上，新增一条规则：每次行动，每个可以移动的SG游戏都要移动，是Every-SG游戏

> 例如棋盘上有n个棋子在不同的位置，双方每次行动都要将每一个可以移动的棋子按规则移动，这就是典型的Every-SG游戏。

$$
step(v)=\begin{cases}
0,&v为终止状态\\
\max(step(u))+1,&sg(v)>0,sg(u)=0\\
\min(step(u))+1,&sg(v)=0
\end{cases}
$$


定理：Every-SG游戏先手必胜当且仅当单一游戏中最大的 step 为奇数



### 多项式

> 一个多项式全家桶模板见上文公式-组合数学-球盒问题。

#### FFT

系数表示法：$F(x)=y=\sum_{i=0}^na_ix^i$，其中$\{a_i\}$是每一项的系数。

点值表示法：$F(x)$可以被n个点$(x_i,f(x_i))$唯一确定

两多项式相乘即求卷积： $f(x)\times g(x)={(x_i,f(x_i)\times g(x_i))}$ ，点值表示法下 $O(n)$

将系数表示法转点值表示法为快速傅里叶变换(FFT), 点值转系数为IFFT , 均 $O(n\log n)$

> 洛谷P3803-输入 $n,m$ 和 $n$ 次多项式 $F(x)$ , $m$ 次多项式 $G(x)$ , 求 $F(x)\cdot G(x)$ , 系数都是个位数

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define mn ((1 << 21) + 1)
ll n1, n2, rev[mn], ans[mn], k, s = 1, len, n;
db pi = acos(-1), v;
typedef complex<db> cp;
cp a[mn], b[mn];
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
#pragma GCC diagnostic ignored "-Wformat" //忽略db转complex警告
signed main()
{
    scanf("%lld%lld", &n1, &n2), n = n1 + n2;
    for (ll i = 0; i <= n1; ++i)
    {
        scanf("%lf", a + i);
    }
    for (ll i = 0; i <= n2; ++i)
    {
        scanf("%lf", b + i);
    }
    while (s <= n)
    {
        s <<= 1, ++k;
    }
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
    for (ll i = 0; i <= n; ++i)
    {
        printf("%lld ", (ll)(a[i].real() + 0.5));
    }
    return 0;
}
```



#### NTT

快速数论变换，FNTT，简称为NTT number theory transform

FFT 在模意义下的一种实现，功能上与 FFT 类似。FFT 的计算量大且存在浮点误差。

欧拉定理：$a\in Z,m\in N^*$，若 $(a,m)=1$，则 $a^{\varphi(m)}\equiv 1\bmod m$

阶：满足 $a^n\equiv1\bmod m$ 的最小正整数 $n$，记作 $\delta_m(a)$

原根：$m\in N_+,a\in Z$，若 $(a,m)=1,\delta_m(a)=\varphi(m)$，则 $a$ 是模 $m$ 的原根

$998244353$ 的原根是 $3$，$10^9+7$ 不能做 NTT(MTT 考虑 P4245)

> 洛谷P3803

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
const ll mn = 3e6 + 10, p = 998244353, g = 3, gi = 332748118;
ll n, m, lim = 1, l, r[mn], a[mn], b[mn]; // 2^l=lim
ll qpow(ll a, ll b)
{
    ll r = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
        {
            r = r * a % p;
        }
        a = a * a % p;
    }
    return r;
}
void ntt(ll *a, ll type)
{
    for (ll i = 0; i < lim; ++i)
    {
        if (i < r[i])
        {
            swap(a[i], a[r[i]]);
        }
    }
    for (ll mid = 1; mid < lim; mid <<= 1)
    {
        ll wn = qpow(type == 1 ? g : gi, (p - 1) / (mid << 1));
        for (ll j = 0; j < lim; j += (mid << 1))
        {
            ll w = 1;
            for (ll k = 0; k < mid; ++k, w = w * wn % p)
            {
                ll x = a[j + k], y = w * a[j + k + mid] % p;
                a[j + k] = (x + y) % p;
                a[j + k + mid] = (x - y + p) % p;
            }
        }
    }
}
signed main()
{
    sc(n), sc(m);
    for (ll i = 0; i <= n; ++i)
    {
        sc(a[i]);
    }
    for (ll i = 0; i <= m; ++i)
    {
        sc(b[i]);
    }
    while (lim <= n + m)
    {
        ++l, lim <<= 1;
    }
    for (ll i = 0; i < lim; ++i)
    {
        r[i] = (r[i >> 1] >> 1 | ((i & 1) << (l - 1)));
    }
    ntt(a, 1), ntt(b, 1);
    for (ll i = 0; i < lim; ++i)
    {
        a[i] = a[i] * b[i] % p;
    }
    ntt(a, -1);
    ll inv = qpow(lim, p - 2);
    for (ll i = 0; i <= n + m; ++i)
    {
        printf("%lld ", a[i] * inv % p);
    }
    return 0;
}
```



#### 分治 FFT

> SCNUOJ1806-求 $\prod_{i=1}^n(1+a_ix)$ 的 $x^k$ 系数对 $998244353$ 取模，$1\le k\le n\le10^5,1\le a_i\le10^9$

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const ll mod = 998244353;

ll qui(ll a, ll x)
{
    ll ret = 1;
    while (x)
    {
        if (x & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return ret;
}

using Poly = vector<ll>;
const int BIT = 20;
int p[1 << BIT];
const ll maxn = 1e5 + 10;
ll fac[maxn], inv[maxn];

Poly operator*(const Poly &a, const Poly &b)
{
    int n = a.size() - 1, m = b.size() - 1;
    int L, l = 0;
    for (L = 1; L <= n + m; l++, L = L << 1)
        ;

    vector<int> p(L);

    for (int i = 1; i < L; i++)
        p[i] = ((p[i >> 1] >> 1) | ((i & 1) << (l - 1)));
    auto u = a, v = b;
    u.resize(L, 0), v.resize(L, 0);
    auto ntt = [&L, &l, &p](Poly &g, int type)
    {
        for (int i = 0; i < L; i++)
            if (i < p[i])
                swap(g[i], g[p[i]]);
        for (int i = 1; i < L; (i <<= 1))
        {
            ll wn = qui(3, (mod - 1) / (i << 1));
            for (int j = 0; j < L; j += (i << 1))
            {
                ll w = 1;
                for (int k = j; k < j + i; w = w * wn % mod, k++)
                {
                    assert(k + i < L);
                    assert(k < L);
                    ll t = g[k + i] * w % mod;
                    g[k + i] = (g[k] - t + mod) % mod;
                    g[k] = (g[k] + t) % mod;
                }
            }
        }
        if (type == 1)
            return;
        reverse(g.begin() + 1, g.begin() + L);
        ll ni = qui(L, mod - 2);
        for (int i = 0; i < L; i++)
            g[i] = g[i] * ni % mod;
    };
    ntt(u, 1), ntt(v, 1);

    Poly g(L, 0);
    for (int i = 0; i < L; i++)
        g[i] = u[i] * v[i] % mod;
    ntt(g, -1);

    return g;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    function<Poly(int, int)> calc = [&](int l, int r)
    {
        if (l >= r)
        {
            assert(l == r);
            return Poly{1, b[l]};
        }
        int mid = (l + r) / 2;
        return calc(l, mid) * calc(mid + 1, r);
    };

    Poly ep = calc(0, n);
    cout << ep[k];
    return 0;
}
```

#### FWT

快速沃尔什变换。求 $C_i=\sum_{i=j\oplus k}A_jB_k$，其中 $\oplus$ 是与/或/异或/同或。复杂度与 FFT 看齐。

> 模板题 P4717-给定长为 $2^n(n\le 17)$ 的序列，分别求对或/与/异或后的序列，对 $P=998244353$ 取模

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll P = 998244353;
ll qpow(ll a, ll b = P - 2)
{
    ll r = 1;
    for (; b; b >>= 1, a = a * a % P)
        if (b & 1)
            r = r * a % P;
    return r;
}
struct modint
{
    ll v;
    modint(ll v_ = 0) : v(v_) {}
    modint operator+(const modint &o) const { return modint((v + o.v) % P); }
    modint operator-(const modint &o) const { return modint((v - o.v + P) % P); }
    modint operator*(const modint &o) const { return modint(v * o.v % P); }
    modint operator/(const modint &o) const { return modint(v * qpow(o.v) % P); }
    modint operator+=(const modint &o) { return *this = *this + o; }
    modint operator-=(const modint &o) { return *this = *this - o; }
    modint operator*=(const modint &o) { return *this = *this * o; }
    modint operator/=(const modint &o) { return *this = *this / o; }
};
#define rd(x) scanf("%d", &x)
const int N = 1 << 17 | 1;
int n, m;
modint A[N], B[N], a[N], b[N];

inline void in()
{
    for (int i = 0; i < n; i++)
        a[i] = A[i], b[i] = B[i];
}

inline void get()
{
    for (int i = 0; i < n; i++)
        a[i] *= b[i];
}

inline void out()
{
    for (int i = 0; i < n; i++)
        printf("%d%c", a[i], " \n"[i == n - 1]);
}

inline void OR(modint *f, modint x = 1)
{
    for (int o = 2, k = 1; o <= n; o <<= 1, k <<= 1)
        for (int i = 0; i < n; i += o)
            for (int j = 0; j < k; j++)
                f[i + j + k] += f[i + j] * x;
}

inline void AND(modint *f, modint x = 1)
{
    for (int o = 2, k = 1; o <= n; o <<= 1, k <<= 1)
        for (int i = 0; i < n; i += o)
            for (int j = 0; j < k; j++)
                f[i + j] += f[i + j + k] * x;
}

inline void XOR(modint *f, modint x = 1)
{
    for (int o = 2, k = 1; o <= n; o <<= 1, k <<= 1)
        for (int i = 0; i < n; i += o)
            for (int j = 0; j < k; j++)
            {
                f[i + j] += f[i + j + k];
                f[i + j + k] = f[i + j] - f[i + j + k] - f[i + j + k];
                f[i + j] *= x, f[i + j + k] *= x;
            }
}

int main()
{
    rd(m), n = 1 << m;
    for (int i = 0; i < n; i++)
        rd(A[i]);
    for (int i = 0; i < n; i++)
        rd(B[i]);
    in(), OR(a), OR(b), get(), OR(a, P - 1), out();
    in(), AND(a), AND(b), get(), AND(a, P - 1), out();
    in(), XOR(a), XOR(b), get(), XOR(a, (modint)1 / 2), out();
    return 0;
}
```



> lc982-给定整数数组 $a,|a|\le10^3,0\le a_i<2^{16}$，求 $a_i\&a_j\&a_k=0$ 的三元对的数目($i,j,k$ 可以取等)

设桶数组 $a$，即求 $\sum_{i\&j\&k=0}a_ia_ja_k=\sum_{i\&p=0}a_i\sum_{j\&k=p}a_ja_k$，即先对 $a$ 做 FWT，然后算 $fwt(b)=fwt(a)^3$，再逆运算得到 $b_0$ 作为答案。

```c++
#include <bits/stdc++.h>
using namespace std;
int w;
int B[1 << 16];
void FWTand(int *a, int opt)
{
    int N = 1 << w;
    for (int mid = 1; mid < N; mid <<= 1)
        for (int R = mid << 1, j = 0; j < N; j += R)
            for (int k = 0; k < mid; k++)
                if (opt == 1)
                    a[j + k] += a[j + k + mid];
                else
                    a[j + k] -= a[j + k + mid];
}
int countTriplets(vector<int> &A)
{
    for (auto a : A)
    {
        B[a]++;
        while ((1 << w) <= a)
            w++;
    }
    FWTand(B, 1);
    for (int i = 0; i < (1 << w); i++)
        B[i] *= B[i] * B[i];
    FWTand(B, -1);
    return B[0];
}
```





#### 拉格朗日插值法

> 洛谷P4781-给定由 n 个点确定的多项式 $f(x)$，求 $f(k)\bmod998244353$ , $x_i$ 各异

复杂度为 $O(n^2)$ ，比高斯消元快 (但高斯消元对给出点坐标无要求) (若 $x_i=i$ 可以朴素 $O(n^2)$ 差分)
$$
f(k)=\sum_{i=0}^ny_i\prod_{i\neq j}\frac{k-x_j}{x_i-x_j}
$$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 2002
#define MOD 998244353
ll n, k, x[MAXN], y[MAXN], ans, s1, s2;
ll qpow(ll a, ll x)
{
	ll res = 1, t = a;
	for (; x; t = t * t % MOD, x >>= 1) if (x & 1)
		res = res * t % MOD;
	return res;
}
inline ll inv(ll x) { return qpow(x, MOD - 2); }
signed main()
{
	scanf("%lld%lld", &n, &k);
	for(ll i = 1; i <= n; ++i) scanf("%lld%lld", x + i, y + i);
	for(ll i = 1; i <= n; ++i)
	{
		s1 = y[i] % MOD, s2 = 1;
		for(ll j = 1; j <= n; ++j) if (i != j)
			s1 = s1 * (k - x[j]) % MOD,
			s2 = s2 * ((x[i] - x[j] % MOD) % MOD) % MOD;
		ans += s1 * inv(s2) % MOD;
		ans = (ans + MOD) % MOD;
	}
	printf("%lld", ans);
	return 0;
}
```



### 杂项

#### 矩阵加速

常见建模：
$$
f_i=af_{i-1}+bf_{i-2}
\Rightarrow
\begin{pmatrix}
a&b\\1&0
\end{pmatrix}
\begin{pmatrix}
f_{i-1}\\f_{i-2}
\end{pmatrix}
=
\begin{pmatrix}
f_i\\f_{i-1}
\end{pmatrix}
$$

$$
f_i=af_{i-1}+b^i
\Rightarrow
\begin{pmatrix}
a&1\\0&b
\end{pmatrix}
\begin{pmatrix}
f_{i-1}\\b^{i-1}
\end{pmatrix}
=
\begin{pmatrix}
f_i\\b^i
\end{pmatrix}
$$

$$
f_i=af_{i-1}+i^3
\Rightarrow
\begin{pmatrix}
a&1&0&0&0\\
0&1&3&3&1\\
0&0&1&2&1\\
0&0&0&1&1\\
0&0&0&0&1
\end{pmatrix}
\begin{pmatrix}
f_{i-1}\\i^3\\i^2\\i\\1
\end{pmatrix}
=
\begin{pmatrix}
f_i\\(i+1)^3\\(i+1)^2\\i+1\\1
\end{pmatrix}
$$



> 矩阵前 $k$ 项和：(SCNUOI1068 / GDCPC2022K) (直接用 A.P. 的问题是不一定可逆)

已知 $n$ 阶方阵 $A$，求 $A+A^2+A^3+\cdots+A^k$。

令 $B_i=A+A^2+\cdots+A^i$，$n$ 阶单位阵为 $E$。若 $k$ 为偶数，上式可以转化为：
$$
B_k=(A+A^2+\cdots+A^{\frac k2})+A^{\frac k2}(A+A^2+\cdots+A^{\frac k2})=B_{\frac k2}+A^{\frac k2}B_{\frac k2}=(E+A^{\frac k2})B_{\frac k2}
$$
若 $k$ 为奇数，可以直接用上一个偶数，即 $B_k=B_{k-1}+A^k$。

其中，$A^i$ 可由矩阵快速幂计算，复杂度为 $O(n^3\log i)$。而 $B_k$ 的递推需要 $\log k$ 次，故总复杂度为 $O(n^3\log^2k)$。

```c++
matrix psum(ll k)
{
    if (k == 0)
        return matrix(n);
    if (k == 1)
        return *this;
    if (k % 2 == 1)
        return psum(k - 1) + pow(k);
    return (unit(n) + this->pow(k / 2)) * psum(k / 2);
}
```



#### 高斯消元

优化的Gauss-Jordan消元法，复杂度 $O(n^3)$ 

> 洛谷P3389-求实数线性方程组的唯一解或 `No solution` ，值域 $|a|\le10^4$ 

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define limn 102
db a[limn][limn];
ll n;
signed main()
{
	scanf("%d", &n);
	repe(i, 1, n) repe(j, 1, n + 1) scanf("%lf", &a[i][j]);
	repe(i, 1, n)
	{
		ll mx = i;
		repe(j, i + 1, n) if (fabs(a[j][i]) > fabs(a[mx][i])) mx = j;
		repe(j, 1, n + 1) swap(a[i][j], a[mx][j]);
		if (!a[i][i]) return !printf("No Solution");
		repe(j, 1, n) if(j!=i)
		{
			db tmp = a[j][i] / a[i][i];
			repe(k, i + 1, n + 1) a[j][k] -= a[i][k] * tmp;
		}
	}
	repe(i, 1, n) printf("%.2lf\n", a[i][n + 1] / a[i][i]);
	return 0;
}
```

> 洛谷P4783-求逆矩阵对 $10^9+7$ 取模或输出 `No Solution`

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define MAXN 402
#define MOD 1000000007
ll n, m, f[MAXN][MAXN << 1], r, ret;
ll inv(ll u, ll v)
{
	for (ret = 1; v; u = u * u % MOD, v >>= 1) if (v & 1)
		ret = ret * u % MOD;
	return ret;
}
signed main()
{
	scanf("%lld", &n), m = n << 1;
	repe(i, 1, n)
	{
		repe(j, 1, n) scanf("%lld", &f[i][j]);
		f[i][n + i] = 1;
	}
	repe(i, 1, n)
	{
		repe(j, i, n) if (f[j][i])
		{
			repe(k, 1, m) swap(f[i][k], f[j][k]);
			break;
		}
		if (!f[i][i]) return !printf("No Solution");
		r = inv(f[i][i], MOD - 2);
		repe(j, i, m) f[i][j] = f[i][j] * r % MOD;
		repe(j,1,n) if (j != i)
		{
			r = f[j][i];
			repe(k, i, m) f[j][k] = (f[j][k] - r * f[i][k] % MOD + MOD) % MOD;
		}
	}
	repe(i, 1, n)
	{
		repe(j, n + 1, m) printf("%lld ", f[i][j]);
		printf("\n");
	}
	return 0;
}
```







#### 康托展开

树状数组优化后 $O(n\log n)$ 求 $[1,n]$ 的任意排列的排名(字典序排序序号)，公式：
$$
1+\sum_{i=1}^n(n-i)!\times(\sum_{j=i}^n[a[j]<a[i]])
$$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 10000002
#define MOD 998244353
ll a, c[MAXN], f[MAXN], ans, v, n, lb[MAXN], k;
ll sum(ll p)
{
	ll res = 0;
	while (p) res += c[p], p -= lb[p];
	return res;
}
void add(ll x, ll&& k)
{
	while (x <= n) c[x] += k, x += lb[x];
}
signed main()
{
	scanf("%lld", &n);
	f[0] = 1;
	for(ll i = 1; i <= n; ++i) f[i] = f[i - 1] * i % MOD;
	for(ll i = 1; i <= n; ++i) lb[i] = i & -i;
	for(ll i = 1; i <= n; ++i) add(i, 1);
	for(ll i = 1; i <= n; ++i)
	{
		scanf("%lld", &a);
		(ans += (sum(a) - 1) * f[n - i] % MOD) %= MOD;
		add(a, -1);
	}
	printf("%lld", (++ans)%MOD);
	return 0;
}
```

逆康托展开(UVA11525)-给定每个 $\sum_{j=i}^n[a[j]<a[i]]$ ，求排列：

```c++
#include<iostream>
#include<cstdio>
#define N (500000+21)
//define一定一定要记得加括号
using namespace std;
struct SegmentTree{int l,r,cnt;}t[N*4];//线段树数组要开四倍
int T,n,x;
//下面是线段树模板，基本和区间加差不多，就是注意查询操作类似于平衡树找第k名
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].cnt=1;
		return;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p].cnt=t[p*2].cnt+t[p*2+1].cnt;
}
int modify(int p,int v){
	if(t[p].l==t[p].r){
		t[p].cnt=0;//这里随着查询也改变了数值
		return t[p].l;
	}
	int res=0;
	if(v<=t[p*2].cnt) res=modify(p*2,v);
	else res=modify(p*2+1,v-t[p*2].cnt);
	t[p].cnt=t[p*2].cnt+t[p*2+1].cnt;
	return res;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		build(1,1,n);
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			printf("%d",modify(1,x+1));//因为从0开始所以要把x加1
			if(i!=n) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
```



#### 自适应辛普森法

> 洛谷P4525-求 $\int_L^R\dfrac{cx+d}{ax+b}dx$ ，输入 $a,b,c,d,L,R$

$$
\int_a^bf(x)dx\approx\dfrac{(b-a)(f(a)+f(b)+4f(\dfrac{a+b}2))}6
$$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
#define sc(x) scanf("%lf", &x)
db a, b, c, d, l, r, eps = 1e-8; // eps可以比题目要求的细一两位
db f(db x)                       //这里根据题目不同输写不同的f
{
    return (c * x + d) / (a * x + b);
}
db simpson(db lf, db rf)
{
    return (rf - lf) * (f(lf) + f(rf) + 4 * f((lf + rf) / 2)) / 6;
}
db solve(db lf, db rf, db now) //当前区间估计值为now
{
    db cf = (lf + rf) / 2;
    db lfans = simpson(lf, cf), rfans = simpson(cf, rf);
    if (abs(lfans + rfans - now) <= eps) //二分后也是now
    {                                    //那就不需要细分了
        return lfans + rfans;
    }
    return solve(lf, cf, lfans) + solve(cf, rf, rfans);
}
signed main()
{
    sc(a), sc(b), sc(c), sc(d), sc(l), sc(r);
    printf("%lf", solve(l, r, 0)); //估计值随便填一个值
    return 0;
}
```





## 数据结构

### ST表

以区间 gcd 为例(时间复杂没有两个 $\log$ 乘积，具体为 $O(n(\log w+\log n))$ ) 

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

笛卡尔树 LCA $\pm1$ RMQ 问题，预处理、查询复杂度是 $O(n), O(1)$ 。空间复杂度 $O(n)$ 。(以区间max为例洛谷P3865,$n\le10^5,m\le2\times10^6$ )

```c++
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int inf=1e9;
int n,m,w[2000000],lg2[1500000];
int pos[1500000],lst[1500000],dep[1500000],id,mm,S,ch[1500000][2],stack[1500000];
struct LIM_RMQ
{
	int w[1500000],bl[1500000],blo,L[150000],R[150000],pos[10000],val[150000],minn[150000],minpos[150000],t[1000],n_st;
	struct ST_node{int f,id;bool operator <(const ST_node &tmp)const{return f<tmp.f;}};
	struct STable
	{
		ST_node a[4][12];//n=1e6的话logn/2只有9...所以放心开
		void make(int w[],int n)
		{
			for(int i=1;i<=n;i++)a[0][i]=(ST_node){w[i],i};
			for(int i=1;(1<<i)<=n;i++)//st表，不过要同时处理出最小值所在的位置
				for(int j=1;j+(1<<i)-1<=n;j++)
					a[i][j]=min(a[i-1][j],a[i-1][j+(1<<(i-1))]);
		}
		ST_node query(int l,int r)
		{
			int len=lg2[r-l+1];
			return min(a[len][l],a[len][r-(1<<len)+1]);
		}
	}st[10000];//这里只有sqrt(n)个，也不用开这么大
	struct STable_block
	{
		ST_node a[20][150000];//这个占空间最大了吧...不过也只是O(n)的
		void make(int w[],int n)
		{
			for(int i=1;i<=n;i++)a[0][i]=(ST_node){w[i],i};
			for(int i=1;(1<<i)<=n;i++)
				for(int j=1;j+(1<<i)-1<=n;j++)
					a[i][j]=min(a[i-1][j],a[i-1][j+(1<<(i-1))]);
		}
		ST_node query(int l,int r)
		{
			int len=lg2[r-l+1];//细节，math库的log2函数不能看做O(1)的，要提前处理
			return min(a[len][l],a[len][r-(1<<len)+1]);
		}
	}st_block;
	void make(int a[],int n)
	{
		for(int i=1;i<=n;i++)w[i]=a[i];
		lg2[1]=0;for(int i=2;i<=n;i++)lg2[i]=lg2[i>>1]+1;//处理log2
		blo=max(lg2[n]>>1,1);//分块
		for(int i=1;i<=n;i++)bl[i]=(i-1)/blo+1;
		for(int i=1;i<=bl[n];i++)L[i]=(i-1)*blo+1,R[i]=min(i*blo,n),minn[i]=inf;
		w[0]=w[1]-1;
		for(int i=1;i<=bl[n];i++)
		{
			int tmp=0,nn=0;
			for(int j=L[i];j<=R[i];j++)
			{
				t[++nn]=w[j],tmp=tmp<<1|(w[j]-w[j-1]==1?1:0);
				if(w[j]<minn[i])minn[i]=w[j],minpos[i]=j;
                //可以用一个状压来表示本质
			}
			if(!pos[tmp])st[pos[tmp]=++n_st].make(t,nn);
			val[i]=pos[tmp];//记下每个块属于哪一个本质
		}
		st_block.make(minn,bl[n]);//块间rmq
	}
	ST_node query_block(int id,int l,int r){ST_node t=st[val[id]].query(l-L[id]+1,r-L[id]+1);return (ST_node){t.f,t.id+L[id]-1};}
    //实际位置=块左端点+块内查询位置-1，如果你把块内查询从0开始写就可以省略-1
	int query(int l,int r)
	{
		int bll=bl[l],blr=bl[r];
		if(bll==blr)return query_block(bll,l,r).id;//一个块
		int ml=query_block(bll,l,R[bll]).id,mr=query_block(blr,L[blr],r).id,mm;
		if(w[ml]<w[mr])mm=ml;else mm=mr;//两端零散块
		if(bll+1<=blr-1)//整块
		{
			int mmid=minpos[st_block.query(bll+1,blr-1).id];
			if(w[mmid]<w[mm])mm=mmid;
		}
		return mm;
	}
}a;
void dfs(int u,int depth)
{
	lst[u]=++id,pos[id]=u;dep[id]=depth;//处理欧拉序列
	for(int i=0;i<=1;i++)
		if(ch[u][i])
		{
			dfs(ch[u][i],depth+1);
			pos[++id]=u,dep[id]=depth;
		}
}
int getin()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
	return x;
}
int wt[30];
void putout(int x)
{
	if(!x){putchar('0');return;}
	int l=0;
	while(x)wt[++l]=x%10,x/=10;
	while(l)putchar(wt[l--]+48);
	puts("");
}
void build_tree()//笛卡尔树
{
	int top=1;stack[1]=S=1;//开始根为1
	for(int i=2;i<=n;i++)
	{
		int lst=0;
		while(top&&w[i]>w[stack[top]])lst=stack[top--];
		if(lst)ch[i][0]=lst;
		if(top)ch[stack[top]][1]=i;else S=i;
		stack[++top]=i;
	}
	dfs(S,1);
}
int main()
{
	n=getin(),m=getin();
	for(int i=1;i<=n;i++)w[i]=getin();
	build_tree();
	a.make(dep,id);
	for(int i=1;i<=m;i++)
	{
		int l=lst[getin()],r=lst[getin()];
		if(l>r)swap(l,r);//可能第一次出现的位置是反过来的
		putout(w[pos[a.query(l,r)]]);
	}
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

对每个节点区间：维护该区间最大值 $mx$、最大值出现次数 $cnt$ 、严格次大值 $se$ 

对操作 $1$ ：

- 若 $mx\le t$ ，整个区间都没 $t$ 大，不操作 (相等也等于没操作)
- 若 $se < t < mx$  ，那么所有最大值都变成 $t$ ，次大值和更小的值都不变，所以 $cnt$ 个 $mx$ 被删掉，再加上 $cnt$ 个 $t$ ，即区间更新 $cnt(t-mx)$ ，并记录懒标记
- 若 $t\le se$ ，递归往下处理子区间

对操作 $2,3$ ，有手就行

处理 `pushup` ：

- 若左右子区间最值一样， $cnt$ 取左右子之和， $se$ 取左右 $se$ 较大者， $mx$ 任取左右(都一样)
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

#### 动态开点

动态开点线段树模板题，强制在线维护：(lc715)

- 将区间 $[l,r)$ 的所有点染色。
- 将区间 $[l,r)$ 的所有点取消染色。
- 查询区间 $[l,r)$ 是否每个点都被染色。

其中操作数 $q=10^4$，值域 $n=10^9$。

本质：懒开点的线段树，即仍然构造值域为 $[1,n]$ 的普通线段树。但是对所有节点，只有需要访问时，才使用内存分配给该点。对大部分不需要访问的点不开内存。

点数估计：可以考虑走大约 $2q\log n$；如果 $q>n$，最坏点数约 $2n-1$。

```c++
using ll = long long;
class RangeModule
{
    constexpr static ll inf = 1e9;
    constexpr static ll maxn = 60 * 1e4; // log(inf)*q
    struct node
    {
        ll ls, rs, sum, laz;
    } t[maxn] = {};
    int cnt = 1;
#define cll const ll &
#define mkcf ll cf = (lf + rf) >> 1
    void pushdown(int r, cll lf, cll rf)
    {
        if (!t[r].ls)
            t[r].ls = ++cnt;
        if (!t[r].rs)
            t[r].rs = ++cnt;
        if (!t[r].laz)
            return;
        if (t[r].laz == 1)
        {
            mkcf;
            t[t[r].ls].sum = (cf - lf + 1); // len-len/2
            t[t[r].rs].sum = rf - cf;       // len/2
        }
        else
        {
            t[t[r].ls].sum = t[t[r].rs].sum = 0;
        }
        t[t[r].ls].laz = t[t[r].rs].laz = t[r].laz;
        t[r].laz = 0;
    }
    void pushup(int r)
    {
        t[r].sum = t[t[r].ls].sum + t[t[r].rs].sum;
    }
    void update(int r, ll lf, ll rf, cll lc, cll rc, cll v)
    {
        if (lc <= lf && rf <= rc)
        {
            t[r].sum += (v == 1) * (rf - lf + 1);
            t[r].laz = v;
            return;
        }
        pushdown(r, lf, rf);
        mkcf;
        if (lc <= cf)
            update(t[r].ls, lf, cf, lc, rc, v);
        if (rc >= cf + 1)
            update(t[r].rs, cf + 1, rf, lc, rc, v);
        pushup(r);
    }
    ll query(int r, ll lf, ll rf, cll lc, cll rc)
    {
        if (lc <= lf && rf <= rc)
            return t[r].sum;
        pushdown(r, lf, rf);
        ll res = 0;
        mkcf;
        if (lc <= cf)
            res += query(t[r].ls, lf, cf, lc, rc);
        if (rc >= cf + 1)
            res += query(t[r].rs, cf + 1, rf, lc, rc);
        return res;
    }
public:
    RangeModule() {}
    void addRange(int left, int right)
    {
        update(1, 1, inf, left, right - 1, 1);
    }
    bool queryRange(int left, int right)
    {
        return query(1, 1, inf, left, right - 1) == right - left;
    }
    void removeRange(int left, int right)
    {
        update(1, 1, inf, left, right - 1, -1);
    }
};
```



#### zkw线段树

##### 单点修改

单点增加修改，区间求和模板(洛谷P3374)

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 500010
ll t[mn << 2], n, N, m, c, x, y;
signed main()
{
    sc(n), sc(m);
    for (N = 1; N <= n + 1; N <<= 1)
        ;
    for (ll i = N + 1; i <= N + n; ++i)
    {
        sc(t[i]);
    }
    for (ll i = N - 1; i >= 1; --i)
    {
        t[i] = t[i << 1] + t[i << 1 | 1];
    }
    while (m--)
    {
        sc(c), sc(x), sc(y);
        if (c == 1)
        {
            for (ll i = x + N; i; i >>= 1)
            {
                t[i] += y;
            }
        }
        else
        {
            ll ans = 0;
            for (ll s = N + x - 1, r = N + y + 1; s ^ r ^ 1; s >>= 1, r >>= 1)
            {
                if (~s & 1)
                {
                    ans += t[s ^ 1];
                }
                if (r & 1)
                {
                    ans += t[r ^ 1];
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
```

##### 区间修改

区间增加修改，区间求和模板 (洛谷P3372)

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 400010
#define sc(x) scanf("%lld", &x)
ll n, m, a[mn], dt, laz[mn], c, x, y, k;
signed main()
{
    sc(n), sc(m);
    for (dt = 1; dt <= n + 1; dt <<= 1)
        ;
    for (ll i = dt + 1; i <= dt + n; ++i)
    {
        sc(a[i]);
    }
    for (ll i = dt - 1; i >= 1; --i)
    {
        a[i] = a[i << 1] + a[i << 1 | 1];
    }
    while (m--)
    {
        sc(c), sc(x), sc(y);
        if (c == 1)
        {
            sc(k);
            ll lf = 0, rf = 0, layer = 1, s = dt + x - 1, t = dt + y + 1;
            for (; s ^ t ^ 1; s >>= 1, t >>= 1, layer <<= 1)
            {
                a[s] += k * lf, a[t] += k * rf;
                if (~s & 1)
                {
                    laz[s ^ 1] += k, a[s ^ 1] += k * layer, lf += layer;
                }
                if (t & 1)
                {
                    laz[t ^ 1] += k, a[t ^ 1] += k * layer, rf += layer;
                }
            }
            for (; s; s >>= 1, t >>= 1)
            {
                a[s] += k * lf, a[t] += k * rf;
            }
        }
        else
        {
            ll lf = 0, rf = 0, layer = 1, s = dt + x - 1, t = dt + y + 1;
            ll ans = 0;
            for (; s ^ t ^ 1; s >>= 1, t >>= 1, layer <<= 1)
            {
                if (laz[s])
                {
                    ans += laz[s] * lf;
                }
                if (laz[t])
                {
                    ans += laz[t] * rf;
                }
                if (~s & 1)
                {
                    ans += a[s ^ 1], lf += layer;
                }
                if (t & 1)
                {
                    ans += a[t ^ 1], rf += layer;
                }
            }
            for (; s; s >>= 1, t >>= 1)
            {
                ans += laz[s] * lf + laz[t] * rf;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
```

#### 树上二分

对单调问题，$O(\log n)$ 单次查询出固定左/右端点下，最长的右端点/左端点，区间内满足性质。

> 2023GDCPC-F 给定长为 $n(\le 10^5)$ 的序列，有颜色 $c_i(1\le c_i\le n)$ 和值 $v_i(1\le v_i\le 10^9)$，$q(\le 10^5)$ 次询问，时限 5s，空间 1GB，要求维护：
>
> 1. `1 p x` 修改 $c_p$ 为 $x$
>
> 2. `2 p x` 修改 $v_p$ 为 $x$
>
> 3. `3 x k a_1 a_2 ... a_k` $\sum k\le 10^6$
>
>    找到包含 $x$ 的最长区间 $[l,r]$ 满足 $k$ 个颜色 $a$ 在该区间全部覆盖

求某个区间出现的颜色是否都在 $A$，即求 $A$ 所有颜色在区间出现次数之和是否等于区间长度。可以维护线段树/树状数组，每个节点保存哈希表，表示该区间出现的颜色及其次数。每个维护值重复 $\log n$  次，故空间复杂度为 $O(n\log n)$。可以考虑用 `pb_ds` un map 卡常。

二分找出从 $x$ 往左往右能到达的最大左右端点，求区间和。如果朴素二分，复杂度为 $O(\sum k \log^2 n)$，考虑使用线段树/树状数组上二分/倍增优化，为 $O(\sum k\log n)$。

线段树上二分：

```c++
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mn = 3e5 + 10, mt = mn * 4;

// 比 unordered_map 更快的哈希表
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash
{
    int operator()(int x) const { return x ^ RANDOM; }
};
typedef gp_hash_table<int, int, chash> hash_t;

ll s[mt];
hash_t h[mt];
#define lfs p << 1
#define rfs p << 1 | 1
#define mkcf ll cf = (lf + rf) >> 1
#define ci const int &
void modifyS(int p, int lf, int rf, ci pos, ci v)
{
    if (lf == rf)
    {
        s[p] += v;
        return;
    }
    mkcf;
    if (pos <= cf)
    {
        modifyS(lfs, lf, cf, pos, v);
    }
    else
    {
        modifyS(rfs, cf + 1, rf, pos, v);
    }
    s[p] = s[lfs] + s[rfs];
}
ll queryS(int p, int lf, int rf, ci lc, ci rc)
{
    if (lc <= lf && rf <= rc)
    {
        return s[p];
    }
    mkcf;
    ll ans = 0;
    if (lc <= cf)
    {
        ans += queryS(lfs, lf, cf, lc, rc);
    }
    if (cf + 1 <= rc)
    {
        ans += queryS(rfs, cf + 1, rf, lc, rc);
    }
    return ans;
}
void modifyC(int p, int lf, int rf, ci pos, ci c, ci v)
{
    h[p][c] += v;
    if (lf == rf)
    {
        return;
    }
    mkcf;
    if (pos <= cf)
    {
        modifyC(lfs, lf, cf, pos, c, v);
    }
    else
    {
        modifyC(rfs, cf + 1, rf, pos, c, v);
    }
}
#define colors const vector<ll> &
ll check(ll p, ll lf, ll rf, colors cs)
{
    ll sum = 0;
    for (auto &c : cs)
    {
        sum += h[p][c];
    }
    return sum == rf - lf + 1;
}
const ll fail = -1;
ll queryCR(int p, int lf, int rf, int lc, colors cs)
{
    if (rf < lc)
    {
        return fail;
    }
    if (lc <= lf)
    {
        if (check(p, lf, rf, cs))
        { // still ok, move right
            return -1;
        }
        if (lf == rf)
        { // first to fail is lf, then ok is lf-1
            return lf - 1;
        }
    }
    mkcf;
    ll pos = queryCR(lfs, lf, cf, lc, cs);
    if (pos != fail)
    {
        return pos;
    }
    return queryCR(rfs, cf + 1, rf, lc, cs);
}
ll queryCL(int p, int lf, int rf, int rc, colors cs)
{
    if (lf > rc)
    {
        return fail;
    }
    if (rf <= rc)
    {
        if (check(p, lf, rf, cs))
        {
            return -1;
        }
        if (lf == rf)
        {
            return lf + 1;
        }
    }
    mkcf;
    ll pos = queryCL(rfs, cf + 1, rf, rc, cs);
    if (pos != fail)
    {
        return pos;
    }
    return queryCL(lfs, lf, cf, rc, cs);
}

ll n, q, c[mn], v[mn];
void solve()
{
    cin >> n >> q;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> c[i];
        modifyC(1, 1, n, i, c[i], 1);
    }
    for (ll i = 1; i <= n; ++i)
    {
        cin >> v[i];
        modifyS(1, 1, n, i, v[i]);
    }
    for (ll op, x, y; q--;)
    {
        cin >> op >> x >> y;
        if (op == 1)
        {
            modifyC(1, 1, n, x, c[x], -1);
            c[x] = y;
            modifyC(1, 1, n, x, c[x], 1);
        }
        else if (op == 2)
        {
            modifyS(1, 1, n, x, y - v[x]);
            v[x] = y;
        }
        else
        {
            bool ok = false;
            vector<ll> vec;
            for (ll i = 1, z; i <= y; ++i)
            {
                cin >> z;
                if (c[x] == z)
                {
                    ok = true;
                }
                vec.emplace_back(z);
            }
            if (!ok)
            {
                cout << "0\n";
                continue;
            }

            ll l = queryCL(1, 1, n, x, vec);
            ll r = queryCR(1, 1, n, x, vec);
            l = l == fail ? 1 : l;
            r = r == fail ? n : r;
            cout << queryS(1, 1, n, l, r) << '\n';
        }
    }

    for (ll i = 1; i <= 4 * n; ++i)
    {
        h[i].clear();
        s[i] = 0;
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
```

树状数组上倍增：

```c++
#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

// 比 unordered_map 更快的哈希表
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
typedef gp_hash_table<int, int, chash> hash_t;

int n, q, C[MAXN + 10], V[MAXN + 10];

hash_t colTree[MAXN + 10];
long long smTree[MAXN + 10];

int lb(int x) { return x & (-x); }

// val == -1：把位置 pos 的颜色 c 删掉
// val == 1：把位置 pos 的颜色设为 c
void addCol(int pos, int c, int val) {
    for (; pos <= n; pos += lb(pos)) colTree[pos][c] += val;
}

// 查询 vec 里的所有颜色在前 pos 个位置中一共出现了几次
int queryCol(int pos, vector<int> &vec) {
    int ret = 0;
    for (; pos; pos -= lb(pos)) for (int c : vec) {
        auto it = colTree[pos].find(c);
        if (it != colTree[pos].end()) ret += it->second;
    }
    return ret;
}

// 树状数组上倍增，
// 返回值 l 满足 vec 里所有颜色在区间 [l, lim] 中出现的总次数等于区间长度，且 l 最小
int gao1(int lim, vector<int> &vec) {
    int base = queryCol(lim, vec);
    if (base == lim) return 1;

    int b;
    for (b = 1; b <= n; b <<= 1);

    int now = 0, cnt = 0;
    for (b >>= 1; b; b >>= 1) {
        int nxt = now | b, tmp = 0;
        for (int c : vec) {
            auto it = colTree[nxt].find(c);
            if (it != colTree[nxt].end()) tmp += it->second;
        }
        if (nxt > lim || base - (cnt + tmp) == lim - nxt) {
            // do nothing
        } else {
            now = nxt; cnt += tmp;
        }
    }
    return now + 2;
}

// 树状数组上倍增，
// 返回值 r 满足 vec 里所有颜色在区间 [lim, r] 中出现的总次数等于区间长度，且 r 最大
int gao2(int lim, vector<int> &vec) {
    int base = queryCol(lim, vec);

    int b;
    for (b = 1; b <= n; b <<= 1);

    int now = 0, cnt = 0;
    for (b >>= 1; b; b >>= 1) {
        int nxt = now | b, tmp = 0;
        for (int c : vec) {
            auto it = colTree[nxt].find(c);
            if (it != colTree[nxt].end()) tmp += it->second;
        }
        if (nxt < lim || (cnt + tmp) - base == nxt - lim) {
            now = nxt; cnt += tmp;
        } else {
            // do nothing
        }
    }
    return now;
}

// 位置 pos 的权值增加 val
void addSm(int pos, long long val) {
    for (; pos <= n; pos += lb(pos)) smTree[pos] += val;
}

// 求前 pos 个位置的权值之和
long long querySm(int pos) {
    long long ret = 0;
    for (; pos; pos -= lb(pos)) ret += smTree[pos];
    return ret;
}

void solve() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &C[i]);
        addCol(i, C[i], 1);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &V[i]);
        addSm(i, V[i]);
    }

    while (q--) {
        int op, x, y; scanf("%d%d%d", &op, &x, &y);
        if (op == 1) {
            addCol(x, C[x], -1);
            addCol(x, y, 1);
            C[x] = y;
        } else if (op == 2) {
            addSm(x, y - V[x]);
            V[x] = y;
        } else {
            bool ok = false;
            vector<int> vec;
            for (int i = 1; i <= y; i++) {
                int z; scanf("%d", &z);
                if (C[x] == z) ok = true;
                vec.push_back(z);
            }
            if (!ok) { printf("0\n"); continue; }

            int L = gao1(x, vec), R = gao2(x, vec);
            printf("%lld\n", querySm(R) - querySm(L - 1));
        }
    }

    for (int i = 1; i <= n; i++) colTree[i].clear();
    for (int i = 1; i <= n; i++) smTree[i] = 0;
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
```



#### 猫树

> 洛谷P3865-求区间 max , $1\le n\le10^5,1\le m\le2\times10^6,a)i\in[0,10^9 ]$

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 131082 // 1<<log(1e5,2)+10
#define ml 20
ll n, m, a[mn], n2, lg[mn * 2], l, r;
ll pos[mn], gcd[mn][ml];
#define lfs p << 1
#define rfs p << 1 | 1
#define mkcf ll cf = (lf + rf) >> 1
void build(ll p, ll lf, ll rf, ll dep)
{
    if (lf == rf)
    {
        pos[lf] = p;
        return;
    }
    mkcf;
    build(lfs, lf, cf, dep + 1);
    build(rfs, cf + 1, rf, dep + 1);
    gcd[cf][dep] = a[cf];
    for (ll i = cf - 1; i >= lf; --i)
    {
        gcd[i][dep] = max(gcd[i + 1][dep], a[i]);
    }
    for (ll i = cf + 1; i <= rf; ++i)
    {
        gcd[i][dep] = max(gcd[i - 1][dep], a[i]);
    }
}
signed main()
{
    sc(n), sc(m);
    for (ll i = 1; i <= n; ++i)
    {
        sc(a[i]);
    }
    for (n2 = 1; n2 < n; n2 <<= 1) //满二叉树下节点有n2个
        ;
    for (ll i = 2; i <= n2 * 2; ++i)
    {
        lg[i] = lg[i / 2] + 1;
    }
    build(1, 1, n2, 1);
    while (m--)
    {
        sc(l), sc(r);
        if (l == r) //猫树不存叶子节点
        {
            printf("%lld\n", a[l]);
            continue;
        }
        ll k = lg[pos[r]] - lg[pos[l] ^ pos[r]];
        printf("%lld\n", max(gcd[l][k], gcd[r][k]));
    }
    return 0;
}
```



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

> 洛谷P3824：长为 $n(1\le n\le2\times 10^5)$ 值域的序列，有 $m(1\le m\le2\times 10^5)$ 次询问，问区间 $[l,r]$ 内严格第 $k$ 小(不去重)的值是什么

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



### K-D Tree

> 洛谷P4475-有 $n$ 人和 $m$ 巧克力，每个人有参数 $a,b,c$ ，巧克力有参数 $x,y,h$ ，每人只要对他自己 $ax+by\le c$ 的巧克力，求每人这样的巧克力的 $h$ 值之和 $1\le n,m\le5\times10^4,-10^9\le$ 参数 $\le10^9$ 

对二元函数 $f(x,y)=ax+by$ ，满足 $x,y$ 上单调性，所以节点维护的超长方体若边界都在肯定全部点都在，所以可以进行二分下去。

```c++
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=5e5+50;
int n,now,m,rt;
ll a,b,c;
struct data
{
	int d[2],mx[2],mn[2],lc,rc,val;
	ll sum;
	friend bool operator < (data a,data b)
		{return a.d[now]<b.d[now];}
}dat[N],t[N];
void getmax(int&a,int b){if(a<b)a=b;}
void getmin(int&a,int b){if(a>b)a=b;}
void pushup(int x)
{
	int lc=t[x].lc,rc=t[x].rc;
	for(int i=0;i<2;i++)
	{
		t[x].mn[i]=t[x].mx[i]=t[x].d[i];
		if(lc)  getmin(t[x].mn[i],t[lc].mn[i]),
			getmax(t[x].mx[i],t[lc].mx[i]);
		if(rc)  getmin(t[x].mn[i],t[rc].mn[i]),
			getmax(t[x].mx[i],t[rc].mx[i]);
	}
	t[x].sum=t[lc].sum+t[rc].sum+t[x].val;
}

int build(int l,int r,int pl)
{
	now=pl; int mid=(l+r)>>1;
	nth_element(dat+l,dat+mid,dat+r+1);
	t[mid]=dat[mid];
	if(l<mid) t[mid].lc=build(l,mid-1,!pl);
	if(r>mid) t[mid].rc=build(mid+1,r,!pl);
	pushup(mid); return mid;
}
bool check(ll x,ll y) {return x*a+y*b<c;}
ll query(int x)
{
	int tot=0;
	tot+=check(t[x].mx[0],t[x].mx[1]);
	tot+=check(t[x].mn[0],t[x].mx[1]);
	tot+=check(t[x].mx[0],t[x].mn[1]);
	tot+=check(t[x].mn[0],t[x].mn[1]);
	if(tot==4) return t[x].sum; // 都满足
	if(tot==0) return 0; // 都不满足
	ll res=0;
	if(check(t[x].d[0],t[x].d[1])) res+=t[x].val;
	if(t[x].lc) res+=query(t[x].lc);
	if(t[x].rc) res+=query(t[x].rc);
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
		scanf("%d%d%d",&dat[i].d[0],&dat[i].d[1],&dat[i].val);
	rt=build(1,n,0); while(m--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		printf("%lld\n",query(rt));
	}
	return 0;
}
```



> 洛谷P4148-对 $n\times n(n\le5\times 10^5)$ 矩阵进行强制在线维护(每个值异或 $lastans$ )：
>
> 1. `1 x y A` 单点加 $A$ (下标值在 $[1,n]$)
> 2. `2 x1 y1 x2 y2` 区间求和
> 3. `3` EOF (操作数不大于 $2\times10^5$)

```c++
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 200010;
int n, op, xl, xr, yl, yr, lstans;

struct node {
  int x, y, v;
} s[maxn];

bool cmp1(int a, int b) { return s[a].x < s[b].x; }

bool cmp2(int a, int b) { return s[a].y < s[b].y; }

double a = 0.725;
int rt, cur, d[maxn], lc[maxn], rc[maxn], L[maxn], R[maxn], D[maxn], U[maxn],
    siz[maxn], sum[maxn];
int g[maxn], t;

void print(int x) {
  if (!x) return;
  print(lc[x]);
  g[++t] = x;
  print(rc[x]);
}

void maintain(int x) {
  siz[x] = siz[lc[x]] + siz[rc[x]] + 1;
  sum[x] = sum[lc[x]] + sum[rc[x]] + s[x].v;
  L[x] = R[x] = s[x].x;
  D[x] = U[x] = s[x].y;
  if (lc[x])
    L[x] = min(L[x], L[lc[x]]), R[x] = max(R[x], R[lc[x]]),
    D[x] = min(D[x], D[lc[x]]), U[x] = max(U[x], U[lc[x]]);
  if (rc[x])
    L[x] = min(L[x], L[rc[x]]), R[x] = max(R[x], R[rc[x]]),
    D[x] = min(D[x], D[rc[x]]), U[x] = max(U[x], U[rc[x]]);
}

int build(int l, int r) {
  if (l > r) return 0;
  int mid = (l + r) >> 1;
  double av1 = 0, av2 = 0, va1 = 0, va2 = 0;
  for (int i = l; i <= r; i++) av1 += s[g[i]].x, av2 += s[g[i]].y;
  av1 /= (r - l + 1);
  av2 /= (r - l + 1);
  for (int i = l; i <= r; i++)
    va1 += (av1 - s[g[i]].x) * (av1 - s[g[i]].x),
        va2 += (av2 - s[g[i]].y) * (av2 - s[g[i]].y);
  if (va1 > va2)
    nth_element(g + l, g + mid, g + r + 1, cmp1), d[g[mid]] = 1;
  else
    nth_element(g + l, g + mid, g + r + 1, cmp2), d[g[mid]] = 2;
  lc[g[mid]] = build(l, mid - 1);
  rc[g[mid]] = build(mid + 1, r);
  maintain(g[mid]);
  return g[mid];
}

void rebuild(int& x) {
  t = 0;
  print(x);
  x = build(1, t);
}

bool bad(int x) { return a * siz[x] <= (double)max(siz[lc[x]], siz[rc[x]]); }

void insert(int& x, int v) {
  if (!x) {
    x = v;
    maintain(x);
    return;
  }
  if (d[x] == 1) {
    if (s[v].x <= s[x].x)
      insert(lc[x], v);
    else
      insert(rc[x], v);
  } else {
    if (s[v].y <= s[x].y)
      insert(lc[x], v);
    else
      insert(rc[x], v);
  }
  maintain(x);
  if (bad(x)) rebuild(x);
}

int query(int x) {
  if (!x || xr < L[x] || xl > R[x] || yr < D[x] || yl > U[x]) return 0;
  if (xl <= L[x] && R[x] <= xr && yl <= D[x] && U[x] <= yr) return sum[x];
  int ret = 0;
  if (xl <= s[x].x && s[x].x <= xr && yl <= s[x].y && s[x].y <= yr)
    ret += s[x].v;
  return query(lc[x]) + query(rc[x]) + ret;
}

int main() {
  scanf("%d", &n);
  while (~scanf("%d", &op)) {
    if (op == 1) {
      cur++, scanf("%d%d%d", &s[cur].x, &s[cur].y, &s[cur].v);
      s[cur].x ^= lstans;
      s[cur].y ^= lstans;
      s[cur].v ^= lstans;
      insert(rt, cur);
    }
    if (op == 2) {
      scanf("%d%d%d%d", &xl, &yl, &xr, &yr);
      xl ^= lstans;
      yl ^= lstans;
      xr ^= lstans;
      yr ^= lstans;
      printf("%d\n", lstans = query(rt));
    }
    if (op == 3) return 0;
  }
}
```



### 堆

#### 可删堆

> 例题：P2056洛谷(的一部分)

以 $O(\log n)$ 均摊实现：①插入任意值 ②删除指定值 ③求最大值 

> 若要求次大值，可以弹两次堆顶，再把第一次弹的压进去，最后返回第二次弹的结果

```c++
struct heap //可删堆(大根堆)
{
    priority_queue<ll> a, b;
    void insert(ll x) { a.push(x); }
    void erase(ll x) { b.push(x); }
    ll top()
    {
        while (!b.empty() && a.top() == b.top())
            a.pop(), b.pop();
        return a.top();
    }
    ll pop()
    {
        ll t = top(); a.pop(); return t;
    }
    ll size() { return a.size() - b.size(); }
}
```



#### 笛卡尔树

节点由 $(k,w)$ 组成， $k$ 满足二叉搜索树， $w$ 满足堆，若 $(k,w)$ 分别互不相同，那么结构唯一

可以 $O(n)$ 构建。 例题P5854：给定排列，构建(满足小根堆的)笛卡尔树，输出me给节点 $i$ 的左右儿子(不存在为 $0$ )的 $\oplus_{i=1}^ni(l_i+1),\oplus_{i=1}^ni(r_i+1)$

笛卡尔树不平衡，单调序列可以卡单次查询到 $O(n)$

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



#### 可并堆

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

> (SCNUOJ1731)你有一个长度为 $n$ 的序列，下标从 $1$ 开始，一开始每个数都是 $1236895$ ，你需要维护 $m$ 次下列操作：
>
> 1. `1 l r x` 将区间 $[l,r]$ 的每个值都设为 $x$ 
> 2. `2 l r x` 将区间 $[l,r]$ 的每个值都加上 $x$
> 3. `3 l r` 查询区间 $[l,r]$ 的值之和
>
>  $n,m(1\le n,m\le10^5)$ ，数据随机，$1\le x\le10^7$ 

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
ll n;
struct node_t
{
    ll l, r;
    mutable ll v; // mutable使得const可变(set元素是const)
    node_t(const ll &il, const ll &ir, const ll &iv) : l(il), r(ir), v(iv) {}
    inline bool operator<(const node_t &o) const { return l < o.l; }
};
set<node_t> odt; //建立一棵珂朵莉树
auto split(ll x) //珂朵莉基操
{
    if (x > n)
        return odt.end();
    auto it = --odt.upper_bound(node_t{x, 0, 0});
    if (it->l == x)
        return it;
    ll l = it->l, r = it->r, v = it->v;
    odt.erase(it);
    odt.insert(node_t(l, x - 1, v));
    return odt.insert(node_t(x, r, v)).first;
}
void assign(ll l, ll r, ll v) //区间赋值为v, 均摊O(loglogn)
{
    auto itr = split(r + 1), itl = split(l);
    odt.erase(itl, itr);
    odt.insert(node_t(l, r, v));
}
void add(ll l, ll r, ll v) //区间增加v, 均摊O(loglogn)
{
    auto itr = split(r + 1), itl = split(l);
    for (; itl != itr; ++itl) //枚举每个子区间
    {
        itl->v = itl->v + v;
    }
}
ll query(ll l, ll r) //区间查询, 均摊O(loglogn)
{
    ll res = 0;
    auto itr = split(r + 1), itl = split(l);
    for (; itl != itr; ++itl)
    { // itl->l, itl->r, itl->v 是当前子区间的左右端点和值
        res += (itl->r - itl->l + 1) * (itl->v);
    }
    return res;
}
signed main()
{
    sc(n);
    odt.insert({1, n, 1236895}); //初始化区间
    ll m, cmd, l, r, x;
    for (sc(m); m--;)
    {
        sc(cmd), sc(l), sc(r);
        if (cmd == 1)
        {
            sc(x), assign(l, r, x);
        }
        else if (cmd == 2)
        {
            sc(x), add(l, r, x);
        }
        else
        {
            printf("%lld\n", query(l, r));
        }
    }
    return 0;
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



> P2294-有 $t(< 100)$ 组询问，每次给定 $n(< 100)$ 个月和 $m(< 10^3)$ 条账本，账本表示 $[u,v]$ 月份收入和为 $w$。问账本是否矛盾。

解法一：差分约束。

设前 $i$ 个月收入之和为 $s_i$，则每条账本为：$s_v-s_{u-1}=w$，即：
$$
\begin{cases}
s_{u-1}&\le s_v-w\\
s_v&\le s_{u-1}+w
\end{cases}
$$
直接建图，建出来的图不一定是连通的，则可以对每个非连通子图都跑一次 SPFA，如果存在一个子图有负环就 false，否则 true。不管跑最短路还是最长路都能过(分别设不同的无穷初始值)，记得初始化全(不要漏了 `cnt` 等数组)。

解法二：并查集。

若已知 $s_a-s_b,s_b-s_c$，且发现新的 $s_a-s_c$，需要判断新的是否符合原有的。维护带权并查集，设 $c_u=s_{fa}-s_u$。当我们发现输入的 $a,b$ 在同一个并查集时，有 $c_a-c_b=s_{fa}-s_a-s_{fa}+s_b$，故判断原有的 $c_u-c_v$ 是否与 $w$ 相等即可。

初始设 $c=0$，合并两并查集 $u,v$ 时，设 $fa_v$ 并到 $fa_u$ 去，因为已知 $s_v-s_u=w$，且原有 $c_u=s_{fa_u}-s_u,c_v=s_{fa_v}-s_v$。要求出新的 $s_{fa_u}-s_{fa_v}=(c_u+s_u)-(c_v+s_v)$ $=c_u-c_v-(s_v-s_u)$ $=c_u-c_v-w$。(类比向量加减法)

对于路径压缩，设已知 $c_u=s_r-s_u,c_v=s_u-s_v$，需要更新 $s_r-s_v$，等于 $c_u+c_v$，即直接求边权和即可。

```c++
#include<bits/stdc++.h>
int fa[105],cha[105];  
int find(int x)
{  
    if(x!=fa[x])
    {
        int t=find(fa[x]);
        cha[x]+=cha[fa[x]];
        fa[x]=t;  
    }  
    return fa[x];  
}  
int main()  
{  
    int T,n,m,i,x,y,z,flag;  
    scanf("%d",&T);  
    while (T--) 
    {  
        flag=0;  
        scanf("%d%d",&n,&m);  
        for(i=0;i<=n;i++)
        {  
            fa[i]=i;  
            cha[i]=0;  
        }  
        for(i=1;i<=m;i++)  
        {  
            scanf("%d%d%d",&x,&y,&z);  
            x--;  
            if(find(x)!=find(y))  
            {  
                cha[fa[y]]=cha[x]-cha[y]-z;  
                fa[fa[y]]=fa[x];
            }  
            else  
            if(cha[x]-cha[y]!=z) flag=1;  
        }  
        if(flag==0) printf("true\n"); else printf("false\n");  
    }  
    return 0;  
}
```

解法三：贪心

先按左端点为第一排序关键字，再排右端点，作为比较依据动态维护一个堆。之后就开始两两比较，如果左端点相等，就比较右端点，如果相等，就比较值，如果值不同，就直接输出false，否则输出true，如果右端点不等，就把相同的部分抵消掉，把新的区间再压入优先队列。直到不能操作，就输出true。



其他例题： 

- (洛谷P2661)出度均 $1$ 无自环 $n$ 点有向图，求最小环长度

  路径压缩时维护每个点到根的距离。枚举每条边，若端点在同一并查集那么环长 $=d[u]+d[v]+1$ ，否则合并并查集 ( $d[u]=d[v]+1,f_{f_u}=f_v$ ) ；也可以 DFS (带深度,重复访问时得环,深度相减)



#### 可撤销并查集

> 洛谷5787 $n(1\le n\le10^5)$ 点 $m(1\le m\le2\times10^5)$ 边无向图，每条边生存周期是 $[l,r)(1\le l < r\le10^5)$，问每个时刻图是不是二分图。

二分图判断：可撤销种类并查集 + 染色法。

对节点 $i$，拆分为两个节点分属 $S,T$。若存在一个点，使得拆分的两点并在一起了，那么就不是二分图。

按时间轴建立线段树，第 $i$ 个线段树节点维护时间区间内存在的所有边(从 $1$ 编号)，那么每次加一条边，会向最多 $\log k$ 个节点加边。

然后按线段树顺序遍历节点，先序时把线段树节点的所有边在并查集上合并，即对边 $(u,v)$ 入图的话，将 $(u,v+n)$ 与 $(u+n,v)$ 在并查集合并，然后每次合并时，按秩合并，树高小的合到大的，并记录进行合并的操作顺序，然后记录这个节点一开始是在哪个操作记号，在再次回到该节点时(后序)，逐个撤销掉并查集操作，进行复原。

设最大生存时间是 $k$，空间复杂度是 $O(m\log k)$，时间复杂度是 $O(k\log k+4k+m\log k+2n\log n)=O(m\log k+n\log n)$

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
using ll = int;
using trip = tuple<ll, ll, ll>; //感觉pair就行
struct stk
{
    vector<trip> a;
    ll top;
    void push(trip v) { a[++top] = v; }
    trip pop() { return a[top--]; }
} s;
signed main()
{
    ll n, m, k;
    sc(n), sc(m), sc(k);
    using edge = pair<ll, ll>;
    vector<vector<edge>> e(4 * k + 10, vector<edge>());
#define lfs p << 1
#define rfs p << 1 | 1
#define mkcf ll cf = (lf + rf) >> 1
    auto insert = [&](auto self, ll p, ll lf, ll rf, ll lc, ll rc, edge v) -> void
    {
        if (lf >= lc && rf <= rc)
        {
            e[p].push_back(v);
            return;
        }
        mkcf;
        if (lc <= cf)
        {
            self(self, lfs, lf, cf, lc, rc, v);
        }
        if (rc >= cf + 1)
        {
            self(self, rfs, cf + 1, rf, lc, rc, v);
        }
    };
    for (ll i = 1, x, y, l, r; i <= m; ++i)
    {
        sc(x), sc(y), sc(l), sc(r), ++l;
        insert(insert, 1, 1, k, l, r, {x, y});
    }
    vector<ll> fa(2 * n + 10), h(2 * n + 10, 1);
    for (ll i = 1; i <= 2 * n; ++i)
    {
        fa[i] = i;
    }
    auto findf = [&](ll x)
    {
        while (x != fa[x])
        {
            x = fa[x] = fa[fa[x]];
        }
        return x;
    };
    ll cnt = 0;
    for (ll i = 1; i <= 4 * k; ++i)
    {
        cnt += e[i].size();
    }
    s.a.resize(cnt * 2 + 10); //我也不知道怎么定的,cnt都行
    auto merge = [&](ll x, ll y)
    {
        ll fx = findf(x), fy = findf(y);
        if (h[fx] > h[fy])
        {
            swap(fx, fy);
        }
        s.push({fx, fy, h[fx] == h[fy]});
        fa[fx] = fy, h[fy] += h[fx] == h[fy];
    };
    auto solve = [&](auto self, ll p, ll lf, ll rf) -> void
    {
        bool ok = true;
        ll lastTop = s.top;
        for (edge x : e[p])
        {
            ll u = x.first, v = x.second;
            if (findf(u) == findf(v))
            {
                ok = false;
                for (ll i = lf; i <= rf; ++i)
                {
                    printf("No\n");
                }
                break;
            }
            merge(u, v + n), merge(u + n, v);
        }
        if (ok)
        {
            if (lf == rf)
            {
                printf("Yes\n");
                return;
            }
            mkcf;
            self(self, lfs, lf, cf), self(self, rfs, cf + 1, rf);
        }
        while (s.top > lastTop)
        {
            trip nd = s.pop();
            ll x, y, dt;
            tie(x, y, dt) = nd;
            h[fa[x]] -= dt;
            fa[x] = x;
        }
    };
    solve(solve, 1, 1, k);
    return 0;
}
```

> 实现版本 2：CF813F(每次更改一条边 $(x,y)(x < y)$，若本来有就删否则加)，$n,m\le 10^5,m$ 是操作次数

```c++
#include <bits/stdc++.h>
const int N = 200000 + 10;
int n, m, ans[N];
struct E
{
    int u, v;
    E(int a, int b) : u(a), v(b) {}
};
std::map<int, int> g[N];

int L[N << 2], R[N << 2];
std::vector<E> tag[N << 2];
#define lc (o << 1)
#define rc ((o << 1) | 1)
void build(int o, int l, int r)
{
    L[o] = l;
    R[o] = r;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
}
// 把一条边拆到logm个区间上去.
// 可以说线段树只是用来保证复杂度的...
void query(int o, int l, int r, const E &e)
{
    if (L[o] > r || R[o] < l)
        return;
    if (l <= L[o] && R[o] <= r)
    {
        tag[o].push_back(e);
        return;
    }
    query(lc, l, r, e);
    query(rc, l, r, e);
}

// merged tree(root=x)->tree(root=y)
struct P
{
    int x, y;
    P(int a, int b) : x(a), y(b) {}
};
int fa[N], size[N], dis[N];
inline int getpar(int x)
{
    while (fa[x] != x)
        x = fa[x];
    return x;
}

// 到并查集根所经过的边数mod2.
// mod2意义下的加法即为xor.
// 用来查询x和根是不是相同颜色.
inline int getdis(int x)
{
    int d = 0;
    while (fa[x] != x)
    {
        d ^= dis[x];
        x = fa[x];
    }
    return d;
}
/// 按照size合并.
inline int solve(int x, int y, std::stack<P> &stk)
{
    int dx = getdis(x), dy = getdis(y);
    x = getpar(x);
    y = getpar(y);
    if (x == y)
        return (dx ^ dy);
    if (size[x] > size[y])
    {
        std::swap(x, y);
        std::swap(dx, dy);
    }
    size[y] += size[x];
    fa[x] = y;
    dis[x] = (dx ^ dy ^ 1);
    stk.push(P(x, y));
    return 1;
}
// 撤销(x->y)的合并.拆出来,size改回去.dis改成0
inline void back(P p)
{
    int x = p.x, y = p.y;
    size[y] -= size[x];
    dis[fa[x] = x] = 0;
}
// 递归线段树,进入区间[l,r]时
// 保证时间轴上[l,r]范围内一直可用的边都被加入了
void dfs(int o, int flag)
{
    std::stack<P> stk;
    for (auto e : tag[o])
        flag &= solve(e.u, e.v, stk);
    if (L[o] == R[o])
        ans[L[o]] = flag;
    else
    {
        dfs(lc, flag);
        dfs(rc, flag);
    }
    // 撤销操作...不然从爸爸进入兄弟节点的时候开始讲到的那个性质会被破坏.
    // 注意撤销顺序...
    while (!stk.empty())
    {
        back(stk.top());
        stk.pop();
    }
}

int read()
{
    int x = 0;
    char c;
    do
    {
        c = getchar();
    } while (!isdigit(c));
    do
    {
        x = x * 10 + c - '0';
        c = getchar();
    } while (isdigit(c));
    return x;
}
int main()
{
    n = read();
    m = read();
    build(1, 1, m);
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        x = read();
        y = read();
        if (x > y)
            std::swap(x, y);
        if (g[x][y] == 0)
            g[x][y] = i;
        else
        {
            query(1, g[x][y], i - 1, E(x, y));
            g[x][y] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        size[fa[i] = i] = 1;
        for (auto p : g[i])
            if (p.second > 0)
                query(1, p.second, m, E(i, p.first));
    }
    dfs(1, 1);
    for (int i = 1; i <= m; i++)
        puts(ans[i] ? "YES" : "NO");
    return 0;
}
```



#### 可持久化并查集

> 洛谷U208135-给定 $n(1\le n\le10^5)$ 个集合，第 $i$ 个集合初始只有数 $i$ ，维护 $m(1\le m\le2\times10^5)$ 次操作：
>
> - `1 a b` 合并 $a,b$ 所在集合
> - `2 k` 回到第 $k$ 次操作之后的状态
> - `3 a b` 问 $a,b$ 是否在同一集合(是输出 $1$ 否则 $0$ )

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
typedef pair<int, int> pii;
const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;
const int maxt = 4e6;//4n+mlogn
#define fi first
#define se second
struct Node
{
    int ls, rs, val, rnk;
};
#define mid ((l + r) / 2)
int n, m;
int rt[maxm];
struct SegTree
{
    Node s[maxt];
    int tot;
    int build(int l, int r)
    {
        int k = ++tot;
        if (l == r)
            s[k] = {0, 0, l, 1};
        else
            s[k] = {build(l, mid), build(mid + 1, r), 0, 0};
        return k;
    }
    pii new_node(int l, int r, int u, int p)
    {
        int k = ++tot;
        s[k] = s[u];
        if (l == r)
            return {k, k};
        int res;
        if (p <= mid)
        {
            pii pos = new_node(l, mid, s[u].ls, p);
            s[k].ls = pos.fi, res = pos.se;
        }
        else
        {
            pii pos = new_node(mid + 1, r, s[u].rs, p);
            s[k].rs = pos.fi, res = pos.se;
        }
        return {k, res};
    }
    int qry(int l, int r, int k, int p)
    { // node
        if (l == r)
            return k;
        if (p <= mid)
            return qry(l, mid, s[k].ls, p);
        else
            return qry(mid + 1, r, s[k].rs, p);
    }
    int merge(int k, int u, int v)
    { // node
        pii p1 = new_node(1, n, k, s[u].val);
        s[p1.se].val = s[v].val;
        pii p2 = new_node(1, n, p1.fi, s[v].val);
        s[p2.se].rnk = max(s[p2.se].rnk, s[p1.se].rnk + 1);
        return p2.fi;
    }
} sgt;

struct DSU
{
    Node *s;
    void init()
    {
        rt[0] = sgt.build(1, n);
        s = sgt.s;
    }
    int fd(int k, int u)
    { // node
        int fa = sgt.qry(1, n, k, u);
        if (s[fa].val == u)
            return fa;
        int res = fd(k, s[fa].val);
        s[fa].rnk = s[res].rnk + 1;
        return res;
    }
    int mg(int k, int u, int v)
    {
        u = fd(k, u), v = fd(k, v);
        if (s[u].val == s[v].val)
            return k;
        if (s[u].rnk < s[v].rnk)
            return sgt.merge(k, u, v);
        else
            return sgt.merge(k, v, u);
    }
} dsu;

int main()
{
    sc(n), sc(m);
    dsu.init();
    for (int i = 1, o, x, y; i <= m; ++i)
    {
        sc(o);
        if (o == 1)
            sc(x), sc(y), rt[i] = dsu.mg(rt[i - 1], x, y);
        if (o == 2)
            sc(x), rt[i] = rt[x];
        if (o == 3)
        {
            sc(x), sc(y);
            rt[i] = rt[i - 1];
            int u = dsu.fd(rt[i], x), v = dsu.fd(rt[i], y);
            printf("%d\n", u == v);
        }
    }
    return 0;
}
```

其他写法：

```c++
#include<stdio.h>
const int N=1e5+5;
int L[N<<6],R[N<<6],rt[N<<6],fa[N<<6],sz[N<<6],cnt;
#define mid (l+r>>1)
#define ls L[k],l,mid
#define rs R[k],mid+1,r
int n,m;
void swap(int &x,int &y){
	int z=x;x=y;y=z;
}
void build(int &k,int l,int r){
	k=++cnt;
	if(l==r)return fa[k]=l,sz[k]=1,void();
	build(ls),build(rs);
}
void modify(int &k,int l,int r,int x,int y,int z){
	++cnt;L[cnt]=L[k],R[cnt]=R[k],fa[cnt]=fa[k],sz[cnt]=sz[k];k=cnt;
	if(l==r)return fa[k]=y,sz[k]=z,void();
	if(x<=mid)modify(ls,x,y,z);
	else modify(rs,x,y,z);
}
int query(int k,int l,int r,int x){
	if(l==r)return k;
	if(x<=mid)return query(ls,x);
	else return query(rs,x);
}
int find(int k,int x){
	int F=query(k,1,n,x);
	if(fa[F]==x)return F;
	return find(k,fa[F]);
}
int main(){
	scanf("%d%d",&n,&m);
	build(rt[0],1,n);
	for(int i=1,opt,x,y;i<=m;i++){
		scanf("%d%d",&opt,&x);rt[i]=rt[i-1];
		if(opt!=2)scanf("%d",&y);
		if(opt==1){
			int fx=find(rt[i],x),fy=find(rt[i],y);
			if(fa[fx]!=fa[fy]){
				if(sz[fx]>sz[fy])swap(fx,fy);
				modify(rt[i],1,n,fa[fx],fa[fy],sz[fx]);
				modify(rt[i],1,n,fa[fy],fa[fy],sz[fx]+sz[fy]);
			}
		}
		else if(opt==2)rt[i]=rt[x];
		else{
			int fx=find(rt[i],x),fy=find(rt[i],y);
			printf("%d\n",fa[fx]==fa[fy]);
		}
	}
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

直径是树的全源最长路径

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

解法零：暴力

```python
if d[u]<d[v]:
    u,v=v,u
while d[u]>d[v]:
    u=fa[u]
while u!=v:
    u,v=fa[u],fa[v]
return u
```

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

解法三：tarjan 离线，复杂度取并查集的

```c++
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

class Edge {
 public:
  int toVertex, fromVertex;
  int next;
  int LCA;
  Edge() : toVertex(-1), fromVertex(-1), next(-1), LCA(-1){};
  Edge(int u, int v, int n) : fromVertex(u), toVertex(v), next(n), LCA(-1){};
};

const int MAX = 100;
int head[MAX], queryHead[MAX];
Edge edge[MAX], queryEdge[MAX];
int parent[MAX], visited[MAX];
int vertexCount, queryCount;

void init() {
  for (int i = 0; i <= vertexCount; i++) {
    parent[i] = i;
  }
}

int find(int x) {
  if (parent[x] == x) {
    return x;
  } else {
    return find(parent[x]);
  }
}

void tarjan(int u) {
  parent[u] = u;
  visited[u] = 1;

  for (int i = head[u]; i != -1; i = edge[i].next) {
    Edge& e = edge[i];
    if (!visited[e.toVertex]) {
      tarjan(e.toVertex);
      parent[e.toVertex] = u;
    }
  }

  for (int i = queryHead[u]; i != -1; i = queryEdge[i].next) {
    Edge& e = queryEdge[i];
    if (visited[e.toVertex]) {
      queryEdge[i ^ 1].LCA = e.LCA = find(e.toVertex);
    }
  }
}

int main() {
  memset(head, 0xff, sizeof(head));
  memset(queryHead, 0xff, sizeof(queryHead));

  cin >> vertexCount >> queryCount;
  int count = 0;
  for (int i = 0; i < vertexCount - 1; i++) {
    int start = 0, end = 0;
    cin >> start >> end;

    edge[count] = Edge(start, end, head[start]);
    head[start] = count;
    count++;

    edge[count] = Edge(end, start, head[end]);
    head[end] = count;
    count++;
  }

  count = 0;
  for (int i = 0; i < queryCount; i++) {
    int start = 0, end = 0;
    cin >> start >> end;

    queryEdge[count] = Edge(start, end, queryHead[start]);
    queryHead[start] = count;
    count++;

    queryEdge[count] = Edge(end, start, queryHead[end]);
    queryHead[end] = count;
    count++;
  }

  init();
  tarjan(1);

  for (int i = 0; i < queryCount; i++) {
    Edge& e = queryEdge[i * 2];
    cout << "(" << e.fromVertex << "," << e.toVertex << ") " << e.LCA << endl;
  }

  return 0;
}
```

解法四：LCA 为两个游标跳转到同一条重链上时深度较小的那个游标所指向的点。

树链剖分的预处理时间复杂度为线性，单次查询的时间复杂度为对数，并且常数较小。

#### 树上k级祖先

倍增：(lc1483, 不存在输出 -1)

```c++
class TreeAncestor {
    vector<vector<int>> pa;
public:
    TreeAncestor(int n, vector<int> &parent) {
        int m = 32 - __builtin_clz(n); // n 的二进制长度
        pa.resize(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
            pa[i][0] = parent[i];
        for (int i = 0; i < m - 1; i++)
            for (int x = 0; x < n; x++)
                if (int p = pa[x][i]; p != -1)
                    pa[x][i + 1] = pa[p][i];
    }

    int getKthAncestor(int node, int k) {
        int m = 32 - __builtin_clz(k); // k 的二进制长度
        for (int i = 0; i < m; i++) {
            if ((k >> i) & 1) { // k 的二进制从低到高第 i 位是 1
                node = pa[node][i];
                if (node < 0) break;
            }
        }
        return node;
    }

    // 另一种写法，不断去掉 k 的最低位的 1
    int getKthAncestor2(int node, int k) {
        for (; k && node != -1; k &= k - 1) // 也可以写成 ~node
            node = pa[node][__builtin_ctz(k)];
        return node;
    }
};
```



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

> 注：暴力思路是从 $u$ 出发 DFS 到 $v$ 即可



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

> 例题洛谷P3806：$n(1\le n\le10^4)$ 点带边权树，$m(1\le m\le100)$ 次询问，每次询问求树上是否有距离为 $k$ 的点对，有就输出 `AYE` 
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
} e[mn << 1];
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

##### 随机游走

> 给定一棵树，树的某个结点上有一个硬币，在某一时刻硬币会等概率地移动到邻接结点上，问硬币移动到邻接结点上的期望距离。

设 $f(u)$ 为 $u$ 节点走到父节点 $p_u$ 的期望距离，有：
$$ {r}
f(u)=\sum_{(u,t)\in E}w(u,t)+\sum_{v\in son_u}f(v)
$$
若 $w=1$ 则即 $u$ 子树所有节点的度数和，即 $u$ 子树大小的二倍减一。

设 $g(u)$ 代表 $p_u$ 走向子节点 $u$ 的期望距离，有：
$$
g(u)=g(p_u)+f(p_u)-f(u)
$$
显然初始值是 $f_{leaf}=1,g_{root}=0$。

```c++
vector<int> G[maxn];
void dfs1(int u, int p) {
  f[u] = G[u].size();
  for (auto v : G[u]) {
    if (v == p) continue;
    dfs1(v, u);
    f[u] += f[v];
  }
}
void dfs2(int u, int p) {
  if (u != 1) g[u] = g[p] + f[p] - f[u];
  for (auto v : G[u]) {
    if (v == p) continue;
    dfs2(v, u);
  }
}
```



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



### 基本概念

> 这一章节主要用作英文题面阅读理解和单词/符号翻译，并提供简单图论性质(下划线)

**起点** (tail) ，**终点** (head) 是有向边 (又称**弧** arc )  $u\to v$ 。点数是**阶** (order) 。无向图里，边 $e$ 和点 $v$ **关联** (incident)是 $e$ 的一个**端点** (endpoint) 为 $v$ ，点的领域记作 $N(v)$ ，即相邻点

度为 $d(v)=1$ 的节点称为**叶节点**或**悬挂点** (leaf/pandant vertex) , 按度数奇偶称**奇/偶点** (odd/even vertex)，<u>奇点个数一定是偶数</u> ，**支配点** (universial vertex) 是度为 $|V|-1$ 的点。最小度记作 $\delta(G)$ ，最大度记作 $\Delta(G)$ ，**入度** (in-degree) 记作 $\delta^-(v)$ ，**出度** (out-degree) 记作 $\delta^+(v)$ 

无 **自环** (loop)、 **重边** (multiple edge) 的图是**简单图** (simple graph) ，否则是**多重图** (multigraph) 。<u>具有至少两顶点的简单无向图一定存在度相同的节点</u>(抽屉原理) 。有向图 $u\to v,v\to u$ 不是重边。序列能作为图/简单图的度数列称为序列是可图化/可简单图化的。

**途径**(walk)是若干点连接起来的边的集合， **迹**(trail)是边互不相同的途径。**路径**(path)/**简单路径**(simple path)，**回路**(circuit)是除首尾点，其余点互不相同的迹。边的数量(或边权和)是长度(该段落定义视具体题目题面)

若点集和边集都是某图子集，那么是**子图** (subgraph) $H\subseteq G$ 。**真子图**称为 proper-subgraph 。若子图只删点( $\forall u,v\in V_H,(u,v)\in E_G\to(u,v)\in E_H$ )，是**导出子图/诱导子图** (induced subgraph)，只由点集决定，记作 $G[V']$ 。若顶点与母图一样，那么称为**生成子图/支撑子图** (spanning subgraph) 。原图或空图称为**平凡子图** (trivial subgraph)。$k-$ **正则图** (k-regular graph) 是每个点度均为 $k$ 的无向图。若无向图生成子图 $F$ 是 $k-$ 正则图，那么 $F$ 是原图的 $k-$ 因子 (k-factor)。若有向图导出子图的每个点 $v$ 满足 $(v,u)\in E$ (在原图边集)且 $u$ 在导出子图，那么称为**闭合子图** (closed subgraph)。从图删去 $V'$ 的点记作 $G[V\backslash V']$ 。删边同理。删点可记作 $G-V$ 。

**连通**(connected) 是无向图任两点可达。 **强连通**是任意两点连通的有向图，**弱连通**是有向图转无向图后成为连通图的图。有**连通块(连通分量)**概念及其强/弱连通分量 (SCC)概念。连通图**点割集** (vertex cut/separating set)大小为 $1$ 叫做**割点** / 割顶 (cut vertex) 。若 $|V|\ge k+1$ 且不存在 $k-1$ 大小点割集，图是 $k-$ **点连通的** (k-vertex-connected) , 其最大 $k$ 叫**点连通度**(vertex connectivity) 记作 $\kappa(G)$ (非完全图是最小点割集大小，完全图是 $n-1$ )。使得本可达的 $u,v$ 不连通的最小点割集(不考虑其他点连通性)大小是局部点连通度 (local connectivity) 记作 $\kappa(u,v)$ 。同理可以定义边割集和桥， $k-$ 边连通的，边连通度 $\lambda(G)$ 和局部边连通度 $\lambda(u,v)$ 。点双连通 (binoeected) 是除单边双点图外的 $2-$ 点连通(是没有割点的连通图)。边双连通等于 $2-$ 边连通。类似有(极大)点/边双连通分量。 <u>Whitney 定理：任意图 $G$ $\kappa(G)\le \lambda(G)\le\delta(G)$</u> 

 一般边数接近点数平方叫稀疏图 (sparse graph)，否则稠密图 (dense graph)。**补图** (complement graph) $\overline G$ 是 $(u,v)\in E(\overline G)$ 当且仅当 $(u,v)\notin E(G)$ 补图是无向简单图。**反图** (transpose graph) 是有向图每条边反向。**完全图** (complete graph) 是无向简单图，任两点有边，记作 $K_n$ 。有向图任两点有两条互为反向的边记作**有向完全图** (complete digraph)。有向简单图两点间有一条单向边是**竞赛图** (tournament graph) 。边集是空叫**零图** (null graph)，记作 $N_n$ 。无向简单图所有边构成一个圈称为**环图/圈图** (cycle graph) , $n\ge 3$ 记作 $C_n$ ，<u>充要条件是为 2-正则连通图</u>。若无向简单图满足一个点是支配点，其他点无边相连，称为**星图/菊花图** (star graph), $n\ge1,n+1$ 阶星图记作 $S_n$ 。无向简单图满足一个点是支配点，其他点构成一个圈是轮图 (wheel graph) $n+1(n\ge 3)$ 阶轮图是 $W_n$ 。无向简单图所有边构成简单路径，称为**链** (chain/path graph)，记作 $P_n$ 。无向连通无环图是**树**。无向连通、恰含一环是**基环树** (pseudotree)。有向弱连通，入度均 $1$ 图是基环外向树，出度均为 $1$ 是基环内向树。多棵树组成**森林**(基环同理)。基环内向森林：functional graph。无向连通图每条边最多在一个环内是**仙人掌** cactus ，仙人掌组成沙漠。**二分图** bipartite graph，任何两个不在同一部分的点都有连边是**完全二分图** (complete bipartite graph/biclique) 记作 $K_{n,m}$ 。

若 $E'\in E$ 且 $E'$ 任两条不同的边没有公共端点，且不是自环，那么 $E'$  是一个**匹配** (matching)/**边独立集** (independent edge set)。若一个点是匹配中某边的端点，称为**被匹配的**(matched)/**饱和的**(saturated)，否则是**不被匹配的**(unmatched)。边数最多的匹配是一张图的**最大匹配**(maximum-cardinality matching)，记作 $v(G)$ 。权重和最大的匹配是**最大权匹配**(maximum-weight matching)。匹配加入任意边后不再是匹配，称为**极大匹配**(maximal matching)。最大的极大匹配就是最大匹配，任何最大匹配都是极大匹配。极大匹配一定是边支配集，但边支配集不一定是匹配。最小极大匹配和最小边支配集大小相等，但最小边支配集不一定是匹配。若一个匹配里所有点都是被匹配的，称为**完美匹配** /完备匹配/完全匹配(perfect matching)。只有一个点不被匹配是准完美匹配(near-perfect matching)。对匹配 $M$ ，若一条路径以非匹配点为起点，每相邻两条边的一条在匹配中另一条不在，称为**交替路径**(alternating path)，在非匹配点终止的交替路径称为**增广路经**(augmenting path)。<u>托特定理： $n$ 阶无向图 $G$ 有完美匹配当且仅当 $\forall V'\subset V(G),p_奇(G-V')\le |V'|$  (奇数阶连通分支数)，任何无桥3-正则图都有完美匹配。</u>

若 $V'\subseteq V$ 且 $\forall e\in E$ 满足 $e$ 至少一个端点在 $V'$ 中，称 $V'$ 为一个**点覆盖**(vertex cover)。<u>点覆盖集必为支配集，但极小点覆盖集不一定是极小支配集。一个点集是点覆盖的充要条件是其补集是独立集，因此最小点覆盖的补集是最大独立集。一张图的任何一个匹配的大小都不超过其任何一个点覆盖的大小。完全二分图 $K_{n,m}$ 的最大匹配和最小点覆盖大小都为 $\min(n,m)$ 。</u>

若 $E'\subseteq E$ 且 $\forall v\in V$ 满足 $v$ 与 $E'$ 至少一条边相邻，称为**边覆盖**(edge cover)，最小边覆盖的大小记作 $\rho(G)$ 。<u>对于所有非匹配点，将其一条邻边加入最大匹配中，即得到了一个最小边覆盖。也可以由最小边覆盖求得：对于最小边覆盖中每对有公共点的边删去其中一条。满足 $\rho(G)+v(G)=|V(G)|$ 且 $v(G)\le \rho(G)$ 特别地，完美匹配一定是一个最小边覆盖，这也是上式取到等号的唯一情况。一张图的任何一个独立集的大小都不超过其任何一个边覆盖的大小。完全二分图 $K_{n,m}$ 的最大独立集和最小边覆盖大小都为 $\max(n,m)$ 。</u>

一张图可以画在一个平面内，无两条边在非端点处相交，是**平面图** (planar graph)，任何子图都不是 ${K_5}$ 或 ${k_{3,3}}$ 是为平面图的充要条件。 简单连通平面图若 $V\ge 3$ 则 $|E|\le 3|V|-6$ 。

若存在双射 $f:V(G)\to V(H)$ ，满足 $(u,v)\in E(G)$ ，当且仅当 $(f(u),f(v))\in E(H)$ 称 $f$ 为 $G$ 到 $H$ 的一个**同构**(isomorphism)，图是同构的(isomorphic)，记作 $G\cong H$ ，必须满足点数边数相同，结点度非增序列相同且存在同构导出子图。

图的交、并是点集、边集分别作交、并。图的和/直和 (sum/direct sum)是任意构造 $H'\cong H$ 使得 $V(H')\cap V_1=\emptyset$ ($H'$ 可以等于 $H$) ，此时与 $G\cup H'$ 同构的任何图叫做 $G$ 和 $H$ 的和/直和/不交并，记作 $G+H$ 或 $G\oplus H$ 。若点集本身不交，则 $G\cup H=G+H$ 。如森林是各树的和。可以理解为，“并”会让两张图中“名字相同”的点、边合并，而“和”则不会。

若 $E'\subseteq E$ 且 $\forall e\in(E\backslash E')$ 存在 $E'$ 中的边与其有公共点，称 $E'$ 是图 $G$ 的一个边支配集(edge dominating set)。若 $V'\subseteq V$ 且 $V'$ 中任意两点都不相邻，则 $V'$ 是一个**独立集**(independent set)。大小记作 $\alpha(G)$ 。若 $V'\subseteq V$ 且 $V'$ 任意两个不同顶点都相邻，则 $V'$ 是一个团(clique)，团的导出子图是完全图。如果一个团在加入任何一个顶点后都不再是一个团，则这个团是一个极大团 (Maximal clique)。最大团大小是 $w(G)$ ，满足 $w(G)=\alpha(\overline G)$ 。

求最大团、最小点覆盖、最大独立集、最小边支配、最小支配集是 NP 困难的，求完美匹配个数是 #P 完全的。

**网络**(流网络)(flow network)是有向图，边权为容量 $c$ capacity，有**源点**source和**汇点**sink。**流量** $f(u,v)$ 不超容量限制，反流量与其相加为零，源点流出流量等于汇点流入流量。网络流量是源点发出的流量和。**剩余容量**residual capacity $c_f(u,v)$ 为 $c(u,v)-f(u,v)$ 。剩余容量大于 $0$ 的边构成的子图是**残量网络** residual network $G_f$ 。**增广路** augmenting path：从源点到汇点所有边剩余容量大于零。**最小割**：删掉 $X$ 条边使得源点汇点不通，让 $X$ 条边加起来的流量总和最小。



### 最短路

最短路存在的条件为无负环。

#### floyd

全源最短路，适用于任何无负环的图。记得初始化为半倍max/极大值，留意重边

```c++
for (k = 1; k <= n; k++) 
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) 
      f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
```

第 $k$ 次循环时，表示只经过前 $k$ 个节点时，最短路的大小。记录路径可以获得更小时设 `pre[i][j]=k` 。

可以求最长路(输入负，输出再负一次)或者上述改为 max。

输出方案：

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mn = 1e2 + 10;
ll n, m, d[mn][mn], nx[mn][mn];
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    memset(d, 0x3f, sizeof d);
    for (ll i = 1; i <= n; ++i)
    {
        d[i][i] = 0, nx[i][i] = i;
    }
    for (ll i = 1, u, v, w; i <= m; ++i)
    {
        cin >> u >> v >> w;
        d[u][v] = w, nx[u][v] = v;
    }
    for (ll k = 1; k <= n; ++k)
    {
        for (ll i = 1; i <= n; ++i)
        {
            for (ll j = 1; j <= n; ++j)
            {
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    nx[i][j] = nx[i][k];
                }
            }
        }
    }
    ll q;
    cin >> q;
    for (ll u, v; q--;)
    {
        cin >> u >> v;
        cout << u << ' ';
        while (u != v)
        {
            cout << nx[u][v] << ' ';
            u = nx[u][v];
        }
        cout << '\n';
    }
    return 0;
}
```



应用：

> hdu1599-给定 $n(\le100)$ 点和 $m(\le10^3)$ 双向带权路，从任一点出发经过共至少 $3$ 个不同点然后回到该点成一个环，求最小带权环，无环输出 `It's impossible.`

环长等于 $d(a,b)+e(b,c)+e(c,a)$ ，枚举起点 $k$ ，跑 floyd 最短路。

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 101
ll n, m, f[mn][mn], e[mn][mn], ans, big = 1e9, u, v, w;
signed main()
{
    while (EOF != scanf("%lld%lld", &n, &m))
    {
        for (ll i = 1; i <= n; ++i)
            for (ll j = 1; j <= n; ++j)
                f[i][j] = e[i][j] = big;
        while (m--)
        {
            sc(u), sc(v), sc(w); //防重边
            e[u][v] = e[v][u] = f[u][v] = f[v][u] = min(e[u][v], w);
        }
        ans = big;
        for (ll k = 1; k <= n; ++k)
        {
            for (ll i = 1; i < k; ++i)
                for (ll j = i + 1; j < k; ++j)
                    ans = min(ans, f[i][j] + e[j][k] + e[k][i]);
            for (ll i = 1; i <= n; ++i)
                for (ll j = 1; j <= n; ++j)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        }
        ans == big ? printf("It's impossible.\n") : printf("%lld\n", ans);
    }
    return 0;
}
```



> poj3660-给定 $n(1\le n\le100)$ 点和 $m(1\le m\le4500)$ 关系，每个关系表示点 $u$ 优于点 $v$ ，问根据这些关系能确定多少个点的排名(保证无自环和环，无矛盾)

floyd跑传递闭包，得到可达矩阵。如果一个点同时被 $n-1$ 个点可达(无论是自己大于这些点还是这些点小于它)，就表明它的位置唯一确定， floyd 更新代码用：

```c++
f[i][j] |= (f[i][k] & f[k][j]);
```

如果用 bitset 优化，复杂度还可以达到 $O(\dfrac{n^3}w)$ ：

```c++
#include <cstdio>
#include <bitset>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 105
ll n, m, ans, u, v;
bitset<mn> f[mn];
signed main()
{
    sc(n), sc(m);
    while (m--)
        sc(u), sc(v), f[v][u] = 1;
    for (ll k = 1; k <= n; ++k)
        for (ll i = 1; i <= n; ++i)
            if (f[i][k])
                f[i] |= f[k];
    for (ll i = 1; i <= n; ++i)
    {
        ll cnt = 0;
        for (ll j = 1; j <= n; ++j)
            cnt += (f[i][j] | f[j][i]);
        ans += cnt == n - 1;
    }
    printf("%lld", ans);
    return 0;
}
```

拓展：如果要求出完整排序，可以判拓扑排序是否无环且能遍历到所有点，其完整排序就是拓扑排序序列



#### Bellman-Ford

不断尝试对图上每一条边进行松弛。我们每进行一轮循环，就对图上所有的边都尝试进行一次松弛操作，当一次循环中没有成功的松弛操作时，算法停止。复杂度 $O(nm)$ 。

可以求出有负权的图的最短路，并可以对最短路不存在的情况进行判断。最严谨的做法是建立一个超级源点，向图上每个节点连一条权值为 0 的边，然后以超级源点为起点执行 Bellman-Ford 算法。若第 n 轮迭代仍有结点的最短路能被更新，则图中有负环

> 洛谷P3385-多组样例，输入 $w$ 为正是无向边，负是有向边 ( $u\to v$ )，问是否存在从顶点 $1$ 出发可达的负环 $T\le10,1\le n\le2\times10^3,1\le m\le3\times10^3$ 

```c++
#include <bits/stdc++.h>
using namespace std;
const int N = 10010, big = 0x7fffffff;
int cnt = 0;
struct node
{
    int x, y, v;
} e[N];
void add(int x, int y, int v) { e[++cnt] = {x, y, v}; }
int n;
bool bellman()
{
    static int d[N];
    d[1] = 0;
    for (int i = 2; i <= n; i++)
        d[i] = big;
    for (int i = 1; i <= n - 1; i++)
        for (int j = 1; j <= cnt; j++)
        {
            if (d[e[j].x] != big &&
                d[e[j].x] + e[j].v < d[e[j].y])
                d[e[j].y] = d[e[j].x] + e[j].v;
        }
    for (int i = 1; i <= cnt; i++)
    {
        if (d[e[i].x] == big || d[e[i].y] == big)
            continue;
        if (d[e[i].x] + e[i].v < d[e[i].y])
            return true; // 负权回路
    }
    return false;
}
signed main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(e, 0, sizeof(e));
        cnt = 0;
        int m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            int x, y, v;
            scanf("%d%d%d", &x, &y, &v);
            if (v < 0)
                add(x, y, v);
            if (v >= 0)
                add(x, y, v), add(y, x, v);
        }
        if (bellman())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
```

若求最长路，可以设初始值为 $-1$ (或负无穷)，松弛反号(起点不为 $-1$ 可以继续)。



#### SPFA

队列优化的 SPFA(某些随机图跑得很快) ，用途是判负环。最坏情况仍然是 $O(nm)$ (<u>堆/栈优化</u>可以被卡指数级复杂度)。记录最短路经过了多少条边，当经过了至少 n 条边时，说明 s 点可以抵达一个负环。在没有负权边时最好使用 Dijkstra 算法。下面是负环模板：

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 2002
#define MAXM 6002
#define BIG (1 << 31) - 1
#define inita(a, n, v) for (int i = 0; i <= n; i++) a[i] = v
int n, m, hd[MAXN], cnt, d[MAXN], cnts[MAXN], ui, vi, wi, ttn;
bool vis[MAXN];
queue<int> q;
struct edege
{
    int to, d, nx;
} e[MAXM];
inline void adde(int u, int v, int w)
{
    e[++cnt].d = w;
    e[cnt].to = v;
    e[cnt].nx = hd[u];
    hd[u] = cnt;
}
void spfa()
{
    inita(d, n, BIG);
    inita(cnts, n, 0);
    inita(vis, n, false);
    while (!q.empty())
        q.pop();
    d[1] = 0;
    vis[1] = true;//表示当前点是否在队列内
    q.push(1);
    int u;
    while (!q.empty())
    {
        u = q.front();
        vis[u] = false;
        q.pop();
        for (int i = hd[u]; i != -1; i = e[i].nx)
        {
            if (d[u] + e[i].d < d[e[i].to])
            {
                d[e[i].to] = d[u] + e[i].d;
                if (!vis[e[i].to])
                {
                    if (++cnts[e[i].to] >= n)//该单源最短路的长度
                    {
                        printf("YES\n");
                        return;
                    }
                    vis[e[i].to] = true;
                    q.push(e[i].to);
                }
            }
        }
    }
    printf("NO\n");
    return;
}
int main()
{
    scanf("%d", &ttn);
    while (ttn--)
    {
        scanf("%d%d", &n, &m);
        cnt = -1;
        inita(hd, n, -1);
        while (m--)
        {
            scanf("%d%d%d", &ui, &vi, &wi);
            adde(ui, vi, wi);
            if (wi >= 0)
                adde(vi, ui, wi);
        }
        spfa();
    }
    return 0;
}
```

求负环并输出方案：

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mn = 5e3 + 10, big = 1e18;
ll n, m, d[mn], pr[mn];
struct edge
{
    ll u, v, w;
} e[mn * 2];
bool spfa(ll s)
{
    fill_n(d, n + 3, 1e18);
    d[s] = 0;
    for (ll i = 1; i <= n; ++i)
    {
        for (ll j = 1; j <= m; ++j)
        {
            ll u = e[j].u, v = e[j].v, w = e[j].w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pr[v] = j;
            }
        }
    }
    for (ll j = 1; j <= m; ++j)
    {
        ll u = e[j].u, v = e[j].v, w = e[j].w;
        if (d[v] > d[u] + w)
        {
            ll a = u;
            for (ll i = 1; i <= n; ++i)
            {
                a = e[pr[a]].u;
            }
            stack<ll> ans;
            ans.push(a);
            for (ll b = e[pr[a]].u; b != a; b = e[pr[b]].u)
            {
                ans.push(b);
            }
            cout << "exists\n"
                 << ans.size() << '\n';
            while (!ans.empty())
            {
                ll c = ans.top();
                ans.pop();
                cout << c << ' ';
            }
            return false;
        }
    }
    cout << "not exists\n";
    return true;
}
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m;
    for (ll i = 1, u, v, w; i <= m; ++i)
    {
        cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    for (ll i = 1; i <= n; ++i)
    {
        e[++m] = {0, i, 0};
    }
    spfa(0);
    return 0;
}
```



#### Dijkstra

非负权图适用。从未确定最短路点集里选最短路最小节点移到已知点集里，把已知点集节点出边松弛。稀疏图二叉堆更优，稠密图暴力做法更优。

暴力：(洛谷P3371) $O(n^2+m)$

```c++
#include <bits/stdc++.h>
#define MAXN 100002
#define MAXM 200002
#define BIG (1 << 31) - 1
using namespace std;
int n, m, s, ui, vi, wi, p[MAXN], d[MAXN];
vector<pair<int, int>> g[MAXN];
bool vis[MAXN];
void dijkstra()
{
    for (int i = 1; i <= n; i++)
        d[i] = BIG;
    d[s] = 0;
    int minv, minu;
    for (int h = 0; h + 1 < n; h++)
    {
        minv = BIG;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && d[i] < minv)
            {
                minv = d[i];//minv不能省略，否则minu可能不为正无穷若初始化min在点范围内
                minu = i;
            }
        }
        vis[minu] = true;
        for (auto i : g[minu])
        {
            if (!vis[i.first] && d[minu] + i.second < d[i.first])
            {
                d[i.first] = d[minu] + i.second;
            }
        }//如果只求d[t]可以vis[t]时break
    }
}
signed main()
{
    scanf("%d%d%d", &n, &m, &s);
    while (m--)
    {
        scanf("%d%d%d", &ui, &vi, &wi);
        g[ui].push_back({vi, wi});
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
        printf("%d ", d[i]);
    return 0;
}

```

优先级队列优化：(洛谷P4771) $O(m\log m)$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define big 0x3ffffffa
#define mn 100010
ll read() {ll r; scanf("%d", &r); return r; }
struct edge
{
    ll to, nx, w;
} e[mn << 1];
ll hd[mn], cnt, n, m, u, v, w, d[mn], s, vis[mn];
void adde(ll &u, ll &v, ll &w)
{
    e[++cnt] = {v, hd[u], w};
    hd[u] = cnt;
}
struct node
{
    ll i, d;
    bool operator<(const node &x) const { return d > x.d; }
};
priority_queue<node> q;
//priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> q;
signed main()
{
    n = read(), m = read(), s = read();
    for (ll i = 1; i <= m; ++i)
        u = read(), v = read(), w = read(), adde(u, v, w);
    memset(d, 127, sizeof d);
    d[s] = 0;
    q.push({s, 0});
    while (!q.empty())
    {
        node p = q.top();
        q.pop();
        if (vis[p.i])
            continue;
        vis[p.i] = true;
        for (ll i = hd[p.i]; i; i = e[i].nx)
        {
            ll toi = e[i].to;
            if (d[toi] > d[p.i] + e[i].w)
            {
                d[toi] = d[p.i] + e[i].w;
                q.push({toi, d[toi]});
            }
        }
    }
    for (ll i = 1; i <= n; ++i)
        printf("%d ", d[i]);
    return 0;
}
```

如果要输出路径本身，那么每次松弛时让 $v$ 指向起点 $u$ ；然后从终点倒序遍历这个指向数组，然后再顺着输出。如果要计数最短路数目，或求最短时点权最值最大的路径等，也在松弛时修改。(==时不用push)

可以修改松弛条件，来求别的最短路，如路径最大边权最小的路：(也可以最小生成树上DFS)(SCNUOJ1458 / lc1631)
$$
dis[j]=\min(dis[j],\max(dis[mink],ma[mink][j]))
$$
同理最大边权最大的最短路取 $dis=\infty$ ($dis_0=0$) 且：(lc1631)

```c++
if(max(dist[u], w) < dist[v]) dist[v] = max(dist[u], w)
```



非负权图跑 $n$ 次可以实现全源最短路，复杂度 $O(nm\log m)$ 。不能求单源最长路。



> lc2699-给定 $n(\le100)$ 点稠密图，有一些边边权不确定($-1$)，给出一种构造正边权方案，使得指定的两点单源最短路为特定值

> 解法一：无解的充要条件：①所有边赋 1 无解；②所有边赋无穷无解。
>
> 设在上述第一种情况跑出来的 $source$ 单源最短路是 $d_{i,0}$，当有解时，根据 dijkstra 的特性，只要按照 dijkstra 遍历顺序去修改边，就不会在修改后对已确定的最短路产生影响。
>
> 所以在第一种情况下，再跑一遍 dijkstra，此时跑出的结果为 $d_{i,1}$，对可修改的边 $(u,v)$，设边权改为 $w$，则所求路径 $s\to \cdots\to x\to y\to\cdots\to t$ 由三部分组成：
>
> 1. $d_{x,1}$ 即 $s\to\cdots\to x$
>
> 2. $x\to y = w$
>
> 3. $y\to\cdots\to t$，如果 $y$ 确实在最短路上，对所有边赋 $1$ 的最短路是 $d_{t,0}$，其在后半段的最短路长度可以直接路径相减，即 $d_{t,0}-d_{y,0}$。
>
>    如果 $y$ 不在最短路上，那么这次修改无效，可以直接忽略修改。
>
> 要满足题意，即构造 $d_{x,1}+w+d_{t,0}-d_{y,0}=target$，即 $w=target-d_{t,0}+d_{y,0}-d_{x,1}$。

解法二：设可修改的边的权列表是 $w$，为书写方便令 $D=target$，则 $w$ 的所有可能性不超过 $O(D^2)$ 种，分别为：$[1,1,\cdots,1],[2,1,\cdots,1],\cdots,[D,1,\cdots,1],[D,2,\cdots,1],\cdots[D,D,\cdots,D]$ 种。

注意到 $[1,D,\cdots,1]$ 这样的可能性不计，这是因为只用上述顺序在有解的情况下一定可以构造出，且每次增加总 $\sum w$ 为 $1$ 下，最多只增加 $1$ 的答案最短路长度。也就是说不需要指数级的所有可能性都枚举出来，只需要枚举所有可能性的一个特定 $D^2$ 子集就一定能覆盖到有解的情况。

复杂度为 $O(2\log Dn^2)$。

#### Johnson

复杂度 $O(nm\log m)$ ，适用于所有图，能判负环

> 洛谷P5905-有向，可能负边权、自环重边、卡SPFA $n(1\le n\le3\times10^3),m(1\le n\le6\times10^3,|w|\le3\times10^5)$ ，若负环输出 $-1$ ，否则输出 $n$ 行，设最短路为 $dis_{i,j}$ ，输出 $\sum_{j=1}^nj\times dis_{i,j}$ 。不存在路径设 $dis_{i,j}=10^9$  ，$dis_{i,i}=0$ 

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define MAXN 5006
#define BIG 1000000000
struct edge { ll to, nx, w; } e[MAXN<<1];
struct node
{
	ll d, i;
	bool operator<(const node& x)const { return d > x.d; }
	node(ll x, ll y) { d = x, i = y; }
};
ll hd[MAXN], t[MAXN], cnt, n, m, h[MAXN], dis[MAXN], ui, vi, wi, ans;
bool vis[MAXN];
inline void adde(ll& u, ll& v, ll& w)
{
	e[++cnt] = { v,hd[u],w };
	hd[u] = cnt;
}
inline bool spfa(ll x)
{
	queue<ll> q;
	memset(h, 63, sizeof h);
	h[x] = 0, vis[x] = true; q.push(x);
	while (!q.empty())
	{
		ll y = q.front(); q.pop();
		vis[y] = false;
		for (ll i = hd[y]; i; i = e[i].nx)
		{
			ll z = e[i].to;
			if (h[z] > h[y] + e[i].w)
			{
				h[z] = h[y] + e[i].w;
				if (!vis[z])
				{
					vis[z] = true, ++t[z];
					q.push(z);
					if (t[z] > n) return false;
				}
			}
		}
	}
	return true;
}
inline void dijkstra(ll x)
{
	priority_queue<node> q;
	repe(i, 1, n) dis[i] = BIG;
	memset(vis, 0, sizeof vis);
	dis[x] = 0;
	q.push(node(0, x));
	while (!q.empty())
	{
		ll u = q.top().i; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (ll i = hd[u]; i; i = e[i].nx)
		{
			ll v = e[i].to;
			if (dis[v] > dis[u] + e[i].w)
			{
				dis[v] = dis[u] + e[i].w;
				if (!vis[v]) q.push(node(dis[v], v));
			}
		}
	}
}
signed main()
{
	scanf("%lld%lld", &n, &m);
	repe(i, 1, m) scanf("%lld%lld%lld", &ui, &vi, &wi), adde(ui, vi, wi);
	repe(i, 1, n) adde(ans, i, ans);
	if (!spfa(0)) return !printf("-1");
	repe(u, 1, n) for (ll i = hd[u]; i; i = e[i].nx)
		e[i].w += h[u] - h[e[i].to];
	repe(i,1,n)
	{
		dijkstra(i);
		ans = 0;
		repe(j, 1, n)
		{
			if (dis[j] == BIG) ans += j * BIG;
			else ans += j * (dis[j] + h[j] - h[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
```



#### 差分约束

对 $n$ 个变量 $x_i$ 和 $m$ 个不等式 $x_i-x_j\le c_k,c_k\in R$，求一组解 $x$ 使得每个不等式都满足，或者判断无解。

将其变为 $x_i\le x_j+c_k$，联想单源最短路三角不等式，所以对每个约束条件构造 $j\to i$ 的权为 $c_k$ 的有向边，且建立超级源点 $x_0$ 向每个点连权为 $0$ 的边。若负环无解，否则最短路数组 $-d$ 是一组解，这组解是最小的。注意到若 $x$ 是合法解，则 $x+C$ 也是合法解。用 Bellman-Ford / SPFA 即可，都是 $O(nm)$。

构造技巧：

1. 如果有约束条件 $x_i=y_i$，等价于两个约束条件 $x_i\le y_i+0,y_i\le x_i+0$
2. 如果有约束条件 $\dfrac{x_i}{x_j}\le c_k$，等价于 $\log x_i-\log x_j\le\log c_k$
3. 反向差分约束，即全部改为 $x_i\ge x_j+c_k$ 连 $j\to i$ 的 $c_k$ 才能有超级源点的图，求最大的跑该不等式的 SPFA 最长路(类似于工程图最晚)，一般用于求最小解
4. 要求 $\max(x_v-x_u)$，等价于求 $u$ 到 $v$ 的最短路；要求 $\min(x_v-x_u)$ 求 $u$ 到 $v$ 最长路(建的图不一样)

> P1260-给定 $n$ 个变量 $t$ 和 $m$ 个不等式 $t_i-t_j\le b$。问能否构造出 $t$ 或输出无解。输出构造非负解且至少一个 $0$。$n\le 10^3,m\le 5\times10^3,b\in(-100,100)$。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mn = 5e3 + 10, inf = 1e9;
ll n, d[mn], m, vis[mn], cnt[mn];
vector<pair<ll, ll>> e[mn];
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m;
    for (ll i = 1, a, b, c; i <= m; ++i)
    {
        cin >> a >> b >> c;
        e[b].push_back({a, c});
    }
    for (ll i = 1; i <= n; ++i)
    {
        e[0].push_back({i, 0});
    }
    fill_n(d, n + 3, inf);
    d[0] = 0, vis[0] = true;
    queue<ll> q;
    q.push(0);
    while (!q.empty())
    {
        ll u = q.front();
        vis[u] = false;
        q.pop();
        for (auto pr : e[u])
        {
            ll v = pr.first, w = pr.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if (!vis[v])
                {
                    if (++cnt[v] >= n + 1)
                    {
                        printf("NO SOLUTION\n");
                        return 0;
                    }
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    ll mi = *min_element(d + 1, d + 1 + n);
    for (ll u = 1; u <= n; ++u)
    {
        cout << d[u] - mi << '\n';
        for (auto pr : e[u])
        {
            ll v = pr.first, w = pr.second;
            assert(d[v] <= d[u] + w);
        }
    }
    return 0;
}
```

> 附：差分约束 P5960 模板题代码 (输入输出与本题类似，但任意解即可)
>
> ```c++
> struct edge { ll u, v, w; } e[MAXN];
> ll d[MAXN], n, m, c0, c1, y;
> signed main()
> {
> 	scanf("%d%d", &n, &m);
> 	repe(i, 1, m) scanf("%d%d%d", &c0, &c1, &y), e[i] = { c1,c0,y };
> 	repe(i, 1, n) d[i] = (i == 1 ? 0 : 0x3f3f3f3f);
> 	rep(i, 1, n) repe(j, 1, m) 
> 		d[e[j].v] = min(d[e[j].u] + e[j].w, d[e[j].v]);
> 	repe(i, 1, m) if (d[e[i].v] > d[e[i].u] + e[i].w)
> 		return !printf("NO");
> 	repe(i, 1, n) printf("%d ", d[i]);
> 	return 0;
> }
> ```





### 拓扑排序

有向图存在环则无法进行拓扑排序。通常用的为 Kahn 算法，复杂度 $O(E+V)$ 

下面程序判断有向图是否有环(含考虑非连通、自环、重边)

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 5010
typedef long long ll;
struct edge
{
    ll to, nx;
} e[500010];
ll hd[mn], n, cnt, m, ru[mn];
void adde(ll u, ll v)
{
    e[++cnt] = {v, hd[u]};
    hd[u] = cnt, ++ru[v];
}
#define sc(x) scanf("%lld", &x)
queue<ll> q;
vector<ll> vis;
signed main()
{
    sc(n), sc(m);
    for (ll i = 1, u, v; i <= m; ++i)
    {
        sc(u), sc(v), adde(u, v);
    }
    for (ll i = 1; i <= n; ++i)
    {
        if (ru[i] == 0)
        {
            q.push(i);
        }
    }
    if (q.empty())
    {
        return printf("YE5"), 0;
    }
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        vis.emplace_back(u);
        for (ll i = hd[u], v; i; i = e[i].nx)
        {
            v = e[i].to;
            --ru[v];
            if (!ru[v])
            {
                q.push(v);
            }
        }
    }
    return printf((ll)vis.size() == n ? "N0" : "YE5"), 0;
}
```

如果要判无向图的环，把上面初始度(出+入)为 $1$ 的入队，当度剩 $1$ 时继续入队，最后剩 $2$ 度的在一个环内(如下蓝桥-发现环例题：求基环树环上所有节点编号)(也可以DFS做，遍历记录深度和prev，发现浅于自己的就不断走prev)

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 100010
struct edge
{
    ll to, nx;
    edge(ll a = 0, ll b = 0) : to(a), nx(b) {}
} e[mn * 2];
ll hd[mn], cnt, n, m, du[mn];
void adde(ll u, ll v)
{
    e[++cnt] = edge(v, hd[u]);
    ++du[v], hd[u] = cnt;
}
signed main()
{
    sc(n);
    for (ll i = 1, u, v; i <= n; ++i)
        sc(u), sc(v), adde(u, v), adde(v, u);
    queue<ll> q;
    for (ll i = 1; i <= n; ++i)
        if (du[i] == 1)
            q.push(i);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (ll i = hd[u], v; i; i = e[i].nx)
        {
            v = e[i].to;
            if (--du[v] == 1)
                q.push(v);
        }
    }
    for (ll i = 1; i <= n; ++i)
        if (du[i] == 2)
            printf("%lld ", i);
    return 0;
}
```

将队列改成最大堆/最小堆可以 $O(E+V\log V)$ 实现字典序最大/最小的拓扑排序

拓扑排序可以求(从入度0开始的点的)有向图单源最长路。对其他同样入度 $0$ 的点，先把它们 BFS 一次删掉(预拓扑删掉它们带来的路径)



### 最小生成树

#### kruskal

$O(m\log m)$ (在排序上)复杂度，对稀疏图较好，反向排序可以最大生成树，可以判无解

(例题洛谷P3366)

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 5010
#define me 200010
struct edge
{
    ll u, v, w;
    bool operator<(const edge &r) const { return w < r.w; }
} e[me];
ll fa[mn], n, m, suc, ans;
ll findf(ll x)
{
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}
signed main()
{
    sc(n), sc(m);
    for (ll i = 1; i <= m; ++i)
        sc(e[i].u), sc(e[i].v), sc(e[i].w);
    sort(e + 1, e + 1 + m);
    for (ll i = 1; i <= n; ++i)
        fa[i] = i;
    for (ll i = 1, fu, fv; i <= m && suc <= n - 1; ++i)
    {
        fu = findf(e[i].u), fv = findf(e[i].v);
        if (fu != fv) //sol += u,v
            fa[fu] = fv, ans += e[i].w, ++suc;
    }
    suc == n - 1 ? printf("%lld", ans) : printf("orz");
    return 0;
}
```

部分应用示例：

- (SCNUOJ1124)求最长边与最短边差值最小的最小生成树 

  每次从第 $i$ 短边开始跑 Kruskal ，必然贪心地得到当前第 $i$ 短时最小的最长边。复杂度为 $O(m\log m+m^2)=O(m^2)$ 

- (洛谷P4047) 给定 $n$ 点聚为 $m$ 类，求两类间最短距离最大值

  跑 Kruskal 直到还剩 $m$ 个连通块，此时生成树下一条边长就是答案



#### prim

暴力 $O(n^2+m)$ ，二叉堆优化 $O((n+m)\log n)$ ， Fib 堆 $O(n\log n+m)$ 

暴力：(适合完全图) (洛谷P1265 求坐标轴上点的最小生成树)

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const ll mn = 5e3 + 10;
ll n, x[mn], y[mn], suc, vis[mn];
db d[mn], ans;
ll sol[mn]; //如果要输出方案
signed main()
{
    cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> x[i] >> y[i];
        d[i] = 1e21;
    }
    d[1] = 0;
    for (ll t = 1; t <= n - 1; ++t)
    {
        ll a = 0;
        for (ll j = 1; j <= n; ++j)
        {
            if (!vis[j] && (!a || d[j] < d[a]))
            {
                a = j;
            }
        }
        vis[a] = true;
        for (ll b = 1; b <= n; ++b)
        {
            if (!vis[b])
            {
                db dis = sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
                if (dis < d[b])
                {
                    d[b] = dis;
                    // sol[b] = a;
                }
            }
        }
    }
    for (ll i = 1; i <= n; ++i)
    {
        ans += d[i];
        // cout << i << ' ' << sol[i] << '\n'; [2,n] 有效
    }
    printf("%.2lf", ans);
    return 0;
}
```

二叉堆：

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 5010
#define me 200010
struct
{
    ll to, nx, w;
} e[me * 2];
ll hd[mn], cnt, d[mn], ans, suc, n, m, vis[mn];
void adde(ll u, ll v, ll w)
{
    e[++cnt] = {v, hd[u], w};
    hd[u] = cnt;
}
typedef pair<ll, ll> pr; // first:w, second:i
priority_queue<pr, vector<pr>, greater<pr>> q;
signed main()
{
    sc(n), sc(m);
    for (ll i = 1, u, v, w; i <= m; ++i)
        sc(u), sc(v), sc(w), adde(u, v, w), adde(v, u, w);
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    q.push({0, 1});
    while (!q.empty() && suc <= n - 1)
    {
        ll w = q.top().first, u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        ans += w, vis[u] = true, ++suc;
        for (ll i = hd[u], v; i; i = e[i].nx)
        {
            v = e[i].to;
            if (e[i].w < d[v]) //sol[v]=u;
                d[v] = e[i].w, q.push({d[v], v});
        }
    }
    suc == n ? printf("%lld", ans) : printf("orz");
    return 0;
}
```



#### Borůvka

可以用于求解边权互不相同的无向图的最小生成森林。权值相同会导致两个连通块互相连的时候出现环，那么此时就需要再按照另一个维度严格排序，常用标号大小排序。即边权相同时，认为编号小的边短。复杂度 $O(m\log n)$ ，每次迭代连通块数量至少减半。

```c++
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 5000 + 5, MaxM = 200000 + 5;

int N, M;
int U[MaxM], V[MaxM], W[MaxM];
bool used[MaxM];
int par[MaxN], Best[MaxN];

void init() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= M; ++i)
        scanf("%d %d %d", &U[i], &V[i], &W[i]);
}

void init_dsu() {
    for (int i = 1; i <= N; ++i)
        par[i] = i;
}

int get_par(int x) {
    if (x == par[x]) return x;
    else return par[x] = get_par(par[x]);
}

inline bool Better(int x, int y) {
    if (y == 0) return true;
    if (W[x] != W[y]) return W[x] < W[y];
    return x < y;
}

void Boruvka() {
    init_dsu();

    int merged = 0, sum = 0;

    bool update = true;
    while (update) {
        update = false;
        memset(Best, 0, sizeof Best);

        for (int i = 1; i <= M; ++i) {
            if (used[i] == true) continue;
            int p = get_par(U[i]), q = get_par(V[i]);
            if (p == q) continue;

            if (Better(i, Best[p]) == true) Best[p] = i;
            if (Better(i, Best[q]) == true) Best[q] = i;
        }

        for (int i = 1; i <= N; ++i)
            if (Best[i] != 0 && used[Best[i]] == false) {
                update = true;
                merged++; sum += W[Best[i]];
                used[Best[i]] = true;
                par[get_par(U[Best[i]])] = get_par(V[Best[i]]);
            }
    }

    if (merged == N - 1) printf("%d\n", sum);
    else puts("orz");
}

int main() {
    init();
    Boruvka();
    return 0;
}
```



#### 严格次小生成树

> 洛谷P4180-可能含自环， $n\le10^5,m\le3\times10^5$ ，保证有解，边权 $[0,10^9]$ ，求严格次小生成树权值和

复杂度为 $O(m\log m)$ ，解法是 Kruskal + LCA + 倍增

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 400010
#define ml 19
#define big 0x7fffffffffffff
struct edge
{
    ll u, v, w, nx;
    bool operator<(const edge &x) const { return w < x.w; }
} e[mn << 1], a[mn << 1];
ll cnt, hd[mn], fa[mn][ml], mx[mn][ml], nd[mn][ml], dep[mn], n, m, ffa[mn];
bool vis[mn << 1];
void adde(ll &u, ll &v, ll &w)
{
    e[++cnt] = {u, v, w, hd[u]};
    hd[u] = cnt;
}
void dfs(ll u, ll f)
{
    fa[u][0] = f;
    for (ll i = hd[u]; i; i = e[i].nx)
    {
        ll v = e[i].v;
        if (v == f)
        {
            continue;
        }
        dep[v] = dep[u] + 1;
        mx[v][0] = e[i].w;
        nd[v][0] = -big;
        dfs(v, u);
    }
}
void cal()
{
    for (ll i = 1; i < ml; ++i)
    {
        for (ll j = 1; j <= n; ++j)
        {
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
            mx[j][i] = max(mx[j][i - 1], mx[fa[j][i - 1]][i - 1]);
            nd[j][i] = max(nd[j][i - 1], nd[fa[j][i - 1]][i - 1]);
            if (mx[j][i - 1] != mx[fa[j][i - 1]][i - 1])
            {
                nd[j][i] = max(nd[j][i], min(mx[j][i - 1], mx[fa[j][i - 1]][i - 1]));
            }
        }
    }
}
ll lca(ll x, ll y)
{
    if (dep[x] < dep[y])
    {
        swap(x, y);
    }
    for (ll i = ml - 1; i >= 0; --i)
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
    for (ll i = ml - 1; i >= 0; --i)
    {
        if (fa[x][i] ^ fa[y][i])
        {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}
ll qmax(ll u, ll v, ll mxv)
{
    ll ans = -big;
    for (ll i = ml - 1; i >= 0; --i)
    {
        if (dep[fa[u][i]] >= dep[v])
        {
            if (mxv != mx[u][i])
            {
                ans = max(ans, mx[u][i]);
            }
            else
            {
                ans = max(ans, nd[u][i]);
            }
            u = fa[u][i];
        }
    }
    return ans;
}
ll finds(ll x)
{
    while (x != ffa[x])
    {
        x = ffa[x] = ffa[ffa[x]];
    }
    return x;
}
signed main()
{
    sc(n), sc(m);
    for (ll i = 1; i <= m; ++i)
    {
        sc(a[i].u), sc(a[i].v), sc(a[i].w);
    }
    sort(a + 1, a + 1 + m);
    for (ll i = 1; i <= n; ++i)
    {
        ffa[i] = i;
    }
    ll suc = 0, res = big;
    for (ll i = 1; i <= m; ++i)
    {
        ll fu = finds(a[i].u), fv = finds(a[i].v);
        if (fu != fv)
        {
            suc += a[i].w;
            ffa[fu] = fv, vis[i] = true;
            adde(a[i].u, a[i].v, a[i].w), adde(a[i].v, a[i].u, a[i].w);
        }
    }
    nd[1][0] = -big, dep[1] = 1;
    dfs(1, -1), cal();
    for (ll i = 1, u, v, w, ca, mxu, mxv; i <= m; ++i)
    {
        if (!vis[i])
        {
            u = a[i].u, v = a[i].v, w = a[i].w;
            ca = lca(u, v);
            mxu = qmax(u, ca, w), mxv = qmax(v, ca, w);
            res = min(res, suc - max(mxu, mxv) + w);
        }
    }
    printf("%lld", res);
    return 0;
}
```

注：下述代码的 85-92 行改为 `ans = max(ans, mx[u][i]);` 即求非严格的次小生成树的代码。非严格次小生成树与最小生成树权值是否相同可以判断最小生成树是否唯一。(POJ1679) (对较小数据，可以暴力：)

> ```c++
> #include<cmath>
> #include<cstring>
> #include<cstdio>
> #include<algorithm>
> using namespace std;
> const int qq=110;
> const int MAX=1e8+5;
> int n,m;
> int vis[qq];
> int dis[qq];
> int map[qq][qq];
> int maxn[qq][qq];	//记录最小生成树中点i到点j的最大距离、 
> int use[qq][qq];	//记录每一条边是否被使用过、 
> int pre[qq];
> int Prim()
> {
> 	memset(vis,0,sizeof(vis));
> 	memset(use,0,sizeof(use));
> 	memset(maxn,0,sizeof(maxn)); 
> 	for(int i=1; i<=n; ++i)	dis[i]=map[1][i],pre[i]=1;
> 	vis[1]=1;
> 	dis[1]=0;
> 	pre[1]=-1; 
> 	int ans=0,minx,k;
> 	for(int i=1; i<n; ++i){
> 		minx=MAX;
> 		for(int j=1; j<=n; ++j)
> 			if(!vis[j] && dis[j]<minx)
> 				minx=dis[k=j];
> 		if(minx==MAX)	return -1; 
> 		ans+=minx;
> 		use[k][pre[k]]=use[pre[k]][k]=1;
> 		vis[k]=1;
> 		for(int j=1; j<=n; ++j){
> 			if(vis[j])	maxn[j][k]=maxn[k][j]=max(dis[k],maxn[j][pre[k]]);
> 			if(!vis[j] && map[k][j]<dis[j])
> 				pre[j]=k,dis[j]=map[k][j];
> 		}
> 	}
> 	return ans;
> }
> int main()
> {
> 	int t;scanf("%d",&t);
> 	while(t--){
> 		scanf("%d%d",&n,&m);
> 		int u,v,w;
> 		for(int i=0; i<=n; ++i)
> 			for(int j=0; j<=n; ++j)	
> 				if(i!=j)	map[i][j]=MAX;
> 				else map[i][j]=0; 
> 		for(int i=0; i<m; ++i){
> 			scanf("%d%d%d",&u,&v,&w);
> 			map[u][v]=map[v][u]=w;
> 		}
> 		int ans=Prim();
> 		if(ans==-1){
> 			printf("Not Unique!\n");
>             continue;
> 		}
> 		int Min=MAX;
> 		for(int j,i=1; i<=n; ++i)
> 			for(j=i+1; j<=n; ++j)
> 				if(!use[i][j] && map[i][j]!=MAX)
> 					Min=min(Min,ans-maxn[i][j]+map[i][j]);
> 		if(Min==ans)	printf("Not Unique!\n");
> 		else	printf("%d\n",ans);
> 	}
> 	return 0;
> }
> ```



### 连通性

#### 连通分量

无向图求连通分量：并查集 / DFS $O(n+m)$

有向图求强联通分量：Tarjan 算法  $O(n+m)$

求无向图割点：$u$ 为割点当① $u$ 非根节点且 $\exists low_v\ge dfn_u$ ② $u$ 为根节点且儿子不少于 $2$ 个

求无向图桥：修改 low ，限定非树边不能是子到父的反向边时，如果 p 是 q 的父节点，并且  $low_q\ge dfn_p$ ，那么 $p\leftrightarrow q$ 是桥

有向图环缩点重建图：跑完 tarjan 后枚举边，不在同一强连通分量的在缩点图上连新边

> 可以解决：求有向图可重复走边/点的最长路 (缩点图跑拓扑排序求最长路)



##### 强连通分量

> 洛谷P2863-给定有向图，求点数大于 $1$ 的强连通分量的个数

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN = 2e4 + 10, MAXM = 2e5 + 10;
struct edge
{
    ll to, nx;
} e[MAXM];
ll hd[MAXN], cnt, n, m, dfn[MAXN], low[MAXN], co[MAXN], num[MAXN], conum, st;
bool vis[MAXN];
stack<ll> s;
void adde(ll &u, ll &v)
{
    e[++cnt] = {v, hd[u]};
    hd[u] = cnt;
}
void paint(ll &x)
{
    s.pop();
    co[x] = conum;  //点x属于第conum个分量
    ++num[conum];   //该分量有多少点
    vis[x] = false; //出栈
}
void tarjan(ll x)
{
    dfn[x] = low[x] = ++st;
    s.push(x);
    vis[x] = true;
    for (ll i = hd[x]; i; i = e[i].nx)
    {
        ll toi = e[i].to;
        if (!dfn[toi]) //小心别写成x
        {
            tarjan(toi); //小心别写成x
            low[x] = min(low[x], low[toi]);
        }
        else if (vis[toi])
            low[x] = min(low[x], dfn[toi]);
    }
    if (low[x] == dfn[x])
    {
        ++conum;
        while (s.top() != x)
            paint(s.top());
        paint(x);
    }
}
signed main()
{
    ll ui, vi, ans = 0;
    scanf("%d%d", &n, &m);
    while (m--)
        scanf("%d%d", &ui, &vi), adde(ui, vi);
    for (ll i = 1; i <= n; ++i)
        if (!dfn[i])
            tarjan(i);
    for (ll i = 1; i <= conum; ++i)
        if (num[i] > 1)
            ++ans;
    printf("%d", ans);
    return 0;
}
```



##### 割点

> 洛谷P3388-无向图(不保证连通)求割点数和按编号顺序输出每个割点

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define MAXN 20002
#define MAXM 100002
struct edge
{
    ll to, nx;
} e[MAXM << 1];
ll n, m, idx, cnt, tot, hd[MAXN], dfn[MAXN], low[MAXN], ui, vi;
bool cut[MAXN];
inline void adde(ll &x, ll &y)
{
    e[++cnt] = {y, hd[x]};
    hd[x] = cnt;
}
void tarjan(ll u, ll fa)
{
    dfn[u] = low[u] = ++idx;
    ll child = 0;
    for (ll i = hd[u]; i; i = e[i].nx)
    {
        ll toi = e[i].to;
        if (!dfn[toi]) //尚未访问
        {
            tarjan(toi, fa);
            low[u] = min(low[u], low[toi]);
            if (low[toi] >= dfn[u] && u != fa)
                cut[u] = true;
            if (u == fa)
                ++child;
        }
        low[u] = min(low[u], dfn[toi]);
    }
    if (child >= 2) // u == fa
        cut[u] = true;
}
signed main()
{
    scanf("%d%d", &n, &m);
    while(m--)
        scanf("%d%d", &ui, &vi), adde(ui, vi), adde(vi, ui);
    for(ll i = 1; i <= n; ++i) if (!dfn[i]) tarjan(i, i);
    for(ll i = 1; i <= n; ++i) if (cut[i]) ++tot;
    printf("%d\n", tot);
    for(ll i = 1; i <= n; ++i) if (cut[i]) printf("%d ", i);
    return 0;
}
```



##### 桥

> UVA796-求有向图桥数量并按字典序输出每个桥的端点

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 100010
#define mm 2000010
struct edge
{
    ll to, nx;
} e[mm * 2];
ll hd[mn], cnt, n, ans, dfn[mn], low[mn], st;
vector<pair<ll, ll>> res;
void adde(ll u, ll v)
{
    e[++cnt] = {v, hd[u]};
    hd[u] = cnt;
}
void tarjan(ll u, ll fa)
{
    dfn[u] = low[u] = ++st;
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (v != fa)
        {
            if (!dfn[v])
            {
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u])
                    ++ans, res.emplace_back(min(u, v), max(u, v));
            }
            else
                low[u] = min(low[u], dfn[v]);
        }
    }
}
signed main()
{
    while (EOF != scanf("%lld", &n))
    {
        cnt = ans = st = 0, res.clear();
        for (ll i = 1, m, u, v; i <= n; ++i)
        {
            hd[i] = 0, dfn[i] = low[i] = 0;
            scanf("%lld (%lld)", &u, &m), ++u;
            while (m--)
                scanf("%lld", &v), ++v, adde(u, v);
        }
        for (ll i = 1; i <= n; ++i)
            if (!dfn[i])
                tarjan(i, i);
        sort(res.begin(), res.end());
        printf("%lld critical links\n", ans);
        for (auto &i : res)
            printf("%lld - %lld\n", i.first - 1, i.second - 1);
        putchar('\n');
    }
    return 0;
}
```



##### 点双连通分量

> P8435 $n(\le5\times10^5)$ 点 $m(\le2\times10^6)$ 边无向图，找出点双数量，输出每个点双的点

点双定义见下文圆方树

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mn = 5e5 + 10;
ll n, m, dfn[mn], low[mn], st, stk[mn], stop, cn;
vector<ll> c[mn], g[mn];
void tarjan(ll u, ll fa)
{
    ll son = 0;
    dfn[u] = low[u] = ++st;
    stk[++stop] = u;
    for (auto v : g[u])
    {
        if (!dfn[v])
        {
            ++son;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u])
            {
                c[++cn].push_back(u);
                for (ll w = 0; w != v;)
                {
                    w = stk[stop--];
                    c[cn].push_back(w);
                }
            }
        }
        else
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (!fa && !son)
    {
        c[++cn].push_back(u);
    }
}
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m;
    for (ll i = 1, u, v; i <= m; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    for (ll i = 1; i <= n; ++i)
    {
        if (!dfn[i])
        {
            stop = 0, tarjan(i, 0);
        }
    }
    cout << cn << '\n';
    for (ll i = 1; i <= cn; ++i)
    {
        cout << c[i].size() << ' ';
        for (auto u : c[i])
        {
            cout << u << ' ';
        }
        cout << '\n';
    }
    return 0;
}

```





##### 边双连通分量

定义为无向图上没有桥的极大连通图。

> 牛客暑假7-L 给定带互异边权 $[-10^9,10^9]$ 的无向连通图 $3\le n\le m\le10^5$，求环上边权最大最小值差最大的差值，并以任意顺序时针输出该环

找环 $O(n)$，就是在边双上找最大和最小。然后用网络流输出方案。

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
const ll mn = 1e5 + 10;
ll n, m, hd[mn], cnt, w[mn], eu[mn], ev[mn];
struct edge
{
    ll to, nx, idx, w = 0, isbridge = false;
} e[mn * 2], e2[mn * 2];
ll st, dfn[mn], low[mn], dcnt, vis[mn];
vector<ll> dcc[mn]; //边双
ll hd2[mn], cnt2, h[mn], d[mn], cur[mn];
signed main()
{
    sc(n), sc(m);
    auto adde = [&](ll u, ll v, ll w, ll idx)
    {
        e[++cnt] = {v, hd[u], idx};
        hd[u] = cnt;
        ::w[idx] = w, eu[idx] = u, ev[idx] = v;
    };
    for (ll i = 1, u, v, w; i <= m; ++i)
    {
        sc(u), sc(v), sc(w), adde(u, v, w, i), adde(v, u, w, i);
    }
    auto tarjan = [&](auto self, ll u, ll fa) -> void
    {
        dfn[u] = low[u] = ++st;
        for (ll i = hd[u]; i; i = e[i].nx)
        {
            ll v = e[i].to, idx = e[i].idx;
            if (!dfn[v])
            {
                self(self, v, u);
                low[u] = min(low[u], low[v]);
                if (dfn[u] < low[v])
                {
                    e[idx].isbridge = true;
                }
            }
            else if (v != fa)
            {
                low[u] = min(low[u], dfn[v]);
            }
        }
    };
    tarjan(tarjan, 1, 0);
    auto dfs = [&](auto self, ll u) -> void
    {
        vis[u] = true;
        for (ll i = hd[u]; i; i = e[i].nx)
        {
            ll v = e[i].to, idx = e[i].idx;
            if (!e[idx].isbridge)
            {
                dcc[dcnt].push_back(idx);
                if (!vis[v])
                {
                    self(self, v);
                }
            }
        }
    };
    for (ll i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            ++dcnt;
            dfs(dfs, i);
        }
    }
    ll res = -1, id = 0;
    for (ll i = 1; i <= dcnt; ++i)
    {
        sort(dcc[i].begin(), dcc[i].end());
        dcc[i].erase(unique(dcc[i].begin(), dcc[i].end()), dcc[i].end());
        sort(dcc[i].begin(), dcc[i].end(), [&](ll u, ll v)
             { return w[u] < w[v]; });
        if (dcc[i].size() >= 2)
        {
            ll x = w[dcc[i].back()] - w[dcc[i].front()];
            if (x > res)
            {
                res = x, id = i;
            }
        }
    }
    printf("%lld\n", res);

    //网络流是有向图，所以要重建图
    memset(hd2, -1, sizeof hd2);
    ll s = n + 1, t = n + 2, mxi = dcc[id].back(), mii = dcc[id].front();
    auto adde2 = [&](ll u, ll v, ll w = 1)
    {
        e2[cnt2] = {v, hd2[u], 0, w};
        hd2[u] = cnt2++;
    };
    adde2(s, eu[mxi]), adde2(eu[mxi], s, 0); //注意顺序
    adde2(s, ev[mxi]), adde2(ev[mxi], s, 0);
    adde2(eu[mii], t), adde2(t, eu[mii], 0);
    adde2(ev[mii], t), adde2(t, ev[mii], 0);
    for (auto i : dcc[id])
    {
        if (i != mxi && i != mii)
        {
            adde2(eu[i], ev[i]), adde2(ev[i], eu[i]);
        }
    }

    auto dinic_dfs = [&](auto self, ll u, ll limit) -> ll
    {
        // printf("<%lld %lld\n", u, limit);
        if (u == t)
        {
            return limit;
        }
        ll flow = 0;
        for (ll i = cur[u]; i != -1 && flow < limit; i = e2[i].nx)
        {
            cur[u] = i; //输出路径
            ll v = e2[i].to;
            if (d[v] == d[u] + 1 && e2[i].w)
            {
                ll dlt = self(self, v, min(e2[i].w, limit - flow));
                if (!dlt)
                {
                    d[v] = -1;
                }
                e2[i].w -= dlt;
                e2[i].idx += dlt;
                e2[i ^ 1].w += dlt;
                e2[i ^ 1].idx -= dlt;
                flow += dlt;
            }
        }
        return flow;
    };
    auto dinic_bfs = [&]() -> bool
    {
        memset(d, -1, sizeof d);
        queue<ll> q;
        q.push(s);
        d[s] = 0, cur[s] = hd2[s];
        while (!q.empty())
        {
            ll u = q.front();
            q.pop();
            for (ll i = hd2[u]; i != -1; i = e2[i].nx)
            {
                ll v = e2[i].to;
                // printf("?%lld %lld\n", u, v);
                if (d[v] == -1 && e2[i].w)
                {
                    d[v] = d[u] + 1, cur[v] = hd2[v];
                    if (v == t)
                    {
                        return true;
                    }
                    q.push(v);
                }
            }
        }
        return false;
    };
    auto dinic = [&]()
    {
        ll res = 0;
        while (dinic_bfs())
        {
            res += dinic_dfs(dinic_dfs, s, 1e18);
        }
        return res;
    };
    dinic();

    vector<ll> res1, res2;
    auto dfs2 = [&](auto self, ll u, vector<ll> &res) -> void
    {
        res.push_back(u);
        for (ll i = hd2[u]; i != -1; i = e2[i].nx)
        {
            ll v = e2[i].to;
            if (e2[i].idx > 0)
            {
                e2[i].idx--;
                self(self, v, res);
                break;
            }
        }
    };
    dfs2(dfs2, s, res1);
    dfs2(dfs2, s, res2);
    reverse(res2.begin(), res2.end());
    printf("%lld\n", res1.size() + res2.size() - 4);
    auto print = [&](vector<ll> &res)
    {
        for (auto i : res)
        {
            if (i != s && i != t)
            {
                printf("%lld ", i);
            }
        }
    };
    print(res1), print(res2);
    return 0;
}
```



#### 圆方树

圆方树（Block forest 或 Round-square tree）是一种将图变成树的方法从而把一般图上的某些问题转化到树上考虑

在圆方树中，原来的每个点对应一个 **圆点**，每一个点双对应一个 **方点**。
所以共有 $n+c$ 个点，其中 $n$ 是原图点数， $c$ 是原图点双连通分量的个数。

而对于每一个点双连通分量，它对应的方点向这个点双连通分量中的每个点连边。
每个点双形成一个“菊花图”，多个“菊花图”通过原图中的割点连接在一起（因为点双的分隔点是割点）

如果原图连通，则“圆方树”才是一棵树，如果原图有 $k$ 个连通分量，则它的圆方树也会形成 $k$ 棵树形成的森林。如果原图中某个连通分量只有一个点，则需要具体情况具体分析，我们在后续讨论中不考虑孤立点。

点双是不存在割点的分量，一个点可能属于多个点双。使用 tarjan 算法求点双及每个点双包含的点。那么每个点双上的点都是圆点，连向一个新增的方点



#### 2-SAT

> 洛谷P4782 有 $n$ 个布尔值变量 $x$ 和 $m$ 个要满足的条件 $x_i$ 为 $a$ 或 $x_j$ 为 $b$ ，构造一组解或报告无解 $1\le n,m\le10^6$ 

对每个变量 $x$ ，存两个点 $x,\lnot x$ 分别表示 $x$ 取 $1/0$ ，编号为 $i,i+n$​ 。在建图后，同一强连通分量内变量值一定相等。若 $x,\lnot x$ 在同一 SCC ，那么一定无解。当 $x$ 所在 SCC 的拓扑序在 $\lnot x$ 所在 SCC 拓扑序之后的话令 $x$ 为真。复杂度 $O(n+m)$ 

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 2000010
ll n, m, hd[mn], cnt, st, low[mn], dfn[mn], ins[mn], scc, c[mn];
stack<ll> s;
struct edge
{
    ll to, nx;
} e[mn * 2];
void tarjan(ll u)
{
    low[u] = dfn[u] = ++st, ins[u] = true;
    s.push(u);
    for (ll i = hd[u], v; i; i = e[i].nx)
    {
        v = e[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (ins[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u])
    {
        ++scc;
        do
        {
            c[u] = scc;
            u = s.top();
            s.pop();
            ins[u] = false;
        } while (low[u] != dfn[u]);
    }
}
signed main()
{
    sc(n), sc(m);
    auto adde = [&](ll u, ll v)
    { e[++cnt] = {v, hd[u]}, hd[u] = cnt; };
    for (ll i = 1, a, va, b, vb; i <= m; ++i)
    {
        sc(a), sc(va), sc(b), sc(vb);
        if (va && vb)
        {
            adde(a + n, b), adde(b + n, a);
        }
        else if (!va && vb)
        {
            adde(a, b), adde(b + n, a + n);
        }
        else if (va && !vb)
        {
            adde(a + n, b + n), adde(b, a);
        }
        else if (!va && !vb)
        {
            adde(a, b + n), adde(b, a + n);
        }
        // i.e. adde(a+n*va,b+n*(vb^1)),adde(b+n*vb,a+n*(va^1))
    }
    for (ll i = 1; i <= 2 * n; ++i)
    {
        if (!dfn[i])
        {
            tarjan(i);
        }
    }
    for (ll i = 1; i <= n; ++i)
    {
        if (c[i] == c[i + n])
        {
            printf("IMPOSSIBLE");
            return 0;
        }
    }
    printf("POSSIBLE\n");
    for (ll i = 1; i <= n; ++i)
    { // tarjan逆拓扑序
        printf("%d ", c[i] < c[i + n]);
    }
    return 0;
}
```





### 匹配问题

#### 二分图

二分图性质：

1. 不存在长为奇数的环  (也是判定方法，直接点 DFS 染二色即可判断)
2. 最小顶点覆盖数等于最大匹配数 $v(G)$
3. 最大独立集数 $\alpha(G)=n-v(G)$ 

转二分图：把每个点拆成两个点，分别加入二分图的两个点集，原图中一条由a到b的边在二分图中是一条由第一个点集中的第a个点到第二个点集中的第b个点



> POJ1422-多组测试，给定 $n$ 点 $m$ 边；可以用多少条路径覆盖全部边使得每个点仅被一条路径访问 

DAG 最小不可相交路径覆盖 = $n-v(G)$

对每条边按上文拆分，求得最大匹配 $v(G)$ ，答案为 $n-v(G)$

> POJ2594-给定有向图(可能零图)，求至少多少条路径可以遍历全部点

DAG 的最小可相交路径覆盖就先 floyd 求传递闭包，在闭包新图跑最大匹配，答案依然为 $n-v(G)$

#### 最大匹配

匈牙利算法又名 KM 算法，邻接矩阵复杂度为 $O(n^3)$ ，邻接表为 $O(nm)$，可以求二分图最大匹配以及二分图最大权匹配(有完美时可求出完美)

也可以使用网络最大流 Dinic 算法以 $O(\sqrt n m)$ 求出

DFS 写法求二分图最大匹配数及其方案 (洛谷P2756-左部点权 $[1,m]$ ，右部 $[m+1,n]$ 若干条边)：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define sc(x) scanf("%lld", &x)
#define mn 105
vector<ll> e[mn];
ll m, n, ui, vi, t, mch[mn], vis[mn], r;
bool dfs(ll u, ll st)
{
    if (vis[u] == st)
    {
        return false;
    }
    vis[u] = st;
    for (auto &v : e[u])
    {
        if (!mch[v] || dfs(mch[v], st))
        {
            mch[v] = u;
            return true;
        }
    }
    return false;
}
signed main()
{
    sc(m), sc(n);
    while (true)
    {
        sc(ui), sc(vi);
        if (ui == -1 && vi == -1)
        {
            break;
        }
        e[ui].emplace_back(vi);
    }
    for (ll i = 1; i <= m; ++i)
    {
        if (dfs(i, i))
        {
            ++r;
        }
    }
    printf("%lld\n", r);
    for (ll i = m + 1; i <= n; ++i)
    {
        if (mch[i])
        {
            printf("%lld %lld\n", mch[i], i);
        }
    }
    return 0;
}
```

#### 完美匹配

> 洛谷P6577-题面类似 $n_l=n_r$ ，求完美匹配(无重边，保证有完美匹配)

BFS 版本：(复杂度 $O(n^3)$ )

对于允许非完美匹配的题目，我们允许选取虚边，也就是将虚边边权设为0即可

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 504
#define big 0x7fffffffffffffff
ll n, m, e[mn][mn], mb[mn], vb[mn], ka[mn], kb[mn], p[mn], c[mn];
ll qf, qb, q[mn], u, v, w;
void bfs(ll u)
{
    ll a, v = 0, v1 = 0, d;
    fill(p + 1, p + n + 1, 0), fill(c + 1, c + n + 1, big), mb[v] = u;
    do
    {
        a = mb[v], d = big, vb[v] = 1;
        for (ll b = 1; b <= n; ++b)
        {
            if (!vb[b])
            {
                if (c[b] > ka[a] + kb[b] - e[a][b])
                {
                    c[b] = ka[a] + kb[b] - e[a][b], p[b] = v;
                }
                if (c[b] < d)
                {
                    d = c[b], v1 = b;
                }
            }
        }
        for (ll b = 0; b <= n; ++b)
        {
            if (vb[b])
            {
                ka[mb[b]] -= d, kb[b] += d;
            }
            else
            {
                c[b] -= d;
            }
        }
        v = v1;
    } while (mb[v]);
    while (v)
    {
        mb[v] = mb[p[v]], v = p[v];
    }
}
ll km()
{ // memset mb,ka,kb->0
    for (ll a = 1; a <= n; ++a)
    {
        fill(vb, vb + n + 1, 0);
        bfs(a);
    }
    ll res = 0;
    for (ll b = 1; b <= n; ++b)
    {
        res += e[mb[b]][b];
    }
    return res;
}
signed main()
{
    sc(n), sc(m);
    memset(e, -127, sizeof e); //-big暴毙
    while (m--)
    {
        sc(u), sc(v), sc(w);
        e[u][v] = max(e[u][v], w);
    }
    printf("%lld\n", km());
    for (ll i = 1; i <= n; ++i)
    {
        printf("%lld ", mb[i]);
    }
    return 0;
}
```

#### 最大权匹配

> UOJ80-左部点数 $n_l$ ，右部 $n_r$ ，编号依次 $1$ 开始， $m$ 条加权边，求最大权匹配以及第 $i$ 个左部点匹配哪个右部点 ( $0$ 代表无匹配)

BFS写法

```c++
#include <bits/stdc++.h>
using namespace std;
#define Maxn 410
#define Maxm 160010
#define LL long long
const LL INF = 1LL << 62;
int N, n, m;
int match[Maxn], op[Maxn];
LL eg[Maxn][Maxn], lx[Maxn], ly[Maxn], slack[Maxn];
int visx[Maxn], visy[Maxn], pre[Maxn];
void mh(int y)
{
    for (int x, z; y > 0; y = z)
    {
        x = pre[y];
        z = op[x];
        op[x] = y;
        match[y] = x;
    }
}

int nt;
void ffind(int st)
{
    for (int i = 1; i <= N; i++)
        slack[i] = INF;
    queue<int> q;
    nt++;
    q.push(st);
    visx[st] = nt;
    while (1)
    {
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int y = 1; y <= N; y++)
                if (visy[y] != nt)
                {
                    if (lx[x] + ly[y] == eg[x][y])
                    {
                        pre[y] = x;
                        if (!match[y])
                        {
                            mh(y);
                            return;
                        }
                        q.push(match[y]);
                        visx[match[y]] = nt;
                        visy[y] = nt;
                    }
                    else if (slack[y] > lx[x] + ly[y] - eg[x][y])
                        slack[y] = lx[x] + ly[y] - eg[x][y], pre[y] = x;
                }
        }
        LL delta = INF;
        for (int y = 1; y <= N; y++)
            if (visy[y] != nt)
                delta = min(delta, slack[y]);
        for (int i = 1; i <= N; i++)
        {
            if (visx[i] == nt)
                lx[i] -= delta;
            if (visy[i] == nt)
                ly[i] += delta;
            else
                slack[i] -= delta;
        }
        for (int i = 1; i <= N; i++)
            if (visy[i] != nt && slack[i] == 0)
            {
                if (!match[i])
                {
                    mh(i);
                    return;
                }
                q.push(match[i]);
                visx[match[i]] = nt;
                visy[i] = nt;
            }
    }
}
void KM()
{
    for (int i = 1; i <= N; i++)
        lx[i] = ly[i] = 0, op[i] = match[i] = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            lx[i] = max(lx[i], eg[i][j]);
    for (int i = 1; i <= N; i++)
        ffind(i);
}
void output()
{
    LL ans = 0;
    for (int i = 1; i <= N; i++)
        ans += lx[i] + ly[i];
    printf("%lld\n", ans);
    for (int i = 1; i <= n; i++)
        if (eg[i][op[i]] != 0)
            printf("%d ", op[i]);
        else
            printf("0 ");
}
void init()
{
    int l;
    scanf("%d%d%d", &n, &m, &l);
    for (int i = 1; i <= l; i++)
    {
        int x, y;
        LL c;
        scanf("%d%d%lld", &x, &y, &c);
        eg[x][y] = max(eg[x][y], c);
    }
    N = max(n, m);
}
int main()
{
    init();
    KM();
    output();
    return 0;
}
```

#### 最小边覆盖

> lc1595-求最小边覆盖(用权和最小的边集覆盖所有的点)

最小权边覆盖可以转化为最小权匹配。边覆盖=匹配+额外边。

额外边是加了之后只多覆盖一个点的边，对不在匹配的每个点，选择最小的边，不会影响其他不在匹配的点。对邻接矩阵，二分图左边第 $i$ 个点的最优额外边是 $\min e_{i,:}$，右边第 $j$ 个点的最优额外边是 $\min e_{:,j}$。即分别为行列最小值。

显然一种较差的解是每个点都直接选择最小的额外边，称为基本解。在基本解的前提下，引入匹配，每加入一条匹配边 $(u,v)$，首先去掉了两边的额外边，再加上这条边的边权，即 $e_{i,j}-\min e_{i,:}-\min e_{:,j}$。在费用网络流建立一个流量为 $1$，费用为上述值的边。然后源点跟左边、右边跟汇点都连流量为 $1$ 费用为 $0$ 的边，即求朴素的最小权匹配。

使用 MCFN，复杂度为 $O(\min(n,m)^2\max(n,m))=O(n^3)$。

一个包装良好的复杂长板子：

> 前置依赖：
>
> ```c++
> namespace details {
> 	inline unsigned int bsf32(uint32_t n) noexcept {
> #if defined __GNUC__
> 		return __builtin_ctz(n);
> #elif defined _MSC_VER
> 		unsigned long ans;
> 		_BitScanForward(&ans, n);
> 		return ans;
> #elif
> 		static constexpr unsigned char table[32] = {
> 			0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,
> 			31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9,
> 		};
> 		return table[((n & -n) * 0x077CB531) >> 57];
> #endif
> 	}
> 
> 	inline unsigned int bsf64(uint64_t n) noexcept {
> #if defined __GNUC__
> 		return __builtin_ctzll(n);
> #elif defined _MSC_VER
> 		unsigned long ans;
> 		_BitScanForward64(&ans, n);
> 		return ans;
> #elif
> 		static constexpr unsigned char table[64] = {
> 			0, 1, 56, 2, 57, 49, 28, 3, 61, 58, 42, 50, 38, 29, 17, 4,
> 			62, 47, 59, 36, 45, 43, 51, 22, 53, 39, 33, 30, 24, 18, 12, 5,
> 			63, 55, 48, 27, 60, 41, 37, 16, 46, 35, 44, 21, 52, 32, 23, 11,
> 			54, 26, 40, 15, 34, 20, 31, 10, 25, 14, 19, 9, 13, 8, 7, 6,
> 		};
> 		return table[((n & -n) * 0x03f79d71b4ca8b09) >> 58];
> #endif
> 	}
> 
> 	inline unsigned int bsr32(uint32_t n) noexcept {
> #if defined __GNUC__
> 		return 31 - __builtin_clz(n);
> #elif defined _MSC_VER
> 		unsigned long ans;
> 		_BitScanReverse(&ans, n);
> 		return ans;
> #elif
> 		float t = n;
> 		uint32_t ans;
> 		memcpy(&ans, &t, sizeof(float));
> 		return (ans >> 23 & 255) - 127;
> #endif
> 	}
> 
> 	inline unsigned int bsr64(uint64_t n) noexcept {
> #if defined __GNUC__
> 		return 63 - __builtin_clzll(n);
> #elif defined _MSC_VER
> 		unsigned long ans;
> 		_BitScanReverse64(&ans, n);
> 		return ans;
> #elif
> 		float t = n;
> 		uint32_t ans;
> 		memcpy(&ans, &t, sizeof(float));
> 		return (ans >> 23 & 255) - 127;
> #endif
> 	}
> 
> 	inline unsigned int popcnt32(uint32_t n) noexcept {
> #if defined __GNUC__
> 		return __builtin_popcount(n);
> #elif defined _MSC_VER
> 		return __popcnt(n);
> #elif
> 		n -= ((n >> 1) & 0x55555555);
> 		n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
> 		return ((((n >> 4) + n) & 0x0f0f0f0f) * 0x01010101) >> 24;
> #endif
> 	}
> 
> 	inline unsigned int popcnt64(uint64_t n) noexcept {
> #if defined __GNUC__
> 		return __builtin_popcountll(n);
> #elif defined _MSC_VER
> 		return __popcnt64(n);
> #elif
> 		n -= ((n >> 1) & 0x5555555555555555);
> 		n = (n & 0x3333333333333333) + ((n >> 2) & 0x3333333333333333);
> 		return ((((n >> 4) + n) & 0x0f0f0f0f0f0f0f0f) * 0x0101010101010101) >> 56;
> #endif
> 	}
> 
> 	inline unsigned int parity32(uint32_t n) noexcept {
> #if defined __GNUC__
> 		return __builtin_parity(n);
> #elif defined _MSC_VER
> 		return __popcnt(n) & 1;
> #elif
> 		n ^= n >> 1;
> 		n ^= n >> 2;
> 		n = (n & 0x11111111) * 0x11111111;
> 		return (n >> 28) & 1;
> #endif
> 	}
> 
> 	inline unsigned int parity64(uint64_t n) noexcept {
> #if defined __GNUC__
> 		return __builtin_parityll(n);
> #elif defined _MSC_VER
> 		return __popcnt64(n) & 1;
> #elif
> 		n ^= n >> 1;
> 		n ^= n >> 2;
> 		n = (n & 0x1111111111111111) * 0x1111111111111111;
> 		return (n >> 60) & 1;
> #endif
> 	}
> 
> 
> 	template<typename I, bool B = 32 < std::numeric_limits<I>::digits>
> 	struct _BitFuncImpl {
> 		inline static unsigned int bsf(I n) noexcept { return bsf64(n); }
> 		inline static unsigned int bsr(I n) noexcept { return bsr64(n); }
> 		inline static unsigned int popcnt(I n) noexcept { return popcnt64(n); }
> 		inline static unsigned int parity(I n) noexcept { return parity64(n); }
> 	};
> 
> 	template<typename I>
> 	struct _BitFuncImpl<I, false> {
> 		inline static unsigned int bsf(I n) noexcept { return bsf32(n); }
> 		inline static unsigned int bsr(I n) noexcept { return bsr32(n); }
> 		inline static unsigned int popcnt(I n) noexcept { return popcnt32(n); }
> 		inline static unsigned int parity(I n) noexcept { return parity32(n); }
> 	};
> 
> 	template<typename I>
> 	inline unsigned int bsf(I n) noexcept { return _BitFuncImpl<I>::bsf(n); }
> 	template<typename I>
> 	inline unsigned int bsr(I n) noexcept { return _BitFuncImpl<I>::bsr(n); }
> 	template<typename I>
> 	inline unsigned int popcnt(I n) noexcept { return _BitFuncImpl<I>::popcnt(n); }
> 	template<typename I>
> 	inline unsigned int parity(I n) noexcept { return _BitFuncImpl<I>::parity(n); }
> }
> 
> template<typename E>
> class Network {
> public:
>  using edge_type = E;
>  using size_type = unsigned;
> 
> private:
>  size_type n, m;
>  size_type* pos;
>  std::unique_ptr<edge_type[]> edges;
> 
> public:
>  Network(std::unique_ptr<edge_type[]> edges, std::unique_ptr<size_type[]> spos, size_type n, size_type m)
>      : n(n), m(m), pos(spos.release() + 1), edges(std::move(edges))
>  {
>      pos[-1] = 1;
>  }
> 
>  Network(const Network& other) : n(other.n), m(other.m), pos(other.pos), edges(new edge_type[m]) {
>      std::copy_n(other.edges.get(), m, edges.get());
>      ++pos[-1];
>  }
> 
>  ~Network() { if (--pos[-1] == 0) delete[] (pos - 1); }
> 
>  inline size_type order() const noexcept { return n; }
>  inline size_type size() const noexcept { return m; }
>  inline const size_type* raw_pos() const noexcept { return pos; }
>  inline const edge_type* raw_edges() const noexcept { return edges.get(); }
>  inline edge_type* raw_edges() noexcept { return edges.get(); }
> };
> 
> template<typename F = int, typename C = int>
> class MCFN {
> public:
>  using size_type = unsigned;
> 
> private:
>  struct RawEdge {
>      size_type from, to;
>      F cap;
>      C cost;
>  };
> 
>  struct Edge {
>  private:
>      friend class MCFN;
>      size_type _rev, _to;
>      F _cap;
>      C _cost;
>      Edge(size_type rev, size_type to, F cap, C cost) : _rev(rev), _to(to), _cap(cap), _cost(cost) {}
>  public:
>      using flow_type = F;
>      using cost_type = C;
>      Edge() = default;
>      inline size_type rev() const noexcept { return _rev; }
>      inline size_type to() const noexcept { return _to; }
>      inline flow_type residual() const noexcept { return _cap; }
>      inline bool full() const noexcept { return _cap == 0; }
>      inline void push(flow_type d) noexcept { _cap -= d; }
>      inline cost_type cost() const noexcept { return _cost; }
>  };
> 
>  std::vector<RawEdge> edges;
>  std::vector<size_type> deg;
> 
> public:
>  MCFN() noexcept = default;
> 
>  MCFN(size_type n) : deg(n, 0) {}
> 
>  void reserve(size_type n, size_type m) {
>      edges.reserve(m);
>      deg.reserve(n);
>  }
> 
>  inline size_type add_vertex() {
>      const size_type ans = deg.size();
>      deg.push_back(0);
>      return ans;
>  }
> 
>  inline void add_edge(size_type from, size_type to, F cap, C cost) {
>      if (cap <= 0) return;
>      edges.emplace_back(RawEdge{from, to, cap, cost});
>      ++deg[from];
>      ++deg[to];
>  }
> 
>  Network<Edge> prepare() const {
>      using size_type = typename Network<Edge>::size_type;
>      const size_type n = deg.size(), m = edges.size();
>      std::unique_ptr<Edge[]> sorted_edges(new Edge[2 * m]);
>      std::unique_ptr<size_type[]> spos(new size_type[n + 2]);
>      const auto pos = spos.get() + 1;
>      *std::partial_sum(deg.begin(), deg.end(), pos) = 2 * m;
>      for (size_type i = m;i-- > 0;) {
>          const RawEdge e = edges[i];
>          const size_type u = e.from, v = e.to;
>          const size_type rp = --pos[v], p = --pos[u];
>          sorted_edges[p] = Edge(rp, v, e.cap, e.cost);
>          sorted_edges[rp] = Edge(p, u, 0, -e.cost);
>      }
>      return Network<Edge>(std::move(sorted_edges), std::move(spos), n, 2 * m);
>  }
> };
> ```
>
> 网络流算法：
>
> ```c++
> template<typename F = int, typename C = int, typename G>
> auto ssp(G&& g, std::size_t s, std::size_t t, bool nneg = false)
> -> std::pair<
>  typename std::common_type<F, typename std::remove_reference<G>::type::edge_type::flow_type>::type,
>  typename std::common_type<C, typename std::remove_reference<G>::type::edge_type::cost_type>::type>
> {
>  using graph_type = typename std::remove_reference<G>::type;
>  using size_type = typename graph_type::size_type;
>  using edge_type = typename graph_type::edge_type;
>  using flow_type = typename std::common_type<F, typename edge_type::flow_type>::type;
>  using cost_type = typename std::common_type<C, typename edge_type::cost_type>::type;
>  static constexpr size_type BIN_LEN = std::numeric_limits<cost_type>::digits;
>  static constexpr cost_type INF = std::numeric_limits<cost_type>::max();
>  struct ShortestPath {
>      size_type pre;
>      cost_type pot, dis;
>  };
>  struct ListNode {
>      size_type prev, next;
>  };
>  const size_type n = g.order(), m = g.size();
>  const bool use_heap = m / n <= n / std::min<size_type>(3 * details::bsr(n + 7) + 15, 64);
>  const auto edges = g.raw_edges();
>  const auto pos = g.raw_pos();
>  std::vector<ShortestPath> sp(n);
>  std::vector<bool> vis;
>  const auto init = [&] {
>      vis.assign(n, false);
>      std::vector<size_type> q(n);
>      size_type l = 0, r = 1;
>      for (auto& e : sp)
>          e.pot = INF;
>      sp[s] = {0, 0};
>      vis[s] = true;
>      q[0] = s;
>      while (l != r) {
>          const size_type u = q[l];
>          l = l + 1 != n ? l + 1 : 0;
>          vis[u] = false;
>          const size_type pu = sp[u].pre;
>          const cost_type du = sp[u].pot;
>          const auto start_edge = edges + pos[u];
>          const auto end_edge = edges + pos[u + 1];
>          for (auto i = start_edge;i != end_edge;++i) {
>              const edge_type e = *i;
>              if (e.full()) continue;
>              const size_type v = e.to();
>              const cost_type dv = sp[v].pot;
>              const cost_type ndv = du + e.cost();
>              if (ndv < dv) {
>                  sp[v].pre = pu + 1;
>                  sp[v].pot = ndv;
>                  if (sp[v].pre >= n) throw std::invalid_argument("graph contains negative cycles.");
>                  if (!vis[v]) {
>                      q[r] = v;
>                      vis[v] = true;
>                      r = r + 1 != n ? r + 1 : 0;
>                  }
>              }
>          }
>      }
>  };
>  if (!nneg) init();
>  const cost_type pt = sp[t].pot;
>  flow_type flow = 0;
>  cost_type cost = 0;
>  const auto augment = [&] {
>      flow_type f = std::numeric_limits<flow_type>::max();
>      for (size_type i = t;i != s;) {
>          const edge_type e = edges[sp[i].pre];
>          const flow_type r = edges[e.rev()].residual();
>          if (r < f) f = r;
>          i = e.to();
>      }
>      for (size_type i = t;i != s;) {
>          auto& e = edges[sp[i].pre];
>          edges[e.rev()].push(f);
>          e.push(-f);
>          i = e.to();
>      }
>      flow += f;
>      const cost_type dt = sp[t].dis;
>      for (auto& e : sp)
>          if (e.dis < dt)
>              e.pot -= dt - e.dis;
>      cost += cost_type(f) * (pt - sp[s].pot);
>  };
>  const auto flow_with_heap = [&] {
>      std::vector<ListNode> list(n + BIN_LEN + 1);
>      const auto dijkstra_with_heap = [&] {
>          const auto radix_distance = [] (cost_type lhs, cost_type rhs) {
>              return lhs != rhs ? details::bsr(lhs ^ rhs) + 1 : 0;
>          };
>          const auto buk = list.data() + n;
>          const auto insert_list = [&] (size_type idx, size_type v) {
>              const size_type rear = buk[idx].prev;
>              list[rear].next = v;
>              list[v].prev = rear;
>              buk[idx].prev = v;
>              list[v].next = idx + n;
>          };
>          cost_type top = 0;
>          for (size_type i = 0;i <= n + BIN_LEN;++i)
>              list[i] = {i, i};
>          list[s] = {n, n};
>          buk[0] = {size_type(s), size_type(s)};
>          for (auto& e : sp)
>              e.dis = INF;
>          sp[s].dis = 0;
>          while (true) {
>              size_type u = buk[0].next;
>              if (u == n) {
>                  size_type idx = 1;
>                  for (;idx <= BIN_LEN;++idx)
>                      if (buk[idx].next < n)
>                          break;
>                  if (idx > BIN_LEN) break;
>                  const size_type head = buk[idx].next;
>                  top = sp[head].dis;
>                  for (size_type i = head;(i = list[i].next) < n;)
>                      if (sp[i].dis < top)
>                          top = sp[i].dis;
>                  for (size_type i = head;i < n;) {
>                      const size_type j = list[i].next;
>                      insert_list(radix_distance(top, sp[i].dis), i);
>                      i = j;
>                  }
>                  buk[idx] = {idx + n, idx + n};
>                  u = buk[0].next;
>              }
>              if (u == size_type(t)) return true;
>              const size_type next = list[u].next;
>              list[next].prev = n;
>              buk[0].next = next;
>              const cost_type pu = sp[u].pot;
>              const cost_type du = sp[u].dis;
>              const auto start_edge = edges + pos[u];
>              const auto end_edge = edges + pos[u + 1];
>              for (auto i = start_edge;i != end_edge;++i) {
>                  const edge_type e = *i;
>                  if (e.full()) continue;
>                  const size_type v = e.to();
>                  const cost_type pv = sp[v].pot;
>                  const cost_type dv = sp[v].dis;
>                  const cost_type ndv = e.cost() + pu - pv + du;
>                  if (ndv < dv) {
>                      const size_type new_idx = radix_distance(top, ndv);
>                      if (new_idx != radix_distance(top, dv)) {
>                          const size_type prev = list[v].prev;
>                          const size_type next = list[v].next;
>                          list[prev].next = next;
>                          list[next].prev = prev;
>                          insert_list(new_idx, v);
>                      }
>                      sp[v].dis = ndv;
>                      sp[v].pre = e.rev();
>                  }
>              }
>          }
>          return false;
>      };
>      while (dijkstra_with_heap())
>          augment();
>  };
>  const auto flow_without_heap = [&] {
>      std::vector<size_type> min_buk;
>      const auto dijkstra_without_heap = [&] {
>          vis.assign(n, false);
>          min_buk = {size_type(s)};
>          for (auto& e : sp)
>              e.dis = INF;
>          sp[s].dis = 0;
>          while (true) {
>              size_type u;
>              cost_type du;
>              if (!min_buk.empty()) {
>                  u = min_buk.back();
>                  min_buk.pop_back();
>                  if (vis[u]) continue;
>                  du = sp[u].dis;
>              } else {
>                  du = INF;
>                  for (size_type i = 0;i < n;++i)
>                      if (!vis[i] && sp[i].dis < du)
>                          du = sp[u = i].dis;
>                  if (du == INF) break;
>              }
>              if (u == size_type(t)) return true;
>              vis[u] = true;
>              const cost_type pu = sp[u].pot;
>              const auto start_edge = edges + pos[u];
>              const auto end_edge = edges + pos[u + 1];
>              for (auto i = start_edge;i != end_edge;++i) {
>                  const edge_type e = *i;
>                  if (e.full()) continue;
>                  const size_type v = e.to();
>                  const cost_type pv = sp[v].pot;
>                  const cost_type dv = sp[v].dis;
>                  const cost_type ndv = e.cost() + pu - pv + du;
>                  if (ndv < dv) {
>                      sp[v].dis = ndv;
>                      sp[v].pre = e.rev();
>                      if (ndv == du) min_buk.push_back(v);
>                  }
>              }
>          }
>          return false;
>      };
>      while (dijkstra_without_heap())
>          augment();
>  };
>  if (use_heap)
>      flow_with_heap();
>  else
>      flow_without_heap();
>  return std::make_pair(flow, cost);
> }
> ```

本题代码：

```c++
class Solution {
public:
    int connectTwoGroups(const vector<vector<int>>& cost) {
        const int m = cost.size(), n = cost[0].size();
        vector<int> row_min(m, INT_MAX);
        vector<int> col_min(n, INT_MAX);
        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n;++j) {
                row_min[i] = min(row_min[i], cost[i][j]);
                col_min[j] = min(col_min[j], cost[i][j]);
            }
        }
        MCFN<int, int> mcfn(m + n + 2);
        const int s = m + n, t = s + 1;
        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n;++j)
                mcfn.add_edge(i, m + j, 1, min(cost[i][j] - row_min[i] - col_min[j], 0));
            mcfn.add_edge(s, i, 1, 0);
        }
        for (int i = 0;i < n;++i)
            mcfn.add_edge(m + i, t, 1, 0);
        return reduce(row_min.begin(), row_min.end(), 0) + reduce(col_min.begin(), col_min.end(), 0) + ssp(mcfn.prepare(), s, t).second;
    }
};
```

### 网络流

#### 最大流

洛谷P3376为例

##### EK 算法 

$O(nm^2)$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define me 5010
#define mn 205
ll n, m, s, t, u, v;
ll w, ans, dis[mn];
ll tot = 1, vis[mn], pre[mn], head[mn], flag[mn][mn];
struct node
{
    ll to, net;
    ll val;
} e[me * 2];
void add(ll u, ll v, ll w)
{
    e[++tot] = {v, head[u], w};
    head[u] = tot;
}
ll bfs()
{ // bfs寻找增广路
    for (ll i = 1; i <= n; i++)
        vis[i] = 0;
    queue<ll> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 0x7fffffffffff;
    while (!q.empty())
    {
        ll x = q.front();
        q.pop();
        for (ll i = head[x]; i; i = e[i].net)
        {
            if (e[i].val == 0)
                continue; //我们只关心剩余流量>0的边
            ll v = e[i].to;
            if (vis[v] == 1)
                continue; //这一条增广路没有访问过
            dis[v] = min(dis[x], e[i].val);
            pre[v] = i; //记录前驱，方便修改边权
            q.push(v);
            vis[v] = 1;
            if (v == t)
                return 1; //找到了一条增广路
        }
    }
    return 0;
}
void update()
{ //更新所经过边的正向边权以及反向边权
    ll x = t;
    while (x != s)
    {
        ll v = pre[x];
        e[v].val -= dis[t];
        e[v ^ 1].val += dis[t];
        x = e[v ^ 1].to;
    }
    ans += dis[t]; //累加每一条增广路经的最小流量值
}
signed main()
{
    scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
    for (ll i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld", &u, &v, &w);
        if (flag[u][v] == 0)
        { //处理重边的操作（加上这个模板题就可以用Ek算法过了）
            add(u, v, w), add(v, u, 0);
            flag[u][v] = tot;
        }
        else
        {
            e[flag[u][v] - 1].val += w;
        }
    }
    while (bfs() != 0)
    { //直到网络中不存在增广路
        update();
    }
    printf("%lld", ans);
    return 0;
}
```



##### Dinic算法

最坏 $O(n^2m)$ ，二分图 $O(\sqrt nm)$ ，以下代码可解决自环

若输出方案，

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 202
#define me 10002
ll n, m, s, t, hd[mn], cnt = 1, ui, vi, wi, res, tot, dep[mn];
ll q[mn], lf, rf;
struct edge
{
    ll to, v, nx;
} e[me];
bool vis[mn];
void adde(ll u, ll v, ll w)
{
    e[++cnt] = {v, w, hd[u]};
    hd[u] = cnt;
}
bool bfs()
{
    fill_n(dep, n + 2, 0);//总点数,与题意可能不一样
    q[lf = rf = 1] = s;
    dep[s] = 1;
    while (lf <= rf)
    {
        ll u = q[lf++];
        for (ll i = hd[u]; i; i = e[i].nx)
        {
            ll v = e[i].to;
            if (e[i].v && !dep[v])
                dep[v] = dep[u] + 1, q[++rf] = v;
        }
    }
    return dep[t];
}
ll dfs(ll u, ll flow)
{
    if (u == t)
        return flow;
    ll out = 0;
    for (ll i = hd[u]; i; i = e[i].nx)
    {
        ll v = e[i].to;
        if (e[i].v && dep[v] == dep[u] + 1)
        {
            ll res = dfs(v, min(e[i].v, flow));
            e[i].v -= res;
            e[i ^ 1].v += res;
            out += res;
            flow -= res;
        }
    }
    return !out ? (dep[u] = 0) : out;
}
signed main()
{
    scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
    for (ll i = 1; i <= m; ++i)
    {
        scanf("%lld%lld%lld", &ui, &vi, &wi);
        adde(ui, vi, wi), adde(vi, ui, 0);
    }
    while (bfs())
        tot += dfs(s, 1e18);
    printf("%lld", tot);
    return 0;
}
```



#### 最小费用最大流

> 洛谷P3381-输入边及其流量限制、单位流量费用；输出最大流以及在最大流量时的最小费用(无负费用)( $1\le w,c\le10^3,1\le n\le5\times10^3,1\le m\le5\times10^4$ )

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define MAXN 100002
bool vis[MAXN];
ll n, m, s, t, x, y, z, f, dis[MAXN], pre[MAXN], last[MAXN], flow[MAXN];
ll mxflow, micost, cnt, hd[MAXN];
struct edge
{
    ll to, nx, f, d;
} e[MAXN];
queue<ll> q;
void adde(ll &u, ll &v, ll f, ll d)
{
    e[++cnt] = {v, hd[u], f, d};
    hd[u] = cnt;
}
bool spfa(ll s, ll t)
{
    memset(dis, 0x7f, sizeof dis);
    memset(flow, 0x7f, sizeof flow);
    memset(vis, 0, sizeof vis);
    q.push(s);
    vis[s] = true, dis[s] = 0, pre[t] = -1;
    while (!q.empty())
    {
        ll no = q.front();
        q.pop();
        vis[no] = false;
        for (ll i = hd[no]; i != -1; i = e[i].nx)
        {
            ll toi = e[i].to;
            if (e[i].f > 0 && dis[toi] > dis[no] + e[i].d)
            {
                dis[toi] = dis[no] + e[i].d;
                pre[toi] = no;
                last[toi] = i;
                flow[toi] = min(e[i].f, flow[no]);
                if (!vis[toi])
                    vis[toi] = true, q.push(toi);
            }
        }
    }
    return pre[t] != -1;
}
void mcmf()
{
    while (spfa(s, t))
    {
        ll no = t;
        mxflow += flow[t];
        micost += flow[t] * dis[t];
        while (no != s)
        {
            e[last[no]].f -= flow[t];
            e[last[no] ^ 1].f += flow[t];
            no = pre[no];
        }
    }
}
signed main()
{
    memset(hd, -1, sizeof hd);
    cnt = -1; //因为有异或操作，从0开始，否则TLE
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (ll i = 1; i <= m; ++i)
    {
        scanf("%d%d%d%d", &x, &y, &z, &f);
        adde(x, y, z, f);
        adde(y, x, 0, -f);
    }
    mcmf();
    printf("%d %d", mxflow, micost);
    return 0;
}
```

> 牛客2022暑假集训10-E 有 $n(1\le n\le400)$ 人 $m(1\le m\le400)$ 稿。若 $a_{ij}=1$ 则第 $i$ 人可读第 $j$ 稿。每人只能读一篇稿。问是否存在分配方案使得每人都能读稿(不能输出 `-1`)，在此前提下输出使得最大化每篇稿被读次数的方案。
>

最小费用最大流。不考虑费用时显然源点向每个人连一条流量为 $1$ 的边，每个人向他能读的稿连流量为 $1$ 的边，而每篇稿子向汇点连流量为入度的边。显然，题意无解即有人没读到，即流量不为 $n$。所有有解都是没人读一篇稿，接下来就是稿的分配了，要使得每稿尽可能多人。但这样建图只能最大化流量，即使得总流量最大，而总流量最大不能保证最小流量最大。为此，将流向汇点的流量为入度的边拆分为若干条流量为 $1$，代价递增的边。这样可以在总流量最大的情况下，让分配更加地平均。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <const int mn, class ty = int>
struct MinCostMaxFlow
{
    const ty inf = numeric_limits<ty>::max();
    struct edge
    {
        int v;
        ty cap, cost;
        int rev;
    };
    vector<edge> g[mn];
    ty sum{}, dis[mn]{};
    int n, s, t, aug[mn]{};
    ty flow{}, cost{};
    bool augment()
    {
        fill(dis, dis + n + 1, inf);
        priority_queue<pair<int, int>> q;
        dis[t] = 0;
        q.push({dis[t], t});
        for (int u, v; !q.empty() && q.top().first != inf;)
        {
            u = q.top().second;
            q.pop();
            for (auto e : g[u])
            {
                v = e.v;
                if (g[v][e.rev].cap && dis[v] > dis[u] - e.cost)
                {
                    dis[v] = dis[u] - e.cost;
                    q.push({dis[v], v});
                }
            }
        }
        sum += dis[s];
        for (int u = 1; u <= n; ++u)
        {
            for (auto &e : g[u])
            {
                e.cost += dis[e.v] - dis[u];
            }
        }
        return dis[s] != inf;
    }

    ty dfs(int u, ty lim)
    {
        if (u == t)
        {
            cost += lim * sum;
            return lim;
        }
        ty f = 0;
        aug[u] = 1;
        for (auto &e : g[u])
        {
            int v = e.v;
            if (!e.cost && e.cap && !aug[v])
            {
                ty t = dfs(v, min(lim - f, e.cap));
                e.cap -= t;
                g[v][e.rev].cap += t;
                f += t;
                if (f == lim)
                {
                    break;
                }
            }
        }
        if (f == lim)
        {
            aug[u] = 0;
        }
        return f;
    }

    void add(int u, int v, ty cap, ty cost)
    {
        g[u].push_back({v, cap, cost, (int)g[v].size()});
        g[v].push_back({u, 0, -cost, (int)g[u].size() - 1});
    }

    pair<ty, ty> solve(int _n, int _s, int _t)
    {
        n = _n, s = _s, t = _t, flow = cost = 0;
        do
        {
            ty f;
            do
            {
                memset(aug, 0, (n + 1) << 2);
                f = dfs(s, inf);
                flow += f;
            } while (f > 0);
        } while (augment());
        return {flow, cost};
    }
};

const ll mn = 405;
MinCostMaxFlow<mn * 2, int> d;
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    int n, m;
    char a[mn];
    cin >> n >> m;
    int s = n + m + 1, t = s + 1;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> (a + 1);
        d.add(s, i, 1, 0);
        for (ll j = 1; j <= m; ++j)
        {
            if (a[j] == '1')
            {
                d.add(i, n + j, 1, 0);
            }
        }
    }
    for (ll i = 1; i <= m; ++i)
    {
        for (ll j = 1; j <= n; ++j)
        {
            d.add(n + i, t, 1, j);
        }
    }
    auto f = d.solve(t, s, t);
    if (f.first != n)
    {
        cout << -1;
        return 0;
    }
    for (ll i = 1; i <= n; ++i)
    {
        for (auto e : d.g[i])
        {
            if (!e.cap && e.v > n)
            {
                cout << (e.v - n) << ' ';
                break;
            }
        }
    }
    return 0;
}
```

#### 最小割

> SCNUOJ1975-给定 $n,m(2\le n\le10^n,1\le m\le10^5)$ 的有向简单连通图，保证点 $1$ 对 $n$ 可达且任意 $1<x<n$ 出入度均不为零。求删掉最少多少边使得 $1,n$ 不连通并输出方案。

割将原点和汇点分在两个不同点集的点划分方案，容量为分属两点集的边的数目。本题显然是最小割模板。

最大流最小割定理：能够从源点到达汇点的最大流量等于从网络中移除导致网络流中断的边集的最小容量和。

Dinic $O(n\sqrt m)$，残余网络搜索有流量的可达边集及其反集，连接两集合的边可删。

```c++
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5;
int n, m, s, t, tot = 1, lnk[N], ter[M], nxt[M], val[M], dep[N], cur[N];

void add(int u, int v, int w)
{
    ter[++tot] = v, nxt[tot] = lnk[u], lnk[u] = tot, val[tot] = w;
}

void addedge(int u, int v, int w) { add(u, v, w), add(v, u, 0); }

int bfs(int s, int t)
{
    memset(dep, 0, sizeof(dep));
    memcpy(cur, lnk, sizeof(lnk));
    std::queue<int> q;
    q.push(s), dep[s] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = lnk[u]; i; i = nxt[i])
        {
            int v = ter[i];
            if (val[i] && !dep[v])
                q.push(v), dep[v] = dep[u] + 1;
        }
    }
    return dep[t];
}

int dfs(int u, int t, int flow)
{
    if (u == t)
        return flow;
    int ans = 0;
    for (int &i = cur[u]; i && ans < flow; i = nxt[i])
    {
        int v = ter[i];
        if (val[i] && dep[v] == dep[u] + 1)
        {
            int x = dfs(v, t, std::min(val[i], flow - ans));
            if (x)
                val[i] -= x, val[i ^ 1] += x, ans += x;
        }
    }
    if (ans < flow)
        dep[u] = -1;
    return ans;
}

int dinic(int s, int t)
{
    int ans = 0;
    while (bfs(s, t))
    {
        int x;
        while ((x = dfs(s, t, 1 << 30)))
            ans += x;
    }
    return ans;
}

int vis[N];
void dfs(int u)
{
    vis[u] = 1;
    for (int i = lnk[u]; i; i = nxt[i])
    {
        int v = ter[i];
        if (!vis[v] && val[i])
            dfs(v);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    s = 1, t = n;
    while (m--)
    {
        int u, v, w = 1;
        scanf("%d%d", &u, &v);
        addedge(u, v, w);
    }
    printf("%d\n", dinic(s, t));
    dfs(s);
    for (int u = 1; u <= n; u++)
    {
        for (int i = lnk[u]; i; i = nxt[i])
        {
            int v = ter[i];
            if (vis[u] == 1 && vis[v] == 0 && val[i] == 0)
            {
                printf("%d %d\n", u, v);
            }
        }
    }
    return 0;
}
```



### 杂项

#### 欧拉图

欧拉路径：经过每条边一次且仅一次的路径(起点不为终点)

欧拉回路：经过每条边一次且仅一次的回路

有向图欧拉路径：恰好存在一个点出度比入度多一(起点)，一个点入度比出度多一(终点)，其他点入度与出度相同

有向图欧拉回路：所有点入度=出度，起点和终点任选

无向图欧拉路径：恰好存在 $2$ 点度数是奇数(分别是起点终点)，其他点度数是偶数

无向图欧拉回路：所有点度数是偶数(起点终点任选)

若存在欧拉回路也一定存在欧拉路径

此外，还应该判定图是否是连通图(满足上面条件也有非连通图)显然可以用并查集来做。

具有欧拉回路的无向或有向图是欧拉图；具有欧拉通路而不具有回路的是半欧拉图。(直观理解回路即任意点开始可以一笔画完图；通路只有特定点开始可以)

> 洛谷 P7771 输出 $n,m$ 有向图的最小字典序欧拉路径，若不存在输出 `No` $1\le n\le10^5,1\le m\le2\times10^5$ 

下面代码模板没有判定联通，要判并查集/tarjan即可

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 100010
typedef long long ll;
ll n, m, ru[mn], cu[mn], s = 1, fail, vis[mn], bgs, eds;
vector<ll> e[mn];
stack<ll> ans;
void dfs(ll u)
{
    for (ll i = vis[u]; i < e[u].size(); i = vis[u])
    { //不i++是可能被后续dfs更新过
        vis[u] = i + 1;
        dfs(e[u][i]);
    }
    ans.push(u);
}
signed main()
{
    scanf("%lld%lld", &n, &m);
    for (ll i = 0, u, v; i < m; ++i)
    {
        scanf("%lld%lld", &u, &v);
        ++cu[u], ++ru[v];
        e[u].emplace_back(v);
    }
    for (ll i = 1; i <= n; ++i)
    {
        if (cu[i] == ru[i] + 1)
        {
            s = i;
            ++bgs;
        }
        else if (ru[i] == cu[i] + 1)
        {
            ++eds;
        }
        if (ru[i] != cu[i])
        {
            ++fail;
        }
        sort(e[i].begin(), e[i].end());
    }
    if (!(fail == 0 || (fail == 2 && bgs == 1 && eds == 1)))
    {
        printf("No");
        return 0;
    }
    dfs(s);
    while (!ans.empty())
    {
        printf("%lld ", ans.top());
        ans.pop();
    }
    return 0;
}
```

> P2731洛谷-给定无向图边数 $m$ ，点在 $[1,500]$ 编号，必然有解且联通，输出字典序最小欧拉路

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 512
ll m, s = 1, g[mn][mn], du[mn], n;
stack<ll> ans;
void dfs(ll u)
{
    for (ll v = 1; v <= n; ++v)
    {
        if (g[u][v] > 0)
        {
            --g[u][v], --g[v][u];
            dfs(v);
        }
    }
    ans.push(u);
}
signed main()
{
    scanf("%lld", &m);
    for (ll i = 0, u, v; i < m; ++i)
    {
        scanf("%lld%lld", &u, &v);
        ++du[u], ++du[v], ++g[u][v], ++g[v][u];
        n = max(n, max(u, v));
    }
    for (ll i = 1; i <= n; ++i)
    {
        if (du[i] & 1)
        {
            s = i;
            break;
        }
    }
    dfs(s);
    while (!ans.empty())
    {
        printf("%lld\n", ans.top());
        ans.pop();
    }
    return 0;
}
```



#### 哈密顿图

哈密顿通路：经过图中所有顶点一次且仅一次的通路

哈密顿回路：经过图中所有顶点一次且仅一次的回路

具有哈密顿回路的图为哈密顿图

具有哈密顿通路，不具有哈密顿回路的图为半哈密顿图

设 $p(x)$ 是图 $x$ 的连通分支数，对哈密顿图任意非空子集 $V_1$，均有 $p(G-V_1)\le |V_1|$。对半哈密顿图有 $p(G-V_1)\le |V_1|+1$

完全图 $K_{2m+1}(m\ge1)$ 含 $m$ 条边不重的哈密顿回路，且加起来含完全图中所有边。完全图 $K_{2m}(m\ge 2)$ 含 $m-1$ 条边不重的哈密顿回路，删掉全部回路后所得图含 $m$ 条互不相邻边。

充分条件：对无向简单图 $G(|V|\ge 2)$，若任意不相邻顶点 $v_i,v_j$ 度数满足 $d(v_i)+d(v_j)\ge n-1$ 则存在哈密顿通路。若 $|V|\ge $3 且满足 $d(v_i)+d(v_j)\ge n$ 则存在哈密顿回路。若任意顶点均有 $d(v_i)\ge\dfrac n2$ 则存在哈密顿回路。

$n\ge 2$ 阶竞赛图具有哈密顿通路，含竞赛图子图也具有哈密顿通路。强联通竞赛图有哈密顿回路。含强联通竞赛图作为子图具有哈密顿回路。

已经证明“判断一个图存不存在哈密顿回路”是NPC。



#### 竞赛图

兰道定理：判定竞赛图。设比分序列是竞赛图出度排序后的序列 $s$，序列能是竞赛图当且仅当
$$
\forall1\le k\le n,\sum_{i=1}^ks_i\ge\dbinom k2
$$
且 $k=n$ 时必须取等。注意并不是说 $s$ 每个还原图都是竞赛图，只是证明存在至少一种正确。

竞赛图如果存在环，至少是三元环。



## 动态规划

### 模板

#### 背包问题

**01背包**：

```c++
for (int i = 1; i <= n; i++) //W容量 v价值
  for (int l = W; l >= w[i]; l--) f[l] = max(f[l], f[l - w[i]] + v[i]);
```

> 方案数：(洛谷P1164)
>
> ```c++
> dp[0]=1;
> for(int i=0;i<n;++i)
>     for(int j=m-a[i];j>=0;--j) 
>         dp[j+a[i]] += dp[j];
> ```

**完全背包**：(可以选取无限次) (将01背包第二维修改顺序即可)

```c++
for (int l = w[i]; l <= W; l++)
```

**多重背包**：(每种物品有 $k_i$ 个) 将 $k_i$ 拆分为 $2^i$ ，然后用 01 背包解决

二维费用背包：(有两个重量维度) (加一层循环, 加一维数组枚举, 同 01 背包解决)

**分组背包**：(每组内物品冲突，只能选组内一个)

```c++
for (int k = 1; k <= ts; k++)          // 循环每一组
  for (int i = m; i >= 0; i--)         // 循环背包容量
    for (int j = 1; j <= cnt[k]; j++)  // 循环该组的每一个物品
      if (i >= w[t[k][j]])
        dp[i] = max(dp[i],
                    dp[i - w[t[k][j]]] + c[t[k][j]]);  // 像0-1背包一样状态转移
```

**依赖背包**：将依赖关系转化为分组关系，用分组背包求



#### 字符DP

> atcoder-contest122-d 求有多少长为 $n$ ，只含字符 `ACGT` 且满足 ①无子串 `AGC` ② 交换相邻两位仍无子串 `AGC` ; 对 $10^9+7$ 取模

设$dp[h][i][j][k]$是长为$h$且最后一、二、三个字符分别为$i,j,k$的字符串的答案 $O(n4^4)$

```c++
#include <iostream>
#define maxn 105
using namespace std;
typedef long long ll;

ll dp[maxn][4][4][4];
const ll MOD = 1e9 + 7;
bool check(int j, int k, int v)
{
	return !(j == 0 && k == 2 && v == 1);
}
bool check2(int j, int k, int v)
{
	// 0->a, 1->c, 2->g, 3->t
	if (!((j == 0 && k == 2 && v == 1) || (j == 0 && k == 1 && v == 2) || (j == 2 && k == 0 && v == 1)))
		return true;
	return false;
}

int main()
{
	int n;
	cin >> n;

	for (int j = 0; j < 4; j++)
	{
		for (int k = 0; k < 4; k++)
		{
			for (int v = 0; v < 4; v++)
			{
				if (check2(j, k, v))
					dp[3][j][k][v] = 1;
			}
		}
	}

	for (int i = 4; i <= n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				for (int v = 0; v < 4; v++)
				{
					for (int u = 0; u < 4; u++)
						if (check2(j, k, v) && check(u, k, v) && check(u, j, v) && check(u, j, k))//最后一个check没有也行；因为这种情况下原dp[i-1][u][j][k]就是0
							dp[i][j][k][v] = (dp[i][j][k][v] + dp[i - 1][u][j][k]) % MOD;
				}
			}
		}
	}

	ll ans = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                ans = (ans + dp[n][i][j][k]) % MOD;

	cout << ans << endl;
	return 0;
}
```



#### 树上DP

> $n$ 点有点权树, 选当前节点就不能选全部直接子节点,求选择方案使得点权和最大,输出最大值(洛谷P1352)

设 $dp[i][j]$ , $j=0$ 表示不选 $i$ 时 $i$ 子树最大值; $j=1$ 表示选 $i$ 时 $i$ 子树最大值

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 6002
struct edge
{
    int to, nx;
} e[MAXN];
int n, ui, vi, hd[MAXN], cnt, dp[MAXN][2], v[MAXN], root;
bool fa[MAXN];
inline void adde(int &u, int &v)
{
    e[++cnt].to = v;
    e[cnt].nx = hd[u];
    hd[u] = cnt;
}
void dfs(int h)
{
    dp[h][0] = 0;
    dp[h][1] = v[h];
    for (int i = hd[h]; i; i = e[i].nx)
    {
        int toi = e[i].to;
        dfs(toi);
        dp[h][0] += max(dp[toi][0], dp[toi][1]);
        dp[h][1] += dp[toi][0];
    }
}
signed main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &v[i]);
    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d", &vi, &ui);
        adde(ui, vi);
        fa[vi] = true;
    }
    for (int i = 1; i <= n; ++i)
        if (!fa[i])
        {
            root = i;
            break;
        }
    dfs(root);
    printf("%d", max(dp[root][0], dp[root][1]));
    return 0;
}
```



#### 区间DP

区间 DP 的复杂度是 $O(n^3)$

> 洛谷P1880-(a,b)合并获得值a+b，若干石子成环(数大于等于0)的最大最小值

```c++
#include <bits/stdc++.h>
#define MAXN 203
const int BIG = 0x7fffffff;
using namespace std;
int mi, mx, n, dpmi[MAXN][MAXN], dpmx[MAXN][MAXN], s[MAXN], a[MAXN], kd;
signed main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    }
    for (int i = 1; i < n + n; ++i)
    {
        s[i] = s[i - 1] + a[i];
    }
    for (int h = 1; h < n; ++h)
    {
        for (int i = 1, j = i + h; i < n + n && j < n + n; i++, j = i + h)
        {
            dpmi[i][j] = BIG;
            kd = s[j] - s[i - 1];
            for (int k = i; k < j; ++k)
            {
                dpmi[i][j] = min(dpmi[i][j], dpmi[i][k] + dpmi[k + 1][j] + kd);
                dpmx[i][j] = max(dpmx[i][j], dpmx[i][k] + dpmx[k + 1][j] + kd);
            }
        }
    }
    mi = BIG;
    for (int i = 1; i <= n; ++i)
    {
        mx = max(mx, dpmx[i][i + n - 1]);
        mi = min(mi, dpmi[i][i + n - 1]);
    }
    printf("%d\n%d", mi, mx);
    return 0;
}
```

> P1063洛谷-如果前一颗能量珠的头标记为m，尾标记为r，后一颗能量珠的头标记为r，尾标记为n，则聚合后释放的能量为m×r×n，新产生的珠子的头标记为m，尾标记为n。给出成环的n和各个标记，求最大能量

```c++
#include <bits/stdc++.h>
#define MAXN 205
#define pr pair<int, int>
using namespace std;
int n, e, a[MAXN][MAXN], b[MAXN], ans;//a为[i,j]内答案
signed main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &b[i]);
		b[i + n] = b[i];
	}
	for (int i = 2; i <= n + 1; ++i)//区间长
	{
		for (int lf = 1, rf = lf + i - 1; rf <= n + n; ++lf, ++rf)
		{
			for (int k = lf + 1; k <= rf - 1; ++k)
			{
				a[lf][rf] = max(a[lf][rf], a[lf][k] + a[k][rf] + b[lf] * b[k] * b[rf]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) ans = max(ans, a[i][i + n]);
	printf("%d", ans);
	return 0;
}
```



#### 状压DP

枚举每个二进制状态，并降序枚举每个状态的子集状态，复杂度为 $O(3^n)$

```c++
for (int m = 0; m < (1 << n); ++m)// 降序遍历 m 的非空子集
  for (int s = m; s; s = (s - 1) & m) // s 是 m 的一个非空子集
```



> 洛谷P1896-在 $n\times n$ 格子放 $k$ 人，每人周围八方向不得有人，求方案数 $1\le n\le9,0\le k\le n^2$

设每一行的状态为 $j$ ，即 $n$ 个 $0/1$ 组合的 $2^n$ 个状态，设 $dp[i][j][k]$ 表示只考虑前 $i$ 行，第 $i$ 行的分布为 $j$ ，已经放置了 $k$ 个人的方案数；先暴力处理一行内所有可能的情况(某状态对应多少个人)

复杂度 $O(2^n+n2^{2n})$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define MAXN 514//2^n
#define N 12//dp的第三维度(从左往右数)定11或以下会WA
ll sit[MAXN], gs[MAXN], cnt, n, k, dp[N][MAXN][N], ans;
void dfs(ll h, ll sum, ll po)
{//现在是状态h,有sum个人,现在处理第po位
	if (po >= n)//处理完了
	{//一行内所有可能的状态(编号)数量为cnt;cnt<2^n,优化后续DP
		sit[++cnt] = h;//该编号对应二进制状态h
		gs[cnt] = sum;//该编号有多少个人(1数目)
		return;
	}
	dfs(h, sum, po + 1);//该位选与不选
	dfs(h + (1 << (int)po), sum + 1, po + 2);
}
signed main()
{
	scanf("%lld%lld", &n, &k);
	dfs(0, 0, 0);
	repe(i, 1, cnt) dp[1][i][gs[i]] = 1;
	repe(i, 2, n) repe(j, 1, cnt) repe(a, 1, cnt)
	{//上下//左上右下//右上左下有人冲突
		if (sit[j] & sit[a] || (sit[j] << 1) & sit[a] || sit[j] & (sit[a] << 1)) continue;
        for(ll s=k;s>=gs[j];--s) dp[i][j][s] += dp[i - 1][a][s - gs[j]];
	}
	repe(i, 1, cnt) ans += dp[n][i][k];
	printf("%lld", ans);
	return 0;
}
```



#### 数位DP

> lc233-问 $[1,n](n\le 10^9)$ 的整数出现了多少个 $1$

$f$ 是从左到右构造好了 $i$ 个位，造好里已经出现了 $cnt_1$ 个 $1$，当前位是否被 $n$ 限制。$dp$ 是已造好 $i$ 个位，出现了 $j$ 个 $1$ 的答案。$O(\log^2n)$。

```c++
const int M = 15;
int countDigitOne(int n) {
    auto s = to_string(n);
    int m = s.length();
    int dp[M][M];
    memset(dp, -1, sizeof(dp));
    function<int(int, int, bool)> f = [&](int i, int cnt1, bool is_limit) -> int {
        if (i == m) return cnt1;
        if (!is_limit && dp[i][cnt1] >= 0) return dp[i][cnt1];
        int res = 0;
        for (int d = 0, up = is_limit ? s[i] - '0' : 9; d <= up; ++d) // 枚举要填入的数字 d
            res += f(i + 1, cnt1 + (d == 1), is_limit && d == up);
        if (!is_limit) dp[i][cnt1] = res;
        return res;
    };
    return f(0, 0, true);
}
```





> 牛客2022寒假第五场D-求区间 $[l,r]$ 内满足如下条件的数字个数①相邻两数位和是素数 ②至少有一个数位1 ③无前导0 $1\le l\le r\le10^{10}$

设 $dp[i][j][k]$ 表示从个位开始数的 i 位，最大的位数字是 j ， k 表示是否出现过 1，相邻数位和都是数组的方案数，即 $i$ 位数区间 $[\overline{j0\cdots 0},\overline{j9\cdots 9}]$ 范围

根据定义，初始化为 $dp[1][1][1]=1$ , $dp[1][j][0]=1 (0\le j\le 9, j\neq 1)$ ，表示十个个位数的情况

递推方程为若 $j+j'$ 是素数，那么 $k'=k\cup k'\cup j==1\cup j'==1$  时可以加上去(具体看代码)

特别地，设 $dd[i]$ 表示区间 $[1,10^{i-1}-1]$ 的答案，则：
$$
dd[i]=dd[i-1]+\sum_{j=1}^9dp[i-1][j][1]
$$
对 $[1, r]$ 的区间内的答案计数，对 $r=\overline{a_k\cdots a_2a_1}$ ，先用 $dd[k]$ 计数前 $k$ 位数的答案，然后讨论 $k$ 位数答案，对第 $i$ 位，$> i$ 的位都取 $r$ 值即 $a_h(h > i)$，第 $i$ 位进行枚举 $[0, a_i)$ ，得到一个范围内的答案；注意若 $> i$ 时出现过 $1$ ，则 $dp$ 第三维度任取，否则只能取 $1$

答案为 $[1,r]$ 内答案减去 $[1,l-1]$ 内答案

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define sc(x) scanf("%lld", &x)
ll dp[12][12][2]; //后i位,最高位为j,是否出现过1,相邻数位和为素数的方案数
ll prime[] = {2, 3, 5, 7, 11, 13, 17}, ps = 7;
ll l, r, res;
ll dd[12]; //[1,10^(i-1)-1]内的答案
ll ispr(ll x)
{
    for (ll i = 0; i < ps; ++i)
    {
        if (x == prime[i])
        {
            return 1;
        }
    }
    return 0;
}
ll ask(ll rf)
{
    res = 0;
    if (rf <= 9 && rf >= 1)
    {
        return 1;
    }
    ll bs = 0;
    ll b[12] = {};
    for (ll i = rf; i; i /= 10)
    {
        ++bs;
        b[bs] = i % 10;
    }
    ll ever1 = 0, ever2 = 0;
    for (ll i = bs; i >= 1; --i)
    {
        ll je = b[i] + (i == 1);
        if (je > 0 && i > 1 && !ever2)
        {
            res += dd[i];
            ever2 = 1;
        }
        ll jb = 1 - (i != bs);
        for (ll j = jb; j < je; ++j)
        {
            ll k = (i > 1) ? 1 : ((j == 1) ? 1 : !ever1);
            if (i != bs && !ispr(b[i + 1] + j))
            {
                continue;
            }
            res += dp[i][j][k];
            if (ever1)
            {
                res += dp[i][j][k ^ 1];
            }
        }
        ever1 |= (b[i] == 1);
        if (i != bs && !ispr(b[i] + b[i + 1]))
        {
            break;
        }
    }
    return res;
}
ll bfcheck(ll lf, ll rf)
{
    ll cnt = 0;
    for (ll h = lf; h <= rf; ++h)
    {
        ll has1 = 0;
        ll bs = 0;
        ll b[12] = {};
        for (ll j = h; j; j /= 10)
        {
            ++bs;
            b[bs] = j % 10;
            has1 |= (b[bs] == 1);
        }
        if (bs == 1)
        {
            cnt += (h == 1);
            continue;
        }
        ll ok = 1;
        for (ll i = 1; i < bs; ++i)
        {
            ll isprime = ispr(b[i] + b[i + 1]);
            if (isprime == 0)
            {
                ok = 0;
                break;
            }
        }
        if (ok && has1)
        {
            ++cnt;
        }
    }
    return cnt;
}
signed main()
{
    dp[1][1][1] = 1;
    for (ll i = 2; i <= 9; ++i)
    {
        dp[1][i][0] = 1; //没有相邻，条件1恒成立
    }
    dp[1][0][0] = 1;
    for (ll i = 2; i <= 11; ++i)
    {
        for (ll x = 0; x <= 9; ++x)
        {
            ll now0 = (x == 1);
            for (ll y = 0; y <= 9; ++y)
            {
                for (ll pr = 0; pr <= 1; ++pr)
                {
                    ll has0 = now0 || ((y == 1) || pr);
                    ll s = x + y;
                    ll isprime = 0;
                    for (ll j = 0; j < ps; ++j)
                    {
                        if (s == prime[j])
                        {
                            isprime = 1;
                            break;
                        }
                    }
                    if (!isprime)
                    {
                        continue;
                    }
                    dp[i][x][has0] += dp[i - 1][y][pr];
                }
            }
        }
    }
    for (ll i = 2; i <= 11; ++i)
    {
        dd[i] = dd[i - 1];
        for (ll j = 1; j <= 9; ++j)
        {
            dd[i] += dp[i - 1][j][1];
        }
    }
    sc(l), sc(r);
    ll ar = ask(r), al = ask(l - 1);
    printf("%lld", ar - al);
    return 0;
}
```





### 杂项

#### 最长公共子序列

LCS, 如abcbdab,bdcaba的最长子序列是bcba

```c++
int c[N+1][N+1];//c[i][j]代表Xi与Yj的LCS长度
int lcs(string X, string Y)
{
    int m = X.size();
    int n = Y.size();
    int maxl = 0;
    X = ' ' + X;
    Y = ' ' + Y;
    for(int i=1;i<=m;i++) c[i][0] = 0;
    for(int j=1;j<=n;j++) c[0][j] = 0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(X[i]==Y[j]) c[i][j] = c[i-1][j-1] + 1;
            else c[i][j] = max(c[i-1][j], c[i][j-1]);
            maxl = max(maxl, c[i][j]);
        }
    }
    return maxl;
}
```



#### 编辑距离

> lc72-有字符串x,y；每次只能进行如下编辑的一种：删除/插入/修改一个字符，求最小编辑次数，使x=y。

定义$dp[i][j]$表示将长为i的x子串编辑为长为j的y子串的编辑距离。

```c++
int minDistance(string s, string t) {
    int n = s.length(), m = t.length(), f[2][m + 1];
    for (int j = 0; j <= m; ++j) f[0][j] = j;
    for (int i = 0; i < n; ++i) {
        f[(i + 1) % 2][0] = i + 1;
        for (int j = 0; j < m; ++j)
            f[(i + 1) % 2][j + 1] = s[i] == t[j] ? f[i % 2][j] : min(min(f[i % 2][j + 1], f[(i + 1) % 2][j]), f[i % 2][j]) + 1;
    }
    return f[n % 2][m];
}
```



#### 约瑟夫问题

$n$ 人从 $1$ 开始编号排列成环，每次数到第 $q$ 个人杀掉，求最后活着的人编号

当 $q=2$ 时，$n=2^k, J=1$ ，否则 $J(2^k+t)=2t+1$ (做掉$t$人后，变成了一个$2^k$环，在这个$2^k$环上，最后活下来的是环的第一个人)

一般情况(设编号从 $0$ 开始)： $J_{n,q}=(J_{n-1,q}+q)\bmod n$ ，初始状态为 $J_{1,q}=0$



## 字符串

### 字符串哈希

$$
\begin{cases}
h(1)=s_1\\
h(i)=h(i-1)\times p+s_i\quad ,i > 1
\end{cases}\bmod2^{64}
$$

$$
h(x)=\sum_{i=1}^{x}s_i\cdot p^{x-i}=s_1p^{x-1}+s_2p^{x-2}+\cdots +s_xp^0\bmod2^{64}
$$

对子串 $S[l..r]$ ，有  $h(S[l..r])=h(S[1..r])-h(S[1..l-1])\times p^{r-l+1}$

> 以字符串匹配为例 SCNUOJ1713 求 $s$ 里 $t$ 的每个出现位置下标

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mn 2000010
char s[mn], t[mn];
ull p = 131, pw[mn], h[mn], ht, n, m, cnt;
signed main()
{
    pw[0] = 1;
    for (ll i = 1; i < mn; ++i)
    {
        pw[i] = pw[i - 1] * p;
    }
    scanf("%s%s", s, t);
    n = strlen(s), m = strlen(t);
    for (ull i = 0; i < n; ++i)
    {
        h[i + 1] = h[i] * p + s[i];
    }
    for (ull i = 0; i < m; ++i)
    {
        ht = ht * p + t[i];
    }
    for (ull lf = 1, rf = m; rf <= n; ++lf, ++rf)
    {
        if (h[rf] - h[lf - 1] * pw[rf - lf + 1] == ht)
        {
            printf("%lld ", lf), ++cnt;
        }
    }
    if (!cnt)
    {
        printf("-1"); // not found
    }
    return 0;
}
```



### KMP

$\pi(x)$ 是长为 $x$ 的子串最长真前缀与真后缀相等的长度；无解为 $0$ 

> 以字符串匹配为例 SCNUOJ1713

```c++
#include <bits/stdc++.h>
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
```

应用：

- 定义 $\exists p\in N,\forall i\in [1,|S|-p]$ 都有 $S[i]=S[i+p]$ ，那么 $p$ 是 $S$ 的周期，则最短周期为 $|S|-\pi(|S|)$ (SCNUOJ1716)

  定义 $S$ 的 border 是前缀和后缀相等的一段前缀。所有 border 长度为 $\pi(|S|),\pi(\pi(S)),\cdots$ 。周期数等于 border 数且串长-周期长度=border长度。

- 串 $S$ 的每个真前缀在串 $S$ 出现次数：(SCNUOJ1717)

  ```c++
  fill(ans + 1, ans + 1 + n, 1);
  for (ll i = n; i >= 1; --i)
      ans[kmp[i]] += ans[i];
  ```

  串 $S$ 的每个真前缀在串 $T$ 出现次数：(SCNUOJ1718)

  重构 $S=S+$ `#` $+T$ ，继续执行上述过程 ( $n'=n+m+1$ )，取 $ans_{1..n}$ 
  
- 将 $s$ 拼接最小长度字符串使其成为回文串 (lc214)

  设 $s$ 为模式串，$s'$ (逆)为原串，用 KMP 在 $s'$ 里匹配出最长的 $s$ 前缀，就是最长的回文串。也可以 manacher 或字符串哈希做
  
- 环上长为 $n$ 的回文串数目(多边形对称轴)  (p3454)

  二倍长链 $s$ 并求单倍长逆 $t'$，求 $s$ 中 $t'$ 的数目



### manacher

> 洛谷P3805-只由小写英文字符组成，求：最长回文子串长度

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 22000010
char s[mn], ch;
int p[mn], n, ans, r, c;
signed main()
{
    s[0] = '^', s[++n] = '#';
    while (EOF != (ch = getchar()))
        s[++n] = ch, s[++n] = '#';
    s[n + 1] = '?'; // 多次询问清尾
    for (int i = 1; i <= n; ++i)
    {
        if (i <= r)
            p[i] = min(p[c * 2 - i], r - i + 1);
        while (s[i + p[i]] == s[i - p[i]])
            ++p[i];
        if (i + p[i] > r)
            r = p[i] + i - 1, c = i;
        ans = max(ans, p[i]);
    }
    printf("%d", ans - 1);
    return 0;
}
```

回文子串数目：$\sum\lfloor\dfrac{p_i}2\rfloor$。

最长回文前缀：$i-p_i+1=1$ 时更新最值为 $2p_i-1$。

长为 $2k$ 的回文串数目(p3454)：`for(int i=2*k+1;i<=4*k;i++)res+=(p[i]>=n);`



### 字典树

> 主要是01字典树相关的一些总结。

对多个数 $a$ 找一个数 $a_i$ 使得所有 $a$ 里 $a_i$ 异或指定数 $k$ 得到的值 $r$ 最大：

对这些数 $a$ 建立01trie，然后以 $k$ 遍历 trie ，贪心选择与 $k$ 二进制数位相反的路径

```c++
ll res = 0, u = rt; //取字典树根节点
for(ll i = 11; i >= 0; --i)
{
    ll c = (k >> i) & 1; //k的第i位是c
    if (ch[u][c ^ 1]) //存在该位相反的数a,异或得1<<i
        u = ch[u][c ^ 1], res += (1 << i);
    else u = ch[u][c];//不存在
} //伪代码
```



### AC自动机

失配指针：状态 $u$ 的失配指针 $fail$ 指向另一个状态 $v$ ，满足 $v$ 是 $u$ 的最长后缀。复杂度 $O(Cn)$ 

> 洛谷P3808-求有多少个模式串在主串出现过(模式串和,主串长度 $\le10^6$ )

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 1000010
int tr[mn][26], cnt, e[mn], fail[mn];
ll n, ans;
char s[mn];
queue<int> q;
signed main()
{
    sc(n);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%s", s + 1);
        int u = 0;
        for (int i = 1; s[i]; ++i)
        {
            int a = s[i] - 'a';
            if (!tr[u][a])
            {
                tr[u][a] = ++cnt;
            }
            u = tr[u][a];
        }
        ++e[u];
    }
    for (ll i = 0; i < 26; ++i)
    {
        if (tr[0][i])
        {
            q.push(tr[0][i]);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; ++i)
        {
            if (tr[u][i])
            {
                fail[tr[u][i]] = tr[fail[u]][i];
                q.push(tr[u][i]);
            }
            else
            {
                tr[u][i] = tr[fail[u]][i];
            }
        }
    }
    scanf("%s", s + 1);
    int u = 0;
    for (int i = 1; s[i]; ++i)
    {
        int a = s[i] - 'a';
        u = tr[u][a];
        for (int j = u; j && e[j] != -1; j = fail[j])
        {
            ans += e[j], e[j] = -1;
        }
    }
    printf("%lld", ans);
    return 0;
}
```

> 洛谷P3796-求所有出现次数最多的字符串(每个模式串长度不超过 $70$ )

思路：对模式串AC自动机，对主串遍历时每个遍历到的节点，不断跳 fail ，跳到的点对应的模式串出现次数都加一，复杂度 $O(70n+Cn)$ 

> 洛谷P5357-求每个模式串的出现次数，模式串总长度不超过 $2\times10^5$ 

思路：在P3796基础上，对模式串 $T$ 去个重。建自动机时，把每个真实连接的 fail 指针(而不是失配 fail) 指向的节点增加一个入度，使用拓扑排序跳 fail ，复杂度 $O(|S|+26|T|)$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 200010
#define alp 26
ll n, cnt, ss;
ll tr[mn][alp], idx[mn], nti[mn], fail[mn], in[mn], ans[mn], vis[mn];
char t[mn], s[mn * 10];
signed main()
{
    sc(n);
    for (ll i = 1, ts; i <= n; ++i)
    {
        scanf("%s", t + 1);
        ts = strlen(t + 1);
        ll p = 0;
        for (ll j = 1, ti; j <= ts; ++j)
        {
            ti = t[j] - 'a';
            if (tr[p][ti] == 0)
            {
                tr[p][ti] = ++cnt;
            }
            p = tr[p][ti];
        }
        if (idx[p] == 0)
        {
            idx[p] = i;
        }
        nti[i] = idx[p];
    }
    queue<ll> q;
    for (ll i = 0; i < alp; ++i)
    {
        if (tr[0][i])
        {
            q.push(tr[0][i]);
        }
    }
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (ll i = 0; i < alp; ++i)
        {
            if (tr[u][i])
            {
                fail[tr[u][i]] = tr[fail[u]][i];
                ++in[fail[tr[u][i]]];
                q.push(tr[u][i]);
            }
            else
            {
                tr[u][i] = tr[fail[u]][i];
            }
        }
    }
    scanf("%s", s + 1);
    ss = strlen(s + 1);
    for (ll i = 1, p = 0; i <= ss; ++i)
    {
        p = tr[p][s[i] - 'a'];
        ++ans[p];
    }
    for (ll i = 0; i <= cnt; ++i)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        vis[idx[u]] = ans[u];
        ll v = fail[u];
        ans[v] += ans[u];
        if (--in[v] == 0)
        {
            q.push(v);
        }
    }
    for (ll i = 1; i <= n; ++i)
    {
        printf("%lld\n", vis[nti[i]]);
    }
    return 0;
}
```





### 后缀数组

#### 基础

下标从 $1$ 开始，后缀 $i$ 表示以第 $i$ 个字符开头的后缀。后缀间大小比较依据是字典序

数组 `sa[i]` 表示将所有后缀排序后第 $i$ 小后缀的编号

数组 `rk[i]` 表示后缀 $i$ 的排名

满足性质： `sa[rk[i]] == rk[sa[i]] == i`

定义 $LCP(x,y)$ 为后缀 $x,y$ 的最长公共前缀 

定义 `height[i]` ： 为 $LCP(sa[i],sa[i-1])$ ，规定 $height[1]=0$

定义：`H[i]` : 为 $height[rk[i]]$

性质： $H[i]\ge H[i-1]-1$  

洛谷P3809 $|S|\le10^6$ ; 复杂度 $O(n\log n)$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 1000010
char s[mn];
ll n, sa[mn], rk[mn], oldrk[mn << 1], id[mn], px[mn], cnt[mn];
bool cmp(ll x, ll y, ll w)
{
    return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];
}
ll m = 300, i, p, w; //ASCII范围<300为计数排序值域,p是新值域
signed main()
{
    scanf("%s", s + 1), n = strlen(s + 1);
    for (ll i = 1; i <= n; ++i)
    { //暂时以第一关键字为排序值，有很多同名并列
        ++cnt[rk[i] = s[i]];
    }
    for (ll i = 1; i <= m; ++i)
    {
        cnt[i] += cnt[i - 1];
    }
    for (ll i = n; i >= 1; --i)
    {
        sa[cnt[rk[i]]--] = i;
    }
    for (w = 1;; w <<= 1, m = p)
    {
        for (p = 0, i = n; i > n - w; --i)
        { //第二关键字排序；无穷小区域
            id[++p] = i;
        }
        for (ll i = 1; i <= n; ++i)
        {
            if (sa[i] > w)
            {
                id[++p] = sa[i] - w;
            }
        }
        memset(cnt, 0, sizeof cnt);
        for (ll i = 1; i <= n; ++i) //第一关键字排序
        {
            ++cnt[px[i] = rk[id[i]]];
        }
        for (ll i = 1; i <= m; ++i)
        {
            cnt[i] += cnt[i - 1];
        }
        for (ll i = n; i >= 1; --i)
        {
            sa[cnt[px[i]]--] = id[i];
        }
        memcpy(oldrk, rk, sizeof rk);
        for (p = 0, i = 1; i <= n; ++i)
        {
            rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
        }
        if (p == n)
        {
            for (ll i = 1; i <= n; ++i)
            {
                sa[rk[i]] = i;
            }
            break;
        }
    }
    for (ll i = 1; i <= n; ++i)
    {
        printf("%lld ", sa[i]);
    }
    return 0;
}
```

$O(n)$ 求 height 数组：

```c++
for (i = 1, k = 0; i <= n; ++i) {
  if (rk[i] == 0) continue;
  if (k) --k;
  while (s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
  height[rk[i]] = k;
}
```

应用：

- 字符串匹配：模式串 $T$ 若出现必然是主串 $S$ 后缀的前缀，二分 $sa$ ，复杂度为 $O(|T|\log|S|)$ ，可以一并求出出现次数和位置
- 字典序最大子串：必然是一个后缀，对全体后缀跑后缀数组即可
- 求两字符串的最长公共子串：将其拼接起来，求 height数组最值(取得 height 的两项要求一个在左原串一个在右)
- 求循环同构串里字典序最小的 (最小表示法算法的第二解法) (可以离散化)
- 两子串的最长公共前缀 $lcp(sa[i],sa[j])=\min(height[i+1..j])$ 
- 比较两个子串的大小关系： $A=S[a..b],B=S[c..d]$ ，若 $lcp(a,c)\ge \min(|A|,|B|)，A < B\Leftrightarrow |A|<|B|$ ，否则 $A < B\Leftrightarrow rk[a] < rk[c]$ 
- 本质不同的子串的数目 $\dfrac{n(n+1)}2-\sum_{i=2}^nheight[i]$
- 出现至少 k 次的子串的最大长度：出现至少 k 次意味着后缀排序后有至少连续 k 个后缀的 LCP 是这个子串。所以，求出每相邻 k-1 个 height 的最小值，再求这些最小值的最大值就是答案。可以使用单调队列 $O(n)$ 解决
- 是否有某字符串在文本串中至少不重叠地出现了两次：可以二分目标串的长度 |s|，将 h 数组划分成若干个连续 LCP 大于等于 |s| 的段，利用 RMQ 对每个段求其中出现的数中最大和最小的下标，若这两个下标的距离满足条件，则一定有长度为 |s| 的字符串不重叠地出现了两次
- 连续的若干个相同子串：枚举连续串的长度 |s| ，按照 |s| 对整个串进行分块，对相邻两块的块首进行 LCP 与 LCS 查询



#### LCP

> 例：求 LCP 和 LCS(两前缀的最长公共后缀)

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mn = 1e6 + 10;
struct suffixArray
{
    ll n, m; // m是字符集(char)大小
    ll sa[mn], rk[mn * 2], hei[mn], ct[mn], s2[mn], r1[mn];
    char *s;
    void calcSA()
    {
        for (ll i = 0; i <= m; ++i)
        {
            ct[i] = 0;
        }
        for (ll i = n + 1; i <= n * 2; ++i)
        {
            rk[i] = 0;
        }
        for (ll i = 1; i <= n; ++i)
        {
            rk[i] = s[i];
            ct[rk[i]]++;
        }
        for (ll i = 1; i <= m; ++i)
        {
            ct[i] += ct[i - 1];
        }
        for (ll i = n; i >= 1; --i)
        {
            sa[ct[rk[i]]--] = i;
        }
        ll mx = m;
        for (ll j = 1, k = 0; k < n; j *= 2, mx = k)
        {
            ll p = 0;
            for (ll i = n - j + 1; i <= n; ++i)
            {
                s2[++p] = i;
            }
            for (ll i = 1; i <= n; ++i)
            {
                if (sa[i] > j)
                {
                    s2[++p] = sa[i] - j;
                }
            }
            for (ll i = 0; i <= mx; ++i)
            {
                ct[i] = 0;
            }
            for (ll i = 1; i <= n; ++i)
            {
                ct[rk[s2[i]]]++;
            }
            for (ll i = 1; i <= mx; ++i)
            {
                ct[i] += ct[i - 1];
            }
            for (ll i = n; i >= 1; --i)
            {
                sa[ct[rk[s2[i]]]--] = s2[i];
            }
            r1[sa[1]] = k = 1;
            for (ll i = 2; i <= n; ++i)
            {
                if (rk[sa[i - 1]] == rk[sa[i]] && rk[sa[i - 1] + j] == rk[sa[i] + j])
                {
                    r1[sa[i]] = k;
                }
                else
                {
                    r1[sa[i]] = ++k;
                }
            }
            for (ll i = 1; i <= n; ++i)
            {
                rk[i] = r1[i];
            }
        }
    }
    void calcHeight()
    {
        memset(hei, 0, sizeof hei);
        for (ll i = 1, j; i <= n; ++i)
        {
            if (rk[i] == 1)
            {
                continue;
            }
            j = max(hei[rk[i - 1]] - 1, 0LL);
            while (s[i + j] == s[sa[rk[i] - 1] + j])
            {
                ++j;
            }
            hei[rk[i]] = j;
        }
    }
    ll t1[mn][20], lg2[mn];
    void initLCP()
    {
        for (ll i = 2; i <= n; ++i)
        {
            lg2[i] = lg2[i / 2] + 1;
        }
        for (ll i = 1; i <= n; ++i)
        {
            t1[i][0] = hei[i];
        }
        for (ll j = 1; j <= 20; ++j)
        {
            for (ll i = 1; i + (1 << j) - 1 <= n; ++i)
            {
                t1[i][j] = min(t1[i][j - 1], t1[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    void build(char *t)
    {
        s = t, n = strlen(s + 1), m = 'z';
        calcSA();
        calcHeight();
        initLCP();
    }
    ll lcp(ll x, ll y)
    {
        ll l = rk[x], r = rk[y];
        if (l > r)
        {
            swap(l, r);
        }
        ++l;
        ll k = lg2[r - l + 1]; // or __lg(r-l+1);
        return min(t1[l][k], t1[r - (1 << k) + 1][k]);
    }
} s1, s2;
char s[mn];
ll n, t, l, r;
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> s + 1;
    n = strlen(s + 1);
    s1.build(s);
    reverse(s + 1, s + 1 + n);
    s2.build(s);
    for (cin >> t; t; --t)
    {
        cin >> l >> r;
        cout << s1.lcp(l, r) << ' ' << s2.lcp(n - l + 1, n - r + 1) << '\n';
    }
    return 0;
}
```

用单调栈线性求 $\sum_{1\le i < j\le n}lcp(i,j)$，意义：任选两个不同位置子串，子串相同的方案数。一种实现：

```c++
ll lc[mn], rc[mn];
ll calcLCPsum()
{
    stack<ll> a;
    ll sum = 0;
    for (ll i = 1; i <= n + 1; ++i)
    {
        while (!a.empty() && hei[a.top()] > hei[i])
        {
            ll j = a.top();
            a.pop();
            rc[j] = i - j;
        }
        a.push(i);
    }
    stack<ll> b;
    for (ll i = n; i >= 0; --i)
    {
        while (!b.empty() && hei[b.top()] >= hei[i])
        {
            ll j = b.top();
            b.pop();
            lc[j] = j - i;
        }
        b.push(i);
    }
    for (ll i = 1; i <= n; ++i)
    {
        sum += hei[i] * lc[i] * rc[i];
    }
    return sum;
}
```



#### SA-IS

时空复杂度 $O(n)$

> 例：牛客2022暑假3H，长为 $n(n\le 10^5)$ 的 $A$ 串对应权值序列 $v(|v_i|\le10^9)$，有 $k$ 个询问，每次问长为 $m(m,k\le10^5,mk\le10^6)$ 的 $B$ 串所有子串能匹配到所有 $A$ 的子串区间里，区间和最大值

后缀数组求高度数组 lcp，即第 $i$ 大后缀与第 $i+1$ 大后缀的最长公共前缀，在其上面建立 ST 表，可求任意两后缀的 LCP 为 $query_{\min}(rank_x, rank_y - 1)$，假设 $rank_x < rank_y$。

对 $B_i$ 的每个位置 $j(1\le j\le m)$，求 $j$ 开始的最长子串，且在 A 出现过，即找到最长 $len$，满足 $B[j..j+len-1]$ 是 $A$ 子串。再找 $j$ 为左端点，长在 $len$ 内所有区间权值和最大值，即 $\max(\sum_{k=j}^lv_k)(j\le l\le j+len-1)$。这部分对数组 $v$ 前缀和数组建 ST 表，求 $[j,j+len-1]$ 区间最大值。

将 $A$ 和所有 $B_i$ 以 `$` 或其他不在字符集的分割符连起来得到 $S$，对 $S$ 跑后缀数组，维护每个 $B_i$ 在 $S$ 的起始下标，第 $i$ 个字符对应原来哪个串。(注意 $A,B$ 间用别的分割符)

按字典序遍历所有后缀，可以知道当前后缀对应哪个 $B_i$ 或 $A$，若当前后缀对应 $B_i$，找到离它最近的属于 $A$ 的后缀，求 $lcp$ 即上文的 $len$。

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
const ll mn = 1.2e6 + 5;
char s[mn];
// begin SA-IS
ll sa[mn], rk[mn], lcp[mn];
ll str[mn * 2], ty[mn * 2], p[mn], cnt[mn], cur[mn];
#define pushs(x) sa[cur[str[x]]--] = x
#define pushl(x) sa[cur[str[x]]++] = x
void sais(ll n, ll m, ll *str, ll *ty, ll *p)
{
    ll n1 = ty[n - 1] = 0, ch = rk[0] = -1, *s1 = str + n;
    for (ll i = n - 2; ~i; --i)
    {
        ty[i] = str[i] == str[i + 1] ? ty[i + 1] : str[i] > str[i + 1];
    }
    for (ll i = 1; i < n; ++i)
    {
        rk[i] = ty[i - 1] && !ty[i] ? (p[n1] = i, n1++) : -1;
    }

    auto induce_sort = [&](ll *v)
    {
        fill_n(sa, n, -1);
        fill_n(cnt, m, 0);
        for (ll i = 0; i < n; ++i)
        {
            cnt[str[i]]++;
        }
        for (ll i = 1; i < m; ++i)
        {
            cnt[i] += cnt[i - 1];
        }
        for (ll i = 0; i < m; ++i)
        {
            cur[i] = cnt[i] - 1;
        }
        for (ll i = n1 - 1; ~i; --i)
        {
            pushs(v[i]);
        }
        for (ll i = 1; i < m; ++i)
        {
            cur[i] = cnt[i - 1];
        }
        for (ll i = 0; i < n; ++i)
        {
            if (sa[i] > 0 && ty[sa[i] - 1])
            {
                pushl(sa[i] - 1);
            }
        }
        for (ll i = 0; i < m; ++i)
        {
            cur[i] = cnt[i] - 1;
        }
        for (ll i = n - 1; ~i; --i)
        {
            if (sa[i] > 0 && !ty[sa[i] - 1])
            {
                pushs(sa[i] - 1);
            }
        }
    };
    induce_sort(p);
    for (ll i = 0, x, y; i < n; ++i)
    {
        if (~(x = rk[sa[i]]))
        {
            if (ch < 1 || p[x + 1] - p[x] != p[y + 1] - p[y])
            {
                ++ch;
            }
            else
            {
                for (ll j = p[x], k = p[y]; j <= p[x + 1]; ++j, ++k)
                {
                    if ((str[j] << 1 | ty[j]) != (str[k] << 1 | ty[k]))
                    {
                        ++ch;
                        break;
                    }
                }
            }
            s1[y = x] = ch;
        }
    }
    if (ch + 1 < n1)
    {
        sais(n1, ch + 1, s1, ty + n, p + n1);
    }
    else
    {
        for (ll i = 0; i < n1; ++i)
        {
            sa[s1[i]] = i;
        }
    }
    for (ll i = 0; i < n1; ++i)
    {
        s1[i] = p[sa[i]];
    }
    induce_sort(s1);
}
ll cti(ll n)
{
    ll m = *max_element(s, s + n);
    fill_n(rk, m + 1, 0);
    for (ll i = 0; i < n; ++i)
    {
        rk[s[i]] = 1;
    }
    for (ll i = 0; i < m; ++i)
    {
        rk[i + 1] += rk[i];
    }
    for (ll i = 0; i < n; ++i)
    {
        str[i] = rk[s[i]] - 1;
    }
    return rk[m];
}
void make_sa(ll n)
{
    // s[n] 一定要比 s 中所有字符 ascii 值小, s[n+1] 倒无所谓
    s[n] = '!', s[n + 1] = '\0';
    ll m = cti(++n);
    sais(n, m, str, ty, p);
    for (ll i = 0; i < n; ++i)
    {
        rk[sa[i]] = i;
    }
    for (ll i = 0, h = lcp[0] = 0; i < n - 1; ++i)
    {
        ll j = sa[rk[i] - 1];
        while (i + h < n && j + h < n && s[i + h] == s[j + h])
        {
            ++h;
        }
        lcp[rk[i] - 1] = h;
        if (lcp[rk[i] - 1])
        {
            --h;
        }
    }
    s[n] = '\0';
}
// end SA-IS
const ll mm = 1e5 + 5, mlg = 20;
ll st[mm][mlg], lg[mm], prf[mm];
void build_st(ll n)
{
    for (ll i = 1; i <= n; ++i)
    {
        st[i][0] = prf[i];
    }
    for (ll k = 1, len = 2; len <= n; len <<= 1, ++k)
    {
        for (ll i = 1; i + len - 1 <= n; ++i)
        {
            st[i][k] = max(st[i][k - 1], st[i + len / 2][k - 1]);
        }
    }
}
ll query(ll x, ll y)
{
    ll k = lg[y - x + 1];
    return max(st[x][k], st[y - (1 << k) + 1][k]);
}
ll v[mm], bg_pos[mm], ans[mm], maps[mn], n, m, k;
signed main()
{
    lg[1] = 0;
    for (ll i = 2; i < mm; ++i)
    {
        lg[i] = lg[i >> 1] + 1;
    }
    sc(n), sc(m), sc(k), scanf("%s", s);
    for (ll i = 1; i <= m; ++i)
    {
        sc(v[i]);
    }

    ll tot = n - 1;
    for (ll i = 1; i <= k; ++i)
    {
        ++tot;
        s[tot] = '$', maps[tot] = -1;
        bg_pos[i] = tot + 1;
        scanf("%s", s + tot + 1);
        for (ll j = tot + 1; j <= tot + m; ++j)
        {
            maps[j] = i;
        }
        tot += m;
    }
    s[n] = '#';
    ++tot;
    make_sa(tot);

    // printf("%s\n", s);
    // for (ll i = 0; i <= tot; ++i)
    // {
    //     printf("%3lld %3lld %3lld %s\n", i, sa[i], lcp[i], s + sa[i]);
    // }

    for (ll i = 1; i <= m; ++i)
    {
        prf[i] = prf[i - 1] + v[i];
    }
    build_st(m);

    ll mi = 0;
    for (ll i = 1; i <= tot; ++i)
    {
        ll j = maps[sa[i]];
        if (j == 0)
        {
            mi = lcp[i];
        }
        else
        {
            if (j > 0 && mi > 0) //不是分隔符，有公共
            {
                ll idx = sa[i] - bg_pos[j] + 1; // B_j起始下标
                ll mx = query(idx, idx + mi - 1);
                ans[j] = max(ans[j], mx - prf[idx - 1]);
            }
            mi = min(mi, lcp[i]);
        }
    }

    mi = 0;
    for (ll i = tot; i; --i)
    {
        ll j = maps[sa[i]];
        if (j == 0)
        {
            mi = lcp[i - 1];
        }
        else
        {
            if (j > 0 && mi > 0) //不是分隔符，有公共
            {
                ll idx = sa[i] - bg_pos[j] + 1; // B_j起始下标
                ll mx = query(idx, idx + mi - 1);
                ans[j] = max(ans[j], mx - prf[idx - 1]);
            }
            mi = min(mi, lcp[i - 1]);
        }
    }
    for (ll i = 1; i <= k; ++i)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
```





### 后缀自动机

构造时空复杂度 $O(n)$ ，在线算法

> 洛谷P3804-求出现次数不为 $1$ 的子串的出现次数乘长度的最大值

```c++
#include<cstdio>
#include<algorithm>
using namespace std;const int N=3*1e6+10;typedef long long ll;
char mde[N];int nl;ll res;
struct suffixautomation
{
    int mp[N][30];int fa[N];int ed;int ct;int len[N];int siz[N];
    suffixautomation(){ed=ct=1;}
    int v[N];int x[N];int al[N];int cnt;
    inline void add(int u,int V){v[++cnt]=V;x[cnt]=al[u];al[u]=cnt;}
    inline void ins(int c) 
    {
        int p=ed;siz[ed=++ct]=1;len[ed]=nl;//先初始化size和len 
        for(;p&&mp[p][c]==0;p=fa[p]){mp[p][c]=ed;}//然后顺着parent树的路径向上找 
        if(p==0){fa[ed]=1;return;}int q=mp[p][c];//case1 
        if(len[p]+1==len[q]){fa[ed]=q;return;}//case2
        len[++ct]=len[p]+1;//case 3
        for(int i=1;i<=26;i++){mp[ct][i]=mp[q][i];}
        fa[ct]=fa[q];fa[q]=ct;fa[ed]=ct;
        for(int i=p;mp[i][c]==q;i=fa[i]){mp[i][c]=ct;}
    }
    inline void bt(){for(int i=2;i<=ct;i++){add(fa[i],i);}}//暴力建树 
    void dfs(int u)//dfs 
    {
        for(int i=al[u];i;i=x[i]){dfs(v[i]);siz[u]+=siz[v[i]];}
        if(siz[u]!=1){res=max(res,(ll)siz[u]*len[u]);}
    }
}sam;
int main()
{
    scanf("%s",mde+1);
    for(nl=1;mde[nl]!='\0';nl++){sam.ins(mde[nl]-'a'+1);}
    sam.bt();sam.dfs(1);printf("%lld",res);return 0;
}
```



### FFT字符串匹配

字符串 $A$ 与 $B$ 以第 $x$ 位结束的连续 $m$ 位完全匹配可以表示为：(从 $0$ 开始下标)
$$
P(x)=\sum_{i=0}^{m-1}[A(i)-B(x-(m-1)+i)]^2
$$
设 $S(x)=A(m-x-1)$ ，则：
$$
P(x)=\sum_{i=0}^{m-1}[S(m-i-1)-B(x-m+i+1)]^2\\

=\sum_{i=0}^{m-1}S(i)^2+\sum_{i=x-m+1}^xB(i)^2-2\sum_{i+j=x}S(i)B(j)
$$
设通配符的ASCII为$0$，则：
$$
C(x,y)=[A(x)-B(y)]^2A(x)B(y)
$$
完全匹配函数即：
$$
P(x)=\sum_{i=0}^{m-1}C(i,x-m+i+1)\\
=\sum_{i+j=x}S(i)^3B(j)+\sum_{i+j=x}S(i)B(j)^3-2\sum_{i+j=x}S(i)^2B(j)^2
$$
带幂的可以先预处理每一项的系数做幂运算。伪代码如下：

```c++
void FFT_match(char *s1,char *s2,int m,int n)
{
	reverse(ss1,ss1+m);
	for(int i=0;i<m;i++) A[i]=(s1[i]!='*')?(s1[i]-'a'+1):0;
	for(int i=0;i<n;i++) B[i]=(s2[i]!='*')?(s2[i]-'a'+1):0;
	
	for(int i=0;i<len;i++) a[i]=Comp(A[i]*A[i]*A[i],0),b[i]=Comp(B[i],0);
	FFT(a,len,1);FFT(b,len,1);
	for(int i=0;i<len;i++) P[i]=P[i]+a[i]*b[i];
	
	for(int i=0;i<len;i++) a[i]=Comp(A[i],0),b[i]=Comp(B[i]*B[i]*B[i],0);
	FFT(a,len,1);FFT(b,len,1);
	for(int i=0;i<len;i++) P[i]=P[i]+a[i]*b[i];
	
	for(int i=0;i<len;i++) a[i]=Comp(A[i]*A[i],0),b[i]=Comp(B[i]*B[i],0);
	FFT(a,len,1);FFT(b,len,1);
	for(int i=0;i<len;i++) P[i]=P[i]-a[i]*b[i]*Comp(2,0);
	
	FFT(P,len,-1);
	for(int i=m-1;i<n;i++) if(fabs(P[i].r)<=1e-7) printf("%d ",i-m+2);
}
```

> 给定带通配符`*`的字符串$a,b,|a|=m,|b|=n$，下标从$1$开始，求$a$的首位作为$b$的第$k$位时能够匹配的所有解和解数目。$1\le m\le n\le3\times10^5$

对 $b$ ，设$P(i)$，一共需要计算$m-n+1$个$P$。事实上，卷积的时候，由于计算的是所有$i\times j$,然后对于某一次只取$i+j=C$的，那么可以对计算出来的结果一次FFT计算后分别累加到不同的$P$上。

```c++
#include <bits/stdc++.h>
using namespace std;
#define db double
const db pi = acos(-1);
#define MAX 1100000
char sa[MAX], sb[MAX];
int m, n, N, top, a[MAX], b[MAX];
int rev[MAX], sta[MAX];
#define il inline
#define ll int
#define re
il ll read()
{
    re char p = 0;
    re ll r = 0, o = 0;
    for (; p < '0' || p > '9'; o |= p == '-', p = getchar())
        ;
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar())
        ;
    return o ? (~r) + 1 : r;
}
struct cpx
{
    double x, y;
    cpx() {}
    cpx(double xx, double yy) { x = xx, y = yy; }
    cpx(int xx, int yy) { x = xx, y = yy; }
    friend cpx operator*(cpx a, cpx b)
    {
        return cpx(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
    }
    friend cpx operator/(cpx a, double b)
    {
        return cpx(a.x / b, a.y / b);
    }
    friend cpx operator+(cpx a, cpx b)
    {
        return cpx(a.x + b.x, a.y + b.y);
    }
    friend cpx operator-(cpx a, cpx b)
    {
        return cpx(a.x - b.x, a.y - b.y);
    }
    friend cpx operator*(cpx a, double b)
    {
        return cpx(a.x * b, a.y * b);
    }
};
cpx A[MAX], B[MAX], C[MAX];
void fft(cpx *a, int f)
{
    for (int i = 0; i < N; i++)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    for (int i = 1; i < N; i <<= 1)
    {
        cpx wn(cos(pi / i), f * sin(pi / i));
        for (int j = 0; j < N; j += (i << 1))
        {
            cpx w(1, 0);
            for (int k = 0; k < i; k++)
            {
                cpx x = a[j + k], y = w * a[j + k + i];
                a[j + k] = x + y;
                a[j + k + i] = x - y;
                w = w * wn;
            }
        }
    }
    if (f == -1)
        for (int i = 0; i < N; i++)
            a[i] = a[i] / N;
}
int main()
{
    scanf("%d%d%s%s", &m, &n, sa, sb);
    reverse(sa, sa + m);
    int l = 0;
    for (N = 1; N < 2 * n; N <<= 1)
    {
        l++;
    }
    for (int i = 0; i < N; i++)
    {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
    }
    for (int i = 0; i < m; i++)
    {
        if (sa[i] != '*')
        {
            a[i] = sa[i] - 'a' + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (sb[i] != '*')
        {
            b[i] = sb[i] - 'a' + 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        A[i] = cpx(a[i] * a[i] * a[i], 0);
    }
    for (int i = 0; i < n; i++)
    {
        B[i] = cpx(b[i], 0);
    }
    fft(A, 1);
    fft(B, 1);
    for (int i = 0; i < N; i++)
    {
        C[i] = C[i] + A[i] * B[i];
    }

    for (int i = 0; i < N; i++)
    {
        A[i] = B[i] = cpx(0, 0);
    }
    for (int i = 0; i < m; i++)
    {
        A[i] = cpx(a[i] * a[i], 0);
    }
    for (int i = 0; i < n; i++)
    {
        B[i] = cpx(b[i] * b[i], 0);
    }
    fft(A, 1);
    fft(B, 1);
    for (int i = 0; i < N; i++)
    {
        C[i] = C[i] - A[i] * B[i] * 2.0;
    }

    for (int i = 0; i < N; i++)
    {
        A[i] = B[i] = cpx(0, 0);
    }
    for (int i = 0; i < m; i++)
    {
        A[i] = cpx(a[i], 0);
    }
    for (int i = 0; i < n; i++)
    {
        B[i] = cpx(b[i] * b[i] * b[i], 0);
    }
    fft(A, 1);
    fft(B, 1);
    for (int i = 0; i < N; i++)
    {
        C[i] = C[i] + A[i] * B[i];
    }

    fft(C, -1);
    for (int i = m - 1; i < n; i++)
    {
        if (fabs(C[i].x) < 0.5)
        {
            sta[top++] = i - m + 2;
        }
    }
    printf("%d\n", top);
    for (int i = 0; i < top; i++)
    {
        printf("%d ", sta[i]);
    }
    return 0;
}
```

### 子序列自动机

对 $S$ 每个字符，升序记录它出现的位置，设字符 $i$ 出现的位置的集合为 $pos_i$。

判断 $T$ 是否是 $S$ 的子序列，每次二分找 $T_i$ 在上一次匹配 $S_j$ 后的最近下标，如果一直能找到则是子序列。复杂度取 $T\log |S|$。

> P5826-字符集大小 $10^5$，$|S|\le10^5,\sum |T|\le 10^6$。上述问题。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define mn 100002
ll n, q, m, type, ii;
vector<ll> v[mn];
signed main()
{
	scanf("%d%d%d%d", &type, &n, &q, &m);
	for(ll i=1;i<=n;++i) scanf("%d", &ii), v[ii].push_back(i);
	while (q--)
	{
		ll len, at = 0, x;
		bool suc = true;
		scanf("%d", &len);
		while (len--)
		{
			scanf("%d", &x);
			if (!suc) continue;
			auto it = lower_bound(v[x].begin(), v[x].end(), at + 1);
			if (it == v[x].end()) suc = false;
			else at = *it;
		}
		printf(suc ? "Yes\n" : "No\n");
	}
	return 0;
}
```

第二种建图方式：$nxt_{i,j}$ 表示 $i$ 位置后的第一个 $j$ 的位置，$0$ 是根节点。

```c++
for(LL i=n;i>=1;--i){
    for(LL j=1;j<=a;++j) nxt[i-1][j]=nxt[i][j];
    nxt[i-1][s[i]]=i;
}
```

> 当字符集较大时，可套用可持久化，在叶子节点放一个 id，表示出边。

将 $T$ 输入自动机，可以检验是否是子序列。

求本质不同子序列个数：记忆化 DFS，设 $x$ 的 DFN 子树有 $f_x$ 个子序列，答案为 $f_0$，转移为 $f_u=1+\sum f_v$。非空就 $f_0-1$。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
vector<ll> nxt[28], f;
ll dfs(int u)
{
    if (f[u])
        return f[u];
    ll ans = 1;
    for (auto i = 1; i <= 26; ++i)
    {
        if (nxt[i][u])
        {
            (ans += dfs(nxt[i][u])) %= mod;
        }
    }
    return f[u] = ans;
}
int distinctSubseqII(string s)
{
    ll n = s.size();
    for (ll j = 1; j <= 26; ++j)
        nxt[j].resize(n + 2, 0);
    for (ll i = n; i >= 1; --i)
    {
        for (ll j = 1; j <= 26; ++j)
            nxt[j][i - 1] = nxt[j][i];
        nxt[s[i - 1] - 'a' + 1][i - 1] = i;
    }
    f.resize(n + 2, 0);
    return (dfs(0) - 1 + mod) % mod;
}
```

求两串公共子序列个数，类比且一下：

```c++
LL Dfs(LL x,LL y){
    if(f[x][y]) return f[x][y];
    for(LL i=1;i<=a;++i)
        if(nxt1[x][i]&&nxt2[y][i])
            f[x][y]+=Dfs(nxt1[x][i],nxt2[y][i]);
    return ++f[x][y];
}
```

回文子序列

```c++
LL Dfs(LL x,LL y){
	if(f[x][y]) return f[x][y];
	for(LL i=1;i<=a;++i)
		if(nxt1[x][i]&&nxt2[y][i]){
			if(nxt1[x][i]+nxt2[y][i]>n+1) continue;
			if(nxt1[x][i]+nxt2[y][i]<n+1) f[x][y]++;
			f[x][y]=(f[x][y]+Dfs(nxt1[x][i],nxt2[y][i]))%mod;
		}
	return ++f[x][y];
}
```



### 最小表示法

> 可以用 SAM, SA, Lyndon 分解等做

求循环同构串里字典序最小的串，复杂度 $O(n)$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans, a[300002], i, j = 1, k;
signed main()
{
	scanf("%lld", &n);
	for(ll i=0;i<n;++i) scanf("%lld", a + i);
	while (i < n && j < n && k < n)
	{
		if (a[(i + k) % n] == a[(j + k) % n]) ++k;
		else
		{
			if (a[(i + k) % n] > a[(j + k) % n]) i += k + 1;
			else j += k + 1;
			if (i == j) ++i; 
			k = 0;
		}
	}
	ans = min(i, j);
	for(ll i=0;i<n;++i) printf("%lld ", a[(i + ans) % n]);
	return 0;
}
```



### Lyndon分解

> SAM 也可以做 Lyndon 分解

对于一个字符串，若其本身就是其最小后缀，则称它为 Lyndon 串，即若一个串的字典序比他所有后缀的字典序小。

任意一个字符串都可以被唯一的分解成若干个字典序非严格递减的 Lyndon 串。对于长度为 n的字符串 s，存在唯一的若干个 Lyndon 串 $t_{1\dots m}$ ，满足 $s=t_1 + t_2 + \cdots + t_m$ 且 $ t_1 \ge t_2 \ge \cdots \ge t_m$。

Duval 算法可以在 $O(n)$ 的时间求出一个字符串的 Lyndon 分解

> 洛谷P6114-求所有Lyndon串右端点的异或和

```c++
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
```

> 改成 `, ans = i <= n ? i : ans` 可以求最小表示法的起点



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

> 例题蓝桥-小朋友排队:将小朋友从低到高排序，每次只能交换相邻两个，交换使得他们不高兴程度增加，增加幅度是上次他增加的数量+1(一开始的上次是0)，求排序后他们的不高兴程度之和的最小值。

总不高兴程度最小时，一个小朋友被交换次数等于他前边比他高的人数+后边比他低的人数，由此可以套用归并排序求逆序对的公式并加以改变：

```c++
#include <bits/stdc++.h>
#define mn 100002
typedef long long ll;
struct pupil
{
	ll v,m;
} a[mn],b[mn];
ll ans,n;
void merges(ll lf, ll rf)
{
	if(lf==rf) return;
	ll cf=lf+rf>>1;
	merges(lf,cf);
	merges(cf+1,rf);
	ll p=lf,q=cf+1,t=lf;
	while(p<=cf&&q<=rf)
	{
		if(a[p].v>a[q].v) a[q].m+=cf+1-p,b[t++]=a[q++];
		else a[p].m+=q-1-cf,b[t++]=a[p++];
	}
	while(q<=rf) b[t++]=a[q++];//+=写成=暴死
	while(p<=cf) a[p].m+=q-1-cf,b[t++]=a[p++];
	for(int i=lf;i<=rf;++i) a[i]=b[i];
}
signed main()
{
	scanf("%lld",&n);
	for(int i=0;i<n;++i) scanf("%lld",&a[i].v);
	merges(0,n-1);
	for(int i=0;i<n;++i) ans+=(a[i].m+1)*a[i].m>>1;
	printf("%lld",ans);
	return 0;
}
```

归并排序求其他内容：

- lc315-每个元素右边比它小的元素数

  归并合并 $a_i\le a_j$ 时，$j$ 是第一个 $\le$ 的，故 $[mid,j)$ 全满足，对当前 $i$ 的原下标累加贡献。用离散化权值树状数组也行。

- lc493-翻转对-求二倍逆序对(前者两倍严格大于后者)的数目

  归并合并前，双指针累加符合的区间数，算完了再合并当前的。

- lc327-区间和在 $[l,u]$ 的区间个数

  归并合并前，双指针累加符合的区间数，算完了再合并当前的。



### 二分

整数三分公式：(以求U型区间最小值/单调区间最小值为例)

```c++
while (lf < rf)
{
    ll tri = (rf - lf) / 3;
    ll lc = lf + tri, rc = rf - tri;
    db lv = calc(lc), rv = calc(rc);
    ans = min({ans, lv, rv});
    if (lv < rv)
    {
        rf = rc - 1;
    }
    else
    {
        lf = lc + 1;
    }
}
```

此三分无法处理 `lv==rv`，可以通过离散化去除连续段。



#### 最长单调序列

LIS (longest increase sequence)

单调栈上二分 复杂度 $O(n\log n)$

Dilworth定理：偏序集的最少反链划分数等于最长链的长度

即：求一个序列最少能分成多少个最长不上升序列，可以求最长上升序列的长度即为答案。其他情况类推。

```c++
#include <bits/stdc++.h>
#define MAXN 100002
#define y1 dy
using namespace std;
int n,a[MAXN],uf[MAXN],df[MAXN],ufl,dfl,x[MAXN],y[MAXN],x1,y1;
int main()
{
    while(EOF!=scanf("%d",&a[++n]));//这样的n比真实+1
    uf[++ufl]=df[++dfl]=a[1];
    x[++x1]=y[++y1]=a[1];
    for(int i=2;i<n;i++)
    {
        if(uf[ufl]>=a[i])uf[++ufl]=a[i];//最长不上升
        else *upper_bound(uf+1,uf+1+ufl,a[i],greater<int>())=a[i];
        
        if(df[dfl]<a[i])df[++dfl]=a[i];//最长上升,与上面互为定律
        else *lower_bound(df+1,df+1+dfl,a[i])=a[i];
        
        if(x[x1]>a[i])x[++x1]=a[i];//最长下降
        else *upper_bound(x+1,x+1+x1,a[i],greater<int>())=a[i];
        
        if(y[y1]<=a[i])y[++y1]=a[i];//最长不下降,与上面互为定律
        else *lower_bound(y+1,y+1+y1,a[i])=a[i];
    }
    printf("\n%d\n%d\n%d\n%d",ufl,dfl,x1,y1);
    return 0;
}
```

规律：

- 对降的(严格降、非严格降(即不升))，一律用 `upper_bound` + `greater<>()` 求第一个小于它的，将这个位置改成更大，得更优解
- 对升的，一律用 `lower_bound` 求第一个大于它的，将这个位置改成更小，得更优解

模板题 

> P1020 导弹拦截  输入至多 $10^5$ 个数，求最长不下降序列的长度和可以划分为多少个最长不下降序列(不是不下降子串)

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 100010
ll n, a[mn], dpnd[mn], dpu[mn], ans, x, nnd, nu;
signed main()
{
    while (EOF != scanf("%lld", &x)) a[++n] = x;
    dpnd[++nnd] = dpu[++nu] = a[1];
    for (ll i = 2; i <= n; ++i)
    {
        if (a[i] <= dpnd[nnd])dpnd[++nnd] = a[i];
        else *upper_bound(dpnd + 1, dpnd + 1 + nnd, a[i], greater<ll>()) = a[i];
        if (a[i] > dpu[nu]) dpu[++nu] = a[i];
        else *lower_bound(dpu + 1, dpu + 1 + nu, a[i]) = a[i];
    }
    printf("%lld\n%lld", nnd, nu);
    return 0;
}
```

> 例题 P2782 友好城市 南北岸有 $n$ 个不同城市，在不同坐标，北岸每个城市与南岸一个城市相连，连线不能相交，求最多能留多少条连线 $1\le n\le2\times10^5,0\le x\le10^6$ 

以一个岸为基准结构体排序，然后求另一个岸的最长单调上升子序列长度即可

> lc354-求长宽同时严格单调上升的最长子序列

先按 $w$ 升序排序，再第二关键字将 $h$ 降序排序，从而避免了相同下存在递增。再第二关键字将 $h$ 降序排序，从而避免了相同下存在递增。



#### 最长公共排列

LCS(longest common sequence)(见DP)

假设元素互不重复，将一个序列重定义为它的每个元素在另一个序列里出现的位置，即设 $h[a[i]]=i$ ，令 $b[i]=h[b[i]]$ 。那么，只需要求该序列的最长上升子序列即可。

> 模板题 P1439 最长公共子排列 $(n\le10^5)$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
#define mn 100010
ll a[mn], b[mn], n, dp[mn], m, h[mn];
signed main()
{
    sc(n);
    for (ll i = 1; i <= n; ++i)
    {
        sc(a[i]);
        h[a[i]] = i;
    }
    for (ll i = 1; i <= n; ++i)
    {
        sc(b[i]);
        b[i] = h[b[i]];
    }
    dp[++m] = b[1];
    for (ll i = 2; i <= n; ++i)
    {
        if (b[i] > dp[m])
        {
            dp[++m] = b[i];
        }
        else
        {
            *lower_bound(dp + 1, dp + 1 + m, b[i]) = b[i];
        }
    }
    printf("%lld", m);
    return 0;
}
```



#### 二分答案

##### 最小中位数子矩阵

> (SCNUOJ1464)有$n\times n$矩阵$a$，找一个$k\times k$子阵，使得在所有$k$阶子阵里，这个子阵的中位数(第$\lfloor\frac{k^2}2+1\rfloor$大数)最小，输出中位数。$1\le k,\le n\le800,0\le a_{i,j}\le10^9$

这题不能暴力枚举(或者用二维双指针法)，无法解决$O(1)$找中位数所以都会TLE。复杂度是$n^3\log n$。

考虑二分，设答案为二分对象，显然这个值越大它的排位越大，所以可以检验排位，从一个方向逐渐逼近中位排位，即$\lfloor\frac{k^2}2+1\rfloor$，每次检验二分值，使得答案逼近于唯一的真实答案。可以证明二分到的一定是存在的最小的中位数。

```c++
#include <bits/stdc++.h> //https://oj.socoding.cn/p/1464
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define repe(i, a, b) for (ll i = a; i <= b; ++i)
#define mn 804
ll n, k, a[mn][mn], s[mn][mn], lf, rf = 1e9, cf, res, t;
bool check()
{ //利用前缀和快速检验中位数
    repe(i, 1, n) repe(j, 1, n) s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (a[i][j] >= cf);
    repe(i, k, n) repe(j, k, n)
    {
        t = s[i][j] + s[i - k][j - k] - s[i][j - k] - s[i - k][j];
        if (t < k * k / 2 + 1)
            return false;
    }
    return true;
}
signed main()
{
    sc(n), sc(k);
    repe(i, 1, n) repe(j, 1, n) sc(a[i][j]);
    while (lf <= rf)
    {
        cf = (lf + rf) >> 1;       //假设存在一个子矩阵的中位数是cf
        if (check())               //如果以cf为中位数不少于k*k/2+1个元素大于它
            lf = cf + 1, res = cf; //那么中位数大于等于cf
        else
            rf = cf - 1; //否则中位数小于cf
    }
    printf("%d", res);
    return 0;
}
```



##### 最大子串平均值

> 例题洛谷P1419-长为n的连续序列，定义平均值为区间和除以区间长度，求长度在[s,t]之间的子序列的最大平均值 $1\le n\le10^5,1\le s\le t\le n,-10^4\le a_i\le10^4$

答案满足单调性,设区间[l,r]，则其平均值x的算式为：
$$
\frac{\sum_{i=l}^ra_i}{r-l+1}=x，即\sum_{i=l}^ra_i=x\times(r-l+1)
$$
当某个区间平均值优于已算出的平均值x时，有：
$$
\frac{\sum_{i=l}^ra_i}{r-l+1}\ge x，即\sum_{i=l}^ra_i\ge x\times(r-l+1)\\即\sum_{i=l}^ra_i\ge\sum_{i=l}^rx，即\sum_{i=l}^r(a_i-x)\ge0
$$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define MAXN 100002
ll n, s, t, q[MAXN];
double c[MAXN], lf = -1e4, rf = 1e4, cf, a[MAXN];
inline bool ck(double &v)
{
    int l = 1, r = 0;
    for (ll i = 1; i <= n; ++i)
        c[i] = c[i - 1] + a[i] - v;
    for (ll i = 1; i <= n; ++i)
    {
        if (i >= s) //单调队列法
        {
            while (r >= l && c[i - s] < c[q[r]])
                --r;
            q[++r] = i - s;
        }
        if (l <= r && q[l] < i - t)
            ++l;
        if (l <= r && c[i] >= c[q[l]])
            return true;
    }
    return false;
}
signed main()
{
    scanf("%d%d%d", &n, &s, &t);
    for (ll i = 1; i <= n; ++i)
        scanf("%lf", &a[i]);
    while (rf - lf > 1e-5)
    {
        cf = (lf + rf) / 2;
        if (ck(cf))
            lf = cf;
        else
            rf = cf;
    }
    printf("%.3lf", lf);
    return 0;
}
```



##### 其他

点权最小最短路

> 洛谷P1462 无向加权图(可能有自环/重边)，而且点加权，从1走到n，在路径长不超过b的前提下，使得经过点集点权的最大值最小，求这个最小值 $点数n\le10^4,边数m\le5\times10^4,边权、点权、b\le10^9$

二分最小值，把大于最小值的点都删了，然后看看能不能有不超过 $b$ 的最短路



环转链最短距离最大值

> (SCNUOJ1479)有$n$个点，编号$[1,n]$，第$i$个点和下一个编号的点连第$i$条无向边，成环。有$m$个点对$(a,b)$，现在删掉一条边，求删掉边后这$m$个点对的两两最短路的最大值最少是多少。$2\le n\le2\times10^5,1\le m\le2\times10^5$,$1\le a_i,b_i\le n,1\le i\le m$，有多组测试，保证$\sum n,\sum m\le2\times10^5$

显然对一个点对$(a,b),a\le b$，最短路要么是$b-a,$要么是$n-(b-a)$。二分最小值，然后把所有超过这个值的段区间标记(差分+前缀和)

```c++
#define sc(x) x = read()
#define mn 200010
ll n, m, e[mn][2], u, v, lf, rf, cf, res, s[mn];
bool check(ll k)
{
    memset(s, 0, sizeof s);
    for (ll i = 0; i < m; ++i)
    {
        //只能在[a,b)这一段删，不然会走[a,b)使得答案>k
        //所以不能走这一段的补集
        if (e[i][1] - e[i][0] > k)
        {
            ++s[1];
            --s[e[i][0]];
            ++s[e[i][1]];
        }
        if (n - (e[i][1] - e[i][0]) > k)
        {
            ++s[e[i][0]];
            --s[e[i][1]];
        }
    }
    for (ll i = 1; i <= n; ++i)
    {
        s[i] += s[i - 1];
        if (!s[i])
        {
            return true;
        }
    }
    return false;
}
signed main()
{
    while (EOF != scanf("%d%d", &n, &m))
    {
        for (ll i = 0; i < m; ++i)
        {
            sc(u), sc(v); //输入不保证a<=b所以要这样
            e[i][0] = min(u, v), e[i][1] = max(u, v);
        }
        lf = 0, rf = n - 1;
        while (lf <= rf) 
        {
            cf = (lf + rf) >> 1;
            if (check(cf)) //如果有答案，那么找一下更小的
            {
                rf = cf - 1;
            }
            else
            {
                lf = cf + 1;
            }
        }
        printf("%d\n", rf + 1);
    }
    return 0;
}
```



#### 整体二分

主体思路：把多个离线查询一起解决

需要满足以下性质：

1. 询问的答案可以二分
2. 修改对判定答案的贡献相互独立，修改之间不影响效果
3. 修改若对判定答案有贡献，则贡献为一个确定的与判定标准无关的值
4. 贡献满足交换律、结合律、具有可加性
5. 题目允许离线算法

时间复杂度 $O(T\log n)$ 。当使用别的结构(如树状数组)时，叠加复杂度

> 例题洛谷P1527-给定 $n\times n(1\le n\le500)$ 矩阵，有 $q(1\le q\le6\times10^4)$ 次询问，每次求矩阵左上角 $(x_1,y_1)$ 和右下角 $(x_2,y_2)$ 的子矩阵的第 $k$ 小数(不去重)( $1\le a_{i,j}\le10^9$ )

整体二分+离散化+二维树状数组。复杂度为 $O((n^2+q)\log^3n)$ 

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 510
#define mm 60010
ll n, t, n2, b[mn][mn];
struct matrix
{ //结构体排序方便
    ll i, j, v;
    bool operator<(const matrix &r) const { return v < r.v; }
} a[mn * mn];
struct queries
{
    ll ax, ay, bx, by, k;
} q[mm];
ll qid[mm], tmp1[mm], tmp2[mm], ans[mm], now[mm];
ll lowbit(ll x) { return x & -x; }
void add(ll x, ll y, ll v)
{
    for (ll i = x; i <= n; i += lowbit(i))
        for (ll j = y; j <= n; j += lowbit(j))
            b[i][j] += v;
}
ll get(ll x, ll y)
{
    ll res = 0;
    for (ll i = x; i; i -= lowbit(i))
        for (ll j = y; j; j -= lowbit(j))
            res += b[i][j];
    return res;
}
ll gets(queries p)
{
    return get(p.bx, p.by) - get(p.ax - 1, p.by) - get(p.bx, p.ay - 1) + get(p.ax - 1, p.ay - 1);
}
void solve(ll lf, ll rf, ll lc, ll rc)
{
    if (lc > rc)
        return;
    if (lf == rf)
    {
        for (ll i = lc; i <= rc; ++i)
            ans[qid[i]] = a[lf].v;
        return;
    }
    ll cf = (lf + rf) >> 1;
    for (ll i = lf; i <= cf; ++i)
        add(a[i].i, a[i].j, 1);
    ll cnt1 = 0, cnt2 = 0;
    for (ll i = lc, u; i <= rc; ++i)
    {
        u = qid[i];
        ll s = now[u] + gets(q[u]);
        if (s >= q[u].k)
            tmp1[++cnt1] = u;
        else
            tmp2[++cnt2] = u, now[u] = s; // 本质为u-s
    }
    ll j = lc - 1;
    for (ll i = 1; i <= cnt1; ++i)
        qid[++j] = tmp1[i];
    for (ll i = 1; i <= cnt2; ++i)
        qid[++j] = tmp2[i];
    for (ll i = lf; i <= cf; ++i)
        add(a[i].i, a[i].j, -1);
    solve(lf, cf, lc, lc + cnt1 - 1);
    solve(cf + 1, rf, lc + cnt1, rc);
}
signed main()
{
    sc(n), sc(t);
    for (ll i = 1; i <= n; ++i)
    {
        for (ll j = 1, v; j <= n; ++j)
        {
            sc(v);
            a[++n2] = {i, j, v};
        }
    }
    sort(a + 1, a + 1 + n2);
    for (ll i = 1; i <= t; ++i)
    {
        sc(q[i].ax), sc(q[i].ay), sc(q[i].bx), sc(q[i].by), sc(q[i].k);
        qid[i] = i;
    }
    solve(1, n2, 1, t);
    for (ll i = 1; i <= t; ++i)
        printf("%lld\n", ans[i]);
    return 0;
}
```



> 洛谷P2617例题-给定长为 $n$ 的数列 $a$ ，支持 $m$ 次两种操作：$1\le n,m\le10^5,0\le a_i,y\le10^9$
>
> - `Q l r k` 查询区间第 $k$ 小
> - `C x y` 将 $a_x$ 改为 $y$

因为涉及修改，所以不要重排序操作。那么在修改前的询问是不受后续修改的影响的。初始修改放在操作的最前面。下面代码没有使用到离散化。

还有一个小要点，就是对于脏数据的处理。脏数据也就是会对计算结果产生影响的数据。对于本题而言，值大于等于mb的操作在[lb,mb)中是没有影响的，但是在[mb,ub)的操作中，值小于mb的操作会产生影响，但是显然如果减去一个k，那么就可以消除这个影响。

```c++
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct op
{
    int type;
    // type==0 Change i means position; j means ispositive; k means the number after change
    // type==1 Query i means left; r means right; k means kth-number
    int i, j, k,id;
};
int n, m, a[10050], ans[10050], f[50050];
vector<op> q;
int lowbit(int x)
{
    return x & -x;
}
void add(int x, int k)
{
    while (x <= n)
    {
        f[x] += k;
        x += lowbit(x);
    }
}
int query(int k)
{
    int ans = 0;
    while (k > 0)
    {
        ans += f[k];
        k -= lowbit(k);
    }
    return ans;
}
void solve(int lb, int ub, vector<op> &q)
{
    vector<op> Left, Right;
    int mb = (lb + ub) >> 1;
    if (ub - lb == 1)
    {
        for (int i = 0; i < q.size(); i++)
        {
            if (q[i].type == 1)
                ans[q[i].id] = lb;
        }
        return;
    }
    else if (q.empty())
        return;
    for (int i = 0; i < q.size(); i++)
    {
        op tmp = q[i];
        if (tmp.type == 0)
        {
            if (tmp.k < mb)
            {
                add(tmp.i, tmp.j); // i:pos j:num
                Left.push_back(tmp);
            }
            else
                Right.push_back(tmp);
        }
        else
        {
            int kth = query(tmp.j) - query(tmp.i - 1);
            if (kth >= tmp.k)
                Left.push_back(tmp);
            else
            {
                tmp.k -= kth;
                Right.push_back(tmp);
            }
        }
    }
    for (int x = 0; x < Left.size(); x++)
        if (Left[x].type == 0)
            add(Left[x].i, -Left[x].j);
    solve(lb, mb, Left);
    solve(mb, ub, Right);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        op tmp = {0, i, 1, a[i]};
        q.push_back(tmp);
    }
    for (int x = 0; x < m; x++)
    {
        char cmd;
        int i;
        scanf("%s%d", &cmd, &i);
        if (cmd == 'C')
        {
            int t;
            scanf("%d", &t);
            op tmp = {0, i, -1, a[i], 0};
            q.push_back(tmp);
            a[i] = t;
            tmp = {0, i, 1, t, 0};
            q.push_back(tmp);
        }
        else
        {
            int j, k;
            scanf("%d%d", &j, &k);
            op tmp = {1, i, j, k, x};
            q.push_back(tmp);
        }
    }
    for (int i = 0; i < m; i++)
        ans[i] = -1;
    solve(0, 1e9, q);
    for (int i = 0; i < m; i++)
        if (ans[i] != -1)
            printf("%d\n", ans[i]);
    return 0;
}
```

#### wqs二分

王钦石二分(Alien Trick)。

> lc188/SCNUOI1069-有 $n(1\le n\le10^5)$ 天，当日股票价格 $p_i(1\le p_i\le 10^9)$，每天可以买入或卖出股票，但最多持有一股，问最大收益。

设恰好完成 $k$ 次买卖时，最大收益是 $g_k$。设增量(/导数)为 $g'_k=g_k-g_{k-1}$那么可以得到一个结论，增量 $g'_k$ 一定单调不降(不严格单调递增)。当 $k$ 不断增大到最大 $n$($n$ 次交易即都当天买当天卖等价于 $0$ 次交易)时，$g_k$ 会降到 $0$，即 $g_0=g_n=0$，一阶导 $g'_k$ 单调递减，不难判断 $g$ 呈倒 U 型。

任务是求出 $g$ 数列(/离散函数)的最大值 $\max g$。用几何思路，考虑作直线与 $g$ 图像相切，设枚举了斜率为 $c(c > 0)$ 的直线，过所有点 $g_i(1\le i\le n)$ 作 $n$ 条直线。

由于 $c > 0$，所以 $y$ 截距最大的直线一定是相切的。设有斜率为 $c$ 过点 $(k,g_k)$ 的直线，不难计算得截距是 $b=g_k-kc$。回到要求的问题上，可以将截距抽象成进行了 $k$ 次买卖，净利润为 $g_k$，但每次卖出需要付手续费 $c$​。抽象为已知手续费 $c$，且不限交易次数，求出最大的含手续费利润 $b$。

因为不限交易次数，考虑贪心，即只要能赚的钱不低于手续费就买卖一次。由此可以 $O(n)$ 计算出对固定的斜率 $c$ 得到的最大切线截距 $b=g_k-kc$ 及其 $k$ 值($sellcnt$)。对答案 $\max g = b+gk$ 而言，$b$ 相等时要尽可能大的 $k$，所以在上述贪心时，在利润最大化的同时，应当再最大化交易次数。

注意到斜率一定不会超过增量的最大值即 $\max p$，故二分上界取 $\max p$ 即可。分母为 $1$，故折线斜率为整数，即二分只需要在整数范围内即可。如果题给的 $k$ 在 $g$ 单调递减时取得(即最高点 $k' < k,g_{k'} > g_k$)，也就是说不限次数地贪心得到的 $sellcnt < k$，那么此时也可以直接不限次数贪心求出 $\max g$，只要 $p_i > p_{i-1}$ 就可以前一天买今天卖。

时间复杂度是 $O(n\log \max p)$。

```c++
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
```



### 前缀和/差分

> 树上前缀和/差分及其例题见图论-树-LCA应用。

高维前缀和可以考虑压缩数组，叠前缀和时可以容斥原理，也可以逐维叠加，即以每个维度进行一次一维前缀和，其他维度不变。

对 $a=(1,1,\cdots)$ 的 $k$ 阶前缀和 $s_n$ 是 $\dfrac{n(n+1)\cdots(n+k-1)}{k!}=C_{n+k-1}^k$。

对任意 $a$ 的 $y$ 阶前缀和 $s_{y,x}=\sum_{i=1}^xC_{y+x-i-1}^{y-1}a_i=\sum_{i=1}^xC_{x-i}^{y-1}a_i$，可以 $O(x)$ 求。要求一段前缀和的和，可以求它更高一阶的两边界值。

**常见应用：**

一维前缀和/差分：

- (SCNUOJ1410猜数)有一个目标数字，猜了若干次，反馈结果为比目标大/小/相等，问结果里最多多少个是对的

  把每个猜的结果转化为坐标轴的一段猜对目标数字取值区间，用差分累加所有区间，然后离散化枚举每个区间边界，被多少个区间覆盖猜对了多少次， $O(n\log n)$

- (蓝桥-最大子阵)求矩阵的最大非空子矩阵的元素和

  先计算每列一维前缀和，然后枚举子矩阵最下行 $i$ ，枚举行跨度 $j(\le i)$ ，枚举列 $k$ ，逐列累加跨 $j$ 行后的新元素和，如果更大加入答案，如果当前和小于 $0$ 舍弃全部，否则继续累加 ，复杂度 $O(n^2 m)$

  ```c++
  for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) 
  		scanf("%d",&v),s[i][j]=s[i-1][j]+v;//当前行前缀和 
  for(int i=1;i<=n;++i) for(int j=1;j<=i;++j) //矩阵右下角为(i,j) 
      for(int k=1,v=0;k<=m;++k) //使用O(m)计算二维前缀和 
      {
          v+=s[i][k]-s[j-1][k];//当前矩阵前缀和 
          mx=max(mx,v);
          v=max(v,0); //负数特判 
      }
  ```

- (蓝桥-k倍区间) 求有多少个连续子序列的和是 $k$ 的倍数

  是 $k$ 的倍数 $\to$ 前缀和模 $k$ 得 $0$ $\to s[r]\equiv s[l-1]\bmod k$ ，即求多少个相等前缀和对，即(解法一) $\sum_{i=1}^k C_2^{s[i]}$ ( $O(n+k)$ ) 或(解法二)每次求得新相等时与原本相等数累加。注意特判本有 $s[0]=1$ 。若 $k$ 过大，可以选择离散化

  ```c++
  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;++i)
      scanf("%d",&v),(cnt+=v)%=k,sum+=vis[cnt]++;
  printf("%lld",sum+vis[0]);
  ```

- (SCNUOJ1193子段异或) 求异或和为 $0$ 的连续子段数

  异或为 $0\to$ 前缀异或满足 $s[r]=s[l-1]$ ，与上题类似，$O(n\log a)$ (离散化) 

  ```c++
  for(scanf("%lld",&n),++m[0];n;--n) //m:map
      scanf("%lld",&v),ans+=m[c^=v]++;
  return printf("%lld",ans)&0;
  ```

- (SCNUOJ1433周游山区) $n$ 个加油站成环，离顺时针下一个加油站距离 $d_i$ ，可加油 $p_i$ ，问从每个加油站出发(本站油量为起始油量)能否顺或逆时针走完一圈

  走完一圈后油量可以为0，但没走完之前不可以为0；但是如果考虑子问题，那么只需要考虑大于等于0，在顺时针时，从$i$出发，可以走回 $i$ 的条件为同时满足以下等式：(需要注意 $d_0=0$ ) , $O(n)$
  $$
  \begin{cases}
  (p_i-d_{i})\ge0\\
  (p_i-d_{i})+(p_{i+1}-d_{i+1})\ge0\\
  \dots\\
  (p_i-d_{i})+(p_{i+1}-d_{i+1})+\dots+(p_{i+n-1}-d_{i+n-1})\ge0
  \end{cases}
  $$
  设前缀和 $s_n=\sum_{i=1}^n p_i-d_i$ ，即需要同时满足：
  $$
  \begin{cases}
  s_i-s_{i-1}\ge0\\
  s_{i+1}-s_{i-1}\ge0\\
  \dots\\
  s_{i+n-1}-s_{i-1}\ge0
  \end{cases}
  $$
  即在 $[i,i+n-1]$ 内， $s_\min-s_{i-1}\ge0$  ，逆时针同理：
  $$
  (s_i-s_j)_\min\ge0\quad j\in[i-n+1,i]\Rightarrow s_i-s_{\max}\ge0
  $$
  可以用单调队列维护一个最小值(逆则最大)。注意单调区间长度不可以大于等于 $n$

  ```c++
  #include <bits/stdc++.h>
  using namespace std;
  typedef long long ll;
  #define mn 2000002
  #define nemp hd<=ed
  ll q[mn],hd,ed=-1,s[mn],p[mn],d[mn],n,n2;
  bool ok[mn];
  signed main()
  {
      scanf("%lld",&n); n2=n<<1;
      for(ll i=1;i<=n;++i) scanf("%lld%lld",p+i,d+i),s[i]=s[i+n]=p[i]-d[i];
      for(ll i=1;i<=n2;++i) s[i]+=s[i-1];
      for(ll i=n2;i;--i)
      {
          while(nemp&&q[hd]-i>=n) ++hd;
          while(nemp&&s[q[ed]]>=s[i]) --ed;
          q[++ed]=i;
          if(i<=n&&s[q[hd]]-s[i-1]>=0) ok[i]=true;
      } hd=0,ed=-1;  d[0]=d[n];
      for(ll i=1;i<=n;++i) s[i]=s[i+n]=p[i]-d[i-1];
      for(ll i=1;i<=n2;++i) s[i]+=s[i-1];
      for(ll i=1;i<=n2;++i)
      {
          while(nemp&&i-q[hd]>=n) ++hd;
          if(i>n&&s[i]-s[q[hd]]>=0) ok[i-n]=true;
          while(nemp&&s[q[ed]]<=s[i]) --ed;
          q[++ed]=i;
      }
      for(ll i=1;i<=n;++i) printf(ok[i]?"YES\n":"NO\n");
      return 0;
  }
  ```

二维前缀和/差分：

- (SCNUOJ1226守卫农田)矩阵内有若干个子矩形被覆盖，若干次询问某个子矩阵是否都被覆盖

  覆盖过程可以二维差分；得出布尔值化的原数组后再求一个二维前缀和，查询时就能 $O(1)$ 比较子矩阵面积与被覆盖大小 $O(n^2)$ 

高维前缀和/差分：

- (蓝桥-三体攻击)有立方体舰队阵列，每次攻击使一个子立方体全员受到定值伤害，求首次出现死亡时是第几次攻击

  二分答案+三维差分。把攻击做成差分数组，二分攻击次数，判断是否出现负数即可 $O(n^3\log t)$

前缀和/差分思想：

- (洛谷P2926)给定 $n$ 个值域在 $w$ 的可重复数，求每个数有多少数能被它整除

  先计数每个数出现了几次，然后对每个因子其所有倍数叠加一遍， $O(n\log n)$

  ```c++
  #include <bits/stdc++.h>
  using namespace std;
  typedef int ll;
  #define MAXN 1000002
  ll ans[MAXN], n, a[MAXN], mx, vis[MAXN];
  signed main()
  {
      scanf("%d", &n);
      for (ll i = 1; i <= n; ++i)
          scanf("%d", &a[i]), ++vis[a[i]], mx = max(a[i], mx);
      for (ll i = 1; i <= mx; ++i)
      {
          if (!vis[i])
              continue;
          for (ll j = 1; j * i <= mx; ++j)
              if (vis[i * j])
                  ans[i * j] += vis[i];
          --ans[i];
      }
      for (ll i = 1; i <= n; ++i)
          printf("%d\n", ans[a[i]]);
      return 0;
  }
  ```



### 搜索

调整 BFS 的顺序，可以达到最短路径字典序最小等要求。对未知有限步数，有时可以设一个大数作为搜索深度边界。遇事不决剪枝记忆化。

一些数字类/字典序/倍数因数的题目也可以搜索每个位数来逐个求解所有可能的值。

#### IDA*

启发式搜索不保证绝对准确性，建立在其基础之上的A\*和IDA\*也不保证绝对的准确性。因为估价函数的估计值并不一定是答案。

其中IDA\*是每次限定搜索深度(逐次增加)的DFS来模拟BFS。好处是空间开销小。不加A\*的该方法为迭代加深搜索

> 洛谷P1379 把 $3\times 3$ 棋盘 $1\sim 8$ 数字 ( $0$ 是空格)转化为 `123804765` 状态，问最小步数

这题也可以BFS+记忆化，双向BFS，康托展开来做

```c++
#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long lt;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
char ss[15];
int ans[4][4]=
{{0,0,0,0},
 {0,1,2,3},
 {0,8,0,4},
 {0,7,6,5}};
int a[5][5],k,judge;
int nxtx[]={0,1,-1,0};//特殊构造
int nxty[]={1,0,0,-1};//pre+i==3时两两互逆，即pre和i互为相反步
int check()
{
    for(int i=1;i<=3;++i)
    for(int j=1;j<=3;++j)
    if(ans[i][j]!=a[i][j])return 0;
    return 1;
}
int test(int step)//预测还要走多少步，启发假设有一个不等就走多一步
{
    int cnt=0;
    for(int i=1;i<=3;++i)
    for(int j=1;j<=3;++j)
    if(ans[i][j]!=a[i][j]){ if(++cnt+step>k) return 0;}
    return 1;
}
void A_star(int step,int x,int y,int pre)//pre防止下一次走回上一步
{
    if(step==k){ if(check())judge=1; return;}//达到当前限制的最大深度
    if(judge) return;
    for(int i=0;i<4;++i)
    {
        int nx=x+nxtx[i],ny=y+nxty[i];
        if(nx<1||nx>3||ny<1||ny>3||pre+i==3) continue;//加入了上述最优性剪枝
        swap(a[x][y],a[nx][ny]);
        if(test(step)&&!judge) A_star(step+1,nx,ny,i);//A*估价合法再向下搜索
        swap(a[x][y],a[nx][ny]);
    }
}
int main()
{
    int x,y;
    scanf("%s",&ss);
    for(int i=0;i<9;++i)
    {
        a[i/3+1][i%3+1]=ss[i]-'0';
        if(ss[i]-'0'==0)x=i/3+1,y=i%3+1;
    }
    if(check()){printf("0");return 0;}//特判不用移动
    while(++k)//枚举最大深度
    {
        A_star(0,x,y,-1);
        if(judge){printf("%d",k);break;}
    }
    return 0;
}
```



#### 双向搜索

对BFS而言，将规模$a^n$缩减为$2a^{\frac n2}$

从起点开始和从终点开始的点分别标注为1和2，那么相加为3必然相遇。

while条件为两队列均不为空还是for和dx,dy搜索。代码类似BFS，很好写



#### 折半搜索

对DFS而言，第一次搜索前半部分，第二次搜索后半部分，最后再组合两部分，将搜索的复杂度指数降低一半，并将空间复杂度提升到时间复杂度等同

> 洛谷P4799-有n场比赛，可用m元，比赛入场需要门票钱x，请问他有多少种参加方案。 $1\le n\le40,1\le m\le10^{18},1\le x\le10^{16}$

第一次搜索前一半比赛并将小于m的全部花费记录。第二次搜索后一半比赛并同样记录，得到的记录数目为$2\times2^{\frac n2}$，时间复杂度也是如此(01背包型搜索)。最后合并，取余额为$m-a_i$，即减去第一次搜索得到的一个花销和，然后在第二次二分搜索(排序后)里寻找大于等于余额的下标，下标即方案数。这里运用了前缀和思维的计数，使用$O(len\log len)$的复杂度完成了合并。总时间时间复杂度为$\Omicron(2^{\frac n2+1}\log2^{\frac n2})=\Omicron(n2^{\frac n2})$，空间复杂度为$\Omicron(2^{\frac n2+1})$

```c++
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define mn (1<<21)+5
ll n,m,x[62],ac,bc,as[mn],bs[mn],cf,ans;
void dfs(ll lf, ll& rf, ll v, ll& cnt, ll* arr)
{
    if(v>m) return;
    if(lf==rf){arr[cnt++]=v; return;}
    dfs(lf+1,rf,v+x[lf],cnt,arr);
    dfs(lf+1,rf,v,cnt,arr);
}
signed main()
{
    scanf("%lld%lld",&n,&m); cf=n>>1;
    for(int i=0;i<n;++i) scanf("%lld",x+i);
    dfs(0,cf,0,ac,as);
    dfs(cf,n,0,bc,bs);
    sort(bs,bs+bc);
    for(int i=0;i<ac;++i)
        ans+=upper_bound(bs,bs+bc,m-as[i])-bs;
    return printf("%lld",ans),0;
}
```



> 洛谷P3067-给定n个数x，选出一些数划分为两堆和相等的数，求方案数。($2\le n\le20,1\le x\le10^8$)

显然不会爆int。由于划分的两堆数数目不定，所以需要使用搜索，单纯搜索时，有三种分支，即当前数不加入，当前数放左堆，当前数放又堆，是三进制背包DFS，复杂度为$\Omicron(3^n)$不通过。

考虑折半搜索。并考虑利用状态压缩、vis数组去重和map离散化。第一次搜索前面一半的数，设sum为左堆-右堆的差值，第二次设sum为右堆-左堆的差值，如果第二次的sum等于第一次的，证明合起来之后，这两堆的和相等。最后统计有效状态即可。

时间复杂度为$\Omicron(3^{\frac n2})$，空间复杂度为$\Omicron(2^n)$，空间复杂度来自于状态压缩(选了什么数)。

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn (1<<20)+5
int n,half,mc,ans,a[21];
bool memo[mn];
vector<int> d[mn];//有多少种nowstate可以拼出情况mc(mc即nowsum)
map<int,int> m;//m[v]->mc 求和值与情况mc一一对应
void dfs1(int i, int nowsum, int nowstate)
{
    if(i==half)
    {
        if(!m.count(nowsum)) m[nowsum]=++mc;//和为nowsum时对应一个独一无二的mc
        d[m[nowsum]].push_back(nowstate);
        return;
    }
    dfs1(i+1,nowsum,nowstate); //两边都不选
    dfs1(i+1,nowsum+a[i],nowstate|(1<<i)); //左边选了
    dfs1(i+1,nowsum-a[i],nowstate|(1<<i)); //右边选了
}
void dfs2(int i, int nowsum, int nowstate)//这次+ -的意义跟上次相反
{
    if(i==n)
    {
        if(m.count(nowsum))//如果可以拼出nowsum
        {
            int x=m[nowsum];
            for(int i=0,ds=d[x].size();i<ds;++i) memo[d[x][i]|nowstate]=true;//起到了去重
        }
        return;
    }
    dfs2(i+1,nowsum,nowstate);
    dfs2(i+1,nowsum+a[i],nowstate|(1<<i));//位运算(状态压缩)里i从0开始
    dfs2(i+1,nowsum-a[i],nowstate|(1<<i));
}
signed main()
{
    scanf("%d",&n);
    half=n>>1;
    for(int i=0;i<n;++i) scanf("%d",a+i);
    dfs1(0,0,0);
    dfs2(half,0,0);
    for(int i=1,n2=1<<n;i<=n2;++i) ans+=memo[i];
    return printf("%d",ans),0;
}

```



### 随机化

$$
(1-\dfrac1n)^n\le\dfrac 1e,\forall n\ge 1
$$

意义：有 $n$ 个**相互独立**的坏事件，且设它们的发生概率都是 $1-\dfrac 1n$ ，那么它们全部都发生的概率至多是 $\dfrac1e\approx0.3679$  

假设可以枚举到的全体解是 $U$ ，$|U|=n$ ，其中正解是 $S$ ，如果每次随机枚举一个解，期望正确率是 $1-\epsilon$ (即错误率是 $\epsilon$ )，那么单次枚举有 $\dfrac{|S|}n$ 概率得到正解，枚举 $n(-\log\dfrac\epsilon{|S|})$ 次可以把全体 $S$ 元素都枚举一次



**爬山算法 / 模拟退火**：

设枚举次数是 $m$ ，那么 $tC^m\approx t_0$ 即 $m\approx\log(\dfrac{t_0}t,C)$ ，即复杂度为 $O\left(\log(\dfrac{t_0}t,C)\right)$  

通常降温系数 $C\in [0.985,0.999],t_0=10^{-15}$ ，$t$ 一般看定义域，例如 $t=10^4$ 

规定熵值越低解越优。通常可以跑多次。一种卡时方法：

```c++
while ((double)clock()/CLOCKS_PER_SEC < MAX_TIME) simulateAnneal();
```



> (SCNUOJ1679) 求满足 $x+y=k$ 下 $\sqrt{p-a+x^2}+\sqrt{p-b+y^2}$ 最小的解 $(x,y)$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
ll p, a, b, q;
db k, t = 0.5, d, minx = 0.5, nowx = 0.5;
db f(db x) // assume k=1
{
    return sqrt(p - a + x * x) + sqrt(p - b + (k - x) * (k - x));
}
signed main()
{
    scanf("%lld%lld%lld%lld", &p, &a, &b, &q);
    while (q--)
    {
        scanf("%lf", &k);
        minx = nowx = k / 2;
        t = k / 2;
        while (t > 1e-6) // t是温度参数
        {
            db x1 = nowx + t;
            db x2 = nowx - t;
            db newx = f(x1) < f(x2) ? x1 : x2;
            nowx = newx;
            if (f(newx) < f(minx))
            {
                minx = newx;
            }
            t *= 0.9; // 降温系数
        }
        printf("%lf %lf\n", minx, (k - minx));
    }
    return 0;
}
```



> (SCNUOJ1730) 给定常数 $a,b,c,d,e,l,r$ ，求下列函数在定义域 $[l,r]$ 的最大值：
> $$
> f(x)=\sin(\dfrac xa)+\sin(\dfrac xb)+\sin(\dfrac xc)+\sin(\dfrac xd)+\sin(\dfrac xe)
> $$
>
> ```c++
> #include <bits/stdc++.h>
> using namespace std;
> #define sc(x) scanf("%lld", &x)
> typedef long long ll;
> typedef double db;
> ll a, b, c, d, e, l, r;
> db x, t, now, mx, ans = -6;
> db f(db x)
> {
>     return sin(x / a) + sin(x / b) + sin(x / c) + sin(x / d) + sin(x / e);
> }
> void solve()
> {
>     static ll rd = 1;//也可以用random_device生成种子
>     mt19937 mt(rd + time(0));
>     rd *= 2;
>     uniform_real_distribution<db> dist0(0, 1);
>     now = (l + r) / 2, t = r - l;
>     while (t > 1e-6)
>     {
>         uniform_real_distribution<db> dist(-t, t);
>         db newx = now + dist(mt);
>         newx = max(1. * l, min(1. * r, newx));
>         db fnow = f(now), fnew = f(newx);
>         db dt = (-fnew) - (-fnow);
>         if (fnow < fnew || exp(-dt / t) > dist0(mt))
>         {
>             now = newx;
>         }
>         if (ans < fnew)
>         {
>             ans = fnew;
>         }
>         t *= 0.999;
>     }
>     for (ll i = 0; i < 1000; ++i) //在终温随机多次
>     { //优化效果不明显
>         uniform_real_distribution<db> dist(-t, t);
>         db newx = now + dist(mt);
>         newx = max(1. * l, min(1. * r, newx));
>         db fnow = f(now), fnew = f(newx);
>         if (fnow < fnew)
>         {
>             now = newx;
>         }
>         if (ans < fnew)
>         {
>             ans = fnew;
>         }
>     }
> }
> signed main()
> {
>     sc(a), sc(b), sc(c), sc(d), sc(e), sc(l), sc(r);
>     for (ll i = 0; i < 20; ++i) //重要：多次退火
>     {
>         solve();
>     }
>     printf("%lf", ans);
>     return 0;
> }
> ```



> 洛谷P2503-将 $n$ 个数分成 $m$ 组，组内求和得到 $m$ 个数，求最小方差 $m\le n\le20,2\le m\le6$ 
>
> 对某个序列，每次将当前数贪心放进 $m$ 组里和最小的一组，可以证明是对确定序列得到最小方差的；然后用模拟退火不断打乱序列即可，对每个位置退火 $1$ 次，共退火 $n$ 次



> lc1157-有数组 $n(\le 2\times10^4)$ 和 $q(\le10^4)$ 次询问，每次问子区间 $[l,r]$ 的出现频率不低于 $t(t$ 至少区间一半长 $)$ 的元素是什么。

因为出现次数至少一半，随机枚举 $20$ 次，几乎不可能取不到是该数字。每次枚举，通过 lower, upper bound 对该元素的出现下标有序数组搜索得到出现频次。

> 解法二：使用 Boyer-Moore 投票算法 $O(n)$ 在已知存在众数的情况下求出众数，利用投票算法套线段树维护信息。



### 莫队

#### 普通

> 洛谷P3901-静态 $n$ 长数列 $a(1\le n,a_i\le10^5)$ ，有 $m(1\le m\le10^5)$ 次询问，问区间内是否每个数互不相同

复杂度 $O(n\sqrt m)$ ，三种正确的循环位置： `l--,r--,r++,l++`  ， `l--,r++,r--,l++` ， `l--,r++,l++,r--` (前两步先扩大区间(`l--,r++`)，后两步缩小区间(`l++,r--`))

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 100010
ll n, m, x, bin[mn], ans[mn], sq, a[mn], sum;
struct query
{
    ll l, r, i;
    bool operator<(const query &x) const
    {
        if (l / sq != x.l / sq)
            return l < x.l;
        if (l / sq & 1)
            return r < x.r;
        return r > x.r;
    }
} q[mn];
void add(ll i)
{
    sum += bin[a[i]]++ == 0;
}
void del(ll i)
{
    sum -= --bin[a[i]] == 0;
}
signed main()
{
    sc(n), sc(m), sq = sqrt(n);
    for (ll i = 1; i <= n; ++i)
    {
        sc(a[i]);
    }
    for (ll i = 1; i <= m; ++i)
    {
        sc(q[i].l), sc(q[i].r), q[i].i = i;
    }
    sort(q + 1, q + 1 + m);
    for (ll i = 1, l = 1, r = 0; i <= m; ++i)
    {
        while (l > q[i].l)
            add(--l);
        while (r < q[i].r)
            add(++r);
        while (l < q[i].l)
            del(l++);
        while (r > q[i].r)
            del(r--);
        ans[q[i].i] = sum == (q[i].r - q[i].l + 1);
    }
    for (ll i = 1; i <= m; ++i)
    {
        printf("%s\n", ans[i] ? "Yes" : "No");
    }
    return 0;
}
```



#### 带修

> 洛谷1903 有 $n$ 长序列 $a(a_i\le10^6)$ ，有 $m(n,m\le 133333)$ 次操作：`Q l r` 表示询问区间 $[l,r]$ 内不同数值数； `R p c` 表示将 $a_p$ 修改为 $c$ 。

复杂度 $O(n^\frac53)$ 

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 133340
ll n, m, sq, a[mn], a0[mn], ans[mn], m1, m2, sum, bin[1000010];
struct query1
{
    ll l, r, i, c;
    bool operator<(const query1 &x) const
    {
        if (l / sq == x.l / sq)
        {
            return r / sq == x.r / sq ? i < x.i : r < x.r;
        }
        return l < x.l;
    }
} q1[mn];
struct query2
{
    ll i, f, t;
} q2[mn];
void add(ll i)
{
    sum += bin[i]++ == 0;
}
void del(ll i)
{
    sum -= --bin[i] == 0;
}
ll l = 1, r;
void addt(ll t)
{
    if (l <= q2[t].i && q2[t].i <= r)
        del(q2[t].f), add(q2[t].t);
    a0[q2[t].i] = q2[t].t;
}
void delt(ll t)
{
    if (l <= q2[t].i && q2[t].i <= r)
        del(q2[t].t), add(q2[t].f);
    a0[q2[t].i] = q2[t].f;
}
signed main()
{
    sc(n), sc(m), sq = pow(n, 2. / 3);
    for (ll i = 1; i <= n; ++i)
    {
        sc(a[i]), a0[i] = a[i];
    }
    char ch[5] = {};
    for (ll i = 1, x, y; i <= m; ++i)
    {
        scanf("%s%lld%lld", ch, &x, &y);
        if (ch[0] == 'Q')
        {
            ++m1, q1[m1] = {x, y, m1, m2 + 1};
        }
        else
        {
            ++m2, q2[m2] = {x, a[x], y}, a[x] = y;
        }
    }
    sort(q1 + 1, q1 + 1 + m1);
    for (ll i = 1, t = 1; i <= m1; ++i)
    {
        while (t < q1[i].c)
            addt(t++);
        while (t > q1[i].c)
            delt(--t);
        while (l > q1[i].l)
            add(a0[--l]);
        while (r < q1[i].r)
            add(a0[++r]);
        while (l < q1[i].l)
            del(a0[l++]);
        while (r > q1[i].r)
            del(a0[r--]);
        ans[q1[i].i] = sum;
    }
    for (ll i = 1; i <= m1; ++i)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
```



#### 树上

子树：

> 例题洛谷U41492：$n(n\le 10^5)$ 个节点的树，每个节点有不同的颜色( $10^5$ 种)，问每个节点为根的子树中，所有节点有多少种不同的颜色；$m(m\le 10^5)$ 次询问，每次问一棵子树

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 100010
ll n, m, sq, ans[mn], bin[mn], sum, a[mn], hd[mn], cnt;
ll dfn[mn], st, mx[mn], id[mn];
struct query
{
    ll l, r, i;
    bool operator<(const query &x) const
    {
        if (l / sq != x.l / sq)
            return l < x.l;
        return l / sq & 1 ? r < x.r : r > x.r;
    }
} q[mn];
struct edge
{
    ll to, nx;
} e[mn * 2];
signed main()
{
    sc(n), sq = sqrt(n);
    auto adde = [&](ll u, ll v)
    { e[++cnt] = {v, hd[u]}, hd[u] = cnt; };
    for (ll i = 1, u, v; i < n; ++i)
    {
        sc(u), sc(v), adde(u, v), adde(v, u);
    }
    for (ll i = 1; i <= n; ++i)
    {
        sc(a[i]);
    }
    auto dfs = [&](auto self, ll u, ll fa) -> ll
    {
        dfn[u] = ++st, mx[u] = st, id[st] = a[u];
        for (ll i = hd[u], v; i; i = e[i].nx)
        {
            if ((v = e[i].to) != fa)
            {
                mx[u] = max(mx[u], self(self, v, u));
            }
        }
        return mx[u];
    };
    dfs(dfs, 1, 0);

    sc(m);
    for (ll i = 1, x; i <= m; ++i)
    {
        sc(x), q[i].l = dfn[x], q[i].r = mx[x], q[i].i = i;
    }
    sort(q + 1, q + 1 + m);
    auto add = [&](ll i)
    { sum += bin[id[i]]++ == 0; };
    auto del = [&](ll i)
    { sum -= --bin[id[i]] == 0; };
    for (ll i = 1, l = 1, r = 0; i <= n; ++i)
    { 
        while (l > q[i].l)
            add(--l);
        while (r < q[i].r)
            add(++r);
        while (l < q[i].l)
            del(l++);
        while (r > q[i].r)
            del(r--);
        ans[q[i].i] = sum;
    }
    for (ll i = 1; i <= m; ++i)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
```



链：

> SP10707 有 $n\le4\times10^4$ 节点树，每个点一种颜色 $\le2\times10^9$，有 $m\le10^5$ 次询问，问 $u,v$ 路径上不同颜色数

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 40010
#define mm 100010
#define mlg 17
ll n, m, sq;
ll a[mn], b[mn], bs;
ll hd[mn], cnt;
struct edge
{
    ll to, nx;
} e[mn * 2];
ll ocnt, ord[mn * 2], st[mn], nd[mn], fa[mn][mlg], dep[mn], lg[mn];
struct query
{
    ll l, r, i, c;
    bool operator<(const query &x) const
    {
        if (l / sq != x.l / sq)
            return l < x.l;
        return l / sq & 1 ? r < x.r : r > x.r;
    }
} q[mm];
ll bin[mn * 2], sum, vis[mn], ans[mm];
signed main()
{
    sc(n), sc(m), sq = sqrt(n);

    for (ll i = 1; i <= n; ++i)
    {
        sc(a[i]), b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    bs = unique(b + 1, b + 1 + n) - (b + 1);
    for (ll i = 1; i <= n; ++i)
    {
        a[i] = lower_bound(b + 1, b + 1 + bs, a[i]) - b;
    }

    auto adde = [&](ll u, ll v)
    {e[++cnt]={v,hd[u]};hd[u]=cnt; };
    for (ll i = 1, u, v; i < n; ++i)
    {
        sc(u), sc(v), adde(u, v), adde(v, u);
    }
    for (ll i = 1; i <= n; ++i)
    {
        lg[i] = lg[i / 2] + 1;
    }
    auto dfs = [&](auto self, ll u) -> void
    {
        ord[++ocnt] = u;
        st[u] = ocnt;
        for (ll i = hd[u], v; i; i = e[i].nx)
        {
            if ((v = e[i].to) != fa[u][0])
            {
                dep[v] = dep[u] + 1;
                fa[v][0] = u;
                for (ll i = 1; i <= lg[dep[v]]; ++i)
                {
                    fa[v][i] = fa[fa[v][i - 1]][i - 1];
                }
                self(self, v);
            }
        }
        ord[++ocnt] = u;
        nd[u] = ocnt;
    };
    dfs(dfs, 1);

    auto lca = [&](ll u, ll v)
    {
        if (dep[u] < dep[v])
        {
            swap(u, v);
        }
        while (dep[u] > dep[v])
        {
            u = fa[u][lg[dep[u] - dep[v]] - 1];
        }
        if (u == v)
        {
            return u;
        }
        for (ll i = lg[dep[u]] - 1; i >= 0; --i)
        {
            if (fa[u][i] != fa[v][i])
            {
                u = fa[u][i], v = fa[v][i];
            }
        }
        return fa[u][0];
    };

    for (ll i = 1, l, r, c; i <= m; ++i)
    {
        sc(l), sc(r), c = lca(l, r), q[i].i = i;
        if (st[l] > st[r])
        {
            swap(l, r);
        }
        if (l == c)
        {
            q[i].l = st[l], q[i].r = st[r];
        }
        else
        {
            q[i].l = nd[l], q[i].r = st[r], q[i].c = c;
        }
    }

    sort(q + 1, q + 1 + m);
    auto work = [&](ll i)
    {
        if (vis[i])
        {
            sum -= --bin[a[i]] == 0;
        }
        else
        {
            sum += bin[a[i]]++ == 0;
        }
        vis[i] ^= 1;
    };
    for (ll i = 1, l = 1, r = 0; i <= m; ++i)
    {
        while (l < q[i].l)
            work(ord[l++]);
        while (l > q[i].l)
            work(ord[--l]);
        while (r < q[i].r)
            work(ord[++r]);
        while (r > q[i].r)
            work(ord[r--]);
        if (q[i].c)
            work(q[i].c);
        ans[q[i].i] = sum;
        if (q[i].c)
            work(q[i].c);
    }
    for (ll i = 1; i <= m; ++i)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
```



#### 回滚

> AT1219 给定长为 $n$ 的数组 $a(1\le a_i\le10^9)$ 和 $q(1\le n,q\le10^5)$ 次询问，每次问 $[l,r]$ 内最大重要度。数字 $x$ 重要度等于 $x$ 乘以它的出现次数

复杂度 $O(n\sqrt m)$ ，按顺序处理询问：

- 如果询问左端点所属块 b 和上一个询问左端点所属块的不同，那么将莫队区间的左端点初始化为 b 的右端点加 1 , 将莫队区间的右端点初始化为 b 的右端点；
- 如果询问的左右端点所属的块相同，那么直接扫描区间回答询问；
- 如果询问的左右端点所属的块不同：
  - 如果询问的右端点大于莫队区间的右端点，那么不断扩展右端点直至莫队区间的右端点等于询问的右端点；
  - 不断扩展莫队区间的左端点直至莫队区间的左端点等于询问的左端点；
  - 回答询问；
  - 撤销莫队区间左端点的改动，使莫队区间的左端点回滚到 b 的右端点加 1。

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 100010
ll n, x[mn], t[mn], m, k, ans[mn], bin[mn], cnt[mn];
ll sq, bn, bel[mn], lf[mn], rf[mn];
struct query
{
    ll l, r, i;
    bool operator<(const query &x) const
    { //一定要这么排序
        return bel[l] == bel[x.l] ? r < x.r : bel[l] < bel[x.l];
    }
} q[mn];
void del(ll v) { --bin[v]; }
void add(ll v, ll &tmp) { tmp = max(tmp, (++bin[v]) * t[v]); }
signed main()
{
    sc(n), sc(m), sq = sqrt(n), bn = n / sq;
    for (ll i = 1; i <= n; ++i)
    {
        sc(x[i]), t[i] = x[i];
    }
    for (ll i = 1; i <= m; ++i)
    {
        sc(q[i].l), sc(q[i].r), q[i].i = i;
    }
    for (ll i = 1; i <= bn; ++i) //一定要这么分块，不能/sq，不然会炸
        lf[i] = (i - 1) * sq + 1, rf[i] = i * sq;
    if (rf[bn] < n)
        ++bn, lf[bn] = rf[bn - 1] + 1, rf[bn] = n;
    for (ll i = 1; i <= bn; ++i)
        for (ll j = lf[i]; j <= rf[i]; ++j)
            bel[j] = i;
    sort(q + 1, q + 1 + m);
    sort(t + 1, t + 1 + n);
    k = unique(t + 1, t + 1 + n) - (t + 1);
    for (ll i = 1; i <= n; ++i)
    { // x[i]是输入的a[i]排在第x[i]位,离散化压[1,1e9]到[1,1e5]
        x[i] = lower_bound(t + 1, t + 1 + k, x[i]) - t;
    }
    ll l = 1, r = 0, la = 0, sum = 0, l2 = 0, sum2 = 0;
    for (ll i = 1; i <= m; ++i)
    {
        if (bel[q[i].l] == bel[q[i].r])
        { // 询问的左右端点同属于一个块则暴力扫描回答
            for (ll j = q[i].l; j <= q[i].r; ++j)
            {
                ++cnt[x[j]]; //入桶
            }
            for (ll j = q[i].l; j <= q[i].r; ++j)
            { //按题意计算
                ans[q[i].i] = max(ans[q[i].i], t[x[j]] * cnt[x[j]]);
            }
            for (ll j = q[i].l; j <= q[i].r; ++j)
            {
                --cnt[x[j]]; //清理记忆
            }
            continue;
        }
        if (bel[q[i].l] != la) // 访问到了新的块则重新初始化莫队区间
        {
            while (r > rf[bel[q[i].l]])
                del(x[r--]);
            while (l < rf[bel[q[i].l]] + 1)
                del(x[l++]);
            sum = 0, la = bel[q[i].l];
        }
        while (r < q[i].r) // 扩展右端点
            add(x[++r], sum);
        l2 = l, sum2 = sum;
        while (l2 > q[i].l) // 扩展左端点
            add(x[--l2], sum2);
        ans[q[i].i] = sum2;
        while (l2 < l) // 回滚
            del(x[l2++]);
    }
    for (ll i = 1; i <= m; ++i)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
```



> 洛谷5906 给定长为 $n$ 的序列 $a(1\le a_i\le2\times10^9)$ 和 $q(1\le n,q\le2\times10^5)$ 个询问，每次问 $[l,r]$ 内相同数的最远间隔距离，特别的如果没有相同数输出 $0$ 

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
#define mn 200010
ll n, x[mn], t[mn], m, k, ans[mn];
ll lc[mn], rc[mn], cnt[mn], cls[mn], cln;
ll sq, bn, bel[mn], lf[mn], rf[mn];
struct query
{
    ll l, r, i;
    bool operator<(const query &x) const
    { //一定要这么排序
        return bel[l] == bel[x.l] ? r < x.r : bel[l] < bel[x.l];
    }
} q[mn];
signed main()
{
    sc(n), sq = sqrt(n), bn = n / sq;
    for (ll i = 1; i <= n; ++i)
    {
        sc(x[i]), t[i] = x[i];
    }
    sc(m);
    for (ll i = 1; i <= m; ++i)
    {
        sc(q[i].l), sc(q[i].r), q[i].i = i;
    }
    for (ll i = 1; i <= bn; ++i) //一定要这么分块，不能/sq，不然会炸
        lf[i] = (i - 1) * sq + 1, rf[i] = i * sq;
    if (rf[bn] < n)
        ++bn, lf[bn] = rf[bn - 1] + 1, rf[bn] = n;
    for (ll i = 1; i <= bn; ++i)
        for (ll j = lf[i]; j <= rf[i]; ++j)
            bel[j] = i;
    sort(q + 1, q + 1 + m);
    sort(t + 1, t + 1 + n);
    k = unique(t + 1, t + 1 + n) - (t + 1);
    for (ll i = 1; i <= n; ++i)
    { // x[i]是输入的a[i]排在第x[i]位,离散化压[1,1e9]到[1,1e5]
        x[i] = lower_bound(t + 1, t + 1 + k, x[i]) - t;
    }
    for (ll i = 1, j = 1; j <= bn; ++j)
    {
        ll br = rf[j], l = br + 1, r = l - 1, sum = 0, sum2 = 0, l2 = 0;
        cln = 0;
        for (; bel[q[i].l] == j; ++i)
        {
            if (bel[q[i].l] == bel[q[i].r])
            { // 询问的左右端点同属于一个块则暴力扫描回答
                for (ll j = q[i].l; j <= q[i].r; ++j)
                {
                    cnt[x[j]] = 0;
                }
                for (ll j = q[i].l; j <= q[i].r; ++j)
                { //按题意计算
                    if (!cnt[x[j]])
                    {
                        cnt[x[j]] = j;
                    }
                    else
                    {
                        ans[q[i].i] = max(ans[q[i].i], j - cnt[x[j]]);
                    }
                }
                continue;
            }
            while (r < q[i].r) // 扩展右端点
            {
                ++r;
                rc[x[r]] = r;
                if (!lc[x[r]])
                {
                    lc[x[r]] = r;
                    cls[++cln] = x[r];
                }
                sum = max(sum, r - lc[x[r]]);
            }
            l2 = l, sum2 = sum;
            while (l2 > q[i].l) // 扩展左端点
            {
                --l2;
                if (rc[x[l2]])
                {
                    sum2 = max(sum2, rc[x[l2]] - l2);
                }
                else
                {
                    rc[x[l2]] = l2;
                }
            }
            ans[q[i].i] = sum2;
            while (l2 < l) // 回滚
            {
                if (rc[x[l2]] == l2)
                {
                    rc[x[l2]] = 0;
                }
                ++l2;
            }
        }
        for (ll k = 1; k <= cln; ++k)
        {
            lc[cls[k]] = rc[cls[k]] = 0;
        }
    }
    for (ll i = 1; i <= m; ++i)
    {
        printf("%lld\n", ans[i]);
    }
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



#### Java 高精度

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

求高精度整数平方根：范围约为 $10^{1000}$ 

```c++
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        System.out.println(isqrtNewton(new BigInteger("99999")));
    }

    public static BigInteger isqrtNewton(BigInteger n) {
        BigInteger a = BigInteger.ONE.shiftLeft(n.bitLength() / 2);
        boolean p_dec = false;
        for (;;) {
            BigInteger b = n.divide(a).add(a).shiftRight(1);
            if (a.compareTo(b) == 0 || a.compareTo(b) < 0 && p_dec)
                break;
            p_dec = a.compareTo(b) > 0;
            a = b;
        }
        return a;
    }
}
```





#### Python 高精度

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

### 悬线法

可以应用于满足以下条件的题目：

- 需要在扫描序列时维护单调的信息；
- 可以使用单调栈解决；
- 不需要在单调栈上二分。

> P4147-给定只包含 FR 的矩阵，求全为 F 矩阵的最大面积的3倍

举每个 `F` 的位置作为矩形的最高点，然后找到以该点向上最上的前提下，向左向右最远能扩展多远。设 $l_{i,j},r_{i,j},a_{i,j}$ 分别表示点 $(i,j)$ 向左右上的最远距离。时间 $O(nm)$，空间 $O(m)$。

```c++
#include <algorithm>
#include <cstdio>
int m, n, a[1010], l[1010], r[1010], ans;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      l[j] = r[j] = j;
    }
    char s[3];
    for (int j = 1; j <= m; j++) {
      scanf("%s", s);
      if (s[0] == 'F')
        a[j]++;
      else if (s[0] == 'R')
        a[j] = 0;
    }
    for (int j = 1; j <= m; j++)
      while (l[j] != 1 && a[l[j] - 1] >= a[j]) l[j] = l[l[j] - 1];
    for (int j = m; j >= 1; j--)
      while (r[j] != m && a[r[j] + 1] >= a[j]) r[j] = r[r[j] + 1];
    for (int j = 1; j <= m; j++) ans = std::max(ans, (r[j] - l[j] + 1) * a[j]);
  }
  printf("%d", ans * 3);
  return 0;
}
```

单调栈法：对每行执行一次每个 $i$ 对应的最远 $l,r$ 可以用单调栈维护。维护单调递增栈，每个元素被退栈之时得到它的右边界。然后再继续来一遍，得到左边界。之后同理操作即可。

### 程序语法

#### 常规运算

- `__int128` $[-2^{127},2^{127}-1]$ ， $16$ 字节，其中 $2^{127}\approx8.5\times10^{37}$
- `double` 有效位数约 $15$ 位， $8$ 字节，范围约为 $[-1.79\times10^{308},1.79\times10^{308}]$
- `long double` 通常有效位数约 $20$ 位，$16$ 字节，范围约为 $[-1.2\times10^{4932},1.2\times10^{4932}]$

注意：

- 取模只可以是整型之间的；负数运算结果等于取绝对值计算，最后正负号与被除数一致，如 $(-5)\bmod 3=-2,5\bmod (-3)=2$  (C99/C++11开始 / JAVA同)

  所有版本 C/C++ 必然满足：`(a/b)*b+a%b=a`

- 浮点数除，被除数为 $0$ ，被除数和除数存在一个负数，结果为负零

> Python : `-17%10=-7,17%-10=7,-17%-10=-7` (除时取取比实际结果稍小的最大整数)

整数上取整公式：
$$
\lceil\dfrac ab\rceil=\dfrac{a+b-1}b=\dfrac{a-1}b+1
$$

`__gcd(a,b)` 若一方为零，返回另一方(无论正负)；二者均负返回负，一正一负比较特殊



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

- 删掉最低的 1，其他不变 `x&(x-1)`



内建函数：

- 注：对 `unsigned long long` 每个函数名后面加上 `ll` (传入的是什么类型不影响结果, 影响的是函数名)

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

应用：`31 - __builtin_clz(n)` 等效于 $\lfloor\log_2n\rfloor$ 



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

计时：(单位：秒) 

```c++
(double)clock() / CLOCKS_PER_SEC
```

decltype

```c++
int x;
decltype((x)) z;//z为int & ,da ck
decltype(x) y;//y为int
typedef decltype(f(x)+g(x)) dt;
dt var1;
```

使用了万能头时，不允许使用这些变量名：`y1` , `y0` , `yn` , `prev` , `tm` 等 



Python日期函数举例：

```python
from datetime import *
d1, d2 = datetime(2022,5,8), datetime(2002,5,8)
print((d1-d2).days) # 天数差
print((datetime.today()+timedelta(days=1)).weekday()) #星期[0,6]一-日
```

输出版本的语法：(适用于 OMS 等可测试平台)

```c
printf("%lld", __STDC_VERSION__); //c
```

```c++
std::cout << __cplusplus; //c++
```

```python
print(sys.version) # Python
```

```java
System.out.println(System.getProperty("java.version")); //Java
```



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
- `strtok(char* s1, const char* sep)` 子串分割

```c++
const char *sep = ", ";   //必须const
char *u = strtok(s, sep); // strtok用法模板
while (u)
{
    t.insert(u); //输出分割结果
    u = strtok(nullptr, sep);
}
```



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
	//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	//mt19937 rand_num(seed); 方法一
    random_device divc;
	mt19937 rand_num(divc()); //方法二：Linux真随机数
	uniform_int_distribution<long long> dist(0, 1000000000);
	cout << dist(rand_num) << endl;
	return 0;
}
```

distribution 范围支持负数和超过 int 的范围(即 long long)。

`uniform_real_distribution<T>` 生成实数范围

随机打乱：  `shuffle(first, last, myrand)` ，`myrand` 通常用 `mt19937` 



##### 杂项

**unique** : 排序后使用，返回去重后下界。

```c++
ll m = unique(a + 1, a + 6) - (a + 1);
```

原地去重：

```c++
nums.erase(unique(nums.begin(), nums.end()), nums.end());
```



**nth\_element** : (a,a+k,a+n,cmp); 使容器a+k所在元素左边都小于它，右边都大于它(a+k通常移位)，不返回值

```c++
nth_element(a + 1, a + k, a + n + 1); //使得a[k]归位
```

**partial\_sort** : 保证\[lf,cf)有序，\[cf,rf\]按本来的相对顺序。排序逆序可以如 `greater<ll>()` 做参数

```c++
partial_sort(lf,cf,rf);
```

**stable_sort** : 用法同 `std::sort` ，区别在于是稳定排序

**advance**：使迭代器前进n个元素，适用于所有迭代器，第一个参数是迭代器引用，第二个参数是整数距离，表示前进或后退的单位(正负控制)。

**max\_element** : 返回首个最大元素所在位置迭代器

**inplace\_merge** : (lf,cf,rf,cmp) 对 $[lf,cf)$ 和 $[cf,rf)$ 就地归并排序 

```c++
inplace_merge(a + lf, a + cf + 1, a + rf + 1);
```

**merge** : (lf1, rf1, lf2, rf2, res, cmp) 归并排序并放到结果迭代器



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
- `reduce(首, 尾, v)` 令每个元素为 $a_i=i+v$
- `lexicographical_compare(迭代器a首, 迭代器a尾, 迭代器b首, 迭代器b尾)` 字典序比较两容器(不一定是字符串)
- `replace(首迭代器, 尾迭代器, 待替换字符, 替换成的字符)` 批量替换
- `count(首迭代器, 尾迭代器, 字符)` 字符出现次数统计
- `reduce(首, 尾, 起始值)` 返回容器元素之和加上起始值，C++17

stringstream：从里面读出数据类比 cin ，用 `ss >> v` ；把数据塞进去用 `<<` 



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

insert(p, b1, b2);将[b1,b2)内元素插入到p位置前面

erase(p)删除 也可以用诸如x.end()-1;O(n) 

erase(p, q)删除区间[p,q)的元素

> 如：erase(s.begin(),s.begin()+2)删除头两个元素。



##### set

想要元素可变尝试设置结构体/类成员属性为 `mutable` 。

逆序 set <类型, greater<类型> >

可以set<类型> var{数组, 数组+len}来获取数组的set化

insert(元素值) 返回 pair，分别代表迭代器和是否成功插入

insert(sp, se)方法植入闭区间

erase(元素值)方法。可以删除不存在的值，将会忽略操作

erase(迭代器)方法 ，如x.end()

对 multiset 而言，erase 元素值会删掉所有同值，迭代器则删单个

find()有，返回迭代器，无，返回末尾end()

并集set_union(Ab, Ae, Bp, Be, 输出迭代器)//algorithm

交集set_intersection

差set_difference

重载 unset: 模板添加一个类,重载 \=\= 方法与返回 size\_t 的 () 方法

```c++
#include <bits/stdc++.h>
using namespace std;
unordered_set<int> s = {1, 1, 4, 5, 1, 4};
struct node
{
    int x, y, z;
    bool operator==(const node &r) const
    {
        return x == r.x && y == r.y && z == r.z;
    }
    size_t operator()(const node &r) const
    {
        return r.x * 1e9 + r.y * 1e5 + r.z;
    }
};
unordered_set<node, node> s2;
int main()
{
    printf("%d\n", s.size());
    s2.insert({1, 2, 3});
    s2.insert({1, 2, 3});
    s2.insert({1, 2, 4});
    printf("%d\n", s2.size());
    return 0;
}
```





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

可以直接当 bool 数组来用。也有方法：

1. 基本的位操作，如：$s|=s<<w[i];$
2. .count()计算1的个数
3. .any()是否存在1
4. .none()是否不存在1
5. .set()全设为1
6. .reset()全设为0
7. .flip()按位取反
8. .test(i) 第i位是不是1

上述函数可以传一个参数，则只对该位操作



##### 其他

priority_queue

默认大根堆。定义小根堆：(或自行写结构体)

```c++
priority_queue<int, vector<int>,greater<int> > q;
```



tuple

直接用 `{}` 构造

取出(如 `map` 迭代器里的可能要先 `second` 一下)，然后用 `tie(a,b,c)=tuple变量` 的方法获得每个元素



list 双向链表

deque

array, valarray



`complex<T>` 复数，支持 `(,)` 构造，能传入 `abs`, `arg`($[-\pi,\pi]$ 离 x 正半最近的偏移)，能和 T 运算。`conj` 共轭复数，`norm` 范数，`polar(T rho,T theta)` 构造对应复数



#### pb_ds

有一种比 unordered_map 更快的哈希表，具体参见上文 `线段树-树上二分`。

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

- 短板 (仅快读)

```c++
#define gc() (is == it ? it = (is = in) + fread(in, 1, Q, stdin), (is == it ? EOF : *is++) : *is++)
const int Q = (1 << 24) + 1;
char in[Q], *is = in, *it = in, c;
void read(long long &n) {
    for (n = 0; (c = gc()) < '0' || c > '9';);
    for (; c <= '9' && c >= '0'; c = gc()) n = n * 10 + c - 48;
}
```

- 长版

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
input = sys.stdin.readline # 实测约快10倍
print = sys.stdout.write # 仅字符串输出(注意不会换行)
```



Java

```java
import java.io.*;

public class Main {
    static StreamTokenizer scanner = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

    public static int nextInt() throws IOException {// 快约一倍
        scanner.nextToken();
        return (int) scanner.nval;
    }

    public static long nextLong() throws IOException {
        scanner.nextToken();
        return (long) scanner.nval;
    }

    static String next() throws IOException {
        scanner.nextToken();
        return scanner.sval;
    }

    public static void main(String[] args) throws IOException {
        int n = nextInt() / 10;
        for (int i = 0; i < n; ++i) {
            int s = 0;
            for (int j = 0; j < 10; ++j) {
                s += nextInt();
            }
            out.println(s);// 实测快约4倍
        }
        out.close();// 没有的话什么也不输出
    }
}
```





#### 其他

```c++
#pragma GCC optimize(2)
```



快速乘：($a\times b\bmod p$)

```c++
return ((ull)a*b-(ull)((ull)a/k*b)*k+k)%k; 
```

防炸 ll 不开 i128 的模乘：

```c++
LL mul(LL a, LL b, LL P){
    LL L = a * (b >> 25LL) % P * (1LL << 25) % P;
    LL R = a * (b & ((1LL << 25) - 1)) % P;
    return (L + R) % P;
}
```

l
