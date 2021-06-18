#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct zahyo{
  ll y,x;
};

ll absll(ll x){
  return (x<0?x*-1:x);
}

void output(vector<vector<ll>> v){
  for(ll i=0;i<v.size();i++){
    for(ll j=0;j<v[i].size();j++){
      if(j){
        cout<<' ';
      }
      cout<<v[i][j];
    }
    cout<<"\n";
  }
  cout<<flush;
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll h,w,d;
  cin>>h>>w>>d;
  map<ll,zahyo> m;
  for(ll i=0;i<h;i++){
    for(ll j=0;j<w;j++){
      ll temp;
      zahyo yx;
      cin>>temp;
      yx.y=i;
      yx.x=j;
      m[temp]=yx;
    }
  }
  vector<vector<ll>> v(d+1,vector<ll> (1,0));
  //cout<<"v.size()="<<v.size()<<endl;
  for(ll i=1;i<=d;i++){
    ll vi=0;
    for(ll j=i+d;j<=h*w;j+=d){
      //cout<<"j="<<j<<endl;
      ll cost;
      cost = absll(m[j].y-m[j-d].y)+absll(m[j].x-m[j-d].x);
      v[i].push_back(v[i][vi] + cost);
      vi++;
    }
  }
  //output(v);
  ll q;
  cin>>q;
  ll l,r;
  for(ll i=0;i<q;i++){
    cin>>l>>r;
    ll ori=l%d;
    if(ori==0){
      ori=d;
    }
    ll left,right;
    left=(l-ori)/d;
    right=(r-ori)/d;
    cout<<v[ori][right]-v[ori][left]<<endl;
  }
  return 0;
}