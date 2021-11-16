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
using ld = long double;

template <typename T>
struct CumulativeSum{
  vector<T> sum;
  CumulativeSum(const vector<T> &a){
    int n=a.size();
    sum.assign(n+1,0);
    for(int i=0;i<n;i++) sum[i+1]=a[i]+sum[i];
  }

  T query(int l,int r){ return sum[r]-sum[l]; }
};

ld kitai(ll p){
  ll sum=(1+p)*p/2;
  return (ld)sum/(ld)p;
}

int main() {
  int n,k;
  cin>>n>>k;
  vector<ll> p(n);

  vector<ld> sum(n);
  range(i,0,n){
    cin>>p[i];
    sum[i]=kitai(p[i]);
  }

  CumulativeSum<ld> csum(sum);

  ld ans=-INF64;
  range(i,0,n){
    int l=i;
    int r=i+k;
    if(r>n) break;
    chmax(ans,csum.query(l,r));
  }

  cout<<fixed<<setprecision(10);
  cout<<ans<<endl;
}