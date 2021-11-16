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


class union_find {
private:
  int grp_cnt, merge_cnt;
  vector<int> siz, par;
  stack<tuple<int, int, int>> history;

public:
  union_find(int N) : grp_cnt(N), merge_cnt(0), siz(N, 1), par(N) {
    iota(par.begin(), par.end(), 0);
  }

  // 根（そのグループの識別番号）
  int root(int x) {
    if ( x == par[x] ) return x;
    return par[x] = root(par[x]);
  }

  // 連結成分の個数
  int group_count() { return grp_cnt; }

  int merge_count() { return merge_cnt; }

  int size(int x) { return siz[root(x)]; }

  bool same(int x, int y) { return root(x) == root(y); }

  bool merge(int x, int y) {
    x = root(x), y = root(y);
    history.emplace(make_tuple(x, par[x], siz[x]));
    history.emplace(make_tuple(y, par[y], siz[y]));
    if ( x == y ) return false;
    if ( siz[x] < siz[y] ) swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
    grp_cnt--;
    merge_cnt++;
    return true;
  }

  bool undo() {
    if ( history.empty() ) return false;
    auto [x, x_par, x_siz] = history.top();
    history.pop();
    auto [y, y_par, y_siz] = history.top();
    history.pop();

    grp_cnt++;
    merge_cnt--;
    par[x] = x_par;
    siz[x] = x_siz;
    par[y] = y_par;
    siz[y] = y_siz;
    return true;
  }

  void clear_history() {
    while ( !history.empty() ) {
      history.pop();
    }
  }

  void all_undo() {
    while ( undo() ) {}
  }

  // Θ(N)
  vector<vector<int>> groups() {
    int n = par.size();
    vector<vector<int>> grps(n);
    for ( int i = 0; i < n; i++ ) {
      grps[root(i)].emplace_back(i);
    }
    vector<vector<int>> res;
    res.reserve(group_count());
    for ( int i = 0; i < n; i++ ) {
      if ( grps[i].empty() ) continue;
      res.emplace_back(grps[i]);
    }
    return res;
  }

  // Θ(NlogN)
  // 2つのunion_findでi番目の頂点と同じ連結成分であるものの個数(i番目の頂点を含む)
  vector<int> connect_count(union_find tree) {
    map<pair<int, int>, int> mp;

    int n = par.size();
    for ( int i = 0; i < n; i++ ) {
      pair<int, int> p = make_pair(root(i), tree.root(i));
      mp[p]++;
    }

    vector<int> res(n);
    for ( int i = 0; i < n; i++ ) {
      pair<int, int> p = make_pair(root(i), tree.root(i));
      res[i] = mp[p];
    }
    return res;
  }
};


int main() {
  int n;
  cin>>n;
  vector<pair<pair<ll,int>,int>> costs(n-1);

  range(i,n-1){
    auto &[p,v]=costs[i];
    auto &[w,u]=p;
    cin>>u>>v>>w;
    u--,v--;
  }

  whole(sort,costs);

  union_find uf(n);

  range(i,n-1){
    auto [p,v]=costs[i];
    auto [w,u]=p;
    uf.merge(u,v);
  }

  ll ans=0;

  rrange(i,n-1){
    auto [p,v]=costs[i];
    auto [w,u]=p;
    uf.undo();
    ans+=(ll)uf.size(u)*(ll)uf.size(v)*w;
  }
  cout<<ans<<endl;
}