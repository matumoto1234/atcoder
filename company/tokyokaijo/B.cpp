#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, v, w, t;
  cin >> a >> v >> b >> w >> t;
  if (a < b) {
    long long int tmp1 = t * v + a;
    long long int tmp2 = t * w + b;
    if (tmp1 >= tmp2) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    long long int tmp1 = -1 * (t * v) + a;
    long long int tmp2 = -1 * (t * w) + b;
    if (tmp1 <= tmp2) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}