#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, max_ans = -1;
  cin >> n;
  vector<int> a(n);
  vector<int> list(100001, 0);
  vector<int> list2(100001, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    list[a[i]]++;
  }
  for (int i = 1; i < 100000; i++) {
    list2[i] = list[i - 1] + list[i] + list[i + 1];
    if(max_ans<list2[i]){
      max_ans = list2[i];
    }
  }
  cout << max_ans << endl;
  return 0;
}