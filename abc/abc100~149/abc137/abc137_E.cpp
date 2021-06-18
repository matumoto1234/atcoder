#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using LP = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;

template <typename T>
struct BellmanFord{
  struct edge {
    int from,to;
    T cost;
    edge(){}
    edge(int f,int t,T c):from(f),to(t),cost(c){}
  };

  int V;
  vector<edge> es;
  vector<T> ds;

  BellmanFord(int N):V(N){}

  void add_edge(int from,int to,T cost){ es.emplace_back(from,to,cost); }

  T inf() { return numeric_limits<T>::max()/2; }

  // sから到達可能で、かつ終点へ到達可能な負閉路が検出されたときはtrue
  bool build(int s,int g){
    ds.assign(V,inf());
    ds[s]=0;

    for(int i=0;i<2*V;i++){
      for(edge e : es){
        if(ds[e.from]>=inf()) continue;
        if(ds[e.to]<=ds[e.from]+e.cost) continue;

        ds[e.to]=ds[e.from]+e.cost;
        if(i>=V-1) ds[e.to]=-inf();
        if(i>=V-1 && e.to==g) return true;
      }
    }
    return false;
  }

  T operator[](int k){ return ds[k]; }
};



int main() {
  int n,m,p;
  cin>>n>>m>>p;

  BellmanFord<ll> G(n);
  range(i,0,m){
    int a,b,c;
    cin>>a>>b>>c;
    a--;
    b--;
    c-=p;
    G.add_edge(a,b,-c);
  }

  bool isNegCycle=G.build(0,n-1);
  if(isNegCycle){
    cout<<-1<<endl;
    return 0;
  }

  cout<<max(0LL,-G[n-1])<<endl;
}