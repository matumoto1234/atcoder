#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct aaa{
  ll a,b,c;
};

bool asc(const aaa& l,const aaa& r){
  return l.c==r.c?l.b<r.b:l.c<r.c;
}

int main() {
  ll n;
  cin >> n;
  using P = pair<ll,ll>;
  vector<P> v(n);
  ll suma=0;
  vector<aaa> info(n);
  for(ll i=0;i<n;i++){
    cin>>v[i].first>>v[i].second;
    suma+=v[i].first;
    info[i].a=v[i].first;
    info[i].b=v[i].second;
    info[i].c=v[i].first*2+v[i].second;
  }
  sort(info.rbegin(),info.rend(),asc);
  ll i=0;
  ll ans=0;
  ll sumb=0;
  while(suma>=sumb){
    suma-=info[i].a;
    sumb+=info[i].a+info[i].b;
    ans++;
    i++;
  }
  cout<<ans<<endl;
  return 0;
}