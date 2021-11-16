#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll a,b;
  cin>>a>>b;
  ll idx=b-a;
  ll ans=0;
  for(ll i=1;i<=idx;i++) ans+=i;
  cout<<ans<<endl;
}