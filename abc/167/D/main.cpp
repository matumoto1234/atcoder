#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n,k;
  cin>>n>>k;
  vector<ll> a(n);
  for(ll i=0;i<n;i++){
    cin>>a[i];
    a[i]--;
  }
  vector<ll> arrived(n,-1);
  ll now=0,siz;
  ll ans;
  arrived[0]=0;
  while(1){
    int to=a[now];
    if(k==0){
      ans=now;
      break;
    }
    if(arrived[to]!=-1){
      siz=arrived[now]+1-arrived[to];
      //cerr<<"siz:"<<siz<<endl;
      //cerr<<"k:"<<k<<endl;
      k--;
      k=k%siz;
      while(k>=0){
        ans=a[now];
        now=a[now];
        k--;
      }
      break;
    }
    arrived[to]=arrived[now]+1;
    now=to;
    k--;
  }
  cout<<ans+1<<endl;
}