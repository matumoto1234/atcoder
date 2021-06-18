#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll ans = 0;
  vector<ll> a(5);
  for (int i = 0; i < 5; i++) {
    cin >> a[i];
  }

  // 5*5*5
  ans += a[4];
  a[4] = 0;

  // 4*4*4
  ans += a[3];
  a[0] -= min(a[3] * 61LL, a[0]);
  a[3] = 0;

  // 3*3*3
  ans += a[2];
  ll temp = a[2];
  a[2] = 0;

  a[1] -= temp * 7;
  if (a[1] < 0) {
    a[1] *= -1;

    a[0] -= (a[1] / 7) * 98;
    if (a[1] % 7 != 0) {
      a[0] -= (125 - 27) - (7 - a[1] % 7) * 8;
    }
    a[1] = 0;
  }

  // 2*2*2
  ll amari = a[1] % 8;
  ans += a[1] / 8;
  a[0] -= (a[1] / 8) * 61;

  if (amari > 0) {
    ans++;
    a[0] -= 125 - amari * 8;
  }
  a[1] = 0;

  // 1*1*1
  ans += max(a[0], 0LL);

  /*for(int i=0;i<5;i++){
    if(i){
      cout<<' ';
    }
    cout<<a[i];
  }
  cout<<endl;
  */

  cout << ans << endl;
  return 0;
}