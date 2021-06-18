#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, cnt = 0;
  cin >> n >> s;
  vector<int> a(n), p(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < n;i++){
    for (int j = 0; j < n;j++){
      if(a[i]+p[j]==s){
        cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}