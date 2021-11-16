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

template <typename T>
struct CumulativeSum {
  vector<T> sum;
  CumulativeSum(const vector<T> &a) {
    int n = a.size();
    sum.assign(n + 1, 0);
    for ( int i = 0; i < n; i++ )
      sum[i + 1] = a[i] + sum[i];
  }

  T query(int l, int r) { return sum[r] - sum[l]; }
};

template <typename T1, typename T2>
T1 Binomial(T1 n, T2 r) {
  T1 res = 1;
  for ( T1 i = 0; i < r; i++ ) {
    res *= n - i;
    res /= i + 1;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for ( auto &A : a )
    cin >> A;

  range(i, 0, n) {
    if ( i % 2 == 0 ) a[i] *= -1;
  }

  CumulativeSum<ll> sum(a);

  map<ll, ll> cntmp;
  for ( auto x : sum.sum ) {
    cntmp[x]++;
  }

  ll ans = 0;
  for ( auto [val, cnt] : cntmp ) {
    ans += Binomial(cnt, 2LL);
  }
  cout << ans << endl;
}