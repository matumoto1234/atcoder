#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define range(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1 )
#define rrange(i, l, r) for ( int i = (int)(r)-1; i >= (int)(l); (i) -= 1 )
#define debug(x) cerr << #x << ": " << (x) << endl;
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

struct UnionFind {
  int cnt;
  vector<int> siz, par;
  UnionFind(int N) : cnt(N), siz(N, 1), par(N) {
    iota(par.begin(), par.end(), 0);
  }

  int root(int x) {
    if ( x == par[x] ) return x;
    return par[x] = root(par[x]);
  }

  int group_count() { return cnt; }

  int size(int x) { return siz[root(x)]; }

  bool same(int x, int y) { return root(x) == root(y); }

  void merge(int x, int y) {
    x = root(x);
    y = root(y);
    if ( x == y ) return;
    if ( siz[x] < siz[y] ) swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
    cnt--;
  }

  // Θ(NlogN)
  // 2つのUnionFindでi番目の頂点と同じ連結成分であるものの個数(i番目の頂点を含む)
  vector<int> connect_count(UnionFind tree) {
    map<pair<int, int>, int> mp;

    int N = par.size();
    for ( int i = 0; i < N; i++ ) {
      pair<int, int> p = make_pair(root(i), tree.root(i));
      mp[p]++;
    }

    vector<int> res(N);
    for ( int i = 0; i < N; i++ ) {
      pair<int, int> p = make_pair(root(i), tree.root(i));
      res[i] = mp[p];
    }
    return res;
  }
};

int main() {
  int n, k, l;
  cin >> n >> k >> l;

  UnionFind uf1(n), uf2(n);

  range(i, 0, k) {
    int p, q;
    cin >> p >> q;
    p--, q--;
    uf1.merge(p, q);
  }

  range(i, 0, l) {
    int r, s;
    cin >> r >> s;
    r--, s--;
    uf2.merge(r, s);
  }

  vector<int> ans = uf1.connect_count(uf2);

  cout << ans << newl;
}