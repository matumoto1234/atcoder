#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans, sum = 0;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sum += abs(a[0]);
  for (int i = 0; i < n - 1; i++) {
    b[i] = abs(a[i] - a[i + 1]);
    sum += b[i];
  }
  sum += abs(a[n - 1]);
  //cout << "--------"<<sum << endl;
  int tmp;
  for (int i = 0; i < n; i++) {
    tmp = sum;
    if(i==0){
      tmp -= abs(a[0]);
      tmp -= abs(a[0] - a[1]);
      tmp += abs(a[1]);
    }else if(i<n-1){
      tmp -= abs(a[i] - a[i + 1]);
      tmp -= abs(a[i] - a[i - 1]);
      tmp += abs(a[i - 1] - a[i + 1]);
    }else{
      tmp -= abs(a[n - 1]);
      tmp -= abs(a[n - 1] - a[n - 2]);
      tmp += abs(a[n - 2]);
    }
    cout << tmp << endl;
  }
  return 0;
}