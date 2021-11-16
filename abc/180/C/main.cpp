#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(ll n){
  vector<ll> a;
  for(ll i=1;i*i<=n;i++){
    if(n%i==0){
      cout<<i<<'\n';
      if(i!=n/i){
        a.push_back(n / i);
      }
    }
  }
  for(ll i=a.size()-1;i>=0;i--){
    cout<<a[i]<<'\n';
  }
}

int main() {
  ll n;
  cin >> n;
  solve(n);
  return 0;
}