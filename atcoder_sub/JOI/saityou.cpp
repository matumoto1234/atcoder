#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  bool flg = false;
  cin >> n >> k;
  vector<int> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    if(a[i]==0){
      flg = true;
    }
  }
  if(!flg){
    int cnt = 0, max = -1;
    sort(a.begin(), a.end());
    for (int i = 1; i < k; i++){
      if(a[i]-a[i-1]==1){
        cnt++;
      }else{
        if(max<cnt){
          max = cnt + 1;
        }
        cnt = 0;
      }
    }
    if (max < cnt) {
      max = cnt + 1;
    }
    cout << max << endl;
  }else{
    sort(a.begin(), a.end());
    
  }
  return 0;
}