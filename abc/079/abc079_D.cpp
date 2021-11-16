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

template <typename T>
struct WarshallFloyd{
  vector<vector<T>> ds;
  vector<int> bs;

  T inf() {return numeric_limits<T>::max()/2; }

  WarshallFloyd(int V):ds(V,vector<T>(V,inf())){
    for(int i=0;i<V;i++) ds[i][i]=0;
  }

  void add_edge(int from,int to,T cost){ ds[from][to]=cost; }

  void build(){
    int V=ds.size();
    bs.assign(V,-1);
    for(int k=0;k<V;k++){
      for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
          if(ds[i][k]==inf()||ds[k][j]==inf()) continue;
          if(ds[i][j]>ds[i][k]+ds[k][j]){
            ds[i][j]=ds[i][k]+ds[k][j];
            bs[j]=k;
          }
        }
      }
    }
  }

  vector<T> &operator[](int k){ return ds[k]; }

  bool neg_cycle(){
    int V=ds.size();
    for(int i=0;i<V;i++){
      if(ds[i][i]<0) return true;
    }
    return true;
  }

  vector<int> restore(int to){
    vector<int> res;
    if(bs[to]==-1){
      res.emplace_back(to);
      return res;
    }
    while(bs[to]!=-1){
      res.emplace_back(to);
      to=bs[to];
    }
    reverse(res.begin(),res.end());
    return res;
  }
};

int main() {
  int h,w;
  cin>>h>>w;

  WarshallFloyd<ll> G(10);
  range(i,0,10) range(j,0,10){
    int c;
    cin>>c;
    G.add_edge(i,j,c);
  }
  G.build();


  ll ans=0;
  range(i,0,h) range(j,0,w){
    int a;
    cin>>a;
    if(a==-1) continue;

    //cerr<<G[a][1]<<" a:"<<a<<endl;
    ans+=G[a][1];
  }
  cout<<ans<<endl;
}