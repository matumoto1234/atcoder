#include <bits/stdc++.h>
using namespace std;

#include<atcoder/math>
using namespace atcoder;

#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second<<'\n'; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

template <typename T>
T extgcd(T a,T b,T &x,T &y){
  if(b==0){
    x=1;
    y=0;
    return a;
  }
  T d=extgcd(b,a%b,y,x);
  y=y-(a/b)*x;
  return d;
}

// a%b
template <typename T>
int mod(T a,T b){
  return (a%b+b)%b;
}

int main() {
  int t;
  cin>>t;
  range(i,0,t){
    ll X,Y,P,Q;
    cin>>X>>Y>>P>>Q;

    ll a=2*X+2*Y;
    ll b=P+Q;
    ll d=gcd(a,b);

    ll ans=INF64;
    range(t1,X,X+Y) range(t2,P,P+Q){
      auto [x,lcm]=crt({t1,t2},{a,b});
      if(lcm==0) continue;
      chmin(ans,x);
    }
    if(ans==INF64) cout<<"infinity"<<newl;
    else cout<<ans<<newl;
  }
}