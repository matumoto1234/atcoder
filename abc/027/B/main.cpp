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
  vector<int> sum(n+1,0);
  range(i,0,n){
    cin>>a[i];
    sum[i+1]=sum[i]+a[i];
  }

  if(sum[n]%n){
    cout<<-1<<endl;
    return 0;
  }

  int per=sum[n]/n;

  int last=0;
  int ans=0;
  range(i,1,n+1){
    if(sum[i]-sum[last]==per*(i-last)){
      last=i;
      continue;
    }
    ans++;
  }
  cout<<ans<<endl;
}