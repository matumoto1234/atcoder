#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll p = 998244353;

int main(){
  ll a,b,c;
  cin>>a>>b>>c;
  ll sum=0;


  a=(1+a)*a/2LL;
  b=(1+b)*b/2LL;
  c=(1+c)*c/2LL;
  a%=p;
  b%=p;
  c%=p;

  sum=(((a*b)%p)*c)%p;
  cout<<sum<<endl;

  return 0;
}