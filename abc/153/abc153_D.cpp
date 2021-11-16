#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll cnt = 0LL, a = 1LL;
  ll h;
  cin >> h;
  while (a <= h) {
    a *= 2LL;
    cnt++;
  }
  cout << a - 1LL<< endl;
  return 0;
}