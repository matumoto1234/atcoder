#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ull = unsigned long long;
using ll = long long;
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

int h,w;
bool rangeChecK(int y,int x){
  return 0<=y&&y<h&&0<=x&&x<w;
}

int main() {
  cin>>h>>w;
  vector<vector<int>> s(h,vector<int>(w));
  range(i,0,h) range(j,0,w){
    char c;
    cin>>c;
    if(c=='.') s[i][j]=0;
    else s[i][j]=1;
  }

  int dy[]={1,0};
  int dx[]={0,1};
  vector<vector<int>> dp(h,vector<int>(w,INF32));
  dp[0][0]=s[0][0];
  queue<P> q;
  q.emplace(0,0);
  while(!q.empty()){
    auto [y,x]=q.front();
    q.pop();
    range(i,0,2){
      int ny=y+dy[i];
      int nx=x+dx[i];
      if(!rangeChecK(ny,nx)) continue;
      if(dp[ny][nx]==INF32) q.emplace(ny,nx);
      if(s[y][x]==0&&s[ny][nx]==1) chmin(dp[ny][nx],dp[y][x]+1);
      else chmin(dp[ny][nx],dp[y][x]);
    }
  }
  cout<<dp[h-1][w-1]<<endl;
}