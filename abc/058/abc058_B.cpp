#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<string> s(2);
  cin >> s[0] >> s[1];
  for (int i = 0; i < s[0].size();i++){
    cout << s[0][i] << flush;
    if(s[1].size()==i){
      break;
    }
    cout << s[1][i] << flush;
  }
  cout << endl;
  return 0;
}