#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n, k;
  cin >> n >> k;
  ll pulas_min = n % k;
  ll minasu_min = pulas_min - k;
  if (minasu_min < 0) {
    minasu_min *= -1LL;
  }
  cout << min(pulas_min, minasu_min) << endl;
  return 0;
}