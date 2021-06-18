#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  vector<string> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    if (a[i] == m) {
      cout << b[i] << endl;
      return 0;
    }
    if (a[i] > m) {
      if (i) {
        cout << b[i - 1] << endl;
      } else {
        cout << "kogakubu10gokan" << endl;
      }
      return 0;
    }
  }
  cout<<b[n-1]<<endl;
  return 0;
}