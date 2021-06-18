#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  ll ans = 0LL;
  vector<ll> a(n);
  vector<ll> list(100001, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    list[a[i]]++;
  }
  for (int i = 0; i < 100001; i++) {
    ans += list[i] * i;
  }
  int q;
  cin >> q;
  vector<ll> b(q), c(q);
  for (int i = 0; i < q; i++) {
    cin >> b[i] >> c[i];
    ans -= list[b[i]] * b[i];
    ans -= list[c[i]] * c[i];
    list[c[i]] += list[b[i]];
    ans += list[c[i]] * c[i];
    list[b[i]] = 0;
    cout << ans << endl;
  }
  return 0;
}