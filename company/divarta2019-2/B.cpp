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
  vector<P> a(n);
  range(i,0,n){
    auto &[x,y]=a[i];
    cin>>x>>y;
  }

  if(n==1){
    cout<<1<<endl;
    return 0;
  }

  map<P,int> cnt;
  range(i,0,n) range(j,0,n){
    if(i==j) continue;
    auto [x1,y1]=a[i];
    auto [x2,y2]=a[j];
    cnt[P(x1-x2,y1-y2)]++;
  }

  int maxc=-INF32;
  for(auto [p,count]:cnt){
    chmax(maxc,count);
  }

  cout<<n-maxc<<endl;
}