#include <bits/stdc++.h>
using namespace std;
#define db double
const db pi = acos(-1);
#define MAX 1100000
char sa[MAX], sb[MAX];
int m, n, N, top, a[MAX], b[MAX];
int rev[MAX], sta[MAX];
#define il inline
#define ll int
#define re
il ll read()
{
    re char p = 0;
    re ll r = 0, o = 0;
    for (; p < '0' || p > '9'; o |= p == '-', p = getchar())
        ;
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar())
        ;
    return o ? (~r) + 1 : r;
}
struct cpx
{
    double x, y;
    cpx() {}
    cpx(double xx, double yy) { x = xx, y = yy; }
    cpx(int xx, int yy) { x = xx, y = yy; }
    friend cpx operator*(cpx a, cpx b)
    {
        return cpx(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
    }
    friend cpx operator/(cpx a, double b)
    {
        return cpx(a.x / b, a.y / b);
    }
    friend cpx operator+(cpx a, cpx b)
    {
        return cpx(a.x + b.x, a.y + b.y);
    }
    friend cpx operator-(cpx a, cpx b)
    {
        return cpx(a.x - b.x, a.y - b.y);
    }
    friend cpx operator*(cpx a, double b)
    {
        return cpx(a.x * b, a.y * b);
    }
};
cpx A[MAX], B[MAX], C[MAX];
void fft(cpx *a, int f)
{
    for (int i = 0; i < N; i++)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    for (int i = 1; i < N; i <<= 1)
    {
        cpx wn(cos(pi / i), f * sin(pi / i));
        for (int j = 0; j < N; j += (i << 1))
        {
            cpx w(1, 0);
            for (int k = 0; k < i; k++)
            {
                cpx x = a[j + k], y = w * a[j + k + i];
                a[j + k] = x + y;
                a[j + k + i] = x - y;
                w = w * wn;
            }
        }
    }
    if (f == -1)
        for (int i = 0; i < N; i++)
            a[i] = a[i] / N;
}
int main()
{
    scanf("%d%d%s%s", &m, &n, sa, sb);
    reverse(sa, sa + m);
    int l = 0;
    for (N = 1; N < 2 * n; N <<= 1)
    {
        l++;
    }
    for (int i = 0; i < N; i++)
    {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
    }
    for (int i = 0; i < m; i++)
    {
        if (sa[i] != '*')
        {
            a[i] = sa[i] - 'a' + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (sb[i] != '*')
        {
            b[i] = sb[i] - 'a' + 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        A[i] = cpx(a[i] * a[i] * a[i], 0);
    }
    for (int i = 0; i < n; i++)
    {
        B[i] = cpx(b[i], 0);
    }
    fft(A, 1);
    fft(B, 1);
    for (int i = 0; i < N; i++)
    {
        C[i] = C[i] + A[i] * B[i];
    }

    for (int i = 0; i < N; i++)
    {
        A[i] = B[i] = cpx(0, 0);
    }
    for (int i = 0; i < m; i++)
    {
        A[i] = cpx(a[i] * a[i], 0);
    }
    for (int i = 0; i < n; i++)
    {
        B[i] = cpx(b[i] * b[i], 0);
    }
    fft(A, 1);
    fft(B, 1);
    for (int i = 0; i < N; i++)
    {
        C[i] = C[i] - A[i] * B[i] * 2.0;
    }

    for (int i = 0; i < N; i++)
    {
        A[i] = B[i] = cpx(0, 0);
    }
    for (int i = 0; i < m; i++)
    {
        A[i] = cpx(a[i], 0);
    }
    for (int i = 0; i < n; i++)
    {
        B[i] = cpx(b[i] * b[i] * b[i], 0);
    }
    fft(A, 1);
    fft(B, 1);
    for (int i = 0; i < N; i++)
    {
        C[i] = C[i] + A[i] * B[i];
    }

    fft(C, -1);
    for (int i = m - 1; i < n; i++)
    {
        if (fabs(C[i].x) < 0.5)
        {
            sta[top++] = i - m + 2;
        }
    }
    printf("%d\n", top);
    for (int i = 0; i < top; i++)
    {
        printf("%d ", sta[i]);
    }
    return 0;
}