#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll t;
  cin>>t;
  for(ll loop=0;loop<t;loop++){
    ll n;
    cin>>n;
    ll sum=0;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
      cin>>a[i];
      sum+=a[i];
    }
    if(n%2==0){
      if(sum%2==0){
        cout<<"First"<<endl;
      }else{
        cout<<"Second"<<endl;
      }
    }else{
      if(sum%2==1){
        cout<<"Second"<<endl;
      }else{
        cout<<"First"<<endl;
      }
    }
  }
}