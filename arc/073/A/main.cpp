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
constexpr int dy[] = { 0, -1, 1, 0, -1, 1, -1, 1 };
constexpr int dx[] = { -1, 0, 0, 1, -1, -1, 1, 1 };
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = static_cast<int>(1e9) + 7;
constexpr char newl = '\n';

// clang-format on

// }}} Templates


namespace data_structure {
  using namespace std;
}

#include <cassert>
#include <set>

namespace data_structure {
  // verify:ABC228_D
  template <typename T = long long>
  struct IntervalSet {
    set<pair<T, T>> s;

    IntervalSet() {
      s.emplace(-inf(), -inf());
      s.emplace(inf(), inf());
    }

    T inf() const { return numeric_limits<T>::max() / 2; }

    bool empty() const { return static_cast<int>(s.size()) == 2; }

    bool contains(T x) const {
      if (empty()) return false;
      auto [lower, upper] = *prev(s.lower_bound(pair(x + 1, x + 1)));
      return lower <= x and x <= upper;
    }

    // max({ (lower, upper) | lower <= x <= upper })
    pair<T, T> get(T x) const {
      assert(contains(x));
      return *prev(s.lower_bound(pair(x + 1, x + 1)));
    }

    bool insert(T x) {
      if (contains(x)) return false;
      auto nit = s.lower_bound(pair(x + 1, x + 1));
      auto it = prev(nit);
      auto [l, u] = *it;
      auto [nl, nu] = *nit;
      if (u == x - 1 and nl == x + 1) {
        s.erase(it);
        s.erase(nit);
        s.emplace(l, nu);
      } else if (u == x - 1 and nl != x + 1) {
        s.erase(it);
        s.emplace(l, x);
      } else if (u != x - 1 and nl == x + 1) {
        s.erase(nit);
        s.emplace(x, nu);
      } else if (u != x - 1 and nl != x + 1) {
        s.emplace(x, x);
      }
      return true;
    }

    // [x, y]
    bool insert(T x, T y) {
      if (x > y) swap(x, y);
      bool contains_x = contains(x);
      bool contains_y = contains(y);
      if (!contains_x and !contains_y) {
        s.emplace(x, y);
      } else if (!contains_x and contains_y) {
        auto yit = prev(s.lower_bound(pair(y + 1, y + 1)));
        auto [yl, yu] = *yit;
        s.erase(yit);
        s.emplace(x, yu);
      } else if (contains_x and !contains_y) {
        auto xit = prev(s.lower_bound(pair(x + 1, x + 1)));
        auto [xl, xu] = *xit;
        s.erase(xit);
        s.emplace(xl, y);
      } else {
        auto xit = prev(s.lower_bound(pair(x + 1, x + 1)));
        auto yit = prev(s.lower_bound(pair(y + 1, y + 1)));
        if (xit == yit) return false;
        auto [xl, xu] = *xit;
        auto [yl, yu] = *yit;
        s.erase(xit);
        s.erase(yit);
        s.emplace(xl, yu);
      }
      return true;
    }

    bool insert(pair<T, T> p) { return insert(p.first, p.second); }

    // { (l, u) | l <= x <= u } => { (l, x - 1), (x + 1, u) | l <= x <= u }
    bool erase(T x) {
      assert(x != -inf() and x != inf());
      if (!contains(x)) return false;
      auto it = prev(s.lower_bound(pair(x + 1, x + 1)));
      auto [l, u] = *it;
      s.erase(it);
      if (x != l) s.emplace(l, x - 1);
      if (x != u) s.emplace(x + 1, u);
      return true;
    }

    // { (l, u) | l <= x <= u } => { (l, x), (x, u) | l <= x <= u }
    bool cut(T x) {
      assert(x != -inf() and x != inf());
      if (!contains(x)) return false;
      auto it = prev(s.lower_bound(pair(x + 1, x + 1)));
      auto [l, u] = *it;
      s.erase(it);
      s.emplace(l, x);
      s.emplace(x, u);
      return true;
    }
  };
} // namespace data_structure
using namespace data_structure;


int main() {
  int n, T;
  cin >> n >> T;

  vector<ll> ts(n);
  cin >> ts;

  IntervalSet<ll> is;

  rep(i, n) {
    int t = ts[i];
    is.insert(t, t + T);
  }

  ll ans = 0;
  // [l,r]
  for (auto [l, r]: is.s) {
    if (l == -is.inf() or l == is.inf()) continue;
    int dist = r - l;
    ans += dist;
    // debug(l, r, dist, ans);
  }

  cout << ans << endl;
}