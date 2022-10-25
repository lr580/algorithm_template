**当前最新普通版发布版本为 `v1.1.0`** ，  **最新打印版发布版本为 `v1.1.0` (总词数约9.0w(含代码))**

成品为 `template.pdf` (移步 [releases](https://github.com/lr580/algorithm_template/releases) 查看/下载)

> 因打印版 `pdf` 目录页码制作困难，因此直到版本 `v1.2.0` 之前不会更新打印版，只会更新普通发布版

<hr/>

## 模板简介

这是一份适用于算法竞赛的 C++ 为主的代码模板集合。主要用作 ICPC区域赛/CCPC 比赛时的参考资料，可打印。本模板收录大部分铜牌算法和银牌算法，不收录过于基础的内容(如栈)，也不收录过难的内容(如广义后缀自动机)。不定期更新。

本模板主要浓缩提炼自我的算法笔记(三份笔记，折合约28.5万+2.5万+5万=36万字(含代码))，历时约两周爆肝制成，因时间仓促，难免可能产生纰漏，如果您发现了任何错误之处或者如果您对本模板的内容增删改有任何意见或建议，欢迎您随时提出 >_<

> 目前版本使用 Typora 制作，有生之年有概率考虑使用 LaTeX 重做本模板。碍于本人技术有限，目前目录页码是手动制作的(使用Adobe Acrobat DC逐目录项修改)，因此可能会出现页码不正确，若发现欢迎纠正

目前模板收录的模块大致如下：(具体请参见详细目录)

1. 数学

   主要含组合数学、数论、计算几何、博弈论等

2. 数据结构

3. 图论

   主要含树上问题、图论基础、二分图、网络流等

4. 动态规划

5. 字符串

6. 杂项

   主要含排序、二分、搜索、高精度、STL等

正文源码在 `template.md` 文件中

> 推荐编辑/阅读该源码文件所用工具为 Typora beta 0.11.17

> 部分代码源码在 `codes/` 内

<s>Star it to keep trace of any possible updates!</s>



## 更新日志

- 22/10/19 - 22/10/20 (`v1.1.0`)

  - 添加了哈密顿图结论
  - 添加了划分数结论
  - 修改了点双连通分量参考代码
  - 添加了斐波那契数列等新的数学结论
  - 添加了竞赛图兰道定理等结论
  
- 22/09/01 - 22/10/18 (`v1.0.5`)

  - 添加了边双连通分量例题
  
  - 添加了可撤销并查集+线段树分治动态判二分图的例题
  - 修改了 manacher 一处错误
  - 修改了数论基础同余的一处书写错误
  - 添加了封装的最小费用最大流模板
  - 添加了后缀数组内容
  - 添加了 STL 重载 unordered\_set 内容
  - 添加了 pollard\_rho 算法
  - 添加了斐波那契数列模数循环节结论
  - 添加了线性快速幂
  - 添加了差分约束算法
  
- 22/06/10 - 22/08/27 (`v1.0.4`)

  - 微改了 STL 的  nth\_element 和 inplace\_merge

  - 微改了复杂度一节的排版错误
  - 删除了 STL 的 string 重复内容
  - 添加了多项式一节，增加 NTT 和分治 FFT 内容
  - 修正了线段树区间最值例题表述错误
  - 更换了欧拉筛一道例题
  - 添加了 tarjan 算法求点双连通分量和圆方树内容

- 22/05/17 - 22/05/25 (`v1.0.3`)

  - 增加了stringstream
  - 增加了普通莫队、带修莫队、树上莫队和回滚莫队算法
  - 增加了set部分内容
  - 增加了2-SAT算法

- 22/04/19 - 22/04/22 (`v1.0.2`)

  - 增加了KMP算法周期与border
  - 删除了凸包一节无关多余内容
  - 增加了另一种写法的C语言快读
  - 修正了计算几何判断线段相交的错误方法
  - 增改了随机化的程序语法、公式和爬山算法及模拟退火例题
  - 重制了珂朵莉树参考模板
  - 微增了博弈论理论内容

- 22/04/06 - 22/04/07 (`v1.0.1`)

  - 增加了位运算一节少量内容
  - 修改部分点分治笔记
  - 增加了 Java 快读快写
  - 增加可删堆，并与笛卡尔树、可并堆合并为堆专题

- 22/04/04  (`v1.0.0`)

  - 稍微补充了少量内容
  - 发布了第一版模板

- 22/04/03

  - 补充了数论、高等数学、杂项内容
  - 增加了博弈论、字符串、计算几何、线性代数和概率论、动态规划内容

- 22/04/02

  - 增加了数论主要内容、高等数学内容

- 22/04/01

  - 增加了图的连通性、组合数学、数学杂项内容

- 22/03/31

  - 增加了拓扑排序、最小生成树、二分图匹配、网络流内容

- 22/03/30

  - 增加了zkw线段树、猫树、K-D Tree内容，修改了部分内容
  - 增加了图概念、最短路内容

- 22/03/29

  - 增加整体二分、LIS、前缀和/差分内容
  - 增加了搜索、二分答案内容

- 22/03/28

  - 增加加权并查集内容

- 22/03/26

  - 补充树内容
  - 增加线段树、树状数组、平衡树等数据类型

- 22/03/25

  - 补充 STL 内容
  - 增加排序、组合数学、快读快写、高精度、树

- 22/03/24 

  - 开始模板编制工作
  - 增加部分数学公式、大部分 STL 内容

  

  

  

