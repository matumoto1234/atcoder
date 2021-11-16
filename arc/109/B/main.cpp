#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll n;
  cin>>n;
  ll ans=1;
  ll rem=n+1;
  for(ll i=1;i<=n;i++){
    rem-=i;
    if(rem<0){
      ans+=n-i+1;
      break;
    }
  }
  cout<<ans<<endl;
}