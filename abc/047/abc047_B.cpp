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

int main() {
  int w,h,n;
  cin>>w>>h>>n;
  vector<vector<bool>> rect(h,vector<bool>(w,false));

  range(i,0,n){
    int x,y,a;
    cin>>x>>y>>a;
    x--;
    y--;
    if(a==1){
      range(i,0,h) range(j,0,x+1){
        rect[i][j]=true;
      }
    }
    if(a==2){
      range(i,0,h) range(j,x-1,w){
        rect[i][j]=true;
      }
    }
    if(a==3){
      range(i,0,y) range(j,0,w){
        rect[i][j]=true;
      }
    }
    if(a==4){
      range(i,y+1,h) range(j,0,w){
        rect[i][j]=true;
      }
    }
  }

  int ans=h*w;
  range(i,0,h) range(j,0,w){
    ans-=rect[i][j];
  }
  // range(i,0,h) cout<<rect[i]<<endl;
  cout<<ans<<endl;
}