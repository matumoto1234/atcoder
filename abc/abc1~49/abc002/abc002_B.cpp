#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string ans;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' ||
        s[i] == 'o') {
      continue;
    }
    ans += s[i];
  }
  cout << ans << endl;
  return 0;
}