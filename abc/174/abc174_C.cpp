#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int POW(int a,int e){
  if(e==0){
    return 1;
  }
  e--;
  for (int i = 0; i < e;i++){
    a *= a;
  }
  return a;
}

int main() {
  ll k, keta = 1;
  cin >> k;
  if (k % 2 == 0) {
    cout << -1 << endl;
  }
  ll n=0,temp=1;
  while(1){
    if(temp>k){
      break;
    }
    temp *= 10;
    n++;
  }
  cout << n << endl;
  string s = {"7"};
  while (1) {
    ll sum = 0;
    for (int i = 0; i < keta % n;i++){
      sum += POW(10, i) + 7;
    }
    sum += (keta / 3 - keta / 3 / 2) * 777;
    sum -= (keta / 3 / 2) * 777;
    if(keta==4)cout << sum << endl;
    if(sum%k==0){
      cout << keta << endl;
      break;
    }
    keta++;
    if(keta>=200000){
      cout << -1 << endl;
      break;
    }
  }
  return 0;
}
/*
a0=7;
an=(an-1)*10+7;

*/