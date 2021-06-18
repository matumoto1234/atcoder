#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct robo{
  ll s,t;

  bool operator<(const robo& r) const { 
    return t == r.t ? s < r.s : t < r.t;
  }
};

int main(){
  ll n;
  cin>>n;
  vector<ll> x(n),l(n);
  vector<robo> a(n);
  for(ll i=0;i<n;i++){
    cin>>x[i]>>l[i];
    a[i].s=x[i]-l[i];
    a[i].t=x[i]+l[i];
  }
  sort(a.begin(),a.end());
  ll ans=n;
  ll minv=a[0].t;
  for(ll i=1;i<n;i++){
    if(minv>a[i].s){
      ans--;
    }else{
      minv=max(minv,a[i].t);
    }
  }
  cout<<ans<<endl;
  return 0;
}