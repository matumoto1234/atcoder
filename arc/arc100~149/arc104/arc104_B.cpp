#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isTrue(char l, char r) {
  if (l > r) {
    char c = l;
    l = r;
    r = c;
  }
  if (l == 'A' && r == 'T') {
    return true;
  } else if (l == 'C' && r == 'G') {
    return true;
  }
  return false;
}

ll solve(int n, string& s, int l, int r) {
  ll sum = 0;
  if (l < 0 || r >= n) {
    return 0LL;
  }
  if (isTrue(s[l], s[r]) == false) {
    return 0LL;
  }
  sum++;
  return sum + solve(n, s, l - 1, r + 1);
}

int main() {
  int n;
  string s;
  cin >> n >> s;

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += solve(n, s, i, i + 1);
  }
  cout << ans << endl;
  return 0;
}
