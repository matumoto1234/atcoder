#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, tmp;
  int flg = 0;
  cin >> n;
  vector<int> a(n);
  vector<int> prime(1000001,1);
  bitset<1000001> prime_num;
  prime_num.set();
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i]==1){
      if(flg==0){
        flg++;
      }else{
        cout << 0 << endl;
        return 0;
      }
    }
    if (prime_num[a[i]]) {
      prime[a[i]]++;
      tmp = a[i];
      for (int j = tmp * 2; j < 1000001; j += tmp) {
        prime_num.reset(j);
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (prime[a[i]]==2&&prime_num[a[i]]) {
      cnt++;
    }
  }
  /*
  for (int i = 0;i<25;i++){
    cout << prime[i] << endl;
  }*/
  cout << cnt << endl;
  return 0;
}