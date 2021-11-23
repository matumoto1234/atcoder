#include <bits/stdc++.h>
using namespace std;

// {{{ templates

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
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { rep (i, len(v)) cout << v[i] << (i == len(v) - 1 ? "" : " "); return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<vector<T>> &v) { for (const auto &vec: v) { cout << vec << '\n'; } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { rep (i, len(v)) cout << v[i] << (i == len(v) - 1 ? "" : " "); return os; }
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

// }}} templates



namespace tools {
  using namespace std;
}


namespace tools {
  // verify:ABC036_C
  template <typename T>
  struct Compress {
    vector<T> xs;
    Compress() {}
    Compress(int N): xs(N, 0) {}
    Compress(const vector<T> &vs): xs(vs) {}

    void set(int i, T x) { xs[i] = x; }

    void set(const vector<T> &vs) {
      for (int i = 0; i < min<int>(xs.size(), vs.size()); i++) {
        xs[i] = vs[i];
      }
    }

    void add(T x) { xs.emplace_back(x); }

    void add(const vector<T> &vs) {
      for (const T &x: vs) {
        xs.emplace_back(x);
      }
    }

    Compress<T> build() {
      sort(xs.begin(), xs.end());
      xs.erase(unique(xs.begin(), xs.end()), xs.end());
      return *this;
    }

    vector<T> get(const vector<T> &vs) const {
      vector<T> res = vs;
      for (T &x: res) {
        x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
      }
      return res;
    }

    int get(T k) const { return lower_bound(xs.begin(), xs.end(), k) - xs.begin(); }

    const T &operator[](int k) const { return xs[k]; }
  };
} // namespace tools
using namespace tools;



namespace data_structure {
  using namespace std;
}


namespace data_structure {
  // verify:ARC033_C
  template <typename T>
  class FenwickTree {
  private:
    int n;
    vector<T> dat;

    // [1,r]
    T sum(int r) {
      T res = 0;
      for (int k = r; k > 0; k -= (k & -k)) {
        res += dat[k];
      }
      return res;
    }

  public:
    FenwickTree(int n_): n(n_ + 2), dat(n_ + 2, 0) {}

    // i:0-indexed
    void add(int i, T x) {
      for (int k = ++i; k < n; k += (k & -k)) {
        dat[k] += x;
      }
    }

    T get(int k) { return dat[++k]; }

    // [l,r)
    T sum(int l, int r) { return sum(r) - sum(l); }

    // min({x | sum(x) >= w})
    int lower_bound(T w) {
      if (w <= 0) return 0;
      int x = 0, twopow = 1;
      while (twopow < n) {
        twopow <<= 1;
      }
      for (int sz = twopow; sz > 0; sz >>= 1) {
        if (x + sz < n and dat[x + sz] < w) {
          w -= dat[x + sz];
          x += sz;
        }
      }
      return x;
    }

    // min({x | sum(x) > w})
    int upper_bound(T w) { return lower_bound(w + 1); }
  };
} // namespace data_structure
using namespace data_structure;

int main() {
  int n;
  cin >> n;

  Compress<int> comp;

  vector<int> ls(n), rs(n);

  rep(i, n) {
    int &l = ls[i], &r = rs[i];
    cin >> l >> r;

    comp.add(l);
    comp.add(r);
  }

  comp.build();

  FenwickTree<int> ft(n);

  int mn = INF32;
  int mx = -INF32;
  int cnt = 0;

  rep(i, n) {
    int l = ls[i], r = rs[i];

    chmin(mn, l);
    chmin(mn, r);
    chmax(mx, l);
    chmax(mx, r);

    ft.add(comp.get(l), 1);
    ft.add(comp.get(r), 1);
    cnt += 2;

    int idx1 = ft.lower_bound(cnt / 2 - 1);
    int idx2 = ft.lower_bound(cnt / 2);

    int x = (comp[idx1] + comp[idx2]) / 2;

    debug(cnt / 2 - 1, cnt / 2);
    debug(idx1, idx2, comp[idx1], comp[idx2], x, mn, mx);
    int ans = INF32;
    if (x < mn) chmin(ans, mn - x);
    if (x > mx) chmin(ans, x - mx);

    if (ans == INF32) ans = 0;

    cout << ans << newl;
  }
}
