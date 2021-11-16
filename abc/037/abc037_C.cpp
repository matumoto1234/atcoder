#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<long long int> a(n), sum(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum[i + 1] = sum[i] + a[i];
  }

  long long int ans = 0;
  for (int i = k; i < n + 1; i++) {
    ans += sum[i] - sum[i - k];
  }
  cout << ans << endl;
  return 0;
}