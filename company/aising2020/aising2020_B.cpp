#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n;i++){
    cin >> a[i];
    if((i+1)%2!=0&&a[i]%2!=0){
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}