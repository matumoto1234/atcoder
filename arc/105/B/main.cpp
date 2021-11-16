#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> a(n);
  ll minv;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(i){
      minv = min(minv, __gcd(a[i-1],a[i]));
    }else{
      minv=a[i];
    }
  }
  cout<<minv<<endl;
  return 0;
}