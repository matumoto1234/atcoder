#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, sum;
  vector<int> v(10000, 0);
  cin >> a >> b >> c;
  sum = a;
  while (1) {
    if (v[sum % b] == 1) {
      cout << "NO" << endl;
      break;
    }
    if (sum % b == c) {
      cout << "YES" << endl;
      break;
    } else {
      v[sum % b]++;
    }
    sum += a;
  }
  return 0;
}