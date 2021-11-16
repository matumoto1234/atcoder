#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll ans = 0LL;
  for (ll i = 0LL; i < n; i++) {
    cin >> a[i];
    while (a[i] % 2LL == 0) {
      ans++;
      a[i] /= 2LL;
    }
  }
  cout << ans << endl;
  return 0;
}