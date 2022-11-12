#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;
using namespace std;

ull count_primes(ull x)
{
    if (x <= 1)
        return 0;

    const int eps = 128;
    const int eps_bit = 8;

    uint S2 = sqrtl(x);
    uint S3 = powl(x, 1.0 / 3);
    uint S4 = sqrtl(S2);
    uint B = std::max(2ull, std::min(ull(S2), ull(S3 * std::max(1.0, pow(log(x), 3) * 0.001))));
    uint U = x / B + eps;

    uint a, b, t;
    register uint p, q, r, u, v;
    ll sum = 0;

    vector<char> mu(B + 1);
    mu[1] = 1;
    for (a = 2; a <= B; ++a)
        if (!mu[a])
            for (b = a; b <= B; b += a)
                mu[b] = mu[b] < 0 ? 1 : -1;
    for (a = 2; a * a <= B; ++a)
        if (mu[a * a])
            for (b = a * a; b <= B; b += a * a)
                mu[b] = 0;

    vector<int> pi(U), primes(uint(U / log(U) * 1.25506)), md(U);
    uint count = 0;
    md[1] = 1 << 30, primes[0] = 1;
    for (a = 6; a < U; a += 3)
        md[a] = 3;
    for (a = 4; a < U; a += 2)
        md[a] = 2;
    for (a = 4; a * a < U; ++a)
        if (!md[a])
        {
            for (b = a * a; b < U; b += 6 * a)
                if (!md[b])
                    md[b] = a;
            for (b = a * (a + (3 - a % 3) * 2); b < U; b += 6 * a)
                if (!md[b])
                    md[b] = a;
        }
    for (a = 2; a < U; ++a)
        pi[a] = md[a] ? pi[a - 1] : (primes[++count] = md[a] = a, pi[a - 1] + 1);

    sum += pi[B] - 1;
    for (p = pi[B] + 1; primes[p] <= S2; ++p)
        sum -= pi[x / primes[p]] - p + 1;
    for (a = 1; a <= B; ++a)
        if (mu[a])
            sum += mu[a] * (x / a);
    for (p = sqrtl(x / primes[pi[B]]) + 1; p <= B; ++p)
        if (pi[p] != pi[p - 1])
            sum += pi[B] - pi[std::max(uint(x / p / p), p)];

    for (p = S4 + 1; p <= S3; ++p)
        if (pi[p] != pi[p - 1])
        {
            uint L = p + 1, R = std::min((ull)B, x / p / p);
            sum += (ll)(2 - pi[p]) * (pi[R] - pi[L - 1]);
            ull m = x / p;
            for (u = L; u <= R; u = v + 1)
            {
                t = pi[m / primes[pi[u - 1] + 1]];
                v = m / primes[t];
                if (v > R)
                    v = R;
                sum += (ll)(pi[v] - pi[u - 1]) * t;
            }
        }

    vector<int> bit(U);
    vector<int> nxt(B + 2);
    for (q = 1; q <= B; ++q)
        nxt[q] = q + !mu[q];
    nxt[B + 1] = B + 1;
    for (r = 1; r <= U - eps; ++r)
        bit[r] = r;
    for (p = 1; p <= S4; ++p)
        if (pi[p] != pi[p - 1])
        {
            ull m = x / p;
            if (p <= eps_bit)
            {
                for (q = std::max(p, B / p) + 1; q <= B; ++q)
                {
                    while (q != nxt[q])
                        q = nxt[q] = nxt[nxt[q]];
                    if (q > B)
                        break;
                    if (md[q] <= p)
                    {
                        nxt[q] = q + 1;
                        continue;
                    }
                    sum -= mu[q] * bit[m / q];
                }
                for (r = 1; r < U; ++r)
                    bit[r] = md[r] > p;
                if (pi[p] < count && primes[pi[p] + 1] > eps_bit)
                {
                    for (r = 1; r < U; ++r)
                        if (r + lowbit(r) < U)
                            bit[r + lowbit(r)] += bit[r];
                }
                else
                {
                    for (r = 1; r < U; ++r)
                        bit[r] += bit[r - 1];
                }
            }
            else
            {
                for (q = std::max(p, B / p) + 1; q <= B; ++q)
                {
                    while (q != nxt[q])
                        q = nxt[q] = nxt[nxt[q]];
                    if (q > B)
                        break;
                    if (md[q] <= p)
                    {
                        nxt[q] = q + 1;
                        continue;
                    }
                    if (mu[q] == 1)
                    {
                        for (a = m / q; a; a -= lowbit(a))
                            sum -= bit[a];
                    }
                    else
                    {
                        for (a = m / q; a; a -= lowbit(a))
                            sum += bit[a];
                    }
                }
                for (a = p; a < U; a += lowbit(a))
                    --bit[a];
                for (r = p * p; r < U; r += 6 * p)
                    if (md[r] == p)
                        for (a = r; a < U; a += lowbit(a))
                            --bit[a];
                for (r = p * (p + (3 - p % 3) * 2); r < U; r += 6 * p)
                    if (md[r] == p)
                        for (a = r; a < U; a += lowbit(a))
                            --bit[a];
            }
        }

    return sum;
}

int main()
{
    ull n;
    cin >> n;
    cout << count_primes(n);
}