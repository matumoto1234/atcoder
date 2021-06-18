#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;

  vector<int> cnt(10,0);
  for(int i=0;i<s.size();i++){
    if(s[i]=='0'){
      continue;
    }
    cnt[s[i]-'0']++;
  }
  string t;
  for(int i=0;i<10;i++){
    int counter=0;
    while(cnt[i]&&counter<3){
      t.push_back('0'+i);
      counter++;
      cnt[i]--;
    }
  }
  bool flg=false;
  int n=t.size();
  if(n==1){
    for(int i=0;i<n;i++){
      if(stoi(t)%8==0){
        flg=true;
      }
    }
  }else if(n==2){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(i==j){
          continue;
        }
        string temp;
        temp.push_back(t[i]);
        temp.push_back(t[j]);
        if(stoi(temp)%8==0){
          flg=true;
          break;
        }
      }
    }
  }else{
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) {
          continue;
        }
        for (int k = 0; k < n; k++) {
          if (i == k || j == k) {
            continue;
          }
          string temp;
          temp.push_back(t[i]);
          temp.push_back(t[j]);
          temp.push_back(t[k]);
          if (stoi(temp) % 8 == 0) {
            flg = true;
            break;
          }
        }
        if (flg) {
          break;
        }
      }
      if (flg) {
        break;
      }
    }
  }
  cout<<(flg?"Yes":"No")<<endl;
  return 0;
}