#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t, n;
  cin >> t;
  vector<ll> x(t, 0);
  vector<vector<ll>> a(t, vector<ll>(n));
  vector<string> s(t);
  for (int i = 0; i < t; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
    cin >> s[i];
    for (int j = 0; j < s[i].size(); j++) {
      if (s[i][j] == '0') {
        for (int k = 0; k < n; k++) {
          if (x[i] ^ a[i][k] == 0) {
            x[i] ^= a[i][k];
            break;
          }
        }
      } else {
        for (int k = 0; k < n; k++) {
          if (x[i] ^ a[i][k] != 0) {
            x[i] ^= a[i][k];
            break;
          }
        }
      }
      cout << x[i] << endl;
    }
    if (x[i] == 0) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
  }
  return 0;
}