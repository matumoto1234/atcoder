#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  cin>>s>>t;
  int index=0;
  bool flg=false;
  for(int i=0;i<s.size();i++){
    if(s[i]==t[0]||s[i]=='?'){
      for(int j=0;j<t.size();j++){
        if(s[i+j]!='?'&&s[i+j]!=t[j]){
          break;
        }
        if(j==t.size()-1){
          flg=true;
          index=i;
        }
      }
    }
  }
  if(!flg){
    cout<<"UNRESTORABLE"<<endl;
    return 0;
  }
  for(int i=0;i<s.size();i++){
    if(s[i]!='?'){
      cout<<s[i];
      continue;
    }
    if(i<index){
      cout<<'a';
    }else if(index<=i&&i<index+t.size()){
      cout<<t[i-index];
    }else{
      cout<<'a';
    }
  }
  cout<<endl;
  return 0;
}