#include <bits/stdc++.h>
using namespace std; //https://leetcode.cn/problems/edit-distance
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
