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
constexpr int dy[] = {0,-1,1,0,-1,1,-1,1};
constexpr int dx[] = {-1,0,0,1,-1,-1,1,1};
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = (int)1e9 + 7;
constexpr char newl = '\n';

template <typename T1,typename T2>
T1 Binomial(T1 n,T2 r){
  T1 res=1;
  for(T1 i=0;i<r;i++){
    res*=n-i;
    res/=i+1;
  }
  return res;
}

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
  int n;
  cin>>n;

  string s,t;
  cin>>s>>t;

  vector<int> cnts(n,0),cntt(n,0);
  range(i,0,n){
    cnts[i]+=(s[i]=='1');
    cntt[i]+=(t[i]=='1');
  }

  CumulativeSum<int> sums(cnts);
  CumulativeSum<int> sumt(cntt);

  range(i,0,n){
    if(s[i]==t[i]){
      if(s[i]=='0' && sums.query(n,i)>sumt.query(n,i)){
        
      }
      continue;
    }

    if(s[i]=='1'){
      s[i+1]='0';
      s[i]='0';
      continue;
    }

    s[i+1]='0';
    s[i]='1';
  }
}