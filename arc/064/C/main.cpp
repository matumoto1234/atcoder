#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, x;
  cin >> N >> x;
  vector<long long> a(N);
  for (long long i = 0; i < N; i++) {
    cin >> a[i];
  }
  long long count = 0;
  for (long long i = 0; i < N - 1; i++) {
    if (a[i] + a[i + 1] > x) {
      count += a[i] + a[i + 1] - x;
      a[i + 1] = x;
      a[i + 1] -= a[i];
      if (a[i + 1] < 0) {
        a[i + 1] = 0;
      }
    }
  }
  cout << count << endl;
  return 0;
}