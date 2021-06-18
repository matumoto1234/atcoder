#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll absll(ll x) {
  if (x < 0) {
    return x * -1;
  } else {
    return x;
  }
}

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0) {
      b[i] = a[i];
    } else {
      b[i] = a[i] + b[i - 1];
    }
    sum += a[i];
  }
  ll mini = 0, minv = LLONG_MAX;
  for (int i = 0; i < n; i++) {
    if (minv > absll(b[i] - sum + b[i])) {
      minv = absll(b[i] - sum + b[i]);
      mini = i;
    }
    //cout << absll(b[i] - sum + b[i]) << endl;
  }
  cout << minv << endl;
  return 0;
}