#include <bits/stdc++.h>
using namespace std;

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
constexpr int dy[] = { 0, 1, -1, 0, -1, 1, -1, 1 };
constexpr int dx[] = { 1, 0, 0, -1, -1, -1, 1, 1 };
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = static_cast<int>(1e9) + 7;
constexpr char newl = '\n';

// clang-format on

// }}} Templates

namespace tools {
  template <int m>
  class ModInt {
    unsigned int v;

    static constexpr unsigned int umod() { return m; }

    void static_assertions() const { static_assert(1 <= m); }

    long long extgcd(long long a, long long b, long long &x, long long &y) {
      if (b == 0) {
        x = 1;
        y = 0;
        return a;
      }
      long long d = extgcd(b, a % b, y, x);
      y -= a / b * x;
      return d;
    }

    // pair(g, x), g = gcd(v, umod()), vx = g (mod umod())
    pair<long long, long long> gcd_inv() const {
      long long x, y;
      long long d = extgcd(v, umod(), x, y);
      return pair(d, x);
    }

  public:
    bool has_invalid_value = false;
    ModInt(): v(0) { static_assertions(); }
    ModInt(long long x) {
      static_assertions();
      if (x == -1) {
        has_invalid_value = true;
      }
      v = ((x % umod()) + umod()) % umod();
    }

    unsigned int val() const { return v; }

    ModInt &operator++() {
      v++;
      if (v == umod())
        v = 0;
      return *this;
    }

    ModInt &operator--() {
      if (v == 0)
        v = umod();
      v--;
      return *this;
    }

    ModInt operator++([[maybe_unused]] int unused) {
      ModInt old = *this;
      ++*this;
      return old;
    }

    ModInt operator--([[maybe_unused]] int unused) {
      ModInt old = *this;
      --*this;
      return old;
    }

    ModInt &operator+=(const ModInt &rhs) {
      v += rhs.v;
      if (v >= umod())
        v -= umod();
      return *this;
    }

    ModInt &operator-=(const ModInt &rhs) {
      v -= rhs.v;
      if (v >= umod())
        v += umod();
      return *this;
    }

    ModInt &operator*=(const ModInt &rhs) {
      unsigned long long z = v;
      z *= rhs.v;
      v = z % umod();
      return *this;
    }

    ModInt operator/=(const ModInt &rhs) { return *this = *this * rhs.inv(); }

    ModInt operator+() const { return *this; }
    ModInt operator-() const { return ModInt() - *this; }

    ModInt pow(long long n) const {
      assert(0 <= n);
      ModInt x = *this, res = 1;
      while (n) {
        if (n & 1)
          res *= x;
        x *= x;
        n >>= 1;
      }
      return res;
    }

    ModInt inv() const {
      const auto &[g, x] = gcd_inv();
      assert(g == 1);
      return x;
    }

    friend ModInt operator+(const ModInt &lhs, const ModInt &rhs) { return ModInt(lhs) += rhs; }

    friend ModInt operator-(const ModInt &lhs, const ModInt &rhs) { return ModInt(lhs) -= rhs; }

    friend ModInt operator*(const ModInt &lhs, const ModInt &rhs) { return ModInt(lhs) *= rhs; }

    friend ModInt operator/(const ModInt &lhs, const ModInt &rhs) { return ModInt(lhs) /= rhs; }

    friend bool operator==(const ModInt &lhs, const ModInt &rhs) { return lhs.v == rhs.v; }

    friend bool operator!=(const ModInt &lhs, const ModInt &rhs) { return lhs.v != rhs.v; }

    friend istream &operator>>(istream &is, ModInt &rhs) {
      long long temp;
      cin >> temp;
      rhs = ModInt(temp);
      return is;
    }

    friend ostream &operator<<(ostream &os, const ModInt &rhs) {
      os << rhs.val();
      return os;
    }
  };
} // namespace tools
using namespace tools;


using mint = ModInt<mod998244353>;


int n, m, k, s, t, x;
vector<vector<int>> G;
constexpr int MAXN = 3000;
constexpr int MAXK = 3000;
constexpr int COUNTX = 2;
mint dp[MAXN][MAXK][COUNTX];
mint dfs(int v, int depth, int count_x) {
  if (depth == 0) {
    if (v == s and count_x == 0)
      return 1;

    return 0;
  }

  mint &res = dp[v][depth][count_x];
  if (not res.has_invalid_value) {
    return res;
  }
  res = 0;

  int next_count = count_x;
  if (v == x) {
    next_count++;
    next_count %= 2;
  }

  for (auto to: G[v]) {
    res += dfs(to, depth - 1, next_count);
  }

  return res;
}


int main() {
  cin >> n >> m >> k >> s >> t >> x;
  s--, t--, x--;

  G.resize(n);

  rep(i, m) {
    int u, v;
    cin >> u >> v;

    u--, v--;

    G[u].push_back(v);
    G[v].push_back(u);
  }

  rep(i, MAXN) {
    rep(j, MAXK) {
      rep(k, COUNTX) { dp[i][j][k] = -1; }
    }
  }

  mint ans = dfs(t, k, 0);

  cout << ans << endl;
}
