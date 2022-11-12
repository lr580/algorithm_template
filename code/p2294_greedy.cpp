#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 1100
using namespace std;
inline void read(int &x)
{
    x=0;
    int p=1;
    char c=getchar();
    while(!isdigit(c)){if(c=='-')p=-1;c=getchar();}
    while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^'0');c=getchar();}
    x*=p;

}//快速读入

int n,m;
struct node
{
    int l,r,s;
    bool operator < (const node &h)const
    {
        if(l!=h.l)return l>h.l;
        return r>h.r;

}//重载运算符，确定优先队列的优先级

}tmp;
priority_queue<node>q;
int main()
{
    int t;
    read(t);
    while(t--)
    {    
        while (!q.empty()) q.pop();//多组数据清空
        read(n);read(m);
        if(m==1){printf("true\n");continue;}//其实没必要特判，只是优化一点点
        for(int i=1;i<=m;i++)
        {
            int l,r,s;
            read(tmp.l);read(tmp.r);read(tmp.s);
            q.push(tmp);
        }
        tmp=q.top();//取出第一个
        q.pop();
        while(!q.empty())
        {    
            node tmp1;
            tmp1=q.top();
            q.pop();
            if(tmp.l==tmp1.l)
            {
                if(tmp.r==tmp1.r)
                {
                    if(tmp.s!=tmp1.s)
                    {printf("false\n");goto end;}//退出多重循环的小操作
                }
                else 
                if(tmp.r<tmp1.r)
                    q.push((node) {tmp.r+1, tmp1.r, tmp1.s - tmp.s});//将抵消后的部分放入队列
            }
            tmp = tmp1;//继续比
        }
        printf("true\n");
        end:;
    }
    return 0;
}