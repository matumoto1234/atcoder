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
    int to, k;
    T cost;
    edge() {}
    edge(int to, T cost) : to(to), cost(cost){}
    edge(int to, T cost, int k) : to(to), cost(cost) ,k(k){}
    bool operator<(const edge &e) const { return cost > e.cost; }
  };

  T inf() { return numeric_limits<T>::max()/2; }

  vector<vector<edge>> G;
  vector<T> ds;
  vector<int> bs;
  Dijkstra(int n) : G(n) {}

  void add_edge(int from, int to, T cost, int k) { G[from].emplace_back(to, cost, k); }

  void build(int start) {
    int n = G.size();
    ds.assign(n, inf());
    bs.assign(n,-1);

    priority_queue<edge> Q;
    ds[start] = 0;
    Q.emplace(start, ds[start]);

    while (!Q.empty()) {
      auto p = Q.top();
      Q.pop();
      int v = p.to;
      if (ds[v] < p.cost) continue;
      for (auto e : G[v]) {
        if(ds[v] % e.k) e.cost += e.k - (ds[v]%e.k);

        if (ds[e.to] > ds[v] + e.cost) {
          ds[e.to] = ds[v] + e.cost;
          bs[e.to]=v;
          Q.emplace(e.to, ds[e.to]);
        }
      }
    }
  }

  T operator[](int k) { return ds[k]; }

  vector<int> restore(int to){
    vector<int> res;
    if(bs[to]==-1){
      res.emplace_back(to);
      return res;
    }
    while(to!=-1){
      res.emplace_back(to);
      to=bs[to];
    }
    reverse(res.begin(),res.end());
    return res;
  }
};

int main() {
  int n,m,x,y;
  cin>>n>>m>>x>>y;
  x--, y--;

  Dijkstra<ll> G(n);

  range(i,0,m){
    int a,b,t,k;
    cin>>a>>b>>t>>k;
    a--, b--;
    G.add_edge(a,b,t,k);
    G.add_edge(b,a,t,k);
  }

  G.build(x);

  ll ans=G[y];
  if(ans == G.inf()) ans=-1;
  cout<<ans<<endl;
}