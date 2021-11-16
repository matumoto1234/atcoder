#include<iostream>
#include<queue>
#include<vector>
#include<cctype>
using namespace std;
using ll = long long;

template <typename T> struct Dijkstra {
  struct edge {
    int to;
    T cost;

    edge() {}

    edge(int to, T cost) : to(to), cost(cost) {}
    bool operator<(const edge &e) const { return cost > e.cost; }
  };

  T inf() { return numeric_limits<T>::max(); }

  vector<vector<edge>> G;
  vector<T> ds;
  Dijkstra(int n) : G(n) {}

  void add_edge(int from, int to, T cost) { G[from].emplace_back(to, cost); }

  void build(int start) {
    int n = G.size();
    ds.assign(n, inf());

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
          Q.emplace(e.to, ds[e.to]);
        }
      }
    }
  }

  T operator[](int k) { return ds[k]; }
};

void solve(){

}

int main(){
  int h,w;
  cin>>h>>w;

  vector<vector<char>> str(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>str[i][j];
    }
  }

  auto to_v = [&](int y,int x){
    return y*w+x;
  };

  auto inside = [&](int y,int x){
    return (0<=y&&y<h&&0<=x&&x<w);
  };

  int dy[]={0,1,0,-1};
  int dx[]={1,0,-1,0};
  int sz=h*w+26;
  int s,g;
  Dijkstra<int> G(sz);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(str[i][j]=='#') continue;

      int v=to_v(i,j);

      if(str[i][j]=='S'){
        s=v;
      }
      if(str[i][j]=='G'){
        g=v;
      }
      if(islower(str[i][j])){
        int u=str[i][j]-'a'+h*w;
        G.add_edge(u,v,0);
        G.add_edge(v,u,1);
      }

      for(int k=0;k<4;k++){
        int y=i+dy[k];
        int x=j+dx[k];
        if(!inside(y,x)) continue;
        if(str[y][x]=='#') continue;
        G.add_edge(v,to_v(y,x),1);
      }
    }
  }

  G.build(s);

  int ans=G[g];
  if(ans==G.inf()) ans=-1;

  cout<<ans<<endl;

  return 0;
}