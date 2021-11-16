#include <bits/stdc++.h>
#include <atcoder/fenwicktree.hpp>
using namespace atcoder;
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

void naive(int n,int k){
  range(a,1,n+1){
    range(b,1,n+1){
      range(c,1,n+1){
        if((a+b)%k==0 && (b+c)%k==0 && (a+c)%k==0){
          cerr<<a<<' '<<b<<' '<<c<<endl;
        }
      }
    }
  }
}

template <typename T1,typename T2>
T1 Pow(T1 a,T2 e){
  if(e==0) return 1;
  if(e%2==0){
    T1 res=Pow(a,e/2);
    return res*res;
  }
  return Pow(a,e-1)*a;
}

int main() {
  int n,k;
  cin>>n>>k;


  ll ans;
  if(k%2==0){
    ans=Pow((ll)(n/(k/2) - n/k),3);
    ans+=Pow((ll)(n/k),3);
  }else{
    ans=Pow((ll)(n/k),3);
  }
  cout<<ans<<endl;
}