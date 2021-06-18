#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
using ll = long long;
using LP = pair<ll, ll>;
using P = pair<int, int>;

template<typename T>
struct Dijkstra{
  struct Edge{
    int to;
    T cost;
    Edge(int to,T cost):to(to),cost(cost){}
    bool operator<(const Edge &o)const{return cost>o.cost;}
  };

  vector< vector<Edge> > G;
  vector<T> ds;
  vector<int> bs;
  Dijkstra(int n):G(n){}

  void add_edge(int u,int v,T c){
    G[u].emplace_back(v,c);
  }

  void build(int s){
    int n=G.size();
    ds.assign(n,inf());
    bs.assign(n,-1);

    priority_queue<Edge> pq;
    ds[s]=0;
    pq.emplace(s,ds[s]);
    bool flg=true;

    while(!pq.empty()){
      auto p=pq.top();pq.pop();
      int v=p.to;
      if(ds[v]<p.cost) continue;
      for(auto e:G[v]){
        if(ds[e.to]>ds[v]+e.cost){
          ds[e.to]=ds[v]+e.cost;
          bs[e.to]=v;
          pq.emplace(e.to,ds[e.to]);
        }
      }
      if(flg&&v==s){
        ds[v]=inf();
        flg=false;
      }
    }
  }

  T operator[](int k){return ds[k];}

  T inf(){ return numeric_limits<T>::max()/2; }

  vector<int> restore(int to){
    vector<int> res;
    if(bs[to]<0) return res;
    while(~to) res.emplace_back(to),to=bs[to];
    reverse(res.begin(),res.end());
    return res;
  }
};

ll solve(Dijkstra<ll> G,int s){
  G.build(s);
  return G[s];
}

int main() {
  int n,m;
  cin>>n>>m;
  Dijkstra<ll> G(n);
  const ll INF = INT64_MAX/2;
  vector<ll> cycle(n,G.inf());
  range(i,0,m){
    int a,b,c;
    cin>>a>>b>>c;
    a--;
    b--;
    if(a==b){
      chmin(cycle[a],c);
      continue;
    }
    G.add_edge(a,b,c);
  }
  range(i,0,n){
    ll ans=solve(G,i);
    chmin(ans,cycle[i]);
    if(ans==G.inf()){
      cout<<-1<<'\n';
    }else{
      cout<<ans<<'\n';
    }
  }
}