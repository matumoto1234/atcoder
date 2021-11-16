#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  string s;
  cin>>s;

  ll ans=0;
  ll cntA=0;
  for(int i=0;i<s.size()-1;i++){
    if(s[i]=='A'){
      cntA++;
      continue;
    }
    if(s[i]=='B'&&s[i+1]=='C'){
      ans+=cntA;
      i++;
      continue;
    }
    cntA=0;
  }
  cout<<ans<<endl;
  return 0;
}