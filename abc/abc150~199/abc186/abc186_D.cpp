#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll sum=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
  }
  sort(a.rbegin(),a.rend());
  ll ans=0;
  ll sum2=0;
  for(ll i=0;i<n;i++){
    sum2+=a[i];
    ll v=(n-1-i)*a[i]-(sum-sum2);
    //cerr<<"v:"<<v<<endl;
    ans+=v;
  }
  cout<<ans<<endl;
  return 0;
}