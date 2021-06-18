#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAXV = 400000;

int main() {
  ll n;
  cin >> n;
  using P = pair<ll,ll>;
  vector<P> a(n);
  ll ans=0;
  vector<bool> used(MAXV+1,false);
  vector<ll> cnt(MAXV+1,0);
  for(int i=0;i<n;i++){
    cin>>a[i].first>>a[i].second;

    if(used[a[i].first]==false){
      used[a[i].first]=true;
      ans++;
      cnt[a[i].first]++;
    }else{
      cnt[a[i].first]++;
    }
    if(used[a[i].second]==false){
      used[a[i].second]=true;
      ans++;
      cnt[a[i].second]++;
    }else{
      cnt[a[i].second]++;
    }
  }

  ll m=n;
  for(int i=0;i<n;i++){
    if(a[i].first==a[i].second&&cnt[a[i].first]>=3){
      m--;
      cnt[a[i].first]-=2;
    }
  }

  cout<<min(ans,m)<<endl;
  return 0;
}