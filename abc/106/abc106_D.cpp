#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second<<'\n'; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

template <class T>
struct Cumlative{
  vector<vector<T>> data;
  Cumlative(int H,int W):data(H+1,vector<T>(W+1,0)){}

  void set(int y,int x,int v){
    y++;
    x++;
    data[y][x]+=v;
  }

  void build(){
    for(int i=1;i<data.size();i++){
      for(int j=1;j<data[i].size();j++){
        data[i][j]+=data[i][j-1]+data[i-1][j]-data[i-1][j-1];
      }
    }
  }

  T query(int sy,int sx,int gy,int gx){
    return data[gy][gx]-data[gy][sx]-data[sy][gx]+data[sy][sx];
  }
};

int main() {
  int n,m,q;
  cin>>n>>m>>q;

  Cumlative<ll> table(n,n);
  range(i,0,m){
    int l,r;
    cin>>l>>r;
    l--;
    r--;
    table.set(l,r,1);
  }

  table.build();

  range(i,0,q){
    int l,r;
    cin>>l>>r;
    l--;
    cout<<table.query(l,l,r,r)<<newl;
  }
}