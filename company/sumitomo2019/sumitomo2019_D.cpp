#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, vi, ans = 0;
  bool flg;
  string s, v(3,'0');
  cin >> n >> s;
  for (int i = 0; i < 1000;i++){
    v[0] = i / 100 + '0';
    v[1] = i % 100 / 10 + '0';
    v[2] = i % 10 + '0';
    vi = 0;
    flg = false;
    for (int j = 0; j < n;j++){
      if(s[j]==v[vi]){
        vi++;
        if(vi>=3){
          flg = true;
          break;
        }
      }
    }
    if(flg){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}