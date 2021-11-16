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
constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr char newl = '\n';

bool isRange(int y,int x,int h,int w){
  return 0<=y&&y<h&&0<=x&&x<w;
}
constexpr int dy[]={1,0,-1,0},dx[]={0,1,0,-1};

int main() {
  int h,w;
  cin>>h>>w;
  vector<string> a(h);
  range(i,0,h){
    cin>>a[i];
  }

  int turn=0;
  vector<queue<P>> q(2);

  range(i,0,h) range(j,0,w){
    if(a[i][j]=='#') q[0].emplace(i,j);
  }

  auto op = [&](){
    bool update=false;
    while(!q[turn].empty()){
      auto [y,x]=q[turn].front();
      q[turn].pop();
      range(i,0,4){
        int ny=y+dy[i],nx=x+dx[i];
        if(!isRange(ny,nx,h,w)) continue;
        if(a[ny][nx]=='#') continue;

        update=true;
        a[ny][nx]='#';
        q[(turn+1)%2].emplace(ny,nx);
      }
    }
    turn=(turn+1)%2;
    return update;
  };

  int ans=0;
  while(1){
    bool result=op();
    if(!result) break;
    ans++;
  }
  cout<<ans<<endl;
}