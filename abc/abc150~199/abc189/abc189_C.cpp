#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 100100100100LL;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  vector<ll> b(n,0);
  for(int i=0;i<n;i++){
    ll minv=a[i];
    for(int j=i;j<n;j++){
      minv=min(a[j],minv);
      b[i]=max(b[i],minv*(j+1-i));
    }
  }
  ll ans=0;
  for(int i=0;i<n;i++){
    ans=max(ans,b[i]);
  }
  cout<<ans<<endl;
}