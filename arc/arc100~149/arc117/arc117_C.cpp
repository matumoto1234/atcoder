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
struct LucasCombination {
  vector<vector<T>> data;
  int MOD;
  LucasCombination(int _MOD) {
    MOD = _MOD;
    data.assign(MOD + 1, vector<T>(MOD + 1, 0));
    data[0][0] = 1;
    for ( int i = 0; i < MOD; i++ ) {
      for ( int j = 0; j <= i; j++ ) {
        data[i + 1][j] += data[i][j];
        data[i + 1][j] %= MOD;
        data[i + 1][j + 1] += data[i][j];
        data[i + 1][j + 1] %= MOD;
      }
    }
  }

  T query(int n, int r) {
    T res = 1;
    while ( n > 0 ) {
      int ni = n % MOD;
      int ri = r % MOD;
      res *= data[ni][ri];
      res %= MOD;
      n /= MOD;
      r /= MOD;
    }
    return res;
  }
};

int main() {
  int n;
  string s;
  cin >> n >> s;
   
  vector<ll> vs(n);
  range(i,0,n){
    if(s[i]=='B') vs[i]=0;
    if(s[i]=='W') vs[i]=1;
    if(s[i]=='R') vs[i]=2;
  }

  LucasCombination<ll> comb(3);
  ll ans=0;
  range(i,0,n){
    ans+=comb.query(n-1,i)*vs[i];
    ans%=3;
  }
  if(n%2==0) ans*=-1;
  ans=(ans+3)%3;
  
  if(ans==0) cout<<'B'<<endl;
  if(ans==1) cout<<'W'<<endl;
  if(ans==2) cout<<'R'<<endl;
}