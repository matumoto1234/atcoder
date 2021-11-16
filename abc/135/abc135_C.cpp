#include <bits/stdc++.h>
using namespace std;
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

int main() {
  int n;
  cin>>n;
  vector<int> a(n+1);
  range(i,0,n+1){
    cin>>a[i];
  }

  vector<int> b(n);
  range(i,0,n){
    cin>>b[i];
  }

  ll ans=0;
  range(i,0,n){
    ans+=min(a[i],b[i]);
    //cerr<<"i:"<<i<<" a[i]:"<<a[i]<<" b[i]:"<<b[i]<<endl;
    b[i]=max(0,b[i]-a[i]);
    ans+=min(a[i+1],b[i]);
    a[i+1]=max(0,a[i+1]-b[i]);
  }
  //cerr<<a<<endl;
  //cerr<<b<<endl;
  cout<<ans<<endl;
}