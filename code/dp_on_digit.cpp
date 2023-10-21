// https://leetcode.cn/problems/number-of-digit-one/
#include <bits/stdc++.h>
using namespace std;
const int M = 15;
int countDigitOne(int n) {
    auto s = to_string(n);
    int m = s.length();
    int dp[M][M];
    memset(dp, -1, sizeof(dp));
    function<int(int, int, bool)> f = [&](int i, int cnt1, bool is_limit) -> int {
        if (i == m) return cnt1;
        if (!is_limit && dp[i][cnt1] >= 0) return dp[i][cnt1];
        int res = 0;
        for (int d = 0, up = is_limit ? s[i] - '0' : 9; d <= up; ++d) // 枚举要填入的数字 d
            res += f(i + 1, cnt1 + (d == 1), is_limit && d == up);
        if (!is_limit) dp[i][cnt1] = res;
        return res;
    };
    return f(0, 0, true);
}
