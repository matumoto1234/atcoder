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



int to_sum_of_minute(int hour, int minute) {
  return hour * 60 + minute;
}

pii to_hour(int sum_of_minute) {
  return pii(sum_of_minute / 60, sum_of_minute % 60);
}

namespace data_structure {
  using namespace std;
}

#include <tuple>
#include <vector>

namespace data_structure {
  template <typename T>
  struct DynamicImos {
    vector<T> xs, imos;
    vector<tuple<T, T, T>> intervals;

    DynamicImos() {}

    // [l, r)
    void add(T l, T r, T v) {
      intervals.emplace_back(l, r, v);
      xs.emplace_back(l);
      xs.emplace_back(r);
    }

    void build() {
      sort(xs.begin(), xs.end());
      xs.erase(unique(xs.begin(), xs.end()), xs.end());
      imos.assign(xs.size(), 0);

      for (auto [l, r, v]: intervals) {
        l = lower_bound(xs.begin(), xs.end(), l) - xs.begin();
        r = lower_bound(xs.begin(), xs.end(), r) - xs.begin();
        imos[l] += v;
        imos[r] -= v;
      }

      for (int i = 1; i < static_cast<int>(imos.size()); i++) {
        imos[i] += imos[i - 1];
      }
    }

    // vector<[l,r), value>
    vector<pair<pair<T, T>, T>> interval_values() {
      vector<pair<pair<T, T>, T>> res(xs.size() - 1);
      for (int i = 0; i < static_cast<int>(xs.size()) - 1; i++) {
        T l = xs[i];
        T r = xs[i + 1];
        T v = imos[i];
        res[i] = pair(pair(l, r), v);
      }
      return res;
    }

    // vector<[l,r)>
    // e.g. <[0,3),3>, <[1,2),1>, <[5,6), 1> => <[0,3)>, <[5,6)>
    vector<pair<T, T>> continuous_intervals() {
      T last = xs[0];
      vector<pair<T, T>> res;
      auto ivs = interval_values();
      if (static_cast<int>(ivs.size()) == 1) {
        res.emplace_back(ivs[0].first);
        return res;
      }
      for (int i = 0; i < static_cast<int>(ivs.size()) - 1; i++) {
        auto [interval, value] = ivs[i];
        if (value == 0) {
          auto [l, r] = interval;
          res.emplace_back(last, l);
          last = r;
        }
      }
      if (res.back().second != last) res.emplace_back(last, ivs.back().first.second);
      return res;
    }
  };
} // namespace data_structure
using namespace data_structure;


int main() {
  int n;
  cin >> n;

  DynamicImos<int> imos;

  rep(i, n) {
    int s, e;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '-');
    cin >> e;

    int l = to_sum_of_minute(s / 100, s % 100);
    int r = to_sum_of_minute(e / 100, e % 100);

    l -= l % 5;
    r += (r % 5 == 0 ? 0 : 5 - r % 5);

    r++;

    imos.add(l, r, 1);
  }

  imos.build();

  auto continuous_intervals = imos.continuous_intervals();
  for (auto [l, r]: continuous_intervals) {
    r--;
    pii s = to_hour(l);
    pii e = to_hour(r);

    printf("%02d%02d-%02d%02d\n", s.first, s.second, e.first, e.second);
  }
}