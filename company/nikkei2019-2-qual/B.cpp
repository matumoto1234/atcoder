#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint.hpp>
using namespace atcoder;
using mint = modint998244353;

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
  map<ll,ll> mp;

  bool imp=false;
  range(i,0,n){
    int d;
    cin>>d;
    if(i==0&&d>0) imp=true;
    if(i>0&&d==0) imp=true;
    mp[d]++;
  }

  mint ans=1;
  for(auto it=mp.begin();it!=mp.end();it++){
    auto [val,cnt]=*it;
    if(it==mp.begin()) continue;

    auto it2=it;
    it2--;
    auto [pval,pcnt]=*it2;
    if(pval+1!=val) imp=true;
    mint mpcnt=pcnt;
    ans*=mpcnt.pow(cnt);
  }
  if(imp) ans=0;
  cout<<ans.val()<<endl;
}