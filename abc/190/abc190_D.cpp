#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main(){
  ll n;
  cin>>n;
  ll ans=0;
  ll sum=0;
  for(ll len=1;len<=n;len++){
    sum+=len;
    if(n-sum<0) break;
    if((n-sum)%len==0) ans+=2;
  }
  cout<<ans<<endl;
}