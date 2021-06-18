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
  int n;
  cin>>n;
  vector<int> s(n);
  range(i,0,n) cin>>s[i];

  vector<vector<bool>> dp(n+1,vector<bool>(20000,0));
  dp[0][0]=true;
  range(i,0,n){
    range(j,0,20000){
      if(dp[i][j]){
        dp[i+1][j]=true;
        dp[i+1][j+s[i]]=true;
      }
    }
  }

//  range(i,0,n+1) {
//    range(j,0,30){
//      cerr<<dp[i][j]<<' ';
//    }
//    cerr<<endl;
//  }

  rrange(j,0,20000){
    if(dp[n][j]){
      if(j%10==0 && j!=0) continue;
      cout<<j<<endl;
      return 0;
    }
  }
}