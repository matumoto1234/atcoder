#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll a, b;
  cin >> a >> b;
  for (int i = -1000; i <= 1000; i++) {
    for (int j = -1000; j <= 1000; j++) {
      if (i + j == a && i - j == b) {
        cout << i << ' ' << j << endl;
        return 0;
      }
    }
  }

  return 0;
}