struct heap //可删堆(大根堆)
{
    priority_queue<ll> a, b;
    void insert(ll x) { a.push(x); }
    void erase(ll x) { b.push(x); }
    ll top()
    {
        while (!b.empty() && a.top() == b.top())
            a.pop(), b.pop();
        return a.top();
    }
    ll pop()
    {
        ll t = top(); a.pop(); return t;
    }
    ll size() { return a.size() - b.size(); }
}
