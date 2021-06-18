#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct info{
  ll v,i;
};

vector<info> a;
info lastl,lastr;

info solve(ll l,ll r){
  if(r-l==1){
    return a[l];
  }

  ll m=(l+r)/2;
  info left=solve(l,m);
  info right=solve(m,r);
  //cerr<<left.v<<' '<<left.i<<endl;
  //cerr<<right.v<<' '<<right.i<<endl;
  lastl=left;
  lastr=right;
  if(left.v>right.v){
    return left;
  }else{
    return right;
  }
}

int main() {
  ll n;
  cin >> n;
  ll sz=(1LL<<n);
  a.resize(sz);
  for(ll i=0;i<sz;i++){
    cin>>a[i].v;
    a[i].i=i+1;
  }
  solve(0,sz);
  if(lastl.v<lastr.v){
    cout<<lastl.i<<endl;
  }else{
    cout<<lastr.i<<endl;
  }
  //cerr<<lastl.v<<' '<<lastl.i<<endl;
  //cerr<<lastr.v<<' '<<lastr.i<<endl;
  return 0;
}