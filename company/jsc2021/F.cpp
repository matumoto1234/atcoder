#include <bits/stdc++.h>
using namespace std;

#include <atcoder/fenwicktree.hpp>
using namespace atcoder;

#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ull = unsigned long long;
using ll = long long;
using Pll = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

struct query{
  ll t,x,y;
};

int main() {
  ll n,m,q;
  cin>>n>>m>>q;

  vector<ll> ys(q);
  vector<query> qs(q);
  range(i,0,q){
    cin>>qs[i].t>>qs[i].x>>qs[i].y;
    ys[i]=qs[i].y;
  }

  ys.emplace_back(0);
  sort(ys.begin(),ys.end());
  ys.erase(unique(ys.begin(),ys.end()),ys.end());

  ll sum=0;
  vector<ll> a(n+10,0),b(m+10,0);
  fenwick_tree<ll> cnta(q+10),cntb(q+10);
  fenwick_tree<ll> suma(q+10),sumb(q+10);

  cnta.add(0,n);
  cntb.add(0,m);

  range(i,0,q){
    ll t=qs[i].t, x=qs[i].x, y=qs[i].y;
    ll compy=lower_bound(ys.begin(),ys.end(),y)-ys.begin();
    //cerr<<"compy:"<<compy<<endl;
    if(t==1){
      ll compax=lower_bound(ys.begin(),ys.end(),a[x])-ys.begin();
      //cerr<<"compy:"<<compy<<" compax:"<<compax<<endl;
      sum-=cntb.sum(0,compax+1)*a[x];
      sum-=sumb.sum(compax+1,q+1);
      cnta.add(compax,-1);
      suma.add(compax,-a[x]);

      a[x]=y;

      sum+=cntb.sum(0,compy+1)*y;
      sum+=sumb.sum(compy+1,q+1);
      cnta.add(compy,1);
      suma.add(compy,y);
    }else{
      ll compbx=lower_bound(ys.begin(),ys.end(),b[x])-ys.begin();
      //cerr<<"compy:"<<compy<<" compbx:"<<compbx<<endl;
      sum-=cnta.sum(0,compbx)*b[x];
      sum-=suma.sum(compbx,q+1);
      cntb.add(compbx,-1);
      sumb.add(compbx,-b[x]);

      b[x]=y;

      //cerr<<"cnta.sum(0,compy):"<<cnta.sum(0,compy)<<endl;
      //cerr<<"sum:"<<sum<<endl;
      //cerr<<"y:"<<y<<endl;
      //cerr<<cnta.sum(0,compy)*y<<endl;
      //cerr<<suma.sum(compy,q+1)<<endl;
      sum+=cnta.sum(0,compy)*y;
      sum+=suma.sum(compy,q+1);
      cntb.add(compy,1);
      sumb.add(compy,y);
    }
    //cerr<<"A:"<<a<<endl;
    //cerr<<"B:"<<b<<endl;
    cout<<sum<<newl;
  }
}