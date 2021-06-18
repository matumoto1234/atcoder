#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = INT64_MAX/2;

int main(){
  ll n,c,k;
  cin>>n>>c>>k;
  vector<ll> t(n);
  for(ll &T:t){
    cin>>T;
  }
  t.emplace_back(INF);
  sort(t.begin(),t.end());
  deque<ll> deq;
  ll now,ans=0;
  for(int i=0;i<=n;i++){
    now=t[i];
    if(deq.empty()){
      deq.emplace_back(now);
      continue;
    }

    if(now>k+deq.front()){
      ans++;
      deq.clear();
    }
    if(deq.size()==c){
      ans++;
      deq.clear();
    }
    deq.emplace_back(now);
  }
  cout<<ans<<endl;
}