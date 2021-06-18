#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using LP = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;

vector<P> group(const vector<P>& v,int lim){
  vector<P> res;
  range(i,1,v.size()){
    if(v[i].second>lim) continue;
    res.emplace_back(v[i]);
  }
  return res;
}

int main() {
  int n,m;
  cin>>n>>m;
  // second:=日,first:=報酬
  vector<P> v;
  range(i,0,n){
    P a;
    cin>>a.second>>a.first;
    if(a.second>m) continue;
    v.emplace_back(a);
  }
  sort(v.begin(),v.end());
  ll ans=0;
  cout<<"----"<<endl;
  rrange(i,0,m){
    if(v.size()==0) break;
    cout<<v[0].first<<' '<<v[0].second<<endl;
    ans+=v[0].first;
    v=group(v,i);
  }
  cout<<ans<<endl;
}