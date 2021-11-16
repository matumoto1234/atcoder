#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

bool isSame(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){
  //cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<' '<<x3<<' '<<y3<<endl;
  //cout<<(y3-y1)<<' '<<(y2-y1)<<' '<<(x2-x1)*(x3-x1)<<endl;
  if((x2-x1)==0){
    return (x1==x2&&x1==x3);
  }
  return (ld)(y3-y1)==(ld)(y2-y1)/(ld)(x2-x1)*(ld)(x3-x1);
}

int main() {

  ll n;
  cin >> n;
  vector<ll> x(n),y(n);
  for(ll i=0;i<n;i++){
    cin>>x[i]>>y[i];
  }
  
  bool flg=false;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j){
        continue;
      }
      for(int k=0;k<n;k++){
        if(i==k||j==k){
          continue;
        }
        if(isSame(x[i],y[i],x[j],y[j],x[k],y[k])){
          flg=true;
          break;
        }
      }
    }
    if(flg){
      break;
    }
  }
  cout<<(flg?"Yes":"No")<<endl;
  return 0;
}