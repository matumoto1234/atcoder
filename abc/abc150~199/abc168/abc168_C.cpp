#include <bits/stdc++.h>
#define PI 3.14159265358979323846264338327
using namespace std;
using ld = long double;
int main() {
  cout << fixed << setprecision(15);
  ld a, b, h, m;
  ld rad, ans;
  cin >> a >> b >> h >> m;
  if (h == 0.0L && m == 0.0L) {
    cout << abs(a - b) << endl;
    return 0;
  }
  h = h * 30.0L + m * 0.5L;
  m = m * 6.0L;
  // cout << h  << m << endl;
  if (h - m > 180.0L) {
    rad = (m - h) * PI / 180.0L;
  } else {
    rad = (h - m) * PI / 180.0L;
  }
  // cout << rad << endl;
  ans = a * a + b * b - 2.0L * a * b * cosl(rad);
  cout << sqrtl(ans) << endl;
  return 0;
}