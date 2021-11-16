#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  string s;
  cin>>s;
  ll sum=2*(s.size()-1);
  for(int i=1;i<s.size()-1;i++){
    if(s[i]=='U'){
      sum+=(s.size()-i-1);
      sum+=2*i;
    }else{
      sum+=2*(s.size()-i-1);
      sum+=i;
    }
  }
  cout<<sum<<endl;
  return 0;
}