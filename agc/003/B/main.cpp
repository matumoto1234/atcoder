#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n;
  cin>>n;
  vector<ll> a(n + 1, 0);
  for (int i = 0; i < n;i++){
    cin >> a[i];
  }
  ll ans = 0;
  for (ll i = 0; i < n;i++){
    ans += a[i] / 2;
    a[i] %= 2;
    if(a[i]>0&&a[i+1]>0){
      ans++;
      a[i + 1]--;
    }
  }
  cout << ans << endl;
  return 0;
}