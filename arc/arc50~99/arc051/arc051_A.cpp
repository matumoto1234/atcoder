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
constexpr int dy[] = {0,-1,1,0,-1,1,-1,1};
constexpr int dx[] = {-1,0,0,1,-1,-1,1,1};
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = (int)1e9 + 7;
constexpr char newl = '\n';


int main() {
  ll x1,y1,rad;
  ll x2,y2,x3,y3;
  cin>>x1>>y1>>rad>>x2>>y2>>x3>>y3;

  ll u,d,l,r;
  u=d=y1;
  l=r=x1;
  range(i,-1001,1001){
    range(j,-1001,1001){
      if((y1-i)*(y1-i)+(x1-j)*(x1-j)<=rad*rad){
        chmax(u,i);
        chmax(r,j);
        chmin(d,i);
        chmin(l,j);
      }
    }
  }

  cerr<<l<<' '<<d<<' '<<r<<' '<<u<<endl;

  bool red=1,blue=1;
  if(jx1){
    blue=0;
  }
  if(x2<=x1-rad&&x1+rad<=x3 && y2<=y1-rad&&y1+rad<=y3){
    red=0;
  }
  cout<<(red?"YES":"NO")<<endl;
  cout<<(blue?"YES":"NO")<<endl;
}