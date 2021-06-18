#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll p=1e9+7;
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll n;
  cin>>n;
  vector<ll> a(n);
  for(ll i=0;i<n;i++){
    cin>>a[n-1-i];
  }
  vector<ll> ruiseki(n+1,0);
  for(ll i=0;i<n;i++){
    ruiseki[i+1]=a[i]+ruiseki[i];
    ruiseki[i+1]%=p;
  }
  ll ans=0;
  for(ll i=0;i<n;i++){
    ans+=(ruiseki[i]*a[i])%p;
    ans%=p;
  }
  cout<<ans<<endl;
  return 0;
}