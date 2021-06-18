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
  int sum=0;
  vector<int> t(n);
  range(i,0,n){
    cin>>t[i];
    sum+=t[i];
  }

  int ans=INF32;
  range(i,0,1<<n){
    vector<bool> bit(n,false);
    range(j,0,n){
      if(i>>j&1) bit[j]=true;
    }

    int sum1=0,sum2=0;
    range(j,0,n){
      if(bit[j]) sum1+=t[j];
      else sum2+=t[j];
    }
    chmin(ans,max(sum1,sum2));
  }
  cout<<ans<<endl;
}