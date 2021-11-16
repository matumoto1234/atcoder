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

vector<pair<char,ll>> runlength(string s){
  vector<pair<char,ll>> res;
  int cnt=0;
  s+='A';
  range(i,0,s.size()-1){
    cnt++;
    if(s[i]!=s[i+1]){
      res.emplace_back(s[i],cnt);
      cnt=0;
    }
  }
  return res;
}

int main() {
  string s;
  cin>>s;

  auto vs=runlength(s);

  if(vs.back().first=='<') vs.emplace_back('>',-111);
  else vs.emplace_back('<',-1111);

  ll ans=0;
  range(i,0,vs.size()-1){
    auto &[c,cnt]=vs[i];
    auto &[nc,ncnt]=vs[i+1];


    if(c=='>'&&nc=='<'){
      ans+=(0+cnt)*(cnt+1)/2;
    }
    if(c=='<'&&nc=='>'){
      if(cnt>ncnt) ncnt--;
      else cnt--;
      ans+=(0+cnt)*(cnt+1)/2;
    }
//    cerr<<vs[i]<<' '<<vs[i+1]<<endl;
//    cerr<<ans<<endl;
  }
  cout<<ans<<endl;
}