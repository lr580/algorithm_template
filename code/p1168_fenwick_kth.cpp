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
		if(ans>tot||now+bit[ans]>=k)ans-=(1<<i);//如果超了总体的最大值（防止数组越界），或者是 超过了k个，就退回去，这里注意是大于等于，因为要考虑有重复元素，所以我们找的其实是一个满足小于他的个数小于k的最大数。。（可能不好理解，跑两遍样例就行了） 
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