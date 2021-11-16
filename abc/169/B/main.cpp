#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long int ans = 1;
  cin >> n;
  vector<long long int> a(n);

  for (int i = 0; i < n;i++){
    cin >> a[i];
    if(a[i]==0){
      cout << 0 << endl;
      return 0;
    }
    
  }
  for (int i = 0; i < n;i++){
    if (a[i] > 1000000000 && ans >= 1000000000) {
      cout << -1 << endl;
      return 0;
    }else if(a[i]>=1000000000&&ans>1000000000){
      cout << -1 << endl;
      return 0;
    }
    if (a[i] * ans > 1000000000000000000) {
      cout << -1 << endl;
      return 0;
    }
    ans *= a[i];
  }
    cout << ans << endl;
  return 0;
}