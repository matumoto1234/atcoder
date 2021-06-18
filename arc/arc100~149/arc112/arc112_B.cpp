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

// [a,b]と[c,d]の共通区間
template <typename T>
T CommonSection(T a,T b,T c,T d){
  if(b<c||d<a) return 0;
  vector<T> v={a,b,c,d};
  sort(v.begin(),v.end());
  return v[2]-v[1]+1;
}

int main() {
  ll b,c;
  cin>>b>>c;

  ll A,B,C,D;

  // [A,B]
  A=-b-(c-1)/2;
  B=-b+(c-1)/2;

  // [C,D]
  C=b-c/2;
  if(c==1) D=b;
  else D=b+(c-2)/2;

  ll cs=CommonSection(A,B,C,D);
  //cerr<<A<<' '<<B<<' '<<C<<' '<<D<<' '<<cs<<endl;
  ll ans=(B-A+1)+(D-C+1)-cs;
  cout<<ans<<endl;
}