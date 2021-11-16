#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
using ll = long long;

ll llpow(ll a,ll e){
  if(e==0){
    return 1LL;
  }
  if(e%2==0){
    ll res=llpow(a,e/2);
    return res*res;
  }
  else{
    return llpow(a,e-1) * a;
  }
}

string lltos(ll x){
  string res;
  while(1){
    res+='0'+x%10;
    x/=10;
    if(x==0){
      break;
    }
  }
  reverse(res.begin(),res.end());
  return res;
}

int log_10(ll x){
  ll a=1;
  int cnt=0;
  while(a<x){
    a*=10;
    cnt++;
  }
  return cnt;
}

ll solve(ll x){
  vector<ll> cnt(log_10(x));
  
  vector<ll> max_cnt(19,0LL);
  max_cnt[1]=2;
  max_cnt[2]=2*10+2*(10-max_cnt[1]);
  for(int i=1;i<=18;i++){
    max_cnt[i]=2*llpow(10LL,i-1)+2*(10-max_cnt[i-1]);
  }
  return 0LL;
}

int main(){
  ll a,b;
  cin>>a>>b;

  //cout<<lltos(a)<<endl;
  return 0;
}