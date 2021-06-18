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

void solve(int &cnt, int &b, int num){
  if(cnt<num) return;
  if(b <= 0) return;
  if(cnt>b*num){
    cnt-=b*num;
    b=0;
  }else{
    b-=cnt/num;
    cnt%=num;
  }
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for ( auto &S : s ) cin >> S;

  vector<int> cnt(26, 0);
  range(i, 0, h)
    range(j, 0, w) {
      cnt[s[i][j] - 'a']++;
   }

  bool ans = true;
  int block = (h/2) * (w/2);
  int border = (w%2)*(h/2) + (h%2)*(w/2);
  bool is_first = true;

  range(i,0,26){
    solve(cnt[i],block,4);
    solve(cnt[i],border,2);
    if ( h%2 && w%2 && cnt[i] > 0 ) {
      if ( !is_first ) ans = false;
      is_first = false;
    }else if( cnt[i] > 0 ) {
      //cerr<<"cnt["<<i<<"]:"<<cnt[i]<<endl;
      //debug(border);
      ans = false;
    }
  }
  if ( block > 0 || border > 0 ) ans = false;

  cout << (ans ? "Yes" : "No") << endl;
}