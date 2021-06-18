#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
const ll MAXW = 100000;

template <typename T1,typename T2>
void chmax(T1& a,T2 b){
  if(a<b){
    a=b;
  }
}

int main(){
  ll N,W;
  cin>>N>>W;

  vector<vector<ll>> dp(N,vector<ll>(MAXW+1,0LL));
  vector<ll> w(N),v(N);
  for(ll i=0;i<N;i++){
    cin>>w[i]>>v[i];
    dp[i][w[i]]=v[i];
  }

  for(ll j=0;j<=MAXW;j++){
    for(ll i=1;i<N;i++){
      chmax(dp[i][j],dp[i-1][j]);
      if(j>=w[i]){
        chmax(dp[i][j],dp[i-1][j-w[i]]+v[i]);
      }
    }
  }

  ll ans=0;
  for(ll j=0;j<=W;j++){
    chmax(ans,dp[N-1][j]);
  }
  cout<<ans<<endl;
  return 0;
}