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

vector<int> compress(vector<int> a){
  int n=a.size();
  vector<int> res=a;
  sort(a.begin(),a.end());
  map<int,int> mp;
  for(int i=0;i<n;i++){
    mp[a[i]]=i;
  }
  for(int i=0;i<n;i++){
    res[i]=mp[res[i]];
  }
  return res;
}

int main() {
  int n;
  cin>>n;

  vector<int> x(n);
  range(i,0,n){
    cin>>x[i];
  }

  auto cpx=compress(x);

  cerr<<cpx<<endl;

  fenwick_tree<int> ft(n);
  range(i,0,n){
    ft.add(cpx[i],1);
  }

  sort(x.begin(),x.end());

  range(i,0,n){
    ft.add(cpx[i],-1);
    ll valid=n+1;
    ll invalid=-1;
    while(abs(valid-invalid)>1){
      ll mid=(valid+invalid)/2;
      if((n)/2<=ft.sum(0,mid+1)) valid=mid;
      else invalid=mid;
      //cerr<<mid<<' '<<(n-1)/2<<' '<<ft.sum(0,mid+1)<<' '<<valid<<' '<<invalid<<endl;
    }
    cout<<x[valid]<<endl;
    ft.add(cpx[i],1);
  }
}