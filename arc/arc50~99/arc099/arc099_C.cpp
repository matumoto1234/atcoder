#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n,k;
  cin>>n>>k;
  vector<ll> a(n);
  ll index;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]==1){
      index=i;
    }
  }
  ll ans;
  ans=index/(k-1);
  if(index%(k-1)!=0){
    ans++;
  }
  //cout<<ans<<endl;
  ans+=(n-1-index)/(k-1);
  if((n-1-index)%(k-1)!=0){
    ans++;
  }
  cout<<ans<<endl;
}