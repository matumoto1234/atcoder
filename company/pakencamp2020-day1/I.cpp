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
int sx,sy,gx,gy;
vector<vector<char>> s;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

bool rangeCheck(int y,int x){
  return 0<=y&&y<h&&0<=x&&x<w;
}

struct Point{
  int y,x;
  // true:updown, false:leftright
  bool dir;
  Point(){}
  Point(int y,int x,bool dir):y(y),x(x),dir(dir){}
};

int solve(bool sdir){
  vector<vector<int>> arrived(h,vector<int>(w,-1));
  arrived[sy][sx]=0;
  queue<Point> q;
  q.emplace(sy,sx,sdir);

  while(!q.empty()){
    auto [y,x,dir]=q.front();
    q.pop();

    range(i,0,4){
      if(dir&&i>=2) continue;
      if(!dir&&i<2) continue;
      int ny=y+dy[i];
      int nx=x+dx[i];


      if(!rangeCheck(ny,nx)) continue;
      if(s[ny][nx]=='#') continue;
      if(arrived[ny][nx] != -1) continue;

      arrived[ny][nx]=arrived[y][x]+1;
      q.emplace(ny,nx,!dir);
    }
  }
  return arrived[gy][gx];
}

int main() {
  cin>>h>>w;
  cin>>sy>>sx>>gy>>gx;
  sx--;
  sy--;
  gx--;
  gy--;

  s.assign(h,vector<char>(w));
  range(i,0,h) range(j,0,w){
    cin>>s[i][j];
  }

  int ans=-1;

  int v=solve(false);
  if(v!=-1) chmax(ans,v);
  v=solve(true);
  if(v!=-1) chmax(ans,v);

  cout<<ans<<endl;
}