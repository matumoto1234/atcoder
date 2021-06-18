#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll q, h, s, d, n, ans = 0;
  vector<ll> a(5, 0);
  cin >> q >> h >> s >> d >> n;
  if(n>=2){
    a[0] = q * 8;
    a[1] = h * 4;
    a[2] = s * 2;
    a[3] = d;
    a[5] = min(a[0], min(a[1], min(a[2], a[3])));
    ans += n / 2 * a[5];
    n -= n / 2 * 2;
  }
  if(n>=1){
    a[0] = q * 4;
    a[1] = h * 2;
    a[2] = s;
    a[5] = min(a[0], min(a[1], a[2]));
    ans += a[5];
  }
  cout << ans << endl;
}