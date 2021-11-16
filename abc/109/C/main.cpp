#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n,x;
  cin>>n>>x;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    a[i]=abs(x-a[i]);
  }
  ll ans=a[0];
  for(int i=1;i<n;i++){
    ans=__gcd(ans,a[i]);
  }
  cout<<ans<<endl;
}