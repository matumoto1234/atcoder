#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  ll h,w;
  cin >> h>>w;
  ll n=h*w;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  ll ans=0;
  for(int i=1;i<n;i++){
    ans+=a[i]-a[0];
  }
  cout<<ans<<endl;
  return 0;
}