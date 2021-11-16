#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

bool solve(ll x){
  while(x>0){
    if(x%10==7) return true;
    x/=10;
  }
  return false;
}

bool solve2(ll x){
  while(x>0){
    if(x%8==7) return true;
    x/=8;
  }
  return false;
}

int main() {
  ll n;
  cin >> n;
  ll ans=0;
  for(ll i=1;i<=n;i++){
    if(solve(i)||solve2(i)){
      ans++;
    }
  }
  cout<<n-ans<<endl;
  return 0;
}