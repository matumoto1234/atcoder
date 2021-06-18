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
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

bool solve(ll a,ll b,ll c){
  range(i,0,60){
    bool ai=a>>i&1;
    bool bi=b>>i&1;
    bool ci=c>>i&1;
    if(!ai){
      if(bi||ci) return false;
    }
    if(bi){
      if(ai==false||ci) return false;
    }
  }
  return true;
}

int main() {
  int t;
  cin>>t;

  range(i,0,t){
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<(solve(a,b,c)?"Yes":"No")<<newl;
  }
}