#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll absll(ll a){
  if(a<0){
    return a * -1;
  }
  return a;
}

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n,0);
  ll count = 0;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i]<0){
      count++;
      sum += a[i] * -1;
      a[i] *= -1;
    }else{
      sum += a[i];
    }
  }
  sort(a.begin(), a.end());
  if(count%2==0){
    cout << sum << endl;
  }else{
    cout << sum + a[0]*-2 << endl;
  }
  return 0;
}