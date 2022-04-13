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

template <typename T, T (*op)(T, T)>
struct sparse_table {
  vector<vector<T>> st;
  vector<int> lookup;

  sparse_table(const vector<T> &v) {
    int b = 0;
    while ((1 << b) <= (int)v.size())
      ++b;
    st.assign(b, vector<T>(1 << b));
    for (int i = 0; i < (int)v.size(); i++) {
      st[0][i] = v[i];
    }
    for (int i = 1; i < b; i++) {
      for (int j = 0; j + (1 << i) <= (1 << b); j++) {
        st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    lookup.resize(v.size() + 1);
    for (int i = 2; i < (int)lookup.size(); i++) {
      lookup[i] = lookup[i >> 1] + 1;
    }
  }

  inline T query(int l, int r) {
    int b = lookup[r - l];
    return op(st[b][l], st[b][r - (1 << b)]);
  }
};

int min_op(int a, int b) {
  return min(a, b);
}

int max_op(int a, int b) {
  return max(a, b);
}

int solve(vector<pii> ps) {
  whole(sort, ps);
  auto [a, b] = ps[0];
  auto [c, d] = ps[1];
  if (b < c)
    return 0;

  if (d <= b) {
    return d - c + 1;
  }

  return b - c + 1;
}

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  vector<int> as(n);
  cin >> as;

  sparse_table<int, min_op> min_table(as);
  sparse_table<int, max_op> max_table(as);

  ll ans = 0;

  rep(l, n) {
    int min_idx = [&]() {
      ll valid = l + 1;
      ll invalid = n;
      auto is_valid = [&](ll m) {
        return min_table.query(l, m) > y;
      };
      while (abs(valid - invalid) > 1) {
        ll mid = (valid + invalid) / 2;
        if (is_valid(mid))
          valid = mid;
        else
          invalid = mid;
      }
      return valid;
    }();

    int max_idx = [&]() {
      ll valid = l + 1;
      ll invalid = n;
      auto is_valid = [&](ll m) {
        return max_table.query(l, m) < x;
      };
      while (abs(valid - invalid) > 1) {
        ll mid = (valid + invalid) / 2;
        if (is_valid(mid))
          valid = mid;
        else
          invalid = mid;
      }
      return valid;
    }();

    if (max_table.query(l, max_idx) < x) {
      max_idx++;
    }
    if (min_table.query(l, min_idx) > y) {
      min_idx++;
    }

    int idx = max(max_idx, min_idx);
    int cnt = n - idx + 1;
    int q1 = max_table.query(l, idx);
    int q2 = min_table.query(l, idx);
    // debug(l, max_idx, min_idx, idx, cnt, q1, q2);
    if (q1 != x or q2 != y) {
      continue;
    }
    // debug("hey");
    ans += cnt;
  }

  cout << ans << newl;
}
