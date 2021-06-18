#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, r, s, p;
  string t, str;
  cin >> n >> k >> r >> s >> p >> t;
  int ans = 0;
  for (int i = 0; i < k; i++) {
    switch (t[i]) {
      case 'r':
        ans += p;
        str.push_back('p');
        break;
      case 's':
        ans += r;
        str.push_back('r');
        break;
      case 'p':
        ans += s;
        str.push_back('s');
        break;
    }
  }
  cout << ans << endl;
  for (int i = k; i < n; i++) {
    int mae, usiro;
    switch (t[i]) {
      case 'r':
        mae = p;
        str.push_back('p');
        break;
      case 's':
        str.push_back('r');
        mae = r;
        break;
      case 'p':
        str.push_back('s');
        mae = s;
        break;
    }

    switch (t[i - k]) {
      case 'r':
        usiro = p;
        break;
      case 's':
        usiro = r;
        break;
      case 'p':
        usiro = s;
        break;
    }
    if(str[i]==str[i-k]){
      if(mae>usiro){
        ans -= usiro;
        ans += mae;
        str[i - k] = 'x';
      }else{
        ans += usiro;
        str[i] = 'o';
      }
    }else{
      ans += mae;
    }
  }
  cout << str << endl;
  cout << ans << endl;
  return 0;
}