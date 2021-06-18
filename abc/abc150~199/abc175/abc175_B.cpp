#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  sort(a.begin(), a.end());
  for (ll i = 0; i < n; i++) {
    for (ll j = i + 1; j < n; j++) {
      if (i == j) {
        continue;
      }
      for (ll k = j + 1; k < n; k++) {
        if (a[i] == a[j] || a[j] == a[k] || a[i] == a[k]) {
          continue;
        }
        if (a[i] + a[j] > a[k] && a[i] + a[k] > a[j] && a[j] + a[k] > a[i]) {
          // printf("%lld %lld %lld\n",a[i],a[j],a[k]);
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}