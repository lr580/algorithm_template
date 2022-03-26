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
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
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