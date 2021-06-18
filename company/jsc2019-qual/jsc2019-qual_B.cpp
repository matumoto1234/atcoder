#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
const ll p = 1e9+7;

int main(){
  ll n,k;
  cin>>n>>k;
  vector<ll> a(n);
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  vector<vector<ll>> cnt(2,vector<ll>(n,0));

  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j){
        continue;
      }
      if(a[i]>a[j]){
        if(j<i){
          cnt[0][i]++;
        }else{
          cnt[0][i]++;
          cnt[1][i]++;
        }
      }
    }
  }
  ll ans=0;
  for(int i=0;i<n;i++){
    ans+=cnt[1][i]*k;
    ans%=p;
    ans+=cnt[0][i]*((k*(k-1)/2)%p);
    ans%=p;
    //cnt*(1+k)*k/2;
    //cnt*(1+k-1)*(k-1)/2;
  }
  cout<<ans<<endl;
  return 0;
}