template<typename F = int, typename C = int, typename G>
auto ssp(G&& g, std::size_t s, std::size_t t, bool nneg = false)
-> std::pair<
 typename std::common_type<F, typename std::remove_reference<G>::type::edge_type::flow_type>::type,
 typename std::common_type<C, typename std::remove_reference<G>::type::edge_type::cost_type>::type>
{
 using graph_type = typename std::remove_reference<G>::type;
 using size_type = typename graph_type::size_type;
 using edge_type = typename graph_type::edge_type;
 using flow_type = typename std::common_type<F, typename edge_type::flow_type>::type;
 using cost_type = typename std::common_type<C, typename edge_type::cost_type>::type;
 static constexpr size_type BIN_LEN = std::numeric_limits<cost_type>::digits;
 static constexpr cost_type INF = std::numeric_limits<cost_type>::max();
 struct ShortestPath {
     size_type pre;
     cost_type pot, dis;
 };
 struct ListNode {
     size_type prev, next;
 };
 const size_type n = g.order(), m = g.size();
 const bool use_heap = m / n <= n / std::min<size_type>(3 * details::bsr(n + 7) + 15, 64);
 const auto edges = g.raw_edges();
 const auto pos = g.raw_pos();
 std::vector<ShortestPath> sp(n);
 std::vector<bool> vis;
 const auto init = [&] {
     vis.assign(n, false);
     std::vector<size_type> q(n);
     size_type l = 0, r = 1;
     for (auto& e : sp)
         e.pot = INF;
     sp[s] = {0, 0};
     vis[s] = true;
     q[0] = s;
     while (l != r) {
         const size_type u = q[l];
         l = l + 1 != n ? l + 1 : 0;
         vis[u] = false;
         const size_type pu = sp[u].pre;
         const cost_type du = sp[u].pot;
         const auto start_edge = edges + pos[u];
         const auto end_edge = edges + pos[u + 1];
         for (auto i = start_edge;i != end_edge;++i) {
             const edge_type e = *i;
             if (e.full()) continue;
             const size_type v = e.to();
             const cost_type dv = sp[v].pot;
             const cost_type ndv = du + e.cost();
             if (ndv < dv) {
                 sp[v].pre = pu + 1;
                 sp[v].pot = ndv;
                 if (sp[v].pre >= n) throw std::invalid_argument("graph contains negative cycles.");
                 if (!vis[v]) {
                     q[r] = v;
                     vis[v] = true;
                     r = r + 1 != n ? r + 1 : 0;
                 }
             }
         }
     }
 };
 if (!nneg) init();
 const cost_type pt = sp[t].pot;
 flow_type flow = 0;
 cost_type cost = 0;
 const auto augment = [&] {
     flow_type f = std::numeric_limits<flow_type>::max();
     for (size_type i = t;i != s;) {
         const edge_type e = edges[sp[i].pre];
         const flow_type r = edges[e.rev()].residual();
         if (r < f) f = r;
         i = e.to();
     }
     for (size_type i = t;i != s;) {
         auto& e = edges[sp[i].pre];
         edges[e.rev()].push(f);
         e.push(-f);
         i = e.to();
     }
     flow += f;
     const cost_type dt = sp[t].dis;
     for (auto& e : sp)
         if (e.dis < dt)
             e.pot -= dt - e.dis;
     cost += cost_type(f) * (pt - sp[s].pot);
 };
 const auto flow_with_heap = [&] {
     std::vector<ListNode> list(n + BIN_LEN + 1);
     const auto dijkstra_with_heap = [&] {
         const auto radix_distance = [] (cost_type lhs, cost_type rhs) {
             return lhs != rhs ? details::bsr(lhs ^ rhs) + 1 : 0;
         };
         const auto buk = list.data() + n;
         const auto insert_list = [&] (size_type idx, size_type v) {
             const size_type rear = buk[idx].prev;
             list[rear].next = v;
             list[v].prev = rear;
             buk[idx].prev = v;
             list[v].next = idx + n;
         };
         cost_type top = 0;
         for (size_type i = 0;i <= n + BIN_LEN;++i)
             list[i] = {i, i};
         list[s] = {n, n};
         buk[0] = {size_type(s), size_type(s)};
         for (auto& e : sp)
             e.dis = INF;
         sp[s].dis = 0;
         while (true) {
             size_type u = buk[0].next;
             if (u == n) {
                 size_type idx = 1;
                 for (;idx <= BIN_LEN;++idx)
                     if (buk[idx].next < n)
                         break;
                 if (idx > BIN_LEN) break;
                 const size_type head = buk[idx].next;
                 top = sp[head].dis;
                 for (size_type i = head;(i = list[i].next) < n;)
                     if (sp[i].dis < top)
                         top = sp[i].dis;
                 for (size_type i = head;i < n;) {
                     const size_type j = list[i].next;
                     insert_list(radix_distance(top, sp[i].dis), i);
                     i = j;
                 }
                 buk[idx] = {idx + n, idx + n};
                 u = buk[0].next;
             }
             if (u == size_type(t)) return true;
             const size_type next = list[u].next;
             list[next].prev = n;
             buk[0].next = next;
             const cost_type pu = sp[u].pot;
             const cost_type du = sp[u].dis;
             const auto start_edge = edges + pos[u];
             const auto end_edge = edges + pos[u + 1];
             for (auto i = start_edge;i != end_edge;++i) {
                 const edge_type e = *i;
                 if (e.full()) continue;
                 const size_type v = e.to();
                 const cost_type pv = sp[v].pot;
                 const cost_type dv = sp[v].dis;
                 const cost_type ndv = e.cost() + pu - pv + du;
                 if (ndv < dv) {
                     const size_type new_idx = radix_distance(top, ndv);
                     if (new_idx != radix_distance(top, dv)) {
                         const size_type prev = list[v].prev;
                         const size_type next = list[v].next;
                         list[prev].next = next;
                         list[next].prev = prev;
                         insert_list(new_idx, v);
                     }
                     sp[v].dis = ndv;
                     sp[v].pre = e.rev();
                 }
             }
         }
         return false;
     };
     while (dijkstra_with_heap())
         augment();
 };
 const auto flow_without_heap = [&] {
     std::vector<size_type> min_buk;
     const auto dijkstra_without_heap = [&] {
         vis.assign(n, false);
         min_buk = {size_type(s)};
         for (auto& e : sp)
             e.dis = INF;
         sp[s].dis = 0;
         while (true) {
             size_type u;
             cost_type du;
             if (!min_buk.empty()) {
                 u = min_buk.back();
                 min_buk.pop_back();
                 if (vis[u]) continue;
                 du = sp[u].dis;
             } else {
                 du = INF;
                 for (size_type i = 0;i < n;++i)
                     if (!vis[i] && sp[i].dis < du)
                         du = sp[u = i].dis;
                 if (du == INF) break;
             }
             if (u == size_type(t)) return true;
             vis[u] = true;
             const cost_type pu = sp[u].pot;
             const auto start_edge = edges + pos[u];
             const auto end_edge = edges + pos[u + 1];
             for (auto i = start_edge;i != end_edge;++i) {
                 const edge_type e = *i;
                 if (e.full()) continue;
                 const size_type v = e.to();
                 const cost_type pv = sp[v].pot;
                 const cost_type dv = sp[v].dis;
                 const cost_type ndv = e.cost() + pu - pv + du;
                 if (ndv < dv) {
                     sp[v].dis = ndv;
                     sp[v].pre = e.rev();
                     if (ndv == du) min_buk.push_back(v);
                 }
             }
         }
         return false;
     };
     while (dijkstra_without_heap())
         augment();
 };
 if (use_heap)
     flow_with_heap();
 else
     flow_without_heap();
 return std::make_pair(flow, cost);
}
