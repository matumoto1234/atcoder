#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while(1){
    n -= 1000;
    if(n<=0){
      break;
    }
  }
  cout << -1 * n << endl;
  return 0;
}