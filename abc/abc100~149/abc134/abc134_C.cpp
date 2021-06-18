#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> lm(n);
  vector<int> rm(n);

  for (int i = 1; i < n; i++) {
    lm[i] = max(lm[i - 1], a[i - 1]);
  }
  for (int i = n - 2; i >= 0; i--) {
    rm[i] = max(rm[i + 1], a[i + 1]);
  }

  for (int i = 0; i < n; i++) {
    cout << max(lm[i], rm[i]) << endl;
  }
  return 0;
}