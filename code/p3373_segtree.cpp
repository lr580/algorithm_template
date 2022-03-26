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