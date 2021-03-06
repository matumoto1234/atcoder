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


namespace data_structure {
  using namespace std;
}

#include <map>
#include <numeric>
#include <stack>
#include <tuple>
#include <vector>

namespace data_structure {
  // ??????????????????
  class UnionFindUndo {
  private:
    int grp_cnt, merge_cnt;
    vector<int> siz, par;
    stack<tuple<int, int, int>> history;

  public:
    UnionFindUndo(int N): grp_cnt(N), merge_cnt(0), siz(N, 1), par(N) { iota(par.begin(), par.end(), 0); }

    // ??????????????????????????????????????????
    int root(int x) {
      if (x == par[x]) return x;
      return root(par[x]);
    }

    // ?????????????????????
    int group_count() { return grp_cnt; }

    int merge_count() { return merge_cnt; }

    int size(int x) { return siz[root(x)]; }

    bool same(int x, int y) { return root(x) == root(y); }

    bool merge(int x, int y) {
      x = root(x);
      y = root(y);
      if (x == y) return false;
      if (siz[x] < siz[y]) swap(x, y);
      history.emplace(make_tuple(x, par[x], siz[x]));
      history.emplace(make_tuple(y, par[y], siz[y]));
      siz[x] += siz[y];
      par[y] = x;
      grp_cnt--;
      merge_cnt++;
      return true;
    }

    bool undo() {
      if (history.empty()) return false;
      auto [x, x_par, x_siz] = history.top();
      history.pop();
      auto [y, y_par, y_siz] = history.top();
      history.pop();

      par[x] = x_par;
      siz[x] = x_siz;
      par[y] = y_par;
      siz[y] = y_siz;
      grp_cnt++;
      return true;
    }

    void clear_history() {
      while (!history.empty()) {
        history.pop();
      }
    }

    void all_undo() {
      while (undo()) {}
    }

    // ??(N)
    vector<vector<int>> groups() {
      int n = par.size();
      vector<vector<int>> grps(n);
      for (int i = 0; i < n; i++) {
        grps[root(i)].emplace_back(i);
      }
      vector<vector<int>> res;
      res.reserve(group_count());
      for (int i = 0; i < n; i++) {
        if (grps[i].empty()) continue;
        res.emplace_back(grps[i]);
      }
      return res;
    }

    // ??(NlogN)
    // 2??????union_find???i????????????????????????????????????????????????????????????(i????????????????????????)
    vector<int> connect_count(UnionFindUndo tree) {
      map<pair<int, int>, int> mp;

      int n = par.size();
      for (int i = 0; i < n; i++) {
        pair<int, int> p = make_pair(root(i), tree.root(i));
        mp[p]++;
      }

      vector<int> res(n);
      for (int i = 0; i < n; i++) {
        pair<int, int> p = make_pair(root(i), tree.root(i));
        res[i] = mp[p];
      }
      return res;
    }
  };

} // namespace data_structure

using namespace data_structure;


int main() {
  int n, m;
  cin >> n >> m;

  UnionFindUndo uf(n);

  vector<pii> edges(m);
  for (auto &[a, b]: edges) {
    cin >> a >> b;

    a--, b--;

    if (a > b) swap(a, b);
  }

  rwhole(sort, edges);

  vector<bool> merged(m, false);

  rep(i, m) {
    auto [a, b] = edges[i];

    merged[i] = uf.merge(a, b);
  }

  whole(sort,edges);

  rep(i, n) {
    int j = i;
    while (edges[j].first == i) {
      if(merged[j]) uf.undo();
      debug(edges[j],i,j, merged[j]);
      j++;
    }

    cout << uf.group_count() - (i + 1) << newl;
  }
}