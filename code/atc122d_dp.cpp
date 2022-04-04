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