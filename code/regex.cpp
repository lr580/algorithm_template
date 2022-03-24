// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define sc(x) scanf("%lld", &x)
// signed main()
// {
//     char data[] = "he...ll..o, worl..d!";
//     std::regex reg("\\.");
//     std::cout << std::regex_replace(data, reg, "");
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string s, t;
signed main()
{
    scanf("%lld%*c", &n);
    while (n--)
    {
        getline(cin, s);
        cin >> t;
        cin.ignore();
        regex reg("\\b" + t + "\\b");
        smatch m;
        auto lf = s.cbegin(); // begin(),end()参数不匹配
        auto rf = s.cend();
        ll ans = 0;
        for (; regex_search(lf, rf, m, reg); lf = m.suffix().first)
            ++ans;
        cout << ans << '\n';
    }
    return 0;
}