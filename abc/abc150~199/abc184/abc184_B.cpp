#include <algorithm>
#include <iostream>
#include<string>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll n,x;
  string s;
  cin>>n>>x>>s;
  ll ans=x;
  for(int i=0;i<n;i++){
    if(s[i]=='o'){
      ans++;
    }else{
      ans--;
      if(ans<0){
        ans=0;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}