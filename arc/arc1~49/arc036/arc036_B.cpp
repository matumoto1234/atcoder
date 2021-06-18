#include <bits/stdc++.h>
#include <atcoder/segtree.hpp>
using namespace atcoder;
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

vector<pair<char,int>> runlength(string s){
  vector<pair<char,int>> res;
  res.emplace_back('<',0);
  for(auto v:s){
    if(res.empty() || res.back().first!=v) res.emplace_back(v,0);
    res.back().second++;
  }
  res.emplace_back('>',0);
  return res;
}

int main() {
  int n;
  cin>>n;
  vector<int> h(n);
  range(i,0,n) cin>>h[i];

  string s;
  range(i,0,n-1){
    if(h[i]>h[i+1]){
      s.push_back('>');
    }else{
      s.push_back('<');
    }
  }

  auto vs=runlength(s);

//  cerr<<s<<endl;
//  cerr<<vs<<endl;

  int ans=0;
  range(i,0,vs.size()-1){
    auto [c,cnt]=vs[i];
    auto [nc,ncnt]=vs[i+1];
    if(c=='<' && nc=='>'){
      chmax(ans,cnt+ncnt+1);
    }
  }
  cout<<ans<<endl;
}