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

struct UnionFind{
  int cnt;
  vector<int> siz,par;
  UnionFind(int N):cnt(N),siz(N,1),par(N){
    iota(par.begin(),par.end(),0);
  }

  int root(int x){
    if(x==par[x]) return x;
    return par[x]=root(par[x]);
  }

  int count(){ return cnt; }

  int size(int x){ return siz[root(x)]; }

  bool issame(int x,int y){ return root(x)==root(y); }

  void unite(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y) return;
    if(siz[x]<siz[y]) swap(x,y);
    siz[x]+=siz[y];
    par[y]=x;
    cnt--;
  }
};

int main() {
  int n,m;
  cin>>n>>m;

  UnionFind uf(n);

  range(i,0,m){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    uf.unite(a,b);
  }

  int ans=0;
  range(i,0,n){
    if(uf.issame(i,0)) continue;
    ans++;
    uf.unite(i,0);
  }
  cout<<ans<<endl;
}