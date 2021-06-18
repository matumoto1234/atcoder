#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint.hpp>
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

using mint = modint1000000007;

int main() {
  int n;
  cin>>n;
  string s;
  cin>>s;
  string t;
  cin>>t;

  vector<mint> dp(n,0);
  int start;
  bool last_is_tate;
  if(s[0]==t[0]){
    dp[0]=3;
    last_is_tate=true;
    start=1;
  }else{
    dp[1]=6;
    last_is_tate=false;
    start=2;
  }

  range(i,start,n){
    if(i+1<=n-1 && s[i]==s[i+1]){
      if(last_is_tate) dp[i+1]=dp[i-1]*2;
      else dp[i+1]=dp[i-1]*3;

      i++;
      last_is_tate=false;
    }else{
      if(last_is_tate) dp[i]=dp[i-1]*2;
      else dp[i]=dp[i-1];
      last_is_tate=true;
    }
  }
  cout<<dp[n-1].val()<<endl;
}