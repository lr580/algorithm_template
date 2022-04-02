// C++ Version
int is_prime[1000000], prime[300000];
int Eratosthenes(int n)
{
    int p = 0;
    for (int i = 0; i <= n; ++i)
        is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            prime[p++] = i; // prime[p]是i,后置自增运算代表当前素数数量
            if ((long long)i * i <= n)
                for (int j = i * i; j <= n; j += i)
                    // 因为从 2 到 i - 1 的倍数我们之前筛过了，这里直接从 i
                    // 的倍数开始，提高了运行速度
                    is_prime[j] = 0; // 是i的倍数的均不是素数
        }
    }
    return p;
}