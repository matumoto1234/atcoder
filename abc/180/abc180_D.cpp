#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

ll looppow(ll y,ll a,ll e){
  if(e==0){
    return 1LL;
  }
  if(e%2==0){
    ll res=looppow(y,a,e/2);
    return min(res*res,y);
  }
  return min(looppow(y,a,e-1)*a,y);
}

int main(){
  ll x,y,a,b;
  cin>>x>>y>>a>>b;
  ll ans=0;
  for(ll i=0;i<70;i++){
    ll temp=looppow(y,a,i);
    if(temp>=y){
      break;
    }
    if(temp*x>=y){
      break;
    }
    if((ll)log10(temp)+(ll)log10(temp)>=(ll)log10(y)){
      break;
    }
    temp*=x;
    ll temp2=(y-temp)/b;
    if((y-temp)%b==0){
      temp2--;
    }
    ans=max(ans,i+temp2);
    //cout<<temp<<' '<<temp2<<' '<<ans<<endl;
  }
  cout<<ans<<endl;
  return 0;
}