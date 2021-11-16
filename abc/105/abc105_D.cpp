#include<iostream>
#include<vector>
#include<map>
using namespace std;
using ll = long long;

ll nCr(ll n,ll r){
  ll res=1;
  for(ll i=1;i<=r;i++){
    res*=(n-i+1);
    res/=i;
  }
  return res;
}

int main(){
  ll n,m;
  cin>>n>>m;

  vector<ll> a(n);
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }

  vector<ll> sum(n+1,0);
  map<ll,ll> mp;
  mp[sum[0]%m]++;
  for(int i=1;i<=n;i++){
    sum[i]+=sum[i-1]+a[i-1];
    mp[sum[i]%m]++;
  }

  ll ans=0;
  for(auto it=mp.begin();it!=mp.end();it++){
    ans+=nCr(it->second,2LL);
  }

  cout<<ans<<endl;

  return 0;
}