#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll absll(ll x){
  if(x<0){
    return x*-1;
  }
  else return x;
}

int main() {
  ll x,k,d;
  cin>>x>>k>>d;
  if(absll(x%d)<=absll(x%d)-d){
    if(k>=x/d){
      k-=absll(x/d);
      if(k%2==0){
        cout<<absll(x%d)<<endl;
      }else{
        cout<<absll(absll(x%d)-d)<<endl;
      }
    }else{
      cout<<absll(absll(x)-absll(k*d))<<endl;
    }
  }else{
    if(k>absll(x/d)){
      k-=absll(x/d)+1;
      if(k%2==0){
        cout<<absll(absll(x%d)-d)<<endl;
      }else{
        cout<<absll(x%d)<<endl;
      }
    }else{
      cout<<absll(absll(x)-absll(k*d))<<endl;
    }
  }
  return 0;
}