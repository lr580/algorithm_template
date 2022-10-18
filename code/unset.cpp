#include <bits/stdc++.h>
using namespace std;
unordered_set<int> s = {1, 1, 4, 5, 1, 4};
struct node
{
    int x, y, z;
    bool operator==(const node &r) const
    {
        return x == r.x && y == r.y && z == r.z;
    }
    size_t operator()(const node &r) const
    {
        return r.x * 1e9 + r.y * 1e5 + r.z;
    }
};
unordered_set<node, node> s2;
int main()
{
    printf("%d\n", s.size());
    s2.insert({1, 2, 3});
    s2.insert({1, 2, 3});
    s2.insert({1, 2, 4});
    printf("%d\n", s2.size());
    return 0;
}