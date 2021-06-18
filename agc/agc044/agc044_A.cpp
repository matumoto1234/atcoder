#include <bits/stdc++.h>
#define loop(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  ll t, n, a, b, c, d, ans, x;
  vector<int> soi(sqrt(n));

  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> a >> b >> c >> d;
    ans = x = 0;
    ans += d;
    x++;
    ll unko1, unko2, true_unko;
    unko1 = unko2 = n;
		
    while (1) {
      ll mod = 2;
      if (true_unko % mod != 0 && mod == 5) {
        break;
      } else if (true_unko % mod != 0) {
        mod++;
      } else {
        true_unko /= mod;
        soi.emplace_back(mod);
      }
    }
  }
  cout << n << endl;
  return 0;
}