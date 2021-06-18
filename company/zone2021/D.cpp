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

int main() {
  string s;
  cin>>s;
  deque<char> t;

  bool flg=false;
  range(i,0,s.size()){
    if(s[i]=='R'){
      flg=!flg;
      continue;
    }

    if(flg){
      if(!t.empty() && t.front()==s[i]){
        t.pop_front();
        continue;
      }
      t.emplace_front(s[i]);
    }else{
      if(!t.empty() && t.back()==s[i]){
        t.pop_back();
        continue;
      }
      t.emplace_back(s[i]);
    }
  }

  if(flg) reverse(t.begin(),t.end());
  for(char c:t){
    cout<<c;
  }
  cout<<endl;
}