#include <bits/stdc++.h>
using namespace std;

namespace details {
	inline unsigned int bsf32(uint32_t n) noexcept {
#if defined __GNUC__
		return __builtin_ctz(n);
#elif defined _MSC_VER
		unsigned long ans;
		_BitScanForward(&ans, n);
		return ans;
#elif
		static constexpr unsigned char table[32] = {
			0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,
			31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9,
		};
		return table[((n & -n) * 0x077CB531) >> 57];
#endif
	}

	inline unsigned int bsf64(uint64_t n) noexcept {
#if defined __GNUC__
		return __builtin_ctzll(n);
#elif defined _MSC_VER
		unsigned long ans;
		_BitScanForward64(&ans, n);
		return ans;
#elif
		static constexpr unsigned char table[64] = {
			0, 1, 56, 2, 57, 49, 28, 3, 61, 58, 42, 50, 38, 29, 17, 4,
			62, 47, 59, 36, 45, 43, 51, 22, 53, 39, 33, 30, 24, 18, 12, 5,
			63, 55, 48, 27, 60, 41, 37, 16, 46, 35, 44, 21, 52, 32, 23, 11,
			54, 26, 40, 15, 34, 20, 31, 10, 25, 14, 19, 9, 13, 8, 7, 6,
		};
		return table[((n & -n) * 0x03f79d71b4ca8b09) >> 58];
#endif
	}

	inline unsigned int bsr32(uint32_t n) noexcept {
#if defined __GNUC__
		return 31 - __builtin_clz(n);
#elif defined _MSC_VER
		unsigned long ans;
		_BitScanReverse(&ans, n);
		return ans;
#elif
		float t = n;
		uint32_t ans;
		memcpy(&ans, &t, sizeof(float));
		return (ans >> 23 & 255) - 127;
#endif
	}

	inline unsigned int bsr64(uint64_t n) noexcept {
#if defined __GNUC__
		return 63 - __builtin_clzll(n);
#elif defined _MSC_VER
		unsigned long ans;
		_BitScanReverse64(&ans, n);
		return ans;
#elif
		float t = n;
		uint32_t ans;
		memcpy(&ans, &t, sizeof(float));
		return (ans >> 23 & 255) - 127;
#endif
	}

	inline unsigned int popcnt32(uint32_t n) noexcept {
#if defined __GNUC__
		return __builtin_popcount(n);
#elif defined _MSC_VER
		return __popcnt(n);
#elif
		n -= ((n >> 1) & 0x55555555);
		n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
		return ((((n >> 4) + n) & 0x0f0f0f0f) * 0x01010101) >> 24;
#endif
	}

	inline unsigned int popcnt64(uint64_t n) noexcept {
#if defined __GNUC__
		return __builtin_popcountll(n);
#elif defined _MSC_VER
		return __popcnt64(n);
#elif
		n -= ((n >> 1) & 0x5555555555555555);
		n = (n & 0x3333333333333333) + ((n >> 2) & 0x3333333333333333);
		return ((((n >> 4) + n) & 0x0f0f0f0f0f0f0f0f) * 0x0101010101010101) >> 56;
#endif
	}

	inline unsigned int parity32(uint32_t n) noexcept {
#if defined __GNUC__
		return __builtin_parity(n);
#elif defined _MSC_VER
		return __popcnt(n) & 1;
#elif
		n ^= n >> 1;
		n ^= n >> 2;
		n = (n & 0x11111111) * 0x11111111;
		return (n >> 28) & 1;
#endif
	}

	inline unsigned int parity64(uint64_t n) noexcept {
#if defined __GNUC__
		return __builtin_parityll(n);
#elif defined _MSC_VER
		return __popcnt64(n) & 1;
#elif
		n ^= n >> 1;
		n ^= n >> 2;
		n = (n & 0x1111111111111111) * 0x1111111111111111;
		return (n >> 60) & 1;
#endif
	}


	template<typename I, bool B = 32 < std::numeric_limits<I>::digits>
	struct _BitFuncImpl {
		inline static unsigned int bsf(I n) noexcept { return bsf64(n); }
		inline static unsigned int bsr(I n) noexcept { return bsr64(n); }
		inline static unsigned int popcnt(I n) noexcept { return popcnt64(n); }
		inline static unsigned int parity(I n) noexcept { return parity64(n); }
	};

	template<typename I>
	struct _BitFuncImpl<I, false> {
		inline static unsigned int bsf(I n) noexcept { return bsf32(n); }
		inline static unsigned int bsr(I n) noexcept { return bsr32(n); }
		inline static unsigned int popcnt(I n) noexcept { return popcnt32(n); }
		inline static unsigned int parity(I n) noexcept { return parity32(n); }
	};

	template<typename I>
	inline unsigned int bsf(I n) noexcept { return _BitFuncImpl<I>::bsf(n); }
	template<typename I>
	inline unsigned int bsr(I n) noexcept { return _BitFuncImpl<I>::bsr(n); }
	template<typename I>
	inline unsigned int popcnt(I n) noexcept { return _BitFuncImpl<I>::popcnt(n); }
	template<typename I>
	inline unsigned int parity(I n) noexcept { return _BitFuncImpl<I>::parity(n); }
}

template<typename E>
class Network {
public:
 using edge_type = E;
 using size_type = unsigned;

private:
 size_type n, m;
 size_type* pos;
 std::unique_ptr<edge_type[]> edges;

public:
 Network(std::unique_ptr<edge_type[]> edges, std::unique_ptr<size_type[]> spos, size_type n, size_type m)
     : n(n), m(m), pos(spos.release() + 1), edges(std::move(edges))
 {
     pos[-1] = 1;
 }

 Network(const Network& other) : n(other.n), m(other.m), pos(other.pos), edges(new edge_type[m]) {
     std::copy_n(other.edges.get(), m, edges.get());
     ++pos[-1];
 }

 ~Network() { if (--pos[-1] == 0) delete[] (pos - 1); }

 inline size_type order() const noexcept { return n; }
 inline size_type size() const noexcept { return m; }
 inline const size_type* raw_pos() const noexcept { return pos; }
 inline const edge_type* raw_edges() const noexcept { return edges.get(); }
 inline edge_type* raw_edges() noexcept { return edges.get(); }
};

template<typename F = int, typename C = int>
class MCFN {
public:
 using size_type = unsigned;

private:
 struct RawEdge {
     size_type from, to;
     F cap;
     C cost;
 };

 struct Edge {
 private:
     friend class MCFN;
     size_type _rev, _to;
     F _cap;
     C _cost;
     Edge(size_type rev, size_type to, F cap, C cost) : _rev(rev), _to(to), _cap(cap), _cost(cost) {}
 public:
     using flow_type = F;
     using cost_type = C;
     Edge() = default;
     inline size_type rev() const noexcept { return _rev; }
     inline size_type to() const noexcept { return _to; }
     inline flow_type residual() const noexcept { return _cap; }
     inline bool full() const noexcept { return _cap == 0; }
     inline void push(flow_type d) noexcept { _cap -= d; }
     inline cost_type cost() const noexcept { return _cost; }
 };

 std::vector<RawEdge> edges;
 std::vector<size_type> deg;

public:
 MCFN() noexcept = default;

 MCFN(size_type n) : deg(n, 0) {}

 void reserve(size_type n, size_type m) {
     edges.reserve(m);
     deg.reserve(n);
 }

 inline size_type add_vertex() {
     const size_type ans = deg.size();
     deg.push_back(0);
     return ans;
 }

 inline void add_edge(size_type from, size_type to, F cap, C cost) {
     if (cap <= 0) return;
     edges.emplace_back(RawEdge{from, to, cap, cost});
     ++deg[from];
     ++deg[to];
 }

 Network<Edge> prepare() const {
     using size_type = typename Network<Edge>::size_type;
     const size_type n = deg.size(), m = edges.size();
     std::unique_ptr<Edge[]> sorted_edges(new Edge[2 * m]);
     std::unique_ptr<size_type[]> spos(new size_type[n + 2]);
     const auto pos = spos.get() + 1;
     *std::partial_sum(deg.begin(), deg.end(), pos) = 2 * m;
     for (size_type i = m;i-- > 0;) {
         const RawEdge e = edges[i];
         const size_type u = e.from, v = e.to;
         const size_type rp = --pos[v], p = --pos[u];
         sorted_edges[p] = Edge(rp, v, e.cap, e.cost);
         sorted_edges[rp] = Edge(p, u, 0, -e.cost);
     }
     return Network<Edge>(std::move(sorted_edges), std::move(spos), n, 2 * m);
 }
};

// 

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

// ... example usage

class Solution {
    using it = vector<int>::iterator;
    int reduce(it b, it e, int s) {
        for(;b!=e;++b) s+=*b;
        return s;
    } //C++17 STL supports
public:
    int connectTwoGroups(const vector<vector<int>>& cost) {
        const int m = cost.size(), n = cost[0].size();
        vector<int> row_min(m, INT_MAX);
        vector<int> col_min(n, INT_MAX);
        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n;++j) {
                row_min[i] = min(row_min[i], cost[i][j]);
                col_min[j] = min(col_min[j], cost[i][j]);
            }
        }
        MCFN<int, int> mcfn(m + n + 2);
        const int s = m + n, t = s + 1;
        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n;++j)
                mcfn.add_edge(i, m + j, 1, min(cost[i][j] - row_min[i] - col_min[j], 0));
            mcfn.add_edge(s, i, 1, 0);
        }
        for (int i = 0;i < n;++i)
            mcfn.add_edge(m + i, t, 1, 0);
        return reduce(row_min.begin(), row_min.end(), 0) + reduce(col_min.begin(), col_min.end(), 0) + ssp(mcfn.prepare(), s, t).second;
    }
};