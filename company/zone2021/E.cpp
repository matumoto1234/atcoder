// #pragma GCC target("avx2")
#pragma GCC optimize("O2")
// #pragma GCC optimize("unroll-loops")

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

template <typename T>
struct Dijkstra {
  struct edge {
    int to;
    T cost;
    edge() {}
    edge(int to, T cost) : to(to), cost(cost) {}
    bool operator<(const edge &e) const { return cost > e.cost; }
  };

  T inf() { return numeric_limits<T>::max()/2; }

  vector<vector<edge>> G;
  vector<T> ds;
  vector<map<int,int>> es;
  // vector<int> bs;
  Dijkstra(int n) : G(n) , es(n){}

  bool is_exist(int from,int to,T cost){
    if(es[from].find(to) == es[from].end()) return false;
    return es[from][to] < cost;
  }

  void add_edge(int from, int to, T cost) {
    G[from].emplace_back(to, cost);
    // es[from][to]=cost;
  }

  void build(int start) {
    int n = G.size();
    ds.assign(n, inf());
    // bs.assign(n,-1);

    priority_queue<edge> Q;
    ds[start] = 0;
    Q.emplace(start, ds[start]);

    while (!Q.empty()) {
      auto p = Q.top();
      Q.pop();
      int v = p.to;
      if (ds[v] < p.cost) continue;
      for (auto e : G[v]) {
        if (ds[e.to] > ds[v] + e.cost) {
          ds[e.to] = ds[v] + e.cost;
          // bs[e.to]=v;
          Q.emplace(e.to, ds[e.to]);
        }
      }
    }
  }

  T operator[](int k) { return ds[k]; }
};

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

template <typename T>
struct BellmanFord{
  struct edge {
    int from,to;
    T cost;
    edge(){}
    edge(int f,int t,T c):from(f),to(t),cost(c){}
  };

  int V;
  bool neg_cycle;
  bool neg_cycle_to_goal;
  vector<edge> es;
  vector<T> ds;
  vector<int> bs;

  BellmanFord(int N):V(N),neg_cycle(false),neg_cycle_to_goal(false){}

  void add_edge(int from,int to,T cost){ es.emplace_back(from,to,cost); }

  T inf() { return numeric_limits<T>::max()/2; }

  void build(int s,int g = -1){
    if(g==-1) g=V-1;
    ds.assign(V,inf());
    bs.assign(V,-1);
    ds[s]=0;

    for(int i=0;i<2*V;i++){
      for(edge e : es){
        if(ds[e.from]>=inf()) continue;
        if(ds[e.to]<=ds[e.from]+e.cost) continue;

        ds[e.to]=ds[e.from]+e.cost;
        bs[e.from]=e.to;
        if(i>=V-1){
          ds[e.to]=-inf();
          neg_cycle=true;
          if(e.to==g){
            neg_cycle_to_goal=true;
            return;
          }
        }
      }
    }
  }

  T operator[](int k){ return ds[k]; }

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


int r,c;
inline int to_v(int y,int x){
  return y*c+x;
}


int main() {
  cin>>r>>c;

  WarshallFloyd<int> G(r*c);

  vector<vector<int>> a(r,vector<int>(c));
  range(i,0,r) range(j,0,c-1){
    cin>>a[i][j];
  }

  vector<vector<int>> b(r,vector<int>(c));
  range(i,0,r-1) range(j,0,c){
    cin>>b[i][j];
  }

  range(i,0,r) range(j,0,c){
    int from = to_v(i,j);

    if(j+1<c){
      // cerr<<"i:"<<i<<" j:"<<j+1<<" v:"<<to_v(i,j+1)<<endl;
      // if(G.is_exist(from,to_v(i,j+1),a[i][j])) continue;
      G.add_edge(from,to_v(i,j+1),a[i][j]);
    }
    if(j-1>=0){
      // cerr<<"i:"<<i<<" j:"<<j-1<<" v:"<<to_v(i,j-1)<<endl;
      // if(G.is_exist(from,to_v(i,j-1),a[i][j-1])) continue;
      G.add_edge(from,to_v(i,j-1),a[i][j-1]);
    }
    if(i+1<r){
      // cerr<<"i:"<<i+1<<" j:"<<j<<" v:"<<to_v(i+1,j)<<endl;
      // if(G.is_exist(from,to_v(i+1,j),b[i][j])) continue;
      G.add_edge(from,to_v(i+1,j),b[i][j]);
    }
    
    range(k,1,i+1){
      // cerr<<"to("<<i-k<<","<<j<<"):"<<to_v(i-k,j)<<endl;
      // if(G.is_exist(from,to_v(i-k,j),1+k)) continue;
      G.add_edge(from,to_v(i-k,j),1+k);
    }
  }

  G.build(0);

  cout<<G[to_v(r-1,c-1)]<<endl;
}