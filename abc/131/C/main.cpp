#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll x, ll y) {
  if (y > x) {
    ll tmp = y;
    y = x;
    x = tmp;
  }
  if (x % y == 0) {
    return y;
  } else {
    return gcd(y, x % y);
  }
}

int main() {
  ll a, b, c, d, ans;
  ll tmpc1, tmpc2, tmpd1, tmpd2;
  ll tmpcd1, tmpcd2, cd;
  cin >> a >> b >> c >> d;
  ans = b - a + 1;
  cd = (c * d) / gcd(c, d);
  tmpcd1 = a / cd;
  if (a % cd == 0LL) {
    tmpcd1--;
  }
  tmpcd2 = b / cd;

  cd = tmpcd2 - tmpcd1;
  tmpc1 = a / c;
  if (a % c == 0LL) {
    tmpc1--;
  }
  tmpc2 = b / c;
  c = tmpc2 - tmpc1;
  tmpd1 = a / d;
  if (a % d == 0LL) {
    tmpd1--;
  }
  tmpd2 = b / d;
  d = tmpd2 - tmpd1;
  ans -= d + c;
  ans += cd;
  //cout << c << " " << d << " " << cd << endl;
  cout << ans << endl;
  return 0;
}