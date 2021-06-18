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
constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr char newl = '\n';

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  range(i,0,n){
    cin>>a[i];
  }

  sort(a.begin(),a.end());

  vector<int> vs1;
  range(i,0,n/2){
    vs1.emplace_back(a[i]);
    vs1.emplace_back(a[n-i-1]);
  }
  if(n%2==1) vs1.emplace_back(a[n/2]);

  vector<int> vs2;
  range(i,0,n/2){
    vs2.emplace_back(a[n-i-1]);
    vs2.emplace_back(a[i]);
  }
  if(n%2==1) vs2.emplace_back(a[n/2]);

  ll v1=0;
  range(i,0,vs1.size()-1){
    v1+=abs(vs1[i]-vs1[i+1]);
  }

  ll v2=0;
  range(i,0,vs2.size()-1){
    v2+=abs(vs2[i]-vs2[i+1]);
  }

  cerr<<v1<<' '<<v2<<endl;
  cerr<<vs1<<newl<<vs2<<endl;

  cout<<max(v1,v2)<<endl;
}