#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll p = 1e9+7;

ll llmodpow(ll a,ll e){
  if(e==0){
    return 1LL;
  }
  if(e%2==0){
    ll ret=llmodpow(a,e/2);
    ret%=p;
    return (ret*ret)%p;
  }else{
    ll ret=a*llmodpow(a,e-1);
    ret%=p;
    return ret;
  }
}

int main(){
  ll n;
  cin>>n;
  ll ans;
  ans=llmodpow(10LL,n)-2*llmodpow(9LL,n)+llmodpow(8LL,n);
  ans%=p;
  ans=(ans+p)%p;
  cout<<ans<<endl;
  return 0;
}