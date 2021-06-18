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

int main() {
  int n,m;
  cin>>n>>m;
  vector<vector<int>> G(n);
  range(i,0,m){
    int a,b;
    cin>>a>>b;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  int ma=0;
  int a=0,b=0,c=0;
  range(i,0,n) range(j,0,n) {
    range(k,0,n){
      if(i==j || j==k || i==k) continue;
      set<int> vs;
      vs.insert(i);
      vs.insert(j);
      vs.insert(k);
      for(int to:G[i]) vs.insert(to);
      for(int to:G[j]) vs.insert(to);
      for(int to:G[k]) vs.insert(to);
      if(ma<(int)vs.size()){
        a=i,b=j,c=k;
        ma=vs.size();
      }
    }
  }
  cerr<<ma<<endl;
  cout<<a<<' '<<b<<' '<<c<<endl;
}