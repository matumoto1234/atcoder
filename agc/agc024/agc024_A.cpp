#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll a,b,c,k;
  cin>>a>>b>>c>>k;
  if(k%2==0){
    cout<<a-b<<endl;
  }else{
    cout<<-a+b<<endl;
  }
  return 0;
}