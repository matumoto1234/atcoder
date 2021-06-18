#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n, money=1000;
  cin>>n;
  vector<ll> a(n+1,0);
  for (ll i = 0;i<n;i++){
    cin >> a[i];
  }
  ll kabu=0;
  for (ll i = 0; i < n;i++){
    if(a[i]<a[i+1]){
      kabu = money / a[i];
      money -= kabu * a[i];
      money += kabu * a[i + 1];
      kabu = 0;
    }
  }
  cout << money << endl;
  return 0;
}