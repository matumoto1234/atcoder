#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  bool flg = false;
  for (int i = 0; i < s.size()-1;i++){
    for (int j = i + 1; j < s.size();j++) {
      if(s[i]==s[j]){
        flg = true;
      }
    }
  }
  if(!flg){
    cout << "yes" << endl;
  }else{
    cout << "no" << endl;
  }
  return 0;
}