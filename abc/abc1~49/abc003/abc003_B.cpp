#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool is_atcoder(char c){
  if(c=='a'||c=='t'||c=='c'||c=='o'||c=='d'||c=='e'||c=='r'){
    return true;
  }
  return false;

}

int main(){
  string s, t;
  cin >> s >> t;
  bool flg=true;
  for(int i=0;i<s.size();i++){
    if(s[i]==t[i]){
      continue;
    }
    if(s[i]=='@'&&is_atcoder(t[i])){
      continue;
    }
    if(t[i]=='@'&&is_atcoder(s[i])){
      continue;
    }
    flg=false;
    break;
  }
  if(flg){
    cout<<"You can win"<<endl;
  }else{
    cout<<"You will lose"<<endl;
  }
  return 0;
}