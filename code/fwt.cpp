#include <bits/stdc++.h>
using namespace std;
int w;
int B[1 << 16];
void FWTand(int *a, int opt)
{
    int N = 1 << w;
    for (int mid = 1; mid < N; mid <<= 1)
        for (int R = mid << 1, j = 0; j < N; j += R)
            for (int k = 0; k < mid; k++)
                if (opt == 1)
                    a[j + k] += a[j + k + mid];
                else
                    a[j + k] -= a[j + k + mid];
}
int countTriplets(vector<int> &A)
{
    for (auto a : A)
    {
        B[a]++;
        while ((1 << w) <= a)
            w++;
    }
    FWTand(B, 1);
    for (int i = 0; i < (1 << w); i++)
        B[i] *= B[i] * B[i];
    FWTand(B, -1);
    return B[0];
}
