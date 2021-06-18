#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n, sum;
  bool flg = false;
  cin >> n;
  vector<ll> t(n+1,0), x(n+1,0), y(n+1,0);
  for (int i = 1; i <= n;i++){
    cin >> t[i] >> x[i] >> y[i];
    sum = t[i] - t[i - 1];
    sum -= abs(x[i - 1] - x[i]) + abs(y[i - 1] - y[i]);
    if(sum<0||sum%2!=0){
      flg = true;
    }
  }
  if(flg){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
  return 0;
}