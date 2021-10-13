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
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { range(i, len(v)) { cout << v[i] << (i == len(v) ? "" : " "); } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { range(i, len(v)) { cout << v[i] << (i == len(v) ? "" : " "); } return os; }
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

template <typename T, typename CostType>
class re_rooting_dp {
private:
  vector<vector<pair<int, CostType>>> g;
  vector<vector<int>> seen_idx;
  vector<vector<T>> ch_tree;
  vector<int> pars, deps, sizs, order;
  vector<T> results;

  T identity;
  function<T(T, T)> merge;
  function<T(T, int, re_rooting_dp<T, CostType> &)> add_node;

  void dfs(int v, int par, int &idx) {
    order[idx++] = v;
    pars[v] = par;
    deps[v] = par == -1 ? 0 : deps[par] + 1;
    for ( auto [to, ignore] : g[v] ) {
      if ( to == par ) continue;
      dfs(to, v, idx);
    }
    if ( par != -1 ) sizs[par] = ++sizs[v];
  }

  void post_order() {
    for ( int i = order.size() - 1; i >= 1; i-- ) {
      int v = order[i];
      int par = pars[v];
      int par_idx = -1;
      T accum = identity;
      for ( int j = 0; j < (int)g[v].size(); j++ ) {
        int to = g[v][j].first;
        if ( to == par ) {
          par_idx = j;
          continue;
        }
        accum = merge(accum, ch_tree[v][j]);
      }
      if ( par_idx != -1 ) {
        ch_tree[par][seen_idx[v][par_idx]] = add_node(accum, v, *this);
      }
    }
  }

  void pre_order() {
    for ( auto v : order ) {
      int adj_cnt = g[v].size();
      vector<T> accum_back(adj_cnt);
      accum_back.back() = identity;
      for ( int j = adj_cnt - 1; j >= 1; j-- ) {
        accum_back[j - 1] = merge(accum_back[j], ch_tree[v][j]);
      }
      T accum_front = identity;
      for ( int j = 0; j < adj_cnt; j++ ) {
        T res = add_node(merge(accum_front, accum_back[j]), v, *this);
        ch_tree[g[v][j].first][seen_idx[v][j]] = res;
        accum_front = merge(accum_front, ch_tree[v][j]);
      }
      results[v] = add_node(accum_front, v, *this);
    }
  }

public:
  re_rooting_dp(int n, T id, function<T(T, T)> f1,
      function<T(T, int, re_rooting_dp<T, CostType> &)> f2)
      : g(n),
        seen_idx(n) {
    identity = id;
    merge = f1;
    add_node = f2;
  }

  void add_edge(int from, int to, CostType cost) {
    g[from].emplace_back(to, cost);
    seen_idx[to].emplace_back(g[from].size() - 1);
  }

  void build(int root) {
    pars.assign(g.size(), -1);
    deps.assign(g.size(), -1);
    sizs.assign(g.size(), 0);
    order.assign(g.size(), -1);
    results.assign(g.size(), identity);
    ch_tree.resize(g.size());
    for ( int i = 0; i < (int)g.size(); i++ ) {
      ch_tree[i].assign(g[i].size(), identity);
    }
    int idx = 0;
    dfs(root, -1, idx);
    post_order();
    pre_order();
  }

  int size(int v) { return sizs[v]; }
  int depth(int v) { return deps[v]; }
  int parent(int v) { return pars[v]; }
  T query(int v) { return results[v]; }
  T operator[](int v) { return results[v]; }
};

Pll e() {
  return make_pair<ll, ll>(0, 0);
}

Pll op(Pll a, Pll b) {
  return make_pair<ll, ll>(a.first + b.first, a.second + b.second);
}

Pll add_node(Pll res, int v, re_rooting_dp<Pll, ll> &tree) {
  auto [child_result, mydistance] = res;
  return make_pair<ll, ll>(child_result + mydistance, mydistance + 1);
}

int main() {
  int n;
  cin >> n;

  re_rooting_dp<Pll, ll> tree(n, e(), op, add_node);
  range(i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    tree.add_edge(u, v, 1);
    tree.add_edge(v, u, 1);
  }

  tree.build(0);

  range(i, n) {
    cout << tree[i].first << newl;
  }
}