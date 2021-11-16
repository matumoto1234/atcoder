#include<bits/stdc++.h>
using namespace std;
int main(){
  int flg = 0;
  vector<string> s(3);
  cin >> s[0] >> s[1] >> s[2];
  int i = 0;
  while (1){
    if(s[0].empty()&&i==0){
      flg = 0;
      break;
    }
    if(s[1].empty()&&i==1){
      flg = 1;
      break;
    }
    if(s[2].empty()&&i==2){
      flg = 2;
      break;
    }
    int tmp = i;
    i = s[i].front() - 'a';
    s[tmp].erase(0, 1);
    //cout << "----" + s[0] << endl << s[1] << endl << s[2] << endl;
  }
  if(flg==0){
    cout << "A" << endl;
  }else if(flg==1){
    cout << "B" << endl;
  }else{
    cout << "C" << endl;
  }
  return 0;
}