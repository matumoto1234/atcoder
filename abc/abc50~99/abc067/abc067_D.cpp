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
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

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
  vector<int> bs;
  Dijkstra(int n) : G(n) {}

  void add_edge(int from, int to, T cost) { G[from].emplace_back(to, cost); }

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

      if (ds[v] < p.cost)
        continue;

      for (auto e : G[v]) {
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
    if(bs[to]<0){
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

vector<bool> used;
vector<vector<int>> G2;
ll dfs(int idx,set<int> &vs){
  ll res=1;
  used[idx]=true;
  for(int to:G2[idx]){
    if(used[to]) continue;
    if(vs.find(to)!=vs.end()) continue;
    res+=dfs(to,vs);
  }
  return res;
}

int main() {
  int n;
  cin>>n;

  Dijkstra<ll> G(n);
  G2.resize(n);
  range(i,0,n-1){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    G.add_edge(a,b,1);
    G.add_edge(b,a,1);
    G2[a].emplace_back(b);
    G2[b].emplace_back(a);
  }

  G.build(0);
  int between=G[n-1]-1;
  vector<int> path = G.restore(n-1);
  set<int> black,white;
  range(i,0,path.size()){
    if(i<(path.size()+(2-1))/2){
      black.insert(path[i]);
    }else{
      white.insert(path[i]);
    }
  }

  int fen_num=0;
  used.assign(n,false);
  for(int s:black){
    if(!used[s]) fen_num+=dfs(s,white);
  }
  
  int snu_num=0;
  used.assign(n,false);
  for(int s:white){
    if(!used[s]) snu_num+=dfs(s,black);
  }

  //cerr<<"fen:"<<fen_num<<" snu:"<<snu_num<<endl;

  string f="Fennec",s="Snuke";
  if(fen_num>snu_num) cout<<f<<endl;
  else cout<<s<<endl;
}