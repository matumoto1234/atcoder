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

template <typename T1,typename T2>
T1 mod(T1 a,T2 m){
  T1 res=a%m;
  if(res<0) res+=m;
  return res;
}

int main(){
  int n;
  string s,x;
  cin>>n>>s>>x;

  const int num[]={0,5,3,1,6,4,2};
  vector<vector<bool>> dp(n+1,vector<bool>(7,false));
  dp[n][0]=true;

  rrange(i,0,n) range(j,0,7){
    if(x[i]=='T'){
      if(!dp[i+1][j]) continue;

      dp[i][num[j]]=true;
      int v=j-(s[i]-'0');
      v=mod(v,7);
      dp[i][num[v]]=true;
    }
    if(x[i]=='A'){
      int v=(10*j)%7;
      int use=s[i]-'0';
      if(dp[i+1][v] && dp[i+1][(v+use)%7]) dp[i][j]=true;
    }
  }
  if(dp[0][0]) cout<<"Takahashi"<<endl;
  else cout<<"Aoki"<<endl;
}