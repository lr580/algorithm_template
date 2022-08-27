ll dfn[mn], low[mn], st, stk[mn], stop, cn;
vector<ll> c[mn]; //点双
void tarjan(ll u)
{
    dfn[u] = low[u] = ++st;
    stk[++stop] = u;
    for (ll i = hd[u]; i; i = e[i].nx)
    {
        ll v = e[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u])
            { //找出新的点双上的所有点
                c[++cn].push_back(u);
                for (ll w = 0; w != v;)
                {
                    w = stk[stop--];
                    c[cn].push_back(w);
                }
            }
        }
        else
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
}