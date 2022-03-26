#include <bits/stdc++.h>
using namespace std;
int s, n, m, a, b, f[2500];
char ch;
int find(int x)
{
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++)
    {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> ch >> a >> b;
        if (ch == 'F')
        {
            f[find(a)] = find(b); //合并
        }
        else
        {
            f[find(a + n)] = find(b);
            f[find(b + n)] = find(a); //反集合并
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == i)
            s++;
    }
    cout << s; //祖先数就是团伙数
}