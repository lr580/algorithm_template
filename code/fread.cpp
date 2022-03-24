#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
const int _IB = 1e6;
char _ibuf[_IB], *_s, *_t;
#define getchar() \
    (_s == _t && (_t = (_s = _ibuf) + fread(_ibuf, 1, _IB, stdin), _s == _t) ? EOF : *_s++)
signed main()
{
    char x = getchar();
    printf("%c", x);
    return 0;
}