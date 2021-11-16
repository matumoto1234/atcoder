#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin>>n;
  vector<ll> a(n);
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  ll maxt=a[0];
  ll sum=0;
  for(ll i=1;i<n;i++){
    if(maxt>a[i]){
      sum+=maxt-a[i];
    }
    if(maxt<a[i]){
      maxt=a[i];
    }
  }
  cout<<sum<<endl;

  return 0;
}