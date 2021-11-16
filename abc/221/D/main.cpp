#include <bits/stdc++.h>
using namespace std;

// {{{

// clang-format off
#define len(x) (static_cast<int>((x).size()))
#define _over_load(_1,_2,_3,_4,NAME,...) NAME
#define range(...) _over_load(__VA_ARGS__, range4, range3, range2)(__VA_ARGS__)
#define range2(i, r) for ( int i = 0; i < static_cast<int>(r); (i) += 1)
#define range3(i, l, r) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i) += 1)
#define range4(i, l, r, step) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i) += (step))
#define rrange(...) _over_load(__VA_ARGS__, rrange4, rrange3, rrange2)(__VA_ARGS__)
#define rrange2(i, r) for ( int i = static_cast<int>(r) - 1; i >= 0; (i) -= 1)
#define rrange3(i, l, r) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= 1)
#define rrange4(i, l, r, step) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= (step))
#define whole(f, x, ...) ([&](decltype((x)) container) { return (f)( begin(container), end(container), ## __VA_ARGS__); })(x)
#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__); })(x)
#define debug(...) debug_function(#__VA_ARGS__, __VA_ARGS__)
template <typename T, typename... T2> void debug_function(string_view name, const T &a, T2 &&...rest) {
  stack<char> bs;
  string_view lbs = "({[<", rbs = ")}]>";
  int end = name.size();
  for ( int i = 0; i < len(name); i++ ) {
    if ( lbs.find(name[i]) != string::npos ) bs.push(name[i]);
    if ( rbs.find(name[i]) != string::npos and !bs.empty() ) bs.pop();
    if ( name[i] == ',' and bs.empty() ) {
      end = i;
      break;
    }
  }
  cerr << name.substr(0, end) << ":" << a;
  if constexpr ( sizeof...(rest) == 0 ) {
    cerr << '\n';
  } else {
    cerr << ' ';
    debug_function(name.substr(name.find_first_not_of(' ', end + 1)), forward<T2>(rest)...);
  }
}
template <typename T> vector<T> make_vector(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector(ts...))>(a, make_vector(ts...)); }
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b and (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b and (a = b, true); }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << p.first << ' ' << p.second; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { for ( pair<T1, T2> x : v ) { os << "(" << x.first <<", " << x.second << ")" << (v.rbegin()->first == x.first ? "" : ", "); } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> v) { if(!v.empty()) { os << v.front(); v.pop(); } while (!v.empty()) { os << " " << v.front(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> v) { if(!v.empty()) { os << v.top(); v.pop(); } while (!v.empty()) { os << " " << v.top(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { range(i, len(v)) { cout << v[i] << (i == len(v) - 1 ? "" : " "); } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { range(i, len(v)) { cout << v[i] << (i == len(v) - 1 ? "" : " "); } return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in : v) is >> in; return is; }
struct IoSetup { IoSetup(int x = 15) { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(x); cerr << fixed << setprecision(x); } } iosetup;
using ull = unsigned long long;
using ll = long long;
using Pll = pair<ll, ll>;
using P = pair<int, int>;
constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr int dy[] = { 0, -1, 1, 0, -1, 1, -1, 1 };
constexpr int dx[] = { -1, 0, 0, 1, -1, -1, 1, 1 };
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = static_cast<int>(1e9) + 7;
constexpr char newl = '\n';
// clang-format on

// }}}

template <typename T>
struct dynamic_imos {
  vector<T> xs, imos;
  vector<tuple<T, T, T>> sections;

  dynamic_imos() {}

  // [l, r)
  void add(T l, T r, T v) {
    sections.emplace_back(l, r, v);
    xs.emplace_back(l);
    xs.emplace_back(r);
  }

  void build() {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    imos.assign(xs.size(), 0);

    for ( auto [l, r, v] : sections ) {
      l = lower_bound(xs.begin(), xs.end(), l) - xs.begin();
      r = lower_bound(xs.begin(), xs.end(), r) - xs.begin();
      imos[l] += v;
      imos[r] -= v;
    }

    for ( int i = 1; i < (int)imos.size(); i++ ) {
      imos[i] += imos[i - 1];
    }
  }

  // vector<[l,r), value>
  vector<pair<pair<T, T>, T>> section_values() {
    vector<pair<pair<T, T>, T>> res(xs.size() - 1);
    for ( int i = 0; i < (int)xs.size() - 1; i++ ) {
      T l = xs[i];
      T r = xs[i + 1];
      T v = imos[i];
      res[i] = make_pair(make_pair(l, r), v);
    }
    return res;
  }
};

int main() {
  int n;
  cin >> n;

  dynamic_imos<int> dimos;

  vector<P> ab(n);
  for ( auto &[a, b] : ab ) {
    cin >> a >> b;
    dimos.add(a, a + b, 1);
  }

  dimos.build();

  auto secs = dimos.section_values();

  vector<int> ans(n + 1, 0);
  for ( auto [section, value] : secs ) {
    auto [l, r] = section;
    ans[value] += r - l;
  }

  range(i, 1, n) cout << ans[i] << ' ';
  cout << ans[n] << endl;
}