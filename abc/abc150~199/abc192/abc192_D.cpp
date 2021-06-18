#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second<<'\n'; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';


ll m;
vector<ll> x;

vector<ll> to_base_n(ll v,ll n){
  vector<ll> res;
  while(v>0){
    res.emplace_back(v%n);
    v/=n;
  }
  reverse(res.begin(),res.end());
  return res;
}

bool comp(ll mid){
  vector<ll> a=to_base_n(m,mid);

  if(a.size()>x.size()) return true;
  if(a.size()<x.size()) return false;

  range(i,0,a.size()){
    if(a[i]>x[i]) return true;
    if(a[i]<x[i]) return false;
  }

  // case : a==x
  return true;
}

int main() {
  string x_;
  cin>>x_>>m;

  x.resize(x_.size());
  range(i,0,x_.size()){
    x[i]=x_[i]-'0';
  }

  ll maxv=0;
  range(i,0,x.size()){
    chmax(maxv,x[i]);
  }

  if(x.size()==1){
    if(maxv<=m){
      cout<<1<<endl;
    }else{
      cout<<0<<endl;
    }
    return 0;
  }


  ll l=maxv;
  ll r=m+1;
  while(r-l>1){
    ll mid=(l+r)/2;
    if(comp(mid)){
      l=mid;
    }else{
      r=mid;
    }
  }


  //cerr<<"l:"<<l<<" r:"<<r<<endl;
  cout<<l-maxv<<endl;
}