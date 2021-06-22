#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n,k;
  cin>>n>>k;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  ll ans;
  ans=(n-1)/(k-1);
  if((n-1)%(k-1)){
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}