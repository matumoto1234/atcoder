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

template <typename T = long long>
vector<T> divisor(T n){
  vector<T> res;
  for(long long i=1;i*i<=n;i++){
    if(n%i==0){
      res.emplace_back(i);
      if(i*i!=n) res.emplace_back(n/i);
    }
  }
  sort(res.begin(),res.end());
  return res;
}

int main() {
  ll n;
  cin>>n;
  auto vs=divisor(n);
  ll ans=0;
  range(i,0,vs.size()-1){
    ans+=vs[i];
  }
  if(ans==n) cout<<"Perfect"<<endl;
  else if(ans<n) cout<<"Deficient"<<endl;
  else cout<<"Abundant"<<endl;
}