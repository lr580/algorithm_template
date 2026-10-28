class Solution {
public:
    int connectTwoGroups(const vector<vector<int>>& cost) {
        const int m = cost.size(), n = cost[0].size();
        vector<int> row_min(m, INT_MAX);
        vector<int> col_min(n, INT_MAX);
        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n;++j) {
                row_min[i] = min(row_min[i], cost[i][j]);
                col_min[j] = min(col_min[j], cost[i][j]);
            }
        }
        MCFN<int, int> mcfn(m + n + 2);
        const int s = m + n, t = s + 1;
        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n;++j)
                mcfn.add_edge(i, m + j, 1, min(cost[i][j] - row_min[i] - col_min[j], 0));
            mcfn.add_edge(s, i, 1, 0);
        }
        for (int i = 0;i < n;++i)
            mcfn.add_edge(m + i, t, 1, 0);
        return reduce(row_min.begin(), row_min.end(), 0) + reduce(col_min.begin(), col_min.end(), 0) + ssp(mcfn.prepare(), s, t).second;
    }
};
