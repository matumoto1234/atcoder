#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, a, b, c, d;
  string s;
  bool rock = false;
  bool ans = false;
  cin >> n >> a >> b >> c >> d >> s;

  a--;
  b--;
  c--;
  d--;
  if(c>d){
    bool exchange = false;
    for (int i = b; i <= d;i++){
      if(s[i]=='.'){
        if(s[i-1]=='.'&&s[i+1]=='.'){
          exchange = true;
        }
      }
    }
    for (int i = a; i <= c;i++){
      if(s[i]=='#'&&s[i+1]=='#'){
        rock = true;
      }
    }
    if(rock){
      ans = false;
    }else{
      ans = exchange;
    }
  }else {
    for (int i = a; i <= c;i++){
      if(s[i]=='#'&&s[i+1]=='#'){
        rock = true;
      }
    }
    for (int i = b; i <= d;i++){
      if(s[i]=='#'&&s[i+1]=='#'){
        rock = true;
      }
    }
    ans = !(rock);
  }
  if(ans){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}