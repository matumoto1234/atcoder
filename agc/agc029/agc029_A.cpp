#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll ans=0;
  string s;
  cin>>s;
  ll count=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='W'){
      ans+=i-count;
      count++;
    }
  }
  cout<<ans<<endl;
  return 0;
}