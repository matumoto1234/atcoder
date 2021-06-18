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

template <typename T>
vector<pair<T,int>> runlength(vector<T> vs){
  vector<pair<T,int>> res;
  for(auto v:vs){
    if(res.empty() || res.back().first!=v) res.emplace_back(v,0);
    res.back().second++;
  }
  return res;
}

int main() {
  string s;
  cin>>s;
  
  vector<char> ns;
  range(i,0,s.size()){
    if(i<(int)s.size()-1 && s[i]=='2' && s[i+1]=='5'){
      ns.emplace_back('A');
      i++;
      continue;
    }
    ns.emplace_back(s[i]);
  }

  auto vs=runlength(ns);
  ll ans=0;
  range(i,0,vs.size()){
    auto [c,cnt]=vs[i];
    if(c=='A'){
      range(j,1,cnt+1){
        ans+=cnt-j+1;
      }
    }
  }
  cout<<ans<<endl;
}