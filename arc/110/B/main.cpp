#include<iostream>
#include<string>
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
  else {
    ll res=llpow(a,e-1)*a;
    return res;
  }
}

int main(){
  int n;
  string s,t;
  cin>>n>>t;

  while(s.size()<2*t.size()){
    s+="110";
  }
  if(s.find(t,0)==string::npos){
    cout<<0<<endl;
    return 0;
  }

  int k=0;
  for(int i=0;i<(int)t.size();i++){
    if(t[i]=='0') k++;
  }
  ll N=llpow(10LL,10LL);
  if(t=="1") cout<<2LL*N<<endl;
  else if(t=="11") cout<<N<<endl;
  else if(t[t.size()-1]=='1') cout<<N-k<<endl;
  else cout<<N-k+1<<endl;
  return 0;
}