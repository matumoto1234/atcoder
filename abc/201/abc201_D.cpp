#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define range(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1 )
#define rrange(i, l, r) for ( int i = (int)(r)-1; i >= (int)(l); (i) -= 1 )
#define debug(x) cerr << "(" << __LINE__ << ") " << #x << ": " << (x) << endl;
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << p.first << ' ' << p.second; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { for ( pair<T1, T2> x : v ) { os << x << (x.first == v.rbegin()->first && x.second == v.rbegin()->second ? "" : "\n"); } return os; }
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

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  for ( auto &S : s ) {
    cin >> S;
  }

  vector<vector<int>> inc(h, vector<int>(w));
  range(i, 0, h) {
    range(j, 0, w) {
      if ( s[i][j] == '+' ) inc[i][j] = 1;
      if ( s[i][j] == '-' ) inc[i][j] = -1;
      if ( (i + j) % 2 == 0 ) inc[i][j] *= -1;
    }
  }

  vector<vector<int>> dp(h, vector<int>(w));
  dp[h - 1][w - 1] = 0;
  rrange(i, 0, h) {
    rrange(j, 0, w) {
      if ( i == h - 1 && j == w - 1 ) continue;
      if ( (i + j) % 2 == 0 ) {
        dp[i][j] = -INF32;
        if ( i + 1 < h ) chmax(dp[i][j], dp[i + 1][j] + inc[i + 1][j]);
        if ( j + 1 < w ) chmax(dp[i][j], dp[i][j + 1] + inc[i][j + 1]);
      } else if ( (i + j) % 2 == 1 ) {
        dp[i][j] = INF32;
        if ( i + 1 < h ) chmin(dp[i][j], dp[i + 1][j] + inc[i + 1][j]);
        if ( j + 1 < w ) chmin(dp[i][j], dp[i][j + 1] + inc[i][j + 1]);
      }
    }
  }

  if ( dp[0][0] > 0 )
    cout << "Takahashi" << endl;
  else if ( dp[0][0] == 0 )
    cout << "Draw" << endl;
  else
    cout << "Aoki" << endl;
}