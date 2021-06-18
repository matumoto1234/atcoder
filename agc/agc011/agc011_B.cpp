#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll n, ans = 0;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0;i<n;i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  ll sum = a[0]*2, last=0;
  for (int i = 1; i < n;i++){
    if(sum>=a[i]){
      sum += a[i] * 2;
    }else{
      last = i;
      sum += a[i]*2;
    }
    //cout << "sum=" << sum <<" last="<<last<< endl;
  }
  ans = n - last;
  cout << ans << endl;
  return 0;
}