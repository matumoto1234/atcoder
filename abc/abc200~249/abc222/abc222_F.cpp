#include <bits/stdc++.h>
using namespace std;

// {{{

// clang-format off
#define _over_load(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) _over_load(__VA_ARGS__, rep4, rep3, rep2)(__VA_ARGS__)
#define rep2(i, r) for ( int i = 0; i < static_cast<int>(r); (i) += 1)
#define rep3(i, l, r) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i) += 1)
#define rep4(i, l, r, stride) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i) += (stride))
#define rrep(...) _over_load(__VA_ARGS__, rrep4, rrep3, rrep2)(__VA_ARGS__)
#define rrep2(i, r) for ( int i = static_cast<int>(r) - 1; i >= 0; (i) -= 1)
#define rrep3(i, l, r) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= 1)
#define rrep4(i, l, r, stride) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= (stride))
#define len(x) (static_cast<int>((x).size()))
#define contains(container, x) (find(begin(container), end(container), x) != end(container))
#define whole(f, x, ...) ([&](decltype((x)) container) { return (f)( begin(container), end(container), ## __VA_ARGS__); })(x)
#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__); })(x)
#define debug(...) debug_function(#__VA_ARGS__, __VA_ARGS__)
// clang-format on

using ull = unsigned long long;
using ll = long long;
using Pll = pair<ll, ll>;
using P = pair<int, int>;

template <typename T, typename... T2>
void debug_function(string_view name, const T &a, T2 &&...rest) {
  stack<char> bs;
  string_view lbs = "({[", rbs = ")}]";
  int end = name.size();
  for (int i = 0; i < len(name); i++) {
    if (lbs.find(name[i]) != string::npos) bs.push(name[i]);
    if (rbs.find(name[i]) != string::npos and !bs.empty()) bs.pop();
    if (name[i] == ',' and bs.empty()) {
      end = i;
      break;
    }
  }
  cerr << name.substr(0, end) << ":" << a;
  if constexpr (sizeof...(rest) == 0) {
    cerr << '\n';
  } else {
    cerr << ' ';
    debug_function(name.substr(name.find_first_not_of(' ', end + 1)), forward<T2>(rest)...);
  }
}

template <typename T>
vector<T> make_vector(size_t a, T b) {
  return vector<T>(a, b);
}

template <typename... Ts>
auto make_vector(size_t a, Ts... ts) {
  return vector<decltype(make_vector(ts...))>(a, make_vector(ts...));
}

template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
  return a < b and (a = b, true);
}

template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
  return a > b and (a = b, true);
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << p.first << ' ' << p.second;
  return os;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const map<T1, T2> &v) {
  for (pair<T1, T2> x: v) {
    os << "(" << x.first << ", " << x.second << ")" << (v.rbegin()->first == x.first ? "" : ", ");
  }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, queue<T> v) {
  if (!v.empty()) {
    os << v.front();
    v.pop();
  }
  while (!v.empty()) {
    os << " " << v.front();
    v.pop();
  }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, stack<T> v) {
  if (!v.empty()) {
    os << v.top();
    v.pop();
  }
  while (!v.empty()) {
    os << " " << v.top();
    v.pop();
  }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  rep(i, len(v)) { cout << v[i] << (i == len(v) - 1 ? "" : " "); }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const deque<T> &v) {
  rep(i, len(v)) { cout << v[i] << (i == len(v) - 1 ? "" : " "); }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  bool is_f = true;
  for (T x: v) {
    os << (is_f ? "" : " ") << x;
    is_f = false;
  }
  return os;
}

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  is >> p.first >> p.second;
  return is;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &in: v)
    is >> in;
  return is;
}

struct IoSetup {
  IoSetup(int x = 15) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(x);
    cerr << fixed << setprecision(x);
  }
} iosetup;

struct get_slice {
  static constexpr int init = INT32_MAX;
  get_slice() {}

  template <typename T>
  vector<T> operator()(const vector<T> &v, int r) {
    if (r < 0) r += v.size();
    vector<T> res;
    res.reserve(r);
    for (int i = 0; i < r; i++) {
      res.emplace_back(v[i]);
    }
    return res;
  }

  template <typename T>
  vector<T> operator()(const vector<T> &v, int l, int r, int stride = init) {
    assert(stride != 0);
    if (stride == init) stride = 1;
    vector<T> res;
    int start = (stride > 0 ? l : r - 1);
    for (int i = start; (stride > 0 ? i < r : i >= l); i += stride) {
      if (i >= 0) {
        res.emplace_back(v[i]);
      } else {
        res.emplace_back(v.end()[i]);
      }
    }
    return res;
  }

  string operator()(const string &s, int r) {
    if (r < 0) r += s.size();
    string res;
    res.reserve(r);
    for (int i = 0; i < r; i++) {
      res.push_back(s[i]);
    }
    return res;
  }

  string operator()(const string &s, int l, int r, int stride = init) {
    assert(stride != 0);
    if (stride == init) stride = 1;
    string res;
    res.reserve(abs(r - l) / stride);
    int start = (stride > 0 ? l : r - 1);
    for (int i = start; (stride > 0 ? i < r : i >= l); i += stride) {
      if (i >= 0) {
        res.push_back(s[i]);
      } else {
        res.push_back(s.end()[i]);
      }
    }
    return res;
  }
} sl;

template <typename iter>
vector<int> sorted_index(const iter &first, const iter &last) {
  auto tmp = *first;
  vector<decltype(tmp)> a(first, last);
  vector<int> res(a.size());
  iota(res.begin(), res.end(), 0);
  stable_sort(res.begin(), res.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  return res;
}

template <typename T1, typename T2>
vector<pair<T1, T2>> aggregate(const vector<T1> &a, const vector<T2> &b) {
  vector<pair<T1, T2>> res;
  int mi = min(a.size(), b.size());
  int ma = max(a.size(), b.size());
  res.reserve(ma);
  for (int i = 0; i < mi; i++) {
    res.emplace_back(a[i], b[i]);
  }

  for (int i = mi; i < ma; i++) {
    if (a.size() > b.size()) {
      res.emplace_back(a[i]);
    } else {
      res.emplace_back(b[i]);
    }
  }
  return res;
}

template <typename T>
map<T, int> counter(const vector<T> &vs) {
  map<T, int> res;
  for (T v: vs)
    res[v]++;
  return res;
}

template <typename T, size_t length>
array<T, length> to_array(const vector<T> &vs) {
  array<T, length> res;
  for (int i = 0; i < (int)length; i++) {
    res[i] = vs[i];
  }
  return res;
}

string join(const vector<string> &strs, const string &sep) {
  string res = "";
  for (int i = 0; i < (int)strs.size(); i++) {
    if (i) res += sep;
    res += strs[i];
  }
  return res;
}

namespace template_internal_math {

  template <typename T>
  T extgcd(T a, T b, T &x, T &y) {
    if (b == 0) {
      x = 1;
      y = 0;
      return a;
    }
    T d = extgcd(b, a % b, y, x);
    y = y - (a / b) * x;
    return d;
  }

} // namespace template_internal_math

ll power(ll a, ll e, ll p = -1) {
  assert(p != 0);
  assert(p >= -1);

  if (e < 0) {
    assert(p != -1 and gcd(a, p) == 1);
    ll x, y;
    template_internal_math::extgcd(a, p, x, y);
    a = (x % p + p) % p;
    e *= -1;
  }

  ll res = 1;
  while (e > 0) {
    if (e & 1) {
      res *= a;
      if (p != -1) res %= p;
    }
    a *= a;
    if (p != -1) a %= p;
    e >>= 1;
  }
  return res;
}

int logarithm(ll base, ll n) {
  assert(base != 0);
  int cnt = 0;
  while (n % base == 0) {
    n /= base;
    cnt++;
  }
  return cnt;
}

ll ceil_div(ll n, ll d) {
  assert(d != 0);
  return n / d + (((n ^ d) >= 0) && (n % d));
}

ll floor_div(ll n, ll d) {
  assert(d != 0);
  return n / d - (((n ^ d) < 0) && (n % d));
}

constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr int dy[] = { 0, -1, 1, 0, -1, 1, -1, 1 };
constexpr int dx[] = { -1, 0, 0, 1, -1, -1, 1, 1 };
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = static_cast<int>(1e9) + 7;
constexpr char newl = '\n';

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
  function<T(T, int, int,re_rooting_dp<T, CostType> &)> add_node;

  void dfs(int v, int par, int &idx) {
    order[idx++] = v;
    pars[v] = par;
    deps[v] = par == -1 ? 0 : deps[par] + 1;
    for (auto [to, ignore]: g[v]) {
      if (to == par) continue;
      dfs(to, v, idx);
    }
    if (par != -1) sizs[par] = ++sizs[v];
  }

  void post_order() {
    for (int i = order.size() - 1; i >= 1; i--) {
      int v = order[i];
      int par = pars[v];
      int par_idx = -1;
      T accum = identity;
      for (int j = 0; j < (int)g[v].size(); j++) {
        int to = g[v][j].first;
        if (to == par) {
          par_idx = j;
          continue;
        }
        accum = merge(accum, ch_tree[v][j]);
      }
      if (par_idx != -1) {
        ch_tree[par][seen_idx[v][par_idx]] = add_node(accum, v, par, *this);
      }
    }
  }

  void pre_order() {
    for (auto v: order) {
      int adj_cnt = g[v].size();
      vector<T> accum_back(adj_cnt);
      accum_back.back() = identity;
      for (int j = adj_cnt - 1; j >= 1; j--) {
        accum_back[j - 1] = merge(accum_back[j], ch_tree[v][j]);
      }
      T accum_front = identity;
      for (int j = 0; j < adj_cnt; j++) {
        int par = g[v][j].first;
        T res = add_node(merge(accum_front, accum_back[j]), v, par,*this);
        ch_tree[g[v][j].first][seen_idx[v][j]] = res;
        accum_front = merge(accum_front, ch_tree[v][j]);
      }
      results[v] = add_node(accum_front, v, -1,*this);
    }
  }

public:
  re_rooting_dp(int n, T id, function<T(T, T)> f1, function<T(T, int, int,re_rooting_dp<T, CostType> &)> f2) : g(n), seen_idx(n) {
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
    for (int i = 0; i < (int)g.size(); i++) {
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


// set<pair<P,ll>> edges;
map<P,ll> edges;
vector<ll> ds;

Pll e() {
  return {0,0};
}

Pll op(Pll a, Pll b) {
  // return make_pair<ll, ll>(a.first + b.first, a.second + b.second);
  return max(a,b);
  // return {max(a.first,b.first),max(a.second,b.second)};
}

Pll add_node(Pll res, int v, int par,re_rooting_dp<Pll, ll> &tree) {
  auto [child_result, d] = res;
  ll cost = edges[pair(v,par)];
  return {child_result+cost+ds[v], v};
  // if(par != -1){
  //   return {child_result+cost, v};
  // }
  // return {child_result, v};
  // return res + ds[v];
  // return make_pair<ll, ll>(child_result + mydistance, mydistance + ds[v]);
}

int main() {
  int n;
  cin>>n;

  re_rooting_dp<Pll,ll> T(n,e(),op,add_node);

  rep(i,n-1){
    int a,b,c;
    cin>>a>>b>>c;
    a--,b--;
    edges[make_pair(a,b)]=c;
    edges[make_pair(b,a)]=c;
    T.add_edge(a,b,c);
    T.add_edge(b,a,c);
    // edges.emplace(make_pair(a,b),c);
  }

  ds.resize(n);
  cin>>ds;

  T.build(0);

  rep(i,n){
    cout<<T[i]<<endl;
    // cout<<T[i].first+ds[T[i].second]<<newl;
  }
}
