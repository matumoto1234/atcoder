#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define P 1000000007

int main() {
  ll n, k, ans = 1;
  ll pi = 0, mi = 0, cnt = 0;
  cin >> n >> k;
  vector<ll> a(n), p, m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] >= 0) {
      p.push_back(a[i]);
    } else {
      m.push_back(a[i]);
    }
  }
  sort(p.begin(), p.end(), greater<ll>());
  sort(m.begin(), m.end());
  while (cnt < k) {
    if (m.size() - mi <= 1) {
      if (pi >= p.size()) {
        break;
      } else {
        while (cnt < k || pi < p.size()) {
          cnt++;
          ans *= p[pi++];
          ans %= P;
        }
        break;
      }
    }
    if (pi >= p.size()) {
      while (cnt < k || m.size() - mi <= 1) {
        cnt += 2;
        ans *= (m[mi] * m[mi + 1]);
        ans %= P;
      }
      break;
    }
    if (m[mi] * m[mi + 1] > p[pi]) {
      cnt += 2;
      ans *= (m[mi] * m[mi + 1]);
      ans %= P;
      mi += 2;
    } else {
      cnt++;
      ans *= p[pi];
      ans %= P;
      pi++;
    }
  }
  cout << ans << endl;
  return 0;
}