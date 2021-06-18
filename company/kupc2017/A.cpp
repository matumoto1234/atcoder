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
  sort(a.rbegin(),a.rend());
  ll sum=0;
  ll ans=0;
  for(int i=0;i<n;i++){
    sum+=a[i];
    ans++;
    if(sum>=k){
      cout<<ans<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}