#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, ans = 1;
  bool flg = false;
  cin >> x;
  for (int i = 1; i <= x; i++) {
    for (int j = 2; j < i; j++) {
      long double tmpi = i;
      flg = false;
      if (i % j == 0) {
        long double tmpj = (long double)j;
        while (1) {
          if (tmpi == tmpj) {
            //cout << tmpi << " " << tmpj << endl;
            flg = true;
            break;
          }
          tmpi /= tmpj;
          if (tmpi < tmpj) {
            flg = false;
            break;
          }
        }
      }
      if (flg) {
        if (ans < i) {
          ans = i;
          break;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}