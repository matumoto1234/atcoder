#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {

  ll n;
  cin >> n;
  ll sum=0;
  for(int i=0;i<n;i++){
    ll a,b;
    cin>>a>>b;
    sum+=(a+b)*(b-a+1)/2LL;
  }
  cout<<sum<<endl;
  return 0;
}