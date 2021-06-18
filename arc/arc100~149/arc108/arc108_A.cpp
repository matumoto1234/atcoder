#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll s,p;
  cin>>s>>p;
  bool flg=false;
  for(ll i=1;i*i<=p;i++){
    if(p%i!=0) continue;
    if(p/i+i==s){
      //cout<<i<<endl;
      flg=true;
      break;
    }
  }
  cout<<(flg?"Yes":"No")<<endl;
}