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

template <typename T>
struct CumulativeSum{
  vector<T> sum;
  CumulativeSum(const vector<T> &a){
    int n=a.size();
    sum.assign(n+1,0);
    for(int i=0;i<n;i++) sum[i+1]=a[i]+sum[i];
  }

  T query(int l,int r){ return sum[r]-sum[l]; }
};

int main() {
  ll n,k;
  cin>>n>>k;
  vector<ll> a(n);
  range(i,0,n){
    cin>>a[i];
  }

  CumulativeSum<ll> sum(a);

  ll ans=0;
  range(i,0,n){
    int valid=n;
    int invalid=i;
    cerr<<"----begin----"<<endl;
    while(abs(valid-invalid)>1){
      int mid=(valid+invalid)/2;
      if(sum.query(i,mid)>=k) valid=mid;
      else invalid=mid;
      // cerr<<"v:"<<valid<<" inv:"<<invalid<<endl;
    }

    if(sum.query(i,valid)>=k){
      ans+=n-valid+1;
    }
  }
  cout<<ans<<endl;
}