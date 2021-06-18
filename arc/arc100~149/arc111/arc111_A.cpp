#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint.hpp>
using namespace atcoder;

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

using mint = modint;

ll mod_pow(ll a,ll e,ll p){
  if(e==0) return 1;
  if(e%2==0){
    ll res=mod_pow(a,e/2,p);
    return (res*res)%p;
  }
  ll res=mod_pow(a,e-1,p)*a;
  return res%p;
}

int main() {
  ll n,m;
  cin>>n>>m;
  ll c=mod_pow(10LL,n,m*m);
  cout<<(c/m)%m<<endl;
}