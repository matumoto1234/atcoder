#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n, ans = 0LL;
  cin >> n;
  vector<ll> a(n), list(200001LL, 0LL);
  for (ll i = 0LL; i < n;i++){
    cin >> a[i];
    if(a[i]>=100001LL){
      ans++;
      a.erase(a.begin()+i);
    }else{
      list[a[i]]++;
    }
  }
  sort(a.begin(), a.end());
  for (ll i = 1LL; i < 100001LL; i++) {
    if(list[i]>=i){
      ans += list[i] - i;
    }else{
      ans += list[i];
    }
  }
  cout << ans << endl;
  return 0;
}