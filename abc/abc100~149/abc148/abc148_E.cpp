#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll llpow(ll a, ll e){
  if(e==0){
    return 1LL;
  }
  if(e%2==0){
    ll res=llpow(a,e/2);
    return res*res;
  }else{
    return llpow(a,e-1)*a;
  }
}

int main(){
  ll n,ans=0;
  cin>>n;
  if(n%2==1){
    cout<<0<<endl;
    return 0;
  }
  ll temp,i=1;
  while(1){
    temp=llpow(5LL,i)*2;
    i++;
    if(temp>n){
      break;
    }
    ans+=n/temp;
  }
  cout<<ans<<endl;
  return 0;
}