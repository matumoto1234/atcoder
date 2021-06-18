#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll search(ll n,ll s,ll t,ll cnt){
  if(s==t){
    return cnt;
  }
  if(n==1){
    return -1;
  }

  return search(n-1,s,t/2,cnt+1);
}

int main(){
  ll n,s,t;
  cin>>n>>s>>t;
  cout<<search(n,s,t,0)<<endl;
  return 0;
}