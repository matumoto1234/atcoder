#include<iostream>
#include<string>
using namespace std;

int main(){
  string s;
  getline(cin,s);
  
  int n=(int)s.size();
  bool is_continuous=false;
  for(int i=0;i<n;i++){
    if(s[i]!=' '){
      cout<<s[i];
      is_continuous=false;
      continue;
    }
    if(is_continuous){
      continue;
    }
    cout<<',';
    is_continuous=true;
  }
  cout<<'\n';
  return 0;
}