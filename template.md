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
7. $C^m_n=(\matrix{n\\m})=\frac{n!}{m!(n-m)!}$
8. $A_n^m=P_n^m=\frac{n!}{(n-m)!}$



#### 组合数学



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
}
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



## 杂项



### 程序语法

#### 常规运算

注意：

- 浮点数除，被除数为 $0$ ，被除数和除数存在一个负数，结果为负零
- 取模只可以是整型之间的；负数运算结果等于取绝对值计算，最后正负号与被除数一致，如 $(-5)\bmod 3=-2,5\bmod (-3)=2$

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

- > `^` 用于汉明码



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



##### tuple

直接用 `{}` 构造

取出(如 `map` 迭代器里的可能要先 `second` 一下)，然后用 `tie(a,b,c)=tuple变量` 的方法获得每个元素



##### 其他

list

双向链表

deque

array, valarray



### 卡常

#### 快读/写

##### 普通



Python:

```python
import sys
input = sys.stdin.readline
print = sys.stdout.write # 仅字符串输出
```





##### 更快

```c++
const int _IB = 1e6;
char _ibuf[_IB], *_s, *_t;
#define getchar() \
    (_s == _t && (_t = (_s = _ibuf) + fread(_ibuf, 1, _IB, stdin), _s == _t) ? EOF : *_s++)
```





#### 其他

```c++
#pragma GCC optimize(2)
```

