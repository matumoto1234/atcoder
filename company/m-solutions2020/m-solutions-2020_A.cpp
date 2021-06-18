#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
  int n,cnt=9;
  int a=400;
  cin>>n;
  while(n>=a){
    a += 200;
    cnt--;
  }
  cout << cnt << endl;
  return 0;
}