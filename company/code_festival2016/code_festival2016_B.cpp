#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n;
  cin >> n;
  bitset<10000001> bit;
  ll sum = (2LL + n - 1) * n / 2;
  for (ll i = 1; i <= n;i++){
    bit.set(i);
  }
  for (ll i = n; i >= 1;i--){
    if(sum-i>=n){
      sum -= i;
      bit.reset(i);
    }
    //cout << sum << endl;
  }
  for (ll i = 1; i <= n;i++){
    if(bit[i]){
      cout << i << endl;
    }
  }
  return 0;
}