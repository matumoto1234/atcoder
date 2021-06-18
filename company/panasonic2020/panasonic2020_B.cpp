#include<iostream>
using namespace std;
using ll = long long;
int main(){
  ll h,w;
  cin>>h>>w;
  if(h==1||w==1){
    cout<<1<<endl;
    return 0;
  }
  ll ans=h*w/2;
  if(h*w%2){
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}