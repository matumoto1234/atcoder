#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

template <typename T> struct Dijkstra {
  struct Edge {
    int to;
    T cost;
    Edge(int to, T cost) : to(to), cost(cost) {}
    bool operator<(const Edge &o) const { return cost > o.cost; }
  };

  vector<vector<Edge>> G;
  vector<T> ds;
  vector<int> bs;
  Dijkstra(int n) : G(n) {}

  void add_edge(int u, int v, T c) { G[u].emplace_back(v, c); }

  T inf(){return numeric_limits<T>::max();}

  void build(int s) {
    int n = G.size();
    ds.assign(n, inf());
    bs.assign(n, -1);

    priority_queue<Edge> pq;
    ds[s] = 0;
    pq.emplace(s, ds[s]);

    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      int v = p.to;
      if (ds[v] < p.cost)
        continue;
      for (auto e : G[v]) {
        if (ds[e.to] > ds[v] + e.cost) {
          ds[e.to] = ds[v] + e.cost;
          bs[e.to] = v;
          pq.emplace(e.to, ds[e.to]);
        }
      }
    }
  }

  T operator[](int k) { return ds[k]; }

  vector<int> restore(int to) {
    vector<int> res;
    if (bs[to] < 0)
      return res;
    while (~to)
      res.emplace_back(to), to = bs[to];
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  int N, M, T;
  cin >> N >> M >> T;

  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  Dijkstra<ll> G(N);
  Dijkstra<ll> G2(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--;
    b--;
    G.add_edge(a, b, c);
    G2.add_edge(b, a, c);
  }
  G.build(0);
  G2.build(0);

  ll ans = 0;
  for (int i = 0; i < N; i++) {
    if(G[i]==G.inf()||G2[i]==G2.inf()){
      continue;
    }
    ll time = T - (G[i] + G2[i]);
    ans = max(ans, time * A[i]);
  }
  cout << ans << endl;
  return 0;
}