#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n, m, sum, ans = 1;
  cin >> n >> m;
  ll l = 1, r = 1000000001LL, mid;
  while(r-l>1){
    mid = (l + r) / 2;
    if(mid*n<=m){
      l = mid;
    }else{
      r = mid;
    }
  }
  while(l>0){
    sum = m - n * l;
    if(sum%l==0){
      ans = l;
      break;
    }else{
      l--;
    }
  }
  cout << ans << endl;
  return 0;
}