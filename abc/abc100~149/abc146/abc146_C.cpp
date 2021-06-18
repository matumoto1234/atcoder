#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll d(ll z){
  ll cnt=0;
  while(z>0){
    cnt++;
    z /= 10;
  }
  return cnt;
}

int main(){
  ll a, b, x;
  cin >> a >> b >> x;
  ll l = 0, r = 1000000001, mid;
  while(r-l>1){
    mid = (r + l) / 2;
    if(mid*a+d(mid)*b<=x){
      l = mid;
    }else{
      r = mid;
    }
  }
  cout << l << endl;
  return 0;
}