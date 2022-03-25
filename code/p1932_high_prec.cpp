// luogu-judger-enable-o2
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cassert>

typedef int i32;
typedef unsigned u32;
typedef unsigned long long u64;

struct BigInt
{
    const static u32 exp = 9;
    const static u32 mod = 1000000000;

    static i32 abs_comp(const BigInt &lhs, const BigInt &rhs)
    {
        if (lhs.len != rhs.len)
            return lhs.len < rhs.len ? -1 : 1;
        for (u32 i = lhs.len - 1; ~i; --i)
            if (lhs.val[i] != rhs.val[i])
                return lhs.val[i] < rhs.val[i] ? -1 : 1;
        return 0;
    }

    u32 *val, len, sgn;

    BigInt(u32 *val = nullptr, u32 len = 0, u32 sgn = 0) : val(val), len(len), sgn(sgn) {}

    // copy_to cannot guarantee val[x] == 0 for x >= len
    // other function should set (the position they assume to be zero) as zero
    void copy_to(BigInt &dst) const
    {
        dst.len = len, dst.sgn = sgn;
        memcpy(dst.val, val, sizeof(u32) * len);
    }

    void trim()
    {
        while (len && !val[len - 1])
            --len;
        if (len == 0)
            sgn = 0;
    }

    void add(BigInt &x)
    {
        if (sgn ^ x.sgn)
            return x.sgn ^= 1, sub(x);
        val[len = std::max(len, x.len)] = 0;
        for (u32 i = 0; i < x.len; ++i)
            if ((val[i] += x.val[i]) >= mod)
                val[i] -= mod, ++val[i + 1];
        for (u32 i = x.len; i < len && val[i] >= mod; ++i)
            val[i] -= mod, ++val[i + 1];
        if (val[len])
            ++len;
    }

    void sub(BigInt &x)
    {
        if (sgn ^ x.sgn)
            return x.sgn ^= 1, add(x);
        if (abs_comp(*this, x) < 0)
            std::swap(*this, x), sgn ^= 1;
        val[len] = 0;
        for (u32 i = 0; i < x.len; ++i)
            if ((val[i] -= x.val[i]) & 0x80000000)
                val[i] += mod, --val[i + 1];
        for (u32 i = x.len; i < len && val[i] & 0x80000000; ++i)
            val[i] += mod, --val[i + 1];
        trim();
    }

    void mul(BigInt &x, u32 *ext_mem)
    {
        assert(this != &x);
        memcpy(ext_mem, val, sizeof(u32) * len);
        memset(val, 0, sizeof(u32) * (len + x.len));
        for (u32 i = 0; i < len; ++i)
            for (u32 j = 0; j < x.len; ++j)
            {
                u64 tmp = (u64)ext_mem[i] * x.val[j] + val[i + j];
                val[i + j] = tmp % mod;
                val[i + j + 1] += tmp / mod;
            }
        len += x.len, sgn ^= x.sgn;
        trim();
    }

    void mul(u32 x)
    {
        if (x & 0x80000000)
            x = -x, sgn ^= 1;
        u64 carry = 0;
        for (u32 i = 0; i < len; ++i)
        {
            carry += (u64)val[i] * x;
            val[i] = carry % mod;
            carry /= mod;
        }
        if (carry)
            val[len++] = carry;
        trim();
    }

    void div(BigInt &x, BigInt &remainder, u32 *ext_mem)
    {
        assert(this != &x && this != &remainder);
        copy_to(remainder), memset(val, 0, sizeof(u32) * len);
        u32 shift = len - x.len;
        if (shift & 0x80000000)
            return void(len = sgn = 0);
        while (~shift)
        {
            u32 l = 0, r = mod;
            BigInt mul_test{ext_mem}, remainder_high{remainder.val + shift, remainder.len - shift};
            while (l <= r)
            {
                u32 mid = (l + r) / 2;
                x.copy_to(mul_test), mul_test.mul(mid);
                abs_comp(mul_test, remainder_high) < 0 ? l = mid + 1 : r = mid - 1;
            }
            val[shift] = r;
            x.copy_to(mul_test), mul_test.mul(r);
            remainder_high.sub(mul_test), remainder.trim();
            --shift;
        }
        sgn ^= x.sgn;
        trim();
    }

    void div(u32 x)
    {
        if (x & 0x80000000)
            x = -x, sgn ^= 1;
        u64 carry = 0;
        for (u32 i = len - 1; ~i; --i)
        {
            carry = carry * mod + val[i];
            val[i] = carry / x;
            carry %= x;
        }
        trim();
    }

    void read(const char *s)
    {
        sgn = len = 0;
        i32 bound = 0, pos;
        if (s[0] == '-')
            sgn = bound = 1;
        u64 cur = 0, pow = 1;
        for (pos = strlen(s) - 1; pos + 1 >= exp + bound; pos -= exp, val[len++] = cur, cur = 0, pow = 1)
            for (i32 i = pos; i + exp > pos; --i)
                cur += (s[i] - '0') * pow, pow *= 10;
        for (cur = 0, pow = 1; pos >= bound; --pos)
            cur += (s[pos] - '0') * pow, pow *= 10;
        if (cur)
            val[len++] = cur;
    }

    void print()
    {
        if (len)
        {
            if (sgn)
                putchar('-');
            printf("%u", val[len - 1]);
            for (u32 i = len - 2; ~i; --i)
                printf("%0*u", exp, val[i]);
        }
        else
            putchar('0');
        puts("");
    }
};

const int N = 1e4 + 20;
u32 a_[N], b_[N], r_[N], tmp[N * 2];
char sa[N], sb[N];

int main()
{
    scanf("%s%s", sa, sb);
    {
        BigInt a{a_}, b{b_};
        a.read(sa), b.read(sb), a.add(b), a.print();
    }
    {
        BigInt a{a_}, b{b_};
        a.read(sa), b.read(sb), a.sub(b), a.print();
    }
    {
        BigInt a{a_}, b{b_};
        a.read(sa), b.read(sb), a.mul(b, tmp), a.print();
    }
    {
        BigInt a{a_}, b{b_}, r{r_};
        a.read(sa), b.read(sb), a.div(b, r, tmp), a.print();
        r.print();
    }
}
/*除法修复：
BigInt a{a_}, b{b_}, r{r_};
a.read(sa), b.read(sb), a.div(b, r, tmp);
if (memcmp(b.val, r.val, sizeof b.val) == 0)
{
    BigInt one{tmp};
    one.read("1");
    a.add(one);
}
a.print();
*/