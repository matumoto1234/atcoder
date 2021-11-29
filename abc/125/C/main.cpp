#include <bits/stdc++.h>
using namespace std;

#include <atcoder/segtree.hpp>
using namespace atcoder;

// {{{ Templates

// clang-format off

// Macros
#define over_load_(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) over_load_(__VA_ARGS__, rep4, rep3, rep2)(__VA_ARGS__)
#define rep2(i, r) for ( int i = 0; i < static_cast<int>(r); (i) += 1)
#define rep3(i, l, r) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i) += 1)
#define rep4(i, l, r, stride) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i) += (stride))
#define rrep(...) over_load_(__VA_ARGS__, rrep4, rrep3, rrep2)(__VA_ARGS__)
#define rrep2(i, r) for ( int i = static_cast<int>(r) - 1; i >= 0; (i) -= 1)
#define rrep3(i, l, r) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= 1)
#define rrep4(i, l, r, stride) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= (stride))
#define len(x) (static_cast<int>((x).size()))
#define whole(f, x, ...) ([&](decltype((x)) container) { return (f)( begin(container), end(container), ## __VA_ARGS__); })(x)
#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__); })(x)
#define debug(...) debug_function(#__VA_ARGS__, __VA_ARGS__)

// Operators
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { bool is_first = true; for (auto x: v) { os << (is_first ? "" : " ") << x; is_first = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> v) { bool is_first = true; while (!v.empty()) { os << (is_first?"":" ")<<v.front(); v.pop(); is_first = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> v) { bool is_first = true; while (!v.empty()) { os << (is_first?"":" ") << v.top(); v.pop(); is_first=false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { rep (i, len(v)) os << v[i] << (i == len(v) - 1 ? "" : " "); return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<vector<T>> &v) { for (const auto &vec: v) { os << vec << '\n'; } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { rep (i, len(v)) os << v[i] << (i == len(v) - 1 ? "" : " "); return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) { bool is_first = true; for (T x: v) { os << (is_first ? "" : " ") << x; is_first = false; } return os; }
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in: v) { is >> in; } return is; }

// For debug macro
int find_comma_not_bracketed(string_view s){ stack<char> bs; string lbs = "({[", rbs = ")}]"; for (size_t i = 0; i < s.size(); i++) { if (lbs.find(s[i]) != string::npos) bs.push(s[i]); if (rbs.find(s[i]) != string::npos and !bs.empty()) bs.pop(); if (s[i] == ',' and bs.empty()) return i; } return s.size(); }
template <typename T, typename... Ts> void debug_function(string_view name, const T &a, Ts &&...rest) { int end = find_comma_not_bracketed(name); cerr << name.substr(0, end) << ":" << a; if constexpr (sizeof...(rest) == 0) { cerr << '\n'; } else { cerr << ' '; debug_function(name.substr(name.find_first_not_of(' ', end + 1)), forward<Ts>(rest)...); } }

// Functions
template <typename T> vector<T> make_vector(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector(ts...))>(a, make_vector(ts...)); }
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b and (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b and (a = b, true); }

// Structs
struct IoSetup { IoSetup(int x = 15) { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(x); cerr << fixed << setprecision(x); } } iosetup;

// Type aliases
using ull = unsigned long long;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

// Literals
constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr int dy[] = { 0, -1, 1, 0, -1, 1, -1, 1 };
constexpr int dx[] = { -1, 0, 0, 1, -1, -1, 1, 1 };
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = static_cast<int>(1e9) + 7;
constexpr char newl = '\n';

// clang-format on

// }}} Templates

namespace math {
  using namespace std;
  using ll = long long;
} // namespace math

#include <atcoder/modint>
#include <cstdint>
#include <cstdlib>
#include <vector>

namespace math {
  namespace inner {
    using u32 = uint32_t;
    using u64 = uint64_t;
    using i64 = int64_t;
    using u128 = __uint128_t;

    u64 gcd_impl(u64 n, u64 m) {
      constexpr u64 K = 5;
      for (int i = 0; i < 80; ++i) {
        u64 t = n - m;
        u64 s = n - m * K;
        bool q = t < m;
        bool p = t < m * K;
        n = q ? m : t;
        m = q ? t : m;
        if (m == 0) return n;
        n = p ? n : s;
      }
      return gcd_impl(m, n % m);
    }

    u64 gcd_pre(u64 n, u64 m) {
      for (int i = 0; i < 4; ++i) {
        u64 t = n - m;
        bool q = t < m;
        n = q ? m : t;
        m = q ? t : m;
        if (m == 0) return n;
      }
      return gcd_impl(n, m);
    }

    u64 gcd_fast(u64 n, u64 m) { return n > m ? gcd_pre(n, m) : gcd_pre(m, n); }

    struct modint64 {
      using u64 = uint64_t;

    public:
      static u64 mod;
      static u64 r, n2;
      static void set_mod(u64 m) {
        mod = m;
        n2 = -u128(m) % m;
        r = get_r();
        assert(r * mod == 1);
      }
      modint64(): a(0) {}
      modint64(const i64 &b): a(reduce((u128(b) + mod) * n2)) {}

      modint64 &operator+=(const modint64 &b) {
        if (i64(a += b.a - 2 * mod) < 0) a += 2 * mod;
        return *this;
      }

      modint64 &operator-=(const modint64 &b) {
        if (i64(a -= b.a) < 0) a += 2 * mod;
        return *this;
      }

      modint64 &operator*=(const modint64 &b) {
        a = reduce(u128(a) * b.a);
        return *this;
      }

      modint64 &operator/=(const modint64 &b) {
        *this *= b.inverse();
        return *this;
      }

      modint64 operator+(const modint64 &b) const { return modint64(*this) += b; }
      modint64 operator-(const modint64 &b) const { return modint64(*this) -= b; }
      modint64 operator*(const modint64 &b) const { return modint64(*this) *= b; }
      modint64 operator/(const modint64 &b) const { return modint64(*this) /= b; }

      modint64 pow(u128 n) const {
        modint64 ret(1), mul(*this);
        while (n > 0) {
          if (n & 1) ret *= mul;
          mul *= mul;
          n >>= 1;
        }
        return ret;
      }

      modint64 inverse() const { return pow(mod - 2); }

      u64 val() const {
        u64 ret = reduce(a);
        return ret >= mod ? ret - mod : ret;
      }

      static u64 get_mod() { return mod; }

    private:
      u64 a;

      static u64 get_r() {
        u64 ret = mod;
        for (int i = 0; i < 5; i++)
          ret *= 2 - mod * ret;
        return ret;
      }

      static u64 reduce(const u128 &b) { return (b + u128(u64(b) * u64(-r)) * mod) >> 64; }
    };
    typename modint64::u64 modint64::mod, modint64::r, modint64::n2;

    u64 rnd() {
      static u64 x = 10150724397891781847ull;
      x ^= x << 7;
      return x ^= x >> 9;
    }

    bool is_prime(const u64 n) {
      if (~n & 1) return n == 2;
      if (n < (1ll << 30)) return atcoder::internal::is_prime_constexpr(n);
      u64 d = n - 1;
      while (~d & 1)
        d >>= 1;
      if (modint64::get_mod() != n) modint64::set_mod(n);
      for (const u64 a: { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 }) {
        if (n <= a) break;
        modint64 t = d, y = modint64(a).pow(d);
        while (t.val() != n - 1 and y.val() != 1 and y.val() != n - 1) {
          y *= y;
          t *= 2;
        }
        if (y.val() != n - 1 and ~t.val() & 1) return false;
      }
      return true;
    }

    u64 pollard_rho(const u64 n) {
      if (~n & 1) return 2;
      if (is_prime(n)) return n;
      if (modint64::get_mod() != n) modint64::set_mod(n);
      modint64 R, one = 1;
      auto f = [&](modint64 x) {
        return x * x + R;
      };
      auto rng = [&]() {
        return rnd() % (n - 2) + 2;
      };
      for (;;) {
        modint64 x, y(rng()), ys, q = one;
        R = rng();
        u64 g = 1;
        constexpr int m = 128;
        for (int r = 1; g == 1; r <<= 1) {
          x = y;
          for (int i = 0; i < r; i++)
            y = f(y);
          for (int k = 0; g == 1 and k < r; k += m) {
            ys = y;
            for (int i = 0; i < m and i < r - k; i++)
              q *= x - (y = f(y));
            g = gcd_fast(q.val(), n);
          }
        }
        if (g == n) do
            g = gcd_fast((x - (ys = f(ys))).val(), n);
          while (g == 1);
        if (g != n) return g;
      }
      exit(1);
    }

    std::vector<u64> factorize(const u64 n) {
      if (n == 1) return {};
      if (is_prime(n)) return { n };
      auto d = pollard_rho(n);
      auto res = factorize(d);
      auto sub = factorize(n / d);
      std::copy(sub.begin(), sub.end(), std::back_inserter(res));
      return res;
    }

  }; // namespace inner
  using inner::is_prime;

  template <typename ll>
  std::vector<ll> fast_factorize(const ll n) {
    auto tmp = inner::factorize(n);
    std::vector<ll> res{ tmp.begin(), tmp.end() };
    std::sort(res.begin(), res.end());
    return res;
  }
} // namespace math
using namespace math;


int op(int a, int b) {
  return gcd(a, b);
}

int e() {
  return 0;
}


int main() {
  int n;
  cin >> n;

  vector<int> as(n);
  cin >> as;

  segtree<int, op, e> seg(as);

  int ans = -INF32;

  rep(i, n) {
    int l = e(), r = e();
    if (i > 0) l = seg.prod(0, i);
    if (i + 1 < n) r = seg.prod(i + 1, n);

    int g = gcd(l, r);
    chmax(ans, g);
  }

  cout << ans << endl;
}