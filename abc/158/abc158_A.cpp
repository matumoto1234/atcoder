#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  bool flg=false;
  for(int i=1;i<3;i++){
    if(s[i]!=s[i-1]){
      flg=true;
    }
  }
  cout<<(flg?"Yes":"No")<<endl;
  return 0;
}