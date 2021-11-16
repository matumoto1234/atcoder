#include <algorithm>
#include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;

bool is_prime(ll x){
  for(ll i=2;i*i<=x;i++){
    if(x%i==0){
      return false;
    }
  }
  return true;
}

int main() {
  ll n;
  cin >> n;
  ll ans=1;
  for(ll i=n;i>=2;i--){
    if(ans%i!=0){
      ans*=i/__gcd(i,ans);
    }
  }
  ans++;
  for(ll i=2;i<=n;i++){
    if(ans%i!=1){
      cerr<<i<<endl;
    }
  }
  cout<<ans<<endl;
  return 0;
}