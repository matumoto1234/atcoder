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
  vector<int> a(n);
  for(auto &A:a) cin>>A;

  if(n==1){
    cout<<a[0]<<endl;
    return 0;
  }

  int ans=INF32;
  range(i,1,1<<(n-1)){
    int pre=0;
    int sum=0;
    range(j,0,n-1){
      if(i>>j&1){
        int v=0;
        range(k,pre,j+1){
          v|=a[k];
        }
        sum^=v;
        pre=j+1;
      }
    }
    int v=0;
    range(j,pre,n){
      v|=a[j];
    }
    sum^=v;
    chmin(ans,sum);
  }
  cout<<ans<<endl;
}