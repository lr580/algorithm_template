#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

#define int long long

using namespace std;

typedef long long ll;

auto seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 gen(seed);
    
uniform_int_distribution<long long> dis(1, (long long)1e18);

ll qpow(ll a, ll b, ll mod)
{
    ll r = 1;
    
    for (; b; b >>= 1)
    {
        if (b & 1)
            r = (__int128)r * a % mod;
        a = (__int128)a * a % mod;
    }
    
    return r;
}

bool miller_rabin(ll p, ll k = 30) // 判断素数
{
    if (p < 2) return false;
    if (p == 2) return true;
    if (p == 3) return true;
    
    ll d = p - 1, r = 0;
    while (!(d & 1)) ++r, d >>= 1; // 将d处理为奇数
    
    while(k--) // k次随机运算提高准确率
    {
        ll a = dis(gen) % (p - 2) + 2;
        ll x = qpow(a, d, p);
        
        if (x == 1 || x == p - 1) continue;
        
        for (ll i = 0; i < r - 1; ++i)
        {
            x = (__int128)x * x % p;
            
			if (x == p - 1) break;
        }
        
        if (x != p - 1) return false;
    }
    
    return true;
}

ll pollard_rho(ll x)
{
    ll c = dis(gen) % (x - 1) + 1;
    
    for (ll goal = 1, s = 0, t; true; goal <<= 1, s = t)
    {
    	ll val = 1;
    	
        for (ll step = 1; step <= goal; ++step)
        {
            t = ((__int128)t * t + c) % x; //随机数生成器
            val = ((__int128)val * abs(t - s)) % x;
            
            if (step % 127 == 0)
            {
                ll d = __gcd(val, x);
                if (d > 1) return d;
            }
        }
        
        ll d = __gcd(val, x);
        if (d > 1) return d;
    }
}

ll get_maxi_prime_factor(ll x)
{
    if (x < 2) return 0;
    
    if (miller_rabin(x)) return x;
    
    ll p = x;
    while (p >= x) p = pollard_rho(x); //直到找到平凡
    while (x % p == 0) x /= p;
    
    return max(get_maxi_prime_factor(x), get_maxi_prime_factor(p)); //返回最大质因子
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    
	ll t, n;
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        
        ll mx = get_maxi_prime_factor(n);
        
        if (mx == n) cout << "Prime\n";
        else cout << mx << '\n';
    }
    
    return 0;
}

/* 因式分解：
void get_prime_factors(ll base, ll index, map<ll, ll>& cnt_prime_fac)
{
    if (base < 2) return;
    
    if (miller_rabin(base))
    {
        cnt_prime_fac[base]+=index;
        
        return;
    }
    
    ll new_fac= base, multimes = 0;
    while (new_fac >= base) new_fac = pollard_rho(base); //直到找到平凡
    while (base % new_fac == 0) base /= new_fac, multimes++;
    
    get_prime_factors(base, index, cnt_prime_fac);
	get_prime_factors(new_fac, index * multimes, cnt_prime_fac);
    
    return;
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    
	map<ll,ll> prime_factors;
	get_prime_factors(27, 2, prime_factors);
	
	for(auto x:prime_factors) cout<<x.first<<':'<<x.second<<'\n';
    
    return 0;
}

*/