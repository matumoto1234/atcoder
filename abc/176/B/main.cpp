#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  long long sum = 0;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    sum += s[i] - '0';
  }
  if (sum % 9 == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}