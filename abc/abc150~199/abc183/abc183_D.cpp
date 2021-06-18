#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  ll n,w;
  cin >> n>>w;
  vector<ll> status(2e5+1,0);
  for(int i=0;i<n;i++){
    ll s,t,p;
    cin>>s>>t>>p;
    status[s]+=p;
    status[min((ll)2e5+1,t)]-=p;
  }
  for(int i=1;i<2e5+1;i++){
    status[i]+=status[i-1];
  }
  bool flg=true;
  for(int i=0;i<2e5+1;i++){
    if(status[i]>w){
      flg=false;
      break;
    }
  }
  cout<<(flg?"Yes":"No")<<endl;
  return 0;
}