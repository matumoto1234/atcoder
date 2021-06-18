#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> p(N);
  bitset<100000> bit;
  int cnt = 0;
  vector<vector<int>> dp(N + 1, vector<int>(101, 0));
  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= 100; j++) {
      if (j - p[i] >= 0) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j-p[i]] + p[i]);
      }
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
    }
  }
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= 10; j++) {
      bit.set(dp[i][j]);
      printf("%3d", dp[i][j]);
    }
    cout << endl;
  }
  for (int i = 0; i < 100000; i++) {
    if (bit[i]) {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}