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
