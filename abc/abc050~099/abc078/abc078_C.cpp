#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll llpow(ll a,ll e){
  if(e==0){
    return 1LL;
  }
  return llpow(a,e-1)*a;
}
int main(){
  ll a,b;
  cin>>a>>b;
  ll x=b*1900+(a-b)*100;
  x*=llpow(2LL,b);
  cout<<x<<endl;

  return 0;
}