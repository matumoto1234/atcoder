#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n, tmp;
  cin >> n;
  for (ll i = 1; i*i <= n;i++){
    tmp = i*i;
  }
  cout << tmp << endl;
  return 0;
}