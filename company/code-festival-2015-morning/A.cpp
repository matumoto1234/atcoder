#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll n;
  cin>>n;
  deque<ll> a;
  for(int i=0;i<n;i++){
    ll x;
    cin>>x;
    a.push_back(x);
  }
  ll ans=0;
  while(a.size()>1){
    if(a.front()<a.back()){
      ans+=a.front();
      ll brack=a.front()+1;
      a.pop_front();
      brack+=a.front();
      a.pop_front();
      ans+=brack;

      ll white=brack+a.front()+1;
      a.pop_front();
      a.push_front(white);
    }else{
      ans+=a.back();
      ll brack=a.back()+1;
      a.pop_back();
      brack+=a.back();
      a.pop_back();
      ans+=brack;
      ll white=brack+a.back()+1;
      a.pop_back();
      a.push_back(white);
    }
  }
  cout<<ans<<endl;
}