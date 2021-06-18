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

template <typename T,T MOD,T B1,T B2>
struct RollingHash2D{
  struct CumulativeSum2D{
    vector<vector<T>> data;
    CumulativeSum2D(){}
    CumulativeSum2D(int H,int W):data(H+1,vector<T>(W+1,0)){}

    void set(int y,int x,T v){ data[y+1][x+1]+=v; }

    void build(){
      for(int i=1;i<(int)data.size();i++){
        for(int j=1;j<(int)data[i].size();j++){
          data[i][j]+=(data[i][j-1]+data[i-1][j]-data[i-1][j-1])%MOD;
          if(data[i][j]<0) data[i][j]+=MOD;
        }
      }
    }

    // [ (sy,sx), (gy,gx) )
    T query(int sy,int sx,int gy,int gx){
      T res=(data[gy][gx]-data[gy][sx]-data[sy][gx]+data[sy][sx])%MOD;
      if(res<0) res+=MOD;
      return res;
    }
  };

  CumulativeSum2D cumulative_sum;
  vector<vector<T>> inv;
  RollingHash2D(vector<vector<T>> vals){ build(vals); }
  RollingHash2D(vector<string> &s){
    vector<vector<T>> vals(s.size());
    for(int i=0;i<(int)s.size();i++){
      for(int j=0;j<(int)s[0].size();j++){
        T val=s[i][j]%MOD;
        if(val<0) val+=MOD;
        vals[i].emplace_back(val);
      }
    }
    build(vals);
  }

  T pow(T a,T e){
    if(e==0) return 1;
    if(e%2==0){
      T res=pow(a,e/2);
      return (res*res)%MOD;
    }
    return (pow(a,e-1)*a)%MOD;
  }

  void build(vector<vector<T>> vals){
    int h=vals.size(),w=vals[0].size();
    inv.assign(h+1,vector<T>(w+1,0));
    cumulative_sum.data.assign(h+1,vector<T>(w+1,0));
    inv[h][w]=(pow(B1,h*(MOD-2))*pow(B2,w*(MOD-2)))%MOD;
    for(int i=h-1;i>=0;i--) inv[i][w]=(inv[i+1][w]*B1)%MOD;
    for(int j=w-1;j>=0;j--) inv[h][j]=(inv[h][j+1]*B2)%MOD;
    for(int i=h-1;i>=0;i--) for(int j=w-1;j>=0;j--){
      inv[i][j]=(((inv[i+1][j+1]*B1)%MOD)*B2)%MOD;
    }
    for(int i=0;i<h;i++) for(int j=0;j<w;j++){
      T val=(((vals[i][j]*pow(B1,i))%MOD)*pow(B2,j))%MOD;
      cumulative_sum.set(i,j,val);
    }
    cumulative_sum.build();
  }

  T find(int sy,int sx,int gy,int gx){
    return (cumulative_sum.query(sy,sx,gy,gx)*inv[sy][sx])%MOD;
  }
};

int main() {
  int n,m;
  cin>>n>>m;
  vector<string> a(n);
  range(i,0,n) cin>>a[i];

  vector<string> b(m);
  range(i,0,m) cin>>b[i];

  RollingHash2D<ll,(ll)1e9+7,(ll)1e8+7,(ll)1e7+7> s(a);
  RollingHash2D<ll,(ll)1e9+7,(ll)1e8+7,(ll)1e7+7> t(b);

  bool flg=false;
  range(i,0,n-m+1) range(j,0,n-m+1){
    if(s.find(i,j,i+m,j+m)==t.find(0,0,m,m)) flg=true;
  }
  cout<<(flg?"Yes":"No")<<endl;
}