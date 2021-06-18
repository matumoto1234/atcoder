#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint.hpp>

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

bool rangecheck(int y,int x,int h,int w){
  return 0<=y&&y<=h&&0<=x&&x<=w;
}

using mint = atcoder::modint1000000007;
class ModFactorial{
public:
  ModFactorial(int N):_fact(N+1),_invfact(N+1){
    _fact[0]=1;
    for(int i=1;i<=N;i++) _fact[i]=_fact[i-1]*i;
    _invfact[N]=1/_fact[N];
    for(int i=N-1;i>=0;i--) _invfact[i]=_invfact[i+1]*(i+1);
  }

  mint fact(int k){ return _fact[k]; }
  mint invfact(int k){ return _invfact[k]; }
  mint inv(int k){ return mint(k).inv(); }

  mint permutation(int n,int r){ return _fact[n]*_invfact[n-r]; }
  mint combination(int n,int r){ return _fact[n]*_invfact[r]*_invfact[n-r]; }
  mint homogeneous(int n,int r){ return combination(n+r-1,r); }

private:
  vector<mint> _fact,_invfact;
};

int main() {
  ll h,w,a,b;
  cin>>h>>w>>a>>b;
  h--;
  w--;

  ModFactorial num(h+w);
  mint ans=0;
  for(int y=h-a,x=b;rangecheck(y,x,h,w);y--,x++){
    mint v1=num.fact(y+x)*num.invfact(y)*num.invfact(x);
    mint v2=num.fact(h-y+w-x)*num.invfact(h-y)*num.invfact(w-x);
    ans+=v1*v2;
  }
  cout<<ans.val()<<endl;
}