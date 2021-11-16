#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll a){
  ll res=0;
  while(a>0){
    res+=a%10;
    a/=10;
  }
  return res;
}

int main(){
  ll a,b;
  cin>>a>>b;
  cout<<max(solve(a),solve(b))<<endl;
  return 0;
}