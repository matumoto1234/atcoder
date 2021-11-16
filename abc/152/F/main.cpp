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

class tree {
private:
  struct sparse_table {
    vector<vector<pair<int, int>>> st;
    vector<int> lookup;

    sparse_table() {}

    void build(const vector<pair<int, int>> &v) {
      int b = 0;
      while ( (1 << b) <= (int)v.size() )
        ++b;
      st.assign(b, vector<pair<int, int>>(1 << b));
      for ( int i = 0; i < (int)v.size(); i++ ) {
        st[0][i] = v[i];
      }
      for ( int i = 1; i < b; i++ ) {
        for ( int j = 0; j + (1 << i) <= (1 << b); j++ ) {
          st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
      }
      lookup.resize(v.size() + 1);
      for ( int i = 2; i < (int)lookup.size(); i++ ) {
        lookup[i] = lookup[i >> 1] + 1;
      }
    }

    inline pair<int, int> query(int l, int r) {
      int b = lookup[r - l];
      return min(st[b][l], st[b][r - (1 << b)]);
    }
  };

  sparse_table min_dep_idx;
  const int LOG;
  vector<int> in, out, dep, par, edge_table;
  vector<vector<int>> G, doubling_par;

  void dfs(int v, int &time, int depth) {
    in[v] = time;
    dep[time] = depth;
    edge_table[time++] = v;
    for ( auto to : G[v] ) {
      if ( in[to] != -1 ) continue;
      par[to] = v;
      dfs(to, time, depth + 1);
    }
    out[v] = time;
    dep[time] = depth - 1;
    edge_table[time++] = -v;
  }

  // min({ x | 2^x > n })
  int log_two(int n) {
    int x = 1;
    while ( (1 << x) <= n ) {
      x++;
    }
    return x;
  }

public:
  tree(int n) : G(n), LOG(log_two(n)) {}

  void add_edge(int from, int to) { G[from].emplace_back(to); }

  void build(int s) {
    int n = G.size();
    in.assign(n, -1);
    out.assign(n, -1);
    par.assign(n, 0);
    dep.assign(2 * n, 0);
    edge_table.assign(2 * n, -1);

    int time = 0;
    dfs(s, time, 0);
    dep.back() = s;

    // build doubling parent
    doubling_par.assign(LOG, vector<int>(n, -1));
    for ( int i = 0; i < n; i++ ) {
      doubling_par[0][i] = par[i];
    }
    for ( int k = 0; k < LOG - 1; k++ ) {
      for ( int i = 0; i < n; i++ ) {
        if ( doubling_par[k][i] == -1 ) {
          doubling_par[k + 1][i] = -1;
          continue;
        }
        doubling_par[k + 1][i] = doubling_par[k][doubling_par[k][i]];
      }
    }

    // build sparse table
    vector<pair<int, int>> dep_idx(dep.size());
    for ( int i = 0; i < (int)dep.size(); i++ ) {
      auto &[depth, idx] = dep_idx[i];
      depth = dep[i];
      idx = i;
    }
    min_dep_idx.build(dep_idx);
  }

  // edge_table:[first, second)
  pair<int, int> subtree(int v) { return make_pair(in[v], out[v]); }

  bool in_subtree(int subroot, int v) {
    return in[subroot] < in[v] and out[v] < out[subroot];
  }

  template <typename F>
  auto path_query(int v, F f){
    return f()
  }

  // lowest common ancestor : O(1)
  int lca(int u, int v) {
    int idx =
        min_dep_idx.query(min(in[u], in[v]), max(in[u], in[v]) + 1).second;
    int res = edge_table[idx];
    if ( res < 0 ) res = par[-res];
    return res;
  }

  // level ancestor : O(log N)
  int la(int v, int depth) {
    int anc = v;
    for ( int i = 0; i < LOG; i++ ) {
      if ( depth >> i & 1 ) anc = doubling_par[i][anc];
    }
    return anc;
  }

  // from v to root move k step
  int up(int v, int k) { return la(v, depth(v) - k); }

  int depth(int v) { return dep[in[v]]; }

  int distance(int u, int v) {
    return depth(u) + depth(v) - 2 * depth(lca(u, v));
  }

  // from u to v move k step
  int next(int u, int v, int k = 1) {
    if ( k <= distance(u, lca(u, v)) ) return up(u, k);
    return up(v, distance(v, lca(u, v)) - k);
  }
};


int main() {
  int n;
  cin>>n;
  tree t(n);
  range(i,n-1){
    int a,b;
    cin>>a>>b;
    a--,b--;
    t.add_edge(a,b);
    t.add_edge(b,a);
  }

  t.build(0);



  int m;
  cin>>m;
  
}