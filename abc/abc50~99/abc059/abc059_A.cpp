#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
int main() {
  string a, b, c;
  cin >> a >> b >> c;
  transform(a.begin(), a.end(), a.begin(), ::toupper);
  transform(b.begin(), b.end(), b.begin(), ::toupper);
  transform(c.begin(), c.end(), c.begin(), ::toupper);
  cout << a[0] << b[0] << c[0] << endl;
  return 0;
}