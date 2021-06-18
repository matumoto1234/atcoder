#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
const ll MAXV = 100000;
const ll INF = INT64_MAX/2LL;

template <typename T1,typename T2>
void chmin(T1& a,T2 b){
  if(a>b){
    a=b;
  }
}

int main(){
  ll N,W;
  cin>>N>>W;

  vector<vector<ll>> dp(N,vector<ll>(MAXV+1,INF));
  vector<ll> w(N),v(N);
  for(ll i=0;i<N;i++){
    cin>>w[i]>>v[i];
    chmin(dp[i][v[i]],w[i]);
  }

  for(ll i=1;i<N;i++){
    for(ll j=0;j<=MAXV;j++){
      chmin(dp[i][j],dp[i-1][j]);
      if(j>=v[i]){
        chmin(dp[i][j],dp[i-1][j-v[i]]+w[i]);
      }
    }
  }

  ll ans=-1LL;
  for(ll j=MAXV;j>=0;j--){
    for(ll i=0;i<N;i++){
      if(dp[i][j]<=W){
        ans=j;
        //cerr<<"dp[i][j]:"<<dp[i][j]<<endl;
        break;
      }
    }
    if(ans!=-1) break;
  }

  cout<<ans<<endl;
  return 0;
}