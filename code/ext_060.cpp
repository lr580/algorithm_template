ll lc[mn], rc[mn];
ll calcLCPsum()
{
    stack<ll> a;
    ll sum = 0;
    for (ll i = 1; i <= n + 1; ++i)
    {
        while (!a.empty() && hei[a.top()] > hei[i])
        {
            ll j = a.top();
            a.pop();
            rc[j] = i - j;
        }
        a.push(i);
    }
    stack<ll> b;
    for (ll i = n; i >= 0; --i)
    {
        while (!b.empty() && hei[b.top()] >= hei[i])
        {
            ll j = b.top();
            b.pop();
            lc[j] = j - i;
        }
        b.push(i);
    }
    for (ll i = 1; i <= n; ++i)
    {
        sum += hei[i] * lc[i] * rc[i];
    }
    return sum;
}
