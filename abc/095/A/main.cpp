#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int ans=700;
  for(int i=0;i<3;i++){
    if(s[i]!='x'){
      ans+=100;
    }
  }
  cout<<ans<<endl;
}