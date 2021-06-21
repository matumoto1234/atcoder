#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define range(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1 )
#define rrange(i, l, r) for ( int i = (int)(r)-1; i >= (int)(l); (i) -= 1 )
#define debug(x) cerr << "(" << __LINE__ << ") " << #x << ": " << (x) << endl;
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << p.first << ' ' << p.second; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { for ( pair<T1, T2> x : v ) { os << x << "\n"; } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> v) { if(!v.empty()) { os << v.front(); v.pop(); } while (!v.empty()) { os << " " << v.front(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> v) { if(!v.empty()) { os << v.top(); v.pop(); } while (!v.empty()) { os << " " << v.top(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
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

template <typename T>
struct WarshallFloyd {
  vector<vector<T>> ds;
  vector<vector<int>> ns;

  T inf() { return numeric_limits<T>::max() / 2; }

  WarshallFloyd(int V) : ds(V, vector<T>(V, inf())) {
    for ( int i = 0; i < V; i++ )
      ds[i][i] = 0;
  }

  void add_edge(int from, int to, T cost) { ds[from][to] = cost; }

  void build() {
    int V = ds.size();

    ns.resize(V, vector<int>(V));
    for ( int i = 0; i < V; i++ ) {
      for ( int j = 0; j < V; j++ ) {
        ns[i][j] = j;
      }
    }

    for ( int k = 0; k < V; k++ ) {
      for ( int i = 0; i < V; i++ ) {
        for ( int j = 0; j < V; j++ ) {
          if ( ds[i][k] == inf() || ds[k][j] == inf() ) continue;
          if ( ds[i][j] > ds[i][k] + ds[k][j] ) {
            ds[i][j] = ds[i][k] + ds[k][j];
            ns[i][j] = ns[i][k];
          }
        }
      }
    }
  }

  vector<T> &operator[](int k) { return ds[k]; }

  bool neg_cycle() {
    int V = ds.size();
    for ( int i = 0; i < V; i++ ) {
      if ( ds[i][i] < 0 ) return true;
    }
    return true;
  }

  vector<int> restore(int s, int g) {
    vector<int> res;
    for ( int v = s; v != g; v = ns[v][g] ) {
      res.emplace_back(v);
    }
    res.emplace_back(g);
    return res;
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  WarshallFloyd<ll> G(n);

  map<P, bool> edges;
  vector<P> ab(m);

  range(i, 0, m) {
    auto &[a, b] = ab[i];
    int c;
    cin >> a >> b >> c;

    a--, b--;

    G.add_edge(a, b, c);
    G.add_edge(b, a, c);
    edges[make_pair(a, b)] = true;
    edges[make_pair(b, a)] = true;
  }

  G.build();

  range(i, 0, n) {
    range(j, 0, n) {
      if ( i == j ) continue;

      auto vs = G.restore(i, j);
      // cerr<<vs<<endl;
      range(k, 1, vs.size()) {
        edges[make_pair(vs[k - 1], vs[k])] = false;
        edges[make_pair(vs[k], vs[k - 1])] = false;
      }
    }
  }

  int ans = 0;
  for ( P e : ab ) {
    if ( edges[e] ) ans++;
  }
  cout << ans << endl;
}