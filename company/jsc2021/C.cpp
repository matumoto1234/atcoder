#include <bits/stdc++.h>
using namespace std;

#include <atcoder/segtree.hpp>
using namespace atcoder;

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

vector<int> divisor(long long n){
  vector<int> res;
  for(long long i=1;i*i<=n;i++){
    if(n%i==0){
      res.emplace_back(i);
      if(i*i!=n) res.emplace_back(n/i);
    }
  }
  sort(res.begin(),res.end());
  return res;
}

int main() {
  int a,b;
  cin>>a>>b;

  int ans=1;
  rrange(i,a,b+1){
    auto ds=divisor(i);
    rrange(j,0,ds.size()){
      for(int k=i-ds[j];k>=a;k-=ds[j]){
        chmax(ans,gcd(i,k));
        break;
      }
    }
  }
  cout<<ans<<endl;
}