#include <bits/stdc++.h>
using namespace std;
int main() {
  double n;
  cin >> n;
  n /= 100;
  if ( n < 1 ) {
    cout << "00" << endl;
    return 0;
  }
  if ( n <= 50 ) {
    if ( n < 10 ) {
      cout << 0 << n << endl;
      return 0;
    }
    cout << n << endl;
    return 0;
  }
  if ( n <= 300 ) {
    n /= 10;
    cout << n + 50 << endl;
    return 0;
  }
  if ( n <= 700 ) {
    n /= 10;
    n -= 30;
    n /= 5.0;
    n += 80;
    cout << n << endl;
    return 0;
  }
  cout << 89 << endl;
  return 0;
}