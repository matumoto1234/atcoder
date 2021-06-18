#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod_pow(ll a,ll e,ll p){
  if(e==0){
    return 1%p;
  }
  if(e%2LL==0){
    ll ret = mod_pow(a, e / 2LL, p) % p;
    return (ret * ret) % p;
  }else{
    return (mod_pow(a, e - 1, p) * a) % p;
  }
}

int main(){
  ll n, m, p;
  cin >> n >> m >> p;
  cout << mod_pow(n, p, m) << endl;
  return 0;
}