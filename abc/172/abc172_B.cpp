#include <bits/stdc++.h>
using namespace std;
int main() {
  int ans = 0;
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < s.size();i++){
    if(s[i]!=t[i]){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}