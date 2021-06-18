#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main(){
  ll n,m;
  cin>>n>>m;
  vector<ll> w(n);
  ll maxw=0;
  for(ll i=0;i<n;i++){
    cin>>w[i];
    maxw=max(maxw,w[i]);
  }
  bool flg=false;
  vector<ll> l(m),v(m);
  for(ll i=0;i<m;i++){
    cin>>l[i]>>v[i];
    if(maxw>v[i]){
      flg=true;
    }
  }

  if(flg){
    cout<<-1<<endl;
    return 0;
  }

  sort(w.begin(),w.end());
  do{
  }while(next_permutation(w.begin(),w.end()));

  return 0;
}