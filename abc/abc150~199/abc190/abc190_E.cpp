#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
using ll = long long;
using LP = pair<ll, ll>;
using P = pair<int, int>;
const ll INF = INT64_MAX / 2LL;
const int inf = INT32_MAX / 2;

// 全頂点を1度だけ訪問したときの最短経路距離
// buildでinfinity()が帰ってきたらそのような経路はない
template <typename T>
class shortestHamiltonPath{
private:
  struct edge{
    int to;
    T cost;
    edge(int to,T cost):to(to),cost(cost){}
  };

  int V;
  vector<vector<edge>> G;
  vector<vector<T>> dp;

  T dfs(int v,int Set){
    T &res=dp[v][Set];
    if(Set+1==1<<V) res=0;
    if(res!=-1) return res;
    res=infinity();
    for(auto [to,cost]:G[v]){
      int bit=1<<to;
      if(Set&bit) continue;
      res=min(res,dfs(to,Set|bit)+cost);
    }
    return res;
  }

public:
  shortestHamiltonPath(int V_):V(V_),G(V_){}

  T infinity(){ return numeric_limits<T>::max() / 2; }

  void add_edge(int from,int to,T cost){ G[from].emplace_back(to,cost); }

  T build(){
    T res=infinity();
    dp.assign(V,vector<T>(1<<V,-1));
    for(int sv=0;sv<V;sv++){
      res=min(res,dfs(sv,1<<sv));
    }
    return res;
  }
};

int main() {
  int n,m;
  cin>>n>>m;
  vector<vector<ll>> G(n);
  range(i,0,m){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int k;
  cin>>k;
  vector<int> c(k);
  range(i,0,k){
    cin>>c[i];
    c[i]--;
  }

  vector<vector<ll>> ds(k,vector<ll>(k));
  range(i,0,k){
    int sv=c[i];
    vector<ll> dist(n,INF);
    dist[sv]=0;
    queue<ll> q;
    q.push(sv);
    while(!q.empty()){
      ll v=q.front();
      q.pop();
      for(auto to:G[v]){
        if(dist[to]!=INF) continue;
        dist[to]=dist[v]+1;
        q.push(to);
      }
    }
    
    range(j,0,k){
      ds[i][j]=dist[c[j]];
    }
  }

  shortestHamiltonPath<ll> hp(k);
  range(i,0,k){
    range(j,0,k){
      hp.add_edge(i,j,ds[i][j]);
    }
  }

  ll ans=hp.build();
  if(ans==hp.infinity()){
    cout<<-1<<endl;
  }else{
    cout<<ans+1<<endl;
  }
}