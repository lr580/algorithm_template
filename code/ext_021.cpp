#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

// 比 unordered_map 更快的哈希表
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
typedef gp_hash_table<int, int, chash> hash_t;

int n, q, C[MAXN + 10], V[MAXN + 10];

hash_t colTree[MAXN + 10];
long long smTree[MAXN + 10];

int lb(int x) { return x & (-x); }

// val == -1：把位置 pos 的颜色 c 删掉
// val == 1：把位置 pos 的颜色设为 c
void addCol(int pos, int c, int val) {
    for (; pos <= n; pos += lb(pos)) colTree[pos][c] += val;
}

// 查询 vec 里的所有颜色在前 pos 个位置中一共出现了几次
int queryCol(int pos, vector<int> &vec) {
    int ret = 0;
    for (; pos; pos -= lb(pos)) for (int c : vec) {
        auto it = colTree[pos].find(c);
        if (it != colTree[pos].end()) ret += it->second;
    }
    return ret;
}

// 树状数组上倍增，
// 返回值 l 满足 vec 里所有颜色在区间 [l, lim] 中出现的总次数等于区间长度，且 l 最小
int gao1(int lim, vector<int> &vec) {
    int base = queryCol(lim, vec);
    if (base == lim) return 1;

    int b;
    for (b = 1; b <= n; b <<= 1);

    int now = 0, cnt = 0;
    for (b >>= 1; b; b >>= 1) {
        int nxt = now | b, tmp = 0;
        for (int c : vec) {
            auto it = colTree[nxt].find(c);
            if (it != colTree[nxt].end()) tmp += it->second;
        }
        if (nxt > lim || base - (cnt + tmp) == lim - nxt) {
            // do nothing
        } else {
            now = nxt; cnt += tmp;
        }
    }
    return now + 2;
}

// 树状数组上倍增，
// 返回值 r 满足 vec 里所有颜色在区间 [lim, r] 中出现的总次数等于区间长度，且 r 最大
int gao2(int lim, vector<int> &vec) {
    int base = queryCol(lim, vec);

    int b;
    for (b = 1; b <= n; b <<= 1);

    int now = 0, cnt = 0;
    for (b >>= 1; b; b >>= 1) {
        int nxt = now | b, tmp = 0;
        for (int c : vec) {
            auto it = colTree[nxt].find(c);
            if (it != colTree[nxt].end()) tmp += it->second;
        }
        if (nxt < lim || (cnt + tmp) - base == nxt - lim) {
            now = nxt; cnt += tmp;
        } else {
            // do nothing
        }
    }
    return now;
}

// 位置 pos 的权值增加 val
void addSm(int pos, long long val) {
    for (; pos <= n; pos += lb(pos)) smTree[pos] += val;
}

// 求前 pos 个位置的权值之和
long long querySm(int pos) {
    long long ret = 0;
    for (; pos; pos -= lb(pos)) ret += smTree[pos];
    return ret;
}

void solve() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &C[i]);
        addCol(i, C[i], 1);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &V[i]);
        addSm(i, V[i]);
    }

    while (q--) {
        int op, x, y; scanf("%d%d%d", &op, &x, &y);
        if (op == 1) {
            addCol(x, C[x], -1);
            addCol(x, y, 1);
            C[x] = y;
        } else if (op == 2) {
            addSm(x, y - V[x]);
            V[x] = y;
        } else {
            bool ok = false;
            vector<int> vec;
            for (int i = 1; i <= y; i++) {
                int z; scanf("%d", &z);
                if (C[x] == z) ok = true;
                vec.push_back(z);
            }
            if (!ok) { printf("0\n"); continue; }

            int L = gao1(x, vec), R = gao2(x, vec);
            printf("%lld\n", querySm(R) - querySm(L - 1));
        }
    }

    for (int i = 1; i <= n; i++) colTree[i].clear();
    for (int i = 1; i <= n; i++) smTree[i] = 0;
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
