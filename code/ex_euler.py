# https://oj.socoding.cn/p/2117
p, phi, f, fp = 998244353, 998244352, [1, 1], [1, 1]
for i in range(2, 5001):
    f.append((f[-1] * i) % p)
    fp.append((fp[-1] * i) % phi)
for _ in range(int(input())):
    n = int(input())
    print(pow(f[n], fp[n], p))