#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int tmp;
  cin >> n;
  vector<int> cnt(n+1, 0);
  for (int i = 1; i <= 100;i++){
    for (int j = 1; j <= 100;j++){
      for (int k = 1; k <= 100;k++){
        tmp = i * i + j * j + k * k + i * j + j * k + k * i;
        if (tmp <= n) {
          cnt[tmp]++;
        }
      }
    }
  }
  for (int i = 1; i <= n;i++){
    cout << cnt[i] << endl;
  }
  return 0;
}