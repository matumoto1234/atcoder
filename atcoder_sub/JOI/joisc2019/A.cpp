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

vector<int> compress(vector<int> a) {
  vector<int> cpa = a;
  sort(cpa.begin(), cpa.end());
  cpa.erase(unique(cpa.begin(), cpa.end()), cpa.end());
  for ( int &A : a ) {
    A = lower_bound(cpa.begin(), cpa.end(), A) - cpa.begin();
  }
  return a;
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> s(n), t(n);
  vector<int> sum(n);
  range(i, 0, n) {
    cin >> s[i] >> t[i];
    sum[i] = s[i] + t[i];
  }

  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  sort(sum.begin(), sum.end());

  s.erase(unique(s.begin(), s.end()), s.end());
  t.erase(unique(t.begin(), t.end()), t.end());
  sum.erase(unique(sum.begin(), sum.end()), sum.end());

  range(i, 0, q) {
    int x, y, z;
    cin >> x >> y >> z;

    int ans = 0;
    int v1 = lower_bound(s.begin(), s.end(), x) - s.begin();
    int v2 = lower_bound(t.begin(), t.end(), y) - t.begin();
    int v3 = lower_bound(sum.begin(), sum.end(), z) - sum.begin();
  }
}