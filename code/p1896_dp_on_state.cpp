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