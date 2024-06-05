#include <bits/stdc++.h> // https://leetcode.cn/problems/range-module
using namespace std;
using ll = long long;
class RangeModule
{
    constexpr static ll inf = 1e9;
    constexpr static ll maxn = 60 * 1e4; // log(inf)*q
    struct node
    {
        ll ls, rs, sum, laz;
    } t[maxn] = {};
    int cnt = 1;
#define cll const ll &
#define mkcf ll cf = (lf + rf) >> 1
    void pushdown(int r, cll lf, cll rf)
    {
        if (!t[r].ls)
            t[r].ls = ++cnt;
        if (!t[r].rs)
            t[r].rs = ++cnt;
        if (!t[r].laz)
            return;
        if (t[r].laz == 1)
        {
            mkcf;
            t[t[r].ls].sum = (cf - lf + 1); // len-len/2
            t[t[r].rs].sum = rf - cf;       // len/2
        }
        else
        {
            t[t[r].ls].sum = t[t[r].rs].sum = 0;
        }
        t[t[r].ls].laz = t[t[r].rs].laz = t[r].laz;
        t[r].laz = 0;
    }
    void pushup(int r)
    {
        t[r].sum = t[t[r].ls].sum + t[t[r].rs].sum;
    }
    void update(int r, ll lf, ll rf, cll lc, cll rc, cll v)
    {
        if (lc <= lf && rf <= rc)
        {
            t[r].sum += (v == 1) * (rf - lf + 1);
            t[r].laz = v;
            return;
        }
        pushdown(r, lf, rf);
        mkcf;
        if (lc <= cf)
            update(t[r].ls, lf, cf, lc, rc, v);
        if (rc >= cf + 1)
            update(t[r].rs, cf + 1, rf, lc, rc, v);
        pushup(r);
    }
    ll query(int r, ll lf, ll rf, cll lc, cll rc)
    {
        if (lc <= lf && rf <= rc)
            return t[r].sum;
        pushdown(r, lf, rf);
        ll res = 0;
        mkcf;
        if (lc <= cf)
            res += query(t[r].ls, lf, cf, lc, rc);
        if (rc >= cf + 1)
            res += query(t[r].rs, cf + 1, rf, lc, rc);
        return res;
    }

public:
    RangeModule() {}

    void addRange(int left, int right)
    {
        update(1, 1, inf, left, right - 1, 1);
    }

    bool queryRange(int left, int right)
    {
        return query(1, 1, inf, left, right - 1) == right - left;
    }

    void removeRange(int left, int right)
    {
        update(1, 1, inf, left, right - 1, -1);
    }
};

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    return 0;
}

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */