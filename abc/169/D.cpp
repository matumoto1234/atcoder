#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
  ll n, cnt, ans, temp, line;
  cin >> n;
  temp = n;
  ans = 0;
  for (ll i = 2; i <= sqrtl(temp) + 1LL; i++) {
    line = 1;
    cnt = 0;
    while (n % i == 0) {
      cnt++;
      if (cnt >= line) {
        line++;
        cnt = 0;
        ans++;
      }
      n /= i;
    }
  }
  if (n > 1LL)
    ans++;
  cout << ans << endl;
  return 0;
}