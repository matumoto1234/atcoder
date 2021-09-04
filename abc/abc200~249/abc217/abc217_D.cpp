#include <bits/stdc++.h>
using namespace std;

// {{{

// clang-format off
#define len(x) ((int)(x).size())
#define _over_load(_1,_2,_3,_4,NAME,...) NAME
#define range(...) _over_load(__VA_ARGS__, range4, range3, range2)(__VA_ARGS__)
#define range2(i, r) for ( int i = 0; i < (int)(r); (i) += 1)
#define range3(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1)
#define range4(i, l, r, inc) for ( int i = (int)(l); i < (int)(r); (i) += (inc))
#define rrange(...) _over_load(__VA_ARGS__, rrange4, rrange3, rrange2)(__VA_ARGS__)
#define rrange2(i, r) for ( int i = (int)(r) - 1; i >= 0; (i) -= 1)
#define rrange3(i, l, r) for ( int i = (int)(r) - 1; i >= (int)(l); (i) -= 1)
#define rrange4(i, l, r, inc) for ( int i = (int)(r) - 1; i >= (int)(l); (i) -= inc)
#define whole(f, x, ...) ([&](decltype((x)) container) { return (f)( begin(container), end(container), ## __VA_ARGS__); })(x)
#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__); })(x)
#define debug(...) debug_function(#__VA_ARGS__, __VA_ARGS__)
template <typename T, typename... T2> void debug_function(string_view name, const T &a, T2 &&...rest) {
  stack<char> bs;
  string_view lbs = "({[<", rbs = ")}]>";
  int end = name.size();
  for ( int i = 0; i < (int)name.size(); i++ ) {
    if ( lbs.find(name[i]) != string::npos ) bs.push(name[i]);
    if ( rbs.find(name[i]) != string::npos && !bs.empty() ) bs.pop();
    if ( name[i] == ',' && bs.empty() ) {
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
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << p.first << ' ' << p.second; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { for ( pair<T1, T2> x : v ) { os << "(" << x.first <<", " << x.second << ")" << (v.rbegin()->first == x.first ? "" : ", "); } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> v) { if(!v.empty()) { os << v.front(); v.pop(); } while (!v.empty()) { os << " " << v.front(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> v) { if(!v.empty()) { os << v.top(); v.pop(); } while (!v.empty()) { os << " " << v.top(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
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
constexpr int mod1000000007 = (int)1e9 + 7;
constexpr char newl = '\n';
// clang-format on

// }}}

template <typename T = long long>
struct pairset {
  set<pair<T, T>> s;

  pairset() {}

  T inf() { return numeric_limits<T>::max() / 2; }

  bool empty() const { return s.empty(); }

  bool contains(T x) const {
    if ( s.empty() ) return false;
    auto [lower, upper] = *prev(s.lower_bound(make_pair(x + 1, x + 1)));
    return lower <= x && x <= upper;
  }

  // max({ (lower, upper) | lower <= x <= upper })
  pair<T, T> get(T x) {
    if ( !contains(x) ) return make_pair<T, T>(inf(), inf());
    return *prev(s.lower_bound(make_pair(x + 1, x + 1)));
  }

  bool insert(T x) {
    if ( contains(x) ) return false;
    auto nit = s.lower_bound(make_pair(x + 1, x + 1));
    auto it = prev(nit);
    auto [l, u] = *it;
    auto [nl, nu] = *nit;
    if ( u == x - 1 && nl == x + 1 ) {
      s.erase(it);
      s.erase(nit);
      s.emplace(l, nu);
    } else if ( u == x - 1 && nl != x + 1 ) {
      s.erase(it);
      s.emplace(l, x);
    } else if ( u != x - 1 && nl == x + 1 ) {
      s.erase(nit);
      s.emplace(x, nu);
    } else if ( u != x - 1 && nl != x + 1 ) {
      s.emplace(x, x);
    }
    return true;
  }

  bool insert(T x, T y) {
    if ( x > y ) swap(x, y);
    bool xflg = contains(x);
    bool yflg = contains(y);
    if ( xflg && yflg ) {
      auto xit = prev(s.lower_bound(make_pair(x + 1, x + 1)));
      auto yit = prev(s.lower_bound(make_pair(y + 1, y + 1)));
      if ( xit == yit ) return false;
      auto [xl, xu] = *xit;
      auto [yl, yu] = *yit;
      s.erase(xit);
      s.erase(yit);
      s.emplace(xl, yu);
    } else if ( xflg && !yflg ) {
      auto xit = prev(s.lower_bound(make_pair(x + 1, x + 1)));
      auto [xl, xu] = *xit;
      s.erase(xit);
      s.emplace(xl, y);
    } else if ( !xflg && yflg ) {
      auto yit = prev(s.lower_bound(make_pair(y + 1, y + 1)));
      auto [yl, yu] = *yit;
      s.erase(yit);
      s.emplace(x, yu);
    } else if ( !xflg && !yflg ) {
      s.emplace(x, y);
    }
    return true;
  }

  bool insert(pair<T, T> p) { return insert(p.first, p.second); }

  // { (l, u) | l <= x <= u } => { (l, x - 1), (x + 1, u) | l <= x <= u }
  bool erase(T x) {
    if ( !contains(x) ) return false;
    auto it = prev(s.lower_bound(make_pair(x + 1, x + 1)));
    auto [l, u] = *it;
    s.erase(it);
    if ( x != l ) s.emplace(l, x - 1);
    if ( x != u ) s.emplace(x + 1, u);
    return true;
  }

  // { (l, u) | l <= x <= u } => { (l, x), (x, u) | l <= x <= u }
  bool cut(T x) {
    if ( !contains(x) ) return false;
    auto it = prev(s.lower_bound(make_pair(x + 1, x + 1)));
    auto [l, u] = *it;
    s.erase(it);
    s.emplace(l, x);
    s.emplace(x, u);
    return true;
  }
};

int main() {
  int l, q;
  cin >> l >> q;

  pairset<int> s;

  s.insert(0, l);

  range(i, q) {
    int c, x;
    cin >> c >> x;
    if ( c == 1 ) {
      s.cut(x);
    } else {
      auto [lower, upper] = s.get(x);
      cout << upper - lower << newl;
    }
  }
}