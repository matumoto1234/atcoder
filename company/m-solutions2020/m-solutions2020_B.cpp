#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
  int k;
  int a, b, c;
  cin >> a >> b >> c >> k;
  while(a>=b){
    b *= 2;
    k--;
    if(k==0){
      break;
    }
  }
  while(b>=c&&k>=1){
    c *= 2;
    k--;
  }
  if(a<b&&b<c){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}