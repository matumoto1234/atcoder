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
constexpr char newl = '\n';

int main() {
  int n,m;
  cin>>n>>m;
  vector<P> ab(n);
  range(i,0,n){
    auto &[a,b]=ab[i];
    cin>>a>>b;
  }

  vector<P> cd(m);
  range(i,0,m){
    auto &[c,d]=cd[i];
    cin>>c>>d;
  }

  range(i,0,n){
    int mi=0,v=INF32;
    auto [a,b]=ab[i];
    range(j,0,m){
      auto [c,d]=cd[j];
      if(abs(a-c)+abs(b-d)<v){
        v=abs(a-c)+abs(b-d);
        mi=j;
      }
    }
    cout<<mi+1<<newl;
  }
}