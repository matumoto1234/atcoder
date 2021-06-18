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
using Pll = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

bool rangeCheck(int h,int w,int y,int x){
  return 0<=y&&y<h&&0<=x&&x<w;
}

int main() {
  int h,w,x,y;
  cin>>h>>w>>y>>x;
  x--;
  y--;
  vector<string> s(h);
  range(i,0,h) cin>>s[i];

  int ans=1;
  const int dy[]={0,1,0,-1};
  const int dx[]={1,0,-1,0};
  range(dir,0,4){
    
    int ny=y;
    int nx=x;
    while(1){
      ny+=dy[dir];
      nx+=dx[dir];
      if(!rangeCheck(h,w,ny,nx)) break;
      if(s[ny][nx]=='#') break;
      ans++;
    }
  }
  cout<<ans<<endl;
}