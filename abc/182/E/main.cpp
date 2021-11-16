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


int h,w,n,m;
vector<vector<int>> board1;
vector<vector<int>> board2;
void dfs(int y,int x,int dir){
  board1[y][x]=1;
  board2[y][x]=1;
  y+=dy[dir];
  x+=dx[dir];
  while(0<=y&&y<h&&0<=x&&x<w){
    if(dir==0 || dir==3){
      if(board1[y][x]) return;
      board1[y][x]=1;
    }else{
      if(board2[y][x]) return;
      board2[y][x]=1;
    }
    y+=dy[dir];
    x+=dx[dir];
  }
}

int main() {
  cin>>h>>w>>n>>m;
  vector<P> ab(n),cd(m);
  for(auto &[a,b]:ab){
    cin>>a>>b;
    a--,b--;
  }
  board1.assign(h,vector<int>(w,0));
  board2.assign(h,vector<int>(w,0));
  for(auto &[c,d]:cd){
    cin>>c>>d;
    c--,d--;
    board1[c][d]=-1;
    board2[c][d]=-1;
  }

  for(auto [a,b]:ab){
    range(i,0,4){
      dfs(a,b,i);
    }
  }

  int ans=0;
  range(i,0,h) range(j,0,w){
    if(board1[i][j]==1 || board2[i][j]==1) ans++;
  }
  cout<<ans<<endl;
}